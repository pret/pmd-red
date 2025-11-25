#include "global.h"
#include "globaldata.h"
#include "debug_field_map_window.h"
#include "constants/input.h"
#include "text_3.h"
#include "music_util.h"
#include "ground_main.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"
#include "ground_map_conversion_table.h"
#include "map_files_table.h"

EWRAM_INIT static struct MenuHeaderWindow *sDebugWindow = {NULL};

static const WindowTemplate sDummyWinTemplate = WIN_TEMPLATE_DUMMY;

static const WindowTemplate sDebugWindowTemplate = {
    .flags = WINTEMPLATE_FLAG_NONE,
    .type = WINDOW_TYPE_WITH_HEADER,
    .pos = { 2, 2 },
    .width = 24,
    .height = 17,
    .totalHeight = 17,
    .unk12 = 0,
    .header = NULL,
};

static void ShowWindowsWithHeader(void);
static void PrintCurrentPageText(void);

#define WINDOW_ID_DEBUG 3

bool8 DebugFieldMapWindow_Init(void)
{
    sDebugWindow = MemoryAlloc(sizeof(*sDebugWindow), 8);
    sDebugWindow->m.menuWinId = WINDOW_ID_DEBUG;
    sDebugWindow->m.menuWindow = &sDebugWindow->m.windows.id[WINDOW_ID_DEBUG];
    RestoreSavedWindows(&sDebugWindow->m.windows);
    sDebugWindow->m.windows.id[sDebugWindow->m.menuWinId] = sDebugWindowTemplate;
    sDebugWindow->m.menuWindow->header = &sDebugWindow->header;
    ResetUnusedInputStruct();
    ShowWindows(&sDebugWindow->m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sDebugWindow->m.input, MAP_COUNT, 10, sDebugWindow->m.menuWinId);
    ShowWindowsWithHeader();
    PrintCurrentPageText();
    return TRUE;
}

void DebugFieldMapWindow_MoveMenuTo(s16 entryId_)
{
    s32 entryId = entryId_;
    MoveMenuToEntryId(&sDebugWindow->m.input, entryId);
    ShowWindowsWithHeader();
    PrintCurrentPageText();
}

u32 DebugFieldMapWindow_GetInput(void)
{
    switch (GetKeyPress(&sDebugWindow->m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return MENU_INPUT_B_PRESS;
        case INPUT_A_BUTTON:
            return MENU_INPUT_A_PRESS;
        default:
            if (MenuCursorUpdate(&sDebugWindow->m.input, TRUE)) {
                ShowWindowsWithHeader();
                PrintCurrentPageText();
                return MENU_INPUT_DPAD;
            }
            return MENU_INPUT_NOTHING;
    }
}

s16 DebugFieldMapWindow_GetCurrentIndex(void)
{
    return GET_CURRENT_MENU_ENTRY(sDebugWindow->m.input);
}

UNUSED static void ShowDebugFieldMapWindow(bool8 addCursorSprite)
{
    sDebugWindow->m.input.totalEntriesCount = MAP_COUNT;
    MenuUpdatePagesData(&sDebugWindow->m.input);
    ShowWindowsWithHeader();
    PrintCurrentPageText();
    if (addCursorSprite)
        AddMenuCursorSprite(&sDebugWindow->m.input);
}

void DebugFieldMapWindow_Free(void)
{
    if (sDebugWindow != NULL) {
        sDebugWindow->m.windows.id[sDebugWindow->m.menuWinId] = sDummyWinTemplate;
        ResetUnusedInputStruct();
        ShowWindows(&sDebugWindow->m.windows, TRUE, TRUE);
        FREE_AND_SET_NULL(sDebugWindow);
    }
}

static void ShowWindowsWithHeader(void)
{
    sDebugWindow->header.count = 1;
    sDebugWindow->header.currId = 0;
    sDebugWindow->header.width = 8;
    sDebugWindow->header.f3 = 0;

    ResetUnusedInputStruct();
    ShowWindows(&sDebugWindow->m.windows, TRUE, TRUE);

    UPDATE_MENU_WINDOW_HEIGHT(sDebugWindow->m);
}

static void PrintCurrentPageText(void)
{
    s32 x, y, pageNum;
    s32 i;

    CallPrepareTextbox_8008C54(sDebugWindow->m.menuWinId);
    sub_80073B8(sDebugWindow->m.menuWinId);
    PrintStringOnWindow(10, 0, _("Field"), sDebugWindow->m.menuWinId, 0);

    x = (sDebugWindow->header.width * 8) - 2;
    pageNum = sDebugWindow->m.input.currPage + 1;
    PrintNumOnWindow(x, 0, pageNum, 2, 7, sDebugWindow->m.menuWinId);

    // This line has no real effect. It's a magic 'fakematch' to fool agb into generating the same asm. It can be removed if you don't care about matching.
    if (x) { i = 0; }

    for (i = 0; i < sDebugWindow->m.input.currPageEntries; i++) {
        s16 index = (sDebugWindow->m.input.currPage * sDebugWindow->m.input.entriesPerPage) + i;
        const GroundConversionStruct *mapConversionPtr = &gGroundMapConversionTable[index];
        const struct MapFilesStruct *mapFilesPtr = &gMapFilesTable[mapConversionPtr->mapFileTableId];

        y = GetMenuEntryYCoord(&sDebugWindow->m.input, i);
        PrintStringOnWindow(8, y, mapFilesPtr->bplFileName, sDebugWindow->m.menuWinId, 0);

        y = GetMenuEntryYCoord(&sDebugWindow->m.input, i);
        PrintStringOnWindow(62, y, mapConversionPtr->text, sDebugWindow->m.menuWinId, 0);
    }

    sub_80073E0(sDebugWindow->m.menuWinId);
}
