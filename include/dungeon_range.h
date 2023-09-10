#ifndef GUARD_DUNGEON_RANGE_H
#define GUARD_DUNGEON_RANGE_H

#include "position.h"

bool8 IsPositionActuallyInSight(Position *pos1, Position *pos2);
bool8 IsPositionInSight(Position *pos1, Position *pos2);
bool8 IsTargetTwoTilesAway(Position *pos1, Position *pos2);

#endif
