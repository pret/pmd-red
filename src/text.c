#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "text.h"
#include "decompress.h"
#include "code_8009804.h"
#include "code_800558C.h"
#include "cpu.h"
#include "structs/str_text.h"
#include "file_system.h"

struct CharMapStruct
{
    s32 unk0;
    struct unkChar *unk4;
};

// data.s

// data2.s
extern const char gUnknown_80B88B0[]; // "font"
extern const char gUnknown_80B88B8[]; // "fontsp"
extern const char gUnknown_80B88C0[]; // "fontsppa"

// system_sbin.s
extern const struct FileArchive gSystemFileArchive;

// Todo fix gUnknown_3000E94 being accessed as s16/u8
extern s16 gUnknown_3000E94[];

EWRAM_DATA UnkTextStruct1 gUnknown_2027370[4] = {0};
EWRAM_DATA static struct CharMapStruct *sCharmaps[2] = {NULL};
EWRAM_DATA static s16 sCharacterSpacing = 0;
EWRAM_DATA u8 gUnknown_202749A[11] = {0};
EWRAM_DATA bool8 gUnknown_20274A5 = FALSE;
EWRAM_DATA static u8 sUnknown_20274A6[6] = {0};
EWRAM_DATA static s32 sCurrentCharmap = 0;
EWRAM_DATA static vu32 sUnknown_20274B0 = 0;
EWRAM_DATA static u32 sUnknown_20274B4[0xEC0] = {0};
EWRAM_DATA static OpenedFile *sCharmapFiles[3] = {NULL};
EWRAM_DATA static Windows sUnknown_202AFC0 = {0};
EWRAM_DATA static s32 sUnknown_202B020 = 0;
EWRAM_DATA static s32 sUnknown_202B024 = 0;
EWRAM_DATA static s32 sCharHeight[2] = {0};
EWRAM_DATA static u32 sTextShadowMask = 0; // Some text color info is stored; retrieve via "& 0xF"
EWRAM_DATA static u8 sDrawTextShadow = 0;
EWRAM_DATA ALIGNED(4) u16 gUnknown_202B038[4][32][32] = {0};

// These text-related functions were deemed important as they're copied and run from IWRAM for improved performance.
static void sub_8272774(UnkTextStruct1 *txtStructs, s32 id);
static void sub_8272884(UnkTextStruct1 *txtStructs, s32 id);
static void sub_82729B8(UnkTextStruct1 *txtStructs, s32 id);
static void sub_8272A8C(UnkTextStruct1 *txtStructs, s32 id);
void sub_8272760(s32 id);
void sub_8272870(s32 id);
void sub_82729A4(s32 id);
void sub_8272A78(s32 id);

EWRAM_INIT void (*gIwramTextFunc1)(s32 a0) = sub_8272760;
EWRAM_INIT void (*gIwramTextFunc2)(s32 a0) = sub_8272870;
EWRAM_INIT void (*gIwramTextFunc3)(s32 a0) = sub_82729A4;
EWRAM_INIT void (*gIwramTextFunc4)(s32 a0) = sub_8272A78;

// This variable is only used in InitGraphics function, which may or may not belong to text.c
EWRAM_INIT u8 gUnknown_203B090 = 0;

static void SaveUnkTextStructAndXXX_8006438(const Windows *a0, bool8 a1, bool8 a2, DungeonPos *a3);
static void sub_8006554(UnkTextStruct1 *a0, u32 *a1, u32 *a2, u16 *a3, u32 a4, const Window *a5, bool8 a6, u32 a7, DungeonPos *a8, u8 a9);
static void sub_800677C(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3);
static void sub_80069CC(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4);
static void sub_8006AC4(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4);
static void sub_8006B70(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4);
static void sub_8006C44(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3);
static void sub_8006E94(UnkTextStruct1 *a0, s32 a1, u32 a2, const WindowHeader *a3, u16 *a4);
static u32 xxx_draw_char(struct UnkTextStruct1 *a0, s32 x, s32 y, u32 a3, u32 color, u32 a5);
static void nullsub_129(u32 a0, s32 x, s32 y, s32 a3, u32 color);
static void sub_8007958(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color);
static void sub_8007AA4(struct UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color);
static void sub_8007BA8(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color);
static void sub_8007D00(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color);
static void sub_8007E64(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);
static void sub_8008030(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);
static void DisplayMonPortrait(UnkTextStruct1 *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4);
static void DisplayMonPortraitFlipped(UnkTextStruct1 *a0, s32 a1, const u8 *compressedData, s32 a3);
static void sub_80084A4(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8);
static void sub_8008818(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);
static bool8 xxx_update_bg_vram(UnkTextStruct1 *a0);
static void sub_800898C(void);
static void sub_80089AC(const Window *r4, DungeonPos *r5_Str);
static void PrepareTextbox_8008C6C(UnkTextStruct1 *strArr, u32 strId);
static void xxx_draw_string(UnkTextStruct1 *strArr, s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 characterSpacing, s32 lineSpacing);
static const u8 *HandleTextFormat(UnkTextStruct1 *strArr, const u8 *str, struct UnkDrawStringStruct *sp);
static void sub_8009388(void);
static s32 InterpretColorChar(u8 a0);

static const u32 gUnknown_80B853C[16] =
{
    0x66666666,
    0x00000000,
    0x11111111,
    0x22222222,
    0x33333333,
    0x44444444,
    0x55555555,
    0x66666666,
    0x77777777,
    0x88888888,
    0x99999999,
    0xAAAAAAAA,
    0xBBBBBBBB,
    0xCCCCCCCC,
    0xDDDDDDDD,
    0xEEEEEEEE,
};

static const Windows gUnknown_80B857C =
{
    .a0 = {
        [0] = {.type = WINDOW_TYPE_NORMAL},
        [1] = {.type = WINDOW_TYPE_NORMAL},
        [2] = {.type = WINDOW_TYPE_NORMAL},
        [3] = {.type = WINDOW_TYPE_NORMAL},
    }
};

static const struct unkShiftData gCharMasksOffsets[8] =
{
    [0] = {.bytesA = 0xFFFFFFFF, .bytesB = 0x00000000, .shift_left = 0x00, .shift_right = 0x20},
    [1] = {.bytesA = 0x0FFFFFFF, .bytesB = 0xF0000000, .shift_left = 0x04, .shift_right = 0x1C},
    [2] = {.bytesA = 0x00FFFFFF, .bytesB = 0xFF000000, .shift_left = 0x08, .shift_right = 0x18},
    [3] = {.bytesA = 0x000FFFFF, .bytesB = 0xFFF00000, .shift_left = 0x0C, .shift_right = 0x14},
    [4] = {.bytesA = 0x0000FFFF, .bytesB = 0xFFFF0000, .shift_left = 0x10, .shift_right = 0x10},
    [5] = {.bytesA = 0x00000FFF, .bytesB = 0xFFFFF000, .shift_left = 0x14, .shift_right = 0x0C},
    [6] = {.bytesA = 0x000000FF, .bytesB = 0xFFFFFF00, .shift_left = 0x18, .shift_right = 0x08},
    [7] = {.bytesA = 0x0000000F, .bytesB = 0xFFFFFFF0, .shift_left = 0x1C, .shift_right = 0x04},
};

static const u16 gUnknown_80B865C[] =
{
    0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0, 0, 0, 0, 0, 0
};

// Fallback character with bitmap?
static const struct unkChar gUnknown_80B86A4 =
{
    .unk0 = gUnknown_80B865C,
    .unk4 = 0x81A1,
    .unk6 = 7,
    .unk8 = 10,
    .fill9 = 0,
    .unkA = 0,
    .fillB = 0,
};

// Very weird...
UNUSED static const u8 sByte8 = 8;

static const u32 gUnknown_80B86B4[][32] = INCBIN_U32("graphics/warning.4bpp");

static const u8 gKanjiA_file_string[] = "kanji_a";
static const u8 gKanjiB_file_string[] = "kanji_b";

static const u32 gFadeInNone[8] = {0};
static const u32 gFadeInDungeon[8] = {0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888};

static const u32 gUnknown_80B8804[4] = {0, 1, 2, 3};
static const u32 gUnknown_80B8814[4] = {1, 2, 3, 0};

void LoadCharmaps(void)
{
    int i;
    int j;
    int k;

    sCurrentCharmap = 0;
    sCharmapFiles[0] = OpenFileAndGetFileDataPtr(gKanjiA_file_string, &gSystemFileArchive);
    sCharmapFiles[1] = OpenFileAndGetFileDataPtr(gKanjiB_file_string, &gSystemFileArchive);
    sCharmaps[0] = (void *) sCharmapFiles[0]->data;
    sCharmaps[1] = (void *) sCharmapFiles[1]->data;
    sCharHeight[0] = 11;
    sCharHeight[1] = 12;

    for (k = 0; k < 4; k++) {
        gUnknown_2027370[k].unk4 = 0;
        gUnknown_2027370[k].unk8 = 0;
        gUnknown_2027370[k].unk46 = 0;
    }

    sCharacterSpacing = 0;

    for (i = 0; i < 20; i++) {
        gUnknown_202B038[0][i][0] = 0xf279;
        gUnknown_202B038[1][i][0] = 0xf27a;

        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xf27a;
        }
    }

    sDrawTextShadow = 1;
    sTextShadowMask = 0x88888888;
    gUnknown_203B078 = NULL;
    gUnknown_20274A5 = FALSE;
    sUnknown_202B020 = 1;
    sUnknown_202B024 = 20;
    UpdateFadeInTile(0);
}

u32 UpdateFadeInTile(u32 a0)
{
    u32 r5 = sUnknown_20274B0;
    u32 *r4 = (u32 *)(VRAM + 0x4F40);
    const u32 *r2;
    sUnknown_20274B0 = a0;

    if (a0 == 0 || a0 == 2) {
        sub_800CDA8(2);
        r2 = gFadeInNone;
    }
    else {
        sub_800CDA8(1);
        r2 = gFadeInDungeon;
    }

    sTextShadowMask = 0x88888888;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    *r4++ = *r2++;
    return r5;
}

u32 sub_80063B0(void)
{
    return sUnknown_20274B0;
}

UNUSED static u8 UnusedSetTextShadow(u8 a0)
{
    u8 retval = sDrawTextShadow;
    sDrawTextShadow = a0;
    return retval;
}

void SelectCharmap(u32 a0)
{
    sCurrentCharmap = a0;
}

void SetCharacterMask(int a0)
{
    u32 retval;
    if (a0 == 0) {
        UNUSED u32 unusedVal = sUnknown_20274B0;
        retval = 0x88888888;
    }
    else {
        retval = (a0 & 0xF) | ((a0 & 0xF) << 4); // Must be one line for matching
        retval |= ((a0 & 0xF) << 8);
        retval |= ((a0 & 0xF) << 12);
        retval |= ((a0 & 0xF) << 16);
        retval |= ((a0 & 0xF) << 20);
        retval |= ((a0 & 0xF) << 24);
        retval |= ((a0 & 0xF) << 28);
    }
    sTextShadowMask = retval;
}

void xxx_call_save_unk_text_struct_800641C(const Windows *a0, bool8 a1, bool8 a2)
{
    DungeonPos r3 = {0, 0};
    SaveUnkTextStructAndXXX_8006438(a0, a1, a2, &r3);
}

// https://decomp.me/scratch/xF5Y1
static void SaveUnkTextStructAndXXX_8006438(const Windows *a0, bool8 a1, bool8 a2, DungeonPos *a3)
{
    s32 i;
    u32 r9;

    r9 = 2;

    if (a0 == NULL)
        a0 = &gUnknown_80B857C;
    if (a2)
        sub_8009388();

    sub_800898C();

    for (i = 0; i < 4; i++) {
        sUnknown_202AFC0.a0[i] = a0->a0[i];

        if (a0->a0[i].width) {
            sub_8006554(gUnknown_2027370, (u32 *)VRAM, sUnknown_20274B4, &gUnknown_202B038[0][0][0], gUnknown_80B8804[i], &a0->a0[i], a1, r9, a3, 0);
            sub_80089AC(&a0->a0[i], a3);
            r9 += a0->a0[i].width * a0->a0[i].unk10;
        }
    }

    // Needed to account for weird compiler LDRs
    ASM_MATCH_TRICK(gUnknown_203B078);
    ASM_MATCH_TRICK(gUnknown_3000E94[0]);
    ASM_MATCH_TRICK(gUnknown_20274A5);

    gUnknown_203B078 = gUnknown_3000E94;
    gUnknown_20274A5 = TRUE;
}

UNUSED static void nullsub_152(void)
{
}

void RestoreUnkTextStruct_8006518(Windows *unkData)
{
    s32 i;
    for (i = 0; i < 4; i++)
        unkData->a0[i] = sUnknown_202AFC0.a0[i];
}

UNUSED static void nullsub_153(void)
{
}

u32 sub_8006544(u32 index)
{
    return gUnknown_80B8814[index];
}

