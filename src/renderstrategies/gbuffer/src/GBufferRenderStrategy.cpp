// Include header
#include "../inc/GBufferRenderStrategy.h"

GBufferRenderStrategy::GBufferRenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::GBUFFER)) {}

void GBufferRenderStrategy::update(const GBufferRenderInputData& f_renderInputData)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shaderProgram->use();

    f_renderInputData.m_scene->draw(false);
}