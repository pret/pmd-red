#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "structs/str_802C39C.h"
#include "structs/str_wonder_mail.h"
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
#include "wonder_mail_802C4C8.h"

static EWRAM_INIT struct unkStruct_203B2E0* gUnknown_203B2E8 = {NULL};
static EWRAM_INIT u16 gUnknown_203B2EC = {0};

#include "data/wonder_mail_802C4C8.h"

static s32 CountAcceptedJobs(void);

static void sub_802C6DC(void);

bool8 sub_802C4C8(s32 a0, DungeonPos *a1, u32 a2)
{
    if (HasNoAcceptedJobs())
        return FALSE;

    gUnknown_203B2E8 = MemoryAlloc(sizeof(struct unkStruct_203B2E0), MEMALLOC_GROUP_8);
    gUnknown_203B2E8->unk8.m.menuWinId = a0;
    gUnknown_203B2E8->unk8.m.menuWindow = &gUnknown_203B2E8->unk8.m.windows.id[a0];
    RestoreSavedWindows(&gUnknown_203B2E8->unk8.m.windows);

    gUnknown_203B2E8->unk8.m.windows.id[gUnknown_203B2E8->unk8.m.menuWinId] = sUnknown_80DFCFC;
    gUnknown_203B2E8->unk8.m.menuWindow->header = &gUnknown_203B2E8->unk8.header;

    if (a1 != NULL)
        gUnknown_203B2E8->unk8.m.windows.id[gUnknown_203B2E8->unk8.m.menuWinId].pos = *a1;

    sub_8012D34(gUnknown_203B2E8->unk8.m.menuWindow, a2);
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E8->unk8.m.windows, TRUE, TRUE);
    CreateMenuOnWindowTwoLinesEntry(&gUnknown_203B2E8->unk8.m.input, CountAcceptedJobs(), a2, a0);
    gUnknown_203B2E8->unk8.m.input.menuIndex = gUnknown_203B2EC;
    MenuUpdatePagesData(&gUnknown_203B2E8->unk8.m.input);
    sub_802C6DC();
    DrawJobListMenu();
    return TRUE;
}

u32 sub_802C598(bool8 a0)
{
    if (!a0) {
        sub_8013660(&gUnknown_203B2E8->unk8.m.input);
        return 0;
    }

    switch (GetKeyPress(&gUnknown_203B2E8->unk8.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        case INPUT_START_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_INFO);
            return 4;
    }

    if (MenuCursorUpdate(&gUnknown_203B2E8->unk8.m.input, 1)) {
        sub_802C6DC();
        DrawJobListMenu();
        return 1;
    }
    return 0;
}

u8 GetPelipperBoardSlotIndex(void)
{
    return gUnknown_203B2E8->pelipperBoardSlots[GET_CURRENT_MENU_ENTRY(gUnknown_203B2E8->unk8.m.input)];
}

void sub_802C640(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&gUnknown_203B2E8->unk8.m.windows, FALSE, FALSE);
    gUnknown_203B2E8->unk8.m.input.totalEntriesCount = CountAcceptedJobs();
    MenuUpdatePagesData(&gUnknown_203B2E8->unk8.m.input);
    sub_802C6DC();
    DrawJobListMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&gUnknown_203B2E8->unk8.m.input);
}

void sub_802C688(void)
{
    if (gUnknown_203B2E8 != NULL) {
        gUnknown_203B2EC = gUnknown_203B2E8->unk8.m.input.menuIndex;
        gUnknown_203B2E8->unk8.m.windows.id[gUnknown_203B2E8->unk8.m.menuWinId] = sUnknown_80DFCE4;
        ResetUnusedInputStruct();
        ShowWindows(&gUnknown_203B2E8->unk8.m.windows, TRUE, TRUE);
        MemoryFree(gUnknown_203B2E8);
        gUnknown_203B2E8 = NULL;
    }
}

static void sub_802C6DC(void)
{
    gUnknown_203B2E8->unk8.header.count = gUnknown_203B2E8->unk8.m.input.pagesCount;
    gUnknown_203B2E8->unk8.header.currId = gUnknown_203B2E8->unk8.m.input.currPage;
    gUnknown_203B2E8->unk8.header.width = 12;
    gUnknown_203B2E8->unk8.header.f3 = 0;

    UPDATE_TWO_LINES_MENU_WINDOW_HEIGHT(gUnknown_203B2E8->unk8.m);
}

void DrawJobListMenu(void)
{
    WonderMail *mail;
    s32 i;
    s32 r4;
    s32 x;
    unkStruct_802C39C local;

    CallPrepareTextbox_8008C54(gUnknown_203B2E8->unk8.m.menuWinId);
    sub_80073B8(gUnknown_203B2E8->unk8.m.menuWinId);
    r4 = gUnknown_203B2E8->unk8.m.input.currPage * 8;
    x = r4;
    x += 10;
    PrintStringOnWindow(x, 0, sJobList, gUnknown_203B2E8->unk8.m.menuWinId, 0);

    r4 += 4;
    x = r4 + (gUnknown_203B2E8->unk8.header.width * 8);
    PrintNumOnWindow(x, 0, gUnknown_203B2E8->unk8.m.input.currPage + 1, 2, 7, gUnknown_203B2E8->unk8.m.menuWinId);

    for (i = 0;  i < gUnknown_203B2E8->unk8.m.input.currPageEntries; i++) {
        mail = GetJobSlotInfo(gUnknown_203B2E8->pelipperBoardSlots[(gUnknown_203B2E8->unk8.m.input.currPage * gUnknown_203B2E8->unk8.m.input.entriesPerPage) + i]);
        local.unk0[0] = gUnknown_203B2E8->unk8.m.menuWinId;
        local.y = GetMenuEntryYCoord(&gUnknown_203B2E8->unk8.m.input, i);
        sub_803B35C(mail, &local);
        CreateRescueTitle(&local);
    }

    sub_80073E0(gUnknown_203B2E8->unk8.m.menuWinId);
}

static s32 CountAcceptedJobs(void)
{
    s32 i;
    s32 sum = 0;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsJobSlotEmpty(i)) {
            gUnknown_203B2E8->pelipperBoardSlots[sum] = i;
            sum++;
        }
    }

    return sum;
}

bool8 HasNoAcceptedJobs(void)
{
    s32 i;

    for (i = 0; i < MAX_ACCEPTED_JOBS; i++) {
        if (!IsJobSlotEmpty(i))
            return FALSE;
    }

    return TRUE;
}
