/*
** POLARA PROJECT, 2025
** samples/test/main
** File description:
** Minecraft like
*/

#include "core/core.hpp"
#include "polara.hpp"

using namespace PL::core;
using namespace PL::graphics;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char* WINDOW_TITLE = "Test program";
const int NUM_CUBES = 10;
const float MOVEMENT_SPEED = 2.5f;
const float ROTATION_SPEED = 20.0f;

const std::array<glm::vec3, NUM_CUBES> CUBE_POSITIONS = {{
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
}};

class CameraController {

private:
    glm::vec3 position;
    float speed;
    
public:
    CameraController(const glm::vec3& initial_pos = glm::vec3(0.0f, 0.0f, 3.0f), 
                    float move_speed = MOVEMENT_SPEED) 
        : position(initial_pos), speed(move_speed) {}
    
    void update(GLFWwindow* window)
    {
        speed = MOVEMENT_SPEED * pl_get_delta_time();
        glm::vec3 movement(0.0f);
        if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
            movement.z -= speed;
        if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)  
            movement.z += speed;
        if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
            movement.x -= speed;
        if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
            movement.x += speed;
        if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
            movement.y += speed;
        if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            movement.y -= speed; 
        position += movement;
        Camera::set_position(position);
    }
    
    const glm::vec3& get_position() const { return position; }
};

class CubeRenderer {

private:
    std::unique_ptr<Mesh> mesh;
    
public:
    CubeRenderer(const Shader& shader, const Texture& texture)
    {
        mesh = MeshFactory::create_cube(shader);
        mesh->set_texture(texture);
    }
    
    void render_cubes() const
    {
        float current_time = static_cast<float>(glfwGetTime());
        
        for (size_t i = 0; i < NUM_CUBES; ++i) {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, CUBE_POSITIONS[i]);
            
            float angle = ROTATION_SPEED * (i + 1);
            glm::vec3 rotation_axis(1.0f, 0.3f, 0.5f);
            model = glm::rotate(model, current_time * glm::radians(angle), rotation_axis);
            
            mesh->set_transform(model);
            mesh->render();
        }
    }
};

static void setup_opengl()
{
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[]) {
    try {
        Window win(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        Shader shader("/Users/del/Desktop/tmp_shaders/triangle.vert", 
                     "/Users/del/Desktop/tmp_shaders/triangle.frag");
        Texture grass("/Users/del/Desktop/tmp_shaders/grass.jpg");
        
        setup_opengl();

        CameraController camera_controller;
        CubeRenderer cube_renderer(shader, grass);

        while (win.should_close() == PL_FALSE) {
            win.clear_frame();
            

            camera_controller.update(win.get_window());

            cube_renderer.render_cubes();

            win.poll_events();
            win.render_frame();
        }
        
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
        return -1;
    } 
    return 0;
}
