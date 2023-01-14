#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "dungeon_entity.h"
#include "position.h"

extern const struct Position gAdjacentTileOffsets[NUM_DIRECTIONS];

bool8 EntityExists(struct Entity *pokemon);
u32 GetEntityType(struct Entity *entity);
u8 GetEntityRoom(struct Entity *entity);
struct EntityInfo *GetTrapData(struct Entity *entity);
struct Item *GetItemData(struct Entity *entity);
struct Tile *GetTileAtEntitySafe(struct Entity *entity);
struct Item *GetItemData_1(struct Entity *entity);

#endif
