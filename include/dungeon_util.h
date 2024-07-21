#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "structs/dungeon_entity.h"
#include "structs/str_position.h"
#include "structs/str_traps.h"

extern const Position gAdjacentTileOffsets[NUM_DIRECTIONS];

bool8 EntityExists(Entity *pokemon);
u32 GetEntityType(Entity *entity);
u8 GetEntityRoom(Entity *entity);
Trap *GetTrapData(Entity *entity);
Trap* GetTrapData_1(Entity *entity);
Item *GetItemData(Entity *entity);
struct Tile *GetTileAtEntitySafe(Entity *entity);
Item *GetItemData_1(Entity *entity);
void sub_804535C(Entity *entity, Position32 *pos);
void SetEntityPixelPos(Entity *entity, s32 x, s32 y);
void IncreaseEntityPixelPos(Entity *entity, s32 x, s32 y);

#endif
