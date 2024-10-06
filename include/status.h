#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "structs/dungeon_entity.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 GetFlashFireStatus(Entity *pokemon);
void UpdateFlashFireBoost(Entity * pokemon, Entity *target);
void ChangeAttackMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void ChangeDefenseMultiplierTarget(Entity *pokemon, Entity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void RaiseAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage);
void LowerAccuracyStageTarget(Entity * pokemon, Entity * target, s32 statStage, bool8 displayMessage);
void CringeStatusTarget(Entity * pokemon,Entity * target, bool8 displayMessage);
void ParalyzeStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void RaiseMovementSpeedTarget(Entity * pokemon, Entity * target, s32 turns, bool8 diplayMessage);
void LowerMovementSpeedTarget(Entity * pokemon, Entity * target, s32 levels, bool8 displayMessage);
void ConfuseStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void CowerStatusTarget(Entity * pokemon, Entity * target, bool8 displayMessage);
void HealTargetHP(Entity *pokemon, Entity *target, s32 param_3, s32 param_4, bool32 displayMessage);
void HandleScannerOrb(Entity* pokemon, Entity* target);
void HandleStairsOrb(Entity* pokemon, Entity* target);
void HandleRadarOrb(Entity* pokemon, Entity* target);
void HandleLeechSeed(Entity * pokemon, Entity * target, bool8 displayMessage);
void DestinyBondStatusTarget(Entity * pokemon, Entity * target);
void SureShotStatusTarget(Entity *pokemon, Entity * target, s32 turns);
void WhifferStatusTarget(Entity *pokemon, Entity * target, s32 turns);
void FixedDamageStatusTarget(Entity *pokemon, Entity * target);
void FocusEnergyStatusTarget(Entity *pokemon, Entity * target);
void CurseStatusTarget(Entity *pokemon, Entity * target);
void SnatchStatusTarget(Entity * pokemon, Entity * target);
void TauntStatusTarget(Entity * pokemon, Entity * target);
void HandleStockpile(Entity * pokemon, Entity * target);
void InvisibleStatusTarget(Entity * pokemon, Entity * target);
void PerishSongTarget(Entity * pokemon, Entity * target);
void EncoreStatusTarget(Entity * pokemon, Entity * target);
void sub_8078A58(struct Entity *pokemon, struct Entity *target, s32 param_3, s32 param_4);

#endif