// a1 is a VRAM pointer
static void sub_8006554(UnkTextStruct1 *a0, u32 *a1, u32 *a2, u16 *a3, u32 a4, const Window *a5, bool8 a6, u32 a7, DungeonPos *a8, u8 a9)
{
    UnkTextStruct1 *t1;
    s32 iVar3;
    s32 iVar5;
    s32 iVar6;
    s32 numI;
    u32 uVar1;

    s32 temp;
    s32 i;
    s32 j;

    t1 = &a0[a4];
    iVar3 = a5->pos.x + a8->x;
    iVar5 =  a5->pos.y + a8->y;
    t1->unk0 = iVar3;
    t1->unk2 = iVar5;
    t1->unk4 = a5->width;
    t1->unk8 = a5->unk10;
    t1->unk6 = a5->height;
    t1->unkC = a5->type;
    t1->unk10 = a7;

    if (t1->unkC == 6)
        t1->unk14 = a7;
    else
        t1->unk14 = a7 + a5->unk12 * t1->unk4;

    t1->unk18 = &a2[t1->unk10 * 8];
    t1->unk1C = &a2[t1->unk14 * 8];
    t1->unk24 = a5->unk12;
    t1->unk28 = &a1[t1->unk14 * 8];

    if (t1->unkC == 6)
        t1->unk2C = t1->unk4 * (t1->unk6 + a5->unk12) * 32;
    else
        t1->unk2C = t1->unk4 * t1->unk6 * 32;

    t1->unk30 = 0;
    t1->unk34 = 0;
    t1->unk38 = 0;
    t1->unk20 = (t1->unk4 * 8) - 8;
    t1->unk45 = t1->unkC == 0;

    if (t1->unk8 == 0)
        return;

    if ((a5->unk0 & 0xA0) != 0x80) {
        temp = iVar5 - 1;

        if (t1->unkC == 6) {
            uVar1 = a6 ? t1->unk14 : 0;

            sub_8006E94(t1, temp, uVar1, a5->unk14, a3);

            temp = iVar5 + 2;
            uVar1 = a6 ? t1->unk14 + t1->unk4 * (a5->unk12 + 2) : 0;
            numI = t1->unk6 - 2;
        }
        else {
            sub_800677C(t1, temp, a3, a9);

            temp = iVar5;
            uVar1 = a6 ? t1->unk14 : 0;
            numI = t1->unk6;
        }

        for (i = 0; i < numI; i++) {
            iVar6 = iVar3 - 1;
            sub_80069CC(t1, iVar6, temp, i, a3);
            iVar6 = iVar3;

            for (j = 0; j < t1->unk4; j++) {
                sub_8006AC4(t1, iVar6, temp, uVar1, a3);

                iVar6++;
                if (a6)
                    uVar1++;
            }

            sub_8006B70(t1, iVar6, temp, i, a3);
            temp++;
        }
        sub_8006C44(t1, temp, a3, a9);
    }

    if ((a5->unk0 & 0x80) == 0)
        PrepareTextbox_8008C6C(a0, a4);

    t1->unk46 = 0;
}

static void sub_800677C(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = a0->unk0 - 1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    switch (a0->unkC) {
        case 0:
        case 1:
        case 2:
        case 6:
            break;
        case 3:
            (a2 + a1 * 0x20)[iVar5] = 0xF2D8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF293;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2D9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6D8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF693;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a2 + a1 * 0x20)[iVar5] = 0xF2E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2E9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a2 + a1 * 0x20)[iVar5] = 0xF2DC;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2DD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6DC;
            break;
        case 7:
           (a2 + a1 * 0x20)[iVar5] = 0xF293;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF297;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF693;
            break;
    }
}

static void sub_80069CC(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 1:
        case 2:
            break;
        case 0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF297;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == a0->unk6 - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFA97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case 3:
        case 6:
            (a4 + a2 * 0x20)[a1] = 0xF2DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a4 + a2 * 0x20)[a1] = 0xF2EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a4 + a2 * 0x20)[a1] = 0xF2DE;
            break;
        case 7:
            (a4 + a2 * 0x20)[a1] = 0xF2B6;
            break;
    }
}

static void sub_8006AC4(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 2:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF278;
            break;
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
        case 7:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            break;
    }
}

static void sub_8006B70(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 1:
        case 2:
            break;
        case 0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF697;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == a0->unk6 - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFE97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case 3:
        case 6:
            (a4 + a2 * 0x20)[a1] = 0xF6DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a4 + a2 * 0x20)[a1] = 0xF6EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a4 + a2 * 0x20)[a1] = 0xF6DE;
            break;
        case 7:
            (a4 + a2 * 0x20)[a1] = 0xF6B6;
            break;
    }
}

static void sub_8006C44(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = a0->unk0 - 1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    switch (a0->unkC) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 6:
            (a2 + a1 * 0x20)[iVar5] = 0xFAD8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xFA93;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFAD9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFED8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xFE93;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a2 + a1 * 0x20)[iVar5] = 0xFAE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFAE9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a2 + a1 * 0x20)[iVar5] = 0xFADC;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFADD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEDC;
            break;
        case 7:
           (a2 + a1 * 0x20)[iVar5] = 0xFA93;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFA97;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFE93;
            break;
    }
}

// Not even close but I don't feel like continuing atm https://decomp.me/scratch/F58jg
/*
void sub_8006E94(UnkTextStruct1 *a0, s32 a1, u32 a2, const WindowHeader *a3, u16 *a4)
{
    s32 bVar1;
    s32 iVar2;
    s32 iVar3;
    s32 sVar4;
    u16 *puVar5;
    u16 *puVar6;
    u16 *puVar7;
    s32 iVar8;
    u16 *puVar9;
    u16 *puVar10;
    u16 *puVar11;
    s32 local_44;
    u32 local_3c;
    u16 *local_30;
    s32 local_2c;
    u16 *local_24;

    iVar2 = a0->unk0;
    bVar1 = -1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    (a4 + a1 * 0x20)[iVar2 - 1] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x400] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x20] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x420] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x40] = 0xF2D8;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x440] = 0xF2DB;

    local_2c = iVar2 * 2;
    puVar5 = a4 + a1 * 0x20 + iVar2 + 0x40;
    puVar7 = a4 + a1 * 0x20 + iVar2 + 0x20;
    local_30 = a4 + a1 * 0x20 + iVar2 + 0x400;
    puVar11 = a4 + a1 * 0x20 + iVar2 + 0x420;
    puVar9 = a4 + a1 * 0x20 + iVar2;
    iVar8 = a1 * 0x40;

    for (local_3c = 0; local_3c < a3[0]; local_3c++) {
        if (local_3c == a3[1]) {
            bVar1 = TRUE;
            *puVar9 = 0xF2E0;
            *local_30 = 0xF2E2;
            *puVar7 = 0xF2DA;
            *puVar11 = 0xF2DB;
            *puVar5 = 0xF6E7;
            puVar9[0x440] = 0xF2DB;
            puVar5++;
            puVar7++;
            local_30++;
            puVar11++;
            puVar9++;
            local_2c += 2;
            iVar2++;

            if (a2 == 0 || ++a2 == 0)
                iVar3 = 0;
            else
                iVar3 = a2 + a0->unk4;

            local_24 = a4 + local_2c + iVar8 + 0x80;
            puVar10 = a4 + local_2c + iVar8 + 0x40;
            puVar6 = a4 + local_2c + iVar8;

            for (local_44 = 0; local_44 < a3[2]; local_44++) {
                *puVar6 = 0xF2E1;
                puVar6[0x400] = 0xF2E2;
                *puVar10 = a2 | 0xF000;
                puVar6[0x420] = 0xF2DB;
                *local_24 = iVar3 | 0xF000;
                puVar6[0x440] = 0xF2DB;
                local_24++;
                puVar10++;
                puVar6++;
                puVar5++;
                puVar7++;
                local_30++;
                puVar11++;
                puVar9++;
                local_2c += 2;
                iVar2++;
                if (a2 != 0)
                    a2++;

                if (iVar3 != 0)
                    iVar3++;
            }

            *puVar9 = 0xF6E0;
            *local_30 = 0xF2E2;
            *puVar7 = 0xF6DA;
            *puVar11 = 0xF2DB;
            *puVar5 = 0xF2E7;
            puVar9[0x440] = 0xF2DB;
        }
        else {
            if (bVar1) {
                if ((a3[3] >> (local_3c & 0xFF) & 1) == 0) {
                    sVar4 = 107;
                    if (local_3c == a3[0] - 1)
                        sVar4 = 103;

                    *puVar9 = (sVar4 + 0x278) | 0xF000;
                    *puVar7 = 0xF6EF;
                    *puVar5 = 0xF2D9;
                }
                else {
                    sVar4 = 31;
                    if (local_3c == a3[0] - 1)
                        sVar4 = 27;

                    *puVar9 = (sVar4 + 0x278) | 0xF000;
                    *puVar7 = 0xF6B6;
                    *puVar5 = 0xF2D9;
                }
                *local_30 = 0xF27A;
                *puVar11 = 0xF6DB;
            }
            else {
                if ((a3[3] >> (local_3c & 0xFF) & 1) == 0) {
                    sVar4 = 107;
                    if (local_3c == 0)
                        sVar4 = 103;

                    *puVar9 = (sVar4 + 0x278) | 0xF400;
                    *puVar7 = 0xF2EF;
                    *puVar5 = 0xF2D9;
                }
                else {
                    sVar4 = 31;
                    if (local_3c == 0)
                        sVar4 = 27;

                    *puVar9 = (sVar4 + 0x278) | 0xF400;
                    *puVar7 = 0xF2B6;
                    *puVar5 = 0xF2D9;
                }
                *local_30 = 0xF27A;
                *puVar11 = 0xF2DB;
            }
            puVar9[0x440] = 0xF2DB;
        }

        local_2c += 2;
        local_30++;
        iVar2++;
        puVar11++;
        puVar5++;
        puVar7++;
        puVar9++;
        if (a2 != 0)
            a2++;
    }

    iVar8 = a0->unk0 + a0->unk4;
    if (iVar2 < iVar8) {
        for (iVar3 = iVar8 - iVar2; iVar3 != 0; iVar3--) {
            (a4 + a1 * 0x20)[iVar2 + iVar3] = 0xF278;
            (a4 + a1 * 0x20)[iVar2 + 0x400 + iVar3] = 0xF27A;
            (a4 + a1 * 0x20)[iVar2 + 0x20 + iVar3] = 0xF278;
            (a4 + a1 * 0x20)[iVar2 + 0x420 + iVar3] = 0xF27A;
            (a4 + a1 * 0x20)[iVar2 + 0x40 + iVar3] = 0xF2D9;
            (a4 + a1 * 0x20)[iVar2 + 0x440 + iVar3] = 0xF2DB;

            if (a2 != 0)
                a2++;

            iVar2 = iVar8;
        }
    }

    (a4 + a1 * 0x20)[iVar2] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 + 0x400] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 + 0x20] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 + 0x420] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 + 0x40] = 0xF6D8;
    (a4 + a1 * 0x20)[iVar2 + 0x440] = 0xF2DB;
}
*/
NAKED
static void sub_8006E94(UnkTextStruct1 *a0, s32 a1, u32 a2, const WindowHeader *a3, u16 *a4)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x30\n"
    "\tstr r0, [sp]\n"
    "\tadds r4, r1, 0\n"
    "\tadds r7, r2, 0\n"
    "\tstr r3, [sp, 0x4]\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmov r10, r0\n"
    "\tmovs r2, 0x1\n"
    "\tnegs r2, r2\n"
    "\tadd r2, r10\n"
    "\tmovs r3, 0\n"
    "\tstr r3, [sp, 0x8]\n"
    "\tcmp r4, 0x1C\n"
    "\tble _08006EBE\n"
    "\tb _080072FE\n"
"_08006EBE:\n"
    "\tcmp r4, 0\n"
    "\tbge _08006EC4\n"
    "\tb _080072FE\n"
"_08006EC4:\n"
    "\tlsls r1, r2, 1\n"
    "\tlsls r4, 6\n"
    "\tldr r6, [sp, 0x50]\n"
    "\tadds r5, r4, r6\n"
    "\tadds r1, r5\n"
    "\tldr r0, _08006F9C\n"
    "\tadds r3, r0, 0\n"
    "\tstrh r3, [r1]\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 4\n"
    "\tadds r0, r1, r2\n"
    "\tldr r6, _08006FA0\n"
    "\tadds r2, r6, 0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r1, 0\n"
    "\tadds r0, 0x40\n"
    "\tstrh r3, [r0]\n"
    "\tmovs r0, 0x84\n"
    "\tlsls r0, 4\n"
    "\tadds r0, r1, r0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r2, r1, 0\n"
    "\tadds r2, 0x80\n"
    "\tldr r3, _08006FA4\n"
    "\tadds r0, r3, 0\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r6, 0x88\n"
    "\tlsls r6, 4\n"
    "\tadds r1, r6\n"
    "\tldr r2, _08006FA8\n"
    "\tadds r0, r2, 0\n"
    "\tstrh r0, [r1]\n"
    "\tmov r12, r10\n"
    "\tmovs r3, 0\n"
    "\tstr r4, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x4]\n"
    "\tldrb r4, [r4]\n"
    "\tcmp r3, r4\n"
    "\tblt _08006F14\n"
    "\tb _08007238\n"
