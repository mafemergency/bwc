#include <windows.h>
#include <tchar.h>
#include <bwc/bwc.h>

void bwcInit(struct bwcClient *client) {
    client->status = BWC_UNCONNECTED;
    client->pipe = NULL;
    client->data = NULL;
    client->event = NULL;
}

void bwcDestroy(struct bwcClient *client) {
    client->status = BWC_UNCONNECTED;
    client->event = NULL;

    if(client->pipe && client->pipe != INVALID_HANDLE_VALUE) {
        CloseHandle(client->pipe);
        client->pipe = NULL;
    }

    if(client->data) {
        UnmapViewOfFile(client->data);
        client->data = NULL;
    }
}

int bwcConnect(struct bwcClient *client, unsigned int interval, unsigned int timeout) {
    void *table_mapping = NULL;
    struct bwcGameTable *table = NULL;
    void *pipe = NULL;
    void *data_mapping = NULL;
    struct bwcGame *data = NULL;
    unsigned int start = GetTickCount();

    do {
        table_mapping = OpenFileMapping(FILE_MAP_READ, FALSE, TEXT("Local\\bwapi_shared_memory_game_list"));
        if(table_mapping) break;
        Sleep(interval);
    } while(GetTickCount() - start < timeout);

    table = MapViewOfFile(table_mapping, FILE_MAP_READ, 0, 0, 0);
    if(!table) goto error;

    struct bwcGameTable *table_max = table + 8;
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

    data = MapViewOfFile(data_mapping, FILE_MAP_WRITE | FILE_MAP_READ, 0, 0, sizeof(struct bwcGame));
    if(!data) goto error;

    int32_t ack = 0x00;
    unsigned int recv;
    if(!ReadFile(pipe, &ack, sizeof(ack), &recv, NULL) || ack != 0x02)
        goto error;

    client->pipe = pipe;
    client->data = data;
    client->event = client->data->events;
    client->status = BWC_CONNECTED;

    CloseHandle(table_mapping);
    UnmapViewOfFile(table);
    CloseHandle(data_mapping);

    return 1;

error:
    if(table_mapping) CloseHandle(table_mapping);
    if(table) UnmapViewOfFile(table);
    if(pipe && pipe != INVALID_HANDLE_VALUE) CloseHandle(pipe);
    if(data_mapping) CloseHandle(data_mapping);
    if(data) UnmapViewOfFile(data);
    return 0;
}

int bwcPoll(struct bwcClient *client) {
    if(!bwcSyn(client)) {
        client->status = BWC_LOST_CONNECTION;
        return 0;
    }

    if(!bwcAck(client)) {
        client->status = BWC_LOST_CONNECTION;
        return 0;
    }

    client->event = client->data->events;

    return 1;
}

int bwcGetEvent(struct bwcClient *client, struct bwcEvent *event) {
    if(client->event < client->data->events + client->data->eventCount) {
        *event = *client->event++;
        return 1;
    }

    return 0;
}

int bwcSyn(struct bwcClient *client) {
    int32_t syn = 0x01;
    unsigned int sent;
    if(!WriteFile(client->pipe, &syn, sizeof(syn), &sent, NULL)) {
        return 0;
    }

    return 1;
}

int bwcAck(struct bwcClient *client) {
    int32_t ack = 0;
    while(ack != 0x02) {
        unsigned int received;
        if(!ReadFile(client->pipe, &ack, sizeof(ack), &received, NULL)) {
            return 0;
        }
    }

    return 1;
}
