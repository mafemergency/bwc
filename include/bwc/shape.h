#ifndef BWC_SHAPE_H
#define BWC_SHAPE_H

#include <stdint.h>

struct bwc_shape {
    int32_t type; /* ShapeType::Enum */
    int32_t ctype; /* BWAPI::CoordinateType::Enum */
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
    int32_t extra1;
    int32_t extra2;
    int32_t color;
    int8_t isSolid;
};

#endif
