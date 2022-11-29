#pragma once

#include "UniformValue.h"

template<typename T>
class VectorUniformValue : public TemplatedUniformValue<T> {
public:
    const T* value;
    unsigned int count;

    VectorUniformValue(const T* value, unsigned int count = 1) {
        this->value = value;
        this->count = count;
    }

    virtual void set(int location) {}

};