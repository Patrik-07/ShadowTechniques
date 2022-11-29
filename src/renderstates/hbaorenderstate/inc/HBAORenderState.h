#ifndef UNTITLED3_HBAORENDERSTATE_H
#define UNTITLED3_HBAORENDERSTATE_H

#include "../../../renderstate/inc/RenderState.h"
#include "../../../menu/hbao/inc/HBAOMenu.h"
#include "../../../renderers/hbao/inc/HBAORenderer.h"
#include "../../../renderers/aoblur/inc/AOBlurRenderer.h"

class HBAORenderState : public RenderState
{
public:
    HBAORenderState();

    void render() override;
    void setRenderInputData(HBAORenderStrategy::RenderInputDataType* f_hbaoRenderInputData);

private:
    void drawToWindow(const char* f_windowName, Texture* f_texture, int f_width, int f_height);

    HBAORenderInputData m_hbaoRenderInputData;
    AOBlurRenderInputData m_aoBlurRenderInputData;

    HBAORenderer m_hbaoRenderer;
    AOBlurRenderer m_aoBlurRenderer;

    HBAOMenu m_hbaoMenu;
};

#endif //UNTITLED3_HBAORENDERSTATE_H
