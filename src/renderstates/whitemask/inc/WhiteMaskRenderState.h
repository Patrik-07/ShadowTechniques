#ifndef UNTITLED3_WHITEMASKRENDERSTATE_H
#define UNTITLED3_WHITEMASKRENDERSTATE_H

#include "../../../renderstate/inc/RenderState.h"
#include "../../../renderstrategies/null/inc/NullRenderInputData.h"
#include "../../../renderers/whitemask/inc/WhiteMaskRenderer.h"

class WhiteMaskRenderState : public RenderState
{
public:
    WhiteMaskRenderState();

    void render() override;

private:
    WhiteMaskRenderer m_whiteMaskRenderer;
    NullRenderInputData m_nullRenderInputData;

};

#endif //UNTITLED3_WHITEMASKRENDERSTATE_H
