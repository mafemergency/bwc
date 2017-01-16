#include <windows.h>
#include <tchar.h>
#include <wchar.h>

#include <stdio.h>
#include <stdlib.h>
#include <bwc/bwc.h>


void bwc_client_init(struct bwc_client *client) {
    client->connected = 0;
    client->event = NULL;
    client->pipe = NULL;
    client->table = NULL;
    client->data = NULL;
}


void bwc_client_destroy(struct bwc_client *client) {
    client->connected = 0;
    client->event = NULL;

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


int bwc_client_connect(struct bwc_client *client, int interval, int timeout) {
    int result = BWC_UNSPECIFIED;
    int attempts = (timeout + (interval - 1)) / interval;
    volatile struct bwc_gametable *table = NULL;

    do {
        bwc_client__open_table(client);
        table = bwc_client__choose_slot(client);
        if(table)
            break;
        Sleep(interval);
    } while(attempts-- > 0);

    if(attempts <= 0) {
        result = BWC_TIMEOUT;
        goto error;
    }

    uint32_t pid = table->serverProcessID;

    if(bwc_client__open_pipe(client, pid)) {
        goto error;
    }

    if(bwc_client__open_mem(client, pid)) {
        goto error;
    }

    if(bwc_client__ack(client)) {
        goto error;
    }

    client->connected = 1;
    return 0;

error:
    bwc_client_destroy(client);
    return result;
}


bool bwc_client_poll(struct bwc_client *client) {
    if(bwc_client__syn(client)) {
        client->connected = 0;
        return false;
    }

    if(bwc_client__ack(client)) {
        client->connected = 0;
        return false;
    }

    client->event = client->data->events;

    return true;
}


bool bwc_client_getevent(struct bwc_client *client, struct bwc_event *event) {
    if(client->event < client->data->events + client->data->eventCount) {
        *event = *client->event++;
        return true;
    }

    return false;
}


int bwc_client__open_table(struct bwc_client *client) {
    if(client->table)
        return -1;

    void *mapping = OpenFileMapping(FILE_MAP_READ, FALSE, TEXT("Local\\bwapi_shared_memory_game_list"));
    if(!mapping)
        return -1;

    volatile void *table = MapViewOfFile(mapping, FILE_MAP_READ, 0, 0, 0);
    if(table) {
        client->table = table;
        CloseHandle(mapping);
        return 0;
    }

    CloseHandle(mapping);
    return -2;
}


int bwc_client__open_pipe(struct bwc_client *client, unsigned int process) {
    if(client->pipe)
        return -1;

    TCHAR filename[MAX_PATH];
    _sntprintf_s(filename, MAX_PATH, MAX_PATH, TEXT("\\\\.\\pipe\\bwapi_pipe_%d"), process);
    HANDLE pipe = CreateFile(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if(pipe == INVALID_HANDLE_VALUE)
        return -1;

    COMMTIMEOUTS commtimeout;
    commtimeout.ReadIntervalTimeout = 100;
    commtimeout.ReadTotalTimeoutMultiplier = 100;
    commtimeout.ReadTotalTimeoutConstant = 2000;
    commtimeout.WriteTotalTimeoutMultiplier = 100;
    commtimeout.WriteTotalTimeoutConstant = 2000;
    SetCommTimeouts(pipe, &commtimeout);

    client->pipe = pipe;

    return 0;
}


int bwc_client__open_mem(struct bwc_client *client, unsigned int process) {
    if(client->data)
        return -1;

    TCHAR filename[MAX_PATH];
    _sntprintf_s(filename, MAX_PATH, MAX_PATH, TEXT("Local\\bwapi_shared_memory_%d"), process);

    void *mapping = OpenFileMapping(FILE_MAP_WRITE | FILE_MAP_READ, FALSE, filename);
    if(!mapping)
        return -1;

    volatile void *data = MapViewOfFile(mapping, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, sizeof(struct bwc_gamedata));
    if(data) {
        client->data = data;
        CloseHandle(mapping);
        return 0;
    }

    CloseHandle(mapping);
    return -2;
}


volatile struct bwc_gametable *bwc_client__choose_slot(struct bwc_client *client) {
    if(!client->table)
        return NULL;

    for(int i=0; i<8; i++) {
        if(client->table[i].serverProcessID == 0)
            continue;

        if(client->table[i].lastKeepAliveTime == 0)
            continue;

        if(client->table[i].isConnected == 0)
            return &client->table[i];
    }

    return NULL;
}


int bwc_client__ack(struct bwc_client *client) {
    int ack = 0;
    while(ack != 0x02) {
        unsigned int received;
        if(!ReadFile(client->pipe, &ack, sizeof(ack), &received, NULL)) {
            return -1;
        }
    }

    return 0;
}


int bwc_client__syn(struct bwc_client *client) {
    int syn = 0x01;
    unsigned int sent;
    if(!WriteFile(client->pipe, &syn, sizeof(syn), &sent, NULL)) {
        return -1;
    }

    return 0;
}
