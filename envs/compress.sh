#!/bin/bash

cd envs

for item in src/*; do
    if [ -d "$item" ]; then  # Check if the item is a directory
        dir=$(basename "$item")
        
        cd $item
        tar -cJf "../../$dir.tar.xz" . # "$item"
        printf "\x1b[32mcompressed\x1b[0m envs/src/$dir/**/* \x1b[30m(envs/$dir.tar.xz)\x1b[0m\n"
        cd ../..
    fi
done
