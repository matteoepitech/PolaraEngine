/*
** POLARA PROJECT, 2025
** src/graphics/primitive/pl_primitive_cone
** File description:
** Primitive cone file
*/

#include "polara.hpp"

/**
 * @brief Init the cone.
 *
 * @return PL_TRUE if everything worked. PL_FALSE otherwise.
 */
pl_bool
PL::graphics::PrimitiveManager::init_cone(void)
{
    const int resolution = 32;
    const float radius = 0.5f;
    const float height = 1.0f;
    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    m_primitive_data data = {0};

    if (m_geometries.find("cone") != m_geometries.end())
        return PL_FALSE;
    vertices.insert(vertices.end(), {
        0.0f, height / 2.0f, 0.0f,
        0.0f, 1.0f, 0.0f,
        0.5f, 1.0f
    });
    vertices.insert(vertices.end(), {
        0.0f, -height / 2.0f, 0.0f,
        0.0f, -1.0f, 0.0f,
        0.5f, 0.5f
    });
    for (int i = 0; i < resolution; ++i) {
        float angle = (2.0f * M_PI * i) / resolution;
        float x = cos(angle) * radius;
        float z = sin(angle) * radius;
        vertices.push_back(x);
        vertices.push_back(-height / 2.0f);
        vertices.push_back(z);
        vertices.push_back(0.0f);
        vertices.push_back(-1.0f);
        vertices.push_back(0.0f);
        vertices.push_back((x / radius + 1.0f) * 0.5f);
        vertices.push_back((z / radius + 1.0f) * 0.5f);
    }
    for (int i = 0; i < resolution; ++i) {
        int current = i + 2;
        int next = ((i + 1) % resolution) + 2;
        indices.push_back(0);
        indices.push_back(next);
        indices.push_back(current);
    }
    for (int i = 0; i < resolution; ++i) {
        int current = i + 2;
        int next = ((i + 1) % resolution) + 2;
        indices.push_back(1);
        indices.push_back(next);
        indices.push_back(current);
    }
    glGenVertexArrays(1, &data._vao);
    glGenBuffers(1, &data._vbo);
    glGenBuffers(1, &data._ebo); 
    glBindVertexArray(data._vao);
    glBindBuffer(GL_ARRAY_BUFFER, data._vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, data._ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) 0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*) (6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    data._index_count = indices.size();
    m_geometries["cone"] = data;
    return PL_TRUE;
}
