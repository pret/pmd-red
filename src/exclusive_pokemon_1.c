#include "global.h"
#include "exclusive_pokemon.h"

extern struct ExclusivePokemonData *gUnknown_203B498;
extern struct ExclusivePokemon gExclusivePokemon[NUM_EXCLUSIVE_POKEMON];

void RestoreIntegerBits(u32 *, void *, u32);
void sub_80980B4(s16);
void sub_8097FA8(u8);
void sub_8098170(s32);
void sub_8097FF8(void);

u8 sub_8098100(u8);
u8 sub_8098134(s16);
u8 sub_80981A0(s32);
void SaveIntegerBits(u32 *, void *, s32);

bool8 IsExclusivePokemonUnlocked(s16 pokeID)
{
    s32 iVar2;
    s32 pokeID_s32;

    pokeID_s32 = pokeID;

    for(iVar2 = 0; iVar2 < NUM_EXCLUSIVE_POKEMON; iVar2++)
    {
        if(gExclusivePokemon[iVar2].poke_id == pokeID_s32)
            return gUnknown_203B498->Exclusives[iVar2];
    }
    return TRUE;
}

void UnlockExclusivePokemon(s16 pokeID)
{
    s32 iVar2;
    s32 pokeID_s32;

    pokeID_s32 = pokeID;

    for(iVar2 = 0; iVar2 < NUM_EXCLUSIVE_POKEMON; iVar2++)
    {
        if(gExclusivePokemon[iVar2].poke_id == pokeID_s32)
            gUnknown_203B498->Exclusives[iVar2] = 1;
    }
}

void WriteExclusivePokemon(u32 *r0)
{
    s32 iVar2;
    u8 *puVar2;

    u8 stack_0;
    u8 stack_1;
    u8 stack_2;
    u8 neg_1;
    u8 zero;

    neg_1 = -1;
    zero = 0;


    SaveIntegerBits(r0, (u8 *)gUnknown_203B498, 1);
    for(iVar2 = 0; iVar2 < 424; iVar2++)
    {   
        stack_0 = sub_8098134(iVar2);
        SaveIntegerBits(r0, &stack_0, 1);
    }
    for(iVar2 = 0; iVar2 < 64; iVar2++)
    {
        stack_1 = sub_8098100(iVar2);
        SaveIntegerBits(r0, &stack_1, 1);
    }
    for(iVar2 = 0; iVar2 < 31; iVar2++)
    {
        stack_2 = sub_80981A0(iVar2);
        SaveIntegerBits(r0, &stack_2, 1);
    }
    for(iVar2 = 0; iVar2 < NUM_EXCLUSIVE_POKEMON; iVar2++)
    {
        if(gUnknown_203B498->Exclusives[iVar2])
            puVar2 = &neg_1;
        else
            puVar2 = &zero;
        SaveIntegerBits(r0, puVar2, 1);
    }
}

void ReadExclusivePokemon(u32 *r0)
{
    s32 iVar2;
    u8 stack_0;
    u8 stack_1;
    u8 stack_2;
    u8 stack_3;

    memset(gUnknown_203B498, 0, sizeof(struct ExclusivePokemonData));
    RestoreIntegerBits(r0, gUnknown_203B498, 1);
    for(iVar2 = 0; iVar2 < 424; iVar2++)
    {
        RestoreIntegerBits(r0, &stack_0, 1);
        if(stack_0)
            sub_80980B4(iVar2);
    }
    for(iVar2 = 0; iVar2 < 64; iVar2++)
    {
        RestoreIntegerBits(r0, &stack_1, 1);
        if(stack_1)
            sub_8097FA8(iVar2);
    }
    for(iVar2 = 0; iVar2 < 31; iVar2++)
    {
        RestoreIntegerBits(r0, &stack_2, 1);
        if(stack_2)
            sub_8098170(iVar2);
    }
    for(iVar2 = 0; iVar2 < NUM_EXCLUSIVE_POKEMON; iVar2++)
    {
        RestoreIntegerBits(r0, &stack_3, 1);

        do; while(0); // do/while needed for matching - jiang

        gUnknown_203B498->Exclusives[iVar2] = 1 & stack_3;
    }
    sub_8097FF8();
}
