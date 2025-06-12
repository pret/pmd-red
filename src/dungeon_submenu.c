#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "dungeon_submenu.h"
#include "dungeon_vram.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_3.h"

// The reason this short file(just 1 function) exists is because of the pksdir string which usually signifies the file's beginning.

extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonSubMenuItemsCount;

extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);

void CreateDungeonMenuSubWindow(WindowTemplate *mainWindow, s32 subWindowX)
{
    s32 i;
    WindowTemplates windows = {
        .id = {
            [0] = WIN_TEMPLATE_DUMMY,
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {22, 4},
                .width = 6,
                .height = 4,
                .unk10 = 4,
            },
            [2] = WIN_TEMPLATE_DUMMY,
            [3] = WIN_TEMPLATE_DUMMY,
        }
    };

    windows.id[0] = *mainWindow;
    windows.id[0].unk0 = 0x80;

    gDungeonMenu.menuIndex = 0;
    gDungeonMenu.entriesPerPage = gDungeonSubMenuItemsCount;
    gDungeonMenu.currPageEntries = gDungeonSubMenuItemsCount;
    gDungeonMenu.currPage = 0;
    gDungeonMenu.pagesCount = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 0;
    gDungeonMenu.windowId = 1;
    gDungeonMenu.leftRightArrowsPos.x = 0;
    gDungeonMenu.leftRightArrowsPos.y = 0;
    gDungeonMenu.unk14 = gDungeonMenu.cursorArrowPos;

    ResetTouchScreenMenuInput(&gDungeonMenu.touchScreen);

    windows.id[1].pos.x = subWindowX;
    windows.id[1].width = 28 - subWindowX;
    windows.id[1].height = windows.id[1].unk10 = sub_80095E4(gDungeonMenu.entriesPerPage, 0);
    DungeonShowWindows(&windows, FALSE);
    sub_80137B0(&gDungeonMenu, windows.id[1].height * 8);
    sub_80073B8(1);

    for (i = 0; i < gDungeonSubMenuItemsCount; i++) {
        s32 colorId, y;
        u8 text[20];

        colorId = (CanSubMenuItemBeChosen(i) != FALSE) ? 7 : 2;
        sprintfStatic(text, _("{COLOR}%c%s"), colorId, GetDungeonSubMenuItemString(i));
        y = GetMenuEntryYCoord(&gDungeonMenu, i);
        PrintStringOnWindow(8, y, text, 1, 0);
    }
    sub_80073E0(1);
}
