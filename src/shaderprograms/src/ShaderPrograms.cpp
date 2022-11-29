// Include headers
#include "../inc/ShaderPrograms.h"
#include "../../framework/utility/Resources.h"

void ShaderPrograms::load()
{
    addShaderProgram(GBUFFER,   RESOURCE::SHADER::GB_VS,         RESOURCE::SHADER::GB_FS);
    addShaderProgram(QUAD,      RESOURCE::SHADER::quad_VS,       RESOURCE::SHADER::quad_FS);

    // Ambient Occlusion
    addShaderProgram(SSAO,      RESOURCE::SHADER::SSAO_VS,       RESOURCE::SHADER::SSAO_FS);
    addShaderProgram(HBAO,      RESOURCE::SHADER::HBAO_VS,       RESOURCE::SHADER::HBAO_FS);
    addShaderProgram(AO_BLUR,   RESOURCE::SHADER::SSAO_VS,       RESOURCE::SHADER::SSAO_BLUR_FS);

    // Shadow Mapping
    addShaderProgram(SHADOW,    RESOURCE::SHADER::SHADOW_VS,     RESOURCE::SHADER::SHADOW_FS);

    addShaderProgram(LIGHT,     RESOURCE::SHADER::LIGHT_VS,      RESOURCE::SHADER::LIGHT_FS);

    addShaderProgram(LIGHTBULB, RESOURCE::SHADER::LIGHTBULB_VS,  RESOURCE::SHADER::LIGHTBULB_FS);
    addShaderProgram(NEGLECT,   RESOURCE::SHADER::DISABLE_AO_VS, RESOURCE::SHADER::DISABLE_AO_FS);
}

void ShaderPrograms::destroy()
{
    std::map<unsigned int, ShaderProgram*>::iterator i;
    for (i = m_shaderPrograms.begin(); i != m_shaderPrograms.end(); i++)
    {
        delete i->second;
    }
}

ShaderProgram* ShaderPrograms::get(unsigned int f_shaderProgramID)
{
    return m_shaderPrograms.at(f_shaderProgramID);
}

void ShaderPrograms::addShaderProgram(unsigned int f_ID, const char* f_vertexShaderPath, const char* f_fragmentShaderPath)
{
    ShaderProgram* l_shaderProgram = new ShaderProgram(f_vertexShaderPath, f_fragmentShaderPath);
    m_shaderPrograms.insert(std::pair<unsigned int, ShaderProgram*>(f_ID, l_shaderProgram));
}

std::map<unsigned int, ShaderProgram*> ShaderPrograms::m_shaderPrograms;

