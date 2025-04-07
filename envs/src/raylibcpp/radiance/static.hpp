#pragma once

#include "common.hpp"


namespace Lib {
    inline void init(State *state) {
        ::init(state);
    }

    inline void update(State *state) {
        ::update(state);
    }

    inline void render(State *state) {
        ::render(state);
    }

    inline void drop(State *state) {
        ::drop(state);
    }
}

