#ifndef GUARD_DUNGEON_LEVELING_H
#define GUARD_DUNGEON_LEVELING_H

#include "structs/dungeon_entity.h"

void AddExpPoints(Entity *pokemon, Entity *target, s32 exp);
void EnemyEvolution(Entity *entity);
void LevelUpTarget(Entity *pokemon, Entity *target, s32 level, u8 param_4, u8 param_5);
void LevelDownTarget(Entity *pokemon, Entity *target, u32 level);
bool8 sub_8072938(Entity *target, u16 moveId);
void sub_8072AC8(s16 *param_1, s32 species, s32 param_3);

#endif
