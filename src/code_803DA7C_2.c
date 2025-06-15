#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "bg_palette_buffer.h"
#include "graphics_memory.h"
#include "code_803D110.h"
#include "dungeon_vram.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "dungeon_random.h"
#include "file_system.h"
#include "game_options.h"
#include "text_1.h"
#include "text_3.h"
#include "dungeon_config.h"
#include "run_dungeon.h"

EWRAM_DATA OpenedFile *gUnknown_202EC94 = NULL;
EWRAM_DATA OpenedFile *gUnknown_202EC98 = NULL;
EWRAM_DATA OpenedFile *gUnknown_202EC9C = NULL;
EWRAM_DATA OpenedFile *gUnknown_202ECA0 = NULL;
EWRAM_DATA RGB gUnknown_202ECA4[33] = {0};

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
