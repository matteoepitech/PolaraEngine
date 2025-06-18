cmake_minimum_required(VERSION 3.16)
project(polara LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE POLARA_SRC src/*.cpp)
add_library(polara SHARED ${POLARA_SRC})

target_include_directories(polara PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/stb
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/glm
)

add_library(glad STATIC
    third_party/glad/src/glad.c
)
target_include_directories(glad PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/third_party/glad/include
)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

target_link_libraries(polara PUBLIC
    glad
    glfw
    OpenGL::GL
)

if(APPLE)
    target_link_libraries(polara PUBLIC
        "-framework Cocoa"
        "-framework IOKit"
        "-framework CoreFoundation"
        "-framework CoreVideo"
    )
endif()
