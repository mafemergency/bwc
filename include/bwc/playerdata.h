#ifndef BWC_PLAYERDATA_H
#define BWC_PLAYERDATA_H

#include <stdint.h>

enum bwc_playerdata_type {
    BWC_PLAYER_NONE,
    BWC_PLAYER_COMPUTER,
    BWC_PLAYER_PLAYER,
    BWC_PLAYER_RESCUEPASSIVE,
    BWC_PLAYER_RESCUEACTIVE,
    BWC_PLAYER_EITHERPREFERCOMPUTER,
    BWC_PLAYER_EITHERPREFERHUMAN,
    BWC_PLAYER_NEUTRAL,
    BWC_PLAYER_CLOSED,
    BWC_PLAYER_OBSERVER,
    BWC_PLAYER_PLAYERLEFT,
    BWC_PLAYER_COMPUTERLEFT,
    BWC_PLAYER_UNKNOWN,
    BWC_PLAYER_MAX
};

struct bwc_playerdata {
    char name[25];
    int32_t race;
    enum bwc_playerdata_type type;
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

    int32_t upgradeLevel[BWC_UPGRADETYPES_MAX];
    int8_t hasResearched[BWC_TECHTYPES_MAX];
    int8_t isResearching[BWC_TECHTYPES_MAX];
    int8_t isUpgrading[BWC_UPGRADETYPES_MAX];

    int32_t color;

    int32_t totalUnitScore;
    int32_t totalKillScore;
    int32_t totalBuildingScore;
    int32_t totalRazingScore;
    int32_t customScore;

    int32_t maxUpgradeLevel[BWC_UPGRADETYPES_MAX];
    int8_t isResearchAvailable[BWC_TECHTYPES_MAX];
    int8_t isUnitAvailable[BWC_UNIT_MAX];
};

#endif
