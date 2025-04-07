#include "../radiance/lib.hpp"


State state = {};  // Global game state shared across all game logic

int main() {
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    InitWindow(1280, 720, "");
    SetTargetFPS(60);
    Lib::init(&state);  // Runs `init` from lib.hpp
    
    while (!WindowShouldClose()) {
        Lib::update(&state);  // Runs `update` from lib.hpp
        Lib::render(&state);  // Runs `render` from lib.hpp
    }

    Lib::drop(&state);  // Runs `drop` from lib.hpp
    CloseWindow();

    return 0;
}
