#!/bin/sh

INIT_BANNER="\e[32;1minit\e[0m"

mkdir -p target/pkg/raylib
cd target/pkg/raylib

# Include Raylib package (lastest)
# https://gist.github.com/steinwaywhw/a4cd19cda655b8249d908261a62687f8
# thanks @maximizations
printf "$INIT_BANNER Downloading the last Raylib release...\n" &
curl -s https://api.github.com/repos/raysan5/raylib/releases/latest \
    | grep "browser_download_url.*amd" \
    | cut -d : -f 2,3 \
    | tr -d \" \
    | xargs -n 1 curl -L -s \
    | tar -xz &&
printf "$INIT_BANNER Release downloaded\n"

mkdir -p ../../hot

find raylib-*_linux_amd64 -name 'libraylib.so.?????' -exec cp {} ../../hot \;

printf "$INIT_BANNER Initialization done\n"
