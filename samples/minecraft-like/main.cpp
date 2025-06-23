/*
** POLARA PROJECT, 2025
** samples/test/main
** File description:
** Minecraft like procedural
*/

#include "core/core.hpp"
#include "input/mouse.hpp"
#include "polara.hpp"

using namespace PL::core;
using namespace PL::graphics;

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char* WINDOW_TITLE = "Test program";
const float MOVEMENT_SPEED = 5.0f;

const int TERRAIN_WIDTH = 150;
const int TERRAIN_DEPTH = 150;
const float NOISE_SCALE = 0.1f;
const float HEIGHT_MULTIPLIER = 10.0f;

std::vector<glm::vec3> CUBE_POSITIONS;

/**
 * @brief Handles camera movement and input
 */
class CameraController {

private:
    glm::vec3 position;
    float speed;

public:
    /**
     * @brief Construct a new Camera Controller
     *
     * @param initial_pos Initial camera position
     * @param move_speed Base movement speed
     */
    CameraController(const glm::vec3& initial_pos = glm::vec3(0.0f, 0.0f, 3.0f), 
                     float move_speed = MOVEMENT_SPEED)
        : position(initial_pos), speed(move_speed) {}

    /**
     * @brief Update camera movement from user input
     *
     * @param window Pointer to GLFW window
     */
    void update(Window &window)
    {
        speed = MOVEMENT_SPEED * pl_get_delta_time();
        glm::vec3 front = glm::normalize(glm::vec3(Camera::get_front().x, 0.0f, Camera::get_front().z));
        glm::vec3 right = glm::normalize(glm::cross(front, Camera::get_up()));
        glm::vec3 movement(0.0f);

        if (glfwGetKey(window.get_window(), GLFW_KEY_W) == GLFW_PRESS)
            movement += front * speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_S) == GLFW_PRESS)
            movement -= front * speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_A) == GLFW_PRESS)
            movement -= right * speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_D) == GLFW_PRESS)
            movement += right * speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_SPACE) == GLFW_PRESS)
            movement.y += speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
            movement.y -= speed;
        if (glfwGetKey(window.get_window(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
            PL::input::pl_ungrab_mouse(window);

        position += movement;
        Camera::set_position(position);
    }

    /**
     * @brief Get the camera position
     *
     * @return Reference to camera position
     */
    const glm::vec3& get_position() const { return position; }
};

/**
 * @brief Renders multiple cubes in a procedurally generated terrain
 */
class CubeRenderer {

private:
    std::unique_ptr<Mesh> mesh;

public:
    /**
     * @brief Construct a new Cube Renderer
     *
     * @param shader Reference to shader
     * @param texture Reference to texture
     */
    CubeRenderer(const Shader& shader, const Texture& texture)
    {
        mesh = MeshFactory::create_cube(shader);
        mesh->set_texture(texture);

        for (int x = 0; x < TERRAIN_WIDTH; ++x) {
            for (int z = 0; z < TERRAIN_DEPTH; ++z) {
                float height = glm::simplex(glm::vec2(x * NOISE_SCALE, z * NOISE_SCALE));
                height = glm::clamp(height, -1.0f, 1.0f) * HEIGHT_MULTIPLIER;

                for (int y = 0; y < static_cast<int>(height); ++y) {
                    CUBE_POSITIONS.push_back(glm::vec3(x, y, z));
                }
            }
        }
    }

    /**
     * @brief Render all cubes
     */
    void render_cubes() const
    {
        for (const auto& pos : CUBE_POSITIONS) {
            glm::mat4 model = glm::translate(glm::mat4(1.0f), pos);
            mesh->set_transform(model);
            mesh->render();
        }
    }
};

/**
 * @brief Main program entry
 *
 * @param argc Arg count
 * @param argv Arg values
 * @return int
 */
int main(int argc, char *argv[])
{
    try {
        Window win(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
        Shader shader("/Users/del/Desktop/tmp_shaders/triangle.vert",
                      "/Users/del/Desktop/tmp_shaders/triangle.frag");
        Texture grass("/Users/del/Desktop/tmp_shaders/grass.jpg");

        CameraController camera_controller;
        CubeRenderer cube_renderer(shader, grass);

        while (win.should_close() == PL_FALSE) {
            win.clear_frame();

            camera_controller.update(win);
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
