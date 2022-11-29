#pragma once

#include "imgui/imgui.h"
#include "imgui/sdl_opengl3/imgui_impl_sdl.h"
#include "imgui/sdl_opengl3/imgui_impl_opengl3.h"

#include "SDL2/SDL.h"

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"

// Opengl includes
#include "Opengl/Buffer/VertexArray.h"
#include "Opengl/Buffer/VertexBuffer.h"
#include "Opengl/Buffer/ElementBuffer.h"
#include "Opengl/Buffer/FramerBuffer.h"

#include "Opengl/Shader/Shader.h"
#include "Opengl/Shader/ShaderProgram.h"

//#include "Opengl/Texture0/Texture0.h"

// model includes
#include "model/Model.h"

// AssimpLoader includes
#include "loader/modelLoader/ModelLoader.h"
#include "loader/modelLoader/AssimpLoader.h"

#include "scene/inc/SceneObject.h"
#include "scene/Camera.h"
#include "scene/Grid.h"
#include "scene/inc/Scene.h"

#include "utility/Timer.h"
#include "utility/CameraHandler.h"
#include "utility/LoadingBar.h"
#include "utility/ImGuiRenderer.h"

#include "utility/Resources.h"
#include "../settings/inc/Settings.h"

void initOpenGL() {
    glewExperimental = GL_TRUE;
    glewInit();

    Settings l_settings = Settings::getInstance();
    glViewport(0, 0, l_settings.getWidth(), l_settings.getHeight());

    glEnable(GL_MULTISAMPLE);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void initSDL(SDL_Window*& window, SDL_GLContext& context) {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("Error: %s\n", SDL_GetError());
        exit(-1);
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);

    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
    SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    Settings l_settings = Settings::getInstance();
    auto window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
    window = SDL_CreateWindow(
        "ShadowTechniques",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        l_settings.getWidth(),
        l_settings.getHeight(),
        window_flags
    );

    context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);
    SDL_GL_SetSwapInterval(1);
}

bool processEvent(SDL_Event event) {
    ImGui_ImplSDL2_ProcessEvent(&event);
    if (event.type == SDL_QUIT)
        return false;
    return true;
}

ImGuiRenderer init(SDL_Window*& window, SDL_GLContext& context) {
    initSDL(window, context);
    initOpenGL();
    return ImGuiRenderer(window, context);
}