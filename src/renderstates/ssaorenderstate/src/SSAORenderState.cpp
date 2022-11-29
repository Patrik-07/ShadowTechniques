// Include header
#include "../inc/SSAORenderState.h"
#include "../../../settings/inc/Settings.h"
#include "imgui/imgui.h"

SSAORenderState::SSAORenderState()
{
    m_ssaoMenu = SSAOMenu();

    m_ssaoRenderInputData = SSAORenderInputData();
    m_ssaoRenderInputData.m_settingData = m_ssaoMenu.getSettingDataPointer();

    m_ssaoRenderer = SSAORenderer();
    m_ssaoRenderer.setRenderInputDataPointer(&m_ssaoRenderInputData);

    m_aoBlurRenderInputData = AOBlurRenderInputData();
    m_aoBlurRenderInputData.m_aoTexture = m_ssaoRenderer.getOutputTexturePointer();

    m_aoBlurRenderer = AOBlurRenderer();
    m_aoBlurRenderer.setRenderInputDataPointer(&m_aoBlurRenderInputData);
}

void SSAORenderState::render()
{
    if (m_ssaoRenderInputData.m_settingData->m_isMenuEnable)
    {
        m_ssaoMenu.draw();
    }

    m_ssaoRenderer.render();

    Texture* l_aoResult;
    l_aoResult = m_ssaoRenderer.getOutputTexturePointer();

    if (m_ssaoMenu.getSettingDataPointer()->m_isBlurEnabled)
    {
        m_aoBlurRenderer.render();
        l_aoResult = m_aoBlurRenderer.getOutputTexturePointer();
    }

    if (m_ssaoRenderInputData.m_settingData->m_isMenuEnable)
    {
        Settings l_settings = Settings::getInstance();
        drawToWindow("Result", l_aoResult, l_settings.getAspectRatio() * 200.0f, 200.0f);
    }

    m_outputTexture = l_aoResult;
}

void SSAORenderState::setRenderInputData(SSAORenderStrategy::RenderInputDataType* f_ssaoRenderInputData)
{
    m_ssaoRenderInputData.m_gBuffer      = f_ssaoRenderInputData->m_gBuffer;
    m_ssaoRenderInputData.m_scene        = f_ssaoRenderInputData->m_scene;
    f_ssaoRenderInputData->m_settingData = m_ssaoMenu.getSettingDataPointer();
}

void SSAORenderState::drawToWindow(const char* f_windowName, Texture* f_texture, int f_width, int f_height)
{
    ImGui::Begin(f_windowName);

    ImVec2 pos = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddImage(
            (void*)f_texture->getID(),
            pos,
            ImVec2(pos.x + (float)f_width, pos.y + (float)f_height),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImGui::End();
}