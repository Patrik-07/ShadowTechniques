#ifndef UNTITLED3_LIGHTBULBRENDERSTRATEGY_H
#define UNTITLED3_LIGHTBULBRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/lightbulb//inc/LightBulbRenderInputData.h"

class LightBulbRenderStrategy : public RenderStrategy<LightBulbRenderInputData>
{
public:
    explicit LightBulbRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const LightBulbRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_LIGHTBULBRENDERSTRATEGY_H
