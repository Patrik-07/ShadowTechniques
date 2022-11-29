#pragma once

#include "imgui/imgui.h"
#include "imgui/sdl_opengl3/imgui_impl_sdl.h"
#include "imgui/sdl_opengl3/imgui_impl_opengl3.h"

#include "SDL2/SDL.h"
//#include "../opengl/buffer/FramerBuffer.h"
//#include "../opengl/buffer/PositionBuffer.h"
//#include "../opengl/buffer/GBuffer.h"
//#include "../scene/GBufferUniform.h"

#include "../scene/inc/Scene.h"
#include "../animation/Animator.h"

float lerp(float a, float b, float f)
{
    return a + f * (b - a);
}

class ImGuiRenderer {
    ImGuiIO* io;
//    FrameBuffer frameBuffer;
//    FrameBuffer depthBuffer;
//    FrameBuffer normalBuffer;
//    FrameBuffer solidBuffer;
//    FrameBuffer positionBuffer;
//    ShaderProgram depthProgram;
//    GBuffer gBuffer;

public:
    ImGuiRenderer(SDL_Window*& window, SDL_GLContext& context) {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        io = &ImGui::GetIO();
        io->ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io->ConfigFlags |= ImGuiConfigFlags_DockingEnable;
        io->ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;
        io->ConfigFlags |= ImGuiWindowFlags_NoDocking;

        ImGui::StyleColorsDark();

        ImGuiStyle& style = ImGui::GetStyle();
        if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        ImGui_ImplSDL2_InitForOpenGL(window, context);
        ImGui_ImplOpenGL3_Init("#version 330 core");

        int w, h;
        SDL_GetWindowSize(window, &w, &h);
//        frameBuffer = FrameBuffer::create(w, h);
//        normalBuffer = FrameBuffer::create(w, h);
//        solidBuffer = FrameBuffer::create(w, h);
//        depthBuffer = FrameBuffer::create(1024, 1024);
//        positionBuffer = FrameBuffer::create(w, h);
//        gBuffer = GBuffer::create(w, h);
    }

    void resize(int w, int h) {
//        frameBuffer = FrameBuffer::create(w, h);
//        normalBuffer = FrameBuffer::create(w, h);
//        solidBuffer = FrameBuffer::create(w, h);
//        positionBuffer = FrameBuffer::create(w, h);
//        gBuffer = GBuffer::create(w, h);
    }

    void preRender() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame();
        ImGui::NewFrame();
        ImGui::DockSpaceOverViewport();
    }

