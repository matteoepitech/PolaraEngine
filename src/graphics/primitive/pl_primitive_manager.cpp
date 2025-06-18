/*
** POLARA PROJECT, 2025
** src/graphics/primitive/primitive_manager
** File description:
** Primitive manager file
*/

#include "polara.hpp"

/**
 * @brief The geometries global variable.
 */
std::unordered_map<std::string, PL::graphics::PrimitiveManager::m_primitive_data> PL::graphics::PrimitiveManager::m_geometries;

/**
 * @brief Init the cube.
 *
 * @return PL_TRUE if everything worked. PL_FALSE otherwise.
 */
pl_bool
PL::graphics::PrimitiveManager::init_cube(void)
{
    return PL_TRUE;
}

/**
 * @brief Get the primitive data of a primitive.
 *
 * @param name              The name of the primitive
 *
 * @return The data of the primitive.
 */
const PL::graphics::PrimitiveManager::m_primitive_data *
PL::graphics::PrimitiveManager::get_primitive(const std::string &name)
{
    return nullptr;
}
