#ifndef UNTITLED3_AOBLURRENDERSTRATEGY_H
#define UNTITLED3_AOBLURRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/aoblur/inc/AOBlurRenderInputData.h"

class AOBlurRenderStrategy : public RenderStrategy<AOBlurRenderInputData>
{
public:
    explicit AOBlurRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const AOBlurRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_AOBLURRENDERSTRATEGY_H
