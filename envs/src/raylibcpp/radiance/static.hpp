#pragma once

#include "../src/lib.hpp"


namespace Lib {
    inline void init(State *state) {
        ::init(state);
    }

    inline void drop(State *state) {
        ::drop(state);
    }

    inline void update(State *state) {
        ::update(state);
    }

    inline void render(State *state) {
        ::render(state);
    }

    inline void hotreload(State *state) {
        ::hotreload(state);
    }
}

