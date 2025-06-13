#include "global.h"
#include "globaldata.h"
#include "structs/str_text.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "graphics_memory.h"
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
    .width = 7,
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

static void AddWindow(Window *windows, u32 *vram, u32 *, u16 tilemaps[4][32][32], u32 windowId, const WindowTemplate *winTemplate, bool8, s32 firstBlockId, DungeonPos *positionModifier, u8);
static void ShowWindowsInternal(const WindowTemplates *winTemplates, bool8, bool8, DungeonPos *positionModifier);
static void PutWindowTopBorderTilemap(Window *window, s32 y, u16 tilemaps[4][32][32], u8 a3);
static void PutWindowLeftBorderTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32]);
static void PutWindowFillTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32]);
static void PutWindowRightBorderTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32]);
static void PutWindowBottomBorderTilemap(Window *window, s32, u16 tilemaps[4][32][32], u8);
static void PutHeaderWindowTopBorderTilemap(Window *window, s32 y, u32 a2, const WindowHeader *winHeader, u16 tilemaps[4][32][32]);

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
            AddWindow(gWindows, (u32 *)VRAM, sUnknown_20274B4, gBgTilemaps, sUnknown_80B8804[i], &winTemplates->id[i], a1, area, positionModifier, 0);
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
static void AddWindow(Window *windows, u32 *vram, u32 *a2, u16 tilemaps[4][32][32], u32 windowId, const WindowTemplate *winTemplate, bool8 a6, s32 firstBlockId, DungeonPos *positionModifier, u8 a9)
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
        s32 workingY = y - 1;
        s32 i, j;

        if (newWindow->type == WINDOW_TYPE_WITH_HEADER) {
            uVar1 = a6 ? newWindow->unk14 : 0;

            PutHeaderWindowTopBorderTilemap(newWindow, workingY, uVar1, winTemplate->header, tilemaps);

            workingY = y + 2;
            uVar1 = a6 ? newWindow->unk14 + newWindow->width * (winTemplate->unk12 + 2) : 0;
            numI = newWindow->height - 2;
        }
        else {
            PutWindowTopBorderTilemap(newWindow, workingY, tilemaps, a9);

            workingY = y;
            uVar1 = a6 ? newWindow->unk14 : 0;
            numI = newWindow->height;
        }

        for (i = 0; i < numI; i++) {
            s32 workingX = x - 1;
            PutWindowLeftBorderTilemap(newWindow, workingX, workingY, i, tilemaps);
            workingX = x;

            for (j = 0; j < newWindow->width; j++) {
                PutWindowFillTilemap(newWindow, workingX, workingY, uVar1, tilemaps);

                workingX++;
                if (a6)
                    uVar1++;
            }

            PutWindowRightBorderTilemap(newWindow, workingX, workingY, i, tilemaps);
            workingY++;
        }
        PutWindowBottomBorderTilemap(newWindow, workingY, tilemaps, a9);
    }

    if ((winTemplate->unk0 & 0x80) == 0)
        PrepareTextbox_8008C6C(windows, windowId);

    newWindow->unk46 = 0;
}

// arm9.bin::02004B0C
static void PutWindowTopBorderTilemap(Window *window, s32 y, u16 tilemaps[4][32][32], u8 a3)
{
    s32 x;
    s32 i;

    x = window->x - 1;

    if (y > 28)
        return;
    if (y < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
        case WINDOW_TYPE_WITH_HEADER:
            break;
        case WINDOW_TYPE_NORMAL:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15);
            if (a3 != 0)
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15);
            else
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            if (a3 != 0)
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            else
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_4:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E8) | TILEMAP_PAL(15);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E9) | TILEMAP_PAL(15);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E8) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DC) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DD) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DC) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
        case WINDOW_TYPE_7:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
    }
}

// arm9.bin::020049D0
static void PutWindowLeftBorderTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32])
{
    if (y > 28)
        return;
    if (y < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_0:
            if (a3 == 0) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                break;
            }
            if (a3 == window->height - 1) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                break;
            }
            // Fallthrough
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DA) | TILEMAP_PAL(15);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_4:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2EA) | TILEMAP_PAL(15);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DE) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_7:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2B6) | TILEMAP_PAL(15);
            break;
    }
}

// arm9.bin::020048F0
static void PutWindowFillTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32])
{
    if (y > 28)
        return;
    if (y < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_2:
            tilemaps[0][y][x] = a3 | TILEMAP_PAL(15);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_4:
        case WINDOW_TYPE_WITH_HEADER:
            tilemaps[0][y][x] = a3 | TILEMAP_PAL(15);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
        case WINDOW_TYPE_7:
            tilemaps[0][y][x] = a3 | TILEMAP_PAL(15);
            break;
    }
}

// arm9.bin::020047B4
static void PutWindowRightBorderTilemap(Window *window, s32 x, s32 y, s32 a3, u16 tilemaps[4][32][32])
{
    if (y > 28)
        return;
    if (y < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_0:
            if (a3 == 0) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                break;
            }
            if (a3 == window->height - 1) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1) | TILEMAP_FLIP_VERTICAL(1);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                break;
            }
            // Fallthrough
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DA) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_4:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2EA) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DE) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
        case WINDOW_TYPE_7:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2B6) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
    }
}

