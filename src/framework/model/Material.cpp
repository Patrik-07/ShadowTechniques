#include "Material.h"

#include "../opengl/uniform/Uniforms.h"
#include "glm/vec4.hpp"
#include "glm/gtc/type_ptr.hpp"

//Material::Material(std::vector<Texture0> textures)  {
//    this->textures = std::move(textures);
//}

Material::Material(float f_r, float f_g, float f_b, float f_a) :
    m_r(f_r), m_g(f_g), m_b(f_b), m_a(f_a)
{
}

void Material::update(ShaderProgram* shaderProgram) {
//    if (!textures.empty())
//    {
//        shaderProgram.setUniform("enableTexture", true);
//        for (int i = 0; i < textures.size(); i++)
//        {
//            std::string textureTypeName = "";
//            switch (textures[i].type) {
//                case Texture0::DIFFUSE: textureTypeName.append("diffuseMap"); break;
//                case Texture0::SPECULAR: textureTypeName.append("specularMap"); break;
//                case Texture0::AMBIENT: textureTypeName.append("ambientMap"); break;
//            }
//            shaderProgram.setUniform(textureTypeName.c_str(), textures[i].ID, i);
//        }
//    }
//    else
//    {
        shaderProgram->setUniform("color", glm::value_ptr(glm::vec4(m_r, m_g, m_b, m_a)), 4);
        //shaderProgram.setUniform("enableTexture", false);
//    }

//    static Texture0 t = Texture0::create("models/plane/wood.png", Texture0::DIFFUSE);
//    shaderProgram.setUniform("depthMap", t.ID, 1);

    glActiveTexture(GL_TEXTURE0);
}
