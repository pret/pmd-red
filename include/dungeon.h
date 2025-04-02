#ifndef GUARD_DUNGEON_H
#define GUARD_DUNGEON_H

#include "structs/str_dungeon.h"

s32 GetDungeonFloorCount(u8 dungeon);
const u8 *GetDungeonName1(u8 dungeon);
bool8 IsStairDirectionUp(u8 dungeon);
u32 GetMaxItemsAllowed(u8 dungeon);
s8 GetRescuesAllowed(u8 dungeon);
bool8 HasCheckpoint(u8 dungeon);
s16 GetRandomMovementChance(u8 dungeon);
void PrintYellowDungeonNametoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);
void PrintDungeonLocationtoBuffer(u8 *buffer, DungeonLocation *dungeonLocation);

void sub_80901D8(DungeonLocation *param_1, DungeonLocation *param_2);
u32 sub_809034C(u8 dungeonIndex, s32 speciesId_, u8 *buffer, bool32 param_4_, bool32 param_5_);
u32 sub_80908D8(DungeonLocation *dungeon);
u8 sub_8090910(DungeonLocation *dungeon, u32 param_2);
bool8 IsNotValidDungeon(u8 dungeon);
u8 IsRecruitingEnabled(u8 dungeon);

#endif // GUARD_DUNGEON_H
