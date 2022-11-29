#ifndef UNTITLED3_AOBLURRENDERER_H
#define UNTITLED3_AOBLURRENDERER_H

#include "../../../renderer/inc/Renderer.h"
#include "../../../renderstrategies/aoblur/inc/AOBlurRenderStrategy.h"

class AOBlurRenderer : public Renderer<AOBlurRenderStrategy>
{
public:
    AOBlurRenderer();

};

#endif //UNTITLED3_AOBLURRENDERER_H
