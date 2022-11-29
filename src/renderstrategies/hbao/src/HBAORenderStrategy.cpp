#include "../inc/HBAORenderStrategy.h"
#include "../../../quad/inc/Quad.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"
#include "glm/gtc/type_ptr.hpp"

HBAORenderStrategy::HBAORenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::HBAO)) {}

void HBAORenderStrategy::update(const HBAORenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    m_shaderProgram->setUniform("ssaoNoiseTexture", f_renderInputData.m_noiseTexture->getID());
    m_shaderProgram->setUniform("projectionMatrix", glm::value_ptr(f_renderInputData.m_scene->camera->projectionMatrix));
    m_shaderProgram->setUniform("viewMatrix", glm::value_ptr(f_renderInputData.m_scene->camera->viewMatrix));

    m_shaderProgram->setUniform("position", f_renderInputData.m_gBuffer->getPositionTexture()->getID(), 1);
    m_shaderProgram->setUniform("normal", f_renderInputData.m_gBuffer->getNormalTexture()->getID(), 2);
    m_shaderProgram->setUniform("depthMap", f_renderInputData.m_gBuffer->getDepthTexture()->getID(), 3);

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}