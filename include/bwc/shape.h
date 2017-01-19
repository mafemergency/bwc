#ifndef BWC_SHAPE_H
#define BWC_SHAPE_H

#include <stdint.h>

enum bwc_shape_type {
    BWC_SHAPE_NONE,
    BWC_SHAPE_TEXT,
    BWC_SHAPE_BOX,
    BWC_SHAPE_TRIANGLE,
    BWC_SHAPE_CIRCLE,
    BWC_SHAPE_ELLIPSE,
    BWC_SHAPE_DOT,
    BWC_SHAPE_LINE
};

enum bwc_coordinate_type {
    BWC_COORDINATE_NONE,
    BWC_COORDINATE_SCREEN,
    BWC_COORDINATE_MAP,
    BWC_COORDINATE_MOUSE
};

struct bwc_shape {
    enum bwc_shape_type type;
    enum bwc_coordinate_type ctype;
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
