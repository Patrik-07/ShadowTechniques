#ifndef UNTITLED3_GBUFFERRENDERINPUTDATA_H
#define UNTITLED3_GBUFFERRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../framework/scene/inc/Scene.h"

struct GBufferRenderInputData : public RenderInputData
{
    Scene* m_scene;
};

#endif //UNTITLED3_GBUFFERRENDERINPUTDATA_H
