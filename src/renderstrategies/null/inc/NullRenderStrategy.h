#ifndef UNTITLED3_NULLRENDERSTRATEGY_H
#define UNTITLED3_NULLRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/null/inc/NullRenderInputData.h"

class NullRenderStrategy : public RenderStrategy<NullRenderInputData>
{
public:
    explicit NullRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const NullRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_NULLRENDERSTRATEGY_H
