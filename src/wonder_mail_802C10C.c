#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "music_util.h"
#include "code_803B050.h"
#include "code_80958E8.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "pokemon_mail.h"
#include "text_1.h"
#include "text_2.h"
#include "wonder_mail_802C10C.h"

static EWRAM_INIT struct unkStruct_203B2E0 *gUnknown_203B2E0 = {NULL};
static EWRAM_INIT u16 gUnknown_203B2E4 = {0};

#include "data/wonder_mail_802C10C.h"

static s32 CountPelipperBoardSlots(void);
static void sub_802C328(void);

bool8 sub_802C10C(s32 a0, DungeonPos *a1, s32 a2)
{
    if (HasNoPelipperBoardJobs())
        return FALSE;

    if (gUnknown_203B2E0 == NULL)
        gUnknown_203B2E0 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), MEMALLOC_GROUP_8);

    gUnknown_203B2E0->unk8.m.menuWinId = a0;
    gUnknown_203B2E0->unk8.m.menuWindow = &gUnknown_203B2E0->unk8.m.windows.id[a0];
    RestoreSavedWindows(&gUnknown_203B2E0->unk8.m.windows);

    gUnknown_203B2E0->unk8.m.windows.id[gUnknown_203B2E0->unk8.m.menuWinId] = sUnknown_80DFCB4;
    gUnknown_203B2E0->unk8.m.menuWindow->header = &gUnknown_203B2E0->unk8.header;

    if (a1 != NULL)
        gUnknown_203B2E0->unk8.m.windows.id[gUnknown_203B2E0->unk8.m.menuWinId].pos = *a1;

    sub_8012D34(gUnknown_203B2E0->unk8.m.menuWindow, a2);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E0->unk8.m.windows, TRUE, TRUE);
    CreateMenuOnWindowTwoLinesEntry(&gUnknown_203B2E0->unk8.m.input, CountPelipperBoardSlots(), a2, a0);
    gUnknown_203B2E0->unk8.m.input.menuIndex = gUnknown_203B2E4;
    MenuUpdatePagesData(&gUnknown_203B2E0->unk8.m.input);
    sub_802C328();
    DrawPelipperBoardJobMenu();
    return TRUE;
}

u32 sub_802C1E4(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_203B2E0->unk8.m.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2E0->unk8.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
        default:
            if (MenuCursorUpdate(&gUnknown_203B2E0->unk8.m.input, 1)) {
                sub_802C328();
                DrawPelipperBoardJobMenu();
                return 1;
            }
            return 0;
    }
}

u8 sub_802C26C(void)
{
    return gUnknown_203B2E0->pelipperBoardSlots[GET_CURRENT_MENU_ENTRY(gUnknown_203B2E0->unk8.m.input)];
}

void sub_802C28C(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E0->unk8.m.windows, FALSE, FALSE);
    gUnknown_203B2E0->unk8.m.input.totalEntriesCount = CountPelipperBoardSlots();
    MenuUpdatePagesData(&gUnknown_203B2E0->unk8.m.input);
    sub_802C328();
    DrawPelipperBoardJobMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B2E0->unk8.m.input);
}

void sub_802C2D4(void)
{
    if (gUnknown_203B2E0 != NULL) {
        gUnknown_203B2E4 = gUnknown_203B2E0->unk8.m.input.menuIndex;
        gUnknown_203B2E0->unk8.m.windows.id[gUnknown_203B2E0->unk8.m.menuWinId] = sUnknown_80DFC9C;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B2E0->unk8.m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E0);
        gUnknown_203B2E0 = NULL;
    }
}

static void sub_802C328(void)
{
    gUnknown_203B2E0->unk8.header.count = gUnknown_203B2E0->unk8.m.input.pagesCount;
    gUnknown_203B2E0->unk8.header.currId = gUnknown_203B2E0->unk8.m.input.currPage;
    gUnknown_203B2E0->unk8.header.width = 12;
    gUnknown_203B2E0->unk8.header.f3 = 0;

    UPDATE_TWO_LINES_MENU_WINDOW_HEIGHT(gUnknown_203B2E0->unk8.m);
}

void DrawPelipperBoardJobMenu(void)
{
    u32 slotIndex;
    WonderMail *mail;
    s32 iVar4;
    s32 x;
    s32 i;
    unkStruct_802C39C local;

    CallPrepareTextbox_8008C54(gUnknown_203B2E0->unk8.m.menuWinId);
    sub_80073B8(gUnknown_203B2E0->unk8.m.menuWinId);
    iVar4 = gUnknown_203B2E0->unk8.m.input.currPage * 8;
    x = iVar4;
    x += 10;
    PrintStringOnWindow(x, 0, sBulletinBoard, gUnknown_203B2E0->unk8.m.menuWinId, 0);

    iVar4 += 4;
    x = iVar4 + (gUnknown_203B2E0->unk8.header.width * 8);
    PrintNumOnWindow(x, 0, gUnknown_203B2E0->unk8.m.input.currPage + 1, 2, 7, gUnknown_203B2E0->unk8.m.menuWinId);

    for (i = 0; i < gUnknown_203B2E0->unk8.m.input.currPageEntries; i++) {
        slotIndex = (gUnknown_203B2E0->pelipperBoardSlots[(gUnknown_203B2E0->unk8.m.input.currPage * gUnknown_203B2E0->unk8.m.input.entriesPerPage) + i]);
        mail = GetPelipperBoardSlotInfo(slotIndex);
        local.unk0[0] = gUnknown_203B2E0->unk8.m.menuWinId;
        local.y = GetMenuEntryYCoord(&gUnknown_203B2E0->unk8.m.input, i);
        sub_803B35C(mail, &local);

        if (IsMailinJobSlot(GetPelipperBoardSlotInfo(slotIndex)))
            local.unk43 = 2;

        CreateRescueTitle(&local);
    }

    sub_80073E0(gUnknown_203B2E0->unk8.m.menuWinId);
}

static s32 CountPelipperBoardSlots(void)
{
    s32 i;
    s32 counter = 0;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsPelipperBoardSlotEmpty(i)) {
            gUnknown_203B2E0->pelipperBoardSlots[counter] = i;
            counter++;
        }
    }

    return counter;
}

bool8 HasNoPelipperBoardJobs(void)
{
    s32 i;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsPelipperBoardSlotEmpty(i))
            return FALSE;
    }

    return TRUE;
}