"_08006F14:\n"
    "\tadds r2, r5, 0\n"
    "\tmov r5, r12\n"
    "\tlsls r1, r5, 1\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r6, [sp, 0x18]\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1\n"
    "\tmov r9, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1\n"
    "\tmov r8, r0\n"
    "\tldr r4, [sp, 0x50]\n"
    "\tmovs r5, 0x80\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1, r0\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tmovs r6, 0x84\n"
    "\tlsls r6, 4\n"
    "\tadds r0, r4, r6\n"
    "\tldr r4, [sp, 0x18]\n"
    "\tadds r0, r4, r0\n"
    "\tadds r0, r1\n"
    "\tmov r10, r0\n"
    "\tadds r4, r1, r2\n"
    "\tldr r5, [sp, 0x18]\n"
    "\tstr r5, [sp, 0x10]\n"
    "\tstr r2, [sp, 0x1C]\n"
    "\tstr r1, [sp, 0x24]\n"
"_08006F56:\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrb r6, [r6, 0x1]\n"
    "\tcmp r3, r6\n"
    "\tbne _08006F60\n"
    "\tb _080070C8\n"
"_08006F60:\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tcmp r0, 0\n"
    "\tbne _08007008\n"
    "\tldr r1, [sp, 0x4]\n"
    "\tldrb r0, [r1, 0x3]\n"
    "\tasrs r0, r3\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _08006FB8\n"
    "\tmovs r1, 0x1F\n"
    "\tcmp r3, 0\n"
    "\tbne _08006F7C\n"
    "\tmovs r1, 0x1B\n"
"_08006F7C:\n"
    "\tmovs r2, 0x9E\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r1, r2\n"
    "\tldr r5, _08006FAC\n"
    "\tadds r1, r5, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r6, _08006FB0\n"
    "\tadds r0, r6, 0\n"
    "\tmov r1, r8\n"
    "\tstrh r0, [r1]\n"
    "\tldr r5, _08006FB4\n"
    "\tmov r2, r9\n"
    "\tstrh r5, [r2]\n"
    "\tb _08006FDC\n"
    "\t.align 2, 0\n"
"_08006F9C: .4byte 0x0000f278\n"
"_08006FA0: .4byte 0x0000f27a\n"
"_08006FA4: .4byte 0x0000f2d8\n"
"_08006FA8: .4byte 0x0000f2db\n"
"_08006FAC: .4byte 0xfffff400\n"
"_08006FB0: .4byte 0x0000f2b6\n"
"_08006FB4: .4byte 0x0000f2d9\n"
"_08006FB8:\n"
    "\tmovs r1, 0x6B\n"
    "\tcmp r3, 0\n"
    "\tbne _08006FC0\n"
    "\tmovs r1, 0x67\n"
"_08006FC0:\n"
    "\tmovs r6, 0x9E\n"
    "\tlsls r6, 2\n"
    "\tadds r0, r1, r6\n"
    "\tldr r2, _08006FF4\n"
    "\tadds r1, r2, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r5, _08006FF8\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08006FFC\n"
    "\tmov r0, r9\n"
    "\tstrh r1, [r0]\n"
"_08006FDC:\n"
    "\tldr r2, _08007000\n"
    "\tadds r0, r2, 0\n"
    "\tldr r5, [sp, 0x20]\n"
    "\tstrh r0, [r5]\n"
    "\tldr r0, _08007004\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r4, r1\n"
    "\tadds r2, 0x61\n"
    "\tb _0800708E\n"
    "\t.align 2, 0\n"
"_08006FF4: .4byte 0xfffff400\n"
"_08006FF8: .4byte 0x0000f2ef\n"
"_08006FFC: .4byte 0x0000f2d9\n"
"_08007000: .4byte 0x0000f27a\n"
"_08007004: .4byte 0x0000f2db\n"
"_08007008:\n"
    "\tldr r5, [sp, 0x4]\n"
    "\tldrb r0, [r5, 0x3]\n"
    "\tasrs r0, r3\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _0800704C\n"
    "\tldrb r0, [r5]\n"
    "\tsubs r0, 0x1\n"
    "\tmovs r1, 0x1F\n"
    "\tcmp r3, r0\n"
    "\tbne _08007022\n"
    "\tmovs r1, 0x1B\n"
"_08007022:\n"
    "\tmovs r6, 0x9E\n"
    "\tlsls r6, 2\n"
    "\tadds r0, r1, r6\n"
    "\tldr r2, _08007040\n"
    "\tadds r1, r2, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r5, _08007044\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007048\n"
    "\tmov r0, r9\n"
    "\tstrh r1, [r0]\n"
    "\tb _08007076\n"
    "\t.align 2, 0\n"
"_08007040: .4byte 0xfffff000\n"
"_08007044: .4byte 0x0000f6b6\n"
"_08007048: .4byte 0x0000f2d9\n"
"_0800704C:\n"
    "\tldr r2, [sp, 0x4]\n"
    "\tldrb r0, [r2]\n"
    "\tsubs r0, 0x1\n"
    "\tmovs r1, 0x6B\n"
    "\tcmp r3, r0\n"
    "\tbne _0800705A\n"
    "\tmovs r1, 0x67\n"
"_0800705A:\n"
    "\tmovs r5, 0x9E\n"
    "\tlsls r5, 2\n"
    "\tadds r0, r1, r5\n"
    "\tldr r6, _080070B0\n"
    "\tadds r1, r6, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r1, _080070B4\n"
    "\tadds r0, r1, 0\n"
    "\tmov r2, r8\n"
    "\tstrh r0, [r2]\n"
    "\tldr r6, _080070B8\n"
    "\tmov r5, r9\n"
    "\tstrh r6, [r5]\n"
"_08007076:\n"
    "\tldr r1, _080070BC\n"
    "\tadds r0, r1, 0\n"
    "\tldr r2, [sp, 0x20]\n"
    "\tstrh r0, [r2]\n"
    "\tldr r5, _080070C0\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r4, r1\n"
    "\tldr r2, _080070C4\n"
"_0800708E:\n"
    "\tstrh r2, [r0]\n"
    "\tmovs r5, 0x2\n"
    "\tadd r9, r5\n"
    "\tadd r8, r5\n"
    "\tldr r6, [sp, 0x20]\n"
    "\tadds r6, 0x2\n"
    "\tstr r6, [sp, 0x20]\n"
    "\tadd r10, r5\n"
    "\tadds r4, 0x2\n"
    "\tldr r0, [sp, 0x24]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x24]\n"
    "\tmovs r1, 0x1\n"
    "\tadd r12, r1\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0x14]\n"
    "\tb _08007226\n"
    "\t.align 2, 0\n"
"_080070B0: .4byte 0xfffff000\n"
"_080070B4: .4byte 0x0000f6ef\n"
"_080070B8: .4byte 0x0000f2d9\n"
"_080070BC: .4byte 0x0000f27a\n"
"_080070C0: .4byte 0x0000f6db\n"
"_080070C4: .4byte 0x0000f2db\n"
"_080070C8:\n"
    "\tmovs r2, 0x1\n"
    "\tstr r2, [sp, 0x8]\n"
    "\tldr r5, _08007128\n"
    "\tadds r0, r5, 0\n"
    "\tstrh r0, [r4]\n"
    "\tldr r6, _0800712C\n"
    "\tadds r0, r6, 0\n"
    "\tldr r1, [sp, 0x20]\n"
    "\tstrh r0, [r1]\n"
    "\tldr r2, _08007130\n"
    "\tadds r0, r2, 0\n"
    "\tmov r5, r8\n"
    "\tstrh r0, [r5]\n"
    "\tldr r0, _08007134\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007138\n"
    "\tadds r0, r1, 0\n"
    "\tmov r2, r9\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r5, 0x88\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tldr r6, _08007134\n"
    "\tstrh r6, [r0]\n"
    "\tmovs r0, 0x2\n"
    "\tadd r9, r0\n"
    "\tadd r8, r0\n"
    "\tldr r1, [sp, 0x20]\n"
    "\tadds r1, 0x2\n"
    "\tstr r1, [sp, 0x20]\n"
    "\tadd r10, r0\n"
    "\tadds r4, 0x2\n"
    "\tldr r2, [sp, 0x24]\n"
    "\tadds r2, 0x2\n"
    "\tstr r2, [sp, 0x24]\n"
    "\tmovs r5, 0x1\n"
    "\tadd r12, r5\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800713C\n"
    "\tadds r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800713C\n"
    "\tldr r6, [sp]\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r6, r1]\n"
    "\tadds r2, r7, r0\n"
    "\tb _0800713E\n"
    "\t.align 2, 0\n"
"_08007128: .4byte 0x0000f2e0\n"
"_0800712C: .4byte 0x0000f2e2\n"
"_08007130: .4byte 0x0000f2da\n"
"_08007134: .4byte 0x0000f2db\n"
"_08007138: .4byte 0x0000f6e7\n"
"_0800713C:\n"
    "\tmovs r2, 0\n"
"_0800713E:\n"
    "\tmovs r5, 0\n"
    "\tstr r5, [sp, 0xC]\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0x14]\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrb r6, [r6, 0x2]\n"
    "\tcmp r5, r6\n"
    "\tbge _080071E0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tadds r0, r1, r0\n"
    "\tldr r3, [sp, 0x24]\n"
    "\tadds r0, r3, r0\n"
    "\tstr r0, [sp, 0x2C]\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r1, r0\n"
    "\tadds r5, r3, r0\n"
    "\tldr r6, [sp, 0x1C]\n"
    "\tadds r3, r6\n"
"_08007168:\n"
    "\tldr r1, _08007310\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r3]\n"
    "\tmovs r6, 0x80\n"
    "\tlsls r6, 4\n"
    "\tadds r6, r3, r6\n"
    "\tstr r6, [sp, 0x28]\n"
    "\tadds r1, 0x1\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r6]\n"
    "\tadds r0, r7, 0\n"
    "\tldr r6, _08007314\n"
    "\torrs r0, r6\n"
    "\tstrh r0, [r5]\n"
    "\tmovs r1, 0x84\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r3, r1\n"
    "\tldr r6, _08007318\n"
    "\tstrh r6, [r0]\n"
    "\tadds r0, r2, 0\n"
    "\tldr r1, _08007314\n"
    "\torrs r0, r1\n"
    "\tldr r6, [sp, 0x2C]\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r3, r1\n"
    "\tldr r6, _08007318\n"
    "\tstrh r6, [r0]\n"
    "\tldr r0, [sp, 0x2C]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x2C]\n"
    "\tadds r5, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tmovs r1, 0x2\n"
    "\tadd r9, r1\n"
    "\tadd r8, r1\n"
    "\tldr r6, [sp, 0x20]\n"
    "\tadds r6, 0x2\n"
    "\tstr r6, [sp, 0x20]\n"
    "\tadd r10, r1\n"
    "\tadds r4, 0x2\n"
    "\tldr r0, [sp, 0x24]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x24]\n"
    "\tmovs r1, 0x1\n"
    "\tadd r12, r1\n"
    "\tcmp r7, 0\n"
    "\tbeq _080071CC\n"
    "\tadds r7, 0x1\n"
"_080071CC:\n"
    "\tcmp r2, 0\n"
    "\tbeq _080071D2\n"
    "\tadds r2, 0x1\n"
"_080071D2:\n"
    "\tldr r6, [sp, 0xC]\n"
    "\tadds r6, 0x1\n"
    "\tstr r6, [sp, 0xC]\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tcmp r6, r0\n"
    "\tblt _08007168\n"
"_080071E0:\n"
    "\tldr r1, _0800731C\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r4]\n"
    "\tldr r2, _08007320\n"
    "\tadds r0, r2, 0\n"
    "\tldr r3, [sp, 0x20]\n"
    "\tstrh r0, [r3]\n"
    "\tldr r5, _08007324\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007318\n"
    "\tmov r0, r10\n"
    "\tstrh r1, [r0]\n"
    "\tadds r2, 0x5\n"
    "\tadds r0, r2, 0\n"
    "\tmov r3, r9\n"
    "\tstrh r0, [r3]\n"
    "\tmovs r5, 0x88\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tstrh r1, [r0]\n"
    "\tmovs r6, 0x2\n"
    "\tadd r9, r6\n"
    "\tadd r8, r6\n"
    "\tldr r0, [sp, 0x20]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tadd r10, r6\n"
    "\tadds r4, 0x2\n"
    "\tldr r1, [sp, 0x24]\n"
    "\tadds r1, 0x2\n"
    "\tstr r1, [sp, 0x24]\n"
    "\tmovs r2, 0x1\n"
    "\tadd r12, r2\n"
"_08007226:\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800722C\n"
    "\tadds r7, 0x1\n"
"_0800722C:\n"
    "\tldr r3, [sp, 0x14]\n"
    "\tldr r5, [sp, 0x4]\n"
    "\tldrb r5, [r5]\n"
    "\tcmp r3, r5\n"
    "\tbge _08007238\n"
    "\tb _08006F56\n"
"_08007238:\n"
    "\tldr r6, [sp]\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r6, r0]\n"
    "\tmovs r2, 0x4\n"
    "\tldrsh r0, [r6, r2]\n"
    "\tadds r0, r1, r0\n"
    "\tcmp r12, r0\n"
    "\tbge _080072BC\n"
    "\tldr r3, _08007328\n"
    "\tadds r4, r3, 0\n"
    "\tmov r8, r0\n"
    "\tmov r5, r12\n"
    "\tlsls r1, r5, 1\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r6, [sp, 0x18]\n"
    "\tadds r0, r6, r0\n"
    "\tadds r5, r1, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r6, r0\n"
    "\tadds r3, r1, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r6, r0\n"
    "\tadds r2, r1, r6\n"
    "\tmovs r1, 0x80\n"
    "\tlsls r1, 4\n"
    "\tmov r10, r1\n"
    "\tmovs r6, 0x84\n"
    "\tlsls r6, 4\n"
    "\tmov r9, r6\n"
    "\tmov r0, r8\n"
    "\tmov r1, r12\n"
    "\tsubs r0, r1\n"
    "\tmov r12, r0\n"
