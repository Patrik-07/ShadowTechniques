#ifndef UNTITLED3_NORMALTEXTURE_H
#define UNTITLED3_NORMALTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class NormalTexture : public Texture
{
public:
    NormalTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_NORMALTEXTURE_H
