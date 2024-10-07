#include "global.h"
#include "dungeon.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text1.h"
#include "code_801602C.h"
#include "menu_input.h"
#include "code_8009804.h"
#include "code_803E46C.h"
#include "dungeon_util.h"
#include "sprite.h"

extern s32 gUnknown_202EDC8;
extern u32 gUnknown_202EDD0;
extern s32 gUnknown_202EDD8;

struct DungeonPalFile
{
    void *unk0;
    const void *unk4;
};

extern struct DungeonPalFile *gDungeonPaletteFile;
extern struct DungeonPalFile *gDungeonNameBannerPalette;
extern struct DungeonPalFile *gUnknown_202EC94;
extern u8 gUnknown_202ECA4[];
extern u8 gUnknown_202D058[];

extern const u8 gUnknown_80F62AC[];

extern void sub_8052210(u32);
extern void sub_8040A84();
extern void sub_8083D44(void);

void sub_803EC94(void);

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

void BgColorCallNullsub4(void)
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

void sub_803EA10(void)
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

    SetBGPaletteBufferColorRGB(248, gUnknown_202D058, gUnknown_202EDC8, NULL);
}

extern u8 gUnknown_203B40C;

extern const struct UnkTextStruct2 gUnknown_80F62B0[];
extern const struct UnkTextStruct2 gUnknown_80F6310[];
extern const struct UnkTextStruct2 gUnknown_80F6370[];
extern const struct UnkTextStruct2 gUnknown_80F63D0[];

void sub_8040ABC(u8 a0);

void sub_803EAF0(u32 a0, u8 *a1)
{
    if (a0 == gUnknown_202EDD0)
        return;

    switch (a0) {
        case 1:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            sub_803EC94();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            break;
        case 0:
            sub_803EC94();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            if (gUnknown_203B40C != 0) {
                sub_8040A84();
                sub_8040ABC(0);
            }
            break;
        case 3:
            xxx_call_save_unk_text_struct_800641C(gUnknown_80F62B0, TRUE, TRUE);
            if (gUnknown_203B40C != 0) {
                sub_8040ABC(1);
            }
            break;
        case 6:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_80F6310, TRUE, TRUE);
            break;
        case 7:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_80F6370, TRUE, TRUE);
            break;
        case 2:
        case 4:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            sub_803EC94();
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            break;
        case 5:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
            break;
        case 8:
            if (gUnknown_203B40C != 0) {
                sub_8083D44();
                sub_8052210(0);
            }
            CreateConfirmNameMenu(2, a1);
            break;
        case 9:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
                sub_8083D44();
            }
            ResetUnusedInputStruct();
            xxx_call_save_unk_text_struct_800641C(gUnknown_80F63D0, FALSE, TRUE);
            break;
        case 10:
            sub_8083D44();
            break;
        case 150: // Dummy case put here to match, any value >= 150 works
            break;
    }

    gUnknown_202EDD0 = a0;
}

extern MenuInputStruct gUnknown_202EE10;

void sub_803EC94(void)
{
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
}

extern void sub_8052210(u32);

void sub_803ECB4(UnkTextStruct2 *a0, bool8 a1)
{
    gUnknown_202EDD0 = 10;
    sub_8052210(0);
    ResetUnusedInputStruct();
    xxx_call_save_unk_text_struct_800641C(a0, TRUE, a1);
}

void sub_803ECE0(void)
{
    gUnknown_202EDD8++;
    if (gUnknown_202EDD8 < 0)
        gUnknown_202EDD8 = 0;
    if (gUnknown_202EDD8 > 11)
        gUnknown_202EDD8 = 0;

    sub_80098BC((void *)VRAM + 0x14400, gUnknown_202EC94->unk4 + ((gUnknown_202EDD8 / 4) * 0x240), 0x240);
}

s32 sub_803EF90(s32 a0, u8 a1);

