#pragma once

#ifdef RADIANCE_HOT
    typedef struct State {} State;
#else
    #include "../src/lib.hpp"
#endif
