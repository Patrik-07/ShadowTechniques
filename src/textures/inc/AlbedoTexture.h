#ifndef UNTITLED3_ALBEDOTEXTURE_H
#define UNTITLED3_ALBEDOTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class AlbedoTexture : public Texture
{
public:
    AlbedoTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_ALBEDOTEXTURE_H
