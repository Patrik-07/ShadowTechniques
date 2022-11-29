#ifndef UNTITLED3_AOMENU_H
#define UNTITLED3_AOMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "../inc/AOMenuSettingData.h"

class AOMenu : public OutputMenu<AOMenuSettingData>
{
public:
    AOMenu();

    void draw() override;

};

#endif //UNTITLED3_AOMENU_H
