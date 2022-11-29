#include "../inc/NullRenderStrategy.h"
#include "../../../quad/inc/Quad.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"

NullRenderStrategy::NullRenderStrategy(FrameBuffer* f_frameBuffer) :
    RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::NEGLECT)) {}

void NullRenderStrategy::update(const NullRenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}