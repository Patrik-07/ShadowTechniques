#pragma once

#include "../opengl/uniform/UniformProvider.h"
#include "glm/ext.hpp"
#include "../../shaderprograms/inc/ShaderPrograms.h"

enum Direction {
    FORTH, BACK, RIGHT, LEFT
};

class Camera : public UniformProvider {
    float pitch, yaw;
    float aspect = 2.0f;

public:
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 up;

    glm::mat4 viewMatrix;
    glm::mat4 projectionMatrix;

    Camera(ShaderProgram* shaderProgram = ShaderPrograms::get(ShaderPrograms::GBUFFER)) : UniformProvider("mvp", shaderProgram) {
        position = glm::vec3(24.0f, 12.0f, -20.0f);
        target = glm::vec3(-0.75f, -0.35f, 0.55f);
        up = glm::vec3(0.0f, 1.0f, 0.0f);

        yaw = 143.5f;
        pitch = -20.48f;

        viewMatrix = updateViewMatrix();
        projectionMatrix = updateProjectionMatrix();

        setUniform("view", new UNIFORM::GL_MATRIX_4F_V(glm::value_ptr(viewMatrix)));
        setUniform("projection", new UNIFORM::GL_MATRIX_4F_V(glm::value_ptr(projectionMatrix)));
    }

    void move(Direction direction, float speed) {
        switch (direction) {
            case FORTH: position += speed * target; break;
            case BACK: position -= speed * target; break;
            case RIGHT: position += glm::normalize(glm::cross(target, up)) * speed; break;
            case LEFT: position -= glm::normalize(glm::cross(target, up)) * speed; break;
        }
        updateMatrices();
    }

    void rotate(float x, float y) {
        pitch += y;
        yaw += x;

        if (pitch > 89.0f) pitch = 89.0f;
        if (pitch < -89.0f) pitch = -89.0f;

        target.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        target.y = sin(glm::radians(pitch));
        target.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

        target = glm::normalize(target);

        updateMatrices();
    }

    glm::vec3 getPosition() const {
        return position;
    }

    void setAspectRatio(float a) {
        aspect = a;
    }

    void update() {
        updateMatrices();
    }

private:
    void updateMatrices() {
        viewMatrix = updateViewMatrix();
        projectionMatrix = updateProjectionMatrix();
    }

    glm::mat4 updateViewMatrix() {
        return glm::lookAt(position, position + target, up);
    }

    glm::mat4 updateProjectionMatrix() {
        return glm::perspective(glm::radians(45.0f), aspect, 0.1f, 1000.0f);
    }
};