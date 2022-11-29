// Include header
#include "../inc/HBAORenderState.h"
#include "../../../settings/inc/Settings.h"
#include "imgui/imgui.h"

HBAORenderState::HBAORenderState()
{
    m_hbaoMenu = HBAOMenu();

    m_hbaoRenderInputData = HBAORenderInputData();
    m_hbaoRenderInputData.m_settingData  = m_hbaoMenu.getSettingDataPointer();

    m_hbaoRenderer = HBAORenderer();
    m_hbaoRenderer.setRenderInputDataPointer(&m_hbaoRenderInputData);

    m_aoBlurRenderInputData = AOBlurRenderInputData();
    m_aoBlurRenderInputData.m_aoTexture = m_hbaoRenderer.getOutputTexturePointer();

    m_aoBlurRenderer = AOBlurRenderer();
    m_aoBlurRenderer.setRenderInputDataPointer(&m_aoBlurRenderInputData);
}

void HBAORenderState::render()
{
    if (m_hbaoRenderInputData.m_settingData->m_isMenuEnable)
    {
        m_hbaoMenu.draw();
    }
    m_hbaoRenderer.render();

    Texture* l_aoResult;
    l_aoResult = m_hbaoRenderer.getOutputTexturePointer();

    if (m_hbaoMenu.getSettingDataPointer()->m_isBlurEnabled)
    {
        m_aoBlurRenderer.render();
        l_aoResult = m_aoBlurRenderer.getOutputTexturePointer();
    }

    if (m_hbaoRenderInputData.m_settingData->m_isMenuEnable)
    {
        Settings l_settings = Settings::getInstance();
        drawToWindow("Result", l_aoResult, l_settings.getAspectRatio() * 200.0f, 200.0f);
    }

    m_outputTexture = l_aoResult;
}

void HBAORenderState::setRenderInputData(HBAORenderStrategy::RenderInputDataType* f_hbaoRenderInputData)
{
    m_hbaoRenderInputData.m_gBuffer      = f_hbaoRenderInputData->m_gBuffer;
    m_hbaoRenderInputData.m_scene        = f_hbaoRenderInputData->m_scene;
    f_hbaoRenderInputData->m_settingData = m_hbaoMenu.getSettingDataPointer();
}

void HBAORenderState::drawToWindow(const char* f_windowName, Texture* f_texture, int f_width, int f_height)
{
    ImGui::Begin(f_windowName);

    ImVec2 pos = ImGui::GetCursorScreenPos();

    ImGui::GetWindowDrawList()->AddImage(
        (void*)f_texture->getID(),
        pos,
        ImVec2(pos.x + (float)f_width, pos.y + (float)f_height),
        ImVec2(0, 1),
        ImVec2(1, 0)
    );

    ImGui::End();
}