"_0800727E:\n"
    "\tstrh r4, [r2]\n"
    "\tmov r6, r10\n"
    "\tadds r0, r2, r6\n"
    "\tldr r1, _0800732C\n"
    "\tstrh r1, [r0]\n"
    "\tstrh r4, [r3]\n"
    "\tmov r6, r9\n"
    "\tadds r0, r2, r6\n"
    "\tstrh r1, [r0]\n"
    "\tadds r1, 0x5F\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r5]\n"
    "\tmovs r6, 0x88\n"
    "\tlsls r6, 4\n"
    "\tadds r1, r2, r6\n"
    "\tldr r6, _08007318\n"
    "\tadds r0, r6, 0\n"
    "\tstrh r0, [r1]\n"
    "\tadds r5, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x2\n"
    "\tmovs r0, 0x1\n"
    "\tnegs r0, r0\n"
    "\tadd r12, r0\n"
    "\tcmp r7, 0\n"
    "\tbeq _080072B4\n"
    "\tadds r7, 0x1\n"
"_080072B4:\n"
    "\tmov r1, r12\n"
    "\tcmp r1, 0\n"
    "\tbne _0800727E\n"
    "\tmov r12, r8\n"
"_080072BC:\n"
    "\tmov r2, r12\n"
    "\tlsls r1, r2, 1\n"
    "\tldr r3, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x50]\n"
    "\tadds r0, r3, r4\n"
    "\tadds r1, r0\n"
    "\tldr r5, _08007328\n"
    "\tadds r3, r5, 0\n"
    "\tstrh r3, [r1]\n"
    "\tmovs r6, 0x80\n"
    "\tlsls r6, 4\n"
    "\tadds r0, r1, r6\n"
    "\tldr r4, _0800732C\n"
    "\tadds r2, r4, 0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r1, 0\n"
    "\tadds r0, 0x40\n"
    "\tstrh r3, [r0]\n"
    "\tmovs r5, 0x84\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r1, r5\n"
    "\tstrh r2, [r0]\n"
    "\tadds r2, r1, 0\n"
    "\tadds r2, 0x80\n"
    "\tldr r6, _08007330\n"
    "\tadds r0, r6, 0\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r0, 0x88\n"
    "\tlsls r0, 4\n"
    "\tadds r1, r0\n"
    "\tldr r2, _08007318\n"
    "\tadds r0, r2, 0\n"
    "\tstrh r0, [r1]\n"
"_080072FE:\n"
    "\tadd sp, 0x30\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08007310: .4byte 0x0000f2e1\n"
"_08007314: .4byte 0xfffff000\n"
"_08007318: .4byte 0x0000f2db\n"
"_0800731C: .4byte 0x0000f6e0\n"
"_08007320: .4byte 0x0000f2e2\n"
"_08007324: .4byte 0x0000f6da\n"
"_08007328: .4byte 0x0000f278\n"
"_0800732C: .4byte 0x0000f27a\n"
"_08007330: .4byte 0x0000f6d8");
}

void sub_8007334(s32 a0)
{
    s32 i, j;
    struct UnkTextStruct1 *textStructPtr = &gUnknown_2027370[a0];
    s32 r5 = textStructPtr->unk14;
    s32 r6 = textStructPtr->unk2;
    for (i = 0; i < textStructPtr->unk6; i++) {
        s32 id = textStructPtr->unk0;
        for (j = 0; j < textStructPtr->unk4; j++) {
            gUnknown_202B038[0][r6][id] &= ~0x3ff;
            gUnknown_202B038[0][r6][id] |= r5;
            id++;
            r5++;
        }
        r6++;
    }
}

UNUSED static void nullsub_154(void)
{
}

void sub_80073B8(s32 a0)
{
    UnkTextStruct1 *r1;

    r1 = &gUnknown_2027370[a0];

    r1->unk3C = &r1->unk1C[(u32)r1->unk2C >> 2];
    r1->unk40 = r1->unk1C;
    r1->unk46 = 1;
}

UNUSED static void nullsub_155(void)
{
}

void sub_80073E0(s32 a0)
{
    UnkTextStruct1 *r1;

    r1 = &gUnknown_2027370[a0];

    if (r1->unk44 == 0) {
        r1->unk30 = &r1->unk28[r1->unk3C - r1->unk1C];
        r1->unk34 = r1->unk3C;
        r1->unk38 = (r1->unk40 - r1->unk3C + 1) * 4;

        if (r1->unk38 >= r1->unk2C)
            r1->unk38 = r1->unk2C;

        if (r1->unk38 < 0)
            r1->unk38 = 0;
    }

    r1->unk46 = 0;
}

UNUSED static void nullsub_156(void)
{
}

u32 xxx_call_draw_char(s32 x, s32 y, u32 a2, u32 color, u32 a4)
{
    return xxx_draw_char(gUnknown_2027370, x, y, a2, color, a4);
}

UNUSED static bool8 sub_8007464(void)
{
    return FALSE;
}

static u32 xxx_draw_char(struct UnkTextStruct1 *a0, s32 x, s32 y, u32 a3, u32 color, u32 a5)
{
    u32 *r3;
    const struct unkShiftData *shiftData;
    const struct unkChar *sp0;
    const u16 *local_44;
    const u16 *sp8;
    const u16 *local_3c;
    s32 i;
    s32 xDiv8, yDiv8;
    struct UnkTextStruct1 *r5 = &a0[a5];
    s32 sp18 = gUnknown_80B853C[color & 0xF];
    u8 var_2C;
    u32 r4;
    u32 r2;

    if (sCurrentCharmap == 1) {
        if (a3 == 0x70 || a3 == 0x6A || a3 == 0x71 || a3 == 0x79 || a3 == 0x67)
            y += 2;
        else if (a3 == 0x8199)
            y -= 2;
    }

    sp0 = GetCharacter(a3);
    local_44 = sp0->unk0;
    ASM_MATCH_TRICK(local_3c); // stack doesn't match without it
    local_3c = sp0->unk0;
    sp8 = sp0->unk0 - 3;

    if (sDrawTextShadow != 0) {
        var_2C = (sp0->unkA >> 1) & 1;
    }
    else {
        var_2C = 0;
    }

    if (sp0->unkA & 1) {
        r3 = r5->unk18 + ((((y / 8) * r5->unk4) + (x / 8)) * 8);
        r3 += y - (y / 8 * 8);
        shiftData = &gCharMasksOffsets[x - ((x / 8) * 8)];
        xDiv8 = x / 8;
        yDiv8 = y / 8;

        if (yDiv8 < r5->unk8) {
            for (i = 0; i < sCharHeight[sCurrentCharmap]; i++) {
                r2 = (local_44[1] << 0x10) | (local_44[0]);
                if (r2 != 0) {
                    if (xDiv8 < r5->unk4) {
                        *r3 |= (shiftData->bytesA & r2) << shiftData->shift_left;
                        if (r5->unk3C > r3)
                            r5->unk3C = r3;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                    }
                    if (xDiv8 < r5->unk4 - 1) {
                        r3 += 8;
                        r2 &= shiftData->bytesB;
                        *r3 |= (r2) >> shiftData->shift_right;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 8;
                    }
                }

                r2 = local_44[2];
                if (r2 != 0) {
                    if (xDiv8 < r5->unk4 - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 8;
                    }
                    if (xDiv8 < r5->unk4 - 2) {
                        r3 += 16;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 16;
                    }
                }

                local_44 += 3;
                r3++;
                y++;
                if (y % 8 == 0) {
                    r3 += r5->unk20;
                    yDiv8++;
                    if (yDiv8 >= r5->unk8)
                        break;
                }
            }
        }
    }
    else {
        bool8 notFirstIteration = FALSE;
        u32 r1;

        r3 = r5->unk18 + ((((y / 8) * r5->unk4) + (x / 8)) * 8);
        r3 += y - (y / 8 * 8);
        shiftData = &gCharMasksOffsets[x - ((x / 8) * 8)];
        xDiv8 = x / 8;
        yDiv8 = y / 8;

        if (yDiv8 < r5->unk8) {
            for (i = 0; i < sCharHeight[sCurrentCharmap]; i++) {
                r4 = (local_44[1] << 0x10) | (local_44[0]);
                r2 = (0x11111111 & r4) + (sp18 & r4);

                if (var_2C != 0) {
                    r1 = ((local_3c[1] << 0x10) | local_3c[0]) << 4;
                    r1 |= r4; // This doesn't really do anything since r4 bits are cleared, but it's needed to match.
                    r1 &= ~(r4);
                    r1 &= sTextShadowMask;
                    r2 |= (r1);
                    if (notFirstIteration) {
                        r1 = (((sp8[1] << 0x10) | sp8[0]) << 4) ^ r4;
                        r1 &= ~(r4);
                        r2 |= (r1 & sTextShadowMask);
                    }
                }

                if (r2 != 0) {
                    if (xDiv8 < r5->unk4) {
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (r5->unk3C > r3)
                            r5->unk3C = r3;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                    }
                    if (xDiv8 < r5->unk4 - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 8;
                    }
                }

                r4 = local_44[2];
                r2 = (0x11111111 & r4) + (sp18 & r4);
                if (var_2C != 0) {
                    r1 = (local_3c[2] << 4) | ((local_3c[1] >> 0xC) & 0xF);
                    r1 |= r4; // This doesn't really do anything since r4 bits are cleared, but it's needed to match.
                    r1 &= ~(r4);
                    r1 &= sTextShadowMask;
                    r2 |= r1;
                    if (notFirstIteration) {
                        r1 = ((sp8[2] << 4) | ((sp8[1] >> 0xC) & 0xF)) ^ r4;
                        r1 &= ~(r4);
                        r1 &= sTextShadowMask;
                        r2 |= (r1);
                    }
                }

                if (r2 != 0) {
                    if (xDiv8 < r5->unk4 - 1) {
                        r3 += 8;
                        *r3 |= (r2 & shiftData->bytesA) << shiftData->shift_left;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 8;
                    }
                    if (xDiv8 < r5->unk4 - 2) {
                        r3 += 16;
                        *r3 |= (r2 & shiftData->bytesB) >> shiftData->shift_right;
                        if (r5->unk40 < r3)
                            r5->unk40 = r3;
                        r3 -= 16;
                    }
                }

                notFirstIteration = TRUE;
                local_44 += 3;
                sp8 += 3;
                local_3c += 3;
                r3++;
                y++;
                if (y % 8 == 0) {
                    r3 += r5->unk20;
                    yDiv8++;
                    if (yDiv8 >= r5->unk8)
                        break;
                }
            }
        }
    }

    return sp0->unk6 + sCharacterSpacing;
}

void sub_80078A4(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_800792C(a0, x, y, a3, color);
    sub_800792C(a0, x, y + 1, a3, sTextShadowMask & 0xF);
}

UNUSED static void sub_80078E8(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    nullsub_129(a0, x, y, a3, color);
    nullsub_129(a0, x, y + 1, a3, sTextShadowMask & 0xF);
}

void sub_800792C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007958(gUnknown_2027370, a0, x, y, a3, color);
}

static void nullsub_129(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
}

static void sub_8007958(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    u32 uVar4;
    u32 *dest;
    s32 r4;
    const struct unkShiftData *shiftData;
    UnkTextStruct1 *r5;
    s32 r6;
    u32 r9;
    s32 lol;

    r5 = &a0[a1];
    r9 = gUnknown_80B853C[color & 0xF];

    r4 = y / 8;

    dest = r5->unk18 + (((r5->unk4 * r4) + (x / 8)) * 8);
    dest += (r4 * -8) + y;
    r6 = x / 8;

    if (y / 8 >= r5->unk8) {
        return;
    }
    else {
        const u32 unkBits[] = {0, 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF, 0xFFFFFF, 0xFFFFFFF, 0xFFFFFFFF};

        for (; a4 > 0; a4 -= 8) {
            lol = a4;
            if (lol > 7)
                lol = 8;

            shiftData = &gCharMasksOffsets[x + (x / 8 * -8)];

            uVar4 = unkBits[lol];
            uVar4 = (uVar4 & 0x11111111) + (uVar4 & r9);

            if (uVar4 != 0) {
                if (r6 < r5->unk4) {
                    dest[0] |= (shiftData->bytesA & uVar4) << shiftData->shift_left;

                    if (r5->unk3C > dest)
                        r5->unk3C = dest;
                    if (r5->unk40 < dest)
                        r5->unk40 = dest;
                }

                if (r6 < r5->unk4 - 1) {
                    dest += 8;
                    dest[0] |= (uVar4 & shiftData->bytesB) >> shiftData->shift_right;

                    if (r5->unk40 < dest)
                        r5->unk40 = dest;
                    dest -= 8;
                }
            }

            r6++;
            dest += 8;
        }
    }
}

void sub_8007A78(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007AA4(gUnknown_2027370, a0, x, y, a3, color);
}

UNUSED static void nullsub_157(void)
{
}

