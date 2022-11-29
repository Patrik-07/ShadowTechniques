// Include header
#include "../inc/ShadowMappingMenu.h"
#include "imgui/imgui.h"

ShadowMappingMenu::ShadowMappingMenu()
{
    m_settingData = ShadowMappingSettingData();
}

void ShadowMappingMenu::draw()
{
    ImGui::Begin("Shadow Mapping");

    ImGui::Text("Enable");
    toggleButton("Enable", &m_settingData.m_isEnable);

    ImGui::End();
}