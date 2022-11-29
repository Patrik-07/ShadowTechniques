#ifndef UNTITLED3_AOSETTINGDATA_H
#define UNTITLED3_AOSETTINGDATA_H

#include "../../../settings/inc/SettingData.h"

struct AOSettingData : public SettingData
{
    AOSettingData();

    bool m_isBlurEnabled;
    bool m_isMenuEnable;

};

#endif //UNTITLED3_AOSETTINGDATA_H
