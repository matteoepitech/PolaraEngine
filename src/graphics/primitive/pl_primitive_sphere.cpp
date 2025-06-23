/*
** POLARA PROJECT, 2025
** src/graphics/primitive/pl_primitive_sphere
** File description:
** Primitive sphere file
*/

#include "polara.hpp"

/**
 * @brief Init the sphere.
 *
 * @return PL_TRUE if everything worked. PL_FALSE otherwise.
 */
/**
 * @brief Init the sphere.
 *
 * @return PL_TRUE if everything worked. PL_FALSE otherwise.
 */
pl_bool
PL::graphics::PrimitiveManager::init_sphere(void)
{
    const unsigned int x_segments = 64;
    const unsigned int y_segments = 64;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    m_primitive_data data = {0};

    if (m_geometries.find("sphere") != m_geometries.end()) return PL_FALSE;
    for (unsigned int y = 0; y <= y_segments; ++y) {
        for (unsigned int x = 0; x <= x_segments; ++x) {
            float x_segment = (float)x / (float)x_segments;
            float y_segment = (float)y / (float)y_segments;
            float x_pos = std::cos(x_segment * 2.0f * M_PI) * std::sin(y_segment * M_PI);
            float y_pos = std::cos(y_segment * M_PI);
            float z_pos = std::sin(x_segment * 2.0f * M_PI) * std::sin(y_segment * M_PI);
            vertices.push_back(x_pos * 0.5f);
            vertices.push_back(y_pos * 0.5f);
            vertices.push_back(z_pos * 0.5f);
            vertices.push_back(x_pos);
            vertices.push_back(y_pos);
            vertices.push_back(z_pos);
            vertices.push_back(x_segment);
            vertices.push_back(y_segment);
        }
    }
    for (unsigned int y = 0; y < y_segments; ++y) {
        for (unsigned int x = 0; x < x_segments; ++x) {
            unsigned int i0 = y * (x_segments + 1) + x;
            unsigned int i1 = i0 + 1;
            unsigned int i2 = (y + 1) * (x_segments + 1) + x;
            unsigned int i3 = i2 + 1;
            indices.push_back(i0);
            indices.push_back(i1);
            indices.push_back(i2);
            indices.push_back(i2);
            indices.push_back(i1);
            indices.push_back(i3);
        }
    }
    glGenVertexArrays(1, &data._vao);
    glGenBuffers(1, &data._vbo);
    glGenBuffers(1, &data._ebo);
    glBindVertexArray(data._vao);
    glBindBuffer(GL_ARRAY_BUFFER, data._vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data._ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    data._index_count = indices.size();
    m_geometries["sphere"] = data;
    return PL_TRUE;
}
