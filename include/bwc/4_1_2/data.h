#ifndef BWC_DATA_H
#define BWC_DATA_H

#include <stdint.h>

#ifndef BWC_DATA_ONLY
    #include "enum.h"
#else
    #define BWC_UNIT_MAX 234
    #define BWC_UPGRADE_MAX 63
    #define BWC_TECH_MAX 47
    #define BWC_MOUSE_MAX 3
    #define BWC_KEY_MAX 255
    #define BWC_FLAG_MAX 2
#endif

#define BWC_MAX_EVENTS 10000
#define BWC_MAX_EVENT_STRINGS 1000
#define BWC_MAX_STRINGS 20000
#define BWC_MAX_SHAPES 20000
#define BWC_MAX_COMMANDS 20000
#define BWC_MAX_UNIT_COMMANDS 20000

typedef struct bwcBullet {
    int32_t id;
    int32_t player;
    int32_t type;
    int32_t source;
    int32_t positionX;
    int32_t positionY;
    double angle;
    double velocityX;
    double velocityY;
    int32_t target;
    int32_t targetPositionX;
    int32_t targetPositionY;
    int32_t removeTimer;
    int8_t exists;
    int8_t isVisible[9];
} bwcBullet;

typedef struct bwcCommand {
    int32_t type;
    int32_t value1;
    int32_t value2;
} bwcCommand;

typedef struct bwcEvent {
    int32_t type;
    int32_t v1;
    int32_t v2;
} bwcEvent;

typedef struct bwcForce {
    char name[32];
} bwcForce;

typedef struct bwcGameTable {
    uint32_t serverProcessID;
    int8_t isConnected;
    uint32_t lastKeepAliveTime;
} bwcGameTable;

typedef struct bwcPlayer {
    char name[25];
    int32_t race;
    int32_t type;
    int32_t force;
    int8_t isAlly[12];
    int8_t isEnemy[12];
    int8_t isNeutral;
    int32_t startLocationX;
    int32_t startLocationY;
    int8_t isVictorious;
    int8_t isDefeated;
    int8_t leftGame;
    int8_t isParticipating;

    int32_t minerals;
    int32_t gas;
    int32_t gatheredMinerals;
    int32_t gatheredGas;
    int32_t repairedMinerals;
    int32_t repairedGas;
    int32_t refundedMinerals;
    int32_t refundedGas;
    int32_t supplyTotal[3];
    int32_t supplyUsed[3];

    int32_t allUnitCount[BWC_UNIT_MAX];
    int32_t visibleUnitCount[BWC_UNIT_MAX];
    int32_t completedUnitCount[BWC_UNIT_MAX];
    int32_t deadUnitCount[BWC_UNIT_MAX];
    int32_t killedUnitCount[BWC_UNIT_MAX];

    int32_t upgradeLevel[BWC_UPGRADE_MAX];
    int8_t hasResearched[BWC_TECH_MAX];
    int8_t isResearching[BWC_TECH_MAX];
    int8_t isUpgrading[BWC_UPGRADE_MAX];

    int32_t color;

    int32_t totalUnitScore;
    int32_t totalKillScore;
    int32_t totalBuildingScore;
    int32_t totalRazingScore;
    int32_t customScore;

    int32_t maxUpgradeLevel[BWC_UPGRADE_MAX];
    int8_t isResearchAvailable[BWC_TECH_MAX];
    int8_t isUnitAvailable[BWC_UNIT_MAX];
} bwcPlayer;

typedef struct bwcPosition {
    int32_t x;
    int32_t y;
} bwcPosition;

typedef struct bwcRegion {
    int32_t id;
    int32_t islandID;
    int32_t center_x;
    int32_t center_y;
    int32_t priority;

    int32_t leftMost;
    int32_t rightMost;
    int32_t topMost;
    int32_t bottomMost;

    int32_t neighborCount;
    int32_t neighbors[256];

    int8_t isAccessible;
    int8_t isHigherGround;
} bwcRegion;

typedef struct bwcShape {
    int32_t type;
    int32_t ctype;
    int32_t x1;
    int32_t y1;
    int32_t x2;
    int32_t y2;
    int32_t extra1;
    int32_t extra2;
    int32_t color;
    int8_t isSolid;
} bwcShape;

