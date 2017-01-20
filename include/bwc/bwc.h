#ifndef BWC_H
#define BWC_H

#ifndef BWC_BWAPI_VERSION
    #define BWC_BWAPI_VERSION "4_1_2"
    #define BWC_BWAPI_INCLUDE "4_1_2/data.h"
#endif

#ifndef BWCAPI
    #ifdef BWC_EXPORT_DLL
        #define BWCAPI __declspec(dllexport)
    #elif BWC_IMPORT_DLL
        #define BWCAPI __declspec(dllimport)
    #else
        #define BWCAPI
    #endif
#endif

#include BWC_BWAPI_INCLUDE

/* types */
    /* client */
typedef enum bwcConnectionStatus {
    BWC_UNCONNECTED,
    BWC_CONNECTED,
    BWC_LOST_CONNECTION
} bwcConnectionStatus;

typedef struct bwcClient {
    int status;
    void *pipe;
    struct bwcGame *data;
    struct bwcEvent *event;
} bwcClient;

/* functions */
    /* client */
BWCAPI void bwcInit(struct bwcClient *client);
BWCAPI void bwcDestroy(struct bwcClient *client);
BWCAPI int bwcConnect(struct bwcClient *client, unsigned int interval, unsigned int timeout);
BWCAPI int bwcPoll(struct bwcClient *client);
BWCAPI int bwcGetEvent(struct bwcClient *client, struct bwcEvent *event);
BWCAPI int bwcSyn(struct bwcClient *client);
BWCAPI int bwcAck(struct bwcClient *client);
    /* bwc */
BWCAPI int bwcAddString(struct bwcClient *client, const char *message, int *index);
BWCAPI int bwcAddShape(struct bwcClient *client, struct bwcShape shape, int *index);
BWCAPI int bwcAddCommand(struct bwcClient *client, struct bwcCommand command, int *index);
BWCAPI int bwcAddUnitCommand(struct bwcClient *client, struct bwcUnitCommand unitcommand, int *index);
    /* command */
BWCAPI int bwcSetScreenPosition(struct bwcClient *client, int x, int y);
BWCAPI int bwcPingMinimap(struct bwcClient *client, int x, int y);
BWCAPI int bwcEnableFlag(struct bwcClient *client, enum bwcFlagType flag);
BWCAPI int bwcPrintf(struct bwcClient *client, const char *format, ...);
BWCAPI int bwcSendText(struct bwcClient *client, int toallies, const char *format, ...);
BWCAPI int bwcPauseGame(struct bwcClient *client);
BWCAPI int bwcResumeGame(struct bwcClient *client);
BWCAPI int bwcLeaveGame(struct bwcClient *client);
BWCAPI int bwcRestartGame(struct bwcClient *client);
BWCAPI int bwcSetLocalSpeed(struct bwcClient *client, int speed);
BWCAPI int bwcSetLatcom(struct bwcClient *client, int enable);
BWCAPI int bwcSetGui(struct bwcClient *client, int enable);
BWCAPI int bwcSetFrameskip(struct bwcClient *client, int frameskip);
BWCAPI int bwcSetMap(struct bwcClient *client, const char *filename);
BWCAPI int bwcSetAllies(struct bwcClient *client, int player, int todo);
BWCAPI int bwcSetVision(struct bwcClient *client, int player, int todo);
BWCAPI int bwcSetCommandOptimizerLevel(struct bwcClient *client, int opt);
BWCAPI int bwcSetRevealAll(struct bwcClient *client, int enabled);
    /* draw*/
BWCAPI int bwcDrawRectangle(struct bwcClient *client, enum bwcCoordinateType coord, int ax, int ay, int bx, int by, int color, int solid);
BWCAPI int bwcDrawTriangle(struct bwcClient *client, enum bwcCoordinateType coord, int ax, int ay, int bx, int by, int cx, int cy, int color, int solid);
BWCAPI int bwcDrawCircle(struct bwcClient *client, enum bwcCoordinateType coord, int x, int y, int r, int color, int solid);
BWCAPI int bwcDrawEllipse(struct bwcClient *client, enum bwcCoordinateType coord, int x, int y, int xrad, int yrad, int color, int solid);
BWCAPI int bwcDrawPoint(struct bwcClient *client, enum bwcCoordinateType coord, int x, int y, int color, int solid);
BWCAPI int bwcDrawLine(struct bwcClient *client, enum bwcCoordinateType coord, int ax, int ay, int bx, int by, int color, int solid);

#endif
