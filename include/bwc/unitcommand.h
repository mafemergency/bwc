#ifndef BWC_UNITCOMMAND_H
#define BWC_UNITCOMMAND_H

#include <stdint.h>

struct bwc_unitcommand {
    int32_t type; /* BWAPI::UnitCommandType */
    int32_t unitIndex;
    int32_t targetIndex;
    int32_t x;
    int32_t y;
    int32_t extra;
};

#endif