static void sub_8007AA4(struct UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    struct UnkTextStruct1 *r4 = &a0[a1];
    u32 ip = gUnknown_80B853C[color & 0xF] + 0x11111111;
    const u32 unkBits[] = {0xF, 0xF0, 0xF00, 0xF000, 0xF0000, 0xF00000, 0xF000000, 0xF0000000};
    s32 r3 = y / 8;
    u32 *dest = r4->unk18 + ((r4->unk4 * r3 + x / 8) * 8);
    s32 r2 = x / 8;

    dest += r3 * -8 + y;
    ip &= unkBits[x & 7];

    if (r2 < r4->unk4) {
        // This goto looks like a fakematch, but I couldn't get it to work otherwise.
        goto LOOP_MIDDLE;
        while (1) {
            y++;
            dest++;
            if ((y % 8) == 0)
                dest += r4->unk20;
            a4--;

        LOOP_MIDDLE:
            if (a4 <= 0)
                return;
            if (r3 >= r4->unk8)
                return;

            dest[0] |= ip;

            if (r4->unk3C > dest)
                r4->unk3C = dest;
            if (r4->unk40 < dest)
                r4->unk40 = dest;
        }
    }
}

void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007BA8(gUnknown_2027370, a0, x, y, a3, color);
}

UNUSED static void nullsub_158(void)
{
}

#ifdef NONMATCHING // https://decomp.me/scratch/AU1bH
static void sub_8007BA8(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    s32 iVar1; // r1
    s32 iVar3;
    s32 iVar9; // r8?

    u32 *r4;
    u32 r5;
    u32 r6;
    UnkTextStruct1 *ip;
    s32 sp4;
    s32 sp8;
    u32 sp1C; // Used correctly

    s32 yeah;
    u32 *sp10; // r2?

    ip = &a0[a1];

    sp8 = y / 8;

    if (sp8 >= ip->unk8)
        return;

    yeah = ip->unk4 * sp8;

    r4 = ip->unk18 + ((yeah + x / 8) * 8);
    r4 += (sp8 * -8) + y;

    for (sp4 = 0; sp4 < color; sp4++) {
        sp10 = r4;
        iVar1 = x / 8;

        for (iVar9 = 0; iVar9 < a4; iVar9 += 8) {
            if (iVar1 >= ip->unk4)
                break;

            r6 = 0xF0000000;
            r5 = 0xE0000000;
            sp1C = 0;

            for (iVar3 = 0; iVar3 < 8; iVar3++) {
                if ((sp10[0] & r6) == 0)
                    sp1C |= r5;

                r6 >>= 4;
                r5 >>= 4;
            }

            sp10[0] |= sp1C;
            if (ip->unk3C > sp10)
                ip->unk3C = sp10;
            if (ip->unk40 < sp10)
                ip->unk40 = sp10;
            sp10 += 8;
            iVar1++;
        }

        y++;
        r4++;
        if ((y % 8) == 0) {
            r4 += ip->unk20;
            sp8++;
            if (sp8 >= ip->unk8)
                return;
        }

        sp4++;
    }
}
#else
NAKED
static void sub_8007BA8(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x20\n"
    "\tstr r2, [sp]\n"
    "\tlsls r2, r1, 3\n"
    "\tadds r2, r1\n"
    "\tlsls r2, 3\n"
    "\tadds r0, r2\n"
    "\tmov r12, r0\n"
    "\tadds r0, r3, 0\n"
    "\tcmp r3, 0\n"
    "\tbge _08007BC8\n"
    "\tadds r0, r3, 0x7\n"
"_08007BC8:\n"
    "\tasrs r0, 3\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmov r1, r12\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r1, r2]\n"
    "\tldr r4, [sp, 0x8]\n"
    "\tcmp r4, r0\n"
    "\tbge _08007CC4\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r1, r7]\n"
    "\tadds r1, r4, 0\n"
    "\tmuls r1, r0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007BE8\n"
    "\tadds r0, 0x7\n"
"_08007BE8:\n"
    "\tasrs r0, 3\n"
    "\tadds r0, r1, r0\n"
    "\tlsls r0, 5\n"
    "\tmov r2, r12\n"
    "\tldr r1, [r2, 0x18]\n"
    "\tadds r4, r1, r0\n"
    "\tldr r7, [sp, 0x8]\n"
    "\tlsls r0, r7, 3\n"
    "\tsubs r0, r3, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tmovs r0, 0\n"
    "\tstr r0, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x44]\n"
    "\tcmp r0, r1\n"
    "\tbge _08007CC4\n"
"_08007C08:\n"
    "\tadds r2, r4, 0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007C12\n"
    "\tadds r0, 0x7\n"
"_08007C12:\n"
    "\tasrs r1, r0, 3\n"
    "\tmovs r7, 0\n"
    "\tmov r8, r7\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0xC]\n"
    "\tadds r4, 0x4\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tldr r0, [sp, 0x40]\n"
    "\tcmp r8, r0\n"
    "\tbge _08007C94\n"
"_08007C26:\n"
    "\tmov r3, r12\n"
    "\tmovs r4, 0x4\n"
    "\tldrsh r0, [r3, r4]\n"
    "\tcmp r1, r0\n"
    "\tbge _08007C94\n"
    "\tmovs r6, 0xF0\n"
    "\tlsls r6, 24\n"
    "\tmovs r5, 0xE0\n"
    "\tlsls r5, 24\n"
    "\tmovs r7, 0\n"
    "\tstr r7, [sp, 0x1C]\n"
    "\tldr r4, [r2]\n"
    "\tadds r3, r4, 0\n"
    "\tmov r0, r12\n"
    "\tldr r0, [r0, 0x3C]\n"
    "\tmov r9, r0\n"
    "\tmov r7, r12\n"
    "\tldr r7, [r7, 0x40]\n"
    "\tmov r10, r7\n"
    "\tadds r1, 0x1\n"
    "\tstr r1, [sp, 0x10]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tstr r0, [sp, 0x18]\n"
    "\tmovs r1, 0x8\n"
    "\tadd r8, r1\n"
    "\tmovs r1, 0x7\n"
"_08007C5C:\n"
    "\tadds r0, r4, 0\n"
    "\tands r0, r6\n"
    "\tcmp r0, 0\n"
    "\tbne _08007C6A\n"
    "\tldr r7, [sp, 0x1C]\n"
    "\torrs r7, r5\n"
    "\tstr r7, [sp, 0x1C]\n"
"_08007C6A:\n"
    "\tlsrs r6, 4\n"
    "\tlsrs r5, 4\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r1, 0\n"
    "\tbge _08007C5C\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\torrs r3, r0\n"
    "\tstr r3, [r2]\n"
    "\tcmp r9, r2\n"
    "\tbls _08007C82\n"
    "\tmov r1, r12\n"
    "\tstr r2, [r1, 0x3C]\n"
"_08007C82:\n"
    "\tcmp r10, r2\n"
    "\tbcs _08007C8A\n"
    "\tmov r3, r12\n"
    "\tstr r2, [r3, 0x40]\n"
"_08007C8A:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tldr r2, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x40]\n"
    "\tcmp r8, r4\n"
    "\tblt _08007C26\n"
"_08007C94:\n"
    "\tldr r3, [sp, 0xC]\n"
    "\tldr r4, [sp, 0x14]\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08007CB8\n"
    "\tmov r7, r12\n"
    "\tldr r0, [r7, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tadds r0, 0x1\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmovs r1, 0x8\n"
    "\tldrsh r0, [r7, r1]\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tcmp r2, r0\n"
    "\tbge _08007CC4\n"
"_08007CB8:\n"
    "\tldr r7, [sp, 0x4]\n"
    "\tadds r7, 0x1\n"
    "\tstr r7, [sp, 0x4]\n"
    "\tldr r0, [sp, 0x44]\n"
    "\tcmp r7, r0\n"
    "\tblt _08007C08\n"
"_08007CC4:\n"
    "\tadd sp, 0x20\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}
#endif // NONMATCHING

UNUSED static void sub_8007CD4(u32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8007D00(gUnknown_2027370, a0, a1, a2, a3, a4);
}

UNUSED static void nullsub_159(void)
{
}

NAKED // Very similar to sub_8007BA8
static void sub_8007D00(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x20\n"
    "\tstr r2, [sp]\n"
    "\tlsls r2, r1, 3\n"
    "\tadds r2, r1\n"
    "\tlsls r2, 3\n"
    "\tadds r0, r2\n"
    "\tmov r12, r0\n"
    "\tadds r0, r3, 0\n"
    "\tcmp r3, 0\n"
    "\tbge _08007D20\n"
    "\tadds r0, r3, 0x7\n"
"_08007D20:\n"
    "\tasrs r0, 3\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmov r1, r12\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r1, r2]\n"
    "\tldr r4, [sp, 0x8]\n"
    "\tcmp r4, r0\n"
    "\tbge _08007E0E\n"
    "\tmovs r5, 0x4\n"
    "\tldrsh r0, [r1, r5]\n"
    "\tadds r1, r4, 0\n"
    "\tmuls r1, r0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007D40\n"
    "\tadds r0, 0x7\n"
"_08007D40:\n"
    "\tasrs r0, 3\n"
    "\tadds r0, r1, r0\n"
    "\tlsls r0, 5\n"
    "\tmov r2, r12\n"
    "\tldr r1, [r2, 0x18]\n"
    "\tadds r4, r1, r0\n"
    "\tldr r5, [sp, 0x8]\n"
    "\tlsls r0, r5, 3\n"
    "\tsubs r0, r3, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tmovs r0, 0\n"
    "\tb _08007E06\n"
"_08007D5A:\n"
    "\tadds r2, r4, 0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007D64\n"
    "\tadds r0, 0x7\n"
"_08007D64:\n"
    "\tasrs r1, r0, 3\n"
    "\tmovs r5, 0\n"
    "\tmov r8, r5\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0xC]\n"
    "\tadds r4, 0x4\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tldr r0, [sp, 0x40]\n"
    "\tcmp r8, r0\n"
    "\tbge _08007DE0\n"
"_08007D78:\n"
    "\tmov r3, r12\n"
    "\tmovs r4, 0x4\n"
    "\tldrsh r0, [r3, r4]\n"
    "\tcmp r1, r0\n"
    "\tbge _08007DE0\n"
    "\tmovs r4, 0xF0\n"
    "\tlsls r4, 24\n"
    "\tmovs r6, 0xE0\n"
    "\tlsls r6, 24\n"
    "\tmovs r7, 0\n"
    "\tldr r5, [r2]\n"
    "\tstr r5, [sp, 0x1C]\n"
    "\tadds r3, r5, 0\n"
    "\tmov r0, r12\n"
    "\tldr r0, [r0, 0x3C]\n"
    "\tmov r9, r0\n"
    "\tmov r5, r12\n"
    "\tldr r5, [r5, 0x40]\n"
    "\tmov r10, r5\n"
    "\tadds r1, 0x1\n"
    "\tstr r1, [sp, 0x10]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tstr r0, [sp, 0x18]\n"
    "\tmovs r1, 0x8\n"
    "\tadd r8, r1\n"
    "\tmovs r1, 0x7\n"
"_08007DAE:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tands r0, r4\n"
    "\tcmp r0, r6\n"
    "\tbne _08007DB8\n"
    "\torrs r7, r4\n"
"_08007DB8:\n"
    "\tlsrs r4, 4\n"
    "\tlsrs r6, 4\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r1, 0\n"
    "\tbge _08007DAE\n"
    "\tbics r3, r7\n"
    "\tstr r3, [r2]\n"
    "\tcmp r9, r2\n"
    "\tbls _08007DCE\n"
    "\tmov r3, r12\n"
    "\tstr r2, [r3, 0x3C]\n"
"_08007DCE:\n"
    "\tcmp r10, r2\n"
    "\tbcs _08007DD6\n"
    "\tmov r4, r12\n"
    "\tstr r2, [r4, 0x40]\n"
"_08007DD6:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tldr r2, [sp, 0x18]\n"
    "\tldr r5, [sp, 0x40]\n"
    "\tcmp r8, r5\n"
    "\tblt _08007D78\n"
"_08007DE0:\n"
    "\tldr r3, [sp, 0xC]\n"
    "\tldr r4, [sp, 0x14]\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08007E02\n"
    "\tmov r1, r12\n"
    "\tldr r0, [r1, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tadds r2, 0x1\n"
    "\tstr r2, [sp, 0x8]\n"
    "\tmovs r5, 0x8\n"
    "\tldrsh r0, [r1, r5]\n"
    "\tcmp r2, r0\n"
    "\tbge _08007E0E\n"
"_08007E02:\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tadds r0, 0x1\n"
"_08007E06:\n"
    "\tstr r0, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x44]\n"
    "\tcmp r0, r1\n"
    "\tblt _08007D5A\n"
"_08007E0E:\n"
    "\tadd sp, 0x20\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}

void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8007E64(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a5, a6);
}

UNUSED static void nullsub_160(void)
{
}

static void sub_8007E64(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        s32 id = (strPtr->unk4 * a4) + a3;
        u32 *unk18Ptr = &strPtr->unk18[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    if (strPtr->unk3C > loopUnk18Ptr) {
                        strPtr->unk3C = loopUnk18Ptr;
                    }
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    if (strPtr->unk40 < loopUnk18Ptr) {
                        strPtr->unk40 = loopUnk18Ptr;
                    }
                    a7++;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

static u32 FlipPixelsHorizontally(u32 a0)
{
    u32 r0;

    r0 = (a0 >> 28)  & 0xF;
    r0 |= (a0 >> 20) & 0xF0;
    r0 |= (a0 >> 12) & 0xF00;
    r0 |= (a0 >> 4)  & 0xF000;
    r0 |= (a0 << 4)  & 0xF0000;
    r0 |= (a0 << 12) & 0xF00000;
    r0 |= (a0 << 20) & 0xF000000;
    r0 |= (a0 << 28) & 0xF0000000;

    return r0;
}

UNUSED static void sub_8007FEC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8008030(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a5, a6);
}

UNUSED static void nullsub_161(void)
{
}

// Similar to sub_8007E64
static void sub_8008030(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        u32 *unk18Ptr = &strPtr->unk18[((strPtr->unk4 * a4) + (a3 + a5)) * 8];
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3 + a5;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                xMaybe--;
                loopUnk18Ptr -= 8;
                if (xMaybe < strPtr->unk4) {
                    if (strPtr->unk3C > loopUnk18Ptr) {
                        strPtr->unk3C = loopUnk18Ptr;
                    }
                    loopUnk18Ptr[0] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[1] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[2] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[3] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[4] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[5] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[6] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[7] = FlipPixelsHorizontally(*(a7++));
                    if (strPtr->unk40 < loopUnk18Ptr + 8) {
                        strPtr->unk40 = loopUnk18Ptr + 8;
                    }
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                else {
                    a7 += 8;
                }
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

// Similar to sub_8007E64
UNUSED static void sub_80081A4(s32 a0, s32 a3, s32 a4, s32 a7Id)
{
    s32 i, j, a5, a6;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[a0];
    const u32 *a7 = gUnknown_80B86B4[a7Id];

    a3 /= 8;
    a4 /= 8;
    a5 = 2;
    a6 = 2;
    if (a4 < strPtr->unk8) {
        s32 id = (strPtr->unk4 * a4) + a3;
        u32 *unk18Ptr = &strPtr->unk28[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    a7++;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2)
{
    DisplayMonPortrait(gUnknown_2027370, gUnknown_202B038[0], a0, compressedData, a2);
}

UNUSED static void nullsub_162(void)
{
}

static void DisplayMonPortrait(UnkTextStruct1 *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a4 *= 4096;
    DecompressAT((u8 *)strPtr->unk18, (strPtr->unk4 * 32) * strPtr->unk8, compressedData);
    for (i = 0; i < strPtr->unk8; i++) {
        for (j = 0; j < strPtr->unk4; j++) {
            a1[strPtr->unk2 + i][strPtr->unk0 + j] &= 0xFFF;
            a1[strPtr->unk2 + i][strPtr->unk0 + j] |= a4;
        }
    }
    strPtr->unk30 = strPtr->unk28;
    strPtr->unk34 = strPtr->unk1C;
    strPtr->unk38 = strPtr->unk2C;
    strPtr->unk44 = 1;
}

static void sub_8008334(u32 *r7, u32 *r12)
{
    s32 i;
    u32 r2, r3;
    u32 r4, r1;

    r4 = *r7;
    r1 = *r12;

    r3 = 0;
    r2 = 0;

    for (i = 0; i < 32; i += 4) {
        r2 <<= 4;
        r3 <<= 4;
        r2 |= r4 & 0xF;
        r3 |= r1 & 0xF;
        r4 >>= 4;
        r1 >>= 4;
    }
    *r7 = r3;
    *r12 = r2;
}

void DisplayMonPortraitSpriteFlipped(s32 a0, const u8 *compressedData, s32 a1)
{
    DisplayMonPortraitFlipped(gUnknown_2027370, a0, compressedData, a1);
}

UNUSED static void nullsub_163(void)
{
}

static void DisplayMonPortraitFlipped(UnkTextStruct1 *a0, s32 a1, const u8 *compressedData, s32 a3)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a1];

    DisplayMonPortraitSprite(a1, compressedData, a3);
    for (i = 0; i < strPtr->unk8; i++) {
        s32 r8 = strPtr->unk4 / 2;
        if (strPtr->unk4 & 1)
            r8++;
        for (j = 0; j < r8; j++) {
            u32 *r4, *r5;
            s32 unk4Mul = strPtr->unk4 * i;

            r4 = &strPtr->unk18[(unk4Mul + j) * 8];
            unk4Mul--;
            r5 = &strPtr->unk18[(unk4Mul + (strPtr->unk4 - j)) * 8];

            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
        }
    }
}

UNUSED static void sub_8008468(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a6)
{
    sub_80084A4(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a6);
}

UNUSED static void nullsub_164(void)
{
}

// Effectively unused
static void sub_80084A4(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                xMaybe++;
            }
            a4++;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

// Oddly similar to sub_803DEC8
const struct unkChar *GetCharacter(s32 chr)
{
    s32 r2, r4;
    const struct unkChar *ret;
    const struct unkChar *strPtr = sCharmaps[sCurrentCharmap]->unk4;
    // TODO: create labels for these
    if (chr > 63487 && chr < 65535)
    {
        s32 r2 = chr & 0xFF;
        s32 r1 = (chr & 0xFF00) >> 8;
        r2 -= 32;
        r1 -= 248;
        ret = &strPtr[r1 * 224 + r2];
    }
    else
    {
        r4 = 0;
        r2 = sCharmaps[sCurrentCharmap]->unk0 - 1;
        while (r4 < r2) {
            s32 r1 = (r4 + r2) / 2;
            if (strPtr[r1].unk4 == chr) {
                r4 = r1;
                break;
            }
            else if (strPtr[r1].unk4 < chr) {
                r4 = r1 + 1;
            }
            else {
                r2 = r1;
            }
        }

        ret = &strPtr[r4];
        if (ret->unk4 != chr)
            ret = &gUnknown_80B86A4;

    }
    return ret;
}

static s32 HexDigitValue(u8 chr)
{
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'a' && chr <= 'f')
        return (chr - 'a') + 10;
    else
        return 1;
}

const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *a0)
{
    s32 currChr = *a1;
    if (currChr == 0x7E) {
        s32 hexDigit;

        a1++;
        hexDigit = (HexDigitValue(a1[0]) << 4) + HexDigitValue(a1[1]);
        if (*a1 != '\0') {
            a1++;
            if (*a1 != '\0') {
                a1++;
            }
        }
        *a0 = hexDigit;
        return a1;
    }
    else if ((currChr >= 0x81 && currChr <= 0x84) || currChr == 0x87) {
        *a0 = a1[1] | (a1[0] << 8);
        return a1 + 2;
    }
    else {
        *a0 = currChr;
        return a1 + 1;
    }
}

UNUSED static void nullsub_165(void)
{
}

UNUSED static void nullsub_166(void)
{
}

UNUSED static void nullsub_167(void)
{
}

UNUSED static void nullsub_168(void)
{
}

static const u32 gUnknown_80B8868[] =
{
    0, 0xF, 0xFF, 0xFFF, 0xFFFF, 0xFFFFF, 0xFFFFFF, 0xFFFFFFF,
    0xFFFFFFFF, 0xFFFFFFF0, 0xFFFFFF00, 0xFFFFF000, 0xFFFF0000,
    0xFFF00000, 0xFF000000, 0xF0000000
};

UNUSED static void sub_80086C8(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    u32 *r5;
    s32 r2, r0, r1;
    UnkTextStruct1 *strPtr = &a0[a1];

    if (a2 < 0) {
        a4 += a2;
        a2 = 0;
    }
    if (a3 < 0) {
        a5 += a3;
        a3 = 0;
    }

    if (a4 + a2 > strPtr->unk4 * 8) {
        a4 = (strPtr->unk4 * 8) - a2;
    }
    if (a3 + a5 > strPtr->unk8 * 8) {
        a5 = (strPtr->unk8 * 8) - a3;
    }

    r2 = strPtr->unk4 * (a3 / 8);
    r0 = 8 * (r2 + (a2 / 8));
    r1 = a3 - ((a3 / 8) * 8);
    r5 = &strPtr->unk18[r0 + r1];
    while (a5 > 0) {
        u32 *loopPtr;
        s32 r4, r6;

        loopPtr = r5;
        r4 = a4;
        r6 = a2;
        if (strPtr->unk3C > r5) {
            strPtr->unk3C = r5;
        }

        while (r4 > 0) {
            s32 r3;
            if (r4 < 8) {
                r3 = r4;
                *loopPtr &= gUnknown_80B8868[(r4 & 7) + 8];
            }
            else if ((r6 & 7) != 0) {
                r3 = 8 - (r6 & 7);
                *loopPtr &= gUnknown_80B8868[r6 & 7];
            }
            else {
                r3 = 8;
                *loopPtr = r6 & 7;
            }

            loopPtr += 8;
            r4 -= r3;
            r6 += r3;
        }
        a5--;
        a3++;
        if (strPtr->unk40 < r5) {
            strPtr->unk40 = r5;
        }
        r5++;
        if (!(a3 & 7)) {
            r5 = &r5[strPtr->unk20];
        }
    }
}

void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8008818(gUnknown_2027370, a0, a1, a2, a3, a4);
}

UNUSED static void nullsub_176(void)
{
}

static void sub_8008818(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a1];
    s32 a2Div = a2 / 8;
    s32 a3Div = a3 / 8;

    for (i = 0; i < a5; i += 8) {
        u32 *ptr = &strPtr->unk18[((strPtr->unk4 * a3Div) + a2Div) * 8];
        for (j = 0; j < a4; j += 8) {
            if (strPtr->unk3C > ptr) {
                strPtr->unk3C = ptr;
            }
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *ptr = 0;
            if (strPtr->unk40 < ptr) {
                strPtr->unk40 = ptr;
            }
            ptr++;
        }
        a3Div++;
    }
}

