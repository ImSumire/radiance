#!/bin/sh

mkdir -p target/linux
# cc -Ofast -o target/linux/release src/main.c -lraylib -lm
g++ -Ofast \
   -o target/linux/release \
   src/main.cpp \
   -Wl,-rpath,target/pkg/raylib/build/raylib \
   -lraylib -lm
