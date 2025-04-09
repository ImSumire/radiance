#!/bin/sh

INIT_BANNER="\e[32;1minit\e[0m"

mkdir -p target/pkg
cd target/pkg

# Include Raylib package (lastest)
if test -f "./raylib/README.md"; then
    printf "$INIT_BANNER Found target/pkg/raylib/\n"
else
    printf "$INIT_BANNER Cloning the Raylib repo...\n" &&
    mkdir -p raylib &&
    cd raylib &&
    curl -s https://imsumire.github.io/radiance/pkg/raylib.tar.xz | tar xJf - &&
    cd .. &&
    printf "$INIT_BANNER Repo cloned\n"
fi

# Build Raylib
cd raylib

if test -f "./build/raylib/libraylib.so"; then
    printf "$INIT_BANNER Found target/pkg/raylib/libraylib.so\n"
else
    printf "$INIT_BANNER Building raylib...\n" &&
    mkdir -p build &&
    cd build &&
    cmake .. -GNinja \
        -DBUILD_SHARED_LIBS=ON -DWITH_PIC=ON -DBUILD_EXAMPLES=OFF &&
    ninja &&
    cd ..
fi

# Back to the root
cd ../../..
 
mkdir -p target/hot

cp target/pkg/raylib/build/raylib/libraylib.so.??? target/hot