// arm9.bin::0200456C
static void PutWindowBottomBorderTilemap(Window *window, s32 y, u16 tilemaps[4][32][32], u8 a3)
{
    s32 x;
    s32 i;

    x = window->x - 1;

    if (y > 28)
        return;
    if (y < 0)
        return;

    switch (window->type) {
        case WINDOW_TYPE_0:
        case WINDOW_TYPE_WITHOUT_BORDER:
        case WINDOW_TYPE_2:
            break;
        case WINDOW_TYPE_NORMAL:
        case WINDOW_TYPE_WITH_HEADER:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
            if (a3 != 0)
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
            else
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1) | TILEMAP_FLIP_HORIZONTAL(1);
            if (a3 != 0)
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1) | TILEMAP_FLIP_HORIZONTAL(1);
            else
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_4:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E8) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E9) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
                tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2E8) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            break;
        case WINDOW_TYPE_FILL_TRANSPARENT:
            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DC) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DD) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x2DC) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
        case WINDOW_TYPE_7:
           tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
            x++;
            for (i = 0; i < window->width; i++) {
                tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x297) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1);
                x++;
            }

            tilemaps[0][y][x] = TILEMAP_TILE_NUM(0x293) | TILEMAP_PAL(15) | TILEMAP_FLIP_VERTICAL(1) | TILEMAP_FLIP_HORIZONTAL(1);
            break;
    }
}

// arm9.bin::02004054
static void PutHeaderWindowTopBorderTilemap(Window *window, s32 y, u32 a2, const WindowHeader *winHeader, u16 tilemaps[4][32][32])
{
     // a2: color or tile type of some sort?
    bool8 currHeaderDone;
    s32 x;
    s32 iVar3;
    s32 i, j;

    x = window->x - 1;
    currHeaderDone = FALSE;

    if (y > 28)
        return;
    if (y < 0)
        return;

    tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
    tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
    tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15);
    tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
    x++;

    for (i = 0; i < winHeader->count; i++) {
        if (i != winHeader->currId) {
            s32 tilemapNum;
            if (!currHeaderDone) {
                if ((winHeader->f3 >> (i) & 1)) {
                    tilemapNum = i == 0 ? 27 : 31;

                    tilemaps[0][y  ][x] = (tilemapNum + 0x278) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2B6) | TILEMAP_PAL(15);
                    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
                }
                else {
                    tilemapNum = i == 0 ? 103 : 107;

                    tilemaps[0][y  ][x] = (tilemapNum + 0x278) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2EF) | TILEMAP_PAL(15);
                    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
                }
                tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
                tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            }
            else {
                if ((winHeader->f3 >> (i) & 1)) {
                    tilemapNum = i == winHeader->count - 1 ? 27 : 31;

                    tilemaps[0][y  ][x] = (tilemapNum + 0x278) | TILEMAP_PAL(15);
                    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2B6) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
                }
                else {
                    tilemapNum = i == winHeader->count - 1 ? 103 : 107;

                    tilemaps[0][y  ][x] = (tilemapNum + 0x278) | TILEMAP_PAL(15);
                    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2EF) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
                }
                tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
                tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
                tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            }
            x++;
            if (a2) a2++;
        }
        else {
            currHeaderDone = TRUE;

            tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x2E0) | TILEMAP_PAL(15);
            tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x2E2) | TILEMAP_PAL(15);
            tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2DA) | TILEMAP_PAL(15);
            tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2E7) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;

            if (a2) a2++;

            if (a2)
                iVar3 = a2 + window->width;
            else
                iVar3 = 0;

            for (j = 0; j < winHeader->width; j++) {
                u32 bits;

                tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x2E1) | TILEMAP_PAL(15);
                tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x2E2) | TILEMAP_PAL(15);
                bits = ~(TILEMAP_TILE_NUM(0x3FF) | TILEMAP_FLIP_HORIZONTAL(1) | TILEMAP_FLIP_VERTICAL(1)); // Clear all bits except pal
                tilemaps[0][y+1][x] = bits | a2;
                tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                tilemaps[0][y+2][x] = bits | iVar3;
                tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
                x++;

                if (a2 != 0)
                    a2++;

                if (iVar3 != 0)
                    iVar3++;
            }

            tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x2E0) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x2E2) | TILEMAP_PAL(15);
            tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x2DA) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
            tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2E7) | TILEMAP_PAL(15);
            tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
            x++;

            if (a2) a2++;
        }
    }

    while (x < window->x + window->width) {
        tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
        tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
        tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
        tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
        tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D9) | TILEMAP_PAL(15);
        tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
        x++;

        if (a2) a2++;
    }

    tilemaps[0][y  ][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
    tilemaps[1][y  ][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
    tilemaps[0][y+1][x] = TILEMAP_TILE_NUM(0x278) | TILEMAP_PAL(15);
    tilemaps[1][y+1][x] = TILEMAP_TILE_NUM(0x27A) | TILEMAP_PAL(15);
    tilemaps[0][y+2][x] = TILEMAP_TILE_NUM(0x2D8) | TILEMAP_PAL(15) | TILEMAP_FLIP_HORIZONTAL(1);
    tilemaps[1][y+2][x] = TILEMAP_TILE_NUM(0x2DB) | TILEMAP_PAL(15);
    x++;
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
