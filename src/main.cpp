#include <random>

#include "framework/Framework.h"

#include "shaderprograms/inc/ShaderPrograms.h"
#include "textures/inc/ShadowDepthTexture.h"
#include "textures/inc/LightTexture.h"
#include "textures/inc/AlbedoTexture.h"

#include "renderstrategies/gbuffer/inc/GBufferRenderStrategy.h"
#include "renderstrategies/null/inc/NullRenderStrategy.h"
#include "renderstrategies/shadowdepth/inc/ShadowDepthRenderStrategy.h"

#include "renderstrategies/ssao/inc/SSAORenderStrategy.h"
#include "renderstrategies/hbao/inc/HBAORenderStrategy.h"

#include "renderstrategies/aoblur/inc/AOBlurRenderStrategy.h"
#include "renderstrategies/light/inc/LightRenderStrategy.h"
#include "textures/inc/NoiseTexture.h"
#include "textures/inc/ShadowTexture.h"
#include "renderstrategies/shadow/inc/ShadowRenderStrategy.h"
#include "renderstrategies/lightbulb/inc/LightBulbRenderInputData.h"
#include "renderstrategies/lightbulb/inc/LightBulbRenderStrategy.h"
#include "menu/ssao/inc/SSAOMenu.h"
#include "renderers/ssao/inc/SSAORenderer.h"
#include "renderers/ssao/inc/Kernel.h"
#include "renderers/aoblur/inc/AOBlurRenderer.h"
#include "renderstates/ssaorenderstate/inc/SSAORenderState.h"
#include "renderstates/hbaorenderstate/inc/HBAORenderState.h"
#include "gbuffer/inc/GBuffer.h"
#include "renderstates/whitemask/inc/WhiteMaskRenderState.h"
#include "menu/debug/inc/DebugMenu.h"
#include "menu/aomenu/inc/AOMenu.h"
#include "menu/settings/inc/SettingsMenu.h"
#include "menu/shadowmapping/inc/ShadowMappingMenu.h"
#include "menu/light/inc/LightMenu.h"

void drawOutput(Texture* f_texture);
void toggleButton(const char* str_id, bool* v);
void getCurrentSetting(unsigned int* f_currentSetting);

enum Setting
{
    DEBUG,
    LIGHT,
    SHADOW_MAPPING,
    AMBIENT_OCCLUSION,
    NUMBER_OF_SETTINGS
};

