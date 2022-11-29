#ifndef UNTITLED3_AOBLURRENDERINPUTDATA_H
#define UNTITLED3_AOBLURRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "../../../framework/opengl/texture/inc/Texture.h"

struct AOBlurRenderInputData : public RenderInputData
{
    Texture* m_aoTexture;
    
};

#endif //UNTITLED3_AOBLURRENDERINPUTDATA_H
