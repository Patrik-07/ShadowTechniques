APPNAME = ShadowTechniques
OUTPUT_DIR = build

CC = compiler\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin\g++

OUTPUT = $(OUTPUT_DIR)\$(APPNAME)

LDLIBS =
LDLIBS += lib

SRC = 
SRC += src/main.cpp
# ImGui
SRC += include/imgui/sdl_opengl3/imgui_impl_opengl3.cpp
SRC += include/imgui/sdl_opengl3/imgui_impl_sdl.cpp
SRC += include/imgui/imgui_demo.cpp
SRC += include/imgui/imgui_draw.cpp
SRC += include/imgui/imgui_tables.cpp
SRC += include/imgui/imgui_widgets.cpp
SRC += include/imgui/imgui.cpp

SRC += src/framework/scene/Camera.h
SRC += src/framework/scene/inc/SceneObject.h
SRC += src/framework/scene/inc/Scene.h
SRC += src/framework/scene/Grid.h
SRC += src/framework/utility/LoadingBar.h
SRC += src/framework/model/Geometry.h
SRC += src/framework/utility/Resources.h
SRC += src/framework/opengl/buffer/Buffer.h
SRC += src/framework/opengl/buffer/VertexBuffer.h
SRC += src/framework/opengl/buffer/VertexBuffer.cpp
SRC += src/framework/opengl/buffer/VertexAttribute.h
SRC += src/framework/opengl/buffer/VertexAttribute.cpp
SRC += src/framework/opengl/buffer/ElementBuffer.cpp
SRC += src/framework/opengl/buffer/ElementBuffer.h
SRC += src/framework/opengl/buffer/VertexArray.cpp
SRC += src/framework/opengl/buffer/VertexArray.h
SRC += src/framework/model/Geometry.cpp
SRC += src/framework/opengl/shader/Shader.cpp
SRC += src/framework/opengl/shader/ShaderProgram.cpp
SRC += src/framework/model/Mesh.cpp
SRC += src/framework/model/Material.cpp
SRC += #src/framework/opengl/texture/Texture0.cpp
SRC += src/framework/model/Model.cpp
SRC += src/framework/loader/modelLoader/AssimpLoader.cpp
SRC += src/framework/opengl/uniform/base/UniformBase.h
SRC += src/framework/opengl/uniform/UniformProvider.h
SRC += src/framework/loader/modelLoader/ModelLoader.h
SRC += src/framework/opengl/uniform/impl/GL_F/GL_1_F.h
SRC += src/framework/opengl/uniform/impl/GL_F/GL_2_F.h
SRC += src/framework/opengl/uniform/impl/GL_F/GL_3_F.h
SRC += src/framework/opengl/uniform/impl/GL_F/GL_4_F.h
SRC += src/framework/opengl/uniform/impl/GL_I/GL_1_I.h
SRC += src/framework/opengl/uniform/impl/GL_I/GL_2_I.h
SRC += src/framework/opengl/uniform/impl/GL_I/GL_3_I.h
SRC += src/framework/opengl/uniform/impl/GL_I/GL_4_I.h
SRC += src/framework/opengl/uniform/impl/GL_UI/GL_1_UI.h
SRC += src/framework/opengl/uniform/impl/GL_UI/GL_2_UI.h
SRC += src/framework/opengl/uniform/impl/GL_UI/GL_3_UI.h
SRC += src/framework/opengl/uniform/impl/GL_UI/GL_4_UI.h
SRC += src/framework/opengl/uniform/impl/GL_F_V/GL_1_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_F_V/GL_2_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_F_V/GL_3_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_F_V/GL_4_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_I_V/GL_1_I_V.h
SRC += src/framework/opengl/uniform/impl/GL_I_V/GL_2_I_V.h
SRC += src/framework/opengl/uniform/impl/GL_I_V/GL_3_I_V.h
SRC += src/framework/opengl/uniform/impl/GL_I_V/GL_4_I_V.h
SRC += src/framework/opengl/uniform/impl/GL_UI_V/GL_1_UI_V.h
SRC += src/framework/opengl/uniform/impl/GL_UI_V/GL_2_UI_V.h
SRC += src/framework/opengl/uniform/impl/GL_UI_V/GL_3_UI_V.h
SRC += src/framework/opengl/uniform/impl/GL_UI_V/GL_4_UI_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_2F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_3F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_4F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_2x3_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_3x2_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_2x4_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_4x3_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_3x4_F_V.h
SRC += src/framework/opengl/uniform/impl/GL_MATRIX_F_V/GL_MATRIX_4x2_F_V.h
SRC += src/framework/opengl/uniform/Uniforms.h
SRC += src/framework/opengl/uniform/base/UniformValue.h
SRC += src/framework/opengl/uniform/base/MatrixUniformValue.h
SRC += src/framework/opengl/uniform/base/ScalarUniformValue.h
SRC += src/framework/opengl/uniform/base/VectorUniformValue.h
SRC += src/framework/utility/Timer.h
SRC += src/framework/utility/CameraHandler.h
SRC += src/framework/utility/ImGuiRenderer.h
SRC += src/framework/opengl/buffer/FramerBuffer.h
SRC += src/framework/utility/Window.h
SRC += src/framework/model/VertexBoneData.h
SRC += src/framework/animation/Bone.h
SRC += src/framework/animation/AssimpGLMHelpers.h
SRC += src/framework/animation/Animation.h
SRC += src/framework/animation/Animator.h
SRC += src/framework/animation/Keyframe.h
SRC += src/framework/model/animatedModel/Skeleton.h
SRC += src/framework/animation/Pose.h
SRC += src/framework/animation/AnimationContainer.h
SRC += src/framework/anim/Bone2.h
SRC += src/framework/anim/Keyframe.h
SRC += src/framework/anim/KeyValue.h
SRC += src/framework/model/animatedModel/AnimatedModel.h
SRC += src/framework/anim/VertexData.h
SRC += src/framework/animation/Timeline.h
SRC += src/framework/opengl/buffer/DepthBuffer.h
SRC += src/framework/opengl/buffer/PositionBuffer.h
SRC += src/framework/opengl/buffer/GBuffer.h
SRC += src/framework/scene/GBufferUniform.h
SRC += src/quad/inc/Quad.h 
SRC += src/quad/src/Quad.cpp
SRC += src/shaderprograms/inc/ShaderPrograms.h
SRC += src/shaderprograms/src/ShaderPrograms.cpp
SRC += src/framework/opengl/texture/inc/Texture.h
SRC += src/textures/inc/ShadowDepthTexture.h
SRC += src/textures/src/ShadowDepthTexture.cpp
SRC += src/framework/opengl/texture/src/Texture.cpp
SRC += src/settings/inc/Settings.h
SRC += src/settings/src/Settings.cpp
SRC += src/renderer/inc/Renderer.h
SRC += src/textures/inc/LightTexture.h
SRC += src/textures/src/LightTexture.cpp
SRC += src/textures/inc/AOBlurTexture.h
SRC += src/textures/src/AOBlurTexture.cpp
SRC += src/renderer/inc/RenderStrategy.h
SRC += src/renderer/inc/RenderInputData.h
SRC += # Shadow
SRC += src/renderstrategies/shadowdepth/inc/ShadowDepthRenderStrategy.h
SRC += src/renderstrategies/shadowdepth/src/ShadowDepthRenderStrategy.cpp
SRC += src/renderstrategies/shadowdepth/inc/ShadowDepthRenderInputData.h
SRC += # light
SRC += src/renderstrategies/light/inc/LightRenderStrategy.h
SRC += src/renderstrategies/light/src/LightRenderStrategy.cpp
SRC += src/renderstrategies/light/inc/LightRenderInputData.h
SRC += # SSAO
SRC += src/renderstrategies/ssao/inc/SSAORenderStrategy.h
SRC += src/renderstrategies/ssao/src/SSAORenderStrategy.cpp
SRC += src/renderstrategies/ssao/inc/SSAORenderInputData.h
SRC += # SSAOBlur
SRC += src/renderstrategies/aoblur/inc/AOBlurRenderStrategy.h
SRC += src/renderstrategies/aoblur/src/AOBlurRenderStrategy.cpp
SRC += src/renderstrategies/aoblur/inc/AOBlurRenderInputData.h
SRC += # GBuffer
SRC += src/renderstrategies/gbuffer/inc/GBufferRenderStrategy.h
SRC += src/renderstrategies/gbuffer/src/GBufferRenderStrategy.cpp
SRC += src/renderstrategies/gbuffer/inc/GBufferRenderInputData.h
SRC += # Null
SRC += src/renderstrategies/null/inc/NullRenderInputData.h
SRC += src/renderstrategies/null/inc/NullRenderStrategy.h
SRC += src/renderstrategies/null/src/NullRenderStrategy.cpp
SRC += 
SRC += src/textures/inc/SSAOTexture.h
SRC += src/textures/src/SSAOTexture.cpp
SRC += src/textures/inc/PositionTexture.h
SRC += src/textures/src/PositionTexture.cpp
SRC += src/textures/inc/NormalTexture.h
SRC += src/textures/inc/AlbedoTexture.h
SRC += src/textures/inc/DepthTexure.h
SRC += src/textures/src/DepthTexture.cpp
SRC += src/textures/src/NormalTexture.cpp
SRC += src/textures/src/AlbedoTexture.cpp
SRC += src/light/inc/Light.h
SRC += src/light/src/Light.cpp
SRC += src/textures/inc/NullTexture.h
SRC += src/textures/src/NullTexture.cpp
SRC += src/renderstrategies/hbao/inc/HBAORenderStrategy.h
SRC += 
SRC += src/renderstrategies/hbao/inc/HBAORenderInputData.h
SRC += src/renderstrategies/hbao/src/HBAORenderStrategy.cpp
SRC += src/textures/src/HBAOTexture.cpp
SRC += src/textures/inc/HBAOTexture.h
SRC += src/textures/inc/NoiseTexture.h
SRC += src/textures/src/NoiseTexture.cpp
SRC += src/textures/inc/ShadowTexture.h
SRC += src/textures/src/ShadowTexture.cpp
SRC += src/renderstrategies/shadow/inc/ShadowRenderInputData.h
SRC += src/renderstrategies/shadow/inc/ShadowRenderStrategy.h
SRC += src/renderstrategies/shadow/src/ShadowRenderStrategy.cpp
SRC += src/textures/src/DefaultTexture.cpp
SRC += src/textures/inc/DefaultTexture.h
SRC += src/renderstrategies/lightbulb/inc/LightBulbRenderStrategy.h
SRC += src/renderstrategies/lightbulb/inc/LightBulbRenderInputData.h
SRC += src/renderstrategies/lightbulb/src/LightBulbRenderStrategy.cpp
SRC += src/settings/inc/Menu.h
SRC += src/ambientocclusion/inc/AmbientOcclusionRenderer.h
SRC += src/ambientocclusion/src/AmibientOcclusion.cpp
SRC += src/settings/inc/SettingData.h
SRC += src/menu/ssao/inc/SSAOSettingData.h
SRC += src/menu/ssao/inc/SSAOMenu.h 
SRC += src/menu/ssao/src/SSAOMenu.cpp 
SRC += src/renderers/ssao/inc/SSAORenderer.h
SRC += src/renderers/ssao/src/SSAORenderer.cpp 
SRC += src/renderers/ssao/inc/Kernel.h 
SRC += src/renderers/ssao/src/Kernel.cpp 
SRC += src/renderstrategies/ssao/src/SSAORenderInputData.cpp 
SRC += src/renderstate/inc/RenderState.h 
SRC += src/renderstate/src/RenderState.cpp 
SRC += src/renderstates/ssaorenderstate/inc/SSAORenderState.h 
SRC += src/renderstates/ssaorenderstate/src/SSAORenderState.cpp 
SRC += src/renderers/aoblur/inc/AOBlurRenderer.h 
SRC += src/renderers/aoblur/src/AOBlurRenderer.cpp 
SRC += src/renderstates/hbaorenderstate/inc/HBAORenderState.h 
SRC += src/renderstates/hbaorenderstate/src/HBAORenderState.cpp 
SRC += src/renderers/hbao/inc/HBAORenderer.h 
SRC += src/renderers/hbao/src/HBAORenderer.cpp 
SRC += src/menu/hbao/inc/HBAOSettingData.h 
SRC += src/menu/hbao/inc/HBAOMenu.h 
SRC += src/menu/hbao/src/HBAOMenu.cpp 
SRC += src/renderstrategies/hbao/src/HBAORenderInputData.cpp 
SRC += src/gbuffer/inc/GBuffer.h 
SRC += src/gbuffer/src/GBuffer.cpp 
SRC += src/renderstates/whitemask/inc/WhiteMaskRenderState.h 
SRC += src/renderstates/whitemask/src/WhiteMaskRenderState.cpp 
SRC += src/renderers/whitemask/inc/WhiteMaskRenderer.h 
SRC += src/renderers/whitemask/src/WhiteMaskRenderer.cpp 
SRC += src/menu/debug/inc/DebugMenu.h 
SRC += src/menu/debug/src/DebugMenu.cpp 
SRC += src/settings/inc/OutputMenu.h
SRC += src/menu/aomenu/inc/AOMenu.h 
SRC += src/menu/aomenu/inc/AOMenuSettingData.h
SRC += src/menu/aomenu/src/AOMenuSettingData.cpp
SRC += src/menu/aomenu/src/AOMenu.cpp
SRC += src/settings/src/Menu.cpp 
SRC += src/menu/settings/inc/SettingsMenu.h 
SRC += src/menu/settings/src/SettingsMenu.cpp
SRC += src/menu/settings/inc/SettingsSettingData.h 
SRC += src/menu/settings/src/SettingsSettingData.cpp
SRC += src/menu/shadowmapping/inc/ShadowMappingMenu.h 
SRC += src/menu/shadowmapping/src/ShadowMappingMenu.cpp 
SRC += src/menu/shadowmapping/inc/ShadowMappingSettingData.h
SRC += src/menu/shadowmapping/src/ShadowMappingSettingData.cpp 
SRC += src/menu/ssao/src/SSAOSettingData.cpp 
SRC += src/menu/ao/inc/AOSettingData.h 
SRC += src/menu/ao/src/AOSettingData.cpp 
SRC += src/menu/hbao/src/HBAOSettingData.cpp 
SRC += src/menu/light/inc/LightMenu.h 
SRC += src/menu/light/src/LightMenu.cpp 
SRC += src/menu/light/inc/LightMenuSettingData.h 
SRC += src/menu/light/src/LightMenuSettingData.cpp

all:
	$(CC) -I include -L $(LDLIBS) -o $(OUTPUT) $(SRC) -lmingw32 -lSDL2main -lSDL2 -lglew32 -lopengl32 -lassimp