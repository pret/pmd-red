#include "global.h"
#include "pokemon.h"
#include "item.h"
#include "file_system.h"

extern struct gPokemon *gMonsterParameters;
extern const char gUnknown_8107600[];
extern const char gUnknown_8107608[];
extern const char gUnownLetters[];
extern const char gUnknown_8107630[];
extern const char gUnknown_8107638[];
extern const char gUnknown_810763C[];
extern const char gUnknown_810768C[];  // lvmp%03d\0
extern struct FileArchive gSystemFileArchive;
extern s16 gUnknown_810ACB8;  // 0x14d
extern s16 gUnknown_810ACBA;  // 0x14d
extern s16 gUnknown_810ACBC;  // 0x14d
extern s16 gUnknown_810ACBE;  // 0x14d

// wram data:
extern u16 gLevelCurrentPokeId;
extern struct LevelData gLevelCurrentData[];


extern void ExpandPlaceholdersBuffer(u8 *buffer, const char *r2, ...);
extern s16 GetBaseSpecies(u32);
extern void sub_80922B4(u8 *, u8 *, s32);
extern int sprintf(char *, const char *, ...);
extern u32 ReturnIntFromChar(u8 r0);
extern void CopyStringtoBuffer(char *r0, char *r1);
extern void sub_8093F50(void*, void*);
extern void sub_80943A0(void*, s32);
extern void xxx_unk_to_pokemonstruct_808DF44(struct PokemonStruct*, struct unkStruct_808DE50*);
extern u8* sub_8092B18(s16);
extern u8* sub_808E07C(u8* a1, u16* a2);
extern u8* sub_8092B54(s32);

struct unkStruct_8107654 {
  s16 unk0;
  s16 fill2;
  s32 unk4;
};

extern u8 gUnknown_8107645[12];
extern struct unkStruct_8107654 gUnknown_8107654[6];
extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gMonsterFileArchive;
extern const char gUnknown_8107684[];
extern struct unkStruct_203B45C *gRecruitedPokemonRef;

// bool8 sub_808D750(s16 index_) {
//     s32 i;
//     register s32 index asm("r8") = index_;
//     s32 count = 0;
//     s32 size_count = 0;

//     for (i = 0; i < 413; i++) {
//         register struct PokemonStruct* pokemon = &i[gRecruitedPokemonRef->pokemon];
//         register u16 unk0 = pokemon->unk0;
//         if ((unk0 & 1) && ((pokemon->unk0 >> 1) & 1)) {
//             size_count += GetPokemonSize(pokemon->speciesNum);
//             count++;
//         }
//     }

//     if (count < 4) {
//         struct PokemonStruct* pokemon;

//         pokemon = &gRecruitedPokemonRef->pokemon[index];

//         size_count += GetPokemonSize(pokemon->speciesNum);
//         if (size_count < 7) {
//             return TRUE;
//         }
//     }
//     return FALSE;
// }


void PeekPokemonItem(s16 index_, struct HeldItem* item) {
    s32 index = index_;
    struct PokemonStruct* pokemon = &gRecruitedPokemonRef->pokemon[index];
    item->itemIndex = pokemon->heldItem.itemIndex;
    item->numItems = pokemon->heldItem.numItems;
}

void GivePokemonItem(s16 index_, struct HeldItem* item) {
    s32 index = index_;
    struct PokemonStruct* pokemon = &gRecruitedPokemonRef->pokemon[index];
    pokemon->heldItem.itemIndex = item->itemIndex;
    pokemon->heldItem.numItems = item->numItems;
}

bool8 IsPokemonRenamed(struct PokemonStruct* pokemon) {
    char species_name[20];
    char* species = GetMonSpecies(pokemon->speciesNum);
    s32 i;
    CopyStringtoBuffer(species_name, species);
    for (i = 0; i < 10; i++) {
        if (pokemon->name[i] != species_name[i]) {
            return FALSE;
        }
        if (!pokemon->name[i]) {
            return TRUE;
        }
    }
    return TRUE;
}

