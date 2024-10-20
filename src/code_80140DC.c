#include "constants/input.h"
#include "global.h"
#include "globaldata.h"
#include "menu_input.h"
#include "sprite.h"
#include "code_80118A4.h"
#include "code_80130A8.h"

extern s32 gUnknown_202E738;
extern s32 gUnknown_202E73C;
extern s32 gUnknown_202E740;
extern s32 gUnknown_202E744;

#include "data/code_80140DC.h"

// TODO: move to menu_input
extern UnkTextStruct2 gUnknown_80D47C8[4];

void sub_80140B4(UnkTextStruct2 *a0)
{
    s32 i;

    for(i = 0; i < 4; i++)
    {
        a0[i] = gUnknown_80D47C8[i];
    }
}

// End of menu_input.c

void sub_80140DC(void)
{
    Position pos;

    pos.x = 200;
    pos.y = 128;
    SetSavingIconCoords(&pos);
    sub_8011830();
}

void sub_80140F8(void)
{
    Position pos;

    pos.x = 188;
    pos.y = 64;
    SetSavingIconCoords(&pos);
    sub_8011830();
}

void sub_8014114(void) {
    xxx_call_start_bg_music();
    SetSavingIconCoords(NULL);
}

void nullsub_201(void) {}

u32 sub_8014128(void) {
    if(sub_8012AE8() == INPUT_B_BUTTON) return 0;
    else return 1;
}

u32 sub_801413C(void)
{
    return 0;
}

u32 sub_8014140(void)
{
    return 0;
}

void sub_8014144(void)
{
    gUnknown_202E744 = 0;
    gUnknown_202E738 = 60;
    gUnknown_202E73C = 60;
    gUnknown_202E740 = 0;
}

void sub_801416C(s32 param_1,s32 param_2)
{
    if (param_1 < -1) {
        gUnknown_202E738 = param_2;
        gUnknown_202E740 = -param_1;
    }
    else {
        gUnknown_202E738 = param_1;
        gUnknown_202E740 = 0;
    }
    gUnknown_202E73C = (param_2 < 0 ) ? 0 : param_2;
}

void CreateDialogueBoxAndPortrait(const u8 *text, u32 param_2, struct MonPortraitMsg *monPortraitPtr, u16 param_4)
{
    CreateMenuDialogueBoxAndPortrait(text, param_2, -1, NULL, NULL, 3, 0, monPortraitPtr, param_4);
}

void sub_80141E0(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, 0, -1, gUnknown_80D485C, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

void sub_8014214(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, 0, -1, gUnknown_80D4880, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

