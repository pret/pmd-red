#include "global.h"
#include "globaldata.h"
#include "exclusive_pokemon.h"
#include "dungeon_data.h"

EWRAM_INIT struct ExclusivePokemonData *gUnknown_203B498 = {0};
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
    gUnknown_203B498->unk48[param_1 / 32] |= 1 << ((param_1 % 32));
}

void sub_8097FD0(u8 param_1)
{
    gUnknown_203B498->unk3C[param_1 / 32] |= 1 << ((param_1 % 32));
}

void sub_8097FF8(void)
{
    s32 index;

    for (index = 0; index < 0x40; index++) {
        if ((gUnknown_203B498->unk48[index / 32] & (1 << (index % 32))) != 0) {
            gUnknown_203B498->unk3C[index / 32] |= (1 << (index % 32));
        }
    }
    sub_8098080();
}

void sub_8098044(u8 param_1)
{
    gUnknown_203B498->unk3C[param_1 / 32] &= ~(1 << (((param_1 % 32))));
    gUnknown_203B498->unk48[param_1 / 32] &= ~(1 << (((param_1 % 32))));
}

void sub_8098080(void)
{
    s32 index;

    for(index = 0; index < 0x3; index++)
    {
        gUnknown_203B498->unk48[index] = 0;
    }
}

u8 sub_80980A4(void)
{
    u32 temp = gUnknown_203B498->unk0;
    gUnknown_203B498->unk0 = 1;
    return temp;
}

void sub_80980B4(s16 pokeID)
{
    s32 pokeID_s32 = pokeID;
    s32 pokeID_s32_1 = pokeID_s32;
    if (pokeID_s32 == MONSTER_DECOY)
        return;
    if (pokeID_s32 == MONSTER_STATUE)
        return;
    if (pokeID_s32 == MONSTER_RAYQUAZA_CUTSCENE)
        return;

    gUnknown_203B498->unk4[pokeID_s32 / 32] |= 1 << (s16)(pokeID_s32_1 % 32);
}

bool8 sub_8098100(u8 param_1)
{
    if (param_1 > 0x3f) {
        return FALSE;
    }
    else
    {
        return (gUnknown_203B498->unk3C[param_1 / 32] & (1 << (param_1 % 32))) != 0;
    }
}

bool8 sub_8098134(s16 pokeID)
{
    s32 pokeID_s32;
    s32 pokeID_s32_1;

    pokeID_s32 = pokeID;
    pokeID_s32_1 = pokeID_s32;
    return ((gUnknown_203B498->unk4[pokeID_s32 / 32] & (1 << (s16)(pokeID_s32_1 % 32))) != 0);
}

void SetTutorialFlag(s32 index)
{
    gUnknown_203B498->unk54[index / 32] |= (1 << (index % 32));
}

bool32 GetTutorialFlag(s32 index)
{
    if (index > 0x1e) {
        return FALSE;
    }
    else {
        return (((gUnknown_203B498->unk54[index / 32]) & (1 << (index % 32))) != 0);
    }
}

bool8 IsExclusivePokemonUnlocked(s32 pokeID)
{
    s32 index;
    s32 pokeID_s32 = (s16) pokeID;

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

void WriteExclusivePokemon(DataSerializer *r0)
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

    WriteBits(r0, gUnknown_203B498, 1);
    for(index = 0; index < MONSTER_MAX; index++)
    {
        stack_0 = sub_8098134(index);
        WriteBits(r0, &stack_0, 1);
    }
    for(index = 0; index < 64; index++)
    {
        stack_1 = sub_8098100(index);
        WriteBits(r0, &stack_1, 1);
    }
    for(index = 0; index < 31; index++)
    {
        stack_2 = GetTutorialFlag(index);
        WriteBits(r0, &stack_2, 1);
    }
    for(index = 0; index < NUM_EXCLUSIVE_POKEMON; index++)
    {
        if(gUnknown_203B498->Exclusives[index])
            puVar2 = &neg_1;
        else
            puVar2 = &zero;
        WriteBits(r0, puVar2, 1);
    }
}

void ReadExclusivePokemon(DataSerializer *r0)
{
    s32 index;

    memset(gUnknown_203B498, 0, sizeof(struct ExclusivePokemonData));
    ReadBits(r0, gUnknown_203B498, 1);
    for (index = 0; index < MONSTER_MAX; index++) {
        u8 stack_0;
        ReadBits(r0, &stack_0, 1);
        if(stack_0)
            sub_80980B4(index);
    }
    for (index = 0; index < 64; index++) {
        u8 stack_1;
        ReadBits(r0, &stack_1, 1);
        if(stack_1)
            sub_8097FA8(index);
    }
    for (index = 0; index < 31; index++) {
        u8 stack_2;
        ReadBits(r0, &stack_2, 1);
        if(stack_2)
            SetTutorialFlag(index);
    }
    for (index = 0; index < NUM_EXCLUSIVE_POKEMON; index++) {
        u8 stack_3;
        ReadBits(r0, &stack_3, 1);
        do; while(0); // do/while needed for matching - jiang
        gUnknown_203B498->Exclusives[index] = (stack_3 & 1) != 0;
    }
    sub_8097FF8();
}
