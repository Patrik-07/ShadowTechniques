#ifndef UNTITLED3_SHADOWDEPTHRENDERINPUTDATA_H
#define UNTITLED3_SHADOWDEPTHRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../framework/scene/inc/Scene.h"
#include "../../../light/inc/Light.h"

struct ShadowDepthRenderInputData : public RenderInputData
{
    Light* m_light;
    Scene* m_scene;
};

#endif //UNTITLED3_SHADOWDEPTHRENDERINPUTDATA_H
