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
#include "pokemon.h"
#include "code_800D090.h"
#include "rescue_team_info.h"
#include "event_flag.h"

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

// This kinda looks like the 'true' beginning of the file
struct SubStruct_203B198
{
    u8 unk0;
    u32 unk4; // x34
    u16 unk8; // x38
    u16 unkA; // x3A
    u16 unkC; // x3C
    u16 unkE; // x3E
    u16 unk10; // x40
    u8 fill12[0x48-0x42]; // x42
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

extern s32 gUnknown_202E738;
extern s32 gUnknown_202E73C;
extern s32 gUnknown_202E740;
extern s32 gUnknown_202E744;
extern struct UnkDrawStringStruct gUnknown_202E748;
extern u32 gUnknown_202EC10;
extern const MenuItem *gUnknown_202EC14;
extern void *gUnknown_202EC18;
extern s32 gUnknown_202EC1C;
extern u8 gUnknown_202E798[];
extern const u8 *gUnknown_202E794;
extern MenuInputStructSub gUnknown_202EC28;
extern struct UnkStruct_203B198 gUnknown_203B198;
extern UnkTextStruct1 gUnknown_2027370[4];
extern u16 gUnknown_202E77C;
extern u8 gUnknown_202E790;
extern u8 gUnknown_202E791;
extern u32 gUnknown_202E788;
extern u32 gUnknown_202E78C;
extern u32 gUnknown_202E784;
extern s32 gUnknown_202E780;
extern SpriteOAM gUnknown_202E6E0;
extern void (*gUnknown_203B088)(s32 a0);
extern MenuStruct gUnknown_202EBC0;
extern u8 gUnknown_202EB80[];
extern u8 gUnknown_202E628[];
extern u8 gPlayerName[][80];
extern u8 gTeamName[];
extern u8 gUnknown_202E5D8[];

// Only read, but never written to. Possibly used in Blue?
struct NeverWrittenToStruct202EC20
{
    struct SubStruct_203B198 unk0;
    const u8 *unk18;
};

extern struct NeverWrittenToStruct202EC20 *gUnknown_202EC20;

extern const struct SubStruct_203B198 gUnknown_80D48AC;
extern const struct UnkTextStruct2 gUnknown_80D48DC;
extern const struct UnkTextStruct2 gUnknown_80D48C4;
extern const u32 gUnknown_80D48A0[];
extern const u8 gUnknown_80D48F8[];
extern const u8 gUnknown_80D4900[];
extern const u8 gUnknown_80D4904[];
extern const u8 gUnknown_80D4908[];
extern const u8 gUnknown_80D4910[];
extern const u8 gUnknown_80D48F4[];

extern void SetCharacterMask(int a0);
extern void sub_8008274(s32 a0, const u8 *compressedData, s32 a2);
extern void sub_80073E0(s32 a0);
extern void sub_8011A04(void);

void sub_8014A88(void);
bool8 sub_8014B94(void);
static void nullsub_35(void);
bool8 AppendString_8014FA8(const u8 *, u8 **, u8 *, u16 r3);

// 'd', 'v' and 'V'
EWRAM_DATA s32 gFormatData_202DE30[10] = {0};
// 'i', apparently only i0 and i1 are actually used though it's yet to be verified
EWRAM_DATA u8 gFormatItems[4][80] = {0};
// 'm' which probably stands for 'monster', available through m0 to m9
EWRAM_DATA u8 gAvailablePokemonNames[10][80] = {0};

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

void CreateDialogueBoxAndPortrait(const u8 *text, void *param_2, struct MonPortraitMsg *monPortraitPtr, u16 param_4)
{
    CreateMenuDialogueBoxAndPortrait(text, param_2, -1, NULL, NULL, 3, 0, monPortraitPtr, param_4);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultYes(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, gUnknown_80D485C, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

void CreateYesNoDialogueBoxAndPortrait_DefaultNo(const u8 *text, struct MonPortraitMsg *monPortraitPtr, u16 param_3)
{
    CreateMenuDialogueBoxAndPortrait(text, NULL, -1, gUnknown_80D4880, NULL, 3, 0, monPortraitPtr, param_3 | 0x300);
}

void CreateMenuDialogueBoxAndPortrait(const u8 *text, void *a1, u32 r9, const MenuItem *menuItems, void *arg_0, u32 a5, u32 unknownUnused, struct MonPortraitMsg *monPortraitPtr, u16 r10)
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

void sub_8014490(void)
{
    gUnknown_202E744 = 0;
    gUnknown_202EC1C = 0;
}

s32 sub_80144A4(s32 *a0)
{
    if (a0 != NULL) {
        *a0 = gUnknown_202EC1C;
    }
    return gUnknown_202E744;
}

void DrawDialogueBoxString(void)
{
    bool8 keepLooping = TRUE;

    gUnknown_202E784++;
    while (keepLooping) {
        switch (gUnknown_202E744) {
            case 0: {
                keepLooping = FALSE;
            }
            break;
            case 1: {
                const u8 *str = gUnknown_202E794;
                s32 r7;

                if (gUnknown_202E790 != 0) {
                    r7 = 99999;
                }
                else {
                    r7 = gUnknown_202E788;
                }
                gUnknown_202E748.unk2C = 0;
                sub_80073B8(0);
                while (r7 > 0) {
                     str = xxx_handle_format_global(str, &gUnknown_202E748);
                     if (gUnknown_202E748.unk21 != 0) {
                        break;
                     }
                     if (gUnknown_202E748.unk20 != 0) {
                        if (gUnknown_202E748.unk2 > 34) {
                            gUnknown_202E744 = 8;
                            gUnknown_202E780 = gUnknown_202E738;
                        }
                        else {
                            gUnknown_202E744 = 7;
                            gUnknown_202E780 = gUnknown_202E73C;
                        }
                        gUnknown_202E791 = 0;
                        break;
                     }
                     if (*str == '\0') {
                        break;
                     }

                     if (*str == '\r' || *str == '\n') {
                        gUnknown_202E748.unk0 = 4;
                        gUnknown_202E748.unk2 += 11;
                        str++;
                     }
                     else {
                        u32 sp;

                        str = xxx_get_next_char_from_string(str, &sp);
                        gUnknown_202E748.unk0 += xxx_call_draw_char(gUnknown_202E748.unk0, gUnknown_202E748.unk2, sp, gUnknown_202E748.unk10, 0);
                        gUnknown_202E748.unk2C = gUnknown_202E78C;
                     }

                     if (gUnknown_202E748.unk2 > 34) {
                        if (!(gUnknown_202E77C & 0x10)) {
                            gUnknown_202E748.unk1C = 0;
                            gUnknown_202E748.unk20 = 1;
                            gUnknown_202E744 = 8;
                            gUnknown_202E791 = 0;
                            gUnknown_202E780 = gUnknown_202E738;
                            break;
                        }
                        else {
                            gUnknown_202E748.unk2 = 4;
                        }
                     }
                     r7--;
                }
                sub_80073E0(0);
                gUnknown_202E794 = str;
                sub_801317C(&gUnknown_202EC28);
                if (gUnknown_202E794[0] == '\0') {
                    if (gUnknown_202EC14 != NULL) {
                        gUnknown_202E744 = 3;
                    }
                    else {
                        gUnknown_202E744 = 6;
                    }
                    keepLooping = FALSE;
                }
                else {
                    gUnknown_202E748.unk30 = 0;
                    if (gUnknown_202E748.unk20 != 0) {
                        if (gUnknown_202E744 == 1) {
                            gUnknown_202E744 = 7;
                            gUnknown_202E791 = 0;
                            gUnknown_202E780 = gUnknown_202E738;
                        }
                        keepLooping = FALSE;
                    }
                    else {
                        gUnknown_202E744 = 2;
                    }
                }
            }
            break;
            case 2: {
                if (gUnknown_202E77C & 4) {
                    sub_8011A04();
                }
                if (!(gUnknown_202E77C & 2)) {
                    if (gUnknown_202E77C & 0x40 && gRealInputs.pressed & AB_BUTTONS) {
                        gUnknown_202E790 = 1;
                        gUnknown_202E748.unk30 = 99999;
                    }
                }

                if (++gUnknown_202E748.unk30 > gUnknown_202E748.unk2C) {
                    gUnknown_202E744 = 1;
                    gUnknown_202E748.unk21 = 0;
                }
                else {
                    keepLooping = FALSE;
                }
            }
            break;
            case 6: {
                if (gUnknown_202E77C & 0x100) {
                    gUnknown_202E744 = 9;
                    gUnknown_202E791 = 0;
                    if (gUnknown_202E740 > 0) {
                        gUnknown_202E780 = gUnknown_202E740 - gUnknown_202E784;
                        if (gUnknown_202E780 < 0) {
                            gUnknown_202E744 = 11;
                            gUnknown_202E780 = 0;
                        }
                    }
                    else {
                        gUnknown_202E780 = gUnknown_202E738;
                    }
                }
                else {
                    gUnknown_202E744 = 11;
                }
            }
            break;
            case 7:
            case 8:
            case 9: {
                bool8 buttonPress = FALSE;
                gUnknown_202E748.unk20 = 0;
                nullsub_34(&gUnknown_202EC28, 0);
                if (!(gUnknown_202E77C & 1)) {
                    buttonPress = TRUE;
                }
                else
                {
                    if (gUnknown_202E77C & 2)
                    {
                        if (gUnknown_202E780 > 0) {
                            gUnknown_202E780--;
                        }
                        else {
                            buttonPress = TRUE;
                        }
                    }
                    else if (gRealInputs.pressed & AB_BUTTONS || gUnknown_202EC28.a_button) {
                        buttonPress = TRUE;
                    }
                    else if ((gRealInputs.held & (DPAD_ANY | B_BUTTON)) == B_BUTTON) {
                        buttonPress = TRUE;
                    }
                    else if (gUnknown_202EC28.unk5) {
                        buttonPress = TRUE;
                    }
                }

                if (!buttonPress) {
                    gUnknown_202E791++;
                    if (!(gUnknown_202E77C & 0x2) && gUnknown_202E791 & 8) {
                        u32 shape, tileNum, palNum, pal;

                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_BPP;

                        shape = 1;
                        shape <<= SPRITEOAM_SHIFT_SHAPE;
                        gUnknown_202E6E0.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
                        gUnknown_202E6E0.attrib1 |= shape;

                        gUnknown_202E6E0.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
                        gUnknown_202E6E0.attrib2 &= ~SPRITEOAM_MASK_SIZE;

                        tileNum = 0x3F0 << SPRITEOAM_SHIFT_TILENUM;
                        gUnknown_202E6E0.attrib3 &= ~SPRITEOAM_MASK_TILENUM;
                        gUnknown_202E6E0.attrib3 |= tileNum;

                        gUnknown_202E6E0.attrib3 &= ~SPRITEOAM_MASK_PRIORITY;

                        pal = 15;
                        palNum = (pal & SPRITEOAM_MAX_PALETTENUM) << SPRITEOAM_SHIFT_PALETTENUM;
                        gUnknown_202E6E0.attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
                        gUnknown_202E6E0.attrib3 |= palNum;


                        if (gUnknown_202E77C & 0x10) {
                            u32 var = 0x780;
                            gUnknown_202E6E0.unk6 &= 0xF;
                            gUnknown_202E6E0.unk6 |= var;
                            gUnknown_202E6E0.attrib2 &= ~SPRITEOAM_MASK_X;
                            gUnknown_202E6E0.attrib2 |= 0x70;
                        }
                        else {
                            s16 x;

                            u32 var = ((gUnknown_202E748.unkA + 1) & 0xFFF) << 4;
                            gUnknown_202E6E0.unk6 &= 0xF;
                            gUnknown_202E6E0.unk6 |= var;
                            x = gUnknown_202E748.unk8;
                            gUnknown_202E6E0.attrib2 &= ~SPRITEOAM_MASK_X;
                            gUnknown_202E6E0.attrib2 |= x & 0x1FF;
                        }

                        AddSprite(&gUnknown_202E6E0, 0x100, NULL, NULL);
                    }
                }
                else {
                    if (*gUnknown_202E794 == '\0') {
                        gUnknown_202E744 = 11;
                    }
                    else if (gUnknown_202E744 == 9) {
                        gUnknown_202E744 = 11;
                    }
                    else if (gUnknown_202E744 == 8) {
                        gUnknown_202E748.unk0 = 4;
                        if (gUnknown_202E748.unk2 > 34) {
                            gUnknown_202E748.unk2 = 4;
                            if (gUnknown_202E77C & 0x10) {
                                CallPrepareTextbox_8008C54(0);
                                gUnknown_202E744 = 1;
                            }
                            else if (gUnknown_202E748.unk1C != 0) {
                                CallPrepareTextbox_8008C54(0);
                                gUnknown_202E744 = 1;
                            }
                            else {
                                gUnknown_202E744 = 10;
                                gUnknown_202E748.unk28 = 0;
                            }
                        }
                        else {
                            gUnknown_202E744 = 1;
                        }
                    }
                    else {
                        gUnknown_202E744 = 1;
                    }

                    gUnknown_202E748.unk8 = 0x70;
                    gUnknown_202E748.unkA = (gUnknown_2027370[0].unk2 * 8) + 34;
                }
                keepLooping = FALSE;
            }
            break;
            case 10: {
                gUnknown_202E748.unk28++;
                gUnknown_203B088(0);
                if (gUnknown_202E748.unk28 > 17) {
                    gUnknown_202E744 = 1;
                }
                keepLooping = FALSE;
            }
            break;
            case 11: {
                if (gUnknown_202E77C & 0x200) {
                    ResetUnusedInputStruct();
                    xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
                    gUnknown_202E744 = 0;
                }
                else {
                    gUnknown_202E744 = 0;
                }
                keepLooping = FALSE;
            }
            break;
            case 3: {
                sub_8014A88();
                gUnknown_202E744 = 4;
                keepLooping = FALSE;
            }
            break;
            case 4: {
                if (sub_8014B94()) {
                    gUnknown_202E744 = 5;
                }
                keepLooping = FALSE;
            }
            break;
            case 5: {
                nullsub_35();
                gUnknown_202E744 = 11;
            }
            break;
        }
    }
}

void sub_8014A88(void)
{
    s32 r2, r1;
    u8 text[128];
    const MenuItem *menuItem = gUnknown_202EC14;
    s32 r5 = 0;
    s32 r7 = 0;
    s32 i;

    for (i = 0; i < 10; menuItem++, i++) {
        s32 val;

        if (menuItem->text == NULL)
            break;

        r5 += 12;;
        xxx_format_string(menuItem->text, text, text + sizeof(text), 0);
        val = sub_8008ED0(text);
        if (r7 < val) {
            r7 = val;
        }
    }

    r2 = r5 / 8;
    if (r5 % 8)
        r2++;

    gUnknown_203B198.unk30.unk4 = gUnknown_202EC10;
    r1 = r7 / 8;
    r1 += 2;
    gUnknown_203B198.unk30.unkC = r1;
    gUnknown_203B198.unk30.unk10 = r2;
    gUnknown_203B198.unk30.unkE = r2;
    gUnknown_203B198.unk30.unk8 = 28 - r1;
    gUnknown_203B198.unk30.unkA = 14 - r2;
    gUnknown_203B198.unk0.unk0 = 0x80;
    gUnknown_203B198.unk18 = 0xC0;
    if (gUnknown_202EC20 != NULL) {
        gUnknown_203B198.unk48 = gUnknown_202EC20->unk0;
    }
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(&gUnknown_203B198.unk0, TRUE, FALSE);
    sub_8012D60(&gUnknown_202EBC0, gUnknown_202EC14, gUnknown_80D48A0, gUnknown_202EC18, gUnknown_202EC1C, 2);
    if (gUnknown_202EC20 != NULL) {
        sub_80073B8(3);
        PrintStringOnWindow(4, 2, gUnknown_202EC20->unk18, 3, 0);
        sub_80073E0(3);
    }
}

bool8 sub_8014B94(void)
{
    if (!sub_8012FD8(&gUnknown_202EBC0)) {
        sub_8013114(&gUnknown_202EBC0, &gUnknown_202EC1C);
        return TRUE;
    }
    else {
        return FALSE;
    }
}

static void UNUSED nullsub_35(void)
{
}

const u8 *xxx_format_string(const u8 *str, u8 *dst, u8 *dstMax, u16 flags)
{
    u8 txtArray[60];
    bool8 r10 = TRUE;
    bool8 r9 = TRUE;
    dstMax--;

    while (1) {
        u8 currChar = *str;

        if (currChar == '\0')
            break;
        if (currChar == '\r' || currChar == '\n') {
            if (flags & 0x80)
                break;
            r9 = TRUE;
        }
        else {
            if (r10) {
                r10 = FALSE;
                r9 = FALSE;
                if (flags & 8) {
                    AppendString_8014FA8(gUnknown_202E5D8, &dst, dstMax, flags);
                    AppendString_8014FA8(gUnknown_80D48F4, &dst, dstMax, flags);
                }
            }
            else if (r9) {
                r9 = FALSE;
            }
        }

        if (currChar == '#') {
            u8 chrPls1 = str[1];
            if (chrPls1 == 'P' || chrPls1 == 'p') {
                r10 = TRUE;
                r9 = TRUE;
            }
            if (dst + 1 < dstMax) {
                *(dst++) = '#';
                *(dst++) = chrPls1;
            }

            str += 2;
        }
        else if (currChar == '$') {
            const u8 *txtPtr = NULL;
            str++;

            switch (*str) {
                case 'i':
                    str++;
                    txtPtr = gFormatItems[*str - '0'];
                    str++;
                    break;
                case 'm':
                    str++;
                    if (*str == 'm') {
                        PokemonStruct1 *monStruct = sub_808D3BC();
                        txtPtr = gUnknown_202EB80;
                        PrintColoredPokeNameToBuffer(gUnknown_202EB80, monStruct, 0);
                    }
                    else {
                        txtPtr = gAvailablePokemonNames[*str - '0'];
                        str++;
                    }
                    break;
                case 'n':
                    str++;
                    txtPtr = gPlayerName[*str - '0'];
                    str++;
                    break;
                case 't':
                    str++;
                    if (sub_80023E4(0)) {
                        sub_80920D8(gTeamName);
                    }
                    else {
                        strcpy(gTeamName, gUnknown_80D48F8); // ????
                    }
                    txtPtr = gTeamName;
                    break;
                case 'h':
                    str++;
                    txtPtr = gUnknown_202E628;
                    break;
                case 'd':
                    str++;
                    sprintfStatic(txtArray, gUnknown_80D4900, gFormatData_202DE30[*(str++) - '0']);
                    txtPtr = txtArray;
                    break;
                case 'v': {
                    s32 a;
                    u8 *unkTxtPtr;

                    str++;
                    a = gFormatData_202DE30[*(str++) - '0'];
                    sprintfStatic(txtArray, gUnknown_80D4904, *(str++) - '0', a);
                    unkTxtPtr = txtArray;
                    while (*unkTxtPtr != '\0') {
                        if (*unkTxtPtr == ' ') {
                            *unkTxtPtr = '`';
                        }
                        unkTxtPtr++;
                    }
                    txtPtr = txtArray;
                    }
                    break;
                // the same as above except "%0*d" instead of "%*d"
                case 'V': {
                    s32 a;
                    u8 *unkTxtPtr;

                    str++;
                    a = gFormatData_202DE30[*(str++) - '0'];
                    sprintfStatic(txtArray, gUnknown_80D4908, *(str++) - '0', a);
                    unkTxtPtr = txtArray;
                    while (*unkTxtPtr != '\0') {
                        if (*unkTxtPtr == ' ') {
                            *unkTxtPtr = '`';
                        }
                        unkTxtPtr++;
                    }
                    txtPtr = txtArray;
                    }
                    break;
                case '$':
                    txtPtr = gUnknown_80D4910;
                    break;
                case '-':
                    str++;
                    break;
            }

            if (txtPtr != NULL) {

                if (AppendString_8014FA8(txtPtr, &dst, dstMax, flags))
                    break;
            }
        }
        else if (currChar == 0x81 || currChar == 0x82 || currChar == 0x83 || currChar == 0x84 || currChar == 0x87) {
            if (dst < dstMax) {
                *(dst++) = currChar;
            }
            str++;
            if (*str == '\0')
                break;
            if (dst < dstMax) {
                *(dst++) = *str;
            }
            str++;
        }
        else {
            if (dst < dstMax) {
                *(dst++) = currChar;
            }
            str++;
        }
    }

    *dst = 0;
    if (*str == '\r') str++;
    if (*str == '\n') str++;

    return str;
}

bool8 AppendString_8014FA8(const u8 *str, u8 **dstPtr, u8 *dstMax, u16 flags)
{
    u8 *dst = *dstPtr;
    while (*str != '\0') {
        if (flags & 0x80 && *str == '\r') {
            *dstPtr = dst;
            return TRUE;
        }
        if (dst < dstMax) {
            *dst = *str;
            dst++;
        }
        str++;
    }

    *dstPtr = dst;
    return FALSE;
}

#define FORMAT_STR_MAX_LEN 500

void PrintFormatStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    u8 formatString[FORMAT_STR_MAX_LEN];

    xxx_format_string(str, formatString, formatString + FORMAT_STR_MAX_LEN, 0);
    formatString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow(x, y, formatString, windowId, terminatingChr);
}

void PrintFormatStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing)
{
    u8 formatString[FORMAT_STR_MAX_LEN];

    xxx_format_string(str, formatString, formatString + FORMAT_STR_MAX_LEN, 0);
    formatString[FORMAT_STR_MAX_LEN - 1] = '\0';
    PrintStringOnWindow2(x, y, formatString, windowId, terminatingChr, lineSpacing);
}

//
