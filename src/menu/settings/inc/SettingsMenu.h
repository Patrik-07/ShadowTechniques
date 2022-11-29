#ifndef UNTITLED3_SETTINGSMENU_H
#define UNTITLED3_SETTINGSMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "SettingsSettingData.h"

class SettingsMenu : public OutputMenu<SettingsSettingData>
{
public:
    SettingsMenu();

    void draw() override;

private:
    void updateCurrentSetting();

};

#endif //UNTITLED3_SETTINGSMENU_H
