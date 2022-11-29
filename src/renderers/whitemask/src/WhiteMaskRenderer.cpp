// Include header
#include "../inc/WhiteMaskRenderer.h"
#include "../../../textures/inc/DefaultTexture.h"
#include "../../../textures/inc/NoiseTexture.h"

WhiteMaskRenderer::WhiteMaskRenderer() : Renderer<NullRenderStrategy>()
{
    m_outputTexture = new DefaultTexture();
    m_frameBuffer = new FrameBuffer({m_outputTexture});
    m_renderStrategy = new NullRenderStrategy(m_frameBuffer);
}