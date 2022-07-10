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
void sub_80776C0(struct DungeonEntity * pokemon,struct DungeonEntity * target, bool8 displayMessage);
void sub_8077780(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void sub_8077910(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 turns, bool8 diplayMessage);
void sub_80779F0(struct DungeonEntity * pokemon, struct DungeonEntity * target, s32 param_3, bool8 displayMessage);
void sub_8077AE4(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);
void sub_8077BB4(struct DungeonEntity * pokemon, struct DungeonEntity * target, bool8 displayMessage);

#endif
