#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern struct gPokemon *gMonsterParameters;
extern const char gUnknown_8107600[];
extern const char gUnknown_8107608[];
extern const char gUnownLetters[];
extern const char gUnknown_8107630[];
extern const char gUnknown_8107638[];
extern const char gUnknown_810763C[];

extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);
extern s16 sub_808E770(u32);
extern void sub_80922B4(u8 *, u8 *, s32);
extern void sub_808DE50(void* r0, struct PokemonStruct *r1, u32 r2, u32 r3);
extern int sprintf(char *, const char *, ...);

struct unkStruct {
  s16 unk0;
  s16 fill2;
  s32 unk4;
};

extern u8 gUnknown_8107645[12];
extern struct unkStruct gUnknown_8107654[6];
extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gMonsterFileArchive;
extern const char gUnknown_8107684[];
extern struct unkStruct_203B45C *gRecruitedPokemonRef;


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

bool8 sub_808DA44(s32 a1_, u32 a2_) 
{
  // this is the dumbest thing ever, but just making a1 a s16 and
  // a2 a u8 did weird stuff with shifting...
  s32 a1 = (s16)a1_;
  u32 a2 = (u8)a2_;
  if (a2 > 0xc) {
    s32 i;
    struct unkStruct data[6];
    memcpy(data, gUnknown_8107654, 6 * sizeof(struct unkStruct));

    for (i = 0; i < 10 && data[i].unk0; i++) {
      if (data[i].unk0 == a1 && data[i].unk4 == a2) {
        return 1;
      }
    }
    return 0;
  }
  else {
    return gUnknown_8107645[a2];
  }
}

u8 *GetCategoryString(s16 index)
{
    return gMonsterParameters[index].category;
}

u8 GetPokemonSize(s16 index)
{
    return gMonsterParameters[index].size;
}

u8 GetShadowSize(s16 index)
{
    return gMonsterParameters[index].shadow_size;
}

s32 GetMoveSpeed(s16 index)
{
    return gMonsterParameters[index].move_speed;
}

u8 GetWalkableTiles(s16 index)
{
    return gMonsterParameters[index].walkable_tiles;
}

u8 GetUnk1B(s16 index)
{
    return ((u8)(gMonsterParameters[index].unk1B) << 25) >> 24;
}

bool8 GetIsMoving(s16 index)
{
    return gMonsterParameters[index].isMoving;
}

u8 GetUnk1D(s16 index)
{
    return gMonsterParameters[index].unk1D;
}

u16 GetLowKickDmg(s16 index)
{
    return gMonsterParameters[index].lowkick_dmg;
}

u16 GetSizeOrbDmg(s16 index)
{
    return gMonsterParameters[index].sizeorb_dmg;
}

u8 GetFriendArea(s16 index)
{
    return gMonsterParameters[index].friend_area;
}

u16 GetBaseHP(s16 index)
{
    return gMonsterParameters[index].base_hp;
}

bool8 GetUnk33(s16 index)
{
    return gMonsterParameters[index].unk33;
}

u8 GetUnk12(s16 index)
{
    return gMonsterParameters[index].unk12;
}

s16 GetPokemonEvolveFrom(s16 index)
{
    return gMonsterParameters[index].pre.evolve_from;
}

u16 GetPokemonAttSpatt(s16 index, u32 r1)
{
    return gMonsterParameters[index].base_att_spatt[r1];
}

u16 GetPokemonDefSpdef(s16 index, u32 r1)
{
    return gMonsterParameters[index].base_def_spdef[r1];
}

u8 GetPokemonType(s32 index, u32 typeIndex)
{
    s16 newIndex = index;
    return gMonsterParameters[newIndex].types[typeIndex];
}

u8 GetPokemonAbility(s16 index, u32 abilityIndex)
{
    return gMonsterParameters[index].abilities[abilityIndex];
}

s16 GetDexInternalNo(s16 index, u32 r1)
{
    return gMonsterParameters[index].dexInternal[r1];
}

s16 GetBaseRecruit(s16 index)
{
    return gMonsterParameters[index].base_recruit;
}

s16 GetAlphabetParentNo(s16 index, s32 r1)
{
    return gMonsterParameters[index].alphabetParent[r1];
}


s16 GetInternalNo(s16 index)
{
    return gMonsterParameters[index].dexInternal[1];
}

s32 CalculateEXPGain(s16 index, s32 level)
{
    s32 baseEXP = gMonsterParameters[index].base_exp;
    return baseEXP + (baseEXP * (level - 1)) / 10;
}

s16 GetPokemonEvolveConditions(s16 index, struct unkEvolve *r1)
{
    struct EvolveStruct1 temp2;
    struct EvolveNeeds temp1;
    temp1 = gMonsterParameters[index].need;
    temp2 = gMonsterParameters[index].pre;
    r1->conditions = temp2;
    r1->needs = temp1;
    // The return value is not used anywhere, but necessary for the function to match.
    return index;
}

u8 GetPokemonOverworldPalette(s16 index, u32 r1)
{
    // Had to have this cast to match
    u32 temp;
    temp = index;
    if (r1 != 0)
    {
        return 10;
    }
    else 
    {
        return gMonsterParameters[temp].overworld_palette;
    }
}

struct OpenedFile *OpenPokemonDialogueSpriteFile(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[index].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, index); // "kao%03d"
    return OpenFile(buffer, &gMonsterFileArchive);
}

struct OpenedFile *GetDialogueSpriteDataPtr(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[index].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, index); // "kao%03d"
    return OpenFileAndGetFileDataPtr(buffer, &gMonsterFileArchive);
}

bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 r1)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[index].dialogue_sprites >> r1) & 1;
}

void sub_808DE30(void* r0, u32 r1)
{
    sub_808DE50(r0, &gRecruitedPokemonRef->pokemon[r1], r1, r1 * sizeof(struct PokemonStruct));
}