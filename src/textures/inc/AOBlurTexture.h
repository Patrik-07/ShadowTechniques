#ifndef UNTITLED3_AOBLURTEXTURE_H
#define UNTITLED3_AOBLURTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class AOBlurTexture : public Texture
{
public:
    AOBlurTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_AOBLURTEXTURE_H
