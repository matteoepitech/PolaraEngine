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
glm::mat4 PL::core::Camera::m_projection = glm::perspective(glm::radians(90.0f), 800.0f / 600.0f, 0.1f, 100.0f);
pl_float PL::core::Camera::m_yaw = -90.0f;
pl_float PL::core::Camera::m_pitch = 0.0f;
pl_bool PL::core::Camera::m_is_cursor_grab = PL_FALSE;

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

/**
 * @brief Set camera front vector.
 *
 * @param front              New camera front vector
 */
void
PL::core::Camera::set_front(glm::vec3 front)
{
    m_camera_front = glm::normalize(front);
}

/**
 * @brief Get camera yaw angle.
 *
 * @return Current yaw angle in degrees.
 */
pl_float
PL::core::Camera::get_yaw(void)
{
    return m_yaw;
}

/**
 * @brief Set camera yaw angle.
 *
 * @param yaw              New yaw angle in degrees
 */
void
PL::core::Camera::set_yaw(pl_float yaw)
{
    m_yaw = yaw;
    update_front_vector();
}

/**
 * @brief Get camera pitch angle.
 *
 * @return Current pitch angle in degrees.
 */
pl_float
PL::core::Camera::get_pitch(void)
{
    return m_pitch;
}

/**
 * @brief Set camera pitch angle.
 *
 * @param pitch              New pitch angle in degrees
 */
void
PL::core::Camera::set_pitch(pl_float pitch)
{
    if (pitch > 89.0f)
        pitch = 89.0f;
    if (pitch < -89.0f)
        pitch = -89.0f;
    m_pitch = pitch;
    update_front_vector();
}

/**
 * @brief Update camera front vector based on yaw and pitch.
 */
void
PL::core::Camera::update_front_vector(void)
{
    glm::vec3 front;
    front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    front.y = sin(glm::radians(m_pitch));
    front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_camera_front = glm::normalize(front);
}

/**
 * @brief Is the cursor grabbed or not?
 *
 * @return PL_TRUE or PL_FALSE.
 */
pl_bool
PL::core::Camera::get_is_cursor_grab(void)
{
    return m_is_cursor_grab;
}

/**
 * @brief Set the cursor grab or not value.
 *        @SHOULD NOT BE USED
 *
 * @param grab
 */
void
PL::core::Camera::__set_cursor_grab(pl_bool grab)
{
    m_is_cursor_grab = grab;
}

/**
 * @brief Get the projection matrice of the camera.
 *
 * @return The projection matrice.
 */
glm::mat4 PL::core::Camera::get_projection(void)
{
    return m_projection;
}
