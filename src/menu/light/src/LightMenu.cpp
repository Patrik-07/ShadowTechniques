// Include header
#include "../inc/LightMenu.h"
#include "imgui/imgui.h"
#include "glm/vec3.hpp"

LightMenu::LightMenu()
{
    m_settingData = LightMenuSettingData();
}

void LightMenu::draw()
{
    ImGui::Begin("Light");

    ImGui::Text("Enable");
    toggleButton("Enable", &m_settingData.m_isLightEnable);

    if (m_settingData.m_isLightEnable)
    {
        ImGui::Begin("Light settings");

        ImGui::DragFloat3("Position", m_settingData.m_lightPosition, 0.25f);

        ImGui::NewLine();

        toggleButton("Lightbulb", &m_settingData.m_isLightBulbEnable);
        ImGui::SameLine();
        ImGui::Text("Lightbulb");

        ImGui::End();
    }

    ImGui::End();
}