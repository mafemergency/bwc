#include <stdio.h>
#include <stdarg.h>
#include "bwc/bwc.h"

int bwcSetScreenPosition(struct bwcClient *client, int x, int y) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETSCREENPOSITION;
    command.value1 = x;
    command.value2 = y;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetPingMinimap(struct bwcClient *client, int x, int y) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_PINGMINIMAP;
    command.value1 = x;
    command.value2 = y;
    return bwcAddCommand(client, command, NULL);
}

int bwcEnableFlag(struct bwcClient *client, enum bwcFlagType flag) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_ENABLEFLAG;
    command.value1 = flag;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcPrintf(struct bwcClient *client, const char *format, ...) {
    char message[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(message, 1024, format, args);
    va_end(args);
    int index;
    if(!bwcAddString(client, message, &index)) {
        return 0;
    }

    struct bwcCommand command;
    command.type = BWC_COMMAND_PRINTF;
    command.value1 = index;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSendText(struct bwcClient *client, int toallies, const char *format, ...) {
    char message[1024];
    va_list args;
    va_start(args, format);
    vsnprintf(message, 1024, format, args);
    va_end(args);
    int index;
    if(!bwcAddString(client, message, &index)) {
        return 0;
    }

    struct bwcCommand command;
    command.type = BWC_COMMAND_SENDTEXT;
    command.value1 = toallies;
    command.value2 = index;
    return bwcAddCommand(client, command, NULL);
}

int bwcPauseGame(struct bwcClient *client) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_PAUSEGAME;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcResumeGame(struct bwcClient *client) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_RESUMEGAME;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcLeaveGame(struct bwcClient *client) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_LEAVEGAME;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcRestartGame(struct bwcClient *client) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_RESTARTGAME;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetLocalSpeed(struct bwcClient *client, int speed) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETLOCALSPEED;
    command.value1 = speed;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetLatcom(struct bwcClient *client, int enable) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETLATCOM;
    command.value1 = enable;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetGui(struct bwcClient *client, int enable) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETGUI;
    command.value1 = enable;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetFrameskip(struct bwcClient *client, int frameskip) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETFRAMESKIP;
    command.value1 = frameskip;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetMap(struct bwcClient *client, const char *filename) {
    snprintf(client->data->strings[client->data->stringCount], 1024, "%s", filename);

    struct bwcCommand command;
    command.type = BWC_COMMAND_SETMAP;
    command.value1 = client->data->stringCount++;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetAllies(struct bwcClient *client, int player, int wat) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETALLIES;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetVision(struct bwcClient *client, int player, int wat) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETVISION;
    command.value1 = 0;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetCommandOptimizerLevel(struct bwcClient *client, int opt) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETCOMMANDOPTIMIZERLEVEL;
    command.value1 = opt;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}

int bwcSetRevealAll(struct bwcClient *client, int enabled) {
    struct bwcCommand command;
    command.type = BWC_COMMAND_SETREVEALALL;
    command.value1 = enabled;
    command.value2 = 0;
    return bwcAddCommand(client, command, NULL);
}
