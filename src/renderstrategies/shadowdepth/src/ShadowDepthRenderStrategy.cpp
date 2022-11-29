#include "../inc/ShadowDepthRenderStrategy.h"

ShadowDepthRenderStrategy::ShadowDepthRenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer) {}

void ShadowDepthRenderStrategy::update(const ShadowDepthRenderInputData& f_renderInputData)
{
    glCullFace(GL_FRONT);

    Scene* l_scene = f_renderInputData.m_scene;

    glm::mat4 vm = l_scene->camera->viewMatrix;
    glm::mat4 pm = l_scene->camera->projectionMatrix;

    l_scene->camera->projectionMatrix = f_renderInputData.m_light->getProjectionMatrix();
    l_scene->camera->viewMatrix = f_renderInputData.m_light->getViewMatrix();

    glClearColor(0.8f, 0.8f, 0.8f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    l_scene->draw(false);

    l_scene->camera->viewMatrix = vm;
    l_scene->camera->projectionMatrix = pm;

    glCullFace(GL_BACK);
}