bool8 xxx_call_update_bg_vram(void)
{
    bool8 ret = FALSE;
    if (gUnknown_20274A5 != 0) {
        gUnknown_20274A5 = FALSE;
        sub_80099C0();
    }
    ret = xxx_update_bg_vram(gUnknown_2027370);
    return ret;
}

static bool8 xxx_update_bg_vram(UnkTextStruct1 *a0)
{
    s32 i, j;
    u32 r5;
    bool8 ret = FALSE;

    for (i = 0; i < 4; i++) {
        UnkTextStruct1 *strPtr = &a0[i];
        if (strPtr->unk4 == 0)
            continue;
        r5 = strPtr->unk38;
        if (r5 == 0)
            continue;

        if (strPtr->unk45) {
            u32 *r2, *r1;

            CpuCopy(strPtr->unk28, strPtr->unk18, 0xD00);
            // The reason for void casts is because we want to add 0xD00/r5 directly to pointers. Because pointers are u32, without the casts, it would multiply the value by 4.
            r2 = (void *)(strPtr->unk18) + 0xD00;
            r1 = (void *)(strPtr->unk28) + 0xD00;
            for (j = 0; j < strPtr->unk4; j++) {
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = 0xDDDDDDDD;
                *(r1++) = 0xEEEEEEEE;
                *(r1++) = 0xFFFFFFFF;
                r2 += 3;
            }
            strPtr->unk38 = 0;
        }
        else {
            CpuCopy(strPtr->unk30, strPtr->unk34, r5);
            strPtr->unk34 += (r5 / 4);
            strPtr->unk30 = (void *)(strPtr->unk30) + r5;
            strPtr->unk38 -= r5;
        }

        if (strPtr->unk38 == 0) {
            strPtr->unk44 = 0;
        }
        ret = TRUE;
    }

    return ret;
}

static void sub_800898C(void)
{
    s32 i;

    for (i = 0; i < 161; i++) {
        gUnknown_3000E94[i] = 0xF0F0;
    }
}

