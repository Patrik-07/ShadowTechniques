// Include header
#include "../inc/Light.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

Light::Light(float f_radius, float f_speed) : m_radius(f_radius), m_speed(f_speed) {
    m_degree = 0.0f;
    m_projectionMatrix = glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 80.0f);
}

void Light::update(float f_deltaTime)
{
    m_degree += m_speed * f_deltaTime;

    float l_x = m_radius * cosf(m_degree);
    float l_y = m_radius * sinf(m_degree);

    m_position = glm::vec3(l_x + 10, 60.0f, l_y);
    m_viewMatrix = glm::lookAt(
        m_position,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}

void Light::update()
{
    m_viewMatrix = glm::lookAt(
        m_position,
        glm::vec3(0.0f, 0.0f, 0.0f),
        glm::vec3(0.0f, 1.0f, 0.0f)
    );
}


glm::vec3 Light::getPosition() const
{
    return m_position;
}

glm::mat4 Light::getProjectionMatrix() const
{
    return m_projectionMatrix;
}

glm::mat4 Light::getViewMatrix() const
{
    return m_viewMatrix;
}
