#include "global.h"
#include "pokemon.h"

extern s16 gUnknown_80E8126[];

extern struct PokemonStruct *GetPlayerPokemonStruct(void);
extern struct PokemonStruct *sub_808D378(void);

extern bool8 sub_803C0DC(s16);
extern bool8 sub_8098134(s16);
extern s16 GetBaseSpecies(s16);
extern bool8 sub_80023E4(u32);

bool8 sub_803C110(s16 index)
{
  struct PokemonStruct *pokeStruct;
  s16 *psVar5;
  s16 *psVar6;
  s32 species_s32;
  
  species_s32 = (s32)index;
  if ((!sub_8098134(index)) || (index != GetBaseSpecies(index)) || (!sub_803C0DC(index))) {
    return FALSE;
  }
  else {
    if (!sub_80023E4(6)) {
      psVar5 = &gUnknown_80E8126[0];
      if (*psVar5 != 0) {
        psVar6 = &gUnknown_80E8126[0];
        do {
          if (*psVar6 == species_s32) return FALSE;
          psVar5++;
          psVar6++;
        } while (*psVar5 != SPECIES_NONE);
      }
      pokeStruct = GetPlayerPokemonStruct();
      if ((pokeStruct->speciesNum == species_s32) ||
         (pokeStruct = sub_808D378(), pokeStruct->speciesNum == species_s32)) return FALSE;
    }
    return TRUE;
  }
}
