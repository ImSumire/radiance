#pragma once

#ifdef RADIANCE_HOT
    typedef struct State {} State;
#else
    #include "../src/lib.h"
#endif

typedef struct Lib {
    const void (*init)(State* state);
    const void (*update)(State* state);
    const void (*render)(State* state);
    const void (*drop)(State* state);
} Lib;
