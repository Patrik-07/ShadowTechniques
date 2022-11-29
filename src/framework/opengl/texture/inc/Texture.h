#ifndef UNTITLED3_TEXTURE_H
#define UNTITLED3_TEXTURE_H

class Texture
{
public:
    Texture(int f_width, int f_height);

    virtual void generate() = 0;
    virtual bool hasColorAttachment() = 0;

    unsigned int getID() const;

    virtual ~Texture();

protected:
    int m_width;
    int m_height;
    unsigned int m_textureID;

};

#endif //UNTITLED3_TEXTURE_H
