#ifndef UNTITLED3_SHADERPROGRAMS_H
#define UNTITLED3_SHADERPROGRAMS_H

#include <map>
#include "../../framework/opengl/shader/ShaderProgram.h"

class ShaderPrograms
{
public:
    static void load();
    static void destroy();

    static ShaderProgram* get(unsigned int f_shaderProgramID);

    enum {
        GBUFFER,
        QUAD,

        SSAO,
        HBAO,
        AO_BLUR,

        SHADOW,

        LIGHT,
        LIGHTBULB,

        NEGLECT,
    };

private:
    static void addShaderProgram(unsigned int f_ID, const char* f_vertexShaderPath, const char* f_fragmentShaderPath);

    static std::map<unsigned int, ShaderProgram*> m_shaderPrograms;

};

#endif //UNTITLED3_SHADERPROGRAMS_H
