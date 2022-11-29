// Include header
#include "../inc/HBAOMenu.h"
#include "imgui/imgui.h"

HBAOMenu::HBAOMenu()
{
    m_settingData.m_isBlurEnabled = false;
}

void HBAOMenu::draw()
{
    ImGui::Begin("HBAO settings");

    toggleButton("Blur", &m_settingData.m_isBlurEnabled);
    ImGui::SameLine();
    ImGui::Text("Blur");

    ImGui::End();
}
