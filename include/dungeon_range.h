#ifndef GUARD_DUNGEON_RANGE_H
#define GUARD_DUNGEON_RANGE_H

#include "structs/str_position.h"

bool8 IsPositionActuallyInSight(DungeonPos *pos1, DungeonPos *pos2);
bool8 IsPositionInSight(DungeonPos *pos1, DungeonPos *pos2);
bool8 IsTargetTwoTilesAway(DungeonPos *pos1, DungeonPos *pos2);

#endif
