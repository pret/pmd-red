#include "global.h"
#include "globaldata.h"
#include "constants/input.h"
#include "text_3.h"
#include "music_util.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"
#include "rescue_scenario.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

#define MAX_SHOWN_DUNGEONS 46

struct DungeonListMenu {
    // size: 0x15C
    s16 rescueDungeonIds[MAX_SHOWN_DUNGEONS];
    bool8 goButton[MAX_SHOWN_DUNGEONS];
    bool8 jobInDungeon[MAX_SHOWN_DUNGEONS];
    bool8 showIcons;
    struct MenuHeaderWindow m;
};

static EWRAM_INIT struct DungeonListMenu *sDungeonListMenu = {NULL};

static const WindowTemplate sWinTemplateDummy = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sWinTemplateNarrow = {
    .unk0 = 0,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = {2, 2},
    .width = 14,
    .height = 14,
    .unk10 = 14,
    .unk12 = 0,
    .header = NULL,
};

static const WindowTemplate sWinTemplateWide = {
    .unk0 = 0,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = {2, 2},
    .width = 16,
    .height = 16,
    .unk10 = 16,
    .unk12 = 0,
    .header = NULL,
};

static void ShowWindowWithHeader(void);
static void PrintCurrentPage(void);
static s32 CountAvailableDungeons(void);

extern bool8 sub_802FCF0(void);

bool8 sub_802F73C(u32 windowId, DungeonPos *winPos, s32 perPageCount, bool8 showIcons)
{
    if (sub_802FCF0())
        return FALSE;

    if (sDungeonListMenu == NULL)
        sDungeonListMenu = MemoryAlloc(sizeof(struct DungeonListMenu), 8);

    sDungeonListMenu->showIcons = showIcons;
    sDungeonListMenu->m.m.menuWinId = windowId;
    sDungeonListMenu->m.m.menuWindow = &sDungeonListMenu->m.m.windows.id[sDungeonListMenu->m.m.menuWinId];
    RestoreSavedWindows(&sDungeonListMenu->m.m.windows);

    if (showIcons)
        sDungeonListMenu->m.m.windows.id[sDungeonListMenu->m.m.menuWinId] = sWinTemplateWide;
    else
        sDungeonListMenu->m.m.windows.id[sDungeonListMenu->m.m.menuWinId] = sWinTemplateNarrow;

    sDungeonListMenu->m.m.menuWindow->header = &sDungeonListMenu->m.header;

    if (winPos != NULL)
        sDungeonListMenu->m.m.windows.id[sDungeonListMenu->m.m.menuWinId].pos = *winPos;

    sub_8012D08(sDungeonListMenu->m.m.menuWindow, perPageCount);
    ResetUnusedInputStruct();
    ShowWindows(&sDungeonListMenu->m.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sDungeonListMenu->m.m.input, CountAvailableDungeons(), perPageCount, windowId);
    ShowWindowWithHeader();
    PrintCurrentPage();
    return TRUE;
}

bool8 sub_802F848(s32 _rescueDungeonId)
{
    s32 i;
    s32 rescueDungeonId = (s16) _rescueDungeonId; // cast needed

    for (i = 0; i < sDungeonListMenu->m.m.input.totalEntriesCount; i++) {
        if (sDungeonListMenu->rescueDungeonIds[i] == rescueDungeonId) {
            MoveMenuToEntryId(&sDungeonListMenu->m.m.input,i);
            ShowWindowWithHeader();
            PrintCurrentPage();
            return TRUE;
        }
    }
    MoveMenuToEntryId(&sDungeonListMenu->m.m.input,0);
    return FALSE;
}

u32 sub_802F8A0(u8 r0)
{
    if (r0 == 0) {
        sub_8013660(&sDungeonListMenu->m.m.input);
        return 0;
    }
    else {
        switch (GetKeyPress(&sDungeonListMenu->m.m.input)) {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(1);
                return 2;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(0);
                return 3;
            default:
                if (MenuCursorUpdate(&sDungeonListMenu->m.m.input, 1) != 0) {
                    ShowWindowWithHeader();
                    PrintCurrentPage();
                    return 1;
                }
                else {
                    return 0;
                }
        }
    }
}

s16 sub_802F90C(void)
{
    return sDungeonListMenu->rescueDungeonIds[GET_CURRENT_MENU_ENTRY(sDungeonListMenu->m.m.input)];
}

void sub_802F938(u8 r0)
{
    sDungeonListMenu->m.m.input.totalEntriesCount = CountAvailableDungeons();
    MenuUpdatePagesData(&sDungeonListMenu->m.m.input);
    ShowWindowWithHeader();
    PrintCurrentPage();

    if (r0 != 0)
        AddMenuCursorSprite(&sDungeonListMenu->m.m.input);
}

