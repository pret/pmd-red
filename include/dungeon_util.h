#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "dungeon_entity.h"

// 0x450E0
bool8 EntityExists(struct DungeonEntity *pokemon);
// 0x450F8
u32 GetEntityType(struct DungeonEntity *entity);
// 0x45108
struct ItemSlot *GetItemData(struct DungeonEntity *entity);

#endif
