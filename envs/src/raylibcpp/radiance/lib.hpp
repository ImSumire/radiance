#pragma once

// #define RADIANCE_HOT

#ifdef RADIANCE_HOT
    #include "hot.hpp"
#else
    #include "static.hpp"
#endif
