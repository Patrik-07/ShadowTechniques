// Include header
#include "../inc/LightMenuSettingData.h"

LightMenuSettingData::LightMenuSettingData()
{
    m_isLightEnable = false;
    m_isLightBulbEnable = false;

    m_lightPosition[0] = -6.0f;
    m_lightPosition[1] = -10.0f;
    m_lightPosition[2] = 10.0f;
}