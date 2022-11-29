#ifndef UNTITLED3_POSITIONTEXTURE_H
#define UNTITLED3_POSITIONTEXTURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class PositionTexture : public Texture
{
public:
    PositionTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_POSITIONTEXTURE_H
