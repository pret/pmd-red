#include "global.h"
#include "pokemon.h"

extern struct gPokemon *gMonsterParameters;
extern const char gUnknown_8107600[];
extern const char gUnknown_8107608[];
extern const char gUnownLetters[];
extern const char gUnknown_8107630[];
extern const char gUnknown_8107638[];
extern const char gUnknown_810763C[];

extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);
extern s16 sub_808E770(u32);
extern s32 GetUnownIndex(s32);
extern void sub_80922B4(u8 *, u8 *, s32);

extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);

void CopySpeciesNametoBuffer(u8 * buffer, s16 index)
{
    strncpy(buffer, gMonsterParameters[index].species, 0x14);
}

void CopyYellowSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    ExpandPlaceholdersBuffer(buffer, gUnknown_8107600, gMonsterParameters[new_index].species); // #c6%s#r
}

void CopyCyanSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    ExpandPlaceholdersBuffer(buffer, gUnknown_8107608, gMonsterParameters[new_index].species); // #c5%s#r
}

void sub_808D930(u8 *buffer, s16 index)
{
  char *unownString;
  s32 newIndex;
  s32 unownIndex;
  const char *preload;
  
  newIndex = index;
  if (sub_808E770(newIndex) == SPECIES_UNOWN) {
    preload = gUnknown_8107630; // %s%c
    unownString = GetMonSpecies(SPECIES_UNOWN);
    unownIndex = GetUnownIndex(newIndex);
    ExpandPlaceholdersBuffer(buffer,preload,unownString,gUnownLetters[unownIndex]); // ABCDEFGHIJKLMNOPQRSTUVWXYZ!? 
  }
  else {
    ExpandPlaceholdersBuffer(buffer,gUnknown_8107638, gMonsterParameters[newIndex].species); // %s
  }
}

char * GetMonSpecies(s16 index)
{
    return gMonsterParameters[index].species;
}

void sub_808D9AC(u8 *buffer, struct PokemonStruct *pokemon, s32 colorNum)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, pokemon->name, 10);
  if (colorNum == 0) {
    colorNum = 5;
  }
  ExpandPlaceholdersBuffer(buffer,gUnknown_810763C,colorNum,auStack32); // #c%c%s#r
}

void sub_808D9DC(u8 *buffer, u8 *param_2, s32 colorNum)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, param_2 + 0x58, 10);
  if (colorNum == 0) {
    colorNum = 6;
  }
  ExpandPlaceholdersBuffer(buffer,gUnknown_810763C,colorNum,auStack32); // #c%c%s#r
}

void sub_808DA0C(u8 *buffer, u8 *param_2)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, param_2 + 0x58, 10);
  ExpandPlaceholdersBuffer(buffer,gUnknown_8107638,auStack32); // %s
}

void sub_808DA34(u8 *buffer, struct PokemonStruct *pokemon)
{
  sub_80922B4(buffer, pokemon->name, 10);
}
