#ifndef BWC_PLAYERDATA_H
#define BWC_PLAYERDATA_H

#include <stdint.h>

struct bwc_playerdata {
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

    int32_t allUnitCount[UNITTYPES_MAX];
    int32_t visibleUnitCount[UNITTYPES_MAX];
    int32_t completedUnitCount[UNITTYPES_MAX];
    int32_t deadUnitCount[UNITTYPES_MAX];
    int32_t killedUnitCount[UNITTYPES_MAX];

    int32_t upgradeLevel[UPGRADETYPES_MAX];
    int8_t hasResearched[TECHTYPES_MAX];
    int8_t isResearching[TECHTYPES_MAX];
    int8_t isUpgrading[UPGRADETYPES_MAX];

    int32_t color;

    int32_t totalUnitScore;
    int32_t totalKillScore;
    int32_t totalBuildingScore;
    int32_t totalRazingScore;
    int32_t customScore;

    int32_t maxUpgradeLevel[UPGRADETYPES_MAX];
    int8_t isResearchAvailable[TECHTYPES_MAX];
    int8_t isUnitAvailable[UNITTYPES_MAX];
};

#endif
