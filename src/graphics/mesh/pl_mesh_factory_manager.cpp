/*
** POLARA PROJECT, 2025
** src/graphics/mesh/mesh_factory_manager
** File description:
** Mesh principale file
*/

#include "polara.hpp"

/**
 * @brief Create a cube by using the primitive.
 *
 * @return The pointer to the mesh.
 */
std::unique_ptr<PL::graphics::Mesh>
PL::graphics::MeshFactory::create_cube(void)
{
    if (PrimitiveManager::get_primitive("cube") != nullptr) {
        PrimitiveManager::init_cube();
    }
    return nullptr;
}
