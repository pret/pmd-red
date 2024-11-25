#ifndef GUARD_POKEMON_MID_H
#define GUARD_POKEMON_MID_H

#include "pokemon.h"

bool8 ComparePokemonNames(s16, s16);
void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);
void PrintPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon);
void GetPokemonLevelData(LevelData* a1, s32 _id, s32 level);
const u8* DecompressMoveID(const u8* a1, u16* moveID);

bool8 sub_808DA44(s32, u32);

#endif // GUARD_POKEMON_MID_H
