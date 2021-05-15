#include "global.h"
#include "pokemon.h"
#include "constants/species.h"

extern struct gPokemon *gMonsterParameters;
extern const char gUnknown_8107600[];
extern const char gUnknown_8107608[];
extern const char gUnownLetters[];
extern const char gUnknown_8107630[];
extern const char gUnknown_8107638[];
extern const char gUnknown_810763C[];

extern void sub_800D158(u8 *buffer, const char *r2, ...);
extern s16 sub_808E770(u32);
extern s32 GetUnownIndex(s32);
extern void sub_80922B4(u8 *, u8 *, s32);

extern void sub_800D158(u8 *buffer, const char *r2, ...);

void CopySpeciesNametoBuffer(u8 * buffer, s16 index)
{
    strncpy(buffer, gMonsterParameters[index].species, 0x14);
}

void CopyYellowSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    sub_800D158(buffer, gUnknown_8107600, gMonsterParameters[new_index].species); // #c6%s#r
}

void CopyCyanSpeciesNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    sub_800D158(buffer, gUnknown_8107608, gMonsterParameters[new_index].species); // #c5%s#r
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
    sub_800D158(buffer,preload,unownString,gUnownLetters[unownIndex]); // ABCDEFGHIJKLMNOPQRSTUVWXYZ!? 
  }
  else {
    sub_800D158(buffer,gUnknown_8107638, gMonsterParameters[newIndex].species); // %s
  }
}

char * GetMonSpecies(s16 index)
{
    return gMonsterParameters[index].species;
}

void sub_808D9AC(u8 *param_1, u8 *param_2, s32 param_3)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, param_2 + 0x4c, 10);
  if (param_3 == 0) {
    param_3 = 5;
  }
  sub_800D158(param_1,gUnknown_810763C,param_3,auStack32); // #c%c%s#r
}

void sub_808D9DC(u8 *param_1, u8 *param_2, s32 param_3)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, param_2 + 0x58, 10);
  if (param_3 == 0) {
    param_3 = 6;
  }
  sub_800D158(param_1,gUnknown_810763C,param_3,auStack32); // #c%c%s#r
}

void sub_808DA0C(u8 *param_1, u8 *param_2)
{
  u8 auStack32 [20];

  sub_80922B4(auStack32, param_2 + 0x58, 10);
  sub_800D158(param_1,gUnknown_8107638,auStack32); // %s
}

void sub_808DA34(u8 *param_1, u8 *param_2)
{
  sub_80922B4(param_1, param_2 + 0x4c, 10);
}
