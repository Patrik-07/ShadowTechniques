// Include header
#include "../inc/Texture.h"

Texture::Texture(int f_width, int f_height) : m_width(f_width), m_height(f_height) {}

unsigned int Texture::getID() const
{
    return m_textureID;
}

Texture::~Texture() = default;