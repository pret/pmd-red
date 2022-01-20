#ifndef GUARD_STATUS_CHECKS_1_H
#define GUARD_STATUS_CHECKS_1_H

#include "dungeon_entity.h"

// 0x70A58
bool8 HasNegativeStatus(struct DungeonEntity *pokemon);
// 0x70B28
bool8 IsSleeping(struct DungeonEntity *pokemon);

#endif
