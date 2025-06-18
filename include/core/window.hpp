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
    class window {

    public:
        window(int width, int height, const std::string &title);
        ~window();

        void poll_events();
        bool should_close() const;

    private:
        GLFWwindow *m_window;

    };

} // namespace PL
