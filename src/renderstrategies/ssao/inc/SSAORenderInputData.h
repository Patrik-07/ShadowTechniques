#ifndef UNTITLED3_SSAORENDERINPUTDATA_H
#define UNTITLED3_SSAORENDERINPUTDATA_H

#include <vector>
#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../menu/ssao/inc/SSAOSettingData.h"
#include "../../../framework/scene/inc/Scene.h"
#include "../../../renderers/ssao/inc/Kernel.h"
#include "../../../framework/opengl/texture/inc/Texture.h"
#include "../../../gbuffer/inc/GBuffer.h"

struct SSAORenderInputData : public RenderInputData
{
    SSAORenderInputData();

    SSAOSettingData* m_settingData;

    Scene* m_scene;

    Kernel m_kernel;

    GBuffer* m_gBuffer;

    Texture* m_noiseTexture;
};

#endif //UNTITLED3_SSAORENDERINPUTDATA_H
