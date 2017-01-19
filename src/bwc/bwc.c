#include <stdio.h>
#include "bwc/bwc.h"

#ifdef BWC_EXPORT_DLL
#include <windows.h>

BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved) {
    return TRUE;
}
#endif

int bwcAddShape(struct bwcClient *client, struct bwcShape shape, int *index) {
    if(client->status != BWC_CONNECTED) {
        return 0;
    }

    if(client->data->shapeCount >= BWC_MAX_SHAPES) {
        return 0;
    }

    if(index != NULL) {
        *index = client->data->shapeCount;
    }

    client->data->shapes[client->data->shapeCount++] = shape;
    return 1;
}

int bwcAddString(struct bwcClient *client, const char *message, int *index) {
    if(client->status != BWC_CONNECTED) {
        return 0;
    }

    if(client->data->stringCount >= BWC_MAX_STRINGS) {
        return 0;
    }

    if(index != NULL) {
        *index = client->data->stringCount;
    }

    snprintf(client->data->strings[client->data->stringCount++], 1024, message);
    return 1;
}

int bwcAddCommand(struct bwcClient *client, struct bwcCommand command, int *index) {
    if(client->status != BWC_CONNECTED) {
        return 0;
    }

    if(client->data->commandCount >= BWC_MAX_COMMANDS) {
        return 0;
    }

    if(index != NULL) {
        *index = client->data->commandCount;
    }

    client->data->commands[client->data->commandCount++] = command;
    return 1;
}

int bwcAddUnitCommand(struct bwcClient *client, struct bwcUnitCommand unitcommand, int *index) {
    if(client->status != BWC_CONNECTED) {
        return 0;
    }

    if(client->data->unitCommandCount >= BWC_MAX_UNIT_COMMANDS) {
        return 0;
    }

    if(index != NULL) {
        *index = client->data->unitCommandCount;
    }

    client->data->unitCommands[client->data->unitCommandCount++] = unitcommand;
    return 1;
}
