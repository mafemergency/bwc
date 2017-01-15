#include <BWAPI.h>

#include <BWAPI/Client/GameData.h>
#include <BWAPI/Client/ForceData.h>
#include <BWAPI/Client/PlayerData.h>
#include <BWAPI/Client/UnitData.h>
#include <BWAPI/Client/BulletData.h>
#include <BWAPI/Client/RegionData.h>
#include <BWAPI/Client/Shape.h>
/* Manually replace BWAPIC::UnitCommand "type" member
   to int in BWAPI/Client/UnitCommand.h */
#include <BWAPI/Client/UnitCommand.h>

#include <stddef.h>
#include <stdio.h>


int check_forcedata() {
	struct BWAPI::ForceData fd;
	printf("ForceData=%zu\n", sizeof(fd));
	printf("  name=%zu; %zu\n", offsetof(BWAPI::ForceData, name), sizeof(fd.name));

	return 0;
}


int check_playerdata() {
	struct BWAPI::PlayerData pd;
	printf("PlayerData=%zu\n", sizeof(pd));
	printf("  name=%zu; %zu\n", offsetof(BWAPI::PlayerData, name), sizeof(pd.name));
	printf("  race=%zu; %zu\n", offsetof(BWAPI::PlayerData, race), sizeof(pd.race));
	printf("  type=%zu; %zu\n", offsetof(BWAPI::PlayerData, type), sizeof(pd.type));
	printf("  force=%zu; %zu\n", offsetof(BWAPI::PlayerData, force), sizeof(pd.force));
	printf("  isAlly=%zu; %zu\n", offsetof(BWAPI::PlayerData, isAlly), sizeof(pd.isAlly));
	printf("  isEnemy=%zu; %zu\n", offsetof(BWAPI::PlayerData, isEnemy), sizeof(pd.isEnemy));
	printf("  isNeutral=%zu; %zu\n", offsetof(BWAPI::PlayerData, isNeutral), sizeof(pd.isNeutral));
	printf("  startLocationX=%zu; %zu\n", offsetof(BWAPI::PlayerData, startLocationX), sizeof(pd.startLocationX));
	printf("  startLocationY=%zu; %zu\n", offsetof(BWAPI::PlayerData, startLocationY), sizeof(pd.startLocationY));
	printf("  isVictorious=%zu; %zu\n", offsetof(BWAPI::PlayerData, isVictorious), sizeof(pd.isVictorious));
	printf("  isDefeated=%zu; %zu\n", offsetof(BWAPI::PlayerData, isDefeated), sizeof(pd.isDefeated));
	printf("  leftGame=%zu; %zu\n", offsetof(BWAPI::PlayerData, leftGame), sizeof(pd.leftGame));
	printf("  isParticipating=%zu; %zu\n", offsetof(BWAPI::PlayerData, isParticipating), sizeof(pd.isParticipating));
	printf("  minerals=%zu; %zu\n", offsetof(BWAPI::PlayerData, minerals), sizeof(pd.minerals));
	printf("  gas=%zu; %zu\n", offsetof(BWAPI::PlayerData, gas), sizeof(pd.gas));
	printf("  gatheredMinerals=%zu; %zu\n", offsetof(BWAPI::PlayerData, gatheredMinerals), sizeof(pd.gatheredMinerals));
	printf("  gatheredGas=%zu; %zu\n", offsetof(BWAPI::PlayerData, gatheredGas), sizeof(pd.gatheredGas));
	printf("  repairedMinerals=%zu; %zu\n", offsetof(BWAPI::PlayerData, repairedMinerals), sizeof(pd.repairedMinerals));
	printf("  repairedGas=%zu; %zu\n", offsetof(BWAPI::PlayerData, repairedGas), sizeof(pd.repairedGas));
	printf("  refundedMinerals=%zu; %zu\n", offsetof(BWAPI::PlayerData, refundedMinerals), sizeof(pd.refundedMinerals));
	printf("  refundedGas=%zu; %zu\n", offsetof(BWAPI::PlayerData, refundedGas), sizeof(pd.refundedGas));
	printf("  supplyTotal=%zu; %zu\n", offsetof(BWAPI::PlayerData, supplyTotal), sizeof(pd.supplyTotal));
	printf("  supplyUsed=%zu; %zu\n", offsetof(BWAPI::PlayerData, supplyUsed), sizeof(pd.supplyUsed));
	printf("  allUnitCount=%zu; %zu\n", offsetof(BWAPI::PlayerData, allUnitCount), sizeof(pd.allUnitCount));
	printf("  visibleUnitCount=%zu; %zu\n", offsetof(BWAPI::PlayerData, visibleUnitCount), sizeof(pd.visibleUnitCount));
	printf("  completedUnitCount=%zu; %zu\n", offsetof(BWAPI::PlayerData, completedUnitCount), sizeof(pd.completedUnitCount));
	printf("  deadUnitCount=%zu; %zu\n", offsetof(BWAPI::PlayerData, deadUnitCount), sizeof(pd.deadUnitCount));
	printf("  killedUnitCount=%zu; %zu\n", offsetof(BWAPI::PlayerData, killedUnitCount), sizeof(pd.killedUnitCount));
	printf("  upgradeLevel=%zu; %zu\n", offsetof(BWAPI::PlayerData, upgradeLevel), sizeof(pd.upgradeLevel));
	printf("  hasResearched=%zu; %zu\n", offsetof(BWAPI::PlayerData, hasResearched), sizeof(pd.hasResearched));
	printf("  isResearching=%zu; %zu\n", offsetof(BWAPI::PlayerData, isResearching), sizeof(pd.isResearching));
	printf("  isUpgrading=%zu; %zu\n", offsetof(BWAPI::PlayerData, isUpgrading), sizeof(pd.isUpgrading));
	printf("  color=%zu; %zu\n", offsetof(BWAPI::PlayerData, color), sizeof(pd.color));
	printf("  totalUnitScore=%zu; %zu\n", offsetof(BWAPI::PlayerData, totalUnitScore), sizeof(pd.totalUnitScore));
	printf("  totalKillScore=%zu; %zu\n", offsetof(BWAPI::PlayerData, totalKillScore), sizeof(pd.totalKillScore));
	printf("  totalBuildingScore=%zu; %zu\n", offsetof(BWAPI::PlayerData, totalBuildingScore), sizeof(pd.totalBuildingScore));
	printf("  totalRazingScore=%zu; %zu\n", offsetof(BWAPI::PlayerData, totalRazingScore), sizeof(pd.totalRazingScore));
	printf("  customScore=%zu; %zu\n", offsetof(BWAPI::PlayerData, customScore), sizeof(pd.customScore));
	printf("  maxUpgradeLevel=%zu; %zu\n", offsetof(BWAPI::PlayerData, maxUpgradeLevel), sizeof(pd.maxUpgradeLevel));
	printf("  isResearchAvailable=%zu; %zu\n", offsetof(BWAPI::PlayerData, isResearchAvailable), sizeof(pd.isResearchAvailable));
	printf("  isUnitAvailable=%zu; %zu\n", offsetof(BWAPI::PlayerData, isUnitAvailable), sizeof(pd.isUnitAvailable));

	return 0;
}


