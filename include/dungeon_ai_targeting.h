#ifndef GUARD_DUNGEON_AI_TARGETING_H
#define GUARD_DUNGEON_AI_TARGETING_H

#include "structs/dungeon_entity.h"

bool8 CanAttackInDirection(Entity *pokemon, s32 direction);
bool8 CanAIMonsterMoveInDirection(Entity *pokemon, s32 direction, bool8 *pokemonInFront);
bool8 IsAtJunction(Entity *pokemon);
bool8 ShouldAvoidFirstHit(Entity *pokemon, bool8 forceAvoid);
bool8 ShouldMonsterRunAway(Entity *pokemon);
bool8 ShouldMonsterRunAwayAndShowEffect(Entity *pokemon, bool8 showRunAwayEffect);
void CheckRunAwayVisualFlag(Entity *pokemon, bool8 showRunAwayEffect);
u8 CanTarget(Entity *pokemon, Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified);
u8 sub_807167C(Entity * pokemon, Entity * target);

#endif
