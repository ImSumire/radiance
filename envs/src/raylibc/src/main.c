#include "../radiance/lib.h"


State state = {};  // Global game state shared across all game logic

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "");
    SetTargetFPS(60);
    lib_init(&state);  // Runs `init` from lib.h
    
    while (!WindowShouldClose()) {
        lib_update(&state);  // Runs `update` from lib.h
        lib_render(&state);  // Runs `render` from lib.h
    }

    lib_drop(&state);  // Runs `drop` from lib.h
    CloseWindow();

    return 0;
}
