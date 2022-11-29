#ifndef UNTITLED3_NOISETEXTURE_H
#define UNTITLED3_NOISETEXTURE_H

#include <vector>
#include "../../framework/opengl/texture/inc/Texture.h"
#include "glm/vec3.hpp"

class NoiseTexture : public Texture
{
public:
    NoiseTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_NOISETEXTURE_H
