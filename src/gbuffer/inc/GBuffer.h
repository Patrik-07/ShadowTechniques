#ifndef UNTITLED3_GBUFFER_H
#define UNTITLED3_GBUFFER_H

#include "../../framework/opengl/buffer/FramerBuffer.h"

class GBuffer : public FrameBuffer
{
public:
    GBuffer();

    Texture* getPositionTexture();
    Texture* getNormalTexture();
    Texture* getAlbedoTexture();
    Texture* getDepthTexture();
    Texture* getTextureCoordTexture();

private:
    Texture* m_gPositionTexture;
    Texture* m_gNormalTexture;
    Texture* m_gAlbedoTexture;
    Texture* m_gDepthTexture;
    Texture* m_textureCoordsTexture;

};

#endif //UNTITLED3_GBUFFER_H
