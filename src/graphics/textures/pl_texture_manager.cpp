/*
** POLARA PROJECT, 2025
** src/graphics/shaders/pl_texture_manager
** File description:
** Polara texture manager
*/

#include "polara.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "../third_party/stb/stb_image.h"

/**
 * @brief Constructor of a texture.
 *
 * @param path
 */
PL::graphics::Texture::Texture(const std::string &path)
{
    GLenum format = GL_RGB;

    stbi_set_flip_vertically_on_load(true);
    this->m_data = stbi_load(path.c_str(),
        &this->m_width,
        &this->m_height,
        &this->m_channels,
        0);        
    if (this->m_data == nullptr) {
        std::cerr << "[PL] Erreur: Cannot open the path: " << path << std::endl;
        return;
    }
    std::cout << "[PL] Texture loaded: " << path << std::endl;
    std::cout << "[PL] Dimensions: " << this->m_width << "x" << this->m_height << ", Channels: " << this->m_channels << std::endl;
    switch(this->m_channels) {
        case 1:
            format = GL_RED;
            break;
        case 3:
            format = GL_RGB;
            break;
        case 4:
            format = GL_RGBA;
            break;
        default:
            std::cerr << "[PL] Image format not supported " << this->m_channels << " channels" << std::endl;
            stbi_image_free(this->m_data);
            return;
    }
    glGenTextures(1, &this->m_id);
    glBindTexture(GL_TEXTURE_2D, this->m_id);
    glTexImage2D(GL_TEXTURE_2D, 0, format, this->m_width, this->m_height, 0, format, GL_UNSIGNED_BYTE, this->m_data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glGenerateMipmap(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    std::cout << "[PL] Texture created (ID: " << this->m_id << ")" << std::endl;
}

/**
 * @brief Use the texture.
 */
void
PL::graphics::Texture::use(void) const
{
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->m_id);
}
