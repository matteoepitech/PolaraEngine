/*
** POLARA PROJECT, 2025
** src/graphics/primitive/pl_primitive_manager
** File description:
** Primitive manager file
*/

#include "polara.hpp"

/**
 * @brief The geometries global variable.
 */
std::unordered_map<std::string, PL::graphics::PrimitiveManager::m_primitive_data> PL::graphics::PrimitiveManager::m_geometries;

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
    auto it = PL::graphics::PrimitiveManager::m_geometries.find(name);

    if (it != PL::graphics::PrimitiveManager::m_geometries.end()) {
        return &it->second;
    } else {
        return nullptr;
    }
}
