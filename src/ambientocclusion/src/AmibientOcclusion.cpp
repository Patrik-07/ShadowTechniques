// Include header
#include "../inc/AmbientOcclusionRenderer.h"
#include "../../textures/inc/DefaultTexture.h"
//
//AmbientOcclusionRenderer::AmbientOcclusionRenderer()
//{
//    m_aoTexture = new DefaultTexture();
//    m_aoBlurTexture = new DefaultTexture();
//
//    m_aoBuffer = new FrameBuffer({m_aoTexture});
//    m_aoBlurBuffer = new FrameBuffer({m_aoBlurTexture});
//}
//
////template<typename RenderInputData>
////void AmbientOcclusionRenderer::render(RenderStrategy<>())
////{
////    l_ssaoRenderStrategy.render(l_ssaoRenderInputData);
////    Texture* l_ssaoResult = l_aoTexture;
////
////    if (l_ssaoMenu.getSettingDataPointer()->m_isBlurEnabled)
////    {
////        l_aoBlurRenderStrategy.render(l_ssaoBlurRenderInputData);
////        l_ssaoResult = l_aoBlurTexture;
////    }
////}
//
//Texture* AmbientOcclusionRenderer::getOutputTexturePointer()
//{
//    return m_aoOutputTexture;
//}
//
//AmbientOcclusionRenderer::~AmbientOcclusionRenderer()
//{
//    m_aoBuffer->destroy();
//    m_aoBlurBuffer->destroy();
//
//    delete m_aoBuffer;
//    delete m_aoBlurBuffer;
//}
