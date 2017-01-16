#include <windows.h>
#include <stdio.h>
#include <stdbool.h>

#include <bwc/bwc.h>
#include <bwc/typedefs.h>


int main(int argc, char **argv) {
    bwc_client client;
    bwc_client_init(&client);

    printf("Establishing connection... ");

    unsigned int interval = 100; /* attempt to connect in 100ms intervals */
    unsigned int timeout = 30000; /* give up after 30,000 ms */
    bwc_client_connect(&client, interval, timeout);

    if(!client.connected) {
        printf("failed!\n");
        return -1;
    }

    printf("connected!\n");

    while(bwc_client_poll(&client)) {
        struct bwc_event event;
        while(bwc_client_getevent(&client, &event)) {
            switch(event.type) {
            case BWC_EVT_MATCHSTART:
                bwc_event_print(event);
                break;

            case BWC_EVT_MATCHEND:
                bwc_event_print(event);
                break;

            case BWC_EVT_MATCHFRAME:
                bwc_event_print(event);
                break;

            default:
                printf("??? ");
                bwc_event_print(event);
            }
        }
    }

    printf("Connection lost.\n");
    bwc_client_destroy(&client);

    return 0;
}
