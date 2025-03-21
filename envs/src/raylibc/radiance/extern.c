#include "../src/lib.h"


// There's no link with hot.h
inline extern void __init(State* state) {
    init(state);
}
inline extern void __update(State* state) {
    update(state);
}
inline extern void __render(State* state) {
    render(state);
}
inline extern void __drop(State* state) {
    drop(state);
}

