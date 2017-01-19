#include <stdio.h>
#include <bwc/bwc.h>

int main(int argc, char **argv) {
    bwcClient client;
    bwcInit(&client);

    printf("Establishing connection...\n");

    unsigned int interval = 100;
    unsigned int timeout = 30000;
    if(!bwcConnect(&client, interval, timeout)) {
        printf("Failed to establish connection.\n");
        return -1;
    }

    printf("Connection established.\n");

    while(bwcPoll(&client)) {
        bwcEvent event;
        while(bwcGetEvent(&client, &event)) {
            if(event.type == BWC_EVENT_MATCHSTART) {
                bwcPrintf(&client, "<bwc> match started");
            }
        }
    }

    printf("Connection lost.\n");
    bwcDestroy(&client);
    return 0;
}
