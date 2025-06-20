#ifndef GUARD_DUNGEON_SPAWNS_H
#define GUARD_DUNGEON_SPAWNS_H

#include "structs/str_spawn_pokemon_data.h"

void sub_803D4AC(void);
void SetFloorItemMonsterSpawns(void);
u8 GetRandomFloorTrap(void);
u8 GetRandomFloorItem(s32 spawnType);
s32 SetMonsterSpawnsArray(SpawnPokemonData *strPtr, s32 id);
s32 GetAvailableMonsToTransform(SpawnPokemonData *strPtr, s32 id);
void SetCurrentMonsterSpawns(void);
bool8 CanMonsterBeSpawnedHere(s16 speciesToFind);
s16 GetRandomFloorMonsterId(s32 arrId);
s32 GetSpawnedMonsterLevel(s32 species);

#endif // GUARD_DUNGEON_SPAWNS_H
