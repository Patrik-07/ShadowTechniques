#ifndef UNTITLED3_HBAORENDERINPUTDATA_H
#define UNTITLED3_HBAORENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../framework/opengl/texture/inc/Texture.h"
#include "../../../renderers/ssao/inc/Kernel.h"
#include "../../../framework/scene/inc/Scene.h"
#include "../../../menu/hbao/inc/HBAOSettingData.h"
#include "../../../gbuffer/inc/GBuffer.h"

struct HBAORenderInputData : public RenderInputData
{
    HBAORenderInputData();

    HBAOSettingData* m_settingData;

    Scene* m_scene;

    Kernel m_kernel;

    GBuffer* m_gBuffer;

    Texture* m_noiseTexture;
};

#endif //UNTITLED3_HBAORENDERINPUTDATA_H
