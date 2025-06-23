/*
** POLARA PROJECT, 2025
** include/core/window
** File description:
** Window Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::core
{
    class Window {

    public:
        /**
         * @brief Window constructor.
         *
         * @param width         The width of the window
         * @param height        The height of the window
         * @param title         The title of the window
         */
        Window(pl_int width, pl_int height, const std::string &title);

        /**
         * @brief Window deconstructor.
         */
        ~Window(void);

        /**
         * @brief Poll all events to get input/sounds/..
         */
        void poll_events(void);

        /**
         * @brief Should close method. If TRUE there we need to close the program.
         *
         * @return TRUE or FALSE.
         */
        pl_bool should_close() const;

        /**
         * @brief Swap the buffers of the screen.
         */
        void render_frame(void) const;

        /**
         * @brief Clear the frame by clearing the COLOR buffer and DEPTH buffer.
         */
        void clear_frame(void) const;

        /**
         * @brief Get the window GLFW pointer.
         *
         * @return 
         */
        GLFWwindow *get_window(void) const;

    private:
        pl_int m_width;
        pl_int m_height;
        GLFWwindow *m_window;

    };

} // namespace PL
