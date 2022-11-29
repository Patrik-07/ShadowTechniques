#ifndef UNTITLED3_RENDERER_H
#define UNTITLED3_RENDERER_H

#include "RenderStrategy.h"
#include "RenderInputData.h"

template<typename RenderStrategy>
class Renderer
{
public:
    void render()
    {
        m_renderStrategy->render(*m_renderInputData);
    }

    void setRenderInputDataPointer(typename RenderStrategy::RenderInputDataType* f_renderInputData)
    {
        m_renderInputData = f_renderInputData;
    }

    Texture* getOutputTexturePointer()
    {
        return m_outputTexture;
    }

    void destroy()
    {
        m_frameBuffer->destroy();
        delete m_frameBuffer;
        delete m_renderStrategy;
    }

protected:
    Texture* m_outputTexture;
    FrameBuffer* m_frameBuffer;
    typename RenderStrategy::RenderInputDataType* m_renderInputData;
    RenderStrategy* m_renderStrategy;

};

#endif //UNTITLED3_RENDERER_H
