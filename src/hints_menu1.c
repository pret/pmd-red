#include "global.h"
#include "globaldata.h"
#include "text_3.h"
#include "music_util.h"
#include "common_strings.h"
#include "hints_menu1.h"
#include "input.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT MenuWindow *sUnknown_203B264 = {NULL};

#include "data/hints_menu1.h"

static void DrawHintSelectionMenu(void);

static void sub_801E594(void);

bool8 sub_801E3F0(u32 a0)
{
    if (sUnknown_203B264 == NULL)
        sUnknown_203B264 = MemoryAlloc(sizeof(*sUnknown_203B264), 8);

    sUnknown_203B264->menuWinId = a0;
    sUnknown_203B264->menuWindow = &sUnknown_203B264->windows.id[a0];
    RestoreSavedWindows(&sUnknown_203B264->windows);
    sUnknown_203B264->windows.id[sUnknown_203B264->menuWinId] = sUnknown_80DC0BC;
    sub_8012D08(sUnknown_203B264->menuWindow, 10);
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B264->windows, TRUE, TRUE);
    CreateMenuOnWindow(&sUnknown_203B264->input, 5, 10, a0);
    sub_801E594();
    DrawHintSelectionMenu();
    return TRUE;
}

u32 sub_801E474(bool8 a0)
{
    if (a0 == 0) {
        sub_8013660(&sUnknown_203B264->input);
        return 0;
    }

    switch(GetKeyPress(&sUnknown_203B264->input))
    {
        case 2:
            PlayMenuSoundEffect(1);
            return 2;
        case 1:
            PlayMenuSoundEffect(0);
            return 3;
        case 4:
            PlayMenuSoundEffect(4);
            return 4;
        default:
            if(MenuCursorUpdate(&sUnknown_203B264->input, 1))
            {
                sub_801E594();
                DrawHintSelectionMenu();
                return 1;
            }
            else
                return 0;
    }
}

s32 GetChosenHintIndex(void)
{
    return GET_CURRENT_MENU_ENTRY(sUnknown_203B264->input);
}

void CreateHintSelectionScreen(bool8 cursorSprite)
{
    ResetUnusedInputStruct();
    ShowWindows(&sUnknown_203B264->windows, FALSE, FALSE);
    MenuUpdatePagesData(&sUnknown_203B264->input);
    sub_801E594();
    DrawHintSelectionMenu();

    if (cursorSprite)
        AddMenuCursorSprite(&sUnknown_203B264->input);
}

void sub_801E54C(void)
{
    if (sUnknown_203B264 != NULL) {
        sUnknown_203B264->windows.id[sUnknown_203B264->menuWinId] = sUnknown_80DC0A0;
        ResetUnusedInputStruct();
        ShowWindows(&sUnknown_203B264->windows, TRUE, TRUE);
        MemoryFree(sUnknown_203B264);
        sUnknown_203B264 = NULL;
    }
}

static void sub_801E594(void)
{
    UPDATE_MENU_WINDOW_HEIGHT(*sUnknown_203B264);
}

static void DrawHintSelectionMenu(void)
{
    s32 hintIndex;
    s32 y;

    CallPrepareTextbox_8008C54(sUnknown_203B264->menuWinId);
    sub_80073B8(sUnknown_203B264->menuWinId);
    PrintStringOnWindow(16, 0, sHints, sUnknown_203B264->menuWinId, 0);

    for (hintIndex = 0; hintIndex < HINT_MAX; hintIndex++) {
        y = GetMenuEntryYCoord(&sUnknown_203B264->input, hintIndex);
        PrintStringOnWindow(10, y, gCommonHints[hintIndex].heading, sUnknown_203B264->menuWinId, 0);
    }

    sub_80073E0(sUnknown_203B264->menuWinId);
}
