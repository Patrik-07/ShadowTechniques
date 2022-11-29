#ifndef UNTITLED3_SHADOWRENDERINPUTDATA_H
#define UNTITLED3_SHADOWRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "../../../framework/opengl/texture/inc/Texture.h"
#include "glm/vec3.hpp"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../light/inc/Light.h"

struct ShadowRenderInputData : public RenderInputData
{
    Texture* m_gPosition;
    Texture* m_gNormal;

    Texture* m_shadowDepth;

    Light* m_light;
};

#endif //UNTITLED3_SHADOWRENDERINPUTDATA_H
