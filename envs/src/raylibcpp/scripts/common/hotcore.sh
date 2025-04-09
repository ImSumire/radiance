#!/bin/sh

HOTCORE_BANNER="\e[34;1mhotcore\e[0m"

printf "$HOTCORE_BANNER Compiling src/main.c..."
g++ -Og -g \
    -o target/hot/main \
    src/main.cpp \
    target/hot/libraylib.so.??? \
    -lltdl -ldl -lm \
    -DHOT
printf " Done.\n"
