/*
** POLARA PROJECT, 2025
** include/graphics/mesh_factory
** File description:
** Mesh factory Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::graphics
{
    class MeshFactory
    {
        public:

            /**
             * @brief Create a cube by using the primitive.
             *
             * @return The pointer to the mesh.
             */
            static std::unique_ptr<Mesh> create_cube(Shader shader);
            
            /**
             * @brief Create a cone by using the primitive.
             *
             * @return The pointer to the mesh.
             */
            static std::unique_ptr<Mesh> create_cone(Shader shader);
            
            /**
             * @brief Create a sphere by using the primitive.
             *
             * @return The pointer to the mesh.
             */
            static std::unique_ptr<Mesh> create_sphere(Shader shader);
    };
}
