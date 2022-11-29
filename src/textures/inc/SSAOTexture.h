#ifndef UNTITLED3_SSAOTEXTURE_H
#define UNTITLED3_SSAOTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class SSAOTexture : public Texture
{
public:
    SSAOTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_SSAOTEXTURE_H
