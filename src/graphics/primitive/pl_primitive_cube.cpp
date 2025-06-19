/*
** POLARA PROJECT, 2025
** src/graphics/primitive/pl_primitive_cube
** File description:
** Primitive cube file
*/

#include "polara.hpp"

/**
 * @brief Init the cube.
 *
 * @return PL_TRUE if everything worked. PL_FALSE otherwise.
 */
pl_bool
PL::graphics::PrimitiveManager::init_cube(void)
{
    std::vector<float> vertices = {

        -0.5f, -0.5f,  0.5f,  0, 0, 1,   0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  0, 0, 1,   1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0, 0, 1,   1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0, 0, 1,   0.0f, 1.0f,

        -0.5f, -0.5f, -0.5f,  0, 0, -1,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0, 0, -1,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  0, 0, -1,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0, 0, -1,  0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f, -1, 0, 0,   0.0f, 0.0f,
        -0.5f, -0.5f,  0.5f, -1, 0, 0,   1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f, -1, 0, 0,   1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f, -1, 0, 0,   0.0f, 1.0f,

         0.5f, -0.5f, -0.5f,  1, 0, 0,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1, 0, 0,   1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1, 0, 0,   0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1, 0, 0,   0.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0, -1, 0,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0, -1, 0,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0, -1, 0,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0, -1, 0,  0.0f, 0.0f,

        -0.5f,  0.5f, -0.5f,  0, 1, 0,   0.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0, 1, 0,   0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  0, 1, 0,   1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  0, 1, 0,   1.0f, 1.0f,
    };
    std::vector<unsigned int> indices = {
        0, 1, 2, 2, 3, 0,
        4, 5, 6, 6, 7, 4,
        8, 9, 10, 10, 11, 8,
        12, 13, 14, 14, 15, 12,
        16, 17, 18, 18, 19, 16,
        20, 21, 22, 22, 23, 20
    };
    m_primitive_data data = {0};

    if (m_geometries.find("cube") != m_geometries.end()) {
        return PL_FALSE;
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
    m_geometries["cube"] = data;
    return PL_TRUE;
}
