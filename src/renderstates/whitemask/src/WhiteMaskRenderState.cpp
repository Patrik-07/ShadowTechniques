// Include header
#include "../inc/WhiteMaskRenderState.h"

WhiteMaskRenderState::WhiteMaskRenderState()
{
    m_nullRenderInputData = NullRenderInputData();
    m_whiteMaskRenderer = WhiteMaskRenderer();

    m_whiteMaskRenderer.setRenderInputDataPointer(&m_nullRenderInputData);
}

void WhiteMaskRenderState::render()
{
    m_whiteMaskRenderer.render();
    m_outputTexture = m_whiteMaskRenderer.getOutputTexturePointer();
}