// Include header
#include "../inc/HBAORenderInputData.h"
#include "../../../textures/inc/NoiseTexture.h"

HBAORenderInputData::HBAORenderInputData()
{
    m_kernel = Kernel();
    m_kernel.generate();

    m_noiseTexture = new NoiseTexture();
    m_noiseTexture->generate();
}