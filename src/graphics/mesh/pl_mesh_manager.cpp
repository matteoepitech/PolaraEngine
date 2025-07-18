/*
** POLARA PROJECT, 2025
** src/graphics/mesh/mesh_manager
** File description:
** Mesh principale file
*/

#include "polara.hpp"

/**
 * @brief Render the mesh on the screen.
 */
void
PL::graphics::Mesh::render() const
{
    auto primitive = PrimitiveManager::get_primitive(this->m_mesh_name);
    glm::mat4 projection = core::Camera::get_projection();
    glm::vec3 camera_pos = core::Camera::get_position();
    glm::vec3 camera_up = core::Camera::get_up();
    glm::vec3 camera_front = core::Camera::get_front();
    glm::mat4 view = glm::lookAt(camera_pos, camera_pos + camera_front, camera_up);

    if (primitive != nullptr) {
        this->m_shader.use();
        this->m_texture->use();
        glUniformMatrix4fv(glGetUniformLocation(this->m_shader.get_id(), "u_model"), 1, GL_FALSE, glm::value_ptr(this->m_transform));
        glUniformMatrix4fv(glGetUniformLocation(this->m_shader.get_id(), "u_projection"), 1, GL_FALSE, glm::value_ptr(projection));
        glUniformMatrix4fv(glGetUniformLocation(this->m_shader.get_id(), "u_view"), 1, GL_FALSE, glm::value_ptr(view));
        glBindVertexArray(primitive->_vao);
        glDrawElements(primitive->_draw_mode, primitive->_index_count, GL_UNSIGNED_INT, 0);
    }
}

/**
 * @brief Set the transform of the mesh using a transform mat4.
 *
 * @param transform         The transform
 */
void
PL::graphics::Mesh::set_transform(const glm::mat4 &transform)
{
    this->m_transform = transform;
}

/**
 * @brief Get the transform of the mesh.
 *        Location/Rotation/Scale
 *
 * @return The transform mat4.
 */
const glm::mat4 &
PL::graphics::Mesh::get_transform() const
{
    return this->m_transform;
}

/**
 * @brief Set the texture of the mesh.
 *
 * @param texture
 */
void
PL::graphics::Mesh::set_texture(PL::graphics::Texture texture)
{
    this->m_texture = std::make_unique<PL::graphics::Texture>(texture);
}
