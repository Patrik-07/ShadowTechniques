// Include header
#include "../inc/SSAORenderer.h"
#include "../../../textures/inc/DefaultTexture.h"
#include "../../../textures/inc/NoiseTexture.h"

SSAORenderer::SSAORenderer() : Renderer<SSAORenderStrategy>()
{
    m_outputTexture = new DefaultTexture();
    m_frameBuffer = new FrameBuffer({m_outputTexture});
    m_renderStrategy = new SSAORenderStrategy(m_frameBuffer);
}