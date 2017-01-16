#ifndef BWC_EVENT_H
#define BWC_EVENT_H

#include <stdint.h>

enum bwc_event_type {
    BWC_EVT_MATCHSTART,
    BWC_EVT_MATCHEND,
    BWC_EVT_MATCHFRAME,
    BWC_EVT_MENUFRAME,
    BWC_EVT_SENDTEXT,
    BWC_EVT_RECEIVETEXT,
    BWC_EVT_PLAYERLEFT,
    BWC_EVT_NUKEDETECT,
    BWC_EVT_UNITDISCOVER,
    BWC_EVT_UNITEVADE,
    BWC_EVT_UNITSHOW,
    BWC_EVT_UNITHIDE,
    BWC_EVT_UNITCREATE,
    BWC_EVT_UNITDESTROY,
    BWC_EVT_UNITMORPH,
    BWC_EVT_UNITRENEGADE,
    BWC_EVT_SAVEGAME,
    BWC_EVT_UNITCOMPLETE,
    BWC_EVT_NONE
};


static const char *bwc_event_str[] = {
    "BWC_EVT_MATCHSTART",
    "BWC_EVT_MATCHEND",
    "BWC_EVT_MATCHFRAME",
    "BWC_EVT_MENUFRAME",
    "BWC_EVT_SENDTEXT",
    "BWC_EVT_RECEIVETEXT",
    "BWC_EVT_PLAYERLEFT",
    "BWC_EVT_NUKEDETECT",
    "BWC_EVT_UNITDISCOVER",
    "BWC_EVT_UNITEVADE",
    "BWC_EVT_UNITSHOW",
    "BWC_EVT_UNITHIDE",
    "BWC_EVT_UNITCREATE",
    "BWC_EVT_UNITDESTROY",
    "BWC_EVT_UNITMORPH",
    "BWC_EVT_UNITRENEGADE",
    "BWC_EVT_SAVEGAME",
    "BWC_EVT_UNITCOMPLETE",
    "BWC_EVT_NONE"
};


struct bwc_event {
    enum bwc_event_type type;
    int32_t v1;
    int32_t v2;
};


inline void bwc_event_print(struct bwc_event event) {
    printf("<%s %d %d>\n", bwc_event_str[event.type], event.v1, event.v2);
}

#endif