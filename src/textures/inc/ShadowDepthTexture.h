#ifndef UNTITLED3_SHADOWDEPTHTEXTURE_H
#define UNTITLED3_SHADOWDEPTHTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class ShadowDepthTexture : public Texture
{
public:
    ShadowDepthTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_SHADOWDEPTHTEXTURE_H
