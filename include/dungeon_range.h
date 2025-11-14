#ifndef GUARD_DUNGEON_RANGE_H
#define GUARD_DUNGEON_RANGE_H

#include "structs/str_position.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"

// Actual function in Sky. TODO: Find other uses of it and sync with Sky.
static inline s32 GetVisibilityRange(void)
{
    s32 visibilityRange = gDungeon->unk181e8.visibilityRange;
    if (visibilityRange == 0)
        return 2;

    return visibilityRange;
}

bool8 IsPositionActuallyInSight(DungeonPos *origin, DungeonPos *target);
bool8 IsPositionInSight(DungeonPos *origin, DungeonPos *target);
void sub_80833E8(DungeonPos *param_1, s32 *param_2);
bool8 IsPositionWithinTwoTiles(DungeonPos *pos1, DungeonPos *pos2);
bool8 sub_8083568(s32 inX, s32 inY, u8 index);
Entity* GetLeader(void);
EntityInfo* GetLeaderInfo(void);
bool8 sub_8083660(DungeonPos *posDst);
bool8 sub_808384C(DungeonPos *posDst, const DungeonPos *posSrc);
void sub_80838EC(u8 *a0);
void sub_8083904(struct DungeonPos *posDst, struct Entity *entityArg);

extern Entity *gLeaderPointer;

#endif
