#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "music_util.h"
#include "code_8024458.h"
#include "event_flag.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon.h"
#include "pokemon_summary_window.h"
#include "text_1.h"

static EWRAM_INIT struct unkStruct_203B2AC *sUnknown_203B2AC = {NULL};

#include "data/code_8024458.h"

static void sub_8024588(void);
static void sub_80245D0(void);
static void sub_8024604(void);

bool8 sub_8024458(s16 speciesNum, s32 a1)
{
    s32 speciesNum_s32 = speciesNum;

    sUnknown_203B2AC = MemoryAlloc(sizeof(struct unkStruct_203B2AC), 8);
    sUnknown_203B2AC->speciesNum = speciesNum_s32;
    sUnknown_203B2AC->unkE0 = a1;
    sUnknown_203B2AC->unkE4 = &sUnknown_203B2AC->unkE8.id[a1];
    RestoreSavedWindows(&sUnknown_203B2AC->unkE8);
    sUnknown_203B2AC->unkE8.id[sUnknown_203B2AC->unkE0] = sUnknown_80DC9C8;
    sUnknown_203B2AC->unkE4->header = &sUnknown_203B2AC->unk148;
    sUnknown_203B2AC->unk148.width = 10;
    sub_8024604();
    sub_802452C();
    MenuUpdatePagesData(&sUnknown_203B2AC->input);
    return TRUE;
}

u32 sub_80244E4(void)
{
    switch (GetKeyPress(&sUnknown_203B2AC->input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (MenuCursorUpdateOnlyLeftRight(&sUnknown_203B2AC->input)) {
                sub_802452C();
                return 1;
            }
            return 0;
    }
}

void sub_802452C(void)
{
    sub_8024588();
    sub_80245D0();
}

void sub_802453C(void)
{
    if (sUnknown_203B2AC != NULL) {
        sUnknown_203B2AC->unkE8.id[sUnknown_203B2AC->unkE0] = sUnknown_80DC9B0;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2AC->unkE8, TRUE, TRUE);
        MemoryFree(sUnknown_203B2AC);
        sUnknown_203B2AC = NULL;
    }
}

static void sub_8024588(void)
{
    sUnknown_203B2AC->unk148.count = sUnknown_203B2AC->input.pagesCount;
    sUnknown_203B2AC->unk148.currId = sUnknown_203B2AC->input.currPage;
    sUnknown_203B2AC->unk148.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2AC->unkE8, TRUE, TRUE);
}

static void sub_80245D0(void)
{
    ShowPokemonSummaryWindow(sUnknown_203B2AC->unk34[sUnknown_203B2AC->input.currPage], sUnknown_203B2AC->input.currPage, &sUnknown_203B2AC->unk4C, &sUnknown_203B2AC->unkB0, sUnknown_203B2AC->unkE0);
}

static void sub_8024604(void)
{
    PokemonStruct1 *pokeStruct;
    struct MonSummaryInfo *iVar3;

    sUnknown_203B2AC->unk34[0] = 2;
    sUnknown_203B2AC->unk34[1] = 3;
    sUnknown_203B2AC->unk34[2] = 5;

    CreateMenuOnWindow(&sUnknown_203B2AC->input, 3, 1, sUnknown_203B2AC->unkE0);
    iVar3 = &sUnknown_203B2AC->unk4C;
    pokeStruct = &gRecruitedPokemonRef->pokemon[sUnknown_203B2AC->speciesNum];
    SetMonSummaryInfo(iVar3, pokeStruct, sub_80023E4(7));
}
