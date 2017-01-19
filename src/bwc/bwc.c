#include <stdio.h>
#include <bwc/bwc.h>

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
