#ifndef BWC_COMMAND_H
#define BWC_COMMAND_H

#include <stdint.h>

struct bwc_command {
    int32_t type; /* CommandType::Enum*/
    int32_t value1;
    int32_t value2;
};

#endif
