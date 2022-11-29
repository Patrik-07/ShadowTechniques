#ifndef UNTITLED3_SETTINGS_H
#define UNTITLED3_SETTINGS_H

class Settings
{
public:
    static Settings& getInstance();

    int getWidth() const;
    int getHeight() const;
    float getAspectRatio() const;

    Settings(Settings const&) = default;
    void operator=(Settings const&) = delete;

private:
    Settings();

    unsigned int m_width;
    unsigned int m_height;

};

#endif //UNTITLED3_SETTINGS_H
