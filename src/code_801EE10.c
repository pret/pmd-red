#include "global.h"
#include "code_800D090.h"
#include "pokemon.h"
#include "input.h"
#include "memory.h"
#include "text.h"

struct unkStruct_203B2AC
{
    u8 unk0[0x1E];
    s16 unk1E;
    s16 unk20;
    u8 unk22[0x34 - 0x22];
    u32 unk34[3];
    u8 unk40[0x48 - 0x40];
    s16 speciesNum;
    u32 unk4C;
    u8 unk50[0xB0 - 0x50];
    u32 unkB0;
    u8 fillB4[0xE0 - 0xB4];
    u32 unkE0;
    struct UnkTextStruct2 *unkE4;
    struct UnkTextStruct2 unkE8[4];
    u8 unk148[4];
};
extern struct unkStruct_203B2AC *gUnknown_203B2AC;

struct unkStruct_3001B60
{
    u32 unk0;
    u32 sortMethod;
    u32 unk8;
    u32 unkC;
    u32 unk10;
    u8 fill14[0x18 - 0x14];
    s16 unk18;
    s16 unk1A[2];
    u8 fill1C[0x370 - 0x1E];
    s16 unk370;
    s16 unk372;
    s16 unk374;
    s16 unk376;
};

extern struct unkStruct_3001B60 *gUnknown_3001B60;

extern struct UnkTextStruct2 gUnknown_80DC9B0;
extern struct UnkTextStruct2 gUnknown_80DC9C8;

extern void sub_8013818(void *, u32, u32, u32);
extern bool8 sub_80023E4(u32);
extern void sub_808FF20(u32 *, struct PokemonStruct *, bool8);
extern void CreatePokemonInfoTabScreen(u32, s16, u32 *, u32 *, u32);
extern s32 GetKeyPress(void *);
extern bool8 sub_8013938(void *);
extern void sub_802452C(void);
extern void PlayMenuSoundEffect(u32);
extern void sub_8013984(void *);
void sub_80922B4(u8 *buffer, u8 *string, s32 size);
bool8 ComparePokemonNames(s16 a1, s16 a2);

void sub_8024588(void);
void sub_80245D0(void);
void sub_8024604(void);

extern u8 gUnknown_80DC9A4[];

void SortbyInternalNo(s32 param_1, s32 param_2);
void SortbyAlphabetNo(s32 param_1,s32 param_2);
void SortbyName(s32 param_1,s32 param_2);

bool8 sub_8024184(struct PokemonStruct *pokemon, u8 area)
{
    if(area == GetFriendArea(pokemon->speciesNum))
        return TRUE;
    else
        return FALSE;
}

void sub_80241A8(void)
{
  switch(gUnknown_3001B60->sortMethod)
  {
    case 2:
        if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10) {
            SortbyAlphabetNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);
        }
        if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8) {
            SortbyAlphabetNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
        }
        break;
    case 3:
        if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10) {
            SortbyName(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);
        }
        if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8) {
            SortbyName(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
        }
        break;
    case 1:
        if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10) {
            SortbyInternalNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);
        }
        if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8) {
            SortbyInternalNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
        }
        break;
  }
}


void SortbyInternalNo(s32 param_1, s32 param_2)
{
  s16 *r4;
  s32 iVar4;
  s16 *r10;
  s16 *r5;
  s32 r6;
  s32 r1;
  s32 r7;
  s32 r9;

  r10 = &gUnknown_3001B60->unk18 + param_2;
  r7 = param_1;
  r1 = param_2 - 1;
  if (r7 < r1) {
    r9 = r1;
    do {
      r4 = r10;
      r6 = r1;
      iVar4 = r7 + 1;
      for (; r6 > r7; r6--) {
        if (GetInternalNo(gRecruitedPokemonRef->pokemon[r5 = r4 - 1, *r5].speciesNum) > GetInternalNo(gRecruitedPokemonRef->pokemon[*r4].speciesNum)) {
          r1 = *r4;
          *r4 = *r5;
          *r5 = r1;
        }
        r4 = r5;
      }
      r7 = iVar4;
      r1 = r9;
    } while (iVar4 < r1);
  }
}

void SortbyAlphabetNo(s32 param_1,s32 param_2)
{
  s16 *r4;
  s32 iVar4;
  s16 *r10;
  s16 *r5;
  s32 r6;
  s32 r1;
  s32 r7;
  s32 r9;

  r10 = &gUnknown_3001B60->unk18 + param_2;
  r7 = param_1;
  r1 = param_2 - 1;
  if (r7 < r1) {
    r9 = r1;
    do {
      r4 = r10;
      r6 = r1;
      iVar4 = r7 + 1;
      for (; r6 > r7; r6--) {
        if (GetAlphabetParentNo(gRecruitedPokemonRef->pokemon[r5 = r4 - 1, *r5].speciesNum, 0) > GetAlphabetParentNo(gRecruitedPokemonRef->pokemon[*r4].speciesNum, 0)) {
          r1 = *r4;
          *r4 = *r5;
          *r5 = r1;
        }
        r4 = r5;
      }
      r7 = iVar4;
      r1 = r9;
    } while (iVar4 < r1);
  }
}

