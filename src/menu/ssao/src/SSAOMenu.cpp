// Include header
#include "../inc/SSAOMenu.h"
#include "imgui/imgui.h"

SSAOMenu::SSAOMenu()
{
    m_settingData.m_radius = 2.5f;
    m_settingData.m_isBlurEnabled = false;
    m_settingData.m_isMenuEnable = false;
}

void SSAOMenu::draw()
{
    ImGui::Begin("SSAO settings");

    ImGui::SliderFloat("Radius", &m_settingData.m_radius, 1.0f, 5.0f);
    toggleButton("Blur", &m_settingData.m_isBlurEnabled);
    ImGui::SameLine();
    ImGui::Text("Blur");

    ImGui::End();
}