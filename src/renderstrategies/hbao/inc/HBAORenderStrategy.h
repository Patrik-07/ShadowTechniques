#ifndef UNTITLED3_HBAORENDERSTRATEGY_H
#define UNTITLED3_HBAORENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/hbao/inc/HBAORenderInputData.h"

class HBAORenderStrategy : public RenderStrategy<HBAORenderInputData>
{
public:
    explicit HBAORenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const HBAORenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_HBAORENDERSTRATEGY_H
