// Include header
#include "../inc/DebugMenu.h"
#include "imgui/imgui.h"
#include "../../../settings/inc/Settings.h"

void DebugMenu::draw()
{
    ImGui::Begin("Debug");

    float l_scale = 0.175f;
    int spacing = 15;

    Settings l_settings = Settings::getInstance();

    ImVec2 pos = ImGui::GetCursorScreenPos();
    ImGui::GetWindowDrawList()->AddImage(
            (void*)m_gBuffer->getPositionTexture()->getID(),
            pos,
            ImVec2(pos.x + (float)l_settings.getWidth() * l_scale, pos.y + (float)l_settings.getHeight() * l_scale),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImVec2 pos2 = ImVec2(pos.x  + (float)l_settings.getWidth() * l_scale + spacing, pos.y);
    ImGui::GetWindowDrawList()->AddImage(
            (void*)m_gBuffer->getNormalTexture()->getID(),
            pos2,
            ImVec2(pos2.x + (float)l_settings.getWidth() * l_scale, pos2.y + (float)l_settings.getHeight() * l_scale),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImVec2 pos3 = ImVec2(pos2.x + (float)l_settings.getWidth() * l_scale + spacing, pos2.y);
    ImGui::GetWindowDrawList()->AddImage(
            (void*)m_gBuffer->getTextureCoordTexture()->getID(),
            pos3,
            ImVec2(pos3.x + (float)l_settings.getWidth() * l_scale, pos3.y + (float)l_settings.getHeight() * l_scale),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImVec2 pos4 = ImVec2(pos3.x + (float)l_settings.getWidth() * l_scale + spacing, pos3.y);
    ImGui::GetWindowDrawList()->AddImage(
            (void*)m_gBuffer->getAlbedoTexture()->getID(),
            pos4,
            ImVec2(pos4.x + (float)l_settings.getWidth() * l_scale, pos4.y + (float)l_settings.getHeight() * l_scale),
            ImVec2(0, 1),
            ImVec2(1, 0)
    );

    ImGui::End();
}

void DebugMenu::setGBufferPointer(GBuffer* f_gBuffer)
{
    m_gBuffer = f_gBuffer;
}
