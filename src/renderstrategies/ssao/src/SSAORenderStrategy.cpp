#include "../inc/SSAORenderStrategy.h"
#include "../../../quad/inc/Quad.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"
#include "glm/gtc/type_ptr.hpp"

SSAORenderStrategy::SSAORenderStrategy(FrameBuffer* f_frameBuffer) : RenderStrategy(f_frameBuffer, ShaderPrograms::get(ShaderPrograms::SSAO)) {}

void SSAORenderStrategy::update(const SSAORenderInputData& f_renderInputData)
{
    m_shaderProgram->use();

    m_shaderProgram->setUniform("radius", f_renderInputData.m_settingData->m_radius);
    m_shaderProgram->setUniform("ssaoNoiseTexture", f_renderInputData.m_noiseTexture->getID());
    m_shaderProgram->setUniform("projectionMatrix", glm::value_ptr(f_renderInputData.m_scene->camera->projectionMatrix));
    m_shaderProgram->setUniform("viewMatrix", glm::value_ptr(f_renderInputData.m_scene->camera->viewMatrix));

    for (unsigned int i = 0; i < f_renderInputData.m_kernel.getKernel().size(); i++)
    {
        m_shaderProgram->setUniform(
            "ssaoSampleKernels[" + std::to_string(i) + "]",
            glm::value_ptr((f_renderInputData.m_kernel.getKernel())[i]),
            3
        );
    }

    m_shaderProgram->setUniform("position", f_renderInputData.m_gBuffer->getPositionTexture()->getID(), 1);
    m_shaderProgram->setUniform("normal", f_renderInputData.m_gBuffer->getNormalTexture()->getID(), 2);

    Quad& l_quad = Quad::getInstance();
    l_quad.render();
}