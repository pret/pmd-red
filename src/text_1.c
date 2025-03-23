#include "global.h"
#include "globaldata.h"
#include "structs/str_text.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "cpu.h"
#include "decompress_at.h"
#include "def_filearchives.h"
#include "file_system.h"
#include "text_1.h"
#include "text_2.h"
#include "text_3.h"
#include "text_4.h"

EWRAM_DATA Window gWindows[MAX_WINDOWS] = {0}; // NDS=020EDDEC
EWRAM_DATA CharMapStruct *gCharmaps[2] = { NULL };
EWRAM_DATA s16 gCharacterSpacing = 0;
EWRAM_DATA u8 gUnknown_202749A[11] = {0};
EWRAM_DATA bool8 gUnknown_20274A5 = FALSE;
EWRAM_DATA u8 gUnknown_20274A6[6] = {0};
EWRAM_DATA s32 gCurrentCharmap = 0;
EWRAM_DATA static vu32 sUnknown_20274B0 = 0;
EWRAM_DATA static u32 sUnknown_20274B4[0xEC0] = {0};
EWRAM_DATA static OpenedFile *sCharmapFiles[3] = { NULL };
EWRAM_DATA static WindowTemplates sSavedWindows = {0};
EWRAM_DATA s32 gUnknown_202B020 = 0; // NDS=020EDCEC
EWRAM_DATA s32 gUnknown_202B024 = 0; // NDS=020EDCE8
EWRAM_DATA s32 gCharHeight[2] = {0};
EWRAM_DATA u32 gTextShadowMask = 0; // Some text color info is stored; retrieve via "& 0xF"
EWRAM_DATA u8 gDrawTextShadow = 0;
// 4 bgs, 32x32 tiles, y dimension goes before x [bgId][y][x]
EWRAM_DATA ALIGNED(4) u16 gBgTilemaps[4][32][32] = {0};

EWRAM_INIT void (*ScrollDownWindowFunc)(s32 windowId) = ScrollDownWindow;
EWRAM_INIT void (*ScrollUpWindowFunc)(s32 windowId) = ScrollUpWindow;
EWRAM_INIT void (*gIwramTextFunc3)(s32 a0) = sub_82729A4;
EWRAM_INIT void (*gIwramTextFunc4)(s32 a0) = sub_8272A78;

IWRAM_DATA ALIGNED(4) s16 gUnknown_3000E94[161] = {0};

const u32 gUnknown_80B853C[16] =
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

