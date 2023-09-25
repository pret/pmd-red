#include "global.h"
#include "code_80118A4.h"
#include "common_strings.h"
#include "hints_menu2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 struct unkStruct_203B268 *sUnknown_203B268 = {0};

#include "data/hints_menu2.h"

static void DisplayChosenHint(void);

static void sub_801E714(void);
static void sub_801E76C(void);

bool8 CreateHintDisplayScreen(u32 index)
{
    sUnknown_203B268 = MemoryAlloc(sizeof(struct unkStruct_203B268), 8);
    sUnknown_203B268->unk34 = 0;
    sUnknown_203B268->unk38 = sUnknown_203B268->unk3C;
    sub_8006518(sUnknown_203B268->unk3C);
    sUnknown_203B268->unk3C[sUnknown_203B268->unk34] = sUnknown_80DC0FC;
    sUnknown_203B268->unk38->unk14 = sUnknown_203B268->unk9C;
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B268->unk3C, TRUE, TRUE);
    sub_8013818(&sUnknown_203B268->input, 5, 1, sUnknown_203B268->unk34);
    sUnknown_203B268->input.unk1E = index;
    sub_801E714();

    return TRUE;
}

u32 HandleHintDisplayScreenInput(void)
{
    switch (GetKeyPress(&sUnknown_203B268->input)) {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_8013938(&sUnknown_203B268->input)) {
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
        sUnknown_203B268->unk3C[sUnknown_203B268->unk34] = sUnknown_80DC0E4;
        ResetUnusedInputStruct();
        sub_800641C(sUnknown_203B268->unk3C, TRUE, TRUE);
        MemoryFree(sUnknown_203B268);
        sUnknown_203B268 = NULL;
    }
}

static void sub_801E76C(void)
{
    sUnknown_203B268->unk9C[0] = sUnknown_203B268->input.unk20;
    sUnknown_203B268->unk9C[1] = sUnknown_203B268->input.unk1E;
    sUnknown_203B268->unk9C[2] = 15;
    sUnknown_203B268->unk9C[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(sUnknown_203B268->unk3C, TRUE, TRUE);
}

static void DisplayChosenHint(void)
{
    sub_80073B8(sUnknown_203B268->unk34);
    xxx_call_draw_string((sUnknown_203B268->input.unk1E * 8) + 16, 0, gCommonHints[sUnknown_203B268->input.unk1E].heading, sUnknown_203B268->unk34, 0);
    xxx_call_draw_string(10, 20, gCommonHints[sUnknown_203B268->input.unk1E].body, sUnknown_203B268->unk34, 0);
    sub_80073E0(sUnknown_203B268->unk34);
}