#ifndef UNTITLED3_QUAD_H
#define UNTITLED3_QUAD_H

class Quad
{
public:
    static Quad& getInstance();

    void render();

    Quad(Quad const&) = delete;
    void operator=(Quad const&) = delete;

private:
    Quad();

    unsigned int m_quadVAO;
    unsigned int m_quadVBO;

};

#endif //UNTITLED3_QUAD_H
