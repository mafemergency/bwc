#include <stdio.h>

#include <bwc/bwc.h>
#include <bwc/typedefs.h>


int main(int argc, char **argv) {
    bwc_client client;
    bwc_client_init(&client);

    printf("Establishing connection... ");

    int interval = 100; /* attempt to connect in 100ms intervals */
    int timeout = 20000; /* give up after 20,000 ms */
    bwc_client_connect(&client, interval, timeout);

    if(!client.connected) {
        printf("Failed!\n");
        return -1;
    }

    printf("Connected!\n");

    while(bwc_client_poll(&client)) {
        struct bwc_event event;
        while(bwc_client_getevent(&client, &event)) {
            switch(event.type) {
                case BWC_EVT_MATCHSTART:
                    printf("Match started!\n");
                    break;

                case BWC_EVT_MATCHEND:
                    printf("Match ended!\n");
                    break;
            }
        }
    }

    bwc_client_destroy(&client);

    return 0;
}
