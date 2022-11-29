#ifndef UNTITLED3_LIGHTBULBRENDERINPUTDATA_H
#define UNTITLED3_LIGHTBULBRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../framework/scene/inc/Scene.h"

struct LightBulbRenderInputData : public RenderInputData
{
    Scene* m_scene;
};

#endif //UNTITLED3_LIGHTBULBRENDERINPUTDATA_H
