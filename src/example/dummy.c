#include <windows.h>
#include <stdio.h>
#include <stdbool.h>
#include <bwc/bwc.h>


int main(int argc, char **argv) {
    struct bwc_client client;
    bwc_client_init(&client);

    printf("Establishing connection...\n");

    unsigned int interval = 100;
    unsigned int timeout = 30000;
    if(!bwc_client_connect(&client, interval, timeout)) {
        printf("Failed to establish connection.\n");
        bwc_client_destroy(&client);
        return -1;
    }

    printf("Connection established.\n");

    while(bwc_client_poll(&client)) {
        struct bwc_event event;
        while(bwc_client_getevent(&client, &event)) {
            if(event.type == BWC_EVT_MATCHSTART) {
                bwc_enable_flag(&client, BWC_FLAG_COMPLETEMAPINFORMATION);
                bwc_enable_flag(&client, BWC_FLAG_USERINPUT);
            }
        }
    }

    printf("Connection lost.\n");
    bwc_client_destroy(&client);
    return 0;
}
