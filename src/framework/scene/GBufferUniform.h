// #pragma once

// #include "Camera.h"
// #include "../opengl/uniform/UniformProvider.h"
// #include "../utility/Resources.h"
// #include "glm/gtc/type_ptr.hpp"

// class GBufferUniformProvider : public UniformProvider {
// public:
//     GBufferUniformProvider(Camera& camera, ShaderProgram& shaderProgram) : UniformProvider("mvp", shaderProgram) {
//         setUniform("view", new UNIFORM::GL_MATRIX_4F_V(glm::value_ptr(camera.viewMatrix)));
//         setUniform("projection", new UNIFORM::GL_MATRIX_4F_V(glm::value_ptr(camera.projectionMatrix)));
//     }
// };

// class GBufferShader {
//     GBufferUniformProvider gBufferdUniformProvider;
//     ShaderProgram gBufferShader;

// public:
//     explicit GBufferShader(Camera& camera) : gBufferShader(
//         RESOURCE::SHADER::GBUFFER_VS,
//         RESOURCE::SHADER::GBUFFER_FS
//     ), gBufferdUniformProvider(camera, gBufferShader) {}

//     void update() {
//         gBufferdUniformProvider.updateShader();
//     }
// };