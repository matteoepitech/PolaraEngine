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
PL::graphics::MeshFactory::create_cube(PL::graphics::Shader shader)
{
    std::unique_ptr<PL::graphics::Mesh> mesh = nullptr;

    if (PrimitiveManager::get_primitive("cube") == nullptr) {
        std::cout << "[PL] Init of a cube!" << std::endl;
        PrimitiveManager::init_cube();
    }
    std::cout << "[PL] Creating a cube!" << std::endl;
    mesh = std::make_unique<Mesh>("cube", shader);
    if (mesh == nullptr) {
        std::cerr << "[PL] Cannot create a cube!" << std::endl;
        return nullptr;
    }
    mesh->set_transform(glm::mat4(1.0f));
    return mesh;
}

/**
 * @brief Create a cone by using the primitive.
 *
 * @return The pointer to the mesh.
 */
std::unique_ptr<PL::graphics::Mesh>
PL::graphics::MeshFactory::create_cone(PL::graphics::Shader shader)
{
    std::unique_ptr<PL::graphics::Mesh> mesh = nullptr;

    if (PrimitiveManager::get_primitive("cone") == nullptr) {
        std::cout << "[PL] Init of a cone!" << std::endl;
        PrimitiveManager::init_cone();
    }
    std::cout << "[PL] Creating a cone!" << std::endl;
    mesh = std::make_unique<Mesh>("cone", shader);
    if (mesh == nullptr) {
        std::cerr << "[PL] Cannot create a cone!" << std::endl;
        return nullptr;
    }
    mesh->set_transform(glm::mat4(1.0f));
    return mesh;
}

/**
 * @brief Create a sphere by using the primitive.
 *
 * @return The pointer to the mesh.
 */
std::unique_ptr<PL::graphics::Mesh>
PL::graphics::MeshFactory::create_sphere(PL::graphics::Shader shader)
{
    std::unique_ptr<PL::graphics::Mesh> mesh = nullptr;

    if (PrimitiveManager::get_primitive("sphere") == nullptr) {
        std::cout << "[PL] Init of a sphere!" << std::endl;
        PrimitiveManager::init_sphere();
    }
    std::cout << "[PL] Creating a sphere!" << std::endl;
    mesh = std::make_unique<Mesh>("sphere", shader);
    if (mesh == nullptr) {
        std::cerr << "[PL] Cannot create a sphere!" << std::endl;
        return nullptr;
    }
    mesh->set_transform(glm::mat4(1.0f));
    return mesh;
}
