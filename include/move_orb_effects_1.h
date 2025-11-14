#ifndef GUARD_MOVE_ORB_EFFECTS_1_H
#define GUARD_MOVE_ORB_EFFECTS_1_H

#include "structs/dungeon_entity.h"
#include "structs/str_stat_index.h"
#include "number_util.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 sub_8075BF4(Entity * pokemon, s32 sleepClassStatusTurns);
void SleepStatusTarget(Entity * pokemon, Entity * target, s32 turns, bool8 displayMessage);
bool8 CannotSleep(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage);
void NightmareStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void NappingStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void YawnedStatusTarget(Entity * pokemon, Entity * target, s32 turns);
void SleeplessStatusTarget(Entity * pokemon, Entity * target);
void PausedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, s32 turns, bool8 displayMessage);
void InfatuateStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void BurnedStatusTarget(Entity * pokemon, Entity * target, u8 param_3, bool8 displayMessage);
void PoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void BadlyPoisonedStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void FrozenStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void SqueezedStatusTarget(Entity * pokemon, Entity * target, s32 param_3, bool32 displayMessage);
void ImmobilizedStatusTarget(Entity * pokemon, Entity * target);
void IngrainedStatusTarget(Entity * pokemon, Entity * target);
void WrapTarget(Entity * pokemon, Entity * target);
void sub_8076CB4(s32 param_1);
void PetrifiedStatusTarget(Entity * pokemon, Entity * target);
void LowerOffensiveStat(Entity *user, Entity *target, StatIndex stat, s32 nStages, bool8 checkProtected, bool8 logMsgProtected);
void LowerDefensiveStat(Entity *user, Entity *target, StatIndex stat, s32 nStages, bool8 checkProtected, bool8 logMsgProtected);
void BoostOffensiveStat(Entity *user, Entity *target, StatIndex stat, s32 nStages);
void BoostDefensiveStat(Entity *user, Entity *target, StatIndex stat, s32 nStages);
u8 GetFlashFireStatus(Entity *pokemon);
void ActivateFlashFire(Entity * pokemon, Entity *target);
void ApplyOffensiveStatMultiplier(Entity *user, Entity *target, StatIndex stat, s24_8 multiplier, bool8 displayMessage);
void ApplyDefensiveStatMultiplier(Entity *user, Entity *target, StatIndex stat, s24_8 multiplier, bool8 displayMessage);
void BoostHitChanceStat(Entity *user, Entity *target, StatIndex stat);
void LowerHitChanceStat(Entity *user, Entity *target, StatIndex stat, bool8 displayMessage);
void TryInflictCringeStatus(Entity *user ,Entity *target, bool8 displayMessage);
void TryInflictParalysisStatus(Entity *user, Entity *target, bool8 displayMessage);
void BoostSpeed(Entity *user, Entity *target, s32 turns, bool8 displayMessage);
void LowerSpeed(Entity *user, Entity *target, s32 nStages, bool8 displayMessage);

#endif

