#ifndef BWC_REGION_H
#define BWC_REGION_H

#include <stdint.h>

struct bwc_region {
    int32_t id;
    int32_t islandID;
    int32_t center_x;
    int32_t center_y;
    int32_t priority;

    int32_t leftMost;
    int32_t rightMost;
    int32_t topMost;
    int32_t bottomMost;

    int32_t neighborCount;
    int32_t neighbors[256];

    int8_t isAccessible;
    int8_t isHigherGround;
};

#endif
