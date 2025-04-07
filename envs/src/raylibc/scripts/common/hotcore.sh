#!/bin/sh

HOTCORE_BANNER="\e[34;1mhotcore\e[0m"

printf "$HOTCORE_BANNER Compiling src/main.c..."
cc -Og -g \
   -o target/hot/main \
   src/main.c \
   target/hot/libraylib.so.??? \
   -lltdl -ldl -lm \
   -DRADIANCE_HOT
printf " Done."
