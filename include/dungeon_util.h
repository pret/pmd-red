#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "structs/dungeon_entity.h"
#include "structs/str_position.h"

extern const Position gAdjacentTileOffsets[NUM_DIRECTIONS];

bool8 EntityExists(Entity *pokemon);
u32 GetEntityType(Entity *entity);
u8 GetEntityRoom(Entity *entity);
EntityInfo *GetTrapData(Entity *entity);
Item *GetItemData(Entity *entity);
struct Tile *GetTileAtEntitySafe(Entity *entity);
Item *GetItemData_1(Entity *entity);

#endif
