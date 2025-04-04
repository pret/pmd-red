#ifndef GUARD_DUNGEON_POS_DATA_H
#define GUARD_DUNGEON_POS_DATA_H

#include "structs/str_position.h"
#include "constants/direction.h"

struct PositionArrayWithOffsets
{
    const DungeonPos *posArray;
    s16 xOffset;
    s16 yOffset;
};

extern const DungeonPos gAdjacentTileOffsets[];
extern const DungeonPos gUnknown_80F4468[76];
extern const DungeonPos gUnknown_80F4598[158];
extern const struct PositionArrayWithOffsets gUnknown_80F4CC4[NUM_DIRECTIONS];
extern const s32 gFaceDirectionIncrements[];
extern const DungeonPos gUnknown_80F4D44[];
extern const u8 gUnknown_80F4D64[];

#endif
