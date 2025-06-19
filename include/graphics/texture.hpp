/*
** POLARA PROJECT, 2025
** include/graphics/texture
** File description:
** Texture Header file
*/

#pragma once

#include "polara.hpp"

namespace PL::graphics
{
    class Texture
    {
        private:
            pl_id m_id;
            std::string m_path;
            pl_int m_width;
            pl_int m_height;
            pl_int m_channels;
            unsigned char *m_data;

        public:      

            /**
             * @brief Constructor of a texture.
             *
             * @param path
             */
            Texture(const std::string &path);

            /**
             * @brief Use the texture.
             */
            void use(void) const;
    };
}
