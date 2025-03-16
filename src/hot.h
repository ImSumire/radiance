#pragma once

#include <stdio.h>
#include <sys/stat.h>

#include <dlfcn.h>
#include <fcntl.h>
#include <raylib.h>
#include <unistd.h>

#include "common.h"


#define HOT_BANNER "\x1b[33;1mhot\x1b[0m "


long lastmodtime = 0;
void* lib = NULL;
const char* libpath = "target/hot/libhot.so";

void (*libinit)(State*) = NULL;
void (*libdrop)(State*) = NULL;
void (*libupdate)(State*) = NULL;
void (*librender)(State*) = NULL;


void reload() {
    // Check exists
    int fd = open(libpath, O_RDONLY);
    if (fd < 0) {
        printf(HOT_BANNER "Library not found: %s\n", libpath);
        return;
    }

    // Check readable
    // The AI Llama helped me here
    unsigned char magic[4];
    if (read(fd, magic, 4) != 4) {
        printf(HOT_BANNER "Unable to read: %s\n", libpath);
        close(fd);
        return;
    }

    // Check .ELF format
    // The AI Llama helped me here
    if (
        magic[0] != 0x7f ||
        magic[1] != 0x45 ||
        magic[2] != 0x4c ||
        magic[3] != 0x46
    ) {
        printf(HOT_BANNER "Invalid ELF file: %s\n", libpath);
        close(fd);
        return;
    }

    close(fd);

    // At this state, the lib is valid

    printf(HOT_BANNER "𐬽 Reloading library...\n");

    // Unmap the current library
    if (lib) {
        dlclose(lib);
    }

    // Load the new library
    void* tmp_lib = dlopen(libpath, RTLD_NOW);
    if (!tmp_lib) {
        printf(HOT_BANNER "Couln't load library: %s\n", dlerror());
        return;
    }
    lib = tmp_lib;

    // Try to load the new init function
    void (*tmp_init)(State*) = (void (*)(State*))dlsym(lib, "init");
    if (!tmp_init) {
        printf(HOT_BANNER "Couln't load `init`: %s\n", dlerror());
    }
    else {
        libinit = tmp_init;
    }

    // Try to load the new drop function
    void (*tmp_drop)(State*) = (void (*)(State*))dlsym(lib, "drop");
    if (!tmp_drop) {
        printf(HOT_BANNER "Couln't load `drop`: %s\n", dlerror());
    }
    else {
        libdrop = tmp_drop;
    }

    // Try to load the new update function
    void (*tmp_update)(State*) = (void (*)(State*))dlsym(lib, "update");
    if (!tmp_update) {
        printf(HOT_BANNER "Couln't load `update`: %s\n", dlerror());
    }
    else {
        libupdate = tmp_update;
    }

    // Try to load the new render function
    void (*tmp_render)(State*) = (void (*)(State*))dlsym(lib, "render");
    if (!tmp_render) {
        printf(HOT_BANNER "Couln't load `render`: %s\n", dlerror());
    }
    else {
        librender = tmp_render;
    }

    printf(HOT_BANNER "Reloaded!\n");

    lastmodtime = GetFileModTime(libpath);
}

void __init(State* state) {
    if (libinit) {
        libinit(state);
    }
}

void __update(State* state) {
    if (GetFileModTime(libpath) > lastmodtime) {
        reload();
    }

    if (libupdate) {
        libupdate(state);
    }
}

void __render(State* state) {
    if (librender) {
        librender(state);
    }
    else {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Invalid render function", 20, 20, 24, WHITE);
        EndDrawing();
    }
}

void __drop(State* state) {
    if (libdrop) {
        libdrop(state);
    }

    if (lib) {
        dlclose(lib);
    }
}


static Lib Main = {
    .init = __init,
    .update = __update,
    .render = __render,
    .drop = __drop
};
