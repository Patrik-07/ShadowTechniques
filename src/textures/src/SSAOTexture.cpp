// Include header
#include "../inc/SSAOTexture.h"
#include "Glew/glew.h"
#include "../../settings/inc/Settings.h"

SSAOTexture::SSAOTexture() : Texture(Settings::getInstance().getWidth(), Settings::getInstance().getHeight()) {}

void SSAOTexture::generate()
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, m_width, m_height, 0, GL_RGBA, GL_FLOAT, NULL);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

//    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_textureID, 0);
}

bool SSAOTexture::hasColorAttachment()
{
    return true;
}

