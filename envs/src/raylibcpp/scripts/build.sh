#!/bin/sh

BUILD_BANNER="\e[34;1mbuild\e[0m"

mkdir -p target/linux

printf "$BUILD_BANNER Compiling src/main.c..."
g++ -Ofast \
   -o target/linux/release \
   src/main.cpp \
   -Wl,-rpath,target/pkg/raylib/build/raylib \
   -lraylib -lm
printf " Done.\n"
