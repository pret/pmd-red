#ifndef GUARD_POSITION_UTIL_H
#define GUARD_POSITION_UTIL_H

#include "position.h"

s32 GetDirectionTowardsPosition(struct Position *originPos, struct Position *targetPos);
s32 GetChebyshevDistance(struct Position *pos1, struct Position *pos2);

#endif
