#ifndef UNTITLED3_SHADOWDEPTHRENDERSTRATEGY_H
#define UNTITLED3_SHADOWDEPTHRENDERSTRATEGY_H

#include "../../../renderer/inc/RenderStrategy.h"
#include "../../../renderstrategies/shadowdepth/inc/ShadowDepthRenderInputData.h"

class ShadowDepthRenderStrategy : public RenderStrategy<ShadowDepthRenderInputData>
{
public:
    explicit ShadowDepthRenderStrategy(FrameBuffer* f_frameBuffer);

private:
    void update(const ShadowDepthRenderInputData& f_renderInputData) override;

};

#endif //UNTITLED3_SHADOWDEPTHRENDERSTRATEGY_H