int check_unitdata() {
	struct BWAPI::UnitData ud;
	printf("UnitData=%zu\n", sizeof(ud));
	printf("  clearanceLevel=%zu; %zu\n", offsetof(BWAPI::UnitData, clearanceLevel), sizeof(ud.clearanceLevel));
	printf("  id=%zu; %zu\n", offsetof(BWAPI::UnitData, id), sizeof(ud.id));
	printf("  player=%zu; %zu\n", offsetof(BWAPI::UnitData, player), sizeof(ud.player));
	printf("  type=%zu; %zu\n", offsetof(BWAPI::UnitData, type), sizeof(ud.type));
	printf("  positionX=%zu; %zu\n", offsetof(BWAPI::UnitData, positionX), sizeof(ud.positionX));
	printf("  positionY=%zu; %zu\n", offsetof(BWAPI::UnitData, positionY), sizeof(ud.positionY));
	printf("  angle=%zu; %zu\n", offsetof(BWAPI::UnitData, angle), sizeof(ud.angle));
	printf("  velocityX=%zu; %zu\n", offsetof(BWAPI::UnitData, velocityX), sizeof(ud.velocityX));
	printf("  velocityY=%zu; %zu\n", offsetof(BWAPI::UnitData, velocityY), sizeof(ud.velocityY));
	printf("  hitPoints=%zu; %zu\n", offsetof(BWAPI::UnitData, hitPoints), sizeof(ud.hitPoints));
	printf("  lastHitPoints=%zu; %zu\n", offsetof(BWAPI::UnitData, lastHitPoints), sizeof(ud.lastHitPoints));
	printf("  shields=%zu; %zu\n", offsetof(BWAPI::UnitData, shields), sizeof(ud.shields));
	printf("  energy=%zu; %zu\n", offsetof(BWAPI::UnitData, energy), sizeof(ud.energy));
	printf("  resources=%zu; %zu\n", offsetof(BWAPI::UnitData, resources), sizeof(ud.resources));
	printf("  resourceGroup=%zu; %zu\n", offsetof(BWAPI::UnitData, resourceGroup), sizeof(ud.resourceGroup));
	printf("  killCount=%zu; %zu\n", offsetof(BWAPI::UnitData, killCount), sizeof(ud.killCount));
	printf("  acidSporeCount=%zu; %zu\n", offsetof(BWAPI::UnitData, acidSporeCount), sizeof(ud.acidSporeCount));
	printf("  scarabCount=%zu; %zu\n", offsetof(BWAPI::UnitData, scarabCount), sizeof(ud.scarabCount));
	printf("  spiderMineCount=%zu; %zu\n", offsetof(BWAPI::UnitData, spiderMineCount), sizeof(ud.spiderMineCount));
	printf("  groundWeaponCooldown=%zu; %zu\n", offsetof(BWAPI::UnitData, groundWeaponCooldown), sizeof(ud.groundWeaponCooldown));
	printf("  airWeaponCooldown=%zu; %zu\n", offsetof(BWAPI::UnitData, airWeaponCooldown), sizeof(ud.airWeaponCooldown));
	printf("  spellCooldown=%zu; %zu\n", offsetof(BWAPI::UnitData, spellCooldown), sizeof(ud.spellCooldown));
	printf("  defenseMatrixPoints=%zu; %zu\n", offsetof(BWAPI::UnitData, defenseMatrixPoints), sizeof(ud.defenseMatrixPoints));
	printf("  defenseMatrixTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, defenseMatrixTimer), sizeof(ud.defenseMatrixTimer));
	printf("  ensnareTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, ensnareTimer), sizeof(ud.ensnareTimer));
	printf("  irradiateTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, irradiateTimer), sizeof(ud.irradiateTimer));
	printf("  lockdownTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, lockdownTimer), sizeof(ud.lockdownTimer));
	printf("  maelstromTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, maelstromTimer), sizeof(ud.maelstromTimer));
	printf("  orderTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, orderTimer), sizeof(ud.orderTimer));
	printf("  plagueTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, plagueTimer), sizeof(ud.plagueTimer));
	printf("  removeTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, removeTimer), sizeof(ud.removeTimer));
	printf("  stasisTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, stasisTimer), sizeof(ud.stasisTimer));
	printf("  stimTimer=%zu; %zu\n", offsetof(BWAPI::UnitData, stimTimer), sizeof(ud.stimTimer));
	printf("  buildType=%zu; %zu\n", offsetof(BWAPI::UnitData, buildType), sizeof(ud.buildType));
	printf("  trainingQueueCount=%zu; %zu\n", offsetof(BWAPI::UnitData, trainingQueueCount), sizeof(ud.trainingQueueCount));
	printf("  trainingQueue=%zu; %zu\n", offsetof(BWAPI::UnitData, trainingQueue), sizeof(ud.trainingQueue));
	printf("  tech=%zu; %zu\n", offsetof(BWAPI::UnitData, tech), sizeof(ud.tech));
	printf("  upgrade=%zu; %zu\n", offsetof(BWAPI::UnitData, upgrade), sizeof(ud.upgrade));
	printf("  remainingBuildTime=%zu; %zu\n", offsetof(BWAPI::UnitData, remainingBuildTime), sizeof(ud.remainingBuildTime));
	printf("  remainingTrainTime=%zu; %zu\n", offsetof(BWAPI::UnitData, remainingTrainTime), sizeof(ud.remainingTrainTime));
	printf("  remainingResearchTime=%zu; %zu\n", offsetof(BWAPI::UnitData, remainingResearchTime), sizeof(ud.remainingResearchTime));
	printf("  remainingUpgradeTime=%zu; %zu\n", offsetof(BWAPI::UnitData, remainingUpgradeTime), sizeof(ud.remainingUpgradeTime));
	printf("  buildUnit=%zu; %zu\n", offsetof(BWAPI::UnitData, buildUnit), sizeof(ud.buildUnit));
	printf("  target=%zu; %zu\n", offsetof(BWAPI::UnitData, target), sizeof(ud.target));
	printf("  targetPositionX=%zu; %zu\n", offsetof(BWAPI::UnitData, targetPositionX), sizeof(ud.targetPositionX));
	printf("  targetPositionY=%zu; %zu\n", offsetof(BWAPI::UnitData, targetPositionY), sizeof(ud.targetPositionY));
	printf("  order=%zu; %zu\n", offsetof(BWAPI::UnitData, order), sizeof(ud.order));
	printf("  orderTarget=%zu; %zu\n", offsetof(BWAPI::UnitData, orderTarget), sizeof(ud.orderTarget));
	printf("  orderTargetPositionX=%zu; %zu\n", offsetof(BWAPI::UnitData, orderTargetPositionX), sizeof(ud.orderTargetPositionX));
	printf("  orderTargetPositionY=%zu; %zu\n", offsetof(BWAPI::UnitData, orderTargetPositionY), sizeof(ud.orderTargetPositionY));
	printf("  secondaryOrder=%zu; %zu\n", offsetof(BWAPI::UnitData, secondaryOrder), sizeof(ud.secondaryOrder));
	printf("  rallyPositionX=%zu; %zu\n", offsetof(BWAPI::UnitData, rallyPositionX), sizeof(ud.rallyPositionX));
	printf("  rallyPositionY=%zu; %zu\n", offsetof(BWAPI::UnitData, rallyPositionY), sizeof(ud.rallyPositionY));
	printf("  rallyUnit=%zu; %zu\n", offsetof(BWAPI::UnitData, rallyUnit), sizeof(ud.rallyUnit));
	printf("  addon=%zu; %zu\n", offsetof(BWAPI::UnitData, addon), sizeof(ud.addon));
	printf("  nydusExit=%zu; %zu\n", offsetof(BWAPI::UnitData, nydusExit), sizeof(ud.nydusExit));
	printf("  powerUp=%zu; %zu\n", offsetof(BWAPI::UnitData, powerUp), sizeof(ud.powerUp));
	printf("  transport=%zu; %zu\n", offsetof(BWAPI::UnitData, transport), sizeof(ud.transport));
	printf("  carrier=%zu; %zu\n", offsetof(BWAPI::UnitData, carrier), sizeof(ud.carrier));
	printf("  hatchery=%zu; %zu\n", offsetof(BWAPI::UnitData, hatchery), sizeof(ud.hatchery));
	printf("  exists=%zu; %zu\n", offsetof(BWAPI::UnitData, exists), sizeof(ud.exists));
	printf("  hasNuke=%zu; %zu\n", offsetof(BWAPI::UnitData, hasNuke), sizeof(ud.hasNuke));
	printf("  isAccelerating=%zu; %zu\n", offsetof(BWAPI::UnitData, isAccelerating), sizeof(ud.isAccelerating));
	printf("  isAttacking=%zu; %zu\n", offsetof(BWAPI::UnitData, isAttacking), sizeof(ud.isAttacking));
	printf("  isAttackFrame=%zu; %zu\n", offsetof(BWAPI::UnitData, isAttackFrame), sizeof(ud.isAttackFrame));
	printf("  isBeingGathered=%zu; %zu\n", offsetof(BWAPI::UnitData, isBeingGathered), sizeof(ud.isBeingGathered));
	printf("  isBlind=%zu; %zu\n", offsetof(BWAPI::UnitData, isBlind), sizeof(ud.isBlind));
	printf("  isBraking=%zu; %zu\n", offsetof(BWAPI::UnitData, isBraking), sizeof(ud.isBraking));
	printf("  isBurrowed=%zu; %zu\n", offsetof(BWAPI::UnitData, isBurrowed), sizeof(ud.isBurrowed));
	printf("  carryResourceType=%zu; %zu\n", offsetof(BWAPI::UnitData, carryResourceType), sizeof(ud.carryResourceType));
	printf("  isCloaked=%zu; %zu\n", offsetof(BWAPI::UnitData, isCloaked), sizeof(ud.isCloaked));
	printf("  isCompleted=%zu; %zu\n", offsetof(BWAPI::UnitData, isCompleted), sizeof(ud.isCompleted));
	printf("  isConstructing=%zu; %zu\n", offsetof(BWAPI::UnitData, isConstructing), sizeof(ud.isConstructing));
	printf("  isDetected=%zu; %zu\n", offsetof(BWAPI::UnitData, isDetected), sizeof(ud.isDetected));
	printf("  isGathering=%zu; %zu\n", offsetof(BWAPI::UnitData, isGathering), sizeof(ud.isGathering));
	printf("  isHallucination=%zu; %zu\n", offsetof(BWAPI::UnitData, isHallucination), sizeof(ud.isHallucination));
	printf("  isIdle=%zu; %zu\n", offsetof(BWAPI::UnitData, isIdle), sizeof(ud.isIdle));
	printf("  isInterruptible=%zu; %zu\n", offsetof(BWAPI::UnitData, isInterruptible), sizeof(ud.isInterruptible));
	printf("  isInvincible=%zu; %zu\n", offsetof(BWAPI::UnitData, isInvincible), sizeof(ud.isInvincible));
	printf("  isLifted=%zu; %zu\n", offsetof(BWAPI::UnitData, isLifted), sizeof(ud.isLifted));
	printf("  isMorphing=%zu; %zu\n", offsetof(BWAPI::UnitData, isMorphing), sizeof(ud.isMorphing));
	printf("  isMoving=%zu; %zu\n", offsetof(BWAPI::UnitData, isMoving), sizeof(ud.isMoving));
	printf("  isParasited=%zu; %zu\n", offsetof(BWAPI::UnitData, isParasited), sizeof(ud.isParasited));
	printf("  isSelected=%zu; %zu\n", offsetof(BWAPI::UnitData, isSelected), sizeof(ud.isSelected));
	printf("  isStartingAttack=%zu; %zu\n", offsetof(BWAPI::UnitData, isStartingAttack), sizeof(ud.isStartingAttack));
	printf("  isStuck=%zu; %zu\n", offsetof(BWAPI::UnitData, isStuck), sizeof(ud.isStuck));
	printf("  isTraining=%zu; %zu\n", offsetof(BWAPI::UnitData, isTraining), sizeof(ud.isTraining));
	printf("  isUnderStorm=%zu; %zu\n", offsetof(BWAPI::UnitData, isUnderStorm), sizeof(ud.isUnderStorm));
	printf("  isUnderDarkSwarm=%zu; %zu\n", offsetof(BWAPI::UnitData, isUnderDarkSwarm), sizeof(ud.isUnderDarkSwarm));
	printf("  isUnderDWeb=%zu; %zu\n", offsetof(BWAPI::UnitData, isUnderDWeb), sizeof(ud.isUnderDWeb));
	printf("  isPowered=%zu; %zu\n", offsetof(BWAPI::UnitData, isPowered), sizeof(ud.isPowered));
	printf("  isVisible=%zu; %zu\n", offsetof(BWAPI::UnitData, isVisible), sizeof(ud.isVisible));
	printf("  buttonset=%zu; %zu\n", offsetof(BWAPI::UnitData, buttonset), sizeof(ud.buttonset));
	printf("  lastAttackerPlayer=%zu; %zu\n", offsetof(BWAPI::UnitData, lastAttackerPlayer), sizeof(ud.lastAttackerPlayer));
	printf("  recentlyAttacked=%zu; %zu\n", offsetof(BWAPI::UnitData, recentlyAttacked), sizeof(ud.recentlyAttacked));
	printf("  replayID=%zu; %zu\n", offsetof(BWAPI::UnitData, replayID), sizeof(ud.replayID));

	return 0;
}


int check_bulletdata() {
	struct BWAPI::BulletData bd;
	printf("BulletData=%zu\n", sizeof(bd));
	printf("  id=%zu; %zu\n", offsetof(BWAPI::BulletData, id), sizeof(bd.id));
	printf("  player=%zu; %zu\n", offsetof(BWAPI::BulletData, player), sizeof(bd.player));
	printf("  type=%zu; %zu\n", offsetof(BWAPI::BulletData, type), sizeof(bd.type));
	printf("  source=%zu; %zu\n", offsetof(BWAPI::BulletData, source), sizeof(bd.source));
	printf("  positionX=%zu; %zu\n", offsetof(BWAPI::BulletData, positionX), sizeof(bd.positionX));
	printf("  positionY=%zu; %zu\n", offsetof(BWAPI::BulletData, positionY), sizeof(bd.positionY));
	printf("  angle=%zu; %zu\n", offsetof(BWAPI::BulletData, angle), sizeof(bd.angle));
	printf("  velocityX=%zu; %zu\n", offsetof(BWAPI::BulletData, velocityX), sizeof(bd.velocityX));
	printf("  velocityY=%zu; %zu\n", offsetof(BWAPI::BulletData, velocityY), sizeof(bd.velocityY));
	printf("  target=%zu; %zu\n", offsetof(BWAPI::BulletData, target), sizeof(bd.target));
	printf("  targetPositionX=%zu; %zu\n", offsetof(BWAPI::BulletData, targetPositionX), sizeof(bd.targetPositionX));
	printf("  targetPositionY=%zu; %zu\n", offsetof(BWAPI::BulletData, targetPositionY), sizeof(bd.targetPositionY));
	printf("  removeTimer=%zu; %zu\n", offsetof(BWAPI::BulletData, removeTimer), sizeof(bd.removeTimer));
	printf("  exists=%zu; %zu\n", offsetof(BWAPI::BulletData, exists), sizeof(bd.exists));
	printf("  isVisible=%zu; %zu\n", offsetof(BWAPI::BulletData, isVisible), sizeof(bd.isVisible));

	return 0;
}


int check_position() {
	struct BWAPIC::Position p;
	printf("Position=%zu\n", sizeof(p));
	printf("  x=%zu; %zu\n", offsetof(BWAPIC::Position, x), sizeof(p.x));
	printf("  y=%zu; %zu\n", offsetof(BWAPIC::Position, y), sizeof(p.y));

	return 0;
}


int check_regiondata() {
	struct BWAPI::RegionData rd;
	printf("RegionData=%zu\n", sizeof(rd));
	printf("  id=%zu; %zu\n", offsetof(BWAPI::RegionData, id), sizeof(rd.id));
	printf("  islandID=%zu; %zu\n", offsetof(BWAPI::RegionData, islandID), sizeof(rd.islandID));
	printf("  center_x=%zu; %zu\n", offsetof(BWAPI::RegionData, center_x), sizeof(rd.center_x));
	printf("  center_y=%zu; %zu\n", offsetof(BWAPI::RegionData, center_y), sizeof(rd.center_y));
	printf("  priority=%zu; %zu\n", offsetof(BWAPI::RegionData, priority), sizeof(rd.priority));
	printf("  leftMost=%zu; %zu\n", offsetof(BWAPI::RegionData, leftMost), sizeof(rd.leftMost));
	printf("  rightMost=%zu; %zu\n", offsetof(BWAPI::RegionData, rightMost), sizeof(rd.rightMost));
	printf("  topMost=%zu; %zu\n", offsetof(BWAPI::RegionData, topMost), sizeof(rd.topMost));
	printf("  bottomMost=%zu; %zu\n", offsetof(BWAPI::RegionData, bottomMost), sizeof(rd.bottomMost));
	printf("  neighborCount=%zu; %zu\n", offsetof(BWAPI::RegionData, neighborCount), sizeof(rd.neighborCount));
	printf("  neighbors=%zu; %zu\n", offsetof(BWAPI::RegionData, neighbors), sizeof(rd.neighbors));
	printf("  isAccessible=%zu; %zu\n", offsetof(BWAPI::RegionData, isAccessible), sizeof(rd.isAccessible));
	printf("  isHigherGround=%zu; %zu\n", offsetof(BWAPI::RegionData, isHigherGround), sizeof(rd.isHigherGround));

	return 0;
}


int check_event() {
	struct BWAPIC::Event e;
	printf("Event=%zu\n", sizeof(e));
	printf("  type=%zu; %zu\n", offsetof(BWAPIC::Event, type), sizeof(e.type));
	printf("  v1=%zu; %zu\n", offsetof(BWAPIC::Event, v1), sizeof(e.v1));
	printf("  v2=%zu; %zu\n", offsetof(BWAPIC::Event, v2), sizeof(e.v2));

	return 0;
}


int check_shape() {
	struct BWAPIC::Shape s;
	printf("Shape=%zu\n", sizeof(s));
	printf("  type=%zu; %zu\n", offsetof(BWAPIC::Shape, type), sizeof(s.type));
	printf("  ctype=%zu; %zu\n", offsetof(BWAPIC::Shape, ctype), sizeof(s.ctype));
	printf("  x1=%zu; %zu\n", offsetof(BWAPIC::Shape, x1), sizeof(s.x1));
	printf("  y1=%zu; %zu\n", offsetof(BWAPIC::Shape, y1), sizeof(s.y1));
	printf("  x2=%zu; %zu\n", offsetof(BWAPIC::Shape, x2), sizeof(s.x2));
	printf("  y2=%zu; %zu\n", offsetof(BWAPIC::Shape, y2), sizeof(s.y2));
	printf("  extra1=%zu; %zu\n", offsetof(BWAPIC::Shape, extra1), sizeof(s.extra1));
	printf("  extra2=%zu; %zu\n", offsetof(BWAPIC::Shape, extra2), sizeof(s.extra2));
	printf("  color=%zu; %zu\n", offsetof(BWAPIC::Shape, color), sizeof(s.color));
	printf("  isSolid=%zu; %zu\n", offsetof(BWAPIC::Shape, isSolid), sizeof(s.isSolid));

	return 0;
}


int check_command() {
	struct BWAPIC::Command c;
	printf("Command=%zu\n", sizeof(c));
	printf("  type=%zu; %zu\n", offsetof(BWAPIC::Command, type), sizeof(c.type));
	printf("  value1=%zu; %zu\n", offsetof(BWAPIC::Command, value1), sizeof(c.value1));
	printf("  value2=%zu; %zu\n", offsetof(BWAPIC::Command, value2), sizeof(c.value2));

	return 0;
}


int check_unitcommand() {
	struct BWAPIC::UnitCommand uc;
	printf("UnitCommand=%zu\n", sizeof(uc));
	printf("  type=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, type), sizeof(uc.type));
	printf("  unitIndex=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, unitIndex), sizeof(uc.unitIndex));
	printf("  targetIndex=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, targetIndex), sizeof(uc.targetIndex));
	printf("  x=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, x), sizeof(uc.x));
	printf("  y=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, y), sizeof(uc.y));
	printf("  extra=%zu; %zu\n", offsetof(BWAPIC::UnitCommand, extra), sizeof(uc.extra));

	return 0;
}


int check_unitfinder() {
	struct BWAPI::unitFinder uf;
	printf("unitFinder=%zu\n", sizeof(uf));
	printf("  unitIndex=%zu; %zu\n", offsetof(BWAPI::unitFinder, unitIndex), sizeof(uf.unitIndex));
	printf("  searchValue=%zu; %zu\n", offsetof(BWAPI::unitFinder, searchValue), sizeof(uf.searchValue));

	return 0;
}


int check_gamedata() {
	struct BWAPI::GameData *gd = (BWAPI::GameData *) calloc(1, sizeof(BWAPI::GameData));
	if(!gd) {
		printf("failed to allocate memory for BWAPI::GameData");
		return -1;
	}

	printf("GameData=%zu\n", sizeof(*gd));
	printf("  revision=%zu; %zu\n", offsetof(BWAPI::GameData, revision), sizeof(gd->revision));
	printf("  isDebug=%zu; %zu\n", offsetof(BWAPI::GameData, isDebug), sizeof(gd->isDebug));
	printf("  instanceID=%zu; %zu\n", offsetof(BWAPI::GameData, instanceID), sizeof(gd->instanceID));
	printf("  botAPM_noselects=%zu; %zu\n", offsetof(BWAPI::GameData, botAPM_noselects), sizeof(gd->botAPM_noselects));
	printf("  botAPM_selects=%zu; %zu\n", offsetof(BWAPI::GameData, botAPM_selects), sizeof(gd->botAPM_selects));
	printf("  forceCount=%zu; %zu\n", offsetof(BWAPI::GameData, forceCount), sizeof(gd->forceCount));
	printf("  forces=%zu; %zu\n", offsetof(BWAPI::GameData, forces), sizeof(gd->forces));
	printf("  playerCount=%zu; %zu\n", offsetof(BWAPI::GameData, playerCount), sizeof(gd->playerCount));
	printf("  players=%zu; %zu\n", offsetof(BWAPI::GameData, players), sizeof(gd->players));
	printf("  initialUnitCount=%zu; %zu\n", offsetof(BWAPI::GameData, initialUnitCount), sizeof(gd->initialUnitCount));
	printf("  units=%zu; %zu\n", offsetof(BWAPI::GameData, units), sizeof(gd->units));
	printf("  unitArray=%zu; %zu\n", offsetof(BWAPI::GameData, unitArray), sizeof(gd->unitArray));
	printf("  bullets=%zu; %zu\n", offsetof(BWAPI::GameData, bullets), sizeof(gd->bullets));
	printf("  nukeDotCount=%zu; %zu\n", offsetof(BWAPI::GameData, nukeDotCount), sizeof(gd->nukeDotCount));
	printf("  nukeDots=%zu; %zu\n", offsetof(BWAPI::GameData, nukeDots), sizeof(gd->nukeDots));
	printf("  gameType=%zu; %zu\n", offsetof(BWAPI::GameData, gameType), sizeof(gd->gameType));
	printf("  latency=%zu; %zu\n", offsetof(BWAPI::GameData, latency), sizeof(gd->latency));
	printf("  latencyFrames=%zu; %zu\n", offsetof(BWAPI::GameData, latencyFrames), sizeof(gd->latencyFrames));
	printf("  latencyTime=%zu; %zu\n", offsetof(BWAPI::GameData, latencyTime), sizeof(gd->latencyTime));
	printf("  remainingLatencyFrames=%zu; %zu\n", offsetof(BWAPI::GameData, remainingLatencyFrames), sizeof(gd->remainingLatencyFrames));
	printf("  remainingLatencyTime=%zu; %zu\n", offsetof(BWAPI::GameData, remainingLatencyTime), sizeof(gd->remainingLatencyTime));
	printf("  hasLatCom=%zu; %zu\n", offsetof(BWAPI::GameData, hasLatCom), sizeof(gd->hasLatCom));
	printf("  hasGUI=%zu; %zu\n", offsetof(BWAPI::GameData, hasGUI), sizeof(gd->hasGUI));
	printf("  replayFrameCount=%zu; %zu\n", offsetof(BWAPI::GameData, replayFrameCount), sizeof(gd->replayFrameCount));
	printf("  frameCount=%zu; %zu\n", offsetof(BWAPI::GameData, frameCount), sizeof(gd->frameCount));
	printf("  elapsedTime=%zu; %zu\n", offsetof(BWAPI::GameData, elapsedTime), sizeof(gd->elapsedTime));
	printf("  countdownTimer=%zu; %zu\n", offsetof(BWAPI::GameData, countdownTimer), sizeof(gd->countdownTimer));
	printf("  fps=%zu; %zu\n", offsetof(BWAPI::GameData, fps), sizeof(gd->fps));
	printf("  averageFPS=%zu; %zu\n", offsetof(BWAPI::GameData, averageFPS), sizeof(gd->averageFPS));
	printf("  mouseX=%zu; %zu\n", offsetof(BWAPI::GameData, mouseX), sizeof(gd->mouseX));
	printf("  mouseY=%zu; %zu\n", offsetof(BWAPI::GameData, mouseY), sizeof(gd->mouseY));
	printf("  mouseState=%zu; %zu\n", offsetof(BWAPI::GameData, mouseState), sizeof(gd->mouseState));
	printf("  keyState=%zu; %zu\n", offsetof(BWAPI::GameData, keyState), sizeof(gd->keyState));
	printf("  screenX=%zu; %zu\n", offsetof(BWAPI::GameData, screenX), sizeof(gd->screenX));
	printf("  screenY=%zu; %zu\n", offsetof(BWAPI::GameData, screenY), sizeof(gd->screenY));
	printf("  flags=%zu; %zu\n", offsetof(BWAPI::GameData, flags), sizeof(gd->flags));
	printf("  mapWidth=%zu; %zu\n", offsetof(BWAPI::GameData, mapWidth), sizeof(gd->mapWidth));
	printf("  mapHeight=%zu; %zu\n", offsetof(BWAPI::GameData, mapHeight), sizeof(gd->mapHeight));
	printf("  mapFileName=%zu; %zu\n", offsetof(BWAPI::GameData, mapFileName), sizeof(gd->mapFileName));
	printf("  mapPathName=%zu; %zu\n", offsetof(BWAPI::GameData, mapPathName), sizeof(gd->mapPathName));
	printf("  mapName=%zu; %zu\n", offsetof(BWAPI::GameData, mapName), sizeof(gd->mapName));
	printf("  mapHash=%zu; %zu\n", offsetof(BWAPI::GameData, mapHash), sizeof(gd->mapHash));
	printf("  getGroundHeight=%zu; %zu\n", offsetof(BWAPI::GameData, getGroundHeight), sizeof(gd->getGroundHeight));
	printf("  isWalkable=%zu; %zu\n", offsetof(BWAPI::GameData, isWalkable), sizeof(gd->isWalkable));
	printf("  isBuildable=%zu; %zu\n", offsetof(BWAPI::GameData, isBuildable), sizeof(gd->isBuildable));
	printf("  isVisible=%zu; %zu\n", offsetof(BWAPI::GameData, isVisible), sizeof(gd->isVisible));
	printf("  isExplored=%zu; %zu\n", offsetof(BWAPI::GameData, isExplored), sizeof(gd->isExplored));
	printf("  hasCreep=%zu; %zu\n", offsetof(BWAPI::GameData, hasCreep), sizeof(gd->hasCreep));
	printf("  isOccupied=%zu; %zu\n", offsetof(BWAPI::GameData, isOccupied), sizeof(gd->isOccupied));
	printf("  mapTileRegionId=%zu; %zu\n", offsetof(BWAPI::GameData, mapTileRegionId), sizeof(gd->mapTileRegionId));
	printf("  mapSplitTilesMiniTileMask=%zu; %zu\n", offsetof(BWAPI::GameData, mapSplitTilesMiniTileMask), sizeof(gd->mapSplitTilesMiniTileMask));
	printf("  mapSplitTilesRegion1=%zu; %zu\n", offsetof(BWAPI::GameData, mapSplitTilesRegion1), sizeof(gd->mapSplitTilesRegion1));
	printf("  mapSplitTilesRegion2=%zu; %zu\n", offsetof(BWAPI::GameData, mapSplitTilesRegion2), sizeof(gd->mapSplitTilesRegion2));
	printf("  regionCount=%zu; %zu\n", offsetof(BWAPI::GameData, regionCount), sizeof(gd->regionCount));
	printf("  regions=%zu; %zu\n", offsetof(BWAPI::GameData, regions), sizeof(gd->regions));
	printf("  startLocationCount=%zu; %zu\n", offsetof(BWAPI::GameData, startLocationCount), sizeof(gd->startLocationCount));
	printf("  startLocations=%zu; %zu\n", offsetof(BWAPI::GameData, startLocations), sizeof(gd->startLocations));
	printf("  isInGame=%zu; %zu\n", offsetof(BWAPI::GameData, isInGame), sizeof(gd->isInGame));
	printf("  isMultiplayer=%zu; %zu\n", offsetof(BWAPI::GameData, isMultiplayer), sizeof(gd->isMultiplayer));
	printf("  isBattleNet=%zu; %zu\n", offsetof(BWAPI::GameData, isBattleNet), sizeof(gd->isBattleNet));
	printf("  isPaused=%zu; %zu\n", offsetof(BWAPI::GameData, isPaused), sizeof(gd->isPaused));
	printf("  isReplay=%zu; %zu\n", offsetof(BWAPI::GameData, isReplay), sizeof(gd->isReplay));
	printf("  selectedUnitCount=%zu; %zu\n", offsetof(BWAPI::GameData, selectedUnitCount), sizeof(gd->selectedUnitCount));
	printf("  selectedUnits=%zu; %zu\n", offsetof(BWAPI::GameData, selectedUnits), sizeof(gd->selectedUnits));
	printf("  self=%zu; %zu\n", offsetof(BWAPI::GameData, self), sizeof(gd->self));
	printf("  enemy=%zu; %zu\n", offsetof(BWAPI::GameData, enemy), sizeof(gd->enemy));
	printf("  neutral=%zu; %zu\n", offsetof(BWAPI::GameData, neutral), sizeof(gd->neutral));
	printf("  eventCount=%zu; %zu\n", offsetof(BWAPI::GameData, eventCount), sizeof(gd->eventCount));
	printf("  events=%zu; %zu\n", offsetof(BWAPI::GameData, events), sizeof(gd->events));
	printf("  eventStringCount=%zu; %zu\n", offsetof(BWAPI::GameData, eventStringCount), sizeof(gd->eventStringCount));
	printf("  eventStrings=%zu; %zu\n", offsetof(BWAPI::GameData, eventStrings), sizeof(gd->eventStrings));
	printf("  stringCount=%zu; %zu\n", offsetof(BWAPI::GameData, stringCount), sizeof(gd->stringCount));
	printf("  strings=%zu; %zu\n", offsetof(BWAPI::GameData, strings), sizeof(gd->strings));
	printf("  shapeCount=%zu; %zu\n", offsetof(BWAPI::GameData, shapeCount), sizeof(gd->shapeCount));
	printf("  shapes=%zu; %zu\n", offsetof(BWAPI::GameData, shapes), sizeof(gd->shapes));
	printf("  commandCount=%zu; %zu\n", offsetof(BWAPI::GameData, commandCount), sizeof(gd->commandCount));
	printf("  commands=%zu; %zu\n", offsetof(BWAPI::GameData, commands), sizeof(gd->commands));
	printf("  unitCommandCount=%zu; %zu\n", offsetof(BWAPI::GameData, unitCommandCount), sizeof(gd->unitCommandCount));
	printf("  unitCommands=%zu; %zu\n", offsetof(BWAPI::GameData, unitCommands), sizeof(gd->unitCommands));
	printf("  unitSearchSize=%zu; %zu\n", offsetof(BWAPI::GameData, unitSearchSize), sizeof(gd->unitSearchSize));
	printf("  xUnitSearch=%zu; %zu\n", offsetof(BWAPI::GameData, xUnitSearch), sizeof(gd->xUnitSearch));
	printf("  yUnitSearch=%zu; %zu\n", offsetof(BWAPI::GameData, yUnitSearch), sizeof(gd->yUnitSearch));

	free(gd);
	return 0;
}


int main(int argc, char **argv) {
	if(check_forcedata()) return -1;
	if(check_playerdata()) return -1;
	if(check_unitdata()) return -1;
	if(check_bulletdata()) return -1;
	if(check_position()) return -1;
	if(check_regiondata()) return -1;
	if(check_event()) return -1;
	if(check_shape()) return -1;
	if(check_command()) return -1;
	if(check_unitcommand()) return -1;
	if(check_unitfinder()) return -1;
	if(check_gamedata()) return -1;
	return 0;
}
