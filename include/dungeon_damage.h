#ifndef GUARD_DUNGEON_DAMAGE_H
#define GUARD_DUNGEON_DAMAGE_H

#include "structs/dungeon_entity.h"
#include "structs/str_damage.h"

void HandleDealingDamage(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 arg4, bool32 arg8, s32 argC);
s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType);
void CalcDamage(Entity *attacker, Entity *target, u8 moveType, s32 movePower, s32 critChance, struct DamageStruct *dmgStruct, s24_8 arg8, u16 moveId, bool8 arg_10);
void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct);
void DealDamageToEntity(Entity *entity, s32 dmg, s32 r6, s32 r4);

#endif
