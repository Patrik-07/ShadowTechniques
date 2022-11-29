#ifndef UNTITLED3_DEFAULTTEXTURE_H
#define UNTITLED3_DEFAULTTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class DefaultTexture : public Texture
{
public:
    DefaultTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_DEFAULTTEXTURE_H
