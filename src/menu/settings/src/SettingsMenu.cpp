// Include header
#include "../inc/SettingsMenu.h"
#include "imgui/imgui.h"

SettingsMenu::SettingsMenu()
{
    m_settingData = SettingsSettingData();
}

void SettingsMenu::draw()
{
    ImGui::Begin("Settings");

    updateCurrentSetting();

    ImGui::End();
}

void SettingsMenu::updateCurrentSetting()
{
    bool l_lightPressed = ImGui::Button("Light", ImVec2(160, 40));
    bool l_shadowPressed = ImGui::Button("Shadow Mapping", ImVec2(160, 40));
    bool l_aoPressed = ImGui::Button("Ambient Occlusion", ImVec2(160, 40));
    ImGui::NewLine();
    bool l_debugPressed = ImGui::Button("Debug", ImVec2(160, 40));

    if (l_lightPressed)
    {
        m_settingData.m_menuType = SettingsSettingData::LIGHT;
    }
    else if (l_shadowPressed)
    {
        m_settingData.m_menuType = SettingsSettingData::SHADOW_MAPPING;
    }
    else if (l_aoPressed)
    {
        m_settingData.m_menuType = SettingsSettingData::AMBIENT_OCCLUSION;
    }
    else if (l_debugPressed)
    {
        m_settingData.m_isDebugEnable = !m_settingData.m_isDebugEnable;
    }
}