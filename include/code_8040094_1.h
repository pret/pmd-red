#ifndef GUARD_CODE_8040094_1_H
#define GUARD_CODE_8040094_1_H

#include "structs/dungeon_entity.h"

u16 GetEffectiveMoveId(u16 moveId, u8 weather, bool32 hasSpecialEffect);

bool8 sub_8040BB0(Entity *entity, Move *move, bool8 a2);
void sub_8040DA0(Entity *entity, Move *move);
void sub_8041168(Entity *entity, Entity *entity2, Move *move, DungeonPos *pos);

#endif // GUARD_CODE_8040094_1_H
