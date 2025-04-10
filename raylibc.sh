# Verify if the directory is empty
if [ "$(ls -A .)" ]; then
    while true; do
        printf "\033[34minfo\033[0m This directory is not empty, continue ? \033[30m[y/n]\033[0m "
        read -p "" yn
        case $yn in
            [Yy]*) break;;
            [Nn]*) printf "\033[34minfo\033[0m Installation cancelled.\n"; exit;;
        esac
    done
fi

# Download the tar.xz (compressed environment)
curl -s https://imsumire.github.io/radiance/envs/raylibc.tar.xz | tar xJf -

# Initialize it if successfuly downloaded
if [ -f Makefile ]; then
    make init
else
    printf "\033[31merror\033[0m An error occured during environment downloading...\n"
fi
