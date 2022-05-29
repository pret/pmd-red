#ifndef GUARD_DUNGEON_AI_TARGETING_H
#define GUARD_DUNGEON_AI_TARGETING_H

#include "dungeon_entity.h"

bool8 CanAttackInFront(struct DungeonEntity *pokemon, s32 direction);
bool8 CanMoveForward(struct DungeonEntity *pokemon, s32 facingDir, bool8 *pokemonInFront);
bool8 IsAtJunction(struct DungeonEntity *pokemon);
bool8 ShouldAvoidFirstHit(struct DungeonEntity *pokemon, bool8 forceAvoid);
bool8 ShouldAvoidEnemies(struct DungeonEntity *pokemon);
bool8 ShouldAvoidEnemiesAndShowEffect(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);
void CheckRunAwayVisualFlag(struct DungeonEntity *pokemon, bool8 showRunAwayEffect);
u8 CanTarget(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, bool8 ignoreInvisible, bool8 checkPetrified);
u8 sub_807167C(struct DungeonEntity * pokemon, struct DungeonEntity * target);

#endif
