#include "global.h"
#include "code_800D090.h"
#include "code_8023868.h"
#include "pokemon.h"
#include "pokemon_mid.h"
#include "structs/str_text.h"
#include "text_util.h"

//static // MAKE STATIC WHEN code_8023868.s IS DONE
IWRAM_DATA struct unkStruct_3001B60 *gUnknown_3001B60 = {0};

#include "data/code_8023868.h"

static void SortbyAlphabetNo(s32, s32);
static void SortbyInternalNo(s32, s32);
static void SortbyName(s32, s32);

//static bool8 sub_8024184(PokemonStruct1 *pokemon, u8 area);
//static void sub_80241A8(void);

// THE REMAINING CODE FROM THIS FILE IS IN code_8023868.s STARTING WITH sub_8023868

//static // MAKE STATIC WHEN code_8023868.s IS DONE
bool8 sub_8024184(PokemonStruct1 *pokemon, u8 area)
{
    if (area == GetFriendArea(pokemon->speciesNum))
        return TRUE;
    return FALSE;
}

//static // MAKE STATIC WHEN code_8023868.s IS DONE
void sub_80241A8(void)
{
    switch (gUnknown_3001B60->sortMethod) {
        case 2:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyAlphabetNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyAlphabetNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
        case 3:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyName(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyName(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
        case 1:
            if (gUnknown_3001B60->unkC != gUnknown_3001B60->unk10)
                SortbyInternalNo(gUnknown_3001B60->unkC, gUnknown_3001B60->unk10);

            if (gUnknown_3001B60->unk10 != gUnknown_3001B60->unk8)
                SortbyInternalNo(gUnknown_3001B60->unk10, gUnknown_3001B60->unk8);
            break;
    }
}

// TODO: Remove hacky if/do
static void SortbyInternalNo(s32 param_1, s32 param_2)
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

// TODO: Remove hacky if/do
static void SortbyAlphabetNo(s32 param_1, s32 param_2)
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

// TODO: Remove hacky if/do
static void SortbyName(s32 param_1, s32 param_2)
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

UNUSED static PokemonStruct1 *sub_80243E8(void)
{
    u8 buffer[40];
    u8 nameBuffer[20];
    PokemonStruct1 *pokeStruct = &gRecruitedPokemonRef->pokemon[gUnknown_3001B60->unk1A[(gUnknown_3001B60->unk376 * gUnknown_3001B60->unk374) + gUnknown_3001B60->unk370]];

    sub_80922B4(nameBuffer, pokeStruct->name, POKEMON_NAME_LENGTH);
    sprintfStatic(buffer, sUnknown_80DC9A4, nameBuffer);
    return pokeStruct;
}