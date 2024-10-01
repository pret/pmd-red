#include "global.h"
#include "exclusive_pokemon.h"

const struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON] = {

    RED_EXCLUSIVE(MONSTER_PORYGON),
    BLUE_EXCLUSIVE(MONSTER_PORYGON2),
    BLUE_EXCLUSIVE(MONSTER_MAGIKARP),
    BLUE_EXCLUSIVE(MONSTER_GYARADOS),
    RED_EXCLUSIVE(MONSTER_FEEBAS),
    RED_EXCLUSIVE(MONSTER_MILOTIC),
    RED_EXCLUSIVE(MONSTER_PLUSLE),
    BLUE_EXCLUSIVE(MONSTER_MINUN),
    BLUE_EXCLUSIVE(MONSTER_LAPRAS),
    RED_EXCLUSIVE(MONSTER_MANTINE),
    RED_EXCLUSIVE(MONSTER_ROSELIA),
    BLUE_EXCLUSIVE(MONSTER_AIPOM),
};

const u8 filler_ex0[8] = 
{
    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};
const u8 filler_ex1[8] = 
{
    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};

EWRAM_DATA_2 struct ExclusivePokemonData *gUnknown_203B498 = {0};
EWRAM_DATA struct ExclusivePokemonData gExclusivePokemonInfo = {0};

void LoadExclusivePokemon(void)
{
    gUnknown_203B498 = &gExclusivePokemonInfo;
}

struct ExclusivePokemonData *GetExclusivePokemon(void)
{
    return &gExclusivePokemonInfo;
}

void InitializeExclusivePokemon(void)
{
    s32 counter;
    memset(gUnknown_203B498, 0, sizeof(struct ExclusivePokemonData));
    for(counter = 0; counter < NUM_EXCLUSIVE_POKEMON; counter++)
    {
        gUnknown_203B498->Exclusives[counter] = gExclusivePokemon[counter].in_rrt;
    }
}

void sub_8097FA8(u8 param_1)
{   
    gUnknown_203B498->unk48[param_1 >> 5] |= 1 << ((param_1 & 0x1f));
}

void sub_8097FD0(u8 param_1)
{   
    gUnknown_203B498->unk3C[param_1 >> 5] |= 1 << ((param_1 & 0x1f));
}

void sub_8097FF8(void)
{
    s32 iVar1;
    s32 index;
    struct ExclusivePokemonData *ptr;

    for(index = 0; index < 0x40; index++)
    {
        ptr = gUnknown_203B498;
        if (index < 0) {
            iVar1 = index + 0x1f;
        }
        else
        {
            iVar1 = index;
        }
        if ((ptr->unk48[iVar1 >> 5] & (1 << (index - ((iVar1 >> 5) * 0x20)))) != 0) {
            ptr->unk3C[iVar1 >> 5] |= (1 << (index - ((iVar1 >> 5) * 0x20)));
        }
    }
    sub_8098080();
}

void sub_8098044(u8 param_1)
{
    gUnknown_203B498->unk3C[param_1 >> 5] &= ~(1 << (((param_1 & 0x1f))));
    gUnknown_203B498->unk48[param_1 >> 5] &= ~(1 << (((param_1 & 0x1f))));
}

void sub_8098080(void)
{
    s32 index;

    for(index = 0; index < 0x3; index++)
    {
        gUnknown_203B498->unk48[index] = 0;
    }
}

u32 sub_80980A4(void)
{
    u32 temp = gUnknown_203B498->unk0;
    gUnknown_203B498->unk0 = 1;
    return temp;
}

void sub_80980B4(s16 pokeID)
{
    s32 index;
    s32 pokeID_s32;
    s32 pokeID_s32_1;
    struct ExclusivePokemonData *ptr;

    pokeID_s32 = pokeID;
    pokeID_s32_1 = pokeID_s32;
    if (pokeID_s32 != MONSTER_DECOY)
    {
        if(pokeID_s32 != MONSTER_STATUE)
        {
            if(pokeID_s32 != MONSTER_RAYQUAZA_CUTSCENE) {
                ptr =  gUnknown_203B498;
                index = pokeID_s32;
                if (pokeID_s32 < 0) {
                    index = pokeID_s32 + 0x1f;
                }
                ptr->unk4[index >> 5] |= 1 << (s16)((pokeID_s32_1 - (index >> 5) * 0x20));
            }
        }
    }
}

bool8 sub_8098100(u8 param_1)
{
    u32 index = param_1;

    if (index > 0x3f) {
        return FALSE;
    }
    else
    {
        return (gUnknown_203B498->unk3C[param_1 >> 0x5] & (1 << (index & 0x1f))) ? TRUE : FALSE;
    }
}

