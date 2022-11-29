#pragma once

#include <vector>

//#include "../Opengl/Texture0/Texture0.h"
#include "../Opengl/Shader/ShaderProgram.h"
#include "../Opengl/Uniform/Base/UniformBase.h"
#include "../Opengl/Uniform/UniformProvider.h"

class Material {
public:
    //std::vector<Texture0> textures;

    //explicit Material(std::vector<Texture0> textures);
    explicit Material(float f_r, float f_g, float f_b, float f_a);

    void update(ShaderProgram* shaderProgram);

private:
    float m_r;
    float m_g;
    float m_b;
    float m_a;

};