static void sub_80089AC(const Window *r4, DungeonPos *r5_Str)
{
    u8 *r6;

    if (r4->unk0 & 0x40)
        return;

    r6 = (void*) &gUnknown_3000E94;
    if (r4->type == WINDOW_TYPE_WITHOUT_BORDER) {
        s32 r12 = (r4->pos.x + r5_Str->x) * 8;
        s32 r5 = (r4->pos.y + r5_Str->y) * 8;
        s32 r7 = (r4->pos.x + r5_Str->x + r4->width) * 8;
        s32 r2 = (r4->pos.y + r5_Str->y + r4->height) * 8;
        if (r4->height != 0) {
            if (r5 < 0)
                r5 = 0;
            if (r2 < 0)
                r2 = 0;
            if (r5 > 160)
                r5 = 160;
            if (r2 > 160)
                r2 = 160;
            while (r5 < r2) {
                s32 id = r5 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r7;
                    r6[id] = r12;
                }
                else {
                    if (r6[id] < r7) {
                        r6[id] = r7;
                    }
                    id++;
                    if (r6[id] > r12) {
                        r6[id] = r12;
                    }
                }
                r5++;
            }
        }
    }
    else if (r4->type == WINDOW_TYPE_WITH_HEADER) {
        s32 i;
        s32 r9 = ((r4->pos.x + r5_Str->x) * 8) - 5;
        s32 r5 = ((r4->pos.y + r5_Str->y) * 8) - 4;
        s32 var_24 = ((r4->pos.x + r5_Str->x + r4->width) * 8) + 5;
        s32 r8 = ((r4->pos.y + r5_Str->y + r4->height) * 8) + 5;
        s32 r12 = ((r4->pos.x + r5_Str->x) * 8) + 3;
        const WindowHeader *r2 = r4->unk14;
        s32 tmp = r2->f2 - 1;
        s32 r10 = (((tmp + r2->f0 + 2) * 8) + r12) - 4;
        s32 r4 = r9 + ((r2->f1 + 1) * 8);
        s32 r7 = (r4 + ((r2->f2 + 2) * 8)) - 4;

        if (r5 < 0)
            r5 = 0;
        if (r8 < 0)
            r8 = 0;
        if (r5 > 160)
            r5 = 160;
        if (r8 > 160)
            r8 = 160;

        for (i = 0; i < 4; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r7;
                r6[id] = r4;
            }
            else {
                if (r6[id] < r7) {
                    r6[id] = r7;
                }
                id++;
                if (r6[id] > r4) {
                    r6[id] = r4;
                }
            }
            r5++;
        }
        for (i = 0; i < 8; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r10;
                r6[id] = r12;
            }
            else {
                if (r6[id] < r10) {
                    r6[id] = r10;
                }
                id++;
                if (r6[id] > r12) {
                    r6[id] = r12;
                }
            }
            r5++;
        }

        while (r5 < r8) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = var_24;
                r6[id] = r9;
            }
            else {
                if (r6[id] < var_24) {
                    r6[id] = var_24;
                }
                id++;
                if (r6[id] > r9) {
                    r6[id] = r9;
                }
            }
            r5++;
        }
    }
    else {
        s32 r8 = ((r4->pos.x + r5_Str->x) * 8) - 5;
        s32 r3 = ((r4->pos.y + r5_Str->y) * 8) - 5;
        s32 r12 = ((r4->pos.x + r5_Str->x + r4->width) * 8) + 5;
        s32 r5 = ((r4->pos.y + r5_Str->y + r4->height) * 8) + 5;
        if (r4->height != 0) {
            if (r4->type == 0) {
                r3 += 8;
                r5 = ((r4->pos.y + r5_Str->y + r4->height) * 8) - 3;
            }
            if (r3 < 0)
                r3 = 0;
            if (r5 < 0)
                r5 = 0;
            if (r3 > 160)
                r3 = 160;
            if (r5 > 160)
                r5 = 160;
            while (r3 < r5) {
                s32 id = r3 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r12;
                    r6[id] = r8;
                }
                else {
                    if (r6[id] < r12) {
                        r6[id] = r12;
                    }
                    id++;
                    if (r6[id] > r8) {
                        r6[id] = r8;
                    }
                }
                r3++;
            }
        }
    }
}

void CallPrepareTextbox_8008C54(u32 strId)
{
    PrepareTextbox_8008C6C(gUnknown_2027370, strId);
}

UNUSED static void nullsub_169(void)
{
}

static void PrepareTextbox_8008C6C(UnkTextStruct1 *strArr, u32 strId)
{
    s32 i;
    UnkTextStruct1 *strPtr = &strArr[strId];

    if (!strPtr->unk45) {
        s32 count = (strPtr->unk4 * strPtr->unk8) * 32;
        for (i = 0; i < count; i += 32) {
            CpuClear(&strPtr->unk18[i / 4u], 32);
        }
    }
    else {
        s32 count = (strPtr->unk4 * (strPtr->unk8 - 1)) * 32;
        u32 *ptr = strPtr->unk18;
        for (i = 0; i < strPtr->unk4; i++) {
            *(ptr++) = 0xFFFFFFFF;
            *(ptr++) = 0xEEEEEEEE;
            *(ptr++) = 0xDDDDDDDD;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
        }
        for (i = 0; i < count; i += 32) {
            CpuClear(ptr, 32);
            ptr += 8;
        }
    }

    if (strPtr->unkC == 6) {
        strPtr->unk46 = 1;
        sub_8007958(strArr, strId, 0, 10, strPtr->unk4 * 8, 0xE);
        sub_8007958(strArr, strId, 0, 11, strPtr->unk4 * 8, 0xD);
        strPtr->unk46 = 0;
    }

    strPtr->unk30 = strPtr->unk28;
    strPtr->unk34 = strPtr->unk1C;
    strPtr->unk38 = strPtr->unk2C;
    strPtr->unk44 = 1;
}

bool8 sub_8008D8C(u32 strId)
{
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strId];
    return (strPtr->unk38 != 0);
}

UNUSED static bool8 sub_8008DA8(void)
{
    return FALSE;
}

UNUSED static void sub_8008DAC(s32 a0, s32 a1, s32 a2)
{
    gUnknown_202B038[0][a1][a0] = a2;
    gUnknown_20274A5 = TRUE;
}

void sub_8008DC8(s32 a0, s32 a1, u16 a2, s32 a3)
{
    gUnknown_202B038[0][a1][a0] = a2;
    gUnknown_202B038[1][a1][a0] = a3;
    gUnknown_20274A5 = TRUE;
}

UNUSED static void sub_8008DF4(s32 a0, s32 a1, u8 *a2)
{
    u8 r1;

    while (1) {
        if (*a2 == 0)
            break;

        r1 = *a2;
        if (r1 >= 97 && r1 <= 122) {
            r1 -= 32;
        }
        gUnknown_202B038[0][a1][a0] = 0xF000 | (r1 + 0x258);
        a2++;
        a0++;
    }
    gUnknown_20274A5 = TRUE;
}

UNUSED static void sub_8008E58(s32 a0, s32 a1, u8 *a2, s32 a3)
{
    u8 r1;

    while (1) {
        if (*a2 == 0)
            break;

        r1 = *a2;
        if (a3 == 0)
            break;

        if (r1 >= 97 && r1 <= 122) {
            r1 -= 32;
        }
        gUnknown_202B038[0][a1][a0] = 0xF000 | (r1 + 0x258);
        a2++;
        a0++;
        a3--;
    }
    gUnknown_20274A5 = TRUE;
}

s32 sub_8008ED0(const u8 *str)
{
    s32 ret = 0;

    while (1) {
        const u8 *strPtr;
        u32 chr;

        strPtr = xxx_get_next_char_from_string(str, &chr);
        str = strPtr;
        if (chr == 0)
            break;
        if (chr == '\r' || chr == '\n')
            break;
        if (chr == 0x82A0 || chr == 0x82A2)
            continue;
        if (chr == '\e')
            break;

        if (chr == '#') {
            if (*strPtr == 'n' || *strPtr == '[' || *strPtr == 'P')
                break;
            switch (*strPtr) {
                case '=':
                case '~':
                    str = strPtr + 2;
                    break;
                case 'C':
                case 'c':
                    str += 2;
                    break;
                case 'R':
                case 'r':
                    str++;
                    break;
                case '+':
                case 'W':
                    str = strPtr + 1;
                    break;
            }
        }
        else if (chr == '`') {
            ret += 6;
        }
        else {
            const struct unkChar *ptr = GetCharacter(chr);
            if (ptr != NULL) {
                ret += ptr->unk6 + sCharacterSpacing;
            }
        }
    }

    return ret;
}

void PrintStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, terminatingChr, 0, lineSpacing);
}

void PrintStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, terminatingChr, 0, 13);
}

UNUSED static void nullsub_170(void)
{
}

// Identical to PrintStringOnWindow
UNUSED static void UnusedPrintStringOnWindow(s32 x, u32 y, const u8 *str, u32 windowId, u32 terminatingChr)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, terminatingChr, 0, 13);
}

UNUSED static void nullsub_171(void)
{
}

static void xxx_draw_string(UnkTextStruct1 *strArr, s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 characterSpacing, s32 lineSpacing)
{
    struct UnkDrawStringStruct sp;
    u32 currChr;

    sp.unk0 = x;
    sp.unk2 = y;
    sp.unkC = x;
    sp.unk10 = 7;
    while (1) {
        str = HandleTextFormat(strArr, str, &sp);
        str = xxx_get_next_char_from_string(str, &currChr);
        if (currChr == '\0' || currChr == terminatingChr)
            break;

        if (currChr == 0x82A0) {
            sCurrentCharmap = 0;
        }
        else if (currChr == 0x82A2) {
            sCurrentCharmap = 1;
        }
        else if (currChr == '\e') {
            break;
        }
        else if (currChr == '\r' || currChr == '\n') {
            sp.unk0 = sp.unkC;
            sp.unk2 += lineSpacing;
        }
        else if (currChr == '\x1D') { // ASCII group separator.
            sp.unk0 = sp.unkC;
            sp.unk2 += 5;
        }
        else if (currChr == '`') {
            sp.unk0 += 6;
        }
        else if (characterSpacing == 0) {
            sp.unk0 += xxx_draw_char(strArr, sp.unk0, sp.unk2, currChr, sp.unk10, windowId);
        }
        else {
            const struct unkChar *chrPtr = GetCharacter(currChr);
            if (chrPtr != NULL) {
                s32 x = sp.unk0;
                s32 x2 = sCharacterSpacing + 10;
                x +=((x2 - chrPtr->unk6) / 2);
                xxx_draw_char(strArr, x, sp.unk2, currChr, sp.unk10, windowId);
                sp.unk0 += characterSpacing;
            }
        }
    }
}

static const u8 *sub_800915C(s16 *a0, const u8 *str)
{
    s32 a = 0;

    while (1)
    {
        if (*str == '.') {
            str++;
            break;
        }
        else if (*str >= '0' && *str <= '9') {
            a *= 10;
            a += (*str - '0');
            str++;
        }
        else {
            break;
        }
    }

    *a0 = a;
    return str;
}

const u8 *xxx_handle_format_global(const u8 *str, struct UnkDrawStringStruct *unkStrPtr)
{
    return HandleTextFormat(gUnknown_2027370, str, unkStrPtr);
}

UNUSED static s32 sub_80091A8(s32 a0)
{
    return a0 + 1;
}

static const u8 *HandleTextFormat(UnkTextStruct1 *strArr, const u8 *str, struct UnkDrawStringStruct *sp)
{
    while (1) {
        if (str[0] == '#') {
            if (str[1] == '[') {
                const u8 *strBefore = str;
                str += 2;
                sp->unk21 = 0;
                while (*str != '\0') {
                    if (*str == ']') {
                        str++;
                        break;
                    }
                    str++;
                }
                if (sp->unk24 != NULL) {
                    const u8 *strNew = sp->unk24(strBefore, str, sp);
                    if (strNew != NULL)
                        str = strNew;
                }

                if (sp->unk21 != 0)
                    break;
            }
            else if (str[1] == '=') {
                sp->unk0 = str[2];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == 'y') {
                sp->unk2 = str[2];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == '>') {
                str = sub_800915C(&sp->unk0, str + 2);
            }
            else if (str[1] == '.') {
                sp->unk0 += str[2];
                str += 3;
            }
            else if (str[1] == 'n') {
                sp->unk0 = sp->unkC;
                sp->unk2 += 11;
                str += 2;
            }
            else if (str[1] == ':') {
                sp->unk4 = sp->unk0;
                str += 2;
            }
            else if (str[1] == ';') {
                sp->unk0 = sp->unk4 + str[2];
                str += 3;
            }
            else if (str[1] == '+') {
                str += 2;
                sp->unk0 = (strArr[0].unk4 * 8) - sub_8008ED0(str);
                sp->unk0 /= 2;
            }
            else if (str[1] == 'C') {
                sp->unk14 = sp->unk10;
                sp->unk10 = InterpretColorChar(str[2]);
                str += 3;
            }
            else if (str[1] == '_') {
                sp->unk14 = sp->unk10;
                sp->unk10 = gUnknown_202749A[str[2]];
                str += 3;
                if (*str == '.')
                    str++;
            }
            else if (str[1] == 'R') {
                sp->unk10 = sp->unk14;
                str += 2;
            }
            else if (str[1] == 'c') {
                sp->unk18 = sp->unk10;
                sp->unk10 = InterpretColorChar(str[2]);
                str += 3;
            }
            else if (str[1] == 'r') {
                sp->unk10 = sp->unk18;
                str += 2;
            }
            else if (str[1] == 'S') {
                sUnknown_20274A6[str[2] & 0x7F] = str[3] & 0x7F;
                str += 4;
            }
            else if (str[1] == 'W') {
                str += 2;
                sp->unk8 = ((strArr[0].unk0 * 8) + sp->unk0) - 2;
                sp->unkA = ((strArr[0].unk2 * 8) + sp->unk2) + 3;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == 'P') {
                str += 2;
                sp->unk2 = 9999;
                sp->unk1C = 0;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == 'p') {
                str += 2;
                sp->unk2 = 9999;
                sp->unk1C = 1;
                sp->unk20 = 1;
                break;
            }
            else if (str[1] == '~') {
                sp->unk2C = str[2];
                sp->unk21 = 1;
                str += 3;
            }
            else {
                return str;
            }
        }
        else {
            break;
        }
    }

    return str;
}

static void sub_8009388(void)
{
    s32 i, j;

    gUnknown_202B038[0][0][0] = 0xF279;
    gUnknown_202B038[1][0][0] = 0xF27A;
    for (i = sUnknown_202B020; i < sUnknown_202B024; i++) {
        gUnknown_202B038[0][i][0] = 0xF279;
        gUnknown_202B038[1][i][0] = 0xF27A;
        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xF27A;
        }
    }
}