static const WindowTemplates sDummyWindows =
{
    .id = {
        [0] = WIN_TEMPLATE_DUMMY,
        [1] = WIN_TEMPLATE_DUMMY,
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

const unkShiftData gCharMasksOffsets[8] =
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

static const u16 sUnknown_80B865C[] =
{
    0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF,
    0xFFFF, 0xFF, 0xFFFF, 0xFFFF, 0xFF, 0xFFFF, 0xFFFF,
    0xFF, 0, 0, 0, 0, 0, 0
};

// Fallback character with bitmap?
const unkChar gUnknown_80B86A4 =
{
    .unk0 = sUnknown_80B865C,
    .unk4 = 0x81A1,
    .unk6 = 7,
    .unk8 = 10,
    .fill9 = 0,
    .unkA = 0,
    .fillB = 0,
};

// Very weird...
UNUSED static const u8 sByte8 = 8;

const u32 gUnknown_80B86B4[][32] = INCBIN_U32("graphics/warning.4bpp");

static const u8 sKanjiA_file_string[] = "kanji_a";
static const u8 sKanjiB_file_string[] = "kanji_b";

static const u32 sFadeInNone[8] = {0};
static const u32 sFadeInDungeon[8] = {0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888, 0x88888888};

static const u32 sUnknown_80B8804[4] = {0, 1, 2, 3};
static const u32 sUnknown_80B8814[4] = {1, 2, 3, 0};

static void AddWindow(Window *windows, u32 *vram, u32 *, u16 *, u32 windowId, const WindowTemplate *winTemplate, bool8, s32 firstBlockId, DungeonPos *positionModifier, u8);
static void ShowWindowsInternal(const WindowTemplates *winTemplates, bool8, bool8, DungeonPos *positionModifier);
static void sub_800677C(Window *window, s32, u16 *, u8);
static void sub_80069CC(Window *window, s32, s32, s32, u16 *);
static void sub_8006AC4(Window *window, s32, s32, s32, u16 *);
static void sub_8006B70(Window *window, s32, s32, s32, u16 *);
static void sub_8006C44(Window *window, s32, u16 *, u8);
static void sub_8006E94(Window *, s32, u32, const WindowHeader *, u16 *);

// arm9.bin::02005448
void LoadCharmaps(void)
{
    s32 i;
    s32 j;
    s32 k;

    gCurrentCharmap = 0;
    sCharmapFiles[0] = OpenFileAndGetFileDataPtr(sKanjiA_file_string, &gSystemFileArchive);
    sCharmapFiles[1] = OpenFileAndGetFileDataPtr(sKanjiB_file_string, &gSystemFileArchive);
    gCharmaps[0] = (CharMapStruct *) sCharmapFiles[0]->data;
    gCharmaps[1] = (CharMapStruct *) sCharmapFiles[1]->data;
    gCharHeight[0] = 11;
    gCharHeight[1] = 12;

    for (k = 0; k < 4; k++) {
        gWindows[k].width = 0;
        gWindows[k].unk8 = 0;
        gWindows[k].unk46 = 0;
    }

    gCharacterSpacing = 0;

    for (i = 0; i < 20; i++) {
        gBgTilemaps[0][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x279);
        gBgTilemaps[1][i][0] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);

        for (j = 1; j < 32; j++) {
            gBgTilemaps[0][i][j] = 0;
            gBgTilemaps[1][i][j] = TILEMAP_PAL(15) | TILEMAP_TILE_NUM(0x27A);
        }
    }

    gDrawTextShadow = 1;
    gTextShadowMask = 0x88888888;
    gUnknown_203B078 = NULL;
    gUnknown_20274A5 = FALSE;
    gUnknown_202B020 = 1;
    gUnknown_202B024 = 20;
    UpdateFadeInTile(0);
}

// arm9.bin::0200538C
u32 UpdateFadeInTile(u32 a0)
{
    u32 r5 = sUnknown_20274B0;
    u32 *r4 = (u32 *)(VRAM + 0x4F40);
    const u32 *r2;
    sUnknown_20274B0 = a0;

    if (a0 == 0 || a0 == 2) {
        sub_800CDA8(2);
        r2 = sFadeInNone;
    }
    else {
        sub_800CDA8(1);
        r2 = sFadeInDungeon;
    }

    gTextShadowMask = 0x88888888;
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

// arm9.bin::0200537C
u32 sub_80063B0(void)
{
    return sUnknown_20274B0;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static u8 UnusedSetTextShadow(u8 a0)
{
    u8 retval = gDrawTextShadow;
    gDrawTextShadow = a0;
    return retval;
}
#endif

// arm9.bin::0200536C
void SelectCharmap(u32 a0)
{
    gCurrentCharmap = a0;
}

// arm9.bin::02005314
void SetCharacterMask(s32 a0)
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
    gTextShadowMask = retval;
}

// arm9.bin::020052E4
void ShowWindows(const WindowTemplates *winTemplates, bool8 a1, bool8 a2)
{
    DungeonPos positionModifier = {0, 0};
    ShowWindowsInternal(winTemplates, a1, a2, &positionModifier);
}

// red  https://decomp.me/scratch/EN6n0 (includes removed code from pmd-blue)
// blue https://decomp.me/scratch/1y9BG
// arm9.bin::020051B0
static void ShowWindowsInternal(const WindowTemplates *winTemplates, bool8 a1, bool8 a2, DungeonPos *positionModifier)
{
    s32 i;
    s32 area = 2;

    if (winTemplates == NULL)
        winTemplates = &sDummyWindows;
    if (a2)
        sub_8009388();

    ResetWindowBgData();

    for (i = 0; i < MAX_WINDOWS; i++) {
        sSavedWindows.id[i] = winTemplates->id[i];

        if (winTemplates->id[i].width != 0) {
            AddWindow(gWindows, (u32 *)VRAM, sUnknown_20274B4, &gBgTilemaps[0][0][0], sUnknown_80B8804[i], &winTemplates->id[i], a1, area, positionModifier, 0);
            sub_80089AC(&winTemplates->id[i], positionModifier);
            area += winTemplates->id[i].width * winTemplates->id[i].unk10;
        }
    }

    // Needed to account for weird compiler LDRs
    ASM_MATCH_TRICK(gUnknown_203B078);
    ASM_MATCH_TRICK(gUnknown_3000E94[0]);
    ASM_MATCH_TRICK(gUnknown_20274A5);

    gUnknown_203B078 = gUnknown_3000E94;
    gUnknown_20274A5 = TRUE;
}

// arm9.bin::0200508C
UNUSED static void nullsub_152(void)
{
    // Seems to be a 2nd version of the func above, probably for 2nd screen windows.
}

// arm9.bin::02005040
void RestoreSavedWindows(WindowTemplates *dst)
{
    s32 i;

    for (i = 0; i < MAX_WINDOWS; i++)
        dst->id[i] = sSavedWindows.id[i];
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void nullsub_153(void)
{
}
#endif

// arm9.bin::02005030
u32 sub_8006544(u32 index)
{
    return sUnknown_80B8814[index];
}

// arm9.bin::02004D54
static void AddWindow(Window *windows, u32 *vram, u32 *a2, u16 *a3, u32 windowId, const WindowTemplate *winTemplate, bool8 a6, s32 firstBlockId, DungeonPos *positionModifier, u8 a9)
{
    Window *newWindow;
    s32 x, y;
    s32 numI;
    u32 uVar1;

    newWindow = &windows[windowId];
    x = winTemplate->pos.x + positionModifier->x;
    y =  winTemplate->pos.y + positionModifier->y;
    newWindow->x = x;
    newWindow->y = y;
    newWindow->width = winTemplate->width;
    newWindow->unk8 = winTemplate->unk10;
    newWindow->height = winTemplate->height;
    newWindow->type = winTemplate->type;
    newWindow->unk10 = firstBlockId;

    if (newWindow->type == WINDOW_TYPE_WITH_HEADER)
        newWindow->unk14 = firstBlockId;
    else
        newWindow->unk14 = firstBlockId + winTemplate->unk12 * newWindow->width;

    newWindow->unk18 = &a2[newWindow->unk10 * 8];
    newWindow->unk1C = &a2[newWindow->unk14 * 8];
    newWindow->unk24 = winTemplate->unk12;
    newWindow->unk28 = &vram[newWindow->unk14 * 8];

    if (newWindow->type == WINDOW_TYPE_WITH_HEADER)
        newWindow->unk2C = newWindow->width * (newWindow->height + winTemplate->unk12) * 32;
    else
        newWindow->unk2C = newWindow->width * newWindow->height * 32;

    newWindow->unk30 = 0;
    newWindow->unk34 = 0;
    newWindow->unk38 = 0;
    newWindow->unk20 = (newWindow->width * 8) - 8;
    newWindow->unk45 = newWindow->type == WINDOW_TYPE_0;

    if (newWindow->unk8 == 0)
        return;

    if ((winTemplate->unk0 & 0xA0) != 0x80) {
        s32 newY = y - 1;
        s32 i, j;

        if (newWindow->type == WINDOW_TYPE_WITH_HEADER) {
            uVar1 = a6 ? newWindow->unk14 : 0;

            sub_8006E94(newWindow, newY, uVar1, winTemplate->header, a3);

            newY = y + 2;
            uVar1 = a6 ? newWindow->unk14 + newWindow->width * (winTemplate->unk12 + 2) : 0;
            numI = newWindow->height - 2;
        }
        else {
            sub_800677C(newWindow, newY, a3, a9);

            newY = y;
            uVar1 = a6 ? newWindow->unk14 : 0;
            numI = newWindow->height;
        }

        for (i = 0; i < numI; i++) {
            s32 newX = x - 1;
            sub_80069CC(newWindow, newX, newY, i, a3);
            newX = x;

            for (j = 0; j < newWindow->width; j++) {
                sub_8006AC4(newWindow, newX, newY, uVar1, a3);

                newX++;
                if (a6)
                    uVar1++;
            }

            sub_8006B70(newWindow, newX, newY, i, a3);
            newY++;
        }
        sub_8006C44(newWindow, newY, a3, a9);
    }

    if ((winTemplate->unk0 & 0x80) == 0)
        PrepareTextbox_8008C6C(windows, windowId);

    newWindow->unk46 = 0;
}

// arm9.bin::02004B0C
static void sub_800677C(Window *window, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = window->x - 1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
        case WINDOW_TYPE_WITH_HEADER:
            break;
        case WINDOW_TYPE_NORMAL:
            (a2 + a1 * 0x20)[iVar5] = 0xF2D8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF293;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < window->width; i++) {
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
        case WINDOW_TYPE_4:
            (a2 + a1 * 0x20)[iVar5] = 0xF2E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2E9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            (a2 + a1 * 0x20)[iVar5] = 0xF2DC;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2DD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6DC;
            break;
        case WINDOW_TYPE_7:
           (a2 + a1 * 0x20)[iVar5] = 0xF293;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF297;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF693;
            break;
    }
}

// arm9.bin::020049D0
static void sub_80069CC(Window *window, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF297;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == window->height - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFA97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            (a4 + a2 * 0x20)[a1] = 0xF2DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_4:
            (a4 + a2 * 0x20)[a1] = 0xF2EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            (a4 + a2 * 0x20)[a1] = 0xF2DE;
            break;
        case WINDOW_TYPE_7:
            (a4 + a2 * 0x20)[a1] = 0xF2B6;
            break;
    }
}

// arm9.bin::020048F0
static void sub_8006AC4(Window *window, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_2:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF278;
            break;
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_4:
        case WINDOW_TYPE_WITH_HEADER:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
        case WINDOW_TYPE_7:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            break;
    }
}

