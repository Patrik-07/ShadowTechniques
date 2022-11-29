#ifndef UNTITLED3_AOMENUSETTINGDATA_H
#define UNTITLED3_AOMENUSETTINGDATA_H

#include "../../../settings/inc/SettingData.h"

struct AOMenuSettingData : public SettingData
{
    AOMenuSettingData();

    enum AOMethod
    {
        SSAO,
        HBAO
    };

    int m_aoMethod;
    bool m_isEnable;
};


#endif //UNTITLED3_AOMENUSETTINGDATA_H
