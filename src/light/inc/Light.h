#ifndef UNTITLED3_LIGHT_H
#define UNTITLED3_LIGHT_H

#include "glm/ext/matrix_float4x4.hpp"

class Light
{
public:
    explicit Light(float f_radius, float f_speed);

    void update(float f_deltaTime);
    void update();

    glm::vec3 getPosition() const;
    glm::mat4 getProjectionMatrix() const;
    glm::mat4 getViewMatrix() const;

    glm::vec3 m_position;
    glm::mat4 m_projectionMatrix;

private:
    float m_radius;
    float m_speed;
    float m_degree;
    glm::mat4 m_viewMatrix;

};

#endif //UNTITLED3_LIGHT_H
