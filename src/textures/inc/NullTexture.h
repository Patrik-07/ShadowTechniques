#ifndef UNTITLED3_NULLTEXTURE_H
#define UNTITLED3_NULLTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class NullTexture : public Texture
{
public:
    NullTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_NULLTEXTURE_H