// arm9.bin::020047B4
static void sub_8006B70(Window *window, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    if (a2 < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF697;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == window->height - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFE97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            (a4 + a2 * 0x20)[a1] = 0xF6DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_4:
            (a4 + a2 * 0x20)[a1] = 0xF6EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            (a4 + a2 * 0x20)[a1] = 0xF6DE;
            break;
        case WINDOW_TYPE_7:
            (a4 + a2 * 0x20)[a1] = 0xF6B6;
            break;
    }
}

// arm9.bin::0200456C
static void sub_8006C44(Window *window, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = window->x - 1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            (a2 + a1 * 0x20)[iVar5] = 0xFAD8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xFA93;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < window->width; i++) {
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
        case WINDOW_TYPE_4:
            (a2 + a1 * 0x20)[iVar5] = 0xFAE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFAE9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            (a2 + a1 * 0x20)[iVar5] = 0xFADC;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFADD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEDC;
            break;
        case WINDOW_TYPE_7:
           (a2 + a1 * 0x20)[iVar5] = 0xFA93;
            iVar5++;
            for (i = 0; i < window->width; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFA97;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFE93;
            break;
    }
}

// Not even close but I don't feel like continuing atm https://decomp.me/scratch/F58jg
// arm9.bin::02004054
/*
static void sub_8006E94(Window *a0, s32 a1, u32 a2, const WindowHeader *a3, u16 *a4)
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
static void sub_8006E94(Window *a0, s32 a1, u32 a2, const WindowHeader *a3, u16 *a4)
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

// arm9.bin::02003FB0
void sub_8007334(s32 windowId)
{
    s32 i, j;
    Window *window = &gWindows[windowId];
    s32 r5 = window->unk14;
    s32 r6 = window->y;
    for (i = 0; i < window->height; i++) {
        s32 id = window->x;
        for (j = 0; j < window->width; j++) {
            gBgTilemaps[0][r6][id] &= ~(TILEMAP_TILE_NUM(0x3FF));
            gBgTilemaps[0][r6][id] |= r5;
            id++;
            r5++;
        }
        r6++;
    }
}

// arm9.bin::02003F0C
UNUSED static void nullsub_154(s32 windowId)
{
    // 2nd version of the func above
}

// arm9.bin::02003ED4
void sub_80073B8(s32 windowId)
{
    Window *window = &gWindows[windowId];

    window->unk3C = &window->unk1C[(u32)window->unk2C >> 2];
    window->unk40 = window->unk1C;
    window->unk46 = 1;
}

// arm9.bin::02003E9C
UNUSED static void nullsub_155(s32 windowId)
{
    // 2nd version of the func above
}

// arm9.bin::02003E08
void sub_80073E0(s32 windowId)
{
    Window *window = &gWindows[windowId];

    if (window->unk44 == 0) {
        window->unk30 = &window->unk28[window->unk3C - window->unk1C];
        window->unk34 = window->unk3C;
        window->unk38 = (window->unk40 - window->unk3C + 1) * 4;

        if (window->unk38 >= window->unk2C)
            window->unk38 = window->unk2C;

        if (window->unk38 < 0)
            window->unk38 = 0;
    }

    window->unk46 = 0;
}

// arm9.bin::02003D74
UNUSED static void nullsub_156(s32 windowId)
{
    // 2nd version of the func above with gSubWindows instead of gMainWindows
}
