#include "global.h"
#include "globaldata.h"
#include "code_800D090.h"
#include "code_80118A4.h"
#include "code_80972F4.h"
#include "code_80A26CC.h"
#include "constants/colors.h"
#include "constants/input.h"
#include "dungeon.h"
#include "input.h"
#include "makuhita_dojo2.h"
#include "memory.h"
#include "menu_input.h"
#include "text1.h"
#include "text2.h"

static EWRAM_DATA_2 MakuhitaDojoWork2 *sMakuhitaDojoWork2 = {0};

#include "data/makuhita_dojo2.h" // 80E07EC

static void MakuhitaDojo_DrawCourseList(void);

static void sub_80304C8(void);
static s32 sub_8030668(void);

bool8 sub_80302E8(s32 param_1, UnkTextStruct2_sub *param_2, u32 param_3)
{
    if (MakuhitaDojo_ReturnFalse())
        return FALSE;

    if (sMakuhitaDojoWork2 == NULL)
        sMakuhitaDojoWork2 = MemoryAlloc(sizeof(MakuhitaDojoWork2), 8);

    sMakuhitaDojoWork2->s30.s0.unk34 = param_1;
    sMakuhitaDojoWork2->s30.s0.unk38 = &sMakuhitaDojoWork2->s30.s0.unk3C[param_1];
    sub_8006518(sMakuhitaDojoWork2->s30.s0.unk3C);
    sMakuhitaDojoWork2->s30.s0.unk3C[sMakuhitaDojoWork2->s30.s0.unk34] = sUnknown_80E0804;
    sMakuhitaDojoWork2->s30.s0.unk38->unk14 = sMakuhitaDojoWork2->s30.unk9C;

    if (param_2 != NULL)
        sMakuhitaDojoWork2->s30.s0.unk3C[sMakuhitaDojoWork2->s30.s0.unk34].unk8 = *param_2;

    sub_8012D08(sMakuhitaDojoWork2->s30.s0.unk38, param_3);
    ResetUnusedInputStruct();
    sub_800641C(sMakuhitaDojoWork2->s30.s0.unk3C, TRUE, TRUE);
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
        sMakuhitaDojoWork2->s30.s0.unk3C[sMakuhitaDojoWork2->s30.s0.unk34] = sUnknown_80E07EC;
        ResetUnusedInputStruct();
        sub_800641C(sMakuhitaDojoWork2->s30.s0.unk3C, TRUE, TRUE);
        MemoryFree(sMakuhitaDojoWork2);
        sMakuhitaDojoWork2 = NULL;
    }
}

static void sub_80304C8(void)
{
    sMakuhitaDojoWork2->s30.unk9C[0] = 1;
    sMakuhitaDojoWork2->s30.unk9C[1] = 0;
    sMakuhitaDojoWork2->s30.unk9C[2] = 8;
    sMakuhitaDojoWork2->s30.unk9C[3] = 0;

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

    sub_8008C54(sMakuhitaDojoWork2->s30.s0.unk34);
    sub_80073B8(sMakuhitaDojoWork2->s30.s0.unk34);
    xxx_call_draw_string(10, 0, sCourses, sMakuhitaDojoWork2->s30.s0.unk34, 0);
    sub_8012BC4((sMakuhitaDojoWork2->s30.unk9C[2] * 8) + 4, 0, sMakuhitaDojoWork2->s30.s0.input.unk1E + 1, 2, 7, sMakuhitaDojoWork2->s30.s0.unk34);

    for (i = 0; i < sMakuhitaDojoWork2->s30.s0.input.unk1A; i++) {
        iVar6 = sMakuhitaDojoWork2->unk0[sMakuhitaDojoWork2->s30.s0.input.unk1E * sMakuhitaDojoWork2->s30.s0.input.unk1C + i];
        dungeonIndex = sub_80A2740(iVar6);

        mazeIndex = sub_80A2668(iVar6);

        y = sub_8013800(&sMakuhitaDojoWork2->s30.s0.input, i);
        color = COLOR_WHITE_2; // COLOR_WHITE again?
        if ((bool8)IsMazeCompleted(mazeIndex)) {
            xxx_call_draw_string(8, y, sStarBullet, sMakuhitaDojoWork2->s30.s0.unk34, 0);
            color = COLOR_GREEN;
        }
        sprintfStatic(buffer, sFmtColor, color, GetDungeonName1(dungeonIndex));
        xxx_call_draw_string(16, y, buffer, sMakuhitaDojoWork2->s30.s0.unk34, 0);
    }
    sub_80073E0(sMakuhitaDojoWork2->s30.s0.unk34);
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
