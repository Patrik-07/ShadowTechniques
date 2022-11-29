#ifndef UNTITLED3_SHADOWMAPPINGMENU_H
#define UNTITLED3_SHADOWMAPPINGMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "ShadowMappingSettingData.h"

class ShadowMappingMenu : public OutputMenu<ShadowMappingSettingData>
{
public:
    ShadowMappingMenu();

    void draw() override;

};

#endif //UNTITLED3_SHADOWMAPPINGMENU_H
