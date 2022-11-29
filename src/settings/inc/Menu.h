#ifndef UNTITLED3_MENU_H
#define UNTITLED3_MENU_H

#include "SettingData.h"

class Menu
{
public:
    virtual void draw() = 0;

protected:
    void toggleButton(const char* str_id, bool* v);

};

#endif //UNTITLED3_MENU_H
