/*
** POLARA PROJECT, 2025
** src/core/camera/pl_camera_manager
** File description:
** camera Implementation file
*/
#include "polara.hpp"

// @brief Variables in the camera static class.
glm::vec3 PL::core::Camera::m_camera_pos = glm::vec3(0.0f, 0.0f, 3.0f);
glm::vec3 PL::core::Camera::m_camera_front = glm::vec3(0.0f, 0.0f, -1.0f);
glm::vec3 PL::core::Camera::m_camera_up = glm::vec3(0.0f, 1.0f, 0.0f);

/**
 * @brief Init the camera.
 *
 * @param position              The position of the camera
 */
void
PL::core::Camera::init(glm::vec3 position)
{
    m_camera_pos = position;
}

/**
 * @brief Get camera position.
 *
 * @return Current camera position.
 */
glm::vec3
PL::core::Camera::get_position(void)
{
    return m_camera_pos;
}

/**
 * @brief Set camera position.
 *
 * @param position              New camera position
 */
void
PL::core::Camera::set_position(glm::vec3 position)
{
    m_camera_pos = position;
}

/**
 * @brief Get camera front vector.
 *
 * @return Current camera front vector.
 */
glm::vec3
PL::core::Camera::get_front(void)
{
    return m_camera_front;
}

/**
 * @brief Get camera up vector.
 *
 * @return Current camera up vector.
 */
glm::vec3
PL::core::Camera::get_up(void)
{
    return m_camera_up;
}
