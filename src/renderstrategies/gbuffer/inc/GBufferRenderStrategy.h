#ifndef UNTITLED3_GBUFFERRENDERSTRATEGY_H
#define UNTITLED3_GBUFFERRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/gbuffer/inc/GBufferRenderInputData.h"

class GBufferRenderStrategy : public RenderStrategy<GBufferRenderInputData>
{
public:
    explicit GBufferRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const GBufferRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_GBUFFERRENDERSTRATEGY_H
