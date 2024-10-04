#include "global.h"
#include "dungeon.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"

extern s32 gUnknown_202EDC8;

struct DungeonPalFile
{
    void *unk0;
    const void *unk4;
};

extern struct DungeonPalFile *gDungeonPaletteFile;
extern struct DungeonPalFile *gDungeonNameBannerPalette;
extern u8 gUnknown_202ECA4[];
extern u8 gUnknown_202D058[];

extern const u8 gUnknown_80F62AC[];

void sub_803E874(bool8 r10, s32 r9)
{
    s32 i, index, count;
    const u8 *colorArray;

    colorArray = gDungeonPaletteFile->unk4;
    SetBGPaletteBufferColorRGB(0, gUnknown_80F62AC, gUnknown_202EDC8, (void *) &gDungeon->unk17C);
    colorArray += 4;
    index = 1;
    count = 159;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, colorArray, gUnknown_202EDC8, (void *) &gDungeon->unk17C);
        colorArray += 4;
        index++;
    }

    if (gDungeon->unk181e8.unk18215 == 0 || gDungeon->unk1C06C == 3) {
        sub_8004AF0(TRUE, gUnknown_202EE8C, 0xA0, 0x20, gUnknown_202EDC8, (void *) &gDungeon->unk17C);
    }

    index += 32;
    colorArray = gUnknown_202ECA4;
    count = 32;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, colorArray, gUnknown_202EDC8, (void *) &gDungeon->unk17C);
        colorArray += 4;
        index++;
    }

    if (r10) {
        index = 224;
        colorArray = gDungeonNameBannerPalette->unk4;
        count = 16;
        for (i = 0; i < count; i++) {
            SetBGPaletteBufferColorRGB(index, colorArray, r9, NULL);
            colorArray += 4;
            index++;
        }
    }

    SetBGPaletteBufferColorRGB(248, gUnknown_202D058, gUnknown_202EDC8, NULL);

    colorArray = ((struct DungeonPalFile*) gDungeon->paletFile)->unk4;
    index = 256;
    count = 208;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, colorArray, gUnknown_202EDC8, (void *) &gDungeon->unk17C);
        nullsub_4(index, colorArray, gUnknown_202EDC8, NULL);
        colorArray += 4;
        index++;
    }
}

void sub_803E9D0(void)
{
    s32 i, index, count;
    const u8 *colorArray;

    colorArray = ((struct DungeonPalFile*) gDungeon->paletFile)->unk4;
    index = 256;
    count = 208;
    for (i = 0; i < count; i++) {
        nullsub_4(index, colorArray, gUnknown_202EDC8, NULL);
        colorArray += 4;
        index++;
    }
}
