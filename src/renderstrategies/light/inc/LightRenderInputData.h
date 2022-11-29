#ifndef UNTITLED3_LIGHTRENDERINPUTDATA_H
#define UNTITLED3_LIGHTRENDERINPUTDATA_H

#include "../../../renderer/inc/RenderInputData.h"
#include "glm/ext/matrix_float4x4.hpp"
#include "../../../light/inc/Light.h"
#include "../../../gbuffer/inc/GBuffer.h"
#include "../../../menu/light/inc/LightMenuSettingData.h"

struct LightRenderInputData : public RenderInputData
{
    Light* m_light;

    GBuffer* m_gBuffer;

    Texture* m_aoTexture;
    Texture* m_shadowTexture;
    Texture* m_lightBulbTexture;

    glm::vec3* m_cameraPosition;

    LightMenuSettingData* m_lightMenuSettingData;
};

#endif //UNTITLED3_LIGHTRENDERINPUTDATA_H
