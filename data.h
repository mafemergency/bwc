#ifndef BWC_DATA_H
#define BWC_DATA_H

#define MAX_EVENTS 10000
#define MAX_EVENT_STRINGS 1000
#define MAX_STRINGS 20000
#define MAX_SHAPES 20000
#define MAX_COMMANDS 20000
#define MAX_UNIT_COMMANDS 20000

#define UNITTYPES_MAX 234
#define UPGRADETYPES_MAX 63
#define TECHTYPES_MAX 47
#define M_MAX 3
#define K_MAX 255
#define FLAG_MAX 2


struct bwc_gametable {
	unsigned int serverProcessID;
	int8_t isConnected;
	unsigned int lastKeepAliveTime;
};

struct bwc_forcedata {
	char name[32];
};

struct bwc_playerdata {
	char name[25];
	int race;
	int type;
	int force;
	int8_t isAlly[12];
	int8_t isEnemy[12];
	int8_t isNeutral;
	int startLocationX;
	int startLocationY;
	int8_t isVictorious;
	int8_t isDefeated;
	int8_t leftGame;
	int8_t isParticipating;

	int minerals;
	int gas;
	int gatheredMinerals;
	int gatheredGas;
	int repairedMinerals;
	int repairedGas;
	int refundedMinerals;
	int refundedGas;
	int supplyTotal[3];
	int supplyUsed[3];

	int allUnitCount[UNITTYPES_MAX];
	int visibleUnitCount[UNITTYPES_MAX];
	int completedUnitCount[UNITTYPES_MAX];
	int deadUnitCount[UNITTYPES_MAX];
	int killedUnitCount[UNITTYPES_MAX];

	int upgradeLevel[UPGRADETYPES_MAX];
	int8_t hasResearched[TECHTYPES_MAX];
	int8_t isResearching[TECHTYPES_MAX];
	int8_t isUpgrading[UPGRADETYPES_MAX];

	int color;

	int totalUnitScore;
	int totalKillScore;
	int totalBuildingScore;
	int totalRazingScore;
	int customScore;

	int maxUpgradeLevel[UPGRADETYPES_MAX];
	int8_t isResearchAvailable[TECHTYPES_MAX];
	int8_t isUnitAvailable[UNITTYPES_MAX];
};

struct bwc_unitdata {
	int clearanceLevel;
	int id;
	int player;
	int type;
	int positionX;
	int positionY;
	double angle;
	double velocityX;
	double velocityY;
	int hitPoints;
	int lastHitPoints;
	int shields;
	int energy;
	int resources;
	int resourceGroup;

	int killCount;
	int acidSporeCount;
	int scarabCount;
	int spiderMineCount;
	int groundWeaponCooldown;
	int airWeaponCooldown;
	int spellCooldown;
	int defenseMatrixPoints;

	int defenseMatrixTimer;
	int ensnareTimer;
	int irradiateTimer;
	int lockdownTimer;
	int maelstromTimer;
	int orderTimer;
	int plagueTimer;
	int removeTimer;
	int stasisTimer;
	int stimTimer;

	int buildType;
	int trainingQueueCount;
	int trainingQueue[5];
	int tech;
	int upgrade;
	int remainingBuildTime;
	int remainingTrainTime;
	int remainingResearchTime;
	int remainingUpgradeTime;
	int buildUnit;

	int target;
	int targetPositionX;
	int targetPositionY;
	int order;
	int orderTarget;
	int orderTargetPositionX;
	int orderTargetPositionY;
	int secondaryOrder;
	int rallyPositionX;
	int rallyPositionY;
	int rallyUnit;
	int addon;
	int nydusExit;
	int powerUp;

	int transport;
	int carrier;
	int hatchery;

	int8_t exists;
	int8_t hasNuke;
	int8_t isAccelerating;
	int8_t isAttacking;
	int8_t isAttackFrame;
	int8_t isBeingGathered;
	int8_t isBlind;
	int8_t isBraking;
	int8_t isBurrowed;
	int carryResourceType;
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
	int buttonset;

	int lastAttackerPlayer;
	int8_t recentlyAttacked;
	int replayID;
};

