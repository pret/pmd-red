#ifndef GUARD_DUNGEON_RANGE_H
#define GUARD_DUNGEON_RANGE_H

#include "position.h"

bool8 IsPositionActuallyInSight(struct Position *pos1, struct Position *pos2);
bool8 IsPositionInSight(struct Position *pos1, struct Position *pos2);
bool8 IsTargetTwoTilesAway(struct Position *pos1, struct Position *pos2);

#endif
