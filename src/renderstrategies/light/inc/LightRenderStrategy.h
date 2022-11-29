#ifndef UNTITLED3_LIGHTRENDERSTRATEGY_H
#define UNTITLED3_LIGHTRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/light/inc/LightRenderInputData.h"

class LightRenderStrategy : public RenderStrategy<LightRenderInputData>
{
public:
    explicit LightRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const LightRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_LIGHTRENDERSTRATEGY_H
