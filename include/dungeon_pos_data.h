#ifndef GUARD_DUNGEON_POS_DATA_H
#define GUARD_DUNGEON_POS_DATA_H

#include "structs/str_position.h"
#include "constants/direction.h"

struct Struct80F4CC4 {
    const DungeonPos *posArray;
    s16 xOffset;
    s16 yOffset;
};

extern const struct Struct80F4CC4 gUnknown_80F4CC4[NUM_DIRECTIONS];

#endif