typedef struct bwcUnit {
    int32_t clearanceLevel;
    int32_t id;
    int32_t player;
    int32_t type;
    int32_t positionX;
    int32_t positionY;
    double angle;
    double velocityX;
    double velocityY;
    int32_t hitPoints;
    int32_t lastHitPoints;
    int32_t shields;
    int32_t energy;
    int32_t resources;
    int32_t resourceGroup;

    int32_t killCount;
    int32_t acidSporeCount;
    int32_t scarabCount;
    int32_t spiderMineCount;
    int32_t groundWeaponCooldown;
    int32_t airWeaponCooldown;
    int32_t spellCooldown;
    int32_t defenseMatrixPoints;

    int32_t defenseMatrixTimer;
    int32_t ensnareTimer;
    int32_t irradiateTimer;
    int32_t lockdownTimer;
    int32_t maelstromTimer;
    int32_t orderTimer;
    int32_t plagueTimer;
    int32_t removeTimer;
    int32_t stasisTimer;
    int32_t stimTimer;

    int32_t buildType;
    int32_t trainingQueueCount;
    int32_t trainingQueue[5];
    int32_t tech;
    int32_t upgrade;
    int32_t remainingBuildTime;
    int32_t remainingTrainTime;
    int32_t remainingResearchTime;
    int32_t remainingUpgradeTime;
    int32_t buildUnit;

    int32_t target;
    int32_t targetPositionX;
    int32_t targetPositionY;
    int32_t order;
    int32_t orderTarget;
    int32_t orderTargetPositionX;
    int32_t orderTargetPositionY;
    int32_t secondaryOrder;
    int32_t rallyPositionX;
    int32_t rallyPositionY;
    int32_t rallyUnit;
    int32_t addon;
    int32_t nydusExit;
    int32_t powerUp;

    int32_t transport;
    int32_t carrier;
    int32_t hatchery;

    int8_t exists;
    int8_t hasNuke;
    int8_t isAccelerating;
    int8_t isAttacking;
    int8_t isAttackFrame;
    int8_t isBeingGathered;
    int8_t isBlind;
    int8_t isBraking;
    int8_t isBurrowed;
    int32_t carryResourceType;
    int8_t isCloaked;
    int8_t isCompleted;
    int8_t isConstructing;
    int8_t isDetected;
    int8_t isGathering;
    int8_t isHallucination;
    int8_t isIdle;
    int8_t isInterruptible;
    int8_t isInvincible;
    int8_t isLifted;
    int8_t isMorphing;
    int8_t isMoving;
    int8_t isParasited;
    int8_t isSelected;
    int8_t isStartingAttack;
    int8_t isStuck;
    int8_t isTraining;
    int8_t isUnderStorm;
    int8_t isUnderDarkSwarm;
    int8_t isUnderDWeb;
    int8_t isPowered;
    int8_t isVisible[9];
    int32_t buttonset;

    int32_t lastAttackerPlayer;
    int8_t recentlyAttacked;
    int32_t replayID;
} bwcUnit;

typedef struct bwcUnitCommand {
    int32_t type;
    int32_t unitIndex;
    int32_t targetIndex;
    int32_t x;
    int32_t y;
    int32_t extra;
} bwcUnitCommand;

typedef struct bwcUnitFinder {
    int32_t unitIndex;
    int32_t searchValue;
} bwcUnitFinder;

typedef struct bwcGame {
    int32_t revision;
    int8_t isDebug;

    int32_t instanceID;
    int32_t botAPM_noselects;
    int32_t botAPM_selects;

    int32_t forceCount;
    struct bwcForce forces[5];

    int32_t playerCount;
    struct bwcPlayer players[12];

    int32_t initialUnitCount;
    struct bwcUnit units[10000];

    int32_t unitArray[1700];

    struct bwcBullet bullets[100];

    int32_t nukeDotCount;
    struct bwcPosition nukeDots[200];

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
    int8_t mouseState[BWC_MOUSE_MAX];
    int8_t keyState[BWC_KEY_MAX];
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
    struct bwcRegion regions[5000];

    int32_t startLocationCount;
    struct bwcPosition startLocations[8];

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
    struct bwcEvent events[BWC_MAX_EVENTS];

    int32_t eventStringCount;
    char eventStrings[BWC_MAX_EVENT_STRINGS][256];

    int32_t stringCount;
    char strings[BWC_MAX_STRINGS][1024];

    int32_t shapeCount;
    struct bwcShape shapes[BWC_MAX_SHAPES];

    int32_t commandCount;
    struct bwcCommand commands[BWC_MAX_COMMANDS];

    int32_t unitCommandCount;
    struct bwcUnitCommand unitCommands[BWC_MAX_UNIT_COMMANDS];

    int32_t unitSearchSize;
    struct bwcUnitFinder xUnitSearch[1700*2];
    struct bwcUnitFinder yUnitSearch[1700*2];
} bwcGame;

#endif
