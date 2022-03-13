#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "dungeon_entity.h"
#include "position.h"

extern const struct Position gAdjacentTileOffsets[NUM_DIRECTIONS];

bool8 EntityExists(struct DungeonEntity *pokemon);
u32 GetEntityType(struct DungeonEntity *entity);
u8 GetEntityRoomIndex(struct DungeonEntity *entity);
struct DungeonEntityData *GetTrapData(struct DungeonEntity *entity);
struct ItemSlot *GetItemData(struct DungeonEntity *entity);
struct MapTile *GetMapTileForDungeonEntity_2(struct DungeonEntity *entity);

#endif