void sub_8009408(s32 from, s32 to)
{
    s32 i, j;

    gUnknown_202B038[0][0][0] = 0xF279;
    gUnknown_202B038[1][0][0] = 0xF27A;
    for (i = from; i < to; i++) {
        gUnknown_202B038[0][i][0] = 0xF279;
        gUnknown_202B038[1][i][0] = 0xF27A;
        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xF27A;
        }
    }
    gUnknown_20274A5 = TRUE;
}

UNUSED static void sub_8009488(s32 strArrId)
{
    s32 i, j;
    s32 id0, id1;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strArrId];

    id0 = strPtr->unk2;
    for (i = 0; i < strPtr->unk6; i++) {
        id1 = strPtr->unk0;
        for (j = 0; j < strPtr->unk4; j++) {
            gUnknown_202B038[0][id0][id1] &= 0xFC00;
            gUnknown_202B038[1][id0][id1] = 0xF27A;
            id1++;
        }
        id0++;
    }
}

UNUSED static void nullsub_172(void)
{
}

void sub_8009524(s32 strArrId)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strArrId];
    s32 id0 = strPtr->unk2 - 1;

    for (i = 0; i < strPtr->unk6 + 2; i++) {
        s32 id1 = strPtr->unk0 - 1;
        for (j = 0; j < strPtr->unk4 + 2; j++) {
            gUnknown_202B038[0][id0][id1] &= 0xFC00;
            gUnknown_202B038[1][id0][id1] = 0xF27A;
            id1++;
        }
        id0++;
    }
}

UNUSED static void nullsub_173(void)
{
}

void sub_80095CC(s32 a0, s32 a1)
{
    sUnknown_202B020 = a0;
    sUnknown_202B024 = a1;
}

UNUSED static void nullsub_174(void)
{
}

s32 sub_80095E4(s32 a0, s32 a1)
{
    s32 r1;

    if (a1 == 0)
        a1 = 10;
    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

// Same as sub_80095E4 except it doesn't check for a1 == 0
s32 sub_8009614(s32 a0, s32 a1)
{
    s32 r1;

    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

static s32 InterpretColorChar(u8 a0)
{
    if (a0 < 16)
        return a0;
    if (a0 >= '0' && a0 <= '?')
        return a0 - '0';

    switch (a0) {
        case 'H':
        case 'I':
            return 4;
        case 'E':
        case 'S':
        case 'T':
            return 15;
        case 'G':
        case 'M':
            return 5;
        case 'C':
        case 'D':
        case 'N':
            return 6;
        case 'W':
            return 2;

    }
    return 7;
}

struct FontData {
    u32 size;
    u8 dataArray[136 * 32];
};

struct FontSpData {
    u32 size;
    u8 dataArray[16 * 32];
};

void InitGraphics(void)
{
    u32 count;
    OpenedFile *file;
    u32 *dest;
    struct FontData *font;
    struct FontSpData *fontSp;
#ifdef NONMATCHING
    RGB *data;
    u32 size;
    const struct FileArchive *arc;
#else
    register RGB *data asm("r4");
    register u32 size asm("r5");
    register const struct FileArchive *arc asm("r4");
#endif

    gUnknown_203B090 = 1;
    dest = (u32 *)VRAM;
    for(count = 0; count < 0x6000; count++)
    {
        *dest++ = 0;
    }

    dest = (u32 *)PLTT;
    for(count = 0; count < 0x100; count++)
    {
        *dest++ = 0;
    }

    dest = (u32 *)OAM;
    for(count = 0; count < 0x100; count++)
    {
         *dest++ = 0x00a000a0;
    }

    arc = &gSystemFileArchive;

    file = OpenFileAndGetFileDataPtr(gUnknown_80B88B0, arc);
    font = (struct FontData *)(file->data);
    size = font->size;
    CpuCopy((u32 *)0x06004f00, font->dataArray, size * 32);
    CloseFile(file);

    file = OpenFileAndGetFileDataPtr(gUnknown_80B88B8, arc);
    fontSp = (struct FontSpData *)(file->data);
    size = fontSp->size;
    CpuCopy((u32 *)0x06017e00, fontSp->dataArray, size * 32);
    CloseFile(file);

    InitFontPalette();
    file = OpenFileAndGetFileDataPtr(gUnknown_80B88C0, arc);
    data = (RGB *)file->data;

    for(count = 0; (s32)count < 0x10; data++, count++)
    {
        SetBGPaletteBufferColorArray(0x1F0 + count, data);
    }
    CloseFile(file);
    TransferBGPaletteBuffer();
}

// These functions run from IWRAM for improved performance.
IWRAM_INIT void sub_8272760(s32 id)
{
    sub_8272774(gUnknown_2027370, id);
}

IWRAM_INIT static void sub_8272774(UnkTextStruct1 *txtStructs, s32 id)
{
    UnkTextStruct1 *txtStructPtr = &txtStructs[id];

    if (txtStructPtr->unk8 > 0) {
        s32 i, j;
        u32 *dstPtr;
        s32 n;
        s32 id8, id9;

        if (txtStructPtr->unkC == 6) {
            s32 unk4 = txtStructPtr->unk4;
            s32 dstAdd = ((txtStructPtr->unk24 + 2) * 8);
            dstAdd *= unk4;
            dstPtr = txtStructPtr->unk18 + dstAdd;
            n = txtStructPtr->unk8 - 2;
        }
        else {
            dstPtr = txtStructPtr->unk18;
            n = txtStructPtr->unk8;
        }

        id8 = txtStructPtr->unk20 + 8;
        id9 = txtStructPtr->unk20 + 9;
        for (i = 0; i < txtStructPtr->unk4; i++) {
            s32 to = n - 1;
            u32 *loopPtr = dstPtr;
            for (j = 0; j < to; j++) {
                loopPtr[0] = loopPtr[2];
                loopPtr[1] = loopPtr[3];
                loopPtr[2] = loopPtr[4];
                loopPtr[3] = loopPtr[5];
                loopPtr[4] = loopPtr[6];
                loopPtr[5] = loopPtr[7];
                loopPtr[6] = loopPtr[id8];
                loopPtr[7] = loopPtr[id9];

                loopPtr += id8;
            }

            loopPtr[0] = loopPtr[2];
            loopPtr[1] = loopPtr[3];
            loopPtr[2] = loopPtr[4];
            loopPtr[3] = loopPtr[5];
            loopPtr[4] = loopPtr[6];
            loopPtr[5] = loopPtr[7];
            loopPtr[6] = 0;
            loopPtr[7] = 0;
            dstPtr += 8;
        }

        txtStructPtr->unk30 = txtStructPtr->unk28;
        txtStructPtr->unk34 = txtStructPtr->unk1C;
        txtStructPtr->unk38 = txtStructPtr->unk2C;
        txtStructPtr->unk44 = 1;
    }
}

IWRAM_INIT void sub_8272870(s32 id)
{
    sub_8272884(gUnknown_2027370, id);
}

IWRAM_INIT static void sub_8272884(UnkTextStruct1 *txtStructs, s32 id)
{
    UnkTextStruct1 *txtStructPtr = &txtStructs[id];

    if (txtStructPtr->unk8 > 0) {
        s32 i, j;
        u32 *dstPtr;
        s32 n;
        s32 id8;
        s32 unk4, unk8, dstAdd;

        if (txtStructPtr->unkC == 6) {
            n = txtStructPtr->unk8 - 2;
        }
        else {
            n = txtStructPtr->unk8;
        }

        unk8 = txtStructPtr->unk8 - 1;
        unk4 =txtStructPtr->unk4;
        dstAdd = (unk8 * unk4) * 8;
        dstPtr = txtStructPtr->unk18 + dstAdd;

        id8 = txtStructPtr->unk20 + 8;
        for (i = 0; i < txtStructPtr->unk4; i++) {
            u32 lastTwo = 0;
            s32 to = n - 1;
            u32 *loopPtr = dstPtr;

            if (n < 2) {
                loopPtr[7] = loopPtr[5];
                loopPtr[6] = loopPtr[4];
                loopPtr[5] = loopPtr[3];
                loopPtr[4] = loopPtr[2];
                loopPtr[3] = loopPtr[1];
                loopPtr[2] = loopPtr[0];
                loopPtr[1] = lastTwo;
                loopPtr[0] = lastTwo;
            }
            else {
                u32 *ptr8 = dstPtr - id8;
                for (j = 0; j < to; j++) {
                    loopPtr[7] = loopPtr[5];
                    loopPtr[6] = loopPtr[4];
                    loopPtr[5] = loopPtr[3];
                    loopPtr[4] = loopPtr[2];
                    loopPtr[3] = loopPtr[1];
                    loopPtr[2] = loopPtr[0];
                    loopPtr[1] = ptr8[7];
                    loopPtr[0] = ptr8[6];

                    loopPtr -= id8;
                    ptr8 -= id8;
                }

                loopPtr[7] = loopPtr[5];
                loopPtr[6] = loopPtr[4];
                loopPtr[5] = loopPtr[3];
                loopPtr[4] = loopPtr[2];
                loopPtr[3] = loopPtr[1];
                loopPtr[2] = loopPtr[0];
                loopPtr[1] = 0;
                loopPtr[0] = 0;
            }
            dstPtr += 8;
        }

        txtStructPtr->unk30 = txtStructPtr->unk28;
        txtStructPtr->unk34 = txtStructPtr->unk1C;
        txtStructPtr->unk38 = txtStructPtr->unk2C;
        txtStructPtr->unk44 = 1;
    }
}

IWRAM_INIT void sub_82729A4(s32 id)
{
    sub_82729B8(gUnknown_2027370, id);
}

IWRAM_INIT static void sub_82729B8(UnkTextStruct1 *txtStructs, s32 id)
{
    s32 i, j;
    UnkTextStruct1 *txtStructPtr = &txtStructs[id];
    u32 *dstPtr = txtStructPtr->unk18;
    s32 id8 = txtStructPtr->unk20 + 8;
    s32 id9 = txtStructPtr->unk20 + 9;

    for (i = 0; i < txtStructPtr->unk4; i++) {
        u32 *loopPtr;

        dstPtr[3] = dstPtr[5];
        dstPtr[4] = dstPtr[6];
        dstPtr[5] = dstPtr[7];
        dstPtr[6] = dstPtr[id8];
        dstPtr[7] = dstPtr[id9];

        loopPtr = dstPtr + id8;
        for (j = 0; j < 5; j++) {
            loopPtr[0] = loopPtr[2];
            loopPtr[1] = loopPtr[3];
            loopPtr[2] = loopPtr[4];
            loopPtr[3] = loopPtr[5];
            loopPtr[4] = loopPtr[6];
            loopPtr[5] = loopPtr[7];
            loopPtr[6] = loopPtr[id8];
            loopPtr[7] = loopPtr[id9];

            loopPtr += id8;
        }

        loopPtr[0] = loopPtr[2];
        loopPtr[1] = loopPtr[3];
        loopPtr[2] = loopPtr[4];
        loopPtr[3] = loopPtr[5];
        loopPtr[4] = 0;
        loopPtr[5] = 0;
        loopPtr[6] = 0;
        loopPtr[7] = 0;

        dstPtr += 8;
    }

    txtStructPtr->unk30 = txtStructPtr->unk28;
    txtStructPtr->unk34 = txtStructPtr->unk1C;
    txtStructPtr->unk38 = txtStructPtr->unk2C;
    txtStructPtr->unk44 = 1;
}

IWRAM_INIT void sub_8272A78(s32 id)
{
    sub_8272A8C(gUnknown_2027370, id);
}

IWRAM_INIT static void sub_8272A8C(UnkTextStruct1 *txtStructs, s32 id)
{
    s32 i, j;
    UnkTextStruct1 *txtStructPtr = &txtStructs[id];
    u32 *dstPtr = txtStructPtr->unk18;
    s32 id8 = txtStructPtr->unk20 + 8;

    for (i = 0; i < txtStructPtr->unk4; i++) {
        u32 *loopPtr;

        dstPtr[3] = 0;
        dstPtr[4] = dstPtr[5];
        dstPtr[5] = dstPtr[6];
        dstPtr[6] = dstPtr[7];
        dstPtr[7] = dstPtr[id8];

        loopPtr = dstPtr + id8;
        for (j = 0; j < 5; j++) {
            loopPtr[0] = loopPtr[1];
            loopPtr[1] = loopPtr[2];
            loopPtr[2] = loopPtr[3];
            loopPtr[3] = loopPtr[4];
            loopPtr[4] = loopPtr[5];
            loopPtr[5] = loopPtr[6];
            loopPtr[6] = loopPtr[7];
            loopPtr[7] = loopPtr[id8];

            loopPtr += id8;
        }

        loopPtr[0] = loopPtr[1];
        loopPtr[1] = loopPtr[2];
        loopPtr[2] = loopPtr[3];
        loopPtr[3] = loopPtr[4];
        loopPtr[4] = loopPtr[5];
        loopPtr[5] = loopPtr[6];
        loopPtr[6] = loopPtr[7];
        loopPtr[7] = 0;

        dstPtr += 8;
    }

    txtStructPtr->unk30 = txtStructPtr->unk28;
    txtStructPtr->unk34 = txtStructPtr->unk1C;
    txtStructPtr->unk38 = txtStructPtr->unk2C;
    txtStructPtr->unk44 = 1;
}

// Needed to match, because without it the alignment is different.
IWRAM_INIT static UNUSED u8 sMatchAlignment = 0;