//    void sceneRender(Scene& scene, float deltaTime, glm::vec3 lightPos, unsigned int ssaoNoiseTexture, const std::vector<glm::vec3>& ssaoSampleKernels, ShaderProgram& gBufferShader) {
//        //////////////////
//        // Depth buffer //
//        //////////////////
//        glViewport(0, 0, 1024, 1024);
//        glCullFace(GL_FRONT);
//        depthBuffer.bind();
//
//        glm::mat4 lightProjection = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 80.0f);
//        glm::mat4 lightView = glm::lookAt(
//            glm::vec3(lightPos.x, lightPos.y, lightPos.z),
//            glm::vec3(0.0f, 0.0f, 0.0f),
//            glm::vec3(0.0f, 1.0f, 0.0f)
//        );
//        glm::mat4 lightSpaceMatrix = lightProjection * lightView;
//
//        glm::mat4 v = scene.camera.viewMatrix;
//        glm::mat4 p = scene.camera.projectionMatrix;
//
//        scene.camera.viewMatrix = lightView;
//        scene.camera.projectionMatrix = lightProjection;
//
//        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        scene.update(deltaTime, false);
//        scene.draw(true);
//
//        scene.camera.viewMatrix = v;
//        scene.camera.projectionMatrix = p;
//
//        depthBuffer.unbind();
//        glCullFace(GL_BACK);
//
//        ///////////
//        // Scene //
//        ///////////
//        glViewport(0, 0, scene.width, scene.height);
//        frameBuffer.bind();
//
//        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        SceneObject* fox = scene.getSceneObject(0);
//        ShaderProgram& foxShader = fox->getShader();
//        scene.update(deltaTime, true);
//        foxShader.setUniform("depthMap", depthBuffer.depthID, 1);
//        foxShader.setUniform("lightSpaceMatrix", glm::value_ptr(lightSpaceMatrix));
//        foxShader.setUniform("viewPos", glm::value_ptr(scene.camera.position), 3);
//        foxShader.setUniform("lightPos", glm::value_ptr(lightPos), 3);
//        foxShader.setUniform("ssaoNoiseTexture", ssaoNoiseTexture, 2);
//        for (unsigned int i = 0; i < 64; i++) {
//            foxShader.setUniform("ssaoSampleKernels[" + std::to_string(i) + "]", glm::value_ptr(ssaoSampleKernels[i]), 3);
//        }
//
//        foxShader.setUniform("enablePosition", false);
//        foxShader.setUniform("enableNormal", false);
//        scene.draw(true);
//
//        frameBuffer.unbind();
//
//        ImGui::Begin("Scene");
//        ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
//        scene.hasFocus = ImGui::IsWindowFocused();
//        ImVec2 pos1 = ImGui::GetCursorScreenPos();
//        ImGui::GetWindowDrawList()->AddImage(
//            (void*)frameBuffer.textureID,
//            pos1,
//            ImVec2(pos1.x + (float)scene.width, pos1.y + (float)scene.height),
//            ImVec2(0, 1),
//            ImVec2(1, 0)
//        );
//        ImGui::End();
//
//        normalBuffer.bind();
//
//        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        scene.update(deltaTime, true);
//
//        foxShader.setUniform("enablePosition", false);
//        foxShader.setUniform("enableNormal", true);
//        scene.draw(true);
//
//        normalBuffer.unbind();
//
//        ImGui::Begin("Normal");
//        ImVec2 pos3 = ImGui::GetCursorScreenPos();
//        ImGui::GetWindowDrawList()->AddImage(
//            (void*)normalBuffer.textureID,
//            pos3,
//            ImVec2(pos3.x + (float)scene.width, pos3.y + (float)scene.height),
//            ImVec2(0, 1),
//            ImVec2(1, 0)
//        );
//        ImGui::End();
//
//        positionBuffer.bind();
//
//        glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//        scene.update(deltaTime, true);
//        foxShader.setUniform("gPosition", frameBuffer.gPosition, 1);
//        foxShader.setUniform("depthMap", depthBuffer.depthID, 1);
//        foxShader.setUniform("lightSpaceMatrix", glm::value_ptr(lightSpaceMatrix));
//        foxShader.setUniform("viewPos", glm::value_ptr(scene.camera.position), 3);
//        foxShader.setUniform("lightPos", glm::value_ptr(glm::vec3(-3.0f, 4.0f, -1.0f)), 3);
//        foxShader.setUniform("ssaoNoiseTexture", ssaoNoiseTexture, 2);
//        for (unsigned int i = 0; i < 64; i++) {
//            foxShader.setUniform("ssaoSampleKernels[" + std::to_string(i) + "]", glm::value_ptr(ssaoSampleKernels[i]), 3);
//        }
//        foxShader.setUniform("enablePosition", true);
//        foxShader.setUniform("enableNormal", false);
//        scene.draw(true);
//
//        positionBuffer.unbind();
//
//        ImGui::Begin("Position");
//        ImVec2 pos4 = ImGui::GetCursorScreenPos();
//        ImGui::GetWindowDrawList()->AddImage(
//            (void*)positionBuffer.textureID,
//            pos4,
//            ImVec2(pos4.x + (float)scene.width, pos4.y + (float)scene.height),
//            ImVec2(0, 1),
//            ImVec2(1, 0)
//        );
//        ImGui::End();
//    }

    void postRender() {
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io->ConfigFlags & ImGuiConfigFlags_ViewportsEnable) {
            SDL_Window* backup_current_window = SDL_GL_GetCurrentWindow();
            SDL_GLContext backup_current_context = SDL_GL_GetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            SDL_GL_MakeCurrent(backup_current_window, backup_current_context);
        }
    }
};