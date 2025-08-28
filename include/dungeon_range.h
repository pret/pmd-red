#ifndef GUARD_DUNGEON_RANGE_H
#define GUARD_DUNGEON_RANGE_H

#include "structs/str_position.h"
#include "structs/dungeon_entity.h"

bool8 IsPositionActuallyInSight(DungeonPos *pos1, DungeonPos *pos2);
bool8 IsPositionInSight(DungeonPos *pos1, DungeonPos *pos2);
void sub_80833E8(DungeonPos *param_1, s32 *param_2);
bool8 IsTargetTwoTilesAway(DungeonPos *pos1, DungeonPos *pos2);
bool8 sub_8083568(s32 inX, s32 inY, u8 index);
Entity* GetLeader(void);
EntityInfo* GetLeaderInfo(void);
bool8 sub_8083660(DungeonPos *posDst);
bool8 sub_808384C(DungeonPos *posDst, const DungeonPos *posSrc);
void sub_80838EC(u8 *a0);
void sub_8083904(struct DungeonPos *posDst, struct Entity *entityArg);

#endif
