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
    pl_float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f,  0.5f, 0.0f
    };
    pl_id vao;
    pl_id vbo;

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    
    if (vao == 0 || vbo == 0)
        return 1;

    while (win.should_close() == PL_FALSE) {
        win.clear_frame();

        glBindVertexArray(vao);
        shader.use();
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        win.poll_events();
        win.render_frame();
    }
    return 0;
}