bool8 ComparePokemonNames(s16 a1, s16 a2) {
    s32 index1 = a1;
    s32 index2 = a2;
    u8* name1 = gRecruitedPokemonRef->pokemon[index1].name;
    u8* name2 = gRecruitedPokemonRef->pokemon[index2].name;

    s32 i;
    for (i = 0; i < 10; i++) {
        s32 c1 = ReturnIntFromChar(*name1);
        s32 c2 = ReturnIntFromChar(*name2);
        if (c1 > c2) {
            return TRUE;
        }
        if (c1 < c2) {
            return FALSE;
        }
        name1++;
        name2++;
    }
    return FALSE;
}

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
  if (GetBaseSpecies(newIndex) == SPECIES_UNOWN) {
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
    struct unkStruct_8107654 data[6];
    memcpy(data, gUnknown_8107654, 6 * sizeof(struct unkStruct_8107654));

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

void xxx_pokemonstruct_index_to_unk_808DE30(void* r0, u32 r1)
{
    xxx_pokemonstruct_to_unk_808DE50(r0, &gRecruitedPokemonRef->pokemon[r1], r1);
}

void xxx_pokemonstruct_to_unk_808DE50(struct unkStruct_808DE50 * a1, struct PokemonStruct *pokemon, s32 a3)
{
    s32 i;
    struct HeldItem* held;
    struct ItemSlot* slot;
    u32 somestruct_80943A0;
    u32 somestruct2_80943A0;

    a1->unk0 = pokemon->unk0;
    a1->unk3 = pokemon->unk3;
    a1->IQ = pokemon->IQ;
    a1->unk4C = pokemon->unk20;
    sub_808E6F4(&a1->unk54);
    a1->unk4 = pokemon->unk4;
    a1->unk2 = pokemon->unk2;
    a1->unkA = a3;
    a1->speciesNum = pokemon->speciesNum;
    a1->unk50 = pokemon->unk24;
    a1->unk12 = pokemon->pokeHP;
    a1->unk10 = pokemon->pokeHP;

    for (i = 0; i < 2; i++) {
        a1->offense.att[i] = pokemon->offense.att[i];
        a1->offense.def[i] = pokemon->offense.def[i];
    }

    a1->unk18 = pokemon->unk1C;
    sub_8093F50(&a1->unk1C, &pokemon->unk2C);

    for (i = 0; i < 10; i++) {
        a1->name[i] = pokemon->name[i];
    }
    
    held = &pokemon->heldItem;
    slot = &a1->itemSlot;

    if ((u32)(-held->itemIndex | held->itemIndex) >> 31) {
        HeldItemToSlot(slot, held);
    }
    else {
        slot->itemIndex = 0;
        slot->numItems = 0;
        slot->unk0 = 0;
    }  
  sub_80943A0(&somestruct_80943A0, 100);
  a1->unk44 = somestruct_80943A0;
  sub_80943A0(&somestruct2_80943A0, 100);
  a1->unk48 = somestruct2_80943A0;
}

void xxx_unk_to_pokemonstruct_index_808DF2C(s32 a1, struct unkStruct_808DE50* a2)
{
    xxx_unk_to_pokemonstruct_808DF44(&a1[gRecruitedPokemonRef->pokemon], a2);
}

extern void sub_8093FA8(struct unkPokeSubStruct_2C*, struct unkPokeSubStruct_2C*);


void xxx_unk_to_pokemonstruct_808DF44(struct PokemonStruct* pokemon, struct unkStruct_808DE50* a2)
{
    s32 i;

    pokemon->unk0 = a2->unk0;
    pokemon->unk3 = a2->unk3;
    pokemon->IQ = a2->IQ;
    pokemon->unk20 = a2->unk4C;
    pokemon->unk4 = a2->unk4;
    pokemon->unk2 = a2->unk2;
    pokemon->speciesNum = a2->speciesNum;
    pokemon->unk24 = a2->unk50;
    pokemon->pokeHP = a2->unk12;

    for (i = 0; i < 2; i++) {
        pokemon->offense.att[i] = a2->offense.att[i];
        pokemon->offense.def[i] = a2->offense.def[i];
    }

    pokemon->unk1C = a2->unk18;
    sub_8093FA8(pokemon->unk2C, a2->unk1C);

    for (i = 0; i < 10; i++) {
        pokemon->name[i] = a2->name[i];
    }

    if (a2->itemSlot.unk0 & 1) {
        SlotToHeldItem(&pokemon->heldItem, &a2->itemSlot);
    }
    else {
        pokemon->heldItem.itemIndex = 0;
    }
}

void sub_808DFDC(s32 a1, struct unkStruct_808DE50* a2)
{
    // transfer item from unk to pokemon at index
    struct PokemonStruct* pokemon = &gRecruitedPokemonRef->pokemon[a1];
    if (a2->itemSlot.unk0 & 1) {    
        SlotToHeldItem(&pokemon->heldItem, &a2->itemSlot);
    }
    else {
        pokemon->heldItem.itemIndex = 0;
    }
}

void GetPokemonLevelData(struct LevelData* a1, s16 _id, s32 a3)
{
  u8 buffer[12];
  s32 id = _id;

  if ((s16)gLevelCurrentPokeId != id)
  {
    struct OpenedFile *file;

    gLevelCurrentPokeId = id;
    // lvmp%03d\0
    sprintf(buffer, gUnknown_810768C, id);
    file = OpenFileAndGetFileDataPtr(buffer, &gSystemFileArchive);
    DecompressATFile((char*)gLevelCurrentData, 0, file);
    CloseFile(file);
  }
  a3 -= 1;
  if ( a3 < 0 )
    a3 = 0;

   *a1 = gLevelCurrentData[a3];
}

u8* sub_808E07C(u8* a1, u16* a2)
{
    u32 r1 = *a1++;
    u32 r3;
    if (r1 & 0x80) {
        r3 = *a1++;
    }
    else {
        r3 = r1;
        r1 = 0;
    }
#ifdef NONMATCHING
    // wrong order
    r1 &= 0x7f;
    r3 &= 0x7f;
    *a2 = (r1 << 7) | r3;
#else
    {
        register u32 mask asm("r0") = 0x7f;
        r3 &= mask;
        r1 &= mask;
        *a2 = (r1 << 7) | r3;
    }
#endif
    return a1;
}

s32 sub_808E0AC(u16* a1, s16 species, s32 a3, s32 a4)
{
  u8* stream;
  u16 result;  // struct?
  s32 count;
  register s32 _species asm("r2");  // weird regalloc
  
  _species = (s16)species;
  count = 0;

  if (species == SPECIES_DECOY) return 0;
  if (species == SPECIES_NONE) return 0;
  if (species == SPECIES_MUNCHLAX) return 0;
  // get stream
  stream = sub_8092B18(_species);

  while (*stream)
  {
    u8 v12;

    // read from stream
    stream = sub_808E07C(stream, &result);
    v12 = *stream++;

    if (v12 > a3)
      break;
    if (v12 == a3) {
      bool8 cond = 1;
      // I don't think these are species IDs
      // the pokemon they would correspond to are pretty random if they are
      // shuckle, heracross, pupitar, vibrava
      if ((result == 238) && (a4 < gUnknown_810ACB8)) cond = 0;
      if ((result == 239) && (a4 < gUnknown_810ACBA)) cond = 0;
      if ((result == 272) && (a4 < gUnknown_810ACBC)) cond = 0;
      if ((result == 354) && (a4 < gUnknown_810ACBE)) cond = 0;

      if (cond) {
        if (count < 16) {
          *a1++ = result;
          ++count;
        }
      }
    }
  }
  return count;
}

bool8 sub_808E190(u16 a1, s16 _species) 
{
  u16 result;
  u16 result2;
  s32 species = _species;  // r4
  u8* ptr;
  
  if (species == SPECIES_DECOY) return 0;
  if (species == SPECIES_NONE) return 0;
  if (species == SPECIES_MUNCHLAX) return 0;
  if (a1 == 352) return 0;

  ptr = sub_8092B18(species);
  while (*ptr) {
    ptr = sub_808E07C(ptr, &result);
    ptr++;
    if (a1 == result) {
      return 1;
    }
  }

  ptr = sub_8092B54(species);
  while (*ptr) {
    ptr = sub_808E07C(ptr, &result2);
    if (result2 == a1) {
      return 1;
    }
  }
  return 0;
}


s32 sub_808E218(struct unkStruct_808E218_arg* a1, struct PokemonStruct* pokemon) 
{
  s32 i;
  s32 count;
  struct unkStruct_808E218 data;  // LevelData?
  s32 limit;

  count = 0;
  a1->count = 0;
  if (pokemon->speciesNum == SPECIES_DECOY) return 0;
  if (pokemon->speciesNum == SPECIES_NONE) return 0;
  if (pokemon->speciesNum == SPECIES_MUNCHLAX) return 0;

  limit = sub_808E3B8(pokemon, &data);
  for (i = 0; i < limit; i++) {
    u8* ptr;
    u16 result;

    ptr = sub_8092B18(data.unk0[i].unk0);
    while (*ptr) {
      s32 value;
      ptr = sub_808E07C(ptr, &result);
      value = *ptr++;

      if (value > data.unk0[i].unk2) {
        break;
      }

      if (count < 413) {
        s32 j;
        bool8 cond = 1;
        // I don't think these are species IDs
        // the pokemon they would correspond to are pretty random if they are
        // shuckle, heracross, pupitar, vibrava
        if ((result == 238) && (pokemon->IQ < gUnknown_810ACB8)) cond = 0;
        if ((result == 239) && (pokemon->IQ < gUnknown_810ACBA)) cond = 0;
        if ((result == 272) && (pokemon->IQ < gUnknown_810ACBC)) cond = 0;
        if ((result == 354) && (pokemon->IQ < gUnknown_810ACBE)) cond = 0;

        for (j = 0; j < 4; j++) {
          if ((pokemon->unk2C[j].unk0 & 1) && pokemon->unk2C[j].unk2 == result) {
            cond = 0;
          }
        }

        if (cond) {
          s32 k;
          for (k = 0; k < count && a1->unk0[k] != result; k++) {}

          if (k == count) {
            a1->unk0[count++] = result;
          }
        }
      }
    }
  }

  a1->count = count;
  return count;
}


s32 sub_808E3B8(struct PokemonStruct* pokemon, struct unkStruct_808E218* a2) 
{
  s32 count;
  s32 species;
  s32 i;
  struct unkStruct_808E6F4* stage;
  u8* has_next_stage;

  a2->unk0[0].unk0 = pokemon->speciesNum;
  a2->unk0[0].unk2 = pokemon->unk3;

  count = 1;
  species = pokemon->speciesNum;
  i = 0;
  has_next_stage = &pokemon->unkC;
  stage = &a2->unk0[1];

  for (; i < 2; i++) {
      if (!*has_next_stage) {
          break;
      }
      species = GetPokemonEvolveFrom(species);
      if (!species) {
          break;
      }
      stage->unk0 = species;
      stage->unk2 = *has_next_stage;
      stage++;
      count++;
      has_next_stage += 4;
  }
  return count;
}