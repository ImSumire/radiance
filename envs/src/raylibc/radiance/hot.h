#pragma once

#include <stdio.h>
#include <sys/stat.h>

#include <dlfcn.h>
#include <fcntl.h>
#include <raylib.h>
#include <unistd.h>

typedef struct State {} State;


#define HOT_BANNER "\x1b[33;1mhot\x1b[0m "


long lastmodtime = 0;
void* dlib = NULL;
const char* dlib_path = "target/hot/libhot.so";

void (*dlib_init)(State*) = NULL;
void (*dlib_drop)(State*) = NULL;
void (*dlib_update)(State*) = NULL;
void (*dlib_render)(State*) = NULL;
void (*dlib_hotreload)(State*) = NULL;


void reload(State* state) {
    // Check exists
    int fd = open(dlib_path, O_RDONLY);
    if (fd < 0) {
        printf(HOT_BANNER "Library not found: %s\n", dlib_path);
        return;
    }

    // Check readable
    // The AI Llama helped me here
    unsigned char magic[4];
    if (read(fd, magic, 4) != 4) {
        printf(HOT_BANNER "Unable to read: %s\n", dlib_path);
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
        printf(HOT_BANNER "Invalid ELF file: %s\n", dlib_path);
        close(fd);
        return;
    }

    close(fd);

    // At this state, the dlib is valid

    printf(HOT_BANNER "𐬽 Reloading library...\n");

    // Unmap the current library
    if (dlib) {
        dlclose(dlib);
    }

    // Load the new library
    void* tmp_lib = dlopen(dlib_path, RTLD_NOW);
    if (!tmp_lib) {
        printf(HOT_BANNER "Couln't load library: %s\n", dlerror());
        return;
    }
    dlib = tmp_lib;

    // Try to load the new init function
    void (*tmp_init)(State*) = (void (*)(State*))dlsym(dlib, "init");
    if (!tmp_init) {
        printf(HOT_BANNER "Couln't load `init`: %s\n", dlerror());
    }
    else {
        dlib_init = tmp_init;
    }

    // Try to load the new drop function
    void (*tmp_drop)(State*) = (void (*)(State*))dlsym(dlib, "drop");
    if (!tmp_drop) {
        printf(HOT_BANNER "Couln't load `drop`: %s\n", dlerror());
    }
    else {
        dlib_drop = tmp_drop;
    }

    // Try to load the new update function
    void (*tmp_update)(State*) = (void (*)(State*))dlsym(dlib, "update");
    if (!tmp_update) {
        printf(HOT_BANNER "Couln't load `update`: %s\n", dlerror());
    }
    else {
        dlib_update = tmp_update;
    }

    // Try to load the new render function
    void (*tmp_render)(State*) = (void (*)(State*))dlsym(dlib, "render");
    if (!tmp_render) {
        printf(HOT_BANNER "Couln't load `render`: %s\n", dlerror());
    }
    else {
        dlib_render = tmp_render;
    }

    // Try to load the new hotreload function
    void (*tmp_hotreload)(State*) = (void (*)(State*))dlsym(dlib, "hotreload");
    if (!tmp_hotreload) {
        printf(HOT_BANNER "Couln't load `hotreload`: %s\n", dlerror());
    }
    else {
        dlib_hotreload = tmp_hotreload;
    }

    dlib_hotreload(state);

    printf(HOT_BANNER "Reloaded!\n");

    lastmodtime = GetFileModTime(dlib_path);
}

void __init(State* state) {
    if (dlib_init) {
        dlib_init(state);
    }
}

void __drop(State* state) {
    if (dlib_drop) {
        dlib_drop(state);
    }

    if (dlib) {
        dlclose(dlib);
    }
}

void __update(State* state) {
    if (GetFileModTime(dlib_path) > lastmodtime) {
        reload(state);
    }

    if (dlib_update) {
        dlib_update(state);
    }
}

void __render(State* state) {
    if (dlib_render) {
        dlib_render(state);
    }
    else {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Invalid render function", 20, 20, 24, WHITE);
        EndDrawing();
    }
}

void __hotreload(State* state) {
    if (dlib_hotreload) {
        dlib_hotreload(state);
    }
}


inline void lib_init(State *state) {
    __init(state);
}

inline void lib_drop(State *state) {
    __drop(state);
}

inline void lib_update(State *state) {
    __update(state);
}

inline void lib_render(State *state) {
    __render(state);
}

inline void lib_hotreload(State *state) {
    __hotreload(state);
}
