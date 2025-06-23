/*
** POLARA PROJECT, 2025
** src/input/pl_mouse_manager
** File description:
** Polara mouse movement manager
*/

#include "polara.hpp"

/**
 * @brief Mouse callback using GLFW prototype syntax.
 *
 * @param window        The window
 * @param x_pos         The X pos
 * @param y_pos         The Y pos
 */
void
PL::input::pl_mouse_callback(GLFWwindow *window, pl_double x_pos, pl_double y_pos)
{
    static float lastX = 400.0f;
    static float lastY = 300.0f;
    static pl_bool firstMouse = PL_TRUE;
    float xoffset = x_pos - lastX;
    float yoffset = lastY - y_pos;
    float sensitivity = 0.1f;
    float yaw = PL::core::Camera::get_yaw();
    float pitch = PL::core::Camera::get_pitch();
    
    if (firstMouse == PL_TRUE)
    {
        lastX = x_pos;
        lastY = y_pos;
        firstMouse = PL_FALSE;
        return;
    }
    lastX = x_pos;
    lastY = y_pos;
    xoffset *= sensitivity;
    yoffset *= sensitivity;
    yaw += xoffset;
    pitch += yoffset;
    if(pitch > 89.0f)
        pitch = 89.0f;
    if(pitch < -89.0f)
        pitch = -89.0f;
    PL::core::Camera::set_yaw(yaw);
    PL::core::Camera::set_pitch(pitch);
    PL::core::Camera::update_front_vector();
}
