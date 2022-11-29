// Include header
#include "../inc/NormalTexture.h"
#include "Glew/glew.h"
#include "../../settings/inc/Settings.h"

NormalTexture::NormalTexture() : Texture(Settings::getInstance().getWidth(), Settings::getInstance().getHeight()) {}

void NormalTexture::generate()
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, m_textureID, 0);
}

bool NormalTexture::hasColorAttachment()
{
    return true;
}