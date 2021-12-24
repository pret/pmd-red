#ifndef GUARD_DUNGEON_POKEMON_ATTRIBUTES_1_H
#define GUARD_DUNGEON_POKEMON_ATTRIBUTES_1_H

#include "dungeon_entity.h"

// 0x71884
bool8 CanSeeInvisible(struct DungeonEntity *pokemon);
// 0x718AC
bool8 HasTactic(struct DungeonEntity *pokemon, u8 tactic);
// 0x718D8
bool8 HasIQSkill(struct DungeonEntity *pokemon, u8 IQSkill);

void LoadIQSkills(struct DungeonEntity *pokemon);
bool8 CanSeeTeammate(struct DungeonEntity * pokemon);
u8 GetMoveType_2(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove);

// 0x71A44
s32 CalculateMovePower(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove);
bool8 ToolboxEnabled(struct DungeonEntityData *pokemon);

#endif
