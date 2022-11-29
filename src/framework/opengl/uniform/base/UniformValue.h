#pragma once

#include "Glew/glew.h"

class UniformValue {
public:
    virtual void set(int location) const = 0;
    virtual ~UniformValue() = default;
};

template<typename T>
class TemplatedUniformValue : public UniformValue {
public:
    virtual void set(int location) const = 0;
};
