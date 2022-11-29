#ifndef UNTITLED3_SSAOSETTINGDATA_H
#define UNTITLED3_SSAOSETTINGDATA_H

#include "../../ao/inc/AOSettingData.h"

struct SSAOSettingData : public AOSettingData
{
    SSAOSettingData();

    float m_radius;
};

#endif //UNTITLED3_SSAOSETTINGDATA_H
