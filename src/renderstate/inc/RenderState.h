#ifndef UNTITLED3_RENDERSTATE_H
#define UNTITLED3_RENDERSTATE_H

#include "../../framework/opengl/texture/inc/Texture.h"

class RenderState
{
public:
    virtual void render() = 0;
    Texture* getOutputTexturePointer();

protected:
    Texture* m_outputTexture;

};

#endif //UNTITLED3_RENDERSTATE_H
