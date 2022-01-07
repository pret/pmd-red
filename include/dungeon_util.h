#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "dungeon_entity.h"
#include "position.h"

extern const struct Position gAdjacentTileOffsets[NUM_DIRECTIONS];

// 0x450E0
bool8 EntityExists(struct DungeonEntity *pokemon);
// 0x450F8
u32 GetEntityType(struct DungeonEntity *entity);
// 0x45104
struct DungeonEntityData *GetTrapData(struct DungeonEntity *entity);
// 0x45108
struct ItemSlot *GetItemData(struct DungeonEntity *entity);
struct MapTile *GetMapEntityForDungeonEntity(struct DungeonEntity *entity);

#endif