struct bwc_bulletdata {
	int id;
	int player;
	int type;
	int source;
	int positionX;
	int positionY;
	double angle;
	double velocityX;
	double velocityY;
	int target;
	int targetPositionX;
	int targetPositionY;
	int removeTimer;
	int8_t exists;
	int8_t isVisible[9];
};

struct bwc_position {
	int x;
	int y;
};

struct bwc_regiondata {
	int id;
	int islandID;
	int center_x;
	int center_y;
	int priority;

	int leftMost;
	int rightMost;
	int topMost;
	int bottomMost;

	int neighborCount;
	int neighbors[256];

	int8_t isAccessible;
	int8_t isHigherGround;
};

struct bwc_event {
	int32_t type; /* BWAPI::EventType::Enum */
	int v1;
	int v2;
};

struct bwc_shape {
	int32_t type; /* ShapeType::Enum */
	int32_t ctype; /* BWAPI::CoordinateType::Enum */
	int x1;
	int y1;
	int x2;
	int y2;
	int extra1;
	int extra2;
	int color;
	int8_t isSolid;
};

struct bwc_command {
	int32_t type; /* CommandType::Enum*/
	int value1;
	int value2;
};

struct bwc_unitcommand {
	int32_t type; /* BWAPI::UnitCommandType */
	int unitIndex;
	int targetIndex;
	int x;
	int y;
	int extra;
};

struct bwc_unitfinder {
	int unitIndex;
	int searchValue;
};

struct bwc_gamedata {
	int revision;
	int8_t isDebug;

	int instanceID;
	int botAPM_noselects;
	int botAPM_selects;

	int forceCount;
	struct bwc_forcedata forces[5];

	int playerCount;
	struct bwc_playerdata players[12];

	int initialUnitCount;
	struct bwc_unitdata units[10000];

	int unitArray[1700];

	struct bwc_bulletdata bullets[100];

	int nukeDotCount;
	struct bwc_position nukeDots[200];

	int gameType;
	int latency;
	int latencyFrames;
	int latencyTime;
	int remainingLatencyFrames;
	int remainingLatencyTime;
	int8_t hasLatCom;
	int8_t hasGUI;
	int replayFrameCount;
	int frameCount;
	int elapsedTime;
	int countdownTimer;
	int fps;
	double averageFPS;

	int mouseX;
	int mouseY;
	int8_t mouseState[M_MAX];
	int8_t keyState[K_MAX];
	int screenX;
	int screenY;

	int8_t flags[FLAG_MAX];

	int mapWidth;
	int mapHeight;
	char mapFileName[261];
	char mapPathName[261];
	char mapName[33];
	char mapHash[41];

	int getGroundHeight[256][256];
	int8_t isWalkable[1024][1024];
	int8_t isBuildable[256][256];
	int8_t isVisible[256][256];
	int8_t isExplored[256][256];
	int8_t hasCreep[256][256];
	int8_t isOccupied[256][256];

	unsigned short mapTileRegionId[256][256];
	unsigned short mapSplitTilesMiniTileMask[5000];
	unsigned short mapSplitTilesRegion1[5000];
	unsigned short mapSplitTilesRegion2[5000];

	int regionCount;
	struct bwc_regiondata regions[5000];

	int startLocationCount;
	struct bwc_position startLocations[8];

	int8_t isInGame;
	int8_t isMultiplayer;
	int8_t isBattleNet;
	int8_t isPaused;
	int8_t isReplay;

	int selectedUnitCount;
	int selectedUnits[12];

	int self;
	int enemy;
	int neutral;

	int eventCount;
	struct bwc_event events[MAX_EVENTS];

	int eventStringCount;
	char eventStrings[MAX_EVENT_STRINGS][256];

	int stringCount;
	char strings[MAX_STRINGS][1024];

	int shapeCount;
	struct bwc_shape shapes[MAX_SHAPES];

	int commandCount;
	struct bwc_command commands[MAX_COMMANDS];

	int unitCommandCount;
	struct bwc_unitcommand unitCommands[MAX_UNIT_COMMANDS];

	int unitSearchSize;
	struct bwc_unitfinder xUnitSearch[1700*2];
	struct bwc_unitfinder yUnitSearch[1700*2];
};

#endif
