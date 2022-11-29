#ifndef UNTITLED3_SSAORENDERSTRATEGY_H
#define UNTITLED3_SSAORENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/ssao/inc/SSAORenderInputData.h"

class SSAORenderStrategy : public RenderStrategy<SSAORenderInputData>
{
public:
    explicit SSAORenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const SSAORenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_SSAORENDERSTRATEGY_H
