#ifndef UNTITLED3_SSAORENDERSTATE_H
#define UNTITLED3_SSAORENDERSTATE_H

#include "../../../renderstate/inc/RenderState.h"
#include "../../../menu/ssao/inc/SSAOMenu.h"
#include "../../../renderers/ssao/inc/SSAORenderer.h"
#include "../../../renderers/aoblur/inc/AOBlurRenderer.h"

class SSAORenderState : public RenderState
{
public:
    SSAORenderState();

    void render() override;
    void setRenderInputData(SSAORenderStrategy::RenderInputDataType* f_ssaoRenderInputData);

private:
    void drawToWindow(const char* f_windowName, Texture* f_texture, int f_width, int f_height);

    SSAORenderInputData m_ssaoRenderInputData;
    AOBlurRenderInputData m_aoBlurRenderInputData;

    SSAORenderer m_ssaoRenderer;
    AOBlurRenderer m_aoBlurRenderer;

    SSAOMenu m_ssaoMenu;
};

#endif //UNTITLED3_SSAORENDERSTATE_H
