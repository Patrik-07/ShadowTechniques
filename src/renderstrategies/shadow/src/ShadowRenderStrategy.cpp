// Include header
#include "../inc/ShadowRenderStrategy.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"
#include "glm/gtc/type_ptr.hpp"
#include "../../../quad/inc/Quad.h"

ShadowRenderStrategy::ShadowRenderStrategy(FrameBuffer* f_frameBuffer) :
    RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::SHADOW))
{}

void ShadowRenderStrategy::update(const ShadowRenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    m_shaderProgram->setUniform("gPosition", f_renderInputData.m_gPosition->getID(), 1);
    m_shaderProgram->setUniform("gNormal", f_renderInputData.m_gNormal->getID(), 2);

    m_shaderProgram->setUniform("shadowDepth", f_renderInputData.m_shadowDepth->getID(), 3);

    m_shaderProgram->setUniform("lightPosition", glm::value_ptr(f_renderInputData.m_light->getPosition()), 3);
    m_shaderProgram->setUniform("lightSpaceMatrix", glm::value_ptr(f_renderInputData.m_light->getProjectionMatrix() * f_renderInputData.m_light->getViewMatrix()));

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}