#ifndef UNTITLED3_DEBUGMENU_H
#define UNTITLED3_DEBUGMENU_H

#include "../../../settings/inc/Menu.h"
#include "../../../settings/inc/SettingData.h"
#include "../../../gbuffer/inc/GBuffer.h"

class DebugMenu : public Menu
{
public:
    void draw() override;
    void setGBufferPointer(GBuffer* f_gBuffer);

private:
    GBuffer* m_gBuffer;

};


#endif //UNTITLED3_DEBUGMENU_H
