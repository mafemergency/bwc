#include <windows.h>
#include <stdio.h>
#include <stdint.h>

#include "data.h"


void bwc_error(const char *message) {
	printf("bwc error: %s\n", message);
}


struct bwc_client {
	int connected;
	void *pipe;
	volatile struct bwc_gametable *table;
	volatile struct bwc_gamedata *data;
};


void bwc_client_init(struct bwc_client *client) {
	client->connected = 0;
	client->pipe = NULL;
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
		UnmapViewOfFile((struct bwc_gametable *) client->table);
		client->table = NULL;
	}

	if(client->data) {
		UnmapViewOfFile((struct bwc_gamedata *) client->data);
		client->data = NULL;
	}
}


int bwc_client__open_table(struct bwc_client *client) {
	if(client->connected) {
		bwc_error("cannot read table again; client is already connected.");
		return -1;
	}

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
	if(client->connected) {
		bwc_error("cannot open pipe again; client is already connected.");
		return -1;
	}

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
	if(client->connected) {
		bwc_error("cannot open pipe again; client is already connected.");
		return -1;
	}

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

	volatile struct bwc_gamedata *data = client->data;

	printf("revision: %d\n", data->revision);
	printf("isDebug: %d\n", data->isDebug);
	printf("instanceID: %d\n", data->instanceID);
	printf("botAPM_noselects: %d\n", data->botAPM_noselects);
	printf("botAPM_selects: %d\n", data->botAPM_selects);
	printf("forceCount: %d\n", data->forceCount);
	for(int i=0; i<data->forceCount; i++) {
		printf("  forces[%d].name: %.*s", i, 32, data->forces[i].name);
	}
	printf("playerCount: %d\n", data->playerCount);
	for(int i=0; i<data->playerCount; i++) {
		printf("  players[%d].name: %.*s", i, 25, data->players[i].name);
	}

	printf("hasGUI: %d\n", data->hasGUI);
	printf("hasLatCom: %d\n", data->hasLatCom);
	printf("%zu\n", sizeof(struct bwc_gamedata));

	/* wait for the server to ack us? */
	int code = 1;
	while(code != 2) {
	  DWORD receivedByteCount;
		BOOL success = ReadFile(client->pipe, &code, sizeof(code),
			&receivedByteCount, NULL);
		if(!success) {
			bwc_error("failed to read pipe.");
			return -1;
		}
	}

	char *message = "this is a test";
	int str_index = bwc_client_pushstr(client, message, strlen(message) + 1);

	struct bwc_command command;
	command.type = 5; /* printf */
	command.value1 = str_index;
	command.value2 = 0;
	bwc_client_pushcmd(client, command);

	return 0;
}


int main(int argc, char **argv) {
	struct bwc_client client;

	if(sizeof(struct bwc_gamedata) != 33017040) {
		bwc_error("bwc_gamedata is incorrect size.");
		return -1;
	}

	bwc_client_init(&client);
	bwc_client_connect(&client);
	bwc_client_destroy(&client);

	return 0;
}
