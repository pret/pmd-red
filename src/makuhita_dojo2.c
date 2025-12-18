#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "code_800D090.h"
#include "music_util.h"
#include "training_maze.h"
#include "code_80A26CC.h"
#include "dungeon_info.h"
#include "input.h"
#include "makuhita_dojo2.h"
#include "memory.h"
#include "menu_input.h"
#include "text_1.h"
#include "text_2.h"

static EWRAM_INIT MakuhitaDojoWork2 *sMakuhitaDojoWork2 = {NULL};

#include "data/makuhita_dojo2.h" // 80E07EC

static void MakuhitaDojo_DrawCourseList(void);

static void sub_80304C8(void);
static s32 sub_8030668(void);

bool8 sub_80302E8(s32 param_1, DungeonPos *param_2, u32 param_3)
{
    if (MakuhitaDojo_ReturnFalse())
        return FALSE;

    if (sMakuhitaDojoWork2 == NULL)
        sMakuhitaDojoWork2 = MemoryAlloc(sizeof(MakuhitaDojoWork2), MEMALLOC_GROUP_8);

    sMakuhitaDojoWork2->s30.m.menuWinId = param_1;
    sMakuhitaDojoWork2->s30.m.menuWindow = &sMakuhitaDojoWork2->s30.m.windows.id[param_1];
    RestoreSavedWindows(&sMakuhitaDojoWork2->s30.m.windows);
    sMakuhitaDojoWork2->s30.m.windows.id[sMakuhitaDojoWork2->s30.m.menuWinId] = sUnknown_80E0804;
    sMakuhitaDojoWork2->s30.m.menuWindow->header = &sMakuhitaDojoWork2->s30.header;

    if (param_2 != NULL)
        sMakuhitaDojoWork2->s30.m.windows.id[sMakuhitaDojoWork2->s30.m.menuWinId].pos = *param_2;

    sub_8012D08(sMakuhitaDojoWork2->s30.m.menuWindow, param_3);
    ResetUnusedInputStruct();
    ShowWindows(&sMakuhitaDojoWork2->s30.m.windows, TRUE, TRUE);
    CreateMenuOnWindow(&sMakuhitaDojoWork2->s30.m.input, sub_8030668(), param_3, param_1);
    sub_80304C8();
    MakuhitaDojo_DrawCourseList();
    return TRUE;
}

u32 sub_80303AC(bool8 param_1)
{
    if (param_1 == FALSE) {
        sub_8013660(&sMakuhitaDojoWork2->s30.m.input);
        return 0;
    }

    switch (GetKeyPress(&sMakuhitaDojoWork2->s30.m.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_BACK);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(MENU_SFX_ACCEPT);
            return 3;
        default:
            if (MenuCursorUpdate(&sMakuhitaDojoWork2->s30.m.input, 1)) {
                sub_80304C8();
                MakuhitaDojo_DrawCourseList();
                return 1;
            }
            else
                return 0;
    }
}

s16 sub_8030418(void)
{
    return sMakuhitaDojoWork2->unk0[GET_CURRENT_MENU_ENTRY(sMakuhitaDojoWork2->s30.m.input)];
}

UNUSED static void sub_8030444(bool8 a0)
{
    sMakuhitaDojoWork2->s30.m.input.totalEntriesCount = sub_8030668();
    MenuUpdatePagesData(&sMakuhitaDojoWork2->s30.m.input);
    sub_80304C8();
    MakuhitaDojo_DrawCourseList();
    if (a0)
        AddMenuCursorSprite(&sMakuhitaDojoWork2->s30.m.input);
}

void sub_8030480(void)
{
    if (sMakuhitaDojoWork2 != NULL) {
        sMakuhitaDojoWork2->s30.m.windows.id[sMakuhitaDojoWork2->s30.m.menuWinId] = sUnknown_80E07EC;
        ResetUnusedInputStruct();
        ShowWindows(&sMakuhitaDojoWork2->s30.m.windows, TRUE, TRUE);
        MemoryFree(sMakuhitaDojoWork2);
        sMakuhitaDojoWork2 = NULL;
    }
}

static void sub_80304C8(void)
{
    sMakuhitaDojoWork2->s30.header.count = 1;
    sMakuhitaDojoWork2->s30.header.currId = 0;
    sMakuhitaDojoWork2->s30.header.width = 8;
    sMakuhitaDojoWork2->s30.header.f3 = 0;

    UPDATE_MENU_WINDOW_HEIGHT(sMakuhitaDojoWork2->s30.m);
}

static void MakuhitaDojo_DrawCourseList(void)
{
    u8 dungeonIndex;
    s32 mazeIndex;
    s32 y;
    s32 iVar6;
    u32 color;
    s32 i;
    u8 buffer[256];

    CallPrepareTextbox_8008C54(sMakuhitaDojoWork2->s30.m.menuWinId);
    sub_80073B8(sMakuhitaDojoWork2->s30.m.menuWinId);
    PrintStringOnWindow(10, 0, sCourses, sMakuhitaDojoWork2->s30.m.menuWinId, 0);
    PrintNumOnWindow((sMakuhitaDojoWork2->s30.header.width * 8) + 4, 0, sMakuhitaDojoWork2->s30.m.input.currPage + 1, 2, 7, sMakuhitaDojoWork2->s30.m.menuWinId);

    for (i = 0; i < sMakuhitaDojoWork2->s30.m.input.currPageEntries; i++) {
        iVar6 = sMakuhitaDojoWork2->unk0[sMakuhitaDojoWork2->s30.m.input.currPage * sMakuhitaDojoWork2->s30.m.input.entriesPerPage + i];
        dungeonIndex = ScriptDungeonIdToDungeonId(iVar6);

        mazeIndex = sub_80A2668(iVar6);

        y = GetMenuEntryYCoord(&sMakuhitaDojoWork2->s30.m.input, i);
        color = COLOR_WHITE_2; // COLOR_WHITE again?
        if ((bool8)IsMazeCompleted(mazeIndex)) {
            PrintStringOnWindow(8, y, sStarBullet, sMakuhitaDojoWork2->s30.m.menuWinId, 0);
            color = COLOR_GREEN;
        }
        sprintfStatic(buffer, sFmtColor, color, GetDungeonName1(dungeonIndex));
        PrintStringOnWindow(16, y, buffer, sMakuhitaDojoWork2->s30.m.menuWinId, 0);
    }
    sub_80073E0(sMakuhitaDojoWork2->s30.m.menuWinId);
}

static s32 sub_8030668(void)
{
    s32 i;
    s32 counter;

    counter = 0;

    for (i = 0; i < NUM_DUNGEON_MAZE; i++) {
        if (sub_8097504(i)) {
            sMakuhitaDojoWork2->unk0[counter] = sub_80A26CC(i);
            counter++;
        }
    }
    return counter;
}

bool8 MakuhitaDojo_ReturnFalse(void)
{
    return FALSE;
}
