#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/str_802C39C.h"
#include "structs/str_wonder_mail.h"
#include "structs/struct_sub80095e4.h"
#include "music_util.h"
#include "code_803B050.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_802CDD4.h"

static EWRAM_INIT struct_Sub80095E4_2 *sUnknown_203B2F4 = {NULL};

#include "data/wonder_mail_802CDD4.h"

static void sub_802CF5C(void);

bool8 sub_802CDD4(u32 a0)
{
    if (sUnknown_203B2F4 == NULL)
        sUnknown_203B2F4 = MemoryAlloc(sizeof(struct_Sub80095E4_2), 8);

    sUnknown_203B2F4->s0.winId = a0;
    sUnknown_203B2F4->s0.unk38 = &sUnknown_203B2F4->s0.windows.id[sUnknown_203B2F4->s0.winId];
    RestoreSavedWindows(&sUnknown_203B2F4->s0.windows);
    sUnknown_203B2F4->s0.windows.id[sUnknown_203B2F4->s0.winId] = sUnknown_80DFDA4;
    sUnknown_203B2F4->s0.unk38->header = &sUnknown_203B2F4->header;
    sub_8012D34(sUnknown_203B2F4->s0.unk38, 4);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2F4->s0.windows, TRUE, TRUE);
    sub_8013848(&sUnknown_203B2F4->s0.input, 5, 4, a0);
    sub_802CF5C();
    sub_802CFD0();
    return TRUE;
}

u32 sub_802CE5C(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2F4->s0.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2F4->s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            return 3;
        default:
            if (sub_80138B8(&sUnknown_203B2F4->s0.input, TRUE)) {
                sub_802CF5C();
                sub_802CFD0();
                return 1;
            }
            return 0;
    }
}

u8 sub_802CEBC(void)
{
    return (sUnknown_203B2F4->s0.input.currPage * sUnknown_203B2F4->s0.input.entriesPerPage) + sUnknown_203B2F4->s0.input.menuIndex;
}

void sub_802CED8(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2F4->s0.windows, FALSE, FALSE);
    sub_8013984(&sUnknown_203B2F4->s0.input);
    sub_802CF5C();
    sub_802CFD0();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2F4->s0.input);
}

void sub_802CF14(void)
{
    if (sUnknown_203B2F4 != NULL) {
        sUnknown_203B2F4->s0.windows.id[sUnknown_203B2F4->s0.winId] = sUnknown_80DFD8C;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2F4->s0.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B2F4);
        sUnknown_203B2F4 = NULL;
    }
}

static void sub_802CF5C(void)
{
    sUnknown_203B2F4->header.count = sUnknown_203B2F4->s0.input.unk20;
    sUnknown_203B2F4->header.currId = sUnknown_203B2F4->s0.input.currPage;
    sUnknown_203B2F4->header.width = 12;
    sUnknown_203B2F4->header.f3 = 0;

    SUB_8009614_CALL(sUnknown_203B2F4->s0);
}

void sub_802CFD0(void)
{
    unkStruct_802C39C local;
    unkStruct_803B344 *iVar1;
    s32 r5;
    s32 r4;

    CallPrepareTextbox_8008C54(sUnknown_203B2F4->s0.winId);
    sub_80073B8(sUnknown_203B2F4->s0.winId);

    r5 = r4 = (sUnknown_203B2F4->s0.input.currPage * 8) + 10;
    PrintStringOnWindow(r5, 0, sRescueEvent, sUnknown_203B2F4->s0.winId, 0);

    r4 -= 6;
    r5 = r4 + (sUnknown_203B2F4->header.width * 8);
    sub_8012BC4(r5, 0, sUnknown_203B2F4->s0.input.currPage + 1, 2, 7, sUnknown_203B2F4->s0.winId);

    for (r5 = 0; r5 < sUnknown_203B2F4->s0.input.unk1A; r5++) {
        iVar1 = sub_803B344((sUnknown_203B2F4->s0.input.currPage * sUnknown_203B2F4->s0.input.entriesPerPage) + r5);

        local.unk0[0] = sUnknown_203B2F4->s0.winId;
        local.y = GetMenuEntryYCoord(&sUnknown_203B2F4->s0.input, r5);
        sub_803B35C(&iVar1->mail, &local);

        local.unk43 = 1;
        local.unk4C = iVar1->unk14;
        CreateRescueTitle(&local);
    }

    sub_80073E0(sUnknown_203B2F4->s0.winId);
}
