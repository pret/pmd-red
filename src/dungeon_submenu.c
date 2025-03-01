#include "global.h"
#include "globaldata.h"
#include "dungeon_submenu.h"
#include "menu_input.h"
#include "text.h"
#include "code_800D090.h"

// The reason this short file(just 1 function) exists is because of the pksdir string which usually signifies the file's beginning.

extern MenuInputStruct gDungeonMenu;
extern s32 gDungeonSubMenuItemsCount;

extern u8 *GetDungeonSubMenuItemString(s32 param_1);
extern bool8 CanSubMenuItemBeChosen(s32 param_1);
extern void DungeonShowWindows(Windows *a0, u8 a1);

void CreateDungeonMenuSubWindow(Window *mainWindow, s32 subWindowX)
{
    s32 i;
    Windows windows = {
        .id = {
            [0] = WINDOW_DUMMY,
            [1] = {
                .type = WINDOW_TYPE_NORMAL,
                .pos = {22, 4},
                .width = 6,
                .height = 4,
                .unk10 = 4,
            },
            [2] = WINDOW_DUMMY,
            [3] = WINDOW_DUMMY,
        }
    };

    windows.id[0] = *mainWindow;
    windows.id[0].unk0 = 0x80;

    gDungeonMenu.menuIndex = 0;
    gDungeonMenu.unk1C = gDungeonSubMenuItemsCount;
    gDungeonMenu.unk1A = gDungeonSubMenuItemsCount;
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unk4 = 0;
    gDungeonMenu.firstEntryY = 0;
    gDungeonMenu.unk0 = 1;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14 = gDungeonMenu.unk8;

    sub_801317C(&gDungeonMenu.unk28);

    windows.id[1].pos.x = subWindowX;
    windows.id[1].width = 28 - subWindowX;
    windows.id[1].height = windows.id[1].unk10 = sub_80095E4(gDungeonMenu.unk1C, 0);
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
