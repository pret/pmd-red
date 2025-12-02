#ifndef GUARD_DUNGEON_DAMAGE_H
#define GUARD_DUNGEON_DAMAGE_H

#include "structs/dungeon_entity.h"
#include "structs/str_damage.h"

void HandleDealingDamage_Async(Entity *attacker, Entity *target, struct DamageStruct *dmgStruct, bool32 isFalseSwipe, bool32 giveExp, s16 dungeonExitReason, bool32 arg8, s32 argC);
s32 WeightWeakTypePicker(Entity *user, Entity *target, u8 moveType);
void CalcDamage(Entity *attacker, Entity *target, u8 moveType, s32 movePower, s32 critChance, struct DamageStruct *dmgStruct, s24_8 arg8, u16 moveId, bool8 arg_10);
void sub_806F2BC(Entity *attacker, Entity *target, u8 moveType, s32 a2, struct DamageStruct *dmgStruct);
void DealDamageToEntity_Async(Entity *entity, s32 dmg, s32 residualDmgType, s32 dungeonExitReason);
void sub_806F370_Async(Entity *pokemon, Entity *target, s32 dmg, s32 giveExp, bool8 *tookNoDamage, u8 moveType, s16 dungeonExitReason, s32 residualDmgType, s32 arg_10, s32 arg_14);
void SetShopkeeperAggression(Entity *pokemon, Entity *target);
void sub_806F480(Entity *pokemon, bool8 attackEnemies);
u8 sub_806F4A4(Entity *pokemon, u8 type);
s32 sub_806F62C(s32 param_1);

#endif
