// Include header
#include "../inc/AOBlurRenderer.h"
#include "../../../textures/inc/DefaultTexture.h"
#include "../../../textures/inc/NoiseTexture.h"

AOBlurRenderer::AOBlurRenderer() : Renderer<AOBlurRenderStrategy>()
{
    m_outputTexture = new DefaultTexture();
    m_frameBuffer = new FrameBuffer({m_outputTexture});
    m_renderStrategy = new AOBlurRenderStrategy(m_frameBuffer);
}