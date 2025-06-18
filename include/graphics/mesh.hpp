/*
** POLARA PROJECT, 2025
** include/graphics/mesh
** File description:
** Mesh Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::graphics
{
    class Mesh
    {
        private:
            glm::mat4 m_transform = glm::mat4(1.0f);
            std::string m_mesh_name;
            
        public:

            /**
             * @brief Mesh constructor.
             *
             * @param name              The name of the mesh
             */
            Mesh(const std::string &name) : m_mesh_name(name) {}
            
            /**
             * @brief Render the mesh on the screen.
             */
            void render(void) const;
            
            /**
             * @brief Set the transform of the mesh using a transform mat4.
             *
             * @param transform         The transform
             */
            void set_transform(const glm::mat4 &transform);

            /**
             * @brief Get the transform of the mesh.
             *        Location/Rotation/Scale
             *
             * @return The transform mat4.
             */
            const glm::mat4 &get_transform(void) const;
    };
}
