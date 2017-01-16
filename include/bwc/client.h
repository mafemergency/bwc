#ifndef BWC_CLIENT_H
#define BWC_CLIENT_H

#include <stdbool.h>

struct bwc_client {
    int connected;
    volatile struct bwc_event *event;
    void *pipe;
    volatile struct bwc_gametable *table;
    volatile struct bwc_gamedata *data;
};

void bwc_client_init(struct bwc_client *client);
void bwc_client_destroy(struct bwc_client *client);
bool bwc_client_connect(struct bwc_client *client, unsigned int interval, unsigned int timeout);
bool bwc_client_poll(struct bwc_client *client);
bool bwc_client_getevent(struct bwc_client *client, struct bwc_event *event);

int bwc_client__ack(struct bwc_client *client);
int bwc_client__syn(struct bwc_client *client);

#endif
