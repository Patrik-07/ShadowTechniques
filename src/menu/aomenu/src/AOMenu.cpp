// Include header
#include "../inc/AOMenu.h"
#include "imgui/imgui.h"

AOMenu::AOMenu()
{
    m_settingData = AOMenuSettingData();
}

void AOMenu::draw()
{
    ImGui::Begin("Ambient Occlusion");

    ImGui::Text("Enable");
    toggleButton("Enable", &m_settingData.m_isEnable);

    if (m_settingData.m_isEnable)
    {
        ImGui::Begin("Methods");

        ImGui::RadioButton("SSAO", &m_settingData.m_aoMethod, AOMenuSettingData::SSAO);
        ImGui::RadioButton("HBAO", &m_settingData.m_aoMethod, AOMenuSettingData::HBAO);

        ImGui::End();
    }

    ImGui::End();
}