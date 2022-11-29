// Include header
#include "../inc/DefaultTexture.h"
#include "../../settings/inc/Settings.h"
#include "Glew/glew.h"

DefaultTexture::DefaultTexture() : Texture(Settings::getInstance().getWidth(), Settings::getInstance().getHeight()) {}

void DefaultTexture::generate()
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, m_width, m_height, 0, GL_RGBA, GL_FLOAT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
}

bool DefaultTexture::hasColorAttachment()
{
    return true;
}

