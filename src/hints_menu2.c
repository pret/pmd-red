#include "global.h"
#include "globaldata.h"
#include "structs/struct_sub80095e4.h"
#include "music_util.h"
#include "common_strings.h"
#include "hints_menu2.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"

static EWRAM_INIT struct_Sub80095E4_2 *sUnknown_203B268 = {NULL};

#include "data/hints_menu2.h"

static void DisplayChosenHint(void);

static void sub_801E714(void);
static void sub_801E76C(void);

bool8 CreateHintDisplayScreen(u32 index)
{
    sUnknown_203B268 = MemoryAlloc(sizeof(struct_Sub80095E4_2), 8);
    sUnknown_203B268->s0.winId = 0;
    sUnknown_203B268->s0.unk38 = &sUnknown_203B268->s0.windows.id[0];
    RestoreSavedWindows(&sUnknown_203B268->s0.windows);
    sUnknown_203B268->s0.windows.id[sUnknown_203B268->s0.winId] = sUnknown_80DC0FC;
    sUnknown_203B268->s0.unk38->header = &sUnknown_203B268->header;
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B268->s0.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sUnknown_203B268->s0.input, 5, 1, sUnknown_203B268->s0.winId);
    sUnknown_203B268->s0.input.unk1E = index;
    sub_801E714();

    return TRUE;
}

u32 HandleHintDisplayScreenInput(void)
{
    switch (GetKeyPress(&sUnknown_203B268->s0.input)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_8013938(&sUnknown_203B268->s0.input)) {
                sub_801E714();
                return 1;
            }
            return 0;
    }
}

static void sub_801E714(void)
{
    sub_801E76C();
    DisplayChosenHint();
}

void DestroyHintDisplayScreen(void)
{
    if (sUnknown_203B268 != NULL) {
        sUnknown_203B268->s0.windows.id[sUnknown_203B268->s0.winId] = sUnknown_80DC0E4;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B268->s0.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B268);
        sUnknown_203B268 = NULL;
    }
}

static void sub_801E76C(void)
{
    sUnknown_203B268->header.count = sUnknown_203B268->s0.input.unk20;
    sUnknown_203B268->header.currId = sUnknown_203B268->s0.input.unk1E;
    sUnknown_203B268->header.width = 15;
    sUnknown_203B268->header.f3 = 0;
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B268->s0.windows, TRUE, TRUE);
}

static void DisplayChosenHint(void)
{
    sub_80073B8(sUnknown_203B268->s0.winId);
    PrintStringOnWindow((sUnknown_203B268->s0.input.unk1E * 8) + 16, 0, gCommonHints[sUnknown_203B268->s0.input.unk1E].heading, sUnknown_203B268->s0.winId, 0);
    PrintStringOnWindow(10, 20, gCommonHints[sUnknown_203B268->s0.input.unk1E].body, sUnknown_203B268->s0.winId, 0);
    sub_80073E0(sUnknown_203B268->s0.winId);
}
