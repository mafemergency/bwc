#ifndef BWC_H
#define BWC_H

#ifndef BWC_BWAPI_VERSION
    #define BWC_BWAPI_VERSION "4_1_2"
    #define BWC_BWAPI_INCLUDE "4_1_2/data.h"
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
void bwcInit(struct bwcClient *client);
void bwcDestroy(struct bwcClient *client);
int bwcConnect(struct bwcClient *client, unsigned int interval, unsigned int timeout);
int bwcPoll(struct bwcClient *client);
int bwcGetEvent(struct bwcClient *client, struct bwcEvent *event);
int bwcSyn(struct bwcClient *client);
int bwcAck(struct bwcClient *client);
    /* bwc */
int bwcAddCommand(struct bwcClient *client, struct bwcCommand command, int *index);
int bwcAddString(struct bwcClient *client, const char *message, int *index);
    /* command */
int bwcSetScreenPosition(struct bwcClient *client, int x, int y);
int bwcSetPingMinimap(struct bwcClient *client, int x, int y);
int bwcEnableFlag(struct bwcClient *client, enum bwcFlagType flag);
int bwcPrintf(struct bwcClient *client, const char *format, ...);
int bwcSendText(struct bwcClient *client, int toallies, const char *format, ...);
int bwcPauseGame(struct bwcClient *client);
int bwcResumeGame(struct bwcClient *client);
int bwcLeaveGame(struct bwcClient *client);
int bwcRestartGame(struct bwcClient *client);
int bwcSetLocalSpeed(struct bwcClient *client, int speed);
int bwcSetLatcom(struct bwcClient *client, int enable);
int bwcSetGui(struct bwcClient *client, int enable);
int bwcSetFrameskip(struct bwcClient *client, int frameskip);
int bwcSetMap(struct bwcClient *client, const char *filename);
int bwcSetAllies(struct bwcClient *client, int player, int todo);
int bwcSetVision(struct bwcClient *client, int player, int todo);
int bwcSetCommandOptimizerLevel(struct bwcClient *client, int opt);
int bwcSetRevealAll(struct bwcClient *client, int enabled);

#endif
