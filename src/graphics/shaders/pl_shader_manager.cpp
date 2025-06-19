/*
** POLARA PROJECT, 2025
** src/graphics/shaders/pl_shader_manager
** File description:
** Polara window manager
*/

#include "polara.hpp"

/**
 * @brief Compile logic for frag/vert shader.
 *
 * @param vert_code             The vertex shader code
 * @param frag_code             The fragment shader code
 *
 * @return TRUE if everything worked. FALSE otherwise.
 */
static pl_bool
compile_shader_logic(const char *vert_code, const char *frag_code, pl_id &shader_id)
{
    pl_id vert_id;
    pl_id frag_id;
    int success;
    char infoLog[512];

    vert_id = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vert_id, 1, &vert_code, NULL);
    glCompileShader(vert_id);
    glGetShaderiv(vert_id, GL_COMPILE_STATUS, &success);
    if(success == PL_FALSE) {
        glGetShaderInfoLog(vert_id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::VERTEX_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        return PL_FALSE;
    };
    frag_id = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(frag_id, 1, &frag_code, NULL);
    glCompileShader(frag_id);
    glGetShaderiv(frag_id, GL_COMPILE_STATUS, &success);
    if(success == PL_FALSE) {
        glGetShaderInfoLog(frag_id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::FRAGMENT_SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
        return PL_FALSE;
    };
    shader_id = glCreateProgram();
    glAttachShader(shader_id, vert_id);
    glAttachShader(shader_id, frag_id);
    glLinkProgram(shader_id);
    glGetProgramiv(shader_id, GL_LINK_STATUS, &success);
    if(success == PL_FALSE) {
        glGetProgramInfoLog(shader_id, 512, NULL, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return PL_FALSE;
    }
    glDeleteShader(vert_id);
    glDeleteShader(frag_id);
    return PL_TRUE;
}

/**
 * @brief Shader constructor.
 *
 * @param vertex_path               The vertex shader path
 * @param fragment_path             The fragment shader path
 */
PL::graphics::Shader::Shader(const std::string &vertex_path, const std::string &fragment_path)
{
    std::string vert_content;
    std::string frag_content;
    std::ifstream vert_file;
    std::ifstream frag_file;
    std::stringstream vert_stream;
    std::stringstream frag_stream;
    const char* frag_code = nullptr;
    const char* vert_code = nullptr;
    
    vert_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    frag_file.exceptions (std::ifstream::failbit | std::ifstream::badbit);
    try {
        vert_file.open(vertex_path);
        frag_file.open(fragment_path);
        vert_stream << vert_file.rdbuf();
        frag_stream << frag_file.rdbuf();
        vert_file.close();
        frag_file.close();
        vert_content = vert_stream.str();
        frag_content = frag_stream.str();
    } catch(std::ifstream::failure e) {
        if (errno == ENOENT) {
            std::cerr << "ERROR::SHADER::FILE_NOT_EXISTING" << std::endl;
        } else {
            std::cerr << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        }
    }
    frag_code = frag_content.c_str();
    vert_code = vert_content.c_str();
    compile_shader_logic(vert_code, frag_code, this->m_id);
}

/**
 * @brief Get the ID program of the shader.
 *
 * @return The ID program.
 */
pl_id
PL::graphics::Shader::get_id(void) const
{
    return this->m_id;
}

/**
 * @brief Use the shader. Using the ID of the program.
 */
void
PL::graphics::Shader::use(void) const
{
    glUseProgram(this->m_id);
}

/**
 * @brief Set a uniform BOOL in the shader.
 *
 * @param name          The name of the uniform
 * @param value         The new value
 */
void
PL::graphics::Shader::set_bool(const std::string &name, pl_bool value) const
{         
    glUniform1i(glGetUniformLocation(this->m_id, name.c_str()), (pl_int) value); 
}

/**
 * @brief Set a uniform INT in the shader.
 *
 * @param name          The name of the uniform
 * @param value         The new value
 */
void
PL::graphics::Shader::set_int(const std::string &name, pl_int value) const
{ 
    glUniform1i(glGetUniformLocation(this->m_id, name.c_str()), value); 
}

/**
 * @brief Set a uniform FLOAT in the shader.
 *
 * @param name          The name of the uniform
 * @param value         The new value
 */
void
PL::graphics::Shader::set_float(const std::string &name, pl_float value) const
{ 
    glUniform1f(glGetUniformLocation(this->m_id, name.c_str()), value); 
} 
