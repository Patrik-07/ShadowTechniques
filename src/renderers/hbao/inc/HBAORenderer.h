#ifndef UNTITLED3_HBAORENDERER_H
#define UNTITLED3_HBAORENDERER_H

#include "../../../renderer/inc/Renderer.h"
#include "../../../renderstrategies/hbao/inc/HBAORenderStrategy.h"

class HBAORenderer : public Renderer<HBAORenderStrategy>
{
public:
    HBAORenderer();

};

#endif //UNTITLED3_HBAORENDERER_H
