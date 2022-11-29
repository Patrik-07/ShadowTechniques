#include "../inc/AOBlurRenderStrategy.h"
#include "../../../quad/inc/Quad.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"

AOBlurRenderStrategy::AOBlurRenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::AO_BLUR)) {}

void AOBlurRenderStrategy::update(const AOBlurRenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    m_shaderProgram->setUniform("ssaoInput", f_renderInputData.m_aoTexture->getID());

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}