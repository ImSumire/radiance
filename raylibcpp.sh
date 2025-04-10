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
curl -s https://imsumire.github.io/radiance/envs/raylibcpp.tar.xz | tar xJf -

# Initialize it if successfuly downloaded
if [ -f scripts/init.sh ]; then
    scripts/init.sh
else
    printf "\033[31merror\033[0m An error occured during environment downloading...\n"
    exit
fi

if [ -f target/hot/libraylib.so.????? ]; then
    printf "\033[32msuccess\033[0m Installation done.\n"
else
    printf "\033[32merror\033[0m An error occured during environment initialization...\n"
fi
