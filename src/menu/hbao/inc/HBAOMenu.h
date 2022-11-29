#ifndef UNTITLED3_HBAOMENU_H
#define UNTITLED3_HBAOMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "HBAOSettingData.h"

class HBAOMenu : public OutputMenu<HBAOSettingData>
{
public:
    HBAOMenu();

    void draw() override;

};

#endif //UNTITLED3_HBAOMENU_H
