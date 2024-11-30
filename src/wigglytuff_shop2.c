#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text.h"
#include "wigglytuff_shop2.h"

static EWRAM_DATA_2 WigglytuffShop2Work *sWigglytuffShop2Work = {0};

#include "data/wigglytuff_shop2.h"

static void sub_8021820(void);
static void sub_8021878(void);
static void PopulateWigglytuffShopFriendAreaInfoScreen(void);
static void sub_8021A60(void);
static s32 CheckSpeciesinWigglytuffFriendArea(s16 species);

bool8 CreateWigglytuffShopFriendAreaMenu(u8 friendArea, bool8 a1, s32 a2)
{
    sWigglytuffShop2Work = MemoryAlloc(sizeof(WigglytuffShop2Work), 8);
    sWigglytuffShop2Work->friendArea = friendArea;
    sWigglytuffShop2Work->unkD = a1;
    sub_801317C(&sWigglytuffShop2Work->unk0);
    sub_8021A60();
    sWigglytuffShop2Work->unk74 = a2;
    sWigglytuffShop2Work->unk78 = &sWigglytuffShop2Work->unk7C[a2];
    RestoreUnkTextStruct_8006518(sWigglytuffShop2Work->unk7C);
    sWigglytuffShop2Work->unk7C[sWigglytuffShop2Work->unk74] = sUnknown_80DC4D8;
    sub_8021820();
    return TRUE;
}

u32 HandleWigglytuffShopFriendAreaMenuInput(void)
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
    PopulateWigglytuffShopFriendAreaInfoScreen();
}

void CleanWigglytuffShopFriendAreaInfoMenu(void)
{
    if (sWigglytuffShop2Work) {
        sWigglytuffShop2Work->unk7C[sWigglytuffShop2Work->unk74] = sUnknown_80DC4BC;
        ResetUnusedInputStruct();
        xxx_call_save_unk_text_struct_800641C(sWigglytuffShop2Work->unk7C, TRUE, TRUE);
        MemoryFree(sWigglytuffShop2Work);
        sWigglytuffShop2Work = NULL;
    }
}

static void sub_8021878(void)
{
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(sWigglytuffShop2Work->unk7C, TRUE, TRUE);
}

static void PopulateWigglytuffShopFriendAreaInfoScreen(void)
{
    const u8 *string;
    u32 y;
    u32 x;
    s32 i;
    u8 buffer1[256];
    u8 buffer2[100];

    sub_80073B8(sWigglytuffShop2Work->unk74);
    WriteFriendAreaName(buffer1, sWigglytuffShop2Work->friendArea, FALSE);
    PrintStringOnWindow(20, 0, buffer1, sWigglytuffShop2Work->unk74, 0);

    string = GetFriendAreaDescription(sWigglytuffShop2Work->friendArea);
    PrintStringOnWindow(10, 20, string, sWigglytuffShop2Work->unk74, 0);

    if (sWigglytuffShop2Work->unkD != 0)
        PrintStringOnWindow(32, 60, sUnknown_80DC4F0, sWigglytuffShop2Work->unk74, 0);
    else
        PrintStringOnWindow(32, 60, sInhabitants, sWigglytuffShop2Work->unk74, 0);

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
        sub_808D930(buffer2, sWigglytuffShop2Work->friendAreaSpecies[i]);

        switch (sWigglytuffShop2Work->pokemonStatus[i]) {
            case POKEMON_UNKNOWN:
                PrintStringOnWindow(x, y, gCommonTripleQuestionMark[0], sWigglytuffShop2Work->unk74, 0);
                break;
            case POKEMON_SEEN:
                PrintStringOnWindow(x, y, buffer2, sWigglytuffShop2Work->unk74, 0);
                break;
            case POKEMON_RECRUITED:
                sprintfStatic(buffer1, sFmtCyanString, buffer2);
                PrintStringOnWindow(x, y, buffer1, sWigglytuffShop2Work->unk74, 0);
                break;
        }
    }

    sub_80073E0(sWigglytuffShop2Work->unk74);
}

static void sub_8021A60(void)
{
    s32 areaIndex;
    s32 iVar6;
    s32 index;
    PokemonStruct1 *pokeStruct;

    sWigglytuffShop2Work->numPokemoninFriendArea = 0;

    for (index = 0; index < 0x10; index++) {
        sWigglytuffShop2Work->friendAreaSpecies[index] = 0;
        sWigglytuffShop2Work->pokemonStatus[index] = POKEMON_UNKNOWN;
    }

    for (index = 0; index < MONSTER_MAX; index++) {
        s32 index2 = (s16)index;

        if (sWigglytuffShop2Work->friendArea == GetFriendArea(index2) && index2 == GetBaseSpeciesNoUnown(index2)) {
            iVar6 = sWigglytuffShop2Work->numPokemoninFriendArea;
            sWigglytuffShop2Work->friendAreaSpecies[iVar6] = index2;
            sWigglytuffShop2Work->numPokemoninFriendArea = iVar6 + 1;
        }
    }

    for (index = 0; index < MONSTER_MAX; index++) {
        if (!sub_8098134(index))
            continue;

        areaIndex = CheckSpeciesinWigglytuffFriendArea(index);
        if (areaIndex != -1)
            sWigglytuffShop2Work->pokemonStatus[areaIndex] = POKEMON_SEEN;
    }

    for (index = 0; index < NUM_MONSTERS; index++) {
        pokeStruct = &gRecruitedPokemonRef->pokemon[index];
        if (!((u8)pokeStruct->unk0 & 1))
            continue;

        areaIndex = CheckSpeciesinWigglytuffFriendArea(pokeStruct->speciesNum);
        if (areaIndex != -1)
            sWigglytuffShop2Work->pokemonStatus[areaIndex] = POKEMON_RECRUITED;
    }
}

/* Return index of pokemon if in the friend area, else return -1 */
static s32 CheckSpeciesinWigglytuffFriendArea(s16 species)
{
    s32 baseSpecies;
    s32 i;

    baseSpecies = GetBaseSpeciesNoUnown(species);

    for (i = 0; i < sWigglytuffShop2Work->numPokemoninFriendArea; i++) {
        if (baseSpecies == sWigglytuffShop2Work->friendAreaSpecies[i])
            return i;
    }
    return -1;
}
