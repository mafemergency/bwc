#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <stdlib.h>
#include <bwc/bwc.h>


void bwc_client_init(struct bwc_client *client) {
    client->connected = 0;
    client->pipe = NULL;
    client->event = NULL;
    client->table = NULL;
    client->data = NULL;
}

void bwc_client_destroy(struct bwc_client *client) {
    client->connected = 0;

    if(client->pipe && client->pipe != INVALID_HANDLE_VALUE) {
        CloseHandle(client->pipe);
        client->pipe = NULL;
    }

    if(client->table) {
        UnmapViewOfFile(client->table);
        client->table = NULL;
    }

    if(client->data) {
        UnmapViewOfFile(client->data);
        client->data = NULL;
    }
}

bool bwc_client_connect(struct bwc_client *client, unsigned int interval, unsigned int timeout) {
    void *table_mapping = NULL;
    struct bwc_gametable *table = NULL;
    void *pipe = NULL;
    void *data_mapping = NULL;
    void *data = NULL;
    unsigned int start = GetTickCount();

    do {
        table_mapping = OpenFileMapping(FILE_MAP_READ, FALSE, TEXT("Local\\bwapi_shared_memory_game_list"));
        if(table_mapping) break;
        Sleep(interval);
    } while(GetTickCount() - start < timeout);

    table = MapViewOfFile(table_mapping, FILE_MAP_READ, 0, 0, 0);
    if(!table) goto error;

    struct bwc_gametable *table_max = table + 8;
    while(table < table_max) {
        if(table->serverProcessID && table->lastKeepAliveTime && table->isConnected == 0)
            break;
        if(++table >= table_max) goto error;
    }

    TCHAR pipe_filename[MAX_PATH];
    _sntprintf_s(pipe_filename, MAX_PATH, MAX_PATH, TEXT("\\\\.\\pipe\\bwapi_pipe_%u"), table->serverProcessID);

    do {
        pipe = CreateFile(pipe_filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
        if(pipe && pipe != INVALID_HANDLE_VALUE) break;
        if(GetLastError() == ERROR_PIPE_BUSY) goto error;
        Sleep(interval);
    } while(GetTickCount() - start < timeout);

    if(!pipe || pipe == INVALID_HANDLE_VALUE) goto error;

    TCHAR data_filename[MAX_PATH];
    _sntprintf_s(data_filename, MAX_PATH, MAX_PATH, TEXT("Local\\bwapi_shared_memory_%u"), table->serverProcessID);

    data_mapping = OpenFileMapping(FILE_MAP_WRITE | FILE_MAP_READ, FALSE, data_filename);
    if(!data_mapping) goto error;

    data = MapViewOfFile(data_mapping, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, sizeof(struct bwc_game));
    if(!data) goto error;

    int32_t ack = 0x00;
    unsigned int recv;
    if(!ReadFile(pipe, &ack, sizeof(ack), &recv, NULL) || ack != 0x02)
        goto error;

    client->pipe = pipe;
    client->table = table;
    client->data = data;
    client->event = client->data->events;
    client->connected = true;

    CloseHandle(table_mapping);
    CloseHandle(data_mapping);

    return true;

error:
    if(table_mapping) CloseHandle(table_mapping);
    if(table) UnmapViewOfFile(table);
    if(pipe && pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe);
    if(data_mapping) CloseHandle(data_mapping);
    if(data) UnmapViewOfFile(data);
    return false;
}

bool bwc_client_poll(struct bwc_client *client) {
    if(!bwc_client__syn(client)) {
        client->connected = 0;
        return false;
    }

    if(!bwc_client__ack(client)) {
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

bool bwc_client__ack(struct bwc_client *client) {
    int32_t ack = 0;
    while(ack != 0x02) {
        unsigned int received;
        if(!ReadFile(client->pipe, &ack, sizeof(ack), &received, NULL)) {
            return false;
        }
    }

    return true;
}

bool bwc_client__syn(struct bwc_client *client) {
    int32_t syn = 0x01;
    unsigned int sent;
    if(!WriteFile(client->pipe, &syn, sizeof(syn), &sent, NULL)) {
        return false;
    }

    return true;
}
