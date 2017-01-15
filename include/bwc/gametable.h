#ifndef BWC_GAMETABLE_H
#define BWC_GAMETABLE_H

#include <stdint.h>

struct bwc_gametable {
    uint32_t serverProcessID;
    int8_t isConnected;
    uint32_t lastKeepAliveTime;
};

#endif
