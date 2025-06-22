#include "global.h"
#include "globaldata.h"
#include "dungeon_name_banner.h"
#include "constants/dungeon.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"
#include "bg_palette_buffer.h"
#include "code_800D090.h"
#include "dungeon_vram.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "file_system.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_1.h"
#include "text_3.h"

extern bool8 sub_80848EC(void);
extern const u8 *GetDungeonName2(u8 dungeon);

EWRAM_DATA OpenedFile *gDungeonNameBannerPalette = NULL;
static EWRAM_DATA OpenedFile *gDungeonNameBannerFontFile = NULL;
static EWRAM_DATA s32 gDungeonNameBannerFont = 0;

// Very similar to unkChar struct
typedef struct UnkStruct_sub_803DC6C
{
    u8 *unk0;
    u16 unk4;
    u8 unk6;
} UnkStruct_sub_803DC6C;

static s32 DisplayStringOnScreen(const u8 *dungName, s32 x, s32 y);
static s32 CalcStringWidth(const u8 *dungName);
static s32 DisplayCharOnScreen(u32 chr, s32 x, s32 y);
static UnkStruct_sub_803DC6C *sub_803DEC8(s32 chr);
static void sub_803DD30(u8 *a0, u32 *a1);

struct DungeonNameFontFileData
{
    /* 0x0 */ u8 unk0;
    /* 0x4 */ s32 font;
};

struct DungeonNamePaletteFileData
{
    RGB pal[16];
};

void ShowDungeonNameBanner_Async(void)
{
    u8 text[100];
    s32 y;
    s32 i, r7;
    const u8 *stairsStr;

    gDungeonNameBannerPalette = OpenFileAndGetFileDataPtr("banrpal", &gDungeonFileArchive);
    gDungeonNameBannerFontFile = OpenFileAndGetFileDataPtr("banfont", &gDungeonFileArchive);
    gDungeonNameBannerFont =  ((struct DungeonNameFontFileData *)(gDungeonNameBannerFontFile->data))->font;
    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(i + 224, &((struct DungeonNamePaletteFileData *)(gDungeonNameBannerPalette->data))->pal[i]);
    }
    CpuClear((void *)(VRAM + 0x140), 0x1C00);
    if (sub_80848EC()) {
        s32 currFloor = gDungeon->unk644.dungeonLocation.floor + gDungeon->startFloorId;
        const u8 *dungName = GetDungeonName2(gDungeon->unk644.dungeonLocation.id);
        s32 r5 = 10;

        for (r7 = 0; r7 < 8; r7++) {
            for (i = 0; i < 28; r5++) {
                u16 a2;

                i++;
                a2 = r5 | 0xE000;
                sub_8008DC8(i, r7 + 4, r5 | a2, 0);
            }
        }

        y = DisplayStringOnScreen(dungName, (224 - CalcStringWidth(dungName)) / 2, 0);
        if (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id))
            stairsStr = "#";
        else
            stairsStr = "B";

        if (currFloor > 9) {
            sprintfStatic(text, "%s%c%cF", stairsStr, '0' + (currFloor / 10), '0' + (currFloor % 10));
        }
        else {
            sprintfStatic(text, "%s%cF", stairsStr, '0' + currFloor);
        }

        DisplayStringOnScreen(text, (224 - CalcStringWidth(text)) / 2, y + 32);
        gUnknown_20274A5 = TRUE;
    }

    CloseFile(gDungeonNameBannerFontFile);
    DungeonRunFrameActions(2);
}

static s32 DisplayStringOnScreen(const u8 *dungName, s32 x, s32 y)
{
    while (*dungName != '\0') {
        u32 currChar = *(dungName++);
        if (currChar == '/') {
            x = 0;
            y += 24;
        }
        else if (currChar == '#') {
            x += 8;
        }
        else if (currChar == ' ') {
            x += 12;
        }
        else {
            if (currChar & 0x80 && *dungName != '\0') {
                currChar = (currChar << 8) | *dungName;
                dungName++;
            }
            x += DisplayCharOnScreen(currChar, x, y);
        }
    }
    return y;
}

// Same as gCharMasksOffsets
static const struct unkShiftData sDungNameBannerMasks[] = {
    [0] = {.bytesA = 0xFFFFFFFF, .bytesB = 0x00000000, .shift_left = 0x00, .shift_right = 0x20},
    [1] = {.bytesA = 0x0FFFFFFF, .bytesB = 0xF0000000, .shift_left = 0x04, .shift_right = 0x1C},
    [2] = {.bytesA = 0x00FFFFFF, .bytesB = 0xFF000000, .shift_left = 0x08, .shift_right = 0x18},
    [3] = {.bytesA = 0x000FFFFF, .bytesB = 0xFFF00000, .shift_left = 0x0C, .shift_right = 0x14},
    [4] = {.bytesA = 0x0000FFFF, .bytesB = 0xFFFF0000, .shift_left = 0x10, .shift_right = 0x10},
    [5] = {.bytesA = 0x00000FFF, .bytesB = 0xFFFFF000, .shift_left = 0x14, .shift_right = 0x0C},
    [6] = {.bytesA = 0x000000FF, .bytesB = 0xFFFFFF00, .shift_left = 0x18, .shift_right = 0x08},
    [7] = {.bytesA = 0x0000000F, .bytesB = 0xFFFFFFF0, .shift_left = 0x1C, .shift_right = 0x04},
};

