#include "global.h"
#include "globaldata.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80972F4.h"
#include "code_80A26CC.h"
#include "dungeon.h"
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
        sMakuhitaDojoWork2 = MemoryAlloc(sizeof(MakuhitaDojoWork2), 8);

    sMakuhitaDojoWork2->s30.s0.winId = param_1;
    sMakuhitaDojoWork2->s30.s0.unk38 = &sMakuhitaDojoWork2->s30.s0.windows.id[param_1];
    RestoreSavedWindows(&sMakuhitaDojoWork2->s30.s0.windows);
    sMakuhitaDojoWork2->s30.s0.windows.id[sMakuhitaDojoWork2->s30.s0.winId] = sUnknown_80E0804;
    sMakuhitaDojoWork2->s30.s0.unk38->header = &sMakuhitaDojoWork2->s30.header;

    if (param_2 != NULL)
        sMakuhitaDojoWork2->s30.s0.windows.id[sMakuhitaDojoWork2->s30.s0.winId].pos = *param_2;

    sub_8012D08(sMakuhitaDojoWork2->s30.s0.unk38, param_3);
    ResetUnusedInputStruct();
    ShowWindows(&sMakuhitaDojoWork2->s30.s0.windows, TRUE, TRUE);
    sub_8013818(&sMakuhitaDojoWork2->s30.s0.input, sub_8030668(), param_3, param_1);
    sub_80304C8();
    MakuhitaDojo_DrawCourseList();
    return TRUE;
}

u32 sub_80303AC(bool8 param_1)
{
    if (param_1 == FALSE) {
        sub_8013660(&sMakuhitaDojoWork2->s30.s0.input);
        return 0;
    }

    switch (GetKeyPress(&sMakuhitaDojoWork2->s30.s0.input)) {
        case INPUT_B_BUTTON:
            PlayMenuSoundEffect(1);
            return 2;
        case INPUT_A_BUTTON:
            PlayMenuSoundEffect(0);
            return 3;
        default:
            if (sub_80138B8(&sMakuhitaDojoWork2->s30.s0.input, 1)) {
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
    return sMakuhitaDojoWork2->unk0[(sMakuhitaDojoWork2->s30.s0.input.unk1E * sMakuhitaDojoWork2->s30.s0.input.unk1C) + sMakuhitaDojoWork2->s30.s0.input.menuIndex];
}

UNUSED static void sub_8030444(bool8 a0)
{
    sMakuhitaDojoWork2->s30.s0.input.unk22 = sub_8030668();
    sub_8013984(&sMakuhitaDojoWork2->s30.s0.input);
    sub_80304C8();
    MakuhitaDojo_DrawCourseList();
    if (a0)
        AddMenuCursorSprite(&sMakuhitaDojoWork2->s30.s0.input);
}

void sub_8030480(void)
{
    if (sMakuhitaDojoWork2 != NULL) {
        sMakuhitaDojoWork2->s30.s0.windows.id[sMakuhitaDojoWork2->s30.s0.winId] = sUnknown_80E07EC;
        ResetUnusedInputStruct();
        ShowWindows(&sMakuhitaDojoWork2->s30.s0.windows, TRUE, TRUE);
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

    SUB_80095E4_CALL(sMakuhitaDojoWork2->s30.s0);
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

    CallPrepareTextbox_8008C54(sMakuhitaDojoWork2->s30.s0.winId);
    sub_80073B8(sMakuhitaDojoWork2->s30.s0.winId);
    PrintStringOnWindow(10, 0, sCourses, sMakuhitaDojoWork2->s30.s0.winId, 0);
    sub_8012BC4((sMakuhitaDojoWork2->s30.header.width * 8) + 4, 0, sMakuhitaDojoWork2->s30.s0.input.unk1E + 1, 2, 7, sMakuhitaDojoWork2->s30.s0.winId);

    for (i = 0; i < sMakuhitaDojoWork2->s30.s0.input.unk1A; i++) {
        iVar6 = sMakuhitaDojoWork2->unk0[sMakuhitaDojoWork2->s30.s0.input.unk1E * sMakuhitaDojoWork2->s30.s0.input.unk1C + i];
        dungeonIndex = sub_80A2740(iVar6);

        mazeIndex = sub_80A2668(iVar6);

        y = GetMenuEntryYCoord(&sMakuhitaDojoWork2->s30.s0.input, i);
        color = COLOR_WHITE_2; // COLOR_WHITE again?
        if ((bool8)IsMazeCompleted(mazeIndex)) {
            PrintStringOnWindow(8, y, sStarBullet, sMakuhitaDojoWork2->s30.s0.winId, 0);
            color = COLOR_GREEN;
        }
        sprintfStatic(buffer, sFmtColor, color, GetDungeonName1(dungeonIndex));
        PrintStringOnWindow(16, y, buffer, sMakuhitaDojoWork2->s30.s0.winId, 0);
    }
    sub_80073E0(sMakuhitaDojoWork2->s30.s0.winId);
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
