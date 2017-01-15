#ifndef BWC_BULLETDATA_H
#define BWC_BULLETDATA_H

#include <stdint.h>

struct bwc_bulletdata {
    int32_t id;
    int32_t player;
    int32_t type;
    int32_t source;
    int32_t positionX;
    int32_t positionY;
    double angle;
    double velocityX;
    double velocityY;
    int32_t target;
    int32_t targetPositionX;
    int32_t targetPositionY;
    int32_t removeTimer;
    int8_t exists;
    int8_t isVisible[9];
};

#endif