void sub_802F974(void)
{
    if (sDungeonListMenu != NULL) {
        sDungeonListMenu->m.m.windows.id[sDungeonListMenu->m.m.menuWinId] = sWinTemplateDummy;
        ResetUnusedInputStruct();
        ShowWindows(&sDungeonListMenu->m.m.windows, TRUE, TRUE);
        FREE_AND_SET_NULL(sDungeonListMenu);
    }
}

static void ShowWindowWithHeader(void)
{
    sDungeonListMenu->m.header.count = 1;
    sDungeonListMenu->m.header.currId = 0;
    sDungeonListMenu->m.header.width = 8;
    sDungeonListMenu->m.header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(sDungeonListMenu->m.m);
}

static void PrintCurrentPage(void)
{
    s32 counter;

    CallPrepareTextbox_8008C54(sDungeonListMenu->m.m.menuWinId);
    sub_80073B8(sDungeonListMenu->m.m.menuWinId);
    PrintStringOnWindow(10,0,_("Dungeons"),sDungeonListMenu->m.m.menuWinId,0);
    PrintNumOnWindow(sDungeonListMenu->m.header.width * 8 + 4,0,sDungeonListMenu->m.m.input.currPage + 1,2,7,sDungeonListMenu->m.m.menuWinId);
    if (sDungeonListMenu->showIcons) {
        for (counter = 0; counter < sDungeonListMenu->m.m.input.currPageEntries; counter++) {
            s32 y = GetMenuEntryYCoord(&sDungeonListMenu->m.m.input,counter);
            s32 index = sDungeonListMenu->m.m.input.currPage * sDungeonListMenu->m.m.input.entriesPerPage + counter;
            s32 rescueDungId = sDungeonListMenu->rescueDungeonIds[index];
            if (sDungeonListMenu->goButton[index]) {
                PrintStringOnWindow(10,y,_("{ICON_GO}"),sDungeonListMenu->m.m.menuWinId,'\0');
            }
            else if (sDungeonListMenu->jobInDungeon[index]) {
                PrintStringOnWindow(10,y,_("{ENVELOPE_OPEN}"),sDungeonListMenu->m.m.menuWinId,'\0');
            }
            PrintStringOnWindow(24,y,sub_80974A0(rescueDungId),sDungeonListMenu->m.m.menuWinId,'\0');
        }
    }
    else {
        for (counter = 0; counter < sDungeonListMenu->m.m.input.currPageEntries; counter++) {
            s32 y = GetMenuEntryYCoord(&sDungeonListMenu->m.m.input,counter);
            const u8 *name = sub_80974A0(sDungeonListMenu->rescueDungeonIds[sDungeonListMenu->m.m.input.currPage * sDungeonListMenu->m.m.input.entriesPerPage + counter]);
            PrintStringOnWindow(8,y,name,sDungeonListMenu->m.m.menuWinId,0);
        }
    }
    sub_80073E0(sDungeonListMenu->m.m.menuWinId);
}

static inline void sub_802FBF4_sub(u8 *test, s32 counter)
{
    test[counter] = 0;
}

static s32 CountAvailableDungeons(void)
{
    bool8 bVar1;
    u32 dungeonIndex;
    s32 iVar6;
    s32 counter;
    s32 i;

    counter = 0;
    for (i = 0; i < MAX_SHOWN_DUNGEONS; i++) {
        iVar6 = iVar6 = (s16)i; // NOTE: LOLOL
        if (((sub_80A27CC(i) != 0) && (iVar6 != 0x13)) && (iVar6 != 0x1d)) {
            bool8 a = 0;
            bool8 b = 0;
            sDungeonListMenu->rescueDungeonIds[counter] = iVar6;
            sDungeonListMenu->jobInDungeon[counter] = a;
            sDungeonListMenu->goButton[counter] = b;
            if ((sDungeonListMenu->showIcons) && (iVar6 != 0xd)) {
                dungeonIndex = sub_80A270C(i);
                bVar1 = FALSE;
                if (0x1e >= iVar6)
                {
                    if (sub_8097384(iVar6) == 0) {
                        if (iVar6 == 6) {
                            if (sub_8097384(0x13) != 0) {
                                sDungeonListMenu->rescueDungeonIds[counter] = 0x13;
                                bVar1 = TRUE;
                            }
                        }
                        else if ((iVar6 == 10) && (sub_8097384(0x1d) != 0)) {
                            sDungeonListMenu->rescueDungeonIds[counter] = 0x1d;
                            bVar1 = TRUE;
                        }
                    }
                    else {
                        bVar1 = TRUE;
                    }
                }
                sDungeonListMenu->goButton[counter] = bVar1;
                if ((!bVar1) && (0 < CountJobsinDungeon(dungeonIndex))) {
                    sDungeonListMenu->jobInDungeon[counter] = 1;
                }
            }
            counter++;
        }
    }

    return counter;
}

bool8 sub_802FCF0(void)
{
    s32 i;

    for (i = 0; i < MAX_SHOWN_DUNGEONS; i++) {
        if (sub_80A27CC(i))
            return FALSE;
    }

    return TRUE;
}
