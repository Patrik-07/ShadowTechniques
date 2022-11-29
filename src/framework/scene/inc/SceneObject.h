#pragma once

#include "../../opengl/uniform/Uniforms.h"
#include "../../opengl/uniform/base/MatrixUniformValue.h"
#include "../../model/Model.h"
#include "../../animation/Animator.h"
#include "../../../shaderprograms/inc/ShaderPrograms.h"
#include "glm/gtc/type_ptr.hpp"

class SceneObject : public UniformProvider {
    Model& model;
    ShaderProgram* shaderProgram;
    Animator animator;

//    TODO make these properties
//    glm::mat3 position;
//    glm::mat3 rotation;
//    glm::mat3 scale;
public:
    glm::mat4 modelMatrix;

    SceneObject(Model& model, ShaderProgram* shaderProgram = ShaderPrograms::get(ShaderPrograms::GBUFFER)) : model(model), shaderProgram(shaderProgram), UniformProvider("mvp", shaderProgram) {
        modelMatrix = glm::mat4(1.0f);
        setUniform("model", new UNIFORM::GL_MATRIX_4F_V(glm::value_ptr(modelMatrix)));
    }

    void setShader(ShaderProgram* f_shaderProgram) {
        this->shaderProgram = f_shaderProgram;
    }

    ShaderProgram* getShader() {
        return shaderProgram;
    }

    // TODO should remove
    void setCurrentAnimation(Animation& animation) {
        animator.setCurrentAnimation(&animation);
    }

    void translate(glm::vec3 v) {
        modelMatrix = glm::translate(modelMatrix, v);
    }

    void moveTo(glm::vec3 position) {
        modelMatrix[3][0] = 0.0f;
        modelMatrix[3][1] = 0.0f;
        modelMatrix[3][2] = 0.0f;

        translate(position);
    }

    void rotate(float angle, glm::vec3 v) {
        modelMatrix = glm::rotate(modelMatrix, angle, v);
    }

    void scale(glm::vec3 s) {
        modelMatrix = glm::scale(modelMatrix, s);
    }

    void draw() {
        model.draw(shaderProgram);
    }

    virtual void update(float deltaTime) {
        UniformProvider::updateShader();
        if (animator.hasAnimation()) {
            animator.updateAnimation(deltaTime);
            auto poses = animator.getPoses();
            for (int i = 0; i < poses.size(); i++) {
                shaderProgram->setUniform("poses[" + std::to_string(i) + "]", glm::value_ptr(poses[i]));
            }
        }
    }
};