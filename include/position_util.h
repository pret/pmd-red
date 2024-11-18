#ifndef GUARD_POSITION_UTIL_H
#define GUARD_POSITION_UTIL_H

#include "structs/str_position.h"

s32 GetDirectionTowardsPosition(DungeonPos *originPos, DungeonPos *targetPos);
s32 GetDistance(DungeonPos *pos1, DungeonPos *pos2);

#endif
