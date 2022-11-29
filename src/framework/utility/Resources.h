#pragma once

namespace RESOURCE {
    class SHADER {
    public:
        static constexpr const char* DEFAULT_VS = R"(shaders\defaultVertexShader.glsl)";
        static constexpr const char* DEFAULT_FS = R"(shaders\defaultFragmentShader.glsl)";

        static constexpr const char* GRID_VS = R"(shaders\gridVertexShader.glsl)";
        static constexpr const char* GRID_FS = R"(shaders\gridFragmentShader.glsl)";

        static constexpr const char* DEPTH_VS = R"(shaders\depthVertexShader.glsl)";
        static constexpr const char* DEPTH_FS = R"(shaders\depthFragmentShader.glsl)";

        static constexpr const char* GBUFFER_VS = R"(shaders\gbufferVertexShader.glsl)";
        static constexpr const char* GBUFFER_FS = R"(shaders\gbufferFragmentShader.glsl)";

        static constexpr const char* GB_VS = R"(shaders\gbVs.glsl)";
        static constexpr const char* GB_FS = R"(shaders\gbFs.glsl)";

        static constexpr const char* quad_VS = R"(shaders\quadVs.glsl)";
        static constexpr const char* quad_FS = R"(shaders\quadFs.glsl)";

        static constexpr const char* SSAO_VS = R"(shaders\ssaoVs.glsl)";
        static constexpr const char* SSAO_FS = R"(shaders\ssaoFs.glsl)";
        static constexpr const char* SSAO_BLUR_FS = R"(shaders\ssaoBlurFs.glsl)";

        static constexpr const char* LIGHT_VS = R"(shaders\lightVS.glsl)";
        static constexpr const char* LIGHT_FS = R"(shaders\lightFS.glsl)";

        static constexpr const char* DISABLE_AO_VS = R"(shaders\aoDisableVS.glsl)";
        static constexpr const char* DISABLE_AO_FS = R"(shaders\aoDisableFS.glsl)";

        static constexpr const char* HBAO_VS = R"(shaders\hbaoVS.glsl)";
        static constexpr const char* HBAO_FS = R"(shaders\hbaoFS.glsl)";

        static constexpr const char* SHADOW_VS = R"(shaders\shadowVS.glsl)";
        static constexpr const char* SHADOW_FS = R"(shaders\shadowFS.glsl)";

        static constexpr const char* LIGHTBULB_VS = R"(shaders\lightbulbVS.glsl)";
        static constexpr const char* LIGHTBULB_FS = R"(shaders\lightbulbFS.glsl)";
    };

    class MODEL {
    public:
        static constexpr const char* FOX = R"(models\fox2\untitled.gltf)";
        static constexpr const char* PLANE = R"(models\plane\plane.gltf)";
        static constexpr const char* ROOM = R"(models\room\asdasd.gltf)";
        static constexpr const char* LIGHT = R"(models\light\light.gltf)";
        static constexpr const char* DOCK = R"(models\dock\casa.gltf)";
        static constexpr const char* DOCK2 = R"(models\dock2\casa.gltf)";
        static constexpr const char* WATERDOCK = R"(models\waterdock\casa.gltf)";
        static constexpr const char* WATER = R"(models\water\asd.gltf)";
    };
}

//C:\Users\PatrikSanta\Prog\C++\Imgui\res
//namespace RESOURCE {
//    namespace SHADER {
//        const char* DEFAULT_VS = R"(shaders\defaultVertexShader.glsl)";
//        const char* DEFAULT_FS = R"(shaders\defaultFragmentShader.glsl)";
//
//        const char* GRID_VS = R"(shaders\gridVertexShader.glsl)";
//        const char* GRID_FS = R"(shaders\gridFragmentShader.glsl)";
//
//        const char* DEPTH_VS = R"(shaders\depthVertexShader.glsl)";
//        const char* DEPTH_FS = R"(shaders\depthFragmentShader.glsl)";
//    }
//
//    namespace MODEL {
//        const char* DUCK = R"(models\duck\10602_Rubber_Duck_v1_L3.obj)";
//        const char* FOX = R"(models\fox2\untitled.gltf)";
//        const char* PLANE = R"(models\plane\plane.gltf)";
//    }
//}
