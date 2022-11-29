#ifndef UNTITLED3_RENDERSTRATEGY_H
#define UNTITLED3_RENDERSTRATEGY_H

#include "../../framework/opengl/buffer/FramerBuffer.h"
#include "../../framework/opengl/shader/ShaderProgram.h"

template<typename RenderInputData>
class RenderStrategy
{
public:
    typedef RenderInputData RenderInputDataType;

    explicit RenderStrategy(
        FrameBuffer* f_frameBuffer,
        ShaderProgram* f_shaderProgram = nullptr
    ) :
        m_frameBuffer(f_frameBuffer),
        m_shaderProgram(f_shaderProgram)
    {}

    void render(const RenderInputData& f_renderInputData)
    {
        m_frameBuffer->bind();

        update(f_renderInputData);

        m_frameBuffer->unbind();
    }

protected:
    virtual void update(const RenderInputData& f_renderInputData) = 0;

    FrameBuffer* m_frameBuffer;
    ShaderProgram* m_shaderProgram;

};

#endif //UNTITLED3_RENDERSTRATEGY_H
