#!/bin/bash

OS="$(uname -s)"
mkdir -p build && cd build

# MacOS
if [[ "$OS" == "Darwin" ]]; then
    cmake ..
    cmake --build . -- -j$(sysctl -n hw.ncpu)
    cp -r ../resources/* ~/Desktop/tmp_shaders/
    cp libpolara.dylib ../samples/test/
    cp libpolara.dylib ../samples/minecraft-like/
    printf "\033[32;1mBuild done for MacOS!\033[0m\n"

# Linux
elif [[ "$OS" == "Linux" ]]; then
    cmake ..
    cmake --build . -- -j$(nproc)
    printf "\033[32;1mBuild done for Linux!\033[0m\n"

# Windows
elif [[ "$OS" == MINGW* || "$OS" == MSYS* || "$OS" == CYGWIN* ]]; then
    cmake -G "MinGW Makefiles" ..
    cmake --build .
    printf "\033[32;1mBuild done for Windows!\033[0m\n"

else
    echo "Unsupported OS: $OS"
    exit 1
fi
