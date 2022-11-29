#include "../inc/LightRenderStrategy.h"
#include "../../../quad/inc/Quad.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"
#include "glm/gtc/type_ptr.hpp"

LightRenderStrategy::LightRenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::LIGHT)) {}

void LightRenderStrategy::update(const LightRenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    m_shaderProgram->setUniform("gPosition", f_renderInputData.m_gBuffer->getPositionTexture()->getID(), 1);
    m_shaderProgram->setUniform("gNormal", f_renderInputData.m_gBuffer->getNormalTexture()->getID(), 2);
    m_shaderProgram->setUniform("gAlbedo", f_renderInputData.m_gBuffer->getAlbedoTexture()->getID(), 3);
    m_shaderProgram->setUniform("shadowMap", f_renderInputData.m_shadowTexture->getID(), 4);
    m_shaderProgram->setUniform("aoOutput", f_renderInputData.m_aoTexture->getID(), 5);
    m_shaderProgram->setUniform("lightBulb", f_renderInputData.m_lightBulbTexture->getID(), 6);
    m_shaderProgram->setUniform("lightPos", glm::value_ptr(f_renderInputData.m_light->getPosition()), 3);
    m_shaderProgram->setUniform("cameraPos", glm::value_ptr(*f_renderInputData.m_cameraPosition), 3);
    m_shaderProgram->setUniform("isLightEnable", f_renderInputData.m_lightMenuSettingData->m_isLightEnable);
    m_shaderProgram->setUniform("isLightBulbEnable", f_renderInputData.m_lightMenuSettingData->m_isLightBulbEnable);

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}