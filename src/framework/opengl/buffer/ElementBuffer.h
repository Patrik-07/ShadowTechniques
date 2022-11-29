#pragma once

#include <cstdio>

#include "Glew/glew.h"

#include "Buffer.h"

class ElementBuffer : Buffer {
public:
    static ElementBuffer create(const void* indices, int size);

    void bind() const override;
    void unbind() const override;

private:
    ElementBuffer(const void* indices, int size);
};