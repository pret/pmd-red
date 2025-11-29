#ifndef GUARD_DUNGEON_ENTITY_MOVEMENT_H
#define GUARD_DUNGEON_ENTITY_MOVEMENT_H

#include "structs/dungeon_entity.h"
#include "structs/str_position.h"

void sub_8074FB0(Entity *entity, s32 a1, DungeonPos *pos);
bool8 DisplayActions_Async(Entity *a0);
void sub_8075680(bool8 unused);
bool8 CheckEntityTileForInteraction(Entity *entity);
void TryTriggerMonsterHouseWithMsg_Async(Entity *pokemon, bool8 forcedMonsterHouse);

#endif
