/*
** EPITECH PROJECT, 2025
** samples/test/main
** File description:
** Test game
*/

#include "../include/polara.hpp"

using namespace PL::core;
using namespace PL::graphics;

/**
 * @brief Main function
 *
 * @param argc
 * @param argv[]
 *
 * @return 
 */
int main(int argc, char *argv[])
{
    Window win(1280, 720, "Test program");
    Shader shader("/Users/del/Desktop/tmp_shaders/triangle.vert", "/Users/del/Desktop/tmp_shaders/triangle.frag");

    PrimitiveManager::init_cube();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    while (win.should_close() == PL_FALSE) {
        win.clear_frame();

        shader.use();

        win.poll_events();
        win.render_frame();
    }
    return 0;
}
