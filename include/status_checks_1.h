#ifndef GUARD_STATUS_CHECKS_1_H
#define GUARD_STATUS_CHECKS_1_H

#include "dungeon_entity.h"

bool8 HasNegativeStatus(struct DungeonEntity *pokemon);
bool8 IsSleeping(struct DungeonEntity *pokemon);
bool8 HasQuarterHPOrLess(struct DungeonEntity* pokemon);

#endif
