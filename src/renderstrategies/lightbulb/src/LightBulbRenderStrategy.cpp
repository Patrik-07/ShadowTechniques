// Include header
#include "../inc/LightBulbRenderStrategy.h"

LightBulbRenderStrategy::LightBulbRenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::LIGHTBULB)) {}

void LightBulbRenderStrategy::update(const LightBulbRenderInputData& f_renderInputData)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shaderProgram->use();

    f_renderInputData.m_scene->draw(false);
}