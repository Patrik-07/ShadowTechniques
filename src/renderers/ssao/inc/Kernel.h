#ifndef UNTITLED3_KERNEL_H
#define UNTITLED3_KERNEL_H

#include <vector>
#include "glm/vec3.hpp"

class Kernel
{
public:
    void generate();
    std::vector<glm::vec3> getKernel() const;

private:
    float linearInterpolation(float a, float b, float f);

    std::vector<glm::vec3> m_kernel;
};

#endif //UNTITLED3_KERNEL_H