int main(int argc, char** argv) {
    SDL_Window* window;
    SDL_GLContext context;
    ImGuiRenderer imGuiRenderer = init(window, context);

    Settings l_settings = Settings::getInstance();
    int width = l_settings.getWidth();
    int height = l_settings.getHeight();

    ShaderPrograms::load();
    AssimpLoader modelLoader = AssimpLoader();

    // Room
    Model dockModel = modelLoader.load(RESOURCE::MODEL::DOCK);
    SceneObject dock(dockModel);
    dock.translate(glm::vec3(0.0f, 0.0f, 0.0f));
    dock.scale(glm::vec3(10.0f, 1.0f, 10.0f));

    Model lightModel = modelLoader.load(RESOURCE::MODEL::LIGHT);
    SceneObject light(lightModel, ShaderPrograms::get(ShaderPrograms::LIGHTBULB));
    light.rotate(1.5708f, glm::vec3(1.0f, 0.0f, 0.0f));

    Camera camera;
    Camera camera2(ShaderPrograms::get(ShaderPrograms::LIGHTBULB));
    Scene scene(width, height, &camera);
    scene.addSceneObject(dock);

    Timer timer;
    CameraHandler cameraHandler(camera);

    Light l_light(50.0f, 0.25f);

    //////////////
    // Textures //
    /////////////

    // Shadow mapping
    Texture* l_shadowDepthTexture = new ShadowDepthTexture();
    Texture* l_shadowTexture      = new ShadowTexture();

    // Light
    Texture* l_lightTexture       = new LightTexture();

    // Light bulb
    Texture* l_lightBulbTexture   = new AlbedoTexture();

    //////////////////
    // FrameBuffers //
    //////////////////

    GBuffer l_gBuffer;

    // Shadow Mapping
    FrameBuffer l_shadowDepthBuffer({l_shadowDepthTexture});
    FrameBuffer l_shadowBuffer({l_shadowTexture});

    // Light
    FrameBuffer l_lightBuffer({l_lightTexture});

    // Light bulb
    FrameBuffer l_lightBulbBuffer({l_lightBulbTexture});

    // RenderStrategies
    GBufferRenderStrategy     l_gBufferRenderStrategy(&l_gBuffer);
    ShadowDepthRenderStrategy l_shadowDepthRenderStrategy(&l_shadowDepthBuffer);
    ShadowRenderStrategy      l_shadowRenderStrategy(&l_shadowBuffer);

    LightRenderStrategy       l_lightRenderStrategy(&l_lightBuffer);
    LightBulbRenderStrategy   l_lightBulbRenderStrategy(&l_lightBulbBuffer);

    // Define IO
    GBufferRenderInputData l_gBufferRenderInputData{};
    l_gBufferRenderInputData.m_scene = &scene;

    LightBulbRenderInputData l_lightBulbRenderInputData{};
    l_lightBulbRenderInputData.m_scene = &scene;

    ShadowDepthRenderInputData l_shadowDepthRenderInputData{};
    l_shadowDepthRenderInputData.m_scene = &scene;
    l_shadowDepthRenderInputData.m_light = &l_light;

    ShadowRenderInputData l_shadowRenderInputData{};
    l_shadowRenderInputData.m_gPosition   = l_gBuffer.getPositionTexture();
    l_shadowRenderInputData.m_gNormal     = l_gBuffer.getNormalTexture();
    l_shadowRenderInputData.m_shadowDepth = l_shadowDepthTexture;
    l_shadowRenderInputData.m_light       = &l_light;

    // SSAO
    SSAORenderInputData l_ssaoRenderInputData;
    l_ssaoRenderInputData.m_gBuffer      = &l_gBuffer;
    l_ssaoRenderInputData.m_scene        = &scene;

    SSAORenderState l_ssaoRenderState;
    l_ssaoRenderState.setRenderInputData(&l_ssaoRenderInputData);

    // HBAO
    HBAORenderInputData l_hbaoRenderInputData{};
    l_hbaoRenderInputData.m_gBuffer = &l_gBuffer;
    l_hbaoRenderInputData.m_scene   = &scene;

    HBAORenderState l_hbaoRenderState;
    l_hbaoRenderState.setRenderInputData(&l_hbaoRenderInputData);

    WhiteMaskRenderState l_whiteMaskRenderState;
    l_whiteMaskRenderState.render();

    LightMenu l_lightMenu;

    LightRenderInputData l_lightRenderInputData{};
    l_lightRenderInputData.m_gBuffer               = &l_gBuffer;
    l_lightRenderInputData.m_shadowTexture         = l_shadowTexture;
    l_lightRenderInputData.m_aoTexture             = l_ssaoRenderState.getOutputTexturePointer();
    l_lightRenderInputData.m_lightBulbTexture      = l_lightBulbTexture;
    l_lightRenderInputData.m_light                 = &l_light;
    l_lightRenderInputData.m_cameraPosition        = &scene.camera->position;
    l_lightRenderInputData.m_lightMenuSettingData  = l_lightMenu.getSettingDataPointer();

    DebugMenu l_debugMenu;
    l_debugMenu.setGBufferPointer(&l_gBuffer);

    SettingsMenu l_settingsMenu;

    ShadowMappingMenu l_shadowMappingMenu;
    AOMenu l_aoMenu;

    int l_currentAOMethod = AOMenuSettingData::SSAO;

    float p[3] = { 3.0f, 4.0f, 7.0f };

    bool isRunning = true;
    while (isRunning) {
        float deltaTime = timer.getDeltaTime();

        if (scene.hasFocus) {
            cameraHandler.process(deltaTime);
        }

        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            isRunning = processEvent(event);

            if (event.type == SDL_WINDOWEVENT) {
                if (event.window.event == SDL_WINDOWEVENT_RESIZED) {
                    SDL_GetWindowSize(window, &width, &height);
                    imGuiRenderer.resize(width, height);
                }
            }
        }

        imGuiRenderer.preRender();

        ///////////////
        // Menu (UI) //
        ///////////////
        l_settingsMenu.draw();

        switch (l_settingsMenu.getSettingDataPointer()->m_menuType) {
            case SettingsSettingData::LIGHT:
                l_ssaoRenderInputData.m_settingData->m_isMenuEnable = false;
                l_hbaoRenderInputData.m_settingData->m_isMenuEnable = false;
                l_lightMenu.draw();
                break;

            case SettingsSettingData::SHADOW_MAPPING:
                l_ssaoRenderInputData.m_settingData->m_isMenuEnable = false;
                l_hbaoRenderInputData.m_settingData->m_isMenuEnable = false;
                l_shadowMappingMenu.draw();
                break;

            case SettingsSettingData::AMBIENT_OCCLUSION:
                l_ssaoRenderInputData.m_settingData->m_isMenuEnable = true;
                l_hbaoRenderInputData.m_settingData->m_isMenuEnable = true;
                l_aoMenu.draw();
                l_currentAOMethod = l_aoMenu.getSettingDataPointer()->m_aoMethod;
                break;
        }

        if (l_settingsMenu.getSettingDataPointer()->m_isDebugEnable)
        {
            l_debugMenu.draw();
        }

        ////////////
        // Render //
        ////////////
        l_gBufferRenderStrategy.render(l_gBufferRenderInputData);

        // Light
        float* l_lightPosition = l_lightMenu.getSettingDataPointer()->m_lightPosition;
        glm::vec3 v(-l_lightPosition[1], -l_lightPosition[0], -l_lightPosition[2]);
        light.moveTo(v);
        l_light.m_position = glm::vec3(v.x, -v.z, v.y);
        l_light.update();

        // Shadow Mapping
        if (l_shadowMappingMenu.getSettingDataPointer()->m_isEnable)
        {
            l_shadowDepthRenderStrategy.render(l_shadowDepthRenderInputData);
            l_shadowRenderStrategy.render(l_shadowRenderInputData);
            l_lightRenderInputData.m_shadowTexture = l_shadowTexture;
        }
        else
        {
            l_lightRenderInputData.m_shadowTexture = l_whiteMaskRenderState.getOutputTexturePointer();
        }

        // Ambient Occlusion
        if (l_aoMenu.getSettingDataPointer()->m_isEnable)
        {
            switch (l_currentAOMethod) {
                default:
                case AOMenuSettingData::SSAO:
                    l_ssaoRenderState.render();
                    l_lightRenderInputData.m_aoTexture = l_ssaoRenderState.getOutputTexturePointer();
                    break;

                case AOMenuSettingData::HBAO:
                    l_hbaoRenderState.render();
                    l_lightRenderInputData.m_aoTexture = l_hbaoRenderState.getOutputTexturePointer();
                    break;
            }
        }
        else
        {
            l_lightRenderInputData.m_aoTexture = l_whiteMaskRenderState.getOutputTexturePointer();
        }

        scene.removeLast();
        scene.addSceneObject(light);
        camera2.projectionMatrix = camera.projectionMatrix;
        camera2.viewMatrix = camera.viewMatrix;

        scene.camera = &camera2;

        l_lightBulbRenderStrategy.render(l_lightBulbRenderInputData);

        scene.camera = &camera;
        scene.removeLast();
        scene.addSceneObject(dock);

        l_lightRenderStrategy.render(l_lightRenderInputData);

        ////////////////
        // Final Draw //
        ////////////////
        drawOutput(l_lightTexture);

        imGuiRenderer.postRender();

        SDL_GL_SwapWindow(window);
    }

    l_gBuffer.destroy();
    l_shadowDepthBuffer.destroy();
    l_lightBuffer.destroy();

    ShaderPrograms::destroy();

    SDL_GL_DeleteContext(context);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}

void drawOutput(Texture* f_texture)
{
    ImGui::Begin("Output");
    ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    ImVec2 pos = ImGui::GetCursorScreenPos();

    Settings l_settings = Settings::getInstance();
    int width = l_settings.getWidth();
    int height = l_settings.getHeight();

    ImGui::GetWindowDrawList()->AddImage(
            (void*)f_texture->getID(),
            pos,
            ImVec2(pos.x + (float)width, pos.y + (float)height),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImGui::End();
}
