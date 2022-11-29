#ifndef UNTITLED3_LIGHTTEXTURE_H
#define UNTITLED3_LIGHTTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class LightTexture : public Texture
{
public:
    LightTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif // UNTITLED3_LIGHTTEXTURE_H
