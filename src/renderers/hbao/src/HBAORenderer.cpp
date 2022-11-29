// Include header
#include "../inc/HBAORenderer.h"
#include "../../../textures/inc/DefaultTexture.h"
#include "../../../textures/inc/NoiseTexture.h"

HBAORenderer::HBAORenderer() : Renderer<HBAORenderStrategy>()
{
    m_outputTexture = new DefaultTexture();
    m_frameBuffer = new FrameBuffer({m_outputTexture});
    m_renderStrategy = new HBAORenderStrategy(m_frameBuffer);
}