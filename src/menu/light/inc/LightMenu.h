#ifndef UNTITLED3_LIGHTMENU_H
#define UNTITLED3_LIGHTMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "../inc/LightMenuSettingData.h"

class LightMenu : public OutputMenu<LightMenuSettingData>
{
public:
    LightMenu();

    void draw() override;

};

#endif //UNTITLED3_LIGHTMENU_H
