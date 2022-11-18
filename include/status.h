#ifndef GUARD_STATUS_H
#define GUARD_STATUS_H

#include "dungeon_entity.h"

#define FLASH_FIRE_STATUS_NONE 0
#define FLASH_FIRE_STATUS_MAXED 1
#define FLASH_FIRE_STATUS_NOT_MAXED 2

u8 GetFlashFireStatus(struct DungeonEntity *pokemon);
void UpdateFlashFireBoost(struct DungeonEntity * pokemon, struct DungeonEntity *target);
void sub_80772C0(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void sub_8077434(struct DungeonEntity *pokemon, struct DungeonEntity *target, u32 statStage, s32 param_4, bool8 displayMessage);
void sub_8077540(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 statStage);
void sub_80775DC(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 statStage, bool8 displayMessage);
void CringeStatusTarget(struct DungeonEntity * pokemon,struct DungeonEntity * target, bool8 displayMessage);
void ParalyzeStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void sub_8077910(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns, bool8 diplayMessage);
void sub_80779F0(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 param_3, bool8 displayMessage);
void ConfuseStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void CowerStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void HealTargetHP(struct DungeonEntity *pokemon, struct DungeonEntity *target, s32 param_3, s32 param_4, u32 displayMessage);
void HandleScannerOrb(struct DungeonEntity* pokemon, struct DungeonEntity* target);
void HandleStairsOrb(struct DungeonEntity* pokemon, struct DungeonEntity* target);
void HandleRadarOrb(struct DungeonEntity* pokemon, struct DungeonEntity* target);
void HandleLeechSeed(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void DestinyBondStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void SureShotStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity * target, s32 turns);
void WhifferStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity * target, s32 turns);
void FixedDamageStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity * target);
void FocusEnergyStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity * target);
void CurseStatusTarget(struct DungeonEntity *pokemon, struct DungeonEntity * target);
void SnatchStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void TauntStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void HandleStockpile(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void InvisibleStatusTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);
void PerishSongTarget(struct DungeonEntity * pokemon, struct DungeonEntity * target);

#endif
