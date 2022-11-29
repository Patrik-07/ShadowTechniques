#ifndef UNTITLED3_WHITEMASKRENDERER_H
#define UNTITLED3_WHITEMASKRENDERER_H

#include "../../../renderer/inc/Renderer.h"
#include "../../../renderstrategies/null/inc/NullRenderStrategy.h"

class WhiteMaskRenderer : public Renderer<NullRenderStrategy>
{
public:
    WhiteMaskRenderer();

};

#endif //UNTITLED3_WHITEMASKRENDERER_H
