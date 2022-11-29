// Include header
#include "../inc/SSAORenderInputData.h"
#include "../../../textures/inc/NoiseTexture.h"

SSAORenderInputData::SSAORenderInputData()
{
    m_kernel = Kernel();
    m_kernel.generate();

    m_noiseTexture = new NoiseTexture();
    m_noiseTexture->generate();

    m_settingData = new SSAOSettingData();
}