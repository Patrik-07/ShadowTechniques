#ifndef UNTITLED3_SSAOMENU_H
#define UNTITLED3_SSAOMENU_H

#include "../../../settings/inc/OutputMenu.h"
#include "SSAOSettingData.h"

class SSAOMenu : public OutputMenu<SSAOSettingData>
{
public:
    SSAOMenu();

    void draw() override;

};

#endif //UNTITLED3_SSAOMENU_H
