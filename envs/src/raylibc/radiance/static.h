#pragma once

#include "common.h"


inline void lib_init(State *state) {
    init(state);
}

inline void lib_update(State *state) {
    update(state);
}

inline void lib_render(State *state) {
    render(state);
}

inline void lib_drop(State *state) {
    drop(state);
}
