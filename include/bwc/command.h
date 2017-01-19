#ifndef BWC_COMMAND_H
#define BWC_COMMAND_H

#include <stdint.h>
#include <stdbool.h>

enum bwc_command_type {
	BWC_COMMAND_NONE,
	BWC_COMMAND_SETSCREENPOSITION,
	BWC_COMMAND_PINGMINIMAP,
	BWC_COMMAND_ENABLEFLAG,
	BWC_COMMAND_PRINTF,
	BWC_COMMAND_SENDTEXT,
	BWC_COMMAND_PAUSEGAME,
	BWC_COMMAND_RESUMEGAME,
	BWC_COMMAND_LEAVEGAME,
	BWC_COMMAND_RESTARTGAME,
	BWC_COMMAND_SETLOCALSPEED,
	BWC_COMMAND_SETLATCOM,
	BWC_COMMAND_SETGUI,
	BWC_COMMAND_SETFRAMESKIP,
	BWC_COMMAND_SETMAP,
	BWC_COMMAND_SETALLIES,
	BWC_COMMAND_SETVISION,
	BWC_COMMAND_SETCOMMANDOPTIMIZERLEVEL,
	BWC_COMMAND_SETREVEALALL
};

enum bwc_flag_type {
	BWC_FLAG_COMPLETEMAPINFORMATION,
	BWC_FLAG_USERINPUT,
	BWC_FLAG_MAX
};

struct bwc_command {
    enum bwc_command_type type;
    int32_t value1;
    int32_t value2;
};

void bwc_add_command(struct bwc_client *client, struct bwc_command command);
void bwc_set_screen_position(struct bwc_client *client, int x, int y);
void bwc_set_ping_minimap(struct bwc_client *client, int x, int y);
void bwc_enable_flag(struct bwc_client *client, enum bwc_flag_type flag);
void bwc_printf(struct bwc_client *client, const char *format, ...);
void bwc_sendtext(struct bwc_client *client, bool toallies, const char *message);
void bwc_pause_game(struct bwc_client *client);
void bwc_resume_game(struct bwc_client *client);
void bwc_leave_game(struct bwc_client *client);
void bwc_restart_game(struct bwc_client *client);
void bwc_set_local_speed(struct bwc_client *client, int speed);
void bwc_set_latcom(struct bwc_client *client, bool enable);
void bwc_set_gui(struct bwc_client *client, bool enable);
void bwc_set_frameskip(struct bwc_client *client, int frameskip);
void bwc_set_map(struct bwc_client *client, const char *filename);
void bwc_set_allies(struct bwc_client *client, int player, int wat); // todo
void bwc_set_vision(struct bwc_client *client, int player, int wat); // todo
void bwc_set_command_optimizer_level(struct bwc_client *client, int opt);
void bwc_set_reveal_all(struct bwc_client *client, bool enabled);

#endif
