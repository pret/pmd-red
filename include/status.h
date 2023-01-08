#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "dungeon_entity.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 GetFlashFireStatus(struct Entity *pokemon);
void UpdateFlashFireBoost(struct Entity * pokemon, struct Entity *target);
void ChangeAttackMultiplierTarget(struct Entity *pokemon, struct Entity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void ChangeDefenseMultiplierTarget(struct Entity *pokemon, struct Entity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void RaiseAccuracyStageTarget(struct Entity * pokemon, struct Entity * target, s32 statStage);
void LowerAccuracyStageTarget(struct Entity * pokemon, struct Entity * target, s32 statStage, bool8 displayMessage);
void CringeStatusTarget(struct Entity * pokemon,struct Entity * target, bool8 displayMessage);
void ParalyzeStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void RaiseMovementSpeedTarget(struct Entity * pokemon, struct Entity * target, s32 turns, bool8 diplayMessage);
void LowerMovementSpeedTarget(struct Entity * pokemon, struct Entity * target, s32 levels, bool8 displayMessage);
void ConfuseStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void CowerStatusTarget(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void HealTargetHP(struct Entity *pokemon, struct Entity *target, s32 param_3, s32 param_4, bool32 displayMessage);
void HandleScannerOrb(struct Entity* pokemon, struct Entity* target);
void HandleStairsOrb(struct Entity* pokemon, struct Entity* target);
void HandleRadarOrb(struct Entity* pokemon, struct Entity* target);
void HandleLeechSeed(struct Entity * pokemon, struct Entity * target, bool8 displayMessage);
void DestinyBondStatusTarget(struct Entity * pokemon, struct Entity * target);
void SureShotStatusTarget(struct Entity *pokemon, struct Entity * target, s32 turns);
void WhifferStatusTarget(struct Entity *pokemon, struct Entity * target, s32 turns);
void FixedDamageStatusTarget(struct Entity *pokemon, struct Entity * target);
void FocusEnergyStatusTarget(struct Entity *pokemon, struct Entity * target);
void CurseStatusTarget(struct Entity *pokemon, struct Entity * target);
void SnatchStatusTarget(struct Entity * pokemon, struct Entity * target);
void TauntStatusTarget(struct Entity * pokemon, struct Entity * target);
void HandleStockpile(struct Entity * pokemon, struct Entity * target);
void InvisibleStatusTarget(struct Entity * pokemon, struct Entity * target);
void PerishSongTarget(struct Entity * pokemon, struct Entity * target);

#endif
