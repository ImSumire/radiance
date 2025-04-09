#include "../src/lib.hpp"


extern "C" {
    void dlib_init(State* state) {
        init(state);
    }

    void dlib_drop(State* state) {
        drop(state);
    }

    void dlib_update(State* state) {
        update(state);
    }

    void dlib_render(State* state) {
        render(state);
    }

    void dlib_hotreload(State* state) {
        hotreload(state);
    }
}
