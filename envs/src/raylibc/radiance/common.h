#pragma once

#ifdef RADIANCE_HOT
    typedef struct State {} State;
#else
    #include "../src/lib.h"
#endif
