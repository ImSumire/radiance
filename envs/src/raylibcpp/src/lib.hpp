#pragma once

#include <raylib.h>

#include "common/state.hpp"


// Called once at startup to initilize the state
void init(State* state) {}

// Cleanup function, called once at shutdown to free the memory
void drop(State* state) {}

// Update the state each frame
void update(State* state) {}

// Responsible for drawing the state each frame
void render(State* state) {
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("Welcome!", 40, 40, 32, WHITE);
    EndDrawing();
}

void hotreload(State* state) {}
