#!/bin/sh

mkdir -p target/linux
# cc -Ofast -o target/linux/release src/main.c -lraylib -lm
cc -Ofast \
   -o target/linux/release \
   src/main.c \
   -Wl,-rpath,target/pkg/raylib/build/raylib \
   -lraylib -lm
