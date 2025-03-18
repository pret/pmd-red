#ifndef GUARD_CODE_8041AD0_H
#define GUARD_CODE_8041AD0_H

#include "structs/dungeon_entity.h"
#include "structs/str_damage.h"

u32 EntityGetStatusSprites(Entity *entity);
void sub_80420E8(Entity *pokemon, DamageStruct *dmgStruct);
void sub_80421C0(Entity *pokemon, u16);

#endif // GUARD_CODE_8041AD0_H