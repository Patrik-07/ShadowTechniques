#ifndef UNTITLED3_LIGHTMENUSETTINGDATA_H
#define UNTITLED3_LIGHTMENUSETTINGDATA_H

#include "../../../settings/inc/SettingData.h"
#include "glm/vec3.hpp"

struct LightMenuSettingData : public SettingData
{
    LightMenuSettingData();

    bool m_isLightEnable;
    bool m_isLightBulbEnable;
    float m_lightPosition[3];

};


#endif //UNTITLED3_LIGHTMENUSETTINGDATA_H
