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
    Texture grass("/Users/del/Desktop/tmp_shaders/grass.jpg");
    auto mesh = MeshFactory::create_cube(shader);

    mesh->set_texture(grass);
    mesh->set_transform(glm::rotate(mesh->get_transform(), glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    while (win.should_close() == PL_FALSE) {
        win.clear_frame();

        mesh->render();
        mesh->set_transform(glm::rotate(mesh->get_transform(), (float) glfwGetTime() * glm::radians(0.1f), glm::vec3(0.5f, 1.0f, 0.0f)));

        win.poll_events();
        win.render_frame();
    }
    return 0;
}
