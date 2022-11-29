// Include header
#include <random>
#include "../inc/Kernel.h"
#include "glm/geometric.hpp"

void Kernel::generate()
{
    std::uniform_real_distribution<float> randomFloats(-1.0, 1.0);
    std::uniform_real_distribution<float> randomFloats2(0.0, 1.0);

    std::default_random_engine generator;

    for (unsigned int i = 0; i < 64; ++i)
    {
        glm::vec3 sample(
            randomFloats(generator),
            randomFloats(generator),
            randomFloats2(generator)
        );

        sample = glm::normalize(sample);
        sample *= randomFloats2(generator);

        float scale = float(i) / 64.0f;
        scale = linearInterpolation(0.1f, 1.0f, scale * scale);
        sample *= scale;
        m_kernel.push_back(sample);
    }
}

std::vector<glm::vec3> Kernel::getKernel() const
{
    return m_kernel;
}

float Kernel::linearInterpolation(float f_v1, float f_v2, float f_factor)
{
    return f_v1 + f_factor * (f_v2 - f_v1);
}