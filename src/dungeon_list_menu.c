#include "global.h"
#include "globaldata.h"
#include "dungeon_list_menu.h"
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
#include "constants/rescue_dungeon_id.h"

struct DungeonListMenu {
    // size: 0x15C
    s16 rescueDungeonIds[RESCUE_DUNGEON_COUNT];
    bool8 goIcon[RESCUE_DUNGEON_COUNT];
    bool8 jobInDungeon[RESCUE_DUNGEON_COUNT];
    bool8 showIcons;
    struct MenuHeaderWindow m;
};

static EWRAM_INIT struct DungeonListMenu *sDungeonListMenu = {NULL};

static const WindowTemplate sWinTemplateDummy = WIN_TEMPLATE_DUMMY;

// Never used in-game. It's slightly narrower as it doesn't have space for go/envelope icons.
static const WindowTemplate sWinTemplateNarrow = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = { 2, 2 },
    .width = 14,
    .height = 14,
    .totalHeight = 14,
    .unk12 = 0,
    .header = NULL,
};

static const WindowTemplate sWinTemplateWide = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = { 2, 2 },
    .width = 16,
    .height = 16,
    .totalHeight = 16,
    .unk12 = 0,
    .header = NULL,
};

static void ShowWindowWithHeader(void);
static void PrintCurrentPage(void);
static s32 CountAvailableDungeons(void);

bool8 DungeonListMenu_Init(u32 windowId, DungeonPos *winPos, s32 perPageCount, bool8 showIcons)
{
    if (HasZeroAvailableDungeons())
        return FALSE;

    if (sDungeonListMenu == NULL)
        sDungeonListMenu = MemoryAlloc(sizeof(struct DungeonListMenu), MEMALLOC_GROUP_8);

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

bool8 DungeonListMenu_MoveMenuTo(s32 _rescueDungeonId)
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

u32 DungeonListMenu_GetInput(u8 arrowType)
{
    if (arrowType == 0) {
        sub_8013660(&sDungeonListMenu->m.m.input);
        return MENU_INPUT_NOTHING;
    }
    else {
        switch (GetKeyPress(&sDungeonListMenu->m.m.input)) {
            case INPUT_B_BUTTON:
                PlayMenuSoundEffect(MENU_SFX_BACK);
                return MENU_INPUT_B_PRESS;
            case INPUT_A_BUTTON:
                PlayMenuSoundEffect(MENU_SFX_ACCEPT);
                return MENU_INPUT_A_PRESS;
            default:
                if (MenuCursorUpdate(&sDungeonListMenu->m.m.input, TRUE)) {
                    ShowWindowWithHeader();
                    PrintCurrentPage();
                    return MENU_INPUT_DPAD;
                }
                return MENU_INPUT_NOTHING;
        }
    }
}

s16 DungeonListMenu_GetCurrentRescueDungeonId(void)
{
    return sDungeonListMenu->rescueDungeonIds[GET_CURRENT_MENU_ENTRY(sDungeonListMenu->m.m.input)];
}

UNUSED static void DungeonListMenu_UpdateShowWindow(u8 arrowType)
{
    sDungeonListMenu->m.m.input.totalEntriesCount = CountAvailableDungeons();
    MenuUpdatePagesData(&sDungeonListMenu->m.m.input);
    ShowWindowWithHeader();
    PrintCurrentPage();

    if (arrowType != 0)
        AddMenuCursorSprite(&sDungeonListMenu->m.m.input);
}

void DungeonListMenu_Free(void)
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
            if (sDungeonListMenu->goIcon[index]) {
                PrintStringOnWindow(10,y,_("{ICON_GO}"),sDungeonListMenu->m.m.menuWinId,'\0');
            }
            else if (sDungeonListMenu->jobInDungeon[index]) {
                PrintStringOnWindow(10,y,_("{ENVELOPE_OPEN}"),sDungeonListMenu->m.m.menuWinId,'\0');
            }
            PrintStringOnWindow(24,y,GetRescueDungeonName(rescueDungId),sDungeonListMenu->m.m.menuWinId,'\0');
        }
    }
    else {
        for (counter = 0; counter < sDungeonListMenu->m.m.input.currPageEntries; counter++) {
            s32 y = GetMenuEntryYCoord(&sDungeonListMenu->m.m.input,counter);
            const u8 *name = GetRescueDungeonName(sDungeonListMenu->rescueDungeonIds[sDungeonListMenu->m.m.input.currPage * sDungeonListMenu->m.m.input.entriesPerPage + counter]);
            PrintStringOnWindow(8,y,name,sDungeonListMenu->m.m.menuWinId,0);
        }
    }
    sub_80073E0(sDungeonListMenu->m.m.menuWinId);
}

static s32 CountAvailableDungeons(void)
{
    s32 rescueDungeonId;
    s32 counter;
    s32 i;
    bool8 icons = FALSE; // Variable needed to match.

    counter = 0;
    for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
        rescueDungeonId = rescueDungeonId = (s16)i; // NOTE: weirdness needed for matching s16 memes
        if (IsRescueDungeonAvailable(i) && rescueDungeonId != RESCUE_DUNGEON_GREAT_CANYON_2 && rescueDungeonId != RESCUE_DUNGEON_MT_FREEZE_2) {
            sDungeonListMenu->rescueDungeonIds[counter] = rescueDungeonId;
            sDungeonListMenu->goIcon[counter] = icons;
            sDungeonListMenu->jobInDungeon[counter] = icons;
            if (sDungeonListMenu->showIcons && rescueDungeonId != RESCUE_DUNGEON_DUMMY) {
                s32 dungeonIndex = RescueDungeonToDungeonId(rescueDungeonId);
                bool8 goIcon = FALSE;
                if (rescueDungeonId < RESCUE_DUNGEON_DESERT_REGION) {
                    if (!sub_8097384(rescueDungeonId)) {
                        if (rescueDungeonId == RESCUE_DUNGEON_GREAT_CANYON) {
                            if (sub_8097384(RESCUE_DUNGEON_GREAT_CANYON_2)) {
                                sDungeonListMenu->rescueDungeonIds[counter] = RESCUE_DUNGEON_GREAT_CANYON_2;
                                goIcon = TRUE;
                            }
                        }
                        else if (rescueDungeonId == RESCUE_DUNGEON_MT_FREEZE) {
                            if (sub_8097384(RESCUE_DUNGEON_MT_FREEZE_2)) {
                                sDungeonListMenu->rescueDungeonIds[counter] = RESCUE_DUNGEON_MT_FREEZE_2;
                                goIcon = TRUE;
                            }
                        }
                    }
                    else {
                        goIcon = TRUE;
                    }
                }
                sDungeonListMenu->goIcon[counter] = goIcon;
                if (!goIcon && CountJobsinDungeon(dungeonIndex) > 0) {
                    sDungeonListMenu->jobInDungeon[counter] = TRUE;
                }
            }
            counter++;
        }
    }

    return counter;
}

bool8 HasZeroAvailableDungeons(void)
{
    s32 i;
    for (i = 0; i < RESCUE_DUNGEON_COUNT; i++) {
        if (IsRescueDungeonAvailable(i))
            return FALSE;
    }

    return TRUE;
}
