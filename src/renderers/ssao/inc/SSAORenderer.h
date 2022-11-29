#ifndef UNTITLED3_SSAORENDERER_H
#define UNTITLED3_SSAORENDERER_H

#include "../../../renderer/inc/Renderer.h"
#include "../../../renderstrategies/ssao/inc/SSAORenderStrategy.h"

class SSAORenderer : public Renderer<SSAORenderStrategy>
{
public:
    SSAORenderer();

};

#endif //UNTITLED3_SSAORENDERER_H
