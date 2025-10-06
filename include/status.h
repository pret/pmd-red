#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "structs/dungeon_entity.h"
#include "number_util.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 GetFlashFireStatus(Entity *pokemon);
void UpdateFlashFireBoost(Entity * pokemon, Entity *target);
void ChangeAttackMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s24_8 param_4, bool8 displayMessage);
void ChangeDefenseMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s24_8 param_4, bool8 displayMessage);
void RaiseAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage);
void LowerAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage, bool8 displayMessage);
void CringeStatusTarget(Entity * pokemon,Entity * target, bool8 displayMessage);
void ParalyzeStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void RaiseMovementSpeedTarget(Entity * pokemon, Entity * target, s32 turns, bool8 diplayMessage);
void LowerMovementSpeedTarget(Entity * pokemon, Entity * target, s32 levels, bool8 displayMessage);

#endif
