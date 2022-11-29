#ifndef UNTITLED3_SHADOWTEXTURE_H
#define UNTITLED3_SHADOWTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class ShadowTexture : public Texture
{
public:
    ShadowTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_SHADOWTEXTURE_H
