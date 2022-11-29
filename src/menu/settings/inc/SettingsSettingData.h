#ifndef UNTITLED3_SETTINGSSETTINGDATA_H
#define UNTITLED3_SETTINGSSETTINGDATA_H

#include "../../../settings/inc/SettingData.h"

struct SettingsSettingData : public SettingData
{
public:
    SettingsSettingData();

    enum MenuType
    {
        LIGHT,
        SHADOW_MAPPING,
        AMBIENT_OCCLUSION
    };

    unsigned int m_menuType;
    bool m_isDebugEnable;

};

#endif //UNTITLED3_SETTINGSSETTINGDATA_H
