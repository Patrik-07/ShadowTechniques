// Include header
#include "../inc/NoiseTexture.h"

#include <random>

#include "Glew/glew.h"

NoiseTexture::NoiseTexture() : Texture(4, 4) {}

void NoiseTexture::generate()
{
    std::uniform_real_distribution<float> l_randomFloats(-1.0, 1.0);
    std::uniform_real_distribution<float> l_randomFloats2(0.0, 1.0);
    std::default_random_engine l_generator;

    std::vector<glm::vec3> l_noise;
    for (unsigned int i = 0; i < 16; i++) {
        l_noise.emplace_back(
            l_randomFloats(l_generator),
            l_randomFloats(l_generator),
            0.0f
        );
    }

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, m_width, m_height, 0, GL_RGB, GL_FLOAT, &l_noise[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_textureID, 0);
}

bool NoiseTexture::hasColorAttachment()
{
    return true;
}