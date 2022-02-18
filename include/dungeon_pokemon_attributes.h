#ifndef GUARD_DUNGEON_POKEMON_ATTRIBUTES_H
#define GUARD_DUNGEON_POKEMON_ATTRIBUTES_H

#include "dungeon_entity.h"

// 0x71824
bool8 HasAbility(struct DungeonEntity *pokemon, u8 ability);
// 0x71858
bool8 HasType(struct DungeonEntity *pokemon, u8 type);
// 0x71884
bool8 CanSeeInvisible(struct DungeonEntity *pokemon);
// 0x718AC
bool8 HasTactic(struct DungeonEntity *pokemon, u8 tactic);
// 0x718D8
bool8 HasIQSkill(struct DungeonEntity *pokemon, u8 IQSkill);

void LoadIQSkills(struct DungeonEntity *pokemon);
bool8 CanSeeTeammate(struct DungeonEntity * pokemon);
u8 GetMoveTypeForPokemon(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove);

// 0x71A44
s32 CalculateMovePower(struct DungeonEntity *pokemon, struct PokemonMove *pokeMove);
bool8 ToolboxEnabled(struct DungeonEntityData *pokemon);

#endif
