#include "global.h"
#include "constants/dungeon.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"
#include "bg_palette_buffer.h"
#include "code_8009804.h"
#include "code_800D090.h"
#include "code_803D110.h"
#include "dungeon_vram.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "dungeon.h"
#include "dungeon_random.h"
#include "file_system.h"
#include "game_options.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_1.h"
#include "text_3.h"
#include "dungeon_config.h"

// File split could be wrong here. Todo.

extern bool8 sub_80848EC(void);
extern u8 GetFloorType(void);
extern const u8 *GetDungeonName2(u8 dungeon);

extern const char gUnknown_80F60F8[]; // "banrpal"
extern const char gUnknown_80F6100[]; // "banfont"
extern const char gUnknown_80F6108[];
extern const char gUnknown_80F610C[];
extern const char gUnknown_80F6110[];
extern const char gUnknown_80F6118[];
extern const u32 gUnknown_80F6120[];

EWRAM_DATA OpenedFile *gDungeonNameBannerPalette = NULL;
EWRAM_DATA OpenedFile *gDungeonNameBannerFontFile = NULL;
EWRAM_DATA s32 gDungeonNameBannerFont = 0;
EWRAM_DATA OpenedFile *gUnknown_202EC94 = NULL;
EWRAM_DATA OpenedFile *gUnknown_202EC98 = NULL;
EWRAM_DATA OpenedFile *gUnknown_202EC9C = NULL;
EWRAM_DATA OpenedFile *gUnknown_202ECA0 = NULL;

// Very similar to unkChar struct
typedef struct UnkStruct_sub_803DC6C
{
    u8 *unk0;
    u16 unk4;
    u8 unk6;
} UnkStruct_sub_803DC6C;

struct FileStruct2
{
    s32 count;
    u8 array[0];
};

struct FileStruct
{
    struct FileStruct2 *ptr;
    struct u8 *ptr2;
};

s32 sub_803DC14(const u8 *dungName, s32 strWidth, s32 a2);
s32 CalcStringWidth(const u8 *dungName);
s32 sub_803DC6C(u32 chr, s32 strWidth, s32 a2);
static UnkStruct_sub_803DC6C *sub_803DEC8(s32 chr);
void sub_803DD30(u8 *a0, u32 *a1);

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
    s32 var;
    s32 i, r7;
    const u8 *r6;

    gDungeonNameBannerPalette = OpenFileAndGetFileDataPtr(gUnknown_80F60F8, &gDungeonFileArchive);
    gDungeonNameBannerFontFile = OpenFileAndGetFileDataPtr(gUnknown_80F6100, &gDungeonFileArchive);
    gDungeonNameBannerFont =  ((struct DungeonNameFontFileData *)(gDungeonNameBannerFontFile->data))->font;
    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(i + 224, &((struct DungeonNamePaletteFileData *)(gDungeonNameBannerPalette->data))->pal[i]);
    }
    CpuClear((void *)(VRAM + 0x140), 0x1C00);
    if (sub_80848EC()) {
        s32 r8 = gDungeon->unk644.dungeonLocation.floor + gDungeon->unk14;
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

        var = sub_803DC14(dungName, (224 - CalcStringWidth(dungName)) / 2, 0);
        if (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id))
            r6 = gUnknown_80F6108;
        else
            r6 = gUnknown_80F610C;

        if (r8 > 9) {
            sprintfStatic(text, gUnknown_80F6110, r6, 48 + (r8 / 10), 48 + (r8 % 10));
        }
        else {
            sprintfStatic(text, gUnknown_80F6118, r6, 48 + r8);
        }

        sub_803DC14(text, (224 - CalcStringWidth(text)) / 2, var + 32);
        gUnknown_20274A5 = TRUE;
    }

    CloseFile(gDungeonNameBannerFontFile);
    DungeonRunFrameActions(2);
}

s32 sub_803DC14(const u8 *dungName, s32 strWidth, s32 a2)
{
    while (*dungName != '\0') {
        u32 currChar = *(dungName++);
        if (currChar == '/') {
            strWidth = 0;
            a2 += 24;
        }
        else if (currChar == '#') {
            strWidth += 8;
        }
        else if (currChar == ' ') {
            strWidth += 12;
        }
        else {
            if (currChar & 0x80 && *dungName != '\0') {
                currChar = (currChar << 8) | *dungName;
                dungName++;
            }
            strWidth += sub_803DC6C(currChar, strWidth, a2);
        }
    }
    return a2;
}

s32 sub_803DC6C(u32 chr, s32 strWidth, s32 a2)
{
    u32 *spPtr;
    s32 i, j, a2DivMul;
    u32 *vramPtr;
    const u32 *constData;
    u32 sp[72];
    s32 r9;
    UnkStruct_sub_803DC6C *strPtr = sub_803DEC8(chr);

    sub_803DD30(strPtr->unk0, sp);
    r9 = strPtr->unk6;
    spPtr = sp;

    a2DivMul = ((a2 / 8) * 8);
    vramPtr = (void *)(VRAM + 0x140 + (((a2DivMul - a2 / 8) * 4) + (strWidth / 8)) * 32); // Pixels?
    vramPtr += a2 - a2DivMul;
    constData = &gUnknown_80F6120[(strWidth - ((strWidth / 8) * 8)) * 4];
    for (i = 0; i < 24; i++) {
        u32 *vramPtrLoop = vramPtr;
        for (j = 0; j < 3; j++) {
            // Sadly cannot match it without asm :/
            #ifdef NONMATCHING
            u32 spVal = *spPtr;
            #else
            register u32 spVal asm("r2") = *spPtr;
            #endif // NONMATCHING

            if (spVal != 0) {
                *vramPtrLoop |= ((constData[0] & spVal) << constData[2]);

                vramPtrLoop += 8;
                spVal &= constData[1];
                spVal >>= constData[3];
                *vramPtrLoop |= spVal;
                vramPtrLoop -= 8;
            }
            spPtr++;
            vramPtrLoop += 8;
        }

        vramPtr++;
        a2++;

        if (!(a2 & 7)) {
            vramPtr += 216;
        }
    }

    return r9;
}

