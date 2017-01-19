#include <stdio.h>
#include <bwc/bwc.h>

void drawOutlines(bwcClient *client) {
    bwcUnit *unit;
    bwcUnit *maxunit = client->data->units + 10000;

    for(unit=client->data->units; unit<maxunit; unit++) {
        if(!unit->exists || unit->type == BWC_UNIT_NONE) {
            continue;
        }

        bwcDrawCircle(client, BWC_COORDINATE_MAP, unit->positionX, unit->positionY, 8, 117, 0);
    }
}

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
                bwcEnableFlag(&client, BWC_FLAG_USERINPUT);
            } else if(event.type == BWC_EVENT_MATCHFRAME) {
                drawOutlines(&client);
            }
        }
    }

    printf("Connection lost.\n");
    bwcDestroy(&client);
    return 0;
}
