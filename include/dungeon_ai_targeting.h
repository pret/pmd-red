#ifndef GUARD_DUNGEON_AI_TARGETING_H
#define GUARD_DUNGEON_AI_TARGETING_H

#include "dungeon_entity.h"

bool8 CanAttackInDirection(struct Entity *pokemon, s32 direction);
bool8 CanAIMonsterMoveInDirection(struct Entity *pokemon, s32 direction, bool8 *pokemonInFront);
bool8 IsAtJunction(struct Entity *pokemon);
bool8 ShouldAvoidFirstHit(struct Entity *pokemon, bool8 forceAvoid);
bool8 ShouldMonsterRunAway(struct Entity *pokemon);
bool8 ShouldMonsterRunAwayAndShowEffect(struct Entity *pokemon, bool8 showRunAwayEffect);
void CheckRunAwayVisualFlag(struct Entity *pokemon, bool8 showRunAwayEffect);
u8 CanTarget(struct Entity *pokemon, struct Entity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified);
u8 sub_807167C(struct Entity * pokemon, struct Entity * target);

#endif
