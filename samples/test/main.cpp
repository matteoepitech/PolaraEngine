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
    glm::vec3 cube_positions[] = {
        glm::vec3( 0.0f,  0.3f,  0.0f), 
        glm::vec3( 2.0f,  5.0f, -15.0f), 
        glm::vec3(-1.5f, -2.2f, -2.5f),  
        glm::vec3(-3.8f, -2.0f, -12.3f),  
        glm::vec3( 2.4f, -0.4f, -3.5f),  
        glm::vec3(-1.7f,  3.0f, -7.5f),  
        glm::vec3( 1.3f, -2.0f, -2.5f),  
        glm::vec3( 1.5f,  2.0f, -2.5f), 
        glm::vec3( 1.5f,  0.2f, -1.5f), 
        glm::vec3(-1.3f,  1.0f, -1.5f)  
    };
    auto mesh = MeshFactory::create_cube(shader);

    mesh->set_texture(grass);

    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    while (win.should_close() == PL_FALSE) {
        win.clear_frame();

        for(unsigned int i = 0; i < 10; i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, cube_positions[i]);
            float angle = 20.0f * (i + 1);
            model = glm::rotate(model, (float) glfwGetTime() * glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            mesh->set_transform(model);
            mesh->render();
        }

        win.poll_events();
        win.render_frame();
    }
    return 0;
}
