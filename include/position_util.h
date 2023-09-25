#ifndef GUARD_POSITION_UTIL_H
#define GUARD_POSITION_UTIL_H

#include "structs/str_position.h"

s32 GetDirectionTowardsPosition(Position *originPos, Position *targetPos);
s32 GetDistance(Position *pos1, Position *pos2);

#endif
