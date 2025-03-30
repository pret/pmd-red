#ifndef GUARD_DUNGEON_UTIL_H
#define GUARD_DUNGEON_UTIL_H

#include "constants/direction.h"
#include "structs/dungeon_entity.h"
#include "structs/str_position.h"
#include "structs/str_traps.h"
#include "structs/map.h"

extern const DungeonPos gAdjacentTileOffsets[NUM_DIRECTIONS];

bool8 EntityIsValid(Entity *pokemon);
u32 GetEntityType(Entity *entity);
u8 GetEntityRoom(Entity *entity);
Tile *GetTileAtEntitySafe(Entity *entity);
void sub_804535C(Entity *entity, PixelPos *pos);
void SetEntityPixelPos(Entity *entity, s32 x, s32 y);
void IncreaseEntityPixelPos(Entity *entity, s32 x, s32 y);

static inline EntityInfo *GetEntInfo(Entity *entity)
{
    return entity->axObj.info.monster;
}
Item *GetItemData(Entity *entity);
Item *GetItemData_1(Entity *entity);
Trap *GetTrapData(Entity *entity);
Trap* GetTrapData_1(Entity *entity);

Entity *SpawnTrap(u8 trapID, DungeonPos *pos, u8 c);
Entity *sub_8045708(DungeonPos *pos);
void sub_80457DC(Entity* ent);

#endif // GUARD_DUNGEON_UTIL_H
