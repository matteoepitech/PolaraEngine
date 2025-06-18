#!/usr/bin/env bash

cd ../../
./build.sh
cd ./samples/test

if [[ "$OSTYPE" == "darwin"* ]]; then
    # macOS
    echo "Building for macOS..."
    gcc main.c -o program -lpolara -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo -I../../include/ -Wl,-rpath,.
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    # Linux
    echo "Building for Linux..."
    gcc main.c -o program -fsanitize=address -lglfw -lGL -lX11 -ldl -lpthread -lm -I../../include/
elif [[ "$OSTYPE" == "msys" ]] || [[ "$OSTYPE" == "cygwin" ]]; then
    # Windows (Git Bash/Cygwin)
    echo "Building for Windows..."
    gcc main.c -o program.exe -fsanitize=address -lglfw3 -lopengl32 -luser32 -lgdi32 -lshell32 -lws2_32 -I../../include/
fi

./program
rm ./program
