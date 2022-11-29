#ifndef UNTITLED3_SHADOWRENDERSTRATEGY_H
#define UNTITLED3_SHADOWRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/shadow//inc/ShadowRenderInputData.h"

class ShadowRenderStrategy : public RenderStrategy<ShadowRenderInputData>
{
public:
    explicit ShadowRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const ShadowRenderInputData& f_renderInputData) override;

};
#endif //UNTITLED3_SHADOWRENDERSTRATEGY_H
