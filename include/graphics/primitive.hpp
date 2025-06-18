/*
** POLARA PROJECT, 2025
** include/graphics/primitive
** File description:
** Primitive Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::graphics
{
    class PrimitiveManager
    {
        public:
            using m_primitive_data = struct primitive_data_s {
                pl_id _vao;
                pl_id _vbo;
                pl_id _ebo;
                pl_long _index_count;
                GLenum _draw_mode = GL_TRIANGLES;
            };
            static std::unordered_map<std::string, m_primitive_data> m_geometries;

        public:

            /**
             * @brief Init the cube.
             *
             * @return PL_TRUE if everything worked. PL_FALSE otherwise.
             */
            static pl_bool init_cube(void);

            /**
             * @brief Get the primitive data of a primitive.
             *
             * @param name              The name of the primitive
             *
             * @return The data of the primitive.
             */
            static const m_primitive_data *get_primitive(const std::string &name);

            /**
             * @brief Free all primitives geometries data.
             */
            static void free_resources(void);
            
    };
}
