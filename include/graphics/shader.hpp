/*
** POLARA PROJECT, 2025
** include/graphics/shader.hpp
** File description:
** Shader Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::graphics
{
    class Shader
    {
        private:
            pl_id m_id;

        public:      

            /**
             * @brief Shader constructor.
             *
             * @param vertex_path               The vertex shader path
             * @param fragment_path             The fragment shader path
             */
            Shader(const std::string &vertex_path, const std::string &fragment_path);

            /**
             * @brief Get the ID program of the shader.
             *
             * @return The ID program.
             */
            pl_id get_id(void) const;

            /**
             * @brief Use the shader.
             */
            void use(void) const;

            /**
             * @brief Set a bool uniform parameter.
             *
             * @param name          The name of the parameter
             * @param value         The value of it
             */
            void set_bool(const std::string &name, pl_bool value) const;
            
            /**
             * @brief Set a bool uniform parameter.
             *
             * @param name          The name of the parameter
             * @param value         The value of it
             */
            void set_int(const std::string &name, pl_int value) const;

            /**
             * @brief Set a float uniform parameter.
             *
             * @param name          The name of the parameter
             * @param value         The value of it
             */
            void set_float(const std::string &name, pl_float value) const;
    };
}
