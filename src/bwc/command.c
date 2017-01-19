#include <stdio.h>
#include <stdarg.h>

#include <bwc/bwc.h>


void bwc_add_command(struct bwc_client *client, struct bwc_command command) {
	if(client->data->commandCount >= BWC_MAX_COMMANDS) {
		return;
	}

	client->data->commands[client->data->commandCount++] = command;
}

void bwc_set_screen_position(struct bwc_client *client, int x, int y) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETSCREENPOSITION;
	command.value1 = x;
	command.value2 = y;
	bwc_add_command(client, command);
}

void bwc_set_ping_minimap(struct bwc_client *client, int x, int y) {
	struct bwc_command command;
	command.type = BWC_COMMAND_PINGMINIMAP;
	command.value1 = x;
	command.value2 = y;
	bwc_add_command(client, command);
}

void bwc_enable_flag(struct bwc_client *client, enum bwc_flag_type flag) {
	struct bwc_command command;
	command.type = BWC_COMMAND_ENABLEFLAG;
	command.value1 = flag;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_printf(struct bwc_client *client, const char *format, ...) {
	va_list args;
	va_start(args, format);
	vsnprintf(client->data->strings[client->data->stringCount], 1024, format, args);
	va_end(args);

	struct bwc_command command;
	command.type = BWC_COMMAND_PRINTF;
	command.value1 = client->data->stringCount++;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_sendtext(struct bwc_client *client, bool toallies, const char *message) {
	snprintf(client->data->strings[client->data->stringCount], 1024, "%s", message);

	struct bwc_command command;
	command.type = BWC_COMMAND_SENDTEXT;
	command.value1 = toallies;
	command.value2 = client->data->stringCount++;
	bwc_add_command(client, command);
}

void bwc_pause_game(struct bwc_client *client) {
	struct bwc_command command;
	command.type = BWC_COMMAND_PAUSEGAME;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_resume_game(struct bwc_client *client) {
	struct bwc_command command;
	command.type = BWC_COMMAND_RESUMEGAME;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_leave_game(struct bwc_client *client) {
	struct bwc_command command;
	command.type = BWC_COMMAND_LEAVEGAME;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_restart_game(struct bwc_client *client) {
	struct bwc_command command;
	command.type = BWC_COMMAND_RESTARTGAME;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_local_speed(struct bwc_client *client, int speed) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETLOCALSPEED;
	command.value1 = speed;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_latcom(struct bwc_client *client, bool enable) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETLATCOM;
	command.value1 = enable;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_gui(struct bwc_client *client, bool enable) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETGUI;
	command.value1 = enable;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_frameskip(struct bwc_client *client, int frameskip) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETFRAMESKIP;
	command.value1 = frameskip;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_map(struct bwc_client *client, const char *filename) {
	snprintf(client->data->strings[client->data->stringCount], 1024, "%s", filename);

	struct bwc_command command;
	command.type = BWC_COMMAND_SETMAP;
	command.value1 = client->data->stringCount++;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_allies(struct bwc_client *client, int player, int wat) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETALLIES;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_vision(struct bwc_client *client, int player, int wat) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETVISION;
	command.value1 = 0;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_command_optimizer_level(struct bwc_client *client, int opt) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETCOMMANDOPTIMIZERLEVEL;
	command.value1 = opt;
	command.value2 = 0;
	bwc_add_command(client, command);
}

void bwc_set_reveal_all(struct bwc_client *client, bool enabled) {
	struct bwc_command command;
	command.type = BWC_COMMAND_SETREVEALALL;
	command.value1 = enabled;
	command.value2 = 0;
	bwc_add_command(client, command);
}
