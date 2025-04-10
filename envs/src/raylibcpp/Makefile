.PHONY: build clean docs hot init run
default: hot

SRC = $(wildcard src/*) $(wildcard radiance/*)

INIT_BANNER  = \033[32m init\033[0m
HOT_BANNER   = \033[33m  hot\033[0m
BUILD_BANNER = \033[34mbuild\033[0m
RUN_BANNER   = \033[36m  run\033[0m



# Initialization
target/pkg/raylib/raylib-*_linux_amd64/README.md:
	@printf "$(INIT_BANNER) Downloading raylib latest..."

	@mkdir -p target/pkg/raylib
	@cd target/pkg/raylib && \
	curl -s https://api.github.com/repos/raysan5/raylib/releases/latest \
	| grep "browser_download_url.*amd" \
	| cut -d : -f 2,3 \
	| tr -d \" \
	| xargs -n 1 curl -L -s \
	| tar -xz

	@printf " Done.\n"

target/hot/libraylib.so.?.?.?: target/pkg/raylib/raylib-*_linux_amd64/README.md
	@printf "$(INIT_BANNER) Copying libraylib.so to targt/hot..."

	@mkdir -p target/hot
	@find target/pkg/raylib/raylib-*_linux_amd64 -name 'libraylib.so.?.?.?' -exec cp {} target/hot \;

	@printf " Done.\n"

init: target/hot/libraylib.so.?.?.?



# Development (Hot-reloading)
target/hot/libhot.so: target/hot/libraylib.so.?.?.?
	@./radiance/scripts/dlib.sh

target/hot/core: target/hot/libraylib.so.?.?.? $(SRC)
	@printf "$(HOT_BANNER) Compiling core..."

	@g++ -Ofast -g \
		-o target/hot/core \
		src/main.cpp \
		target/hot/libraylib.so.?.?.? \
		-lltdl -ldl -lm \
		-DHOT

	@printf " Done.\n"

hot: target/hot/libhot.so target/hot/core
	@printf "$(RUN_BANNER) Running dev (hot-reloading)\n"

	@./radiance/scripts/hot.sh



# Release
target/linux/release: $(SRC)
	@printf "$(BUILD_BANNER) Compiling release..."

	@mkdir -p target/linux
	@g++ -Ofast \
		-o target/linux/release \
		src/main.cpp \
		-Wl,-rpath,target/pkg/raylib/build/raylib \
		-lraylib -lm;

	@printf " Done.\n"

build: target/linux/release

run: target/linux/release
	@printf "$(RUN_BANNER) Running release\n"

	@./target/linux/release



# Utils
clean:
	@rm -rf target

docs:
	@xdg-open https://imsumire.github.io/radiance/docs
