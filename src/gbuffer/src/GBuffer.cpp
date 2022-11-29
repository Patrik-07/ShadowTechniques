// Include header
#include "../inc/GBuffer.h"
#include "../../textures/inc/DefaultTexture.h"
#include "../../textures/inc/DepthTexure.h"

GBuffer::GBuffer() :
    FrameBuffer({
        new DefaultTexture(),
        new DefaultTexture(),
        new DefaultTexture(),
        new DefaultTexture(),
        new DepthTexture()
    })
{
    m_gPositionTexture     = m_textures[0];
    m_gNormalTexture       = m_textures[1];
    m_gAlbedoTexture       = m_textures[2];
    m_textureCoordsTexture = m_textures[3];
    m_gDepthTexture        = m_textures[4];
}

Texture* GBuffer::getPositionTexture()
{
    return m_gPositionTexture;
}

Texture* GBuffer::getNormalTexture()
{
    return m_gNormalTexture;
}

Texture* GBuffer::getAlbedoTexture()
{
    return m_gAlbedoTexture;
}

Texture* GBuffer::getTextureCoordTexture()
{
    return m_textureCoordsTexture;
}

Texture* GBuffer::getDepthTexture()
{
return m_gDepthTexture;
}
