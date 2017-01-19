#ifndef BWC_GAMEDATA_H
#define BWC_GAMEDATA_H

#include <stdint.h>

struct bwc_gamedata {
    int32_t revision;
    int8_t isDebug;

    int32_t instanceID;
    int32_t botAPM_noselects;
    int32_t botAPM_selects;

    int32_t forceCount;
    struct bwc_forcedata forces[5];

    int32_t playerCount;
    struct bwc_playerdata players[12];

    int32_t initialUnitCount;
    struct bwc_unitdata units[10000];

    int32_t unitArray[1700];

    struct bwc_bulletdata bullets[100];

    int32_t nukeDotCount;
    struct bwc_position nukeDots[200];

    int32_t gameType;
    int32_t latency;
    int32_t latencyFrames;
    int32_t latencyTime;
    int32_t remainingLatencyFrames;
    int32_t remainingLatencyTime;
    int8_t hasLatCom;
    int8_t hasGUI;
    int32_t replayFrameCount;
    int32_t frameCount;
    int32_t elapsedTime;
    int32_t countdownTimer;
    int32_t fps;
    double averageFPS;

    int32_t mouseX;
    int32_t mouseY;
    int8_t mouseState[BWC_M_MAX];
    int8_t keyState[BWC_K_MAX];
    int32_t screenX;
    int32_t screenY;

    int8_t flags[BWC_FLAG_MAX];

    int32_t mapWidth;
    int32_t mapHeight;
    char mapFileName[261];
    char mapPathName[261];
    char mapName[33];
    char mapHash[41];

    int32_t getGroundHeight[256][256];
    int8_t isWalkable[1024][1024];
    int8_t isBuildable[256][256];
    int8_t isVisible[256][256];
    int8_t isExplored[256][256];
    int8_t hasCreep[256][256];
    int8_t isOccupied[256][256];

    uint16_t mapTileRegionId[256][256];
    uint16_t mapSplitTilesMiniTileMask[5000];
    uint16_t mapSplitTilesRegion1[5000];
    uint16_t mapSplitTilesRegion2[5000];

    int32_t regionCount;
    struct bwc_regiondata regions[5000];

    int32_t startLocationCount;
    struct bwc_position startLocations[8];

    int8_t isInGame;
    int8_t isMultiplayer;
    int8_t isBattleNet;
    int8_t isPaused;
    int8_t isReplay;

    int32_t selectedUnitCount;
    int32_t selectedUnits[12];

    int32_t self;
    int32_t enemy;
    int32_t neutral;

    int32_t eventCount;
    struct bwc_event events[BWC_MAX_EVENTS];

    int32_t eventStringCount;
    char eventStrings[BWC_MAX_EVENT_STRINGS][256];

    int32_t stringCount;
    char strings[BWC_MAX_STRINGS][1024];

    int32_t shapeCount;
    struct bwc_shape shapes[BWC_MAX_SHAPES];

    int32_t commandCount;
    struct bwc_command commands[BWC_MAX_COMMANDS];

    int32_t unitCommandCount;
    struct bwc_unitcommand unitCommands[BWC_MAX_UNIT_COMMANDS];

    int32_t unitSearchSize;
    struct bwc_unitfinder xUnitSearch[1700*2];
    struct bwc_unitfinder yUnitSearch[1700*2];
};

#endif
