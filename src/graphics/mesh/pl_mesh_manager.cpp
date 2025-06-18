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

    if (primitive != nullptr) {
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
