#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/str_802C39C.h"
#include "structs/str_wonder_mail.h"
#include "text_3.h"
#include "music_util.h"
#include "code_803B050.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_802CDD4.h"

static EWRAM_INIT MenuHeaderWindow *sUnknown_203B2F4 = {NULL};

#include "data/wonder_mail_802CDD4.h"

static void sub_802CF5C(void);

bool8 sub_802CDD4(u32 a0)
{
    if (sUnknown_203B2F4 == NULL)
        sUnknown_203B2F4 = MemoryAlloc(sizeof(MenuHeaderWindow), MEMALLOC_GROUP_8);

    sUnknown_203B2F4->m.menuWinId = a0;
    sUnknown_203B2F4->m.menuWindow = &sUnknown_203B2F4->m.windows.id[sUnknown_203B2F4->m.menuWinId];
    RestoreSavedWindows(&sUnknown_203B2F4->m.windows);
    sUnknown_203B2F4->m.windows.id[sUnknown_203B2F4->m.menuWinId] = sUnknown_80DFDA4;
    sUnknown_203B2F4->m.menuWindow->header = &sUnknown_203B2F4->header;
    sub_8012D34(sUnknown_203B2F4->m.menuWindow, 4);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2F4->m.windows, TRUE, TRUE);
    CreateMenuOnWindowTwoLinesEntry(&sUnknown_203B2F4->m.input, 5, 4, a0);
    sub_802CF5C();
    sub_802CFD0();
    return TRUE;
}

u32 sub_802CE5C(bool8 a0)
{
    if (!a0) {
        sub_8013660(&sUnknown_203B2F4->m.input);
        return 0;
    }

    switch (GetKeyPress(&sUnknown_203B2F4->m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            return 3;
        default:
            if (MenuCursorUpdate(&sUnknown_203B2F4->m.input, TRUE)) {
                sub_802CF5C();
                sub_802CFD0();
                return 1;
            }
            return 0;
    }
}

u8 sub_802CEBC(void)
{
    return GET_CURRENT_MENU_ENTRY(sUnknown_203B2F4->m.input);
}

void sub_802CED8(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B2F4->m.windows, FALSE, FALSE);
    MenuUpdatePagesData(&sUnknown_203B2F4->m.input);
    sub_802CF5C();
    sub_802CFD0();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B2F4->m.input);
}

void sub_802CF14(void)
{
    if (sUnknown_203B2F4 != NULL) {
        sUnknown_203B2F4->m.windows.id[sUnknown_203B2F4->m.menuWinId] = sUnknown_80DFD8C;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B2F4->m.windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B2F4);
        sUnknown_203B2F4 = NULL;
    }
}

static void sub_802CF5C(void)
{
    sUnknown_203B2F4->header.count = sUnknown_203B2F4->m.input.pagesCount;
    sUnknown_203B2F4->header.currId = sUnknown_203B2F4->m.input.currPage;
    sUnknown_203B2F4->header.width = 12;
    sUnknown_203B2F4->header.f3 = 0;

    UPDATE_TWO_LINES_MENU_WINDOW_HEIGHT(sUnknown_203B2F4->m);
}

void sub_802CFD0(void)
{
    unkStruct_802C39C local;
    unkStruct_803B344 *iVar1;
    s32 r5;
    s32 r4;

    CallPrepareTextbox_8008C54(sUnknown_203B2F4->m.menuWinId);
    sub_80073B8(sUnknown_203B2F4->m.menuWinId);

    r5 = r4 = (sUnknown_203B2F4->m.input.currPage * 8) + 10;
    PrintStringOnWindow(r5, 0, sRescueEvent, sUnknown_203B2F4->m.menuWinId, 0);

    r4 -= 6;
    r5 = r4 + (sUnknown_203B2F4->header.width * 8);
    PrintNumOnWindow(r5, 0, sUnknown_203B2F4->m.input.currPage + 1, 2, 7, sUnknown_203B2F4->m.menuWinId);

    for (r5 = 0; r5 < sUnknown_203B2F4->m.input.currPageEntries; r5++) {
        iVar1 = sub_803B344((sUnknown_203B2F4->m.input.currPage * sUnknown_203B2F4->m.input.entriesPerPage) + r5);

        local.unk0[0] = sUnknown_203B2F4->m.menuWinId;
        local.y = GetMenuEntryYCoord(&sUnknown_203B2F4->m.input, r5);
        sub_803B35C(&iVar1->mail, &local);

        local.unk43 = 1;
        local.unk4C = iVar1->unk14;
        CreateRescueTitle(&local);
    }

    sub_80073E0(sUnknown_203B2F4->m.menuWinId);
}