static s32 DisplayCharOnScreen(u32 chr, s32 x, s32 y)
{
    s32 r9;
    u32 *spPtr;
    u32 *vramPtr;
    s32 i, j;
    const struct unkShiftData *constData;
    u32 sp[72];
    struct UnkStruct_sub_803DC6C *strPtr = sub_803DEC8(chr);

    sub_803DD30(strPtr->unk0, sp);
    r9 = strPtr->unk6;
    spPtr = sp;

    vramPtr = (void *)(VRAM) + ((((y / 8) * 28) + x / 8) + 10) * 32;
    vramPtr += y % 8;
    constData = &sDungNameBannerMasks[x % 8];
    for (i = 0; i < 24; i++) {
        u32 *vramPtrLoop = vramPtr;
        for (j = 0; j < 3; j++) {
            #ifdef NONMATCHING
            u32 spVal = *spPtr;
            #else
            register u32 spVal asm("r2") = *spPtr;
            #endif
            if (spVal != 0) {
                *vramPtrLoop |= (spVal & constData->bytesA) << constData->shift_left;
                vramPtrLoop += 8;

                spVal &= constData->bytesB;
                spVal >>= constData->shift_right;
                *vramPtrLoop |= spVal;
                vramPtrLoop -= 8;
            }
            spPtr++;
            vramPtrLoop += 8;
        }

        vramPtr++;
        y++;

        if ((y % 8) == 0) {
            vramPtr += 216;
        }
    }

    return r9;
}

static void sub_803DD30(u8 *a0, u32 *a1)
{
    u8 sp[576];
    u8 sp575[576];
    s32 spId = 0;
    s32 i, j = 0, k;
    u32 currSp;
    s32 r6;

    for (i = 0; i < 576; i += 2) {
        sp[i] = (*a0 >> 4) & 0xF;
        sp[i+1] = *a0 & 0xF;
        a0++;
    }

    while (j < 576) {
        currSp = sp[spId++];
        r6 = currSp & 7;
        if (currSp & 8) {
            currSp = sp[spId++];
            for (k = 0; k < r6; k++) {
                sp575[j] = currSp;
                if (++j >= 576)
                    break;
            }
        }
        else {
            for (k = 0; k < r6; k++) {
                currSp = sp[spId++];
                sp575[j] = currSp;
                if (++j >= 576)
                    break;
            }
        }
        if (j >= 576)
            break;
    }

    for (i = 0; i < 576; i += 8) {
        u32 val = sp575[i + 7] << 0x1C;
        val |= (sp575[i + 6] << 0x18) & 0xF000000;
        val |= (sp575[i + 5] << 0x14) & 0xF00000;
        val |= (sp575[i + 4] << 0x10) & 0xF0000;
        val |= (sp575[i + 3] << 0xC) & 0xF000;
        val |= (sp575[i + 2] << 0x8) & 0xF00;
        val |= (sp575[i + 1] << 0x4) & 0xF0;
        val |= (sp575[i]) & 0xF;
        *(a1++) = val;
    }
}

// Could be a misnomer?
static s32 CalcStringWidth(const u8 *dungName)
{
    s32 w = 0;

    while (*dungName != '\0') {
        u32 currChar = *(dungName++);
        if (currChar == '#') {
            w += 8;
        }
        else if (currChar == ' ') {
            w += 12;
        }
        else {
            struct UnkStruct_sub_803DC6C *strPtr;

            if (currChar & 0x80 && *dungName != '\0') {
                currChar = (currChar << 8) | *dungName;
                dungName++;
            }
            strPtr = sub_803DEC8(currChar);
            if (strPtr != NULL) {
                w += strPtr->unk6;
            }
        }
    }

    return w;
}

static UnkStruct_sub_803DC6C *sub_803DEC8(s32 chr)
{
    s32 r2, r4;
    UnkStruct_sub_803DC6C *ret;
    UnkStruct_sub_803DC6C *strPtr = *((UnkStruct_sub_803DC6C **) gDungeonNameBannerFontFile->data);
    // Fakematch? Or just magic numbers which will make more sense once this file is documented?
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
        r2 = gDungeonNameBannerFont - 1;
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
            ret = &strPtr[1];

    }
    return ret;
};
