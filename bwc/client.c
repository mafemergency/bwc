#include <windows.h>
#include <stdio.h>
#include <stdint.h>

#include "data.h"


void bwc_error(const char *message, ...) {
    char formatted[1024];
    va_list args;
    va_start(args, message);
    snprintf(formatted, 1024, message, va_arg(args, char *));
    va_end(args);
    printf("bwc error: %s\n", formatted);
}


struct bwc_client {
    int connected;
    void *pipe;
    volatile struct bwc_gametable *table;
    volatile struct bwc_gamedata *data;
    int event_offset;
};


void bwc_client_init(struct bwc_client *client) {
    client->connected = 0;
    client->pipe = NULL;
    client->table = NULL;
    client->data = NULL;
    client->event_offset = 0;
}


void bwc_client_destroy(struct bwc_client *client) {
    client->connected = 0;

    if(client->pipe && client->pipe != INVALID_HANDLE_VALUE) {
        CloseHandle(client->pipe);
        client->pipe = NULL;
    }

    if(client->table) {
        UnmapViewOfFile((struct bwc_gametable *) client->table);
        client->table = NULL;
    }

    if(client->data) {
        UnmapViewOfFile((struct bwc_gamedata *) client->data);
        client->data = NULL;
    }
}


int bwc_client__open_table(struct bwc_client *client) {
    void *mapping = OpenFileMapping(FILE_MAP_WRITE | FILE_MAP_READ, FALSE,
        "Local\\bwapi_shared_memory_game_list");
    if(!mapping) {
        bwc_error("failed to open game table file.");
        return -1;
    }

    client->table = MapViewOfFile(mapping,FILE_MAP_WRITE | FILE_MAP_READ,
        0, 0, 0);
    if(!client->table) {
        bwc_error("failed to map game table.");
        return -1;
    }

    CloseHandle(mapping);
    return 0;
}


int bwc_client__open_pipe(struct bwc_client *client, unsigned int process) {
    char filename[MAX_PATH];
    snprintf(filename, MAX_PATH, "\\\\.\\pipe\\bwapi_pipe_%d", process);

    client->pipe = CreateFile(filename, GENERIC_READ | GENERIC_WRITE, 0,
        NULL, OPEN_EXISTING, 0, NULL);
    if(client->pipe == INVALID_HANDLE_VALUE) {
        bwc_error("failed to open communication pipe.");
        return -1;
    }

    COMMTIMEOUTS commtimeout;
    commtimeout.ReadIntervalTimeout = 100;
    commtimeout.ReadTotalTimeoutMultiplier = 100;
    commtimeout.ReadTotalTimeoutConstant = 2000;
    commtimeout.WriteTotalTimeoutMultiplier = 100;
    commtimeout.WriteTotalTimeoutConstant = 2000;
    SetCommTimeouts(client->pipe, &commtimeout);

    return 0;
}


int bwc_client__open_mem(struct bwc_client *client, unsigned int process) {
    char filename[MAX_PATH];
    snprintf(filename, MAX_PATH, "Local\\bwapi_shared_memory_%d", process);

    void *mapping = OpenFileMapping(FILE_MAP_WRITE | FILE_MAP_READ, FALSE,
        filename);
    if(!mapping) {
        bwc_error("failed to open game data mapping.");
        return -1;
    }

    client->data = MapViewOfFile(mapping, FILE_MAP_WRITE | FILE_MAP_READ, 0,
        0, sizeof(struct bwc_gamedata));
    if(!client->data) {
        bwc_error("failed to map game data.");
        return -1;
    }

    CloseHandle(mapping);

    return 0;
}


int bwc_client_pushstr(struct bwc_client *client, char *string, int length) {
    if(client->data->stringCount >= MAX_COMMANDS) {
        bwc_error("string queue is full.");
        return -1;
    }

    volatile char *dest = client->data->strings[client->data->stringCount];
    for(int i=0; i<length; i++) {
        dest[i] = string[i];
    }
    return client->data->stringCount++;
}


int bwc_client_pushcmd(struct bwc_client *client, struct bwc_command command) {
    if(client->data->commandCount >= MAX_COMMANDS) {
        bwc_error("command queue is full.");
        return -1;
    }

    client->data->commands[client->data->commandCount] = command;
    return client->data->commandCount++;
}


int bwc_client_connectrace(struct bwc_client *client, int attempts) {
    while(attempts--) {
        if(!bwc_client_connect(client)) {
            return 0;
        }

        bwc_client_destroy(client);
        Sleep(100);
    }

    return -1;
}


int bwc_client__ack(struct bwc_client *client) {
    int ack = 0;
    while(ack != 0x02) {
        unsigned int received;
        if(!ReadFile(client->pipe, &ack, sizeof(ack), &received, NULL)) {
            bwc_error("failed to read pipe.");
            return -1;
        }
    }

    return 0;
}


int bwc_client__syn(struct bwc_client *client) {
    int syn = 0x01;
    unsigned int sent;
    if(!WriteFile(client->pipe, &syn, sizeof(syn), &sent, NULL)) {
        bwc_error("failed to write pipe.");
        return -1;
    }

    return 0;
}


int bwc_client_connect(struct bwc_client *client) {
    if(client->connected) {
        bwc_error("client is already connected to a server.");
        return -1;
    }

    if(bwc_client__open_table(client)) {
        return -1;
    }

    struct bwc_gametable table = client->table[0];
    printf("Table: %d; %d; %d;\n",
        table.serverProcessID,
        table.isConnected,
        table.lastKeepAliveTime);

    if(bwc_client__open_pipe(client, client->table[0].serverProcessID)) {
        return -1;
    }

    if(bwc_client__open_mem(client, client->table[0].serverProcessID)) {
        return -1;
    }

    if(bwc_client__ack(client)) {
        return -1;
    }

    client->connected = 1;

    return 0;
}


int bwc_client_poll(struct bwc_client *client) {
    if(bwc_client__syn(client)) {
        bwc_error("syn failed.");
        client->connected = 0;
        return -1;
    }

    if(bwc_client__ack(client)) {
        bwc_error("ack failed.");
        client->connected = 0;
        return -1;
    }

    client->event_offset = 0;

    return 0;
}


int bwc_client_get_event(struct bwc_client *client, struct bwc_event *event) {
    if(client->event_offset >= client->data->eventCount) {
        return 0;
    }

    *event = client->data->events[client->event_offset];
    client->event_offset += 1;

    return 1;
}


static const char *bwc_event_type_str[] = {
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


int main(int argc, char **argv) {
    struct bwc_client client;

    bwc_client_init(&client);
    bwc_client_connectrace(&client, 1000);

    struct bwc_event event;
    while(client.connected) {
        bwc_client_poll(&client);

        while(bwc_client_get_event(&client, &event)) {
            printf("<%s v1=%d v2=%d>\n",
                bwc_event_type_str[event.type], event.v1, event.v2);
        }
    }

    bwc_client_destroy(&client);

    return 0;
}
