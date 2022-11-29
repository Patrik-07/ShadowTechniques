#pragma once

#include "Glew/glew.h"

#include "Buffer.h"
#include "../texture/inc/Texture.h"
#include <vector>

class FrameBuffer : public Buffer {
public:
    std::vector<Texture*> m_textures;

    FrameBuffer(std::initializer_list<Texture*> f_textures)
    {
        glGenFramebuffers(1, &ID);
        glBindFramebuffer(GL_FRAMEBUFFER, ID);

        m_textures = f_textures;

        int l_colorAttachmentCount = 0;
        for (Texture* texture : m_textures)
        {
            texture->generate();

            if (texture->hasColorAttachment())
            {
                glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + l_colorAttachmentCount, GL_TEXTURE_2D, texture->getID(), 0);
                l_colorAttachmentCount++;
            }
        }

        setColorAttachment(l_colorAttachmentCount);

        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

    void setColorAttachment(int f_colorAttachmentCount)
    {
        unsigned int l_colorAttachment[f_colorAttachmentCount];

        for (unsigned int i = 0; i < f_colorAttachmentCount; i++)
        {
            l_colorAttachment[i] = GL_COLOR_ATTACHMENT0 + i;
        }

        glDrawBuffers(f_colorAttachmentCount, l_colorAttachment);
    }

    void destroy()
    {
        for (Texture* l_texture : m_textures)
        {
            delete l_texture;
        }
    }

//    static FrameBuffer create(unsigned int w, unsigned int h) {
//        return FrameBuffer(w, h);
//    }

    void bind() const override {
        glBindFramebuffer(GL_FRAMEBUFFER, ID);
    }

    void unbind() const override {
        glBindFramebuffer(GL_FRAMEBUFFER, 0);
    }

//    FrameBuffer(unsigned int w = 0, unsigned int h = 0) {
//        glGenFramebuffers(1, &ID);
//        glBindFramebuffer(GL_FRAMEBUFFER, ID);
//
//        float borderColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
//
//        glGenTextures(1, &textureID);
//        glBindTexture(GL_TEXTURE_2D, textureID);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB32F, w, h, 0, GL_RGBA, GL_UNSIGNED_INT, nullptr);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, textureID, 0);
//
//        glGenTextures(1, &gPosition);
//        glBindTexture(GL_TEXTURE_2D, gPosition);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA16F, w, h, 0, GL_RGBA, GL_FLOAT, NULL);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
//        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT1, GL_TEXTURE_2D, gPosition, 0);
//
//        unsigned int attachments[2] = { GL_COLOR_ATTACHMENT0, GL_COLOR_ATTACHMENT1 };
//        glDrawBuffers(2, attachments);
//
//        glGenTextures(1, &depthID);
//        glBindTexture(GL_TEXTURE_2D, depthID);
//        glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, w, h, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
//        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
//        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
//        glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthID, 0);
//
//        glBindFramebuffer(GL_FRAMEBUFFER, 0);
//    }
};