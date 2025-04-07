#!/bin/sh

RUN_BANNER="\e[32;1mrun\e[0m"

scripts/build.sh

printf "$RUN_BANNER Running built target...\n"
target/linux/release
