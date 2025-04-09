#!/bin/sh

cd pkg

mkdir -p src

if test -f "src/raylib/README.md"; then
    printf "Raylib found\n"
else
    cd src
    git clone https://github.com/raysan5/raylib.git
    cd ..
fi

mkdir -p mini/raylib

printf "Copying..."
cp src/raylib/cmake -r mini/raylib
cp src/raylib/src -r mini/raylib
cp src/raylib/CMakeLists.txt mini/raylib
cp src/raylib/CMakeOptions.txt mini/raylib
cp src/raylib/LICENSE mini/raylib
cp src/raylib/raylib.pc.in mini/raylib
cp src/raylib/README.md mini/raylib
printf " Done.\n"

cd mini/raylib

tar -cJf "../../raylib.tar.xz" .