bool8 sub_8098134(s16 pokeID)
{
    s32 index;
    s32 pokeID_s32;
    s32 pokeID_s32_1;
    struct ExclusivePokemonData *ptr;

    pokeID_s32 = pokeID;
    pokeID_s32_1 = pokeID_s32;
    ptr =  gUnknown_203B498;
    if (pokeID < 0) {
        index = pokeID_s32 + 0x1f;
    }
    else
    {
        index = pokeID_s32;
    }
    return ((ptr->unk4[(index >> 5)] & (1 << (s16)(pokeID_s32_1 - ((index >> 5) * 0x20)))) != 0) ? TRUE : FALSE;
}

void SetTutorialFlag(s32 param_1)
{
  s32 index;
  struct ExclusivePokemonData *ptr;
  
    ptr =  gUnknown_203B498;
    if (param_1 < 0) {
        index = param_1 + 0x1f;
    }
    else
    {
        index = param_1;
    }
    ptr->unk54[(index >> 5)] |= 1 << (param_1 - ((index >> 5) * 0x20));
}

bool32 GetTutorialFlag(s32 param_1)
{
  s32 index;
  bool32 flag;
  struct ExclusivePokemonData *ptr;
  
  if (param_1 > 0x1e) {
    return FALSE;
  }
  else {
    ptr =  gUnknown_203B498;
    if (param_1 < 0) {
        index = param_1 + 0x1f;
    }
    else
    {
        index = param_1;
    }
    flag = ptr->unk54[(index >> 5)] & 1 << (param_1 - ((index >> 5) * 0x20));
    if (flag != 0) {
      flag = TRUE;
    }
    return flag;
  }
}

bool8 IsExclusivePokemonUnlocked(s16 pokeID)
{
    s32 index;
    s32 pokeID_s32;

    pokeID_s32 = pokeID;

    for(index = 0; index < NUM_EXCLUSIVE_POKEMON; index++)
    {
        if(gExclusivePokemon[index].poke_id == pokeID_s32)
            return gUnknown_203B498->Exclusives[index];
    }
    return TRUE;
}

void UnlockExclusivePokemon(s16 pokeID)
{
    s32 index;
    s32 pokeID_s32;

    pokeID_s32 = pokeID;

    for(index = 0; index < NUM_EXCLUSIVE_POKEMON; index++)
    {
        if(gExclusivePokemon[index].poke_id == pokeID_s32)
            gUnknown_203B498->Exclusives[index] = TRUE;
    }
}

void WriteExclusivePokemon(struct unkStruct_8094924 *r0)
{
    s32 index;
    u8 *puVar2;

    u8 stack_0;
    u8 stack_1;
    u8 stack_2;
    u8 neg_1;
    u8 zero;

    neg_1 = -1;
    zero = 0;


    SaveIntegerBits(r0, gUnknown_203B498, 1);
    for(index = 0; index < MONSTER_MAX; index++)
    {   
        stack_0 = sub_8098134(index);
        SaveIntegerBits(r0, &stack_0, 1);
    }
    for(index = 0; index < 64; index++)
    {
        stack_1 = sub_8098100(index);
        SaveIntegerBits(r0, &stack_1, 1);
    }
    for(index = 0; index < 31; index++)
    {
        stack_2 = GetTutorialFlag(index);
        SaveIntegerBits(r0, &stack_2, 1);
    }
    for(index = 0; index < NUM_EXCLUSIVE_POKEMON; index++)
    {
        if(gUnknown_203B498->Exclusives[index])
            puVar2 = &neg_1;
        else
            puVar2 = &zero;
        SaveIntegerBits(r0, puVar2, 1);
    }
}

void ReadExclusivePokemon(struct unkStruct_8094924 *r0)
{
    s32 index;
    u8 stack_0;
    u8 stack_1;
    u8 stack_2;
    u8 stack_3;

    memset(gUnknown_203B498, 0, sizeof(struct ExclusivePokemonData));
    RestoreIntegerBits(r0, gUnknown_203B498, 1);
    for(index = 0; index < MONSTER_MAX; index++)
    {
        RestoreIntegerBits(r0, &stack_0, 1);
        if(stack_0)
            sub_80980B4(index);
    }
    for(index = 0; index < 64; index++)
    {
        RestoreIntegerBits(r0, &stack_1, 1);
        if(stack_1)
            sub_8097FA8(index);
    }
    for(index = 0; index < 31; index++)
    {
        RestoreIntegerBits(r0, &stack_2, 1);
        if(stack_2)
            SetTutorialFlag(index);
    }
    for(index = 0; index < NUM_EXCLUSIVE_POKEMON; index++)
    {
        RestoreIntegerBits(r0, &stack_3, 1);

        do; while(0); // do/while needed for matching - jiang

        gUnknown_203B498->Exclusives[index] = 1 & stack_3;
    }
    sub_8097FF8();
}

