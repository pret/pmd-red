#include "global.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text1.h"
#include "text2.h"
#include "wigglytuff_shop2.h"

static EWRAM_DATA_2 WigglytuffShop2Work *sWigglytuffShop2Work = {0};

#include "data/wigglytuff_shop2.h"

static void sub_8021820(void);
static void sub_8021878(void);
static void sub_8021894(void);
static void sub_8021A60(void);
static s32 sub_8021B58(s16 species);

bool8 sub_8021774(u8 friendArea, bool8 a1, s32 a2)
{
    sWigglytuffShop2Work = MemoryAlloc(sizeof(WigglytuffShop2Work), 8);
    sWigglytuffShop2Work->friendArea = friendArea;
    sWigglytuffShop2Work->unkD = a1;
    sub_801317C(&sWigglytuffShop2Work->unk0);
    sub_8021A60();
    sWigglytuffShop2Work->unk74 = a2;
    sWigglytuffShop2Work->unk78 = &sWigglytuffShop2Work->unk7C[a2];
    sub_8006518(sWigglytuffShop2Work->unk7C);
    sWigglytuffShop2Work->unk7C[sWigglytuffShop2Work->unk74] = sUnknown_80DC4D8;
    sub_8021820();
    return TRUE;
}

u32 sub_80217EC(void)
{
    switch (sub_8012A64(&sWigglytuffShop2Work->unk0, sWigglytuffShop2Work->unk74)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            return 0;
    }
}

static void sub_8021820(void)
{
    sub_8021878();
    sub_8021894();
}

void sub_8021830(void)
{
    if (sWigglytuffShop2Work) {
        sWigglytuffShop2Work->unk7C[sWigglytuffShop2Work->unk74] = sUnknown_80DC4BC;
        ResetUnusedInputStruct();
        sub_800641C(sWigglytuffShop2Work->unk7C, TRUE, TRUE);
        MemoryFree(sWigglytuffShop2Work);
        sWigglytuffShop2Work = NULL;
    }
}

static void sub_8021878(void)
{
    ResetUnusedInputStruct();
    sub_800641C(sWigglytuffShop2Work->unk7C, TRUE, TRUE);
}

static void sub_8021894(void)
{
    const u8 *string;
    u32 y;
    u32 x;
    s32 i;
    u8 buffer1[256];
    u8 buffer2[100];

    sub_80073B8(sWigglytuffShop2Work->unk74);
    sub_8092578(buffer1, sWigglytuffShop2Work->friendArea, FALSE);
    xxx_call_draw_string(20, 0, buffer1, sWigglytuffShop2Work->unk74, 0);

    string = GetFriendAreaDescription(sWigglytuffShop2Work->friendArea);
    xxx_call_draw_string(10, 20, string, sWigglytuffShop2Work->unk74, 0);

    if (sWigglytuffShop2Work->unkD != 0)
        xxx_call_draw_string(32, 60, sUnknown_80DC4F0, sWigglytuffShop2Work->unk74, 0);
    else
        xxx_call_draw_string(32, 60, sInhabitants, sWigglytuffShop2Work->unk74, 0);

    sub_800792C(sWigglytuffShop2Work->unk74, 4, 64, 20, 4);

    if (sWigglytuffShop2Work->unkD != 0)
        sub_800792C(sWigglytuffShop2Work->unk74, 184, 64, 20, 4);
    else
        sub_800792C(sWigglytuffShop2Work->unk74, 94, 64, 110, 4);

    sub_800792C(sWigglytuffShop2Work->unk74, 4, 130, 200, 4);
    sub_8007A78(sWigglytuffShop2Work->unk74, 3, 64, 67, 4);
    sub_8007A78(sWigglytuffShop2Work->unk74, 204, 64, 67, 4);

    for (i = 0; i < sWigglytuffShop2Work->numPokemoninFriendArea; i++) {
        x = (i % 3) * 63 + 7;
        y = (i / 3) * 12 + 71;
        sub_808D930(buffer2, sWigglytuffShop2Work->unkE[i]);

        switch (sWigglytuffShop2Work->unk30[i]) {
            case 0: // Not recruited/seen
                xxx_call_draw_string(x, y, gCommonTripleQuestionMark[0], sWigglytuffShop2Work->unk74, 0);
                break;
            case 1: // Seen but not recruited
                xxx_call_draw_string(x, y, buffer2, sWigglytuffShop2Work->unk74, 0);
                break;
            case 2:
                sprintfStatic(buffer1, sFmtCyanString, buffer2);
                xxx_call_draw_string(x, y, buffer1, sWigglytuffShop2Work->unk74, 0);
                break;
        }
    }

    sub_80073E0(sWigglytuffShop2Work->unk74);
}

static void sub_8021A60(void)
{
    s32 sVar4;
    s32 iVar6;
    s32 index;
    PokemonStruct1 *pokeStruct;

    sWigglytuffShop2Work->numPokemoninFriendArea = 0;

    for (index = 0; index < 0x10; index++) {
        sWigglytuffShop2Work->unkE[index] = 0;
        sWigglytuffShop2Work->unk30[index] = 0;
    }

    for (index = 0; index <= MONSTER_MAX; index++) {
        s32 index2 = (s16)index;

        if (sWigglytuffShop2Work->friendArea == GetFriendArea(index2) && index2 == GetBaseSpeciesNoUnown(index2)) {
            iVar6 = sWigglytuffShop2Work->numPokemoninFriendArea;
            sWigglytuffShop2Work->unkE[iVar6] = index2;
            sWigglytuffShop2Work->numPokemoninFriendArea = iVar6 + 1;
        }
    }

    for (index = 0; index <= MONSTER_MAX; index++) {
        if (!sub_8098134(index))
            continue;

        sVar4 = sub_8021B58(index);
        if (sVar4 != -1)
            sWigglytuffShop2Work->unk30[sVar4] = 1;
    }

    for (index = 0; index < NUM_MONSTERS; index++) {
        pokeStruct = &gRecruitedPokemonRef->pokemon[index];
        if (!((u8)pokeStruct->unk0 & 1))
            continue;

        sVar4 = sub_8021B58(pokeStruct->speciesNum);
        if (sVar4 != -1)
            sWigglytuffShop2Work->unk30[sVar4] = 2;
    }
}

static s32 sub_8021B58(s16 species)
{
    s32 baseSpecies;
    s32 i;

    baseSpecies = GetBaseSpeciesNoUnown(species);

    for (i = 0; i < sWigglytuffShop2Work->numPokemoninFriendArea; i++) {
        if (baseSpecies == sWigglytuffShop2Work->unkE[i])
            return i;
    }
    return -1;
}