void SortbyName(s32 param_1,s32 param_2)
{
  s16 *r4;
  s32 iVar4;
  s16 *r10;
  s16 *r5;
  s32 r6;
  s32 r1;
  s32 r7;
  s32 r9;

  r10 = &gUnknown_3001B60->unk18 + param_2;
  r7 = param_1;
  r1 = param_2 - 1;
  if (r7 < r1) {
    r9 = r1;
    do {
      r4 = r10;
      r6 = r1;
      iVar4 = r7 + 1;
      for (; r6 > r7; r6--) {
        r5 = r4 - 1;
        if (ComparePokemonNames(*r5, *r4)) {
          r1 = *r4;
          *r4 = *r5;
          *r5 = r1;
        }
        r4 = r5;
      }
      r7 = iVar4;
      r1 = r9;
    } while (iVar4 < r1);
  }
}

struct PokemonStruct *sub_80243E8(void)
{
    u8 buffer [40];
    u8 nameBuffer [20];
    struct PokemonStruct *pokeStruct =  &gRecruitedPokemonRef->pokemon[gUnknown_3001B60->unk1A[gUnknown_3001B60->unk376 * gUnknown_3001B60->unk374 + gUnknown_3001B60->unk370]];

    sub_80922B4(nameBuffer, pokeStruct->name, POKEMON_NAME_LENGTH);
    sprintfStatic(buffer, gUnknown_80DC9A4,nameBuffer); // %s
    return pokeStruct;
}

bool8 sub_8024458(s16 speciesNum, s32 param_2)
{
  s32 speciesNum_s32 = speciesNum;
  gUnknown_203B2AC = MemoryAlloc(sizeof(struct unkStruct_203B2AC), 8);
  gUnknown_203B2AC->speciesNum = speciesNum_s32;
  gUnknown_203B2AC->unkE0 = param_2;
  gUnknown_203B2AC->unkE4 = &gUnknown_203B2AC->unkE8[param_2];
  sub_8006518(gUnknown_203B2AC->unkE8);
  gUnknown_203B2AC->unkE8[gUnknown_203B2AC->unkE0] = gUnknown_80DC9C8;
  gUnknown_203B2AC->unkE4->unk14 = gUnknown_203B2AC->unk148;
  gUnknown_203B2AC->unk148[2] = 10;
  sub_8024604();
  sub_802452C();
  sub_8013984(gUnknown_203B2AC);
  return TRUE;
}

u8 sub_80244E4(void)
{ 
  switch(GetKeyPress(gUnknown_203B2AC))
  {
      case 2:
        PlayMenuSoundEffect(1);
        return 2;
      case 1:
        PlayMenuSoundEffect(0);
        return 3;
      default:
        if (sub_8013938(gUnknown_203B2AC) != 0) {
            sub_802452C();
            return 1;
        }
        else {
            return 0;
        }
  }
}

void sub_802452C(void)
{ 
    sub_8024588();
    sub_80245D0();
}

void sub_802453C(void)
{ 
    if(gUnknown_203B2AC)
    {
        gUnknown_203B2AC->unkE8[gUnknown_203B2AC->unkE0] = gUnknown_80DC9B0;
        ResetUnusedInputStruct();
        sub_800641C(gUnknown_203B2AC->unkE8, 1, 1);
        MemoryFree(gUnknown_203B2AC);
        gUnknown_203B2AC = NULL;
    }
}

void sub_8024588(void)
{ 
   gUnknown_203B2AC->unk148[0] = gUnknown_203B2AC->unk20;
   gUnknown_203B2AC->unk148[1] = gUnknown_203B2AC->unk1E;
   gUnknown_203B2AC->unk148[3] = 0;
   ResetUnusedInputStruct();
   sub_800641C(gUnknown_203B2AC->unkE8,1,1);
}

void sub_80245D0(void)
{ 
  CreatePokemonInfoTabScreen
            (gUnknown_203B2AC->unk34[gUnknown_203B2AC->unk1E],
             gUnknown_203B2AC->unk1E,&gUnknown_203B2AC->unk4C,
             &gUnknown_203B2AC->unkB0,gUnknown_203B2AC->unkE0);
}

void sub_8024604(void)
{
  struct PokemonStruct *pokeStruct;
  u32 *iVar3;
  
  gUnknown_203B2AC->unk34[0] = 2;
  gUnknown_203B2AC->unk34[1] = 3;
  gUnknown_203B2AC->unk34[2] = 5;
  sub_8013818(gUnknown_203B2AC,3,1,gUnknown_203B2AC->unkE0);
  iVar3 = &gUnknown_203B2AC->unk4C;
  pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_203B2AC->speciesNum];
  sub_808FF20(iVar3,pokeStruct, sub_80023E4(7));
}
