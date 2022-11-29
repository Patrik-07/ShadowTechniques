#ifndef UNTITLED3_OUTPUTMENU_H
#define UNTITLED3_OUTPUTMENU_H

#include "Menu.h"

template<typename SettingData>
class OutputMenu : public Menu
{
public:
    typedef SettingData SettingDataType;

    SettingData* getSettingDataPointer()
    {
        return &m_settingData;
    }

protected:
    SettingData m_settingData;

};

#endif //UNTITLED3_OUTPUTMENU_H
