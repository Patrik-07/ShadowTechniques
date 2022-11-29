#ifndef UNTITLED3_DEPTHTEXURE_H
#define UNTITLED3_DEPTHTEXURE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class DepthTexture : public Texture
{
public:
    DepthTexture();

    void generate() override;
    bool hasColorAttachment() override;

};

#endif //UNTITLED3_DEPTHTEXURE_H
