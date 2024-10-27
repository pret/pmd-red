#include "constants/input.h"
#include "global.h"
#include "globaldata.h"
#include "menu_input.h"
#include "sprite.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "bg_palette_buffer.h"
#include "input.h"
#include "text1.h"
#include "text2.h"
#include "game_options.h"

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

void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, 0, -1, gUnknown_80D485C, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, 0, -1, gUnknown_80D4880, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

extern u8 gUnknown_202E798[];

extern u8 *gUnknown_202E794;

struct UnkStruct_202E748
{
    u16 unk0;
    u16 unk2;
    u8 fill4;
    u8 fill5;
    u8 fill6;
    u8 fill7;
    u16 unk8;
    u16 unkA;
    u8 fillB;
    u8 fillC;
    u8 fillD;
    u8 fillE;
    u32 unk10;
    u8 fill14[6];
    u32 unk1C;
    u8 unk20;
    u32 unk24;
};

extern struct UnkStruct_202E748 gUnknown_202E748;
extern u32 gUnknown_202EC10;
extern const MenuItem *gUnknown_202EC14;
extern void *gUnknown_202EC18;
extern u32 gUnknown_202EC1C;

extern MenuInputStructSub gUnknown_202EC28;

struct SubStruct_203B198
{
    u8 fill0[0x18];
};

struct UnkStruct_203B198
{
    UnkTextStruct2 unk0;
    u8 unk18;
    u32 unk1C;
    Position unk20;
    u16 unk24;
    u16 unk26;
    u16 unk28;
    u8 fill2A[4];
    struct SubStruct_203B198 unk30;
    struct SubStruct_203B198 unk48;
};

extern struct UnkStruct_203B198 gUnknown_203B198;

extern const struct SubStruct_203B198 gUnknown_80D48AC;

extern const struct UnkTextStruct2 gUnknown_80D48DC;
extern const struct UnkTextStruct2 gUnknown_80D48C4;

extern UnkTextStruct1 gUnknown_2027370[4];
extern u16 gUnknown_202E77C;
extern u8 gUnknown_202E790;
extern u8 gUnknown_202E791;
extern u32 gUnknown_202E788;
extern u32 gUnknown_202E78C;
extern u32 gUnknown_202E784;

extern void SetCharacterMask(int a0);
extern void sub_8008274(s32 a0, const u8 *compressedData, s32 a2);
extern void sub_80073E0(s32 a0);

void CreateMenuDialogueBoxAndPortrait(const u8 *text, u32 a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, struct MonPortraitMsg *monPortraitPtr, u16 r10)
{
    bool8 portraitOn = FALSE;

    xxx_format_string(text, gUnknown_202E798, gUnknown_202E798 + 999, r10);
    gUnknown_202E794 = gUnknown_202E798;
    gUnknown_202E748.unk24 = a1;
    gUnknown_202EC10 = a5;
    gUnknown_202EC14 = menuItems;
    gUnknown_202EC18 = arg_0;
    gUnknown_202EC1C = r9;
    sub_801317C(&gUnknown_202EC28);
    if (r10 & 0x10) {
        gUnknown_203B198.unk0 = gUnknown_80D48DC;
    }
    else {
        gUnknown_203B198.unk0 = gUnknown_80D48C4;
    }

    gUnknown_203B198.unk24 = 0;
    gUnknown_203B198.unk26 = 0;
    gUnknown_203B198.unk28 = 0;
    gUnknown_203B198.unk18 = 0x40;

    if (monPortraitPtr != NULL && monPortraitPtr->faceData != NULL && monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].gfx != 0) {
        s32 i;

        gUnknown_203B198.unk20.x = monPortraitPtr->pos.x;
        gUnknown_203B198.unk20.y = monPortraitPtr->pos.y;
        gUnknown_203B198.unk24 = 5;
        gUnknown_203B198.unk26 = 5;
        gUnknown_203B198.unk28 = 5;
        for (i = 0; i < 16; i++) {
            SetBGPaletteBufferColorArray(224 + i, &monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].pal[i * 4]);
        }
        portraitOn = TRUE;
        if (monPortraitPtr->unkE) {
            gUnknown_203B198.unk1C = 7;
        }
        else {
            gUnknown_203B198.unk1C = 5;
        }
    }

    gUnknown_203B198.unk30 = gUnknown_80D48AC;
    gUnknown_203B198.unk48 = gUnknown_80D48AC;
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(&gUnknown_203B198.unk0, TRUE, TRUE);
    gUnknown_202E748.unk0 = 4;
    gUnknown_202E748.unk2 = 4;
    gUnknown_202E748.unk8 = 0x70;
    gUnknown_202E748.unkA = (gUnknown_2027370[0].unk2 * 8) + 34;
    gUnknown_202E748.unk10 = 7;
    gUnknown_202E748.unk1C = 0;
    gUnknown_202E748.unk20 = 0;
    SetCharacterMask((r10 & 0x10) ? 8 : 3);
    gUnknown_202E744 = 1;
    gUnknown_202E77C = r10;
    if (r10 & 0x20) {
        gUnknown_202E790 = 1;
    }
    else {
        gUnknown_202E790 = 0;
    }

    if (r10 & 0x400) {
        SetWindowBGColor();
    }
    gUnknown_202E788 = 1;
    gUnknown_202E78C = 1;
    UnpressButtons();
    gUnknown_202E791 = 0;
    gUnknown_202E784 = 0;
    if (portraitOn) {
        const u8 *data = monPortraitPtr->faceData->sprites[monPortraitPtr->spriteId].gfx;

        sub_80073B8(1);
        if (!monPortraitPtr->flip) {
            sub_8008274(1, data, 0xE);
        }
        else {
            sub_800836C(1, data, 0xE);
        }
        sub_80073E0(1);
    }
}