struct UnkStruct_202EDE8
{
    s16 unk0;
    s16 unk2;
    Entity *unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern struct UnkStruct_202EDE8 gUnknown_202EDE8;

void sub_803ED30(s32 a0, Entity *mon, u8 a2, s32 a3)
{
    s32 i, var;

    if (a0 == 0 || gDungeon->unk181e8.blinded)
        return;

    for (i = 0; i < 20; i++) {
        if (gUnknown_202EDE8.unk0 == 0)
            break;
        sub_803E46C(0x29);
    }

    var = sub_803EF90(a0, a2);
    gUnknown_202EDE8.unk0 = 60;
    gUnknown_202EDE8.unk4 = mon;
    gUnknown_202EDE8.unk8 = mon->spawnGenID;
    gUnknown_202EDE8.unkC = -(var * 768);
    gUnknown_202EDE8.unk10 = 0;

    if (a3 < 0) {
        if (a0 < -999) {
            gUnknown_202EDE8.unk2 = 6;
        }
        else if (a0 >= 0) {
            gUnknown_202EDE8.unk2 = 10;
        }
        else {
            gUnknown_202EDE8.unk2 = 3;
        }
    }
    else {
        gUnknown_202EDE8.unk2 = a3;
    }

    sub_80098BC((void *) VRAM + 0x142C0, gDungeon->unk18, 0x80);
}

SpriteOAM gUnknown_202EDDC;

void sub_803EDF0(void)
{
    EntityInfo *entInfo;
    s32 x, y, y1, y2;

    if (gUnknown_202EDE8.unk0 == 0)
        return;
    if (!EntityExists(gUnknown_202EDE8.unk4)) {
        gUnknown_202EDE8.unk0 = 0;
        return;
    }
    if (gUnknown_202EDE8.unk8 != gUnknown_202EDE8.unk4->spawnGenID) {
        gUnknown_202EDE8.unk0 = 0;
        return;
    }

    gUnknown_202EDE8.unk0--;
    gUnknown_202EDE8.unk10 -= 46;
    entInfo = GetEntInfo(gUnknown_202EDE8.unk4);
    x = (entInfo->pixelPos.x + (gUnknown_202EDE8.unkC / 256)) - gDungeon->unk181e8.cameraPixelPos.x;
    y1 = (entInfo->pixelPos.y + (gUnknown_202EDE8.unk10 / 256));
    y2 = (gDungeon->unk181e8.cameraPixelPos.y + 24);
    y = y1 - y2;

    // sprite oam memes strike again
    if (x >= -32 && y >= -8 && x < 240 && y < 160) {
        u32 r9;
        u32 unk6;
        u32 shape, spriteX, palNum, prio, tileNum;

        unk6 = y & SPRITEOAM_MAX_UNK6_4;
        unk6 <<= SPRITEOAM_SHIFT_UNK6_4;
        gUnknown_202EDDC.unk6 &= ~SPRITEOAM_MASK_UNK6_4;
        gUnknown_202EDDC.unk6 |= unk6;

        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE1;
        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_AFFINEMODE2;
        r9 = 3;
        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_OBJMODE;
        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_MOSAIC;
        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_BPP;

        shape = 1 << SPRITEOAM_SHIFT_SHAPE;
        gUnknown_202EDDC.attrib1 &= ~SPRITEOAM_MASK_SHAPE;
        gUnknown_202EDDC.attrib1 |= shape;

        spriteX = x & SPRITEOAM_MAX_X;
        gUnknown_202EDDC.attrib2 &= ~SPRITEOAM_MASK_X;
        gUnknown_202EDDC.attrib2 |= spriteX;

        gUnknown_202EDDC.attrib2 &= ~SPRITEOAM_MASK_MATRIXNUM;
        gUnknown_202EDDC.attrib2 &= ~SPRITEOAM_MASK_SIZE;
        gUnknown_202EDDC.attrib2 |= 1 << SPRITEOAM_SHIFT_SIZE;

        tileNum = 0x216 << SPRITEOAM_SHIFT_TILENUM;
        gUnknown_202EDDC.attrib3 &= ~SPRITEOAM_MASK_TILENUM;
        gUnknown_202EDDC.attrib3 |= tileNum;

        prio = gDungeon->unk181e8.unk18208 & r9;
        prio <<= SPRITEOAM_SHIFT_PRIORITY;
        gUnknown_202EDDC.attrib3 &= ~SPRITEOAM_MASK_PRIORITY;
        gUnknown_202EDDC.attrib3 |= prio;

        palNum = gUnknown_202EDE8.unk2;
        palNum &= 0xF;
        palNum <<= SPRITEOAM_SHIFT_PALETTENUM;
        gUnknown_202EDDC.attrib3 &= ~SPRITEOAM_MASK_PALETTENUM;
        gUnknown_202EDDC.attrib3 |= palNum;

        gUnknown_202EDDC.unk6 &= 0xFFFE;
        gUnknown_202EDDC.unk6 &= 0xFFFD;
        gUnknown_202EDDC.unk6 &= 0xFFFB;

        AddSprite(&gUnknown_202EDDC, 0x100, NULL, NULL);
    }
}

//
