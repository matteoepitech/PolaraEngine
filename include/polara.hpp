/*
** POLARA PROJECT, 2025
** include/polara
** File description:
** Polara ENGINE principal header file
*/

#pragma once

#define GL_SILENCE_DEPRECATION

#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <string>

#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include "../third_party/glm/glm.hpp"
#include "../third_party/glm/gtc/matrix_transform.hpp"
#include "../third_party/glm/gtc/type_ptr.hpp"

#include "polara_defines.hpp"
#include "polara_types.hpp"

#include "core/window.hpp"
#include "graphics/shader.hpp"
#include "graphics/primitive.hpp"
#include "graphics/mesh.hpp"
#include "graphics/mesh_factory.hpp"
