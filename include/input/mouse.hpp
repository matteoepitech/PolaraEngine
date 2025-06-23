/*
** POLARA PROJECT, 2025
** include/input/mouse.hpp
** File description:
** Input mouse Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::input
{

/**
 * @brief Mouse callback using GLFW prototype syntax.
 *
 * @param window        The window
 * @param x_pos         The X pos
 * @param y_pos         The Y pos
 */
void pl_mouse_callback(GLFWwindow *window, pl_double x_pos, pl_double y_pos);

/**
 * @brief Ungrab the mouse and put it available to the user for UI for example.
 *
 * @param window        The window
 */
void pl_ungrab_mouse(const PL::core::Window &window);

} // namespace PL