void sub_803DD30(u8 *a0, u32 *a1)
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
s32 CalcStringWidth(const u8 *dungName)
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

EWRAM_DATA RGB gUnknown_202ECA4[33] = {0};

void sub_803DF60(void)
{
    u8 *vram;
    s32 i;
    const void *src;
    OpenedFile *file;

    file = OpenFileAndGetFileDataPtr("itempat", &gDungeonFileArchive);
    src = ((struct FileStruct *)(file->data))->ptr;
    i = ((struct FileStruct2 *)(src))->count;
    src = ((struct FileStruct2 *)(src))->array;
    vram = OBJ_VRAM0 + 0x3400;
    while (i != 0)
    {
        CpuCopy(vram, src, 0x20);
        vram += 0x20;
        src += 0x20;
        i--;
    }
    CloseFile(file);

    file = OpenFileAndGetFileDataPtr("etcfont", &gDungeonFileArchive);
    src = ((struct FileStruct2 *)(file->data));
    i = ((struct FileStruct2 *)(src))->count;
    src = ((struct FileStruct2 *)(src))->array;
    vram = OBJ_VRAM0 + 0x4000;
    while (i != 0)
    {
        CpuCopy(vram, src, 0x20);
        vram += 0x20;
        src += 0x20;
        i--;
    }
    CloseFile(file);

    gUnknown_202EC94 = OpenFileAndGetFileDataPtr("etcfonta", &gDungeonFileArchive);
    gUnknown_202EC98 = OpenFileAndGetFileDataPtr("levfont", &gDungeonFileArchive);
    gUnknown_202EC9C = OpenFileAndGetFileDataPtr("hp5font", &gDungeonFileArchive);
    gUnknown_202ECA0 = OpenFileAndGetFileDataPtr("colvec", &gDungeonFileArchive);
}

void sub_803E02C(void)
{
    u8 *vram;
    s32 i, j, r6;
    const void *src;
    OpenedFile *file;
    u8 fileName[12];

    sub_803E13C();
    strcpy(fileName, "trappat");
    file = OpenFileAndGetFileDataPtr(fileName, &gDungeonFileArchive);

    src = ((struct FileStruct *)(file->data))->ptr;
    i = ((struct FileStruct2 *)(src))->count;
    src = ((struct FileStruct2 *)(src))->array;
    vram = (void *) VRAM + 0xC000;
    while (i != 0)
    {
        CpuCopy(vram, src, 0x20);
        vram += 0x20;
        src += 0x20;
        i--;
    }
    CpuCopy(gUnknown_202ECA4, ((struct FileStruct *)(file->data))->ptr2, 0x80);
    CloseFile(file);

    r6 = 0x200;
    for (i = 0; i < UNK12A18_ARR_COUNT; i++) {
        for (j = 0; j < UNK12A18_ARR_COUNT_2; j++) {
            gDungeon->unk12A18[i][j] = (gUnknown_80F5F70[i] << 0xC) | r6;
            r6++;
        }
    }
    for (i = 0; i < 9; i++) {
        gDungeon->unk13554[i] = 0xC000;
    }
    for (i = 0; i < COLOR_RAMP_COUNT; i++) {
        gDungeon->colorRamp[i].r = i;
        gDungeon->colorRamp[i].g = i;
        gDungeon->colorRamp[i].b = i;
    }
}

void sub_803E13C(void)
{
    s32 i;
    RGB *pal;

    SetWindowBGColor();
    if (gGameOptionsRef->playerGender != 0)
        pal = &gFontPalette[16 * 4];
    else
        pal = &gFontPalette[0];

    for (i = 0; i < 16; i++) {
        SetBGPaletteBufferColorArray(240 + i, pal);
        pal++;
    }
}

void sub_803E178(void)
{
    s32 val = GetFloorType();

    if (val == 0) {
        if (gDungeon->unk644.dungeonLocation.id == DUNGEON_METEOR_CAVE && !gDungeon->deoxysDefeat) {
            gDungeon->unk3A12 = 28;
        }
        else {
            gDungeon->unk3A12 = (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id) != FALSE) ? 23 : 22;
        }
    }
    else if (val == 1) {
        gDungeon->unk3A12 = 6;
    }
    else {
        gDungeon->unk3A12 = 24;
    }
}

void sub_803E214(void)
{
    CloseFile(gUnknown_202EC94);
    CloseFile(gUnknown_202EC98);
    CloseFile(gUnknown_202EC9C);
    CloseFile(gUnknown_202ECA0);
}

void nullsub_56(void)
{
}
