#include "../inc/Settings.h"

Settings::Settings() : m_width(1800), m_height(900) {}

Settings& Settings::getInstance()
{
    static Settings l_settings;
    return l_settings;
}

int Settings::getWidth() const
{
    return m_width;
}

int Settings::getHeight() const
{
    return m_height;
}

float Settings::getAspectRatio() const
{
    return (float) m_width / (float) m_height;
}
