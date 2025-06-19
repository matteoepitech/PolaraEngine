/*
** POLARA PROJECT, 2025
** src/core/window/pl_window_manager
** File description:
** Polara window manager
*/

#include "polara.hpp"

/**
 * @brief Window constructor.
 *
 * @param width         The width of the window
 * @param height        The height of the window
 * @param title         The title of the window
 */
PL::core::Window::Window(int width, int height, const std::string &title)
{
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
    if (m_window == nullptr) {
        glfwTerminate();
        throw std::runtime_error("Polara: Failed to create GLFW window");
    }
    glfwMakeContextCurrent(m_window);
    glEnable(GL_DEPTH_TEST);
}

/**
 * @brief Window deconstructor.
 */
PL::core::Window::~Window(void)
{
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

/**
 * @brief Poll all events to get input/sounds/..
 */
void
PL::core::Window::poll_events(void)
{
    glfwPollEvents();
}

/**
 * @brief Should close method. If TRUE there we need to close the program.
 *
 * @return TRUE or FALSE.
 */
bool
PL::core::Window::should_close(void) const
{
    return glfwWindowShouldClose(this->m_window);
}

/**
 * @brief Swap the buffers of the screen.
 */
void
PL::core::Window::render_frame(void) const
{
    glfwSwapBuffers(this->m_window);
}

/**
 * @brief Clear the frame by clearing the COLOR buffer and DEPTH buffer.
 */
void
PL::core::Window::clear_frame(void) const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
