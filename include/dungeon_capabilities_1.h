#ifndef GUARD_DUNGEON_CAPABILITIES_1_H
#define GUARD_DUNGEON_CAPABILITIES_1_H

#include "dungeon_entity.h"

// 0x70C60
bool8 CannotUseItems(struct DungeonEntity *pokemon);
// 0x70CD0
bool8 CannotAct(struct DungeonEntity *pokemon);

#endif
