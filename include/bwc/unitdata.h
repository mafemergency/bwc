#ifndef BWC_UNITDATA_H
#define BWC_UNITDATA_H

#include <stdint.h>

struct bwc_unitdata {
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
};

#endif
