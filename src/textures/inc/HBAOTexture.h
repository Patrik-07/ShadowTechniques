#ifndef UNTITLED3_HBAOTEXTURE_H
#define UNTITLED3_HBAOTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class HBAOTexture : public Texture
{
public:
    HBAOTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_HBAOTEXTURE_H
