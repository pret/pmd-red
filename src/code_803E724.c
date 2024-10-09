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
#include "code_800E9E4.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_map_access.h"
#include "sprite.h"
#include "bg_control.h"
#include "game_options.h"
#include "code_800558C.h"
#include "dungeon_range.h"
#include "code_806CD90.h"
#include "dungeon_items.h"
#include "constants/item.h"
#include "constants/status.h"

extern s32 gUnknown_202EDC8;
extern u32 gUnknown_202EDD0;
extern s32 gUnknown_202EDD8;
extern u32 gUnknown_202EDFC;

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
extern u8 gUnknown_203B40C;
extern MenuInputStruct gUnknown_202EE10;
extern SpriteOAM gUnknown_202EDDC;

extern const u8 gUnknown_80F62AC[];
extern const struct UnkTextStruct2 gUnknown_80F62B0[];
extern const struct UnkTextStruct2 gUnknown_80F6310[];
extern const struct UnkTextStruct2 gUnknown_80F6370[];
extern const struct UnkTextStruct2 gUnknown_80F63D0[];
extern const u32 gUnknown_80F6490[];
extern const s32 gUnknown_80F64B4[];
extern const s32 gUnknown_80F64FC[];
extern const s32 gUnknown_80F6520[];
extern const u16 gUnknown_80F64D8[][9];
extern const u16 gUnknown_80F6544[][9];

extern u8 gUnknown_20274A5;

extern u8 gUnknown_202D06C[];
// 2d array? possibly the same as gUnknown_202D06C TODO: merge the variables
extern u8 gUnknown_202D068[];

extern s32 gUnknown_202EDCC;
extern u32 gUnknown_3001018[];

extern void sub_8052210(u32);
extern void sub_8040A84();
extern void sub_8083D44(void);
extern void sub_8052210(u32);
extern void sub_8049ED4(void);
extern void sub_8040A84(void);
extern void sub_80400D4(void);
extern void sub_8041888(u8 param_1);
extern void sub_804A1F0(s32 a0, s32 a1);
extern void sub_804A49C(s32 a0, s32 a1);
extern void sub_80402AC(s32, s32);

void sub_803EC94(void);
void sub_8040ABC(u8 a0);
s32 sub_803EF90(s32 a0, u8 a1);
void sub_803F580(u8 a0);
void sub_803F7BC(void);
void sub_803F38C(void);
void sub_803FB74(void);
void sub_803FE30(s32 a0, u16 *a1, bool8 a2, bool8 a3);
void sub_803FF18(s32 a0, u16 *a1, bool8 a2);

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

void sub_803EC94(void)
{
    gUnknown_202EE10.unk1E = 0;
    gUnknown_202EE10.unk20 = 0;
    gUnknown_202EE10.unkC = 0;
    gUnknown_202EE10.unkE = 0;
    gUnknown_202EE10.unk14.x = 0;
    sub_801317C(&gUnknown_202EE10.unk28);
}

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

/*
Not even attempting this, opened file unknown structs weirdly put on stack, my head hurts just looking at this
s32 sub_803EF90(s32 a0, u8 a1)
{

}
*/

NAKED s32 sub_803EF90(s32 a0, u8 a1)
{
    asm_unified("push {r4-r7,lr}\n"
	"	mov r7, r10\n"
	"	mov r6, r9\n"
	"	mov r5, r8\n"
	"	push {r5-r7}\n"
	"	sub sp, 0x58\n"
	"	str r0, [sp, 0x48]\n"
	"	lsls r1, 24\n"
	"	lsrs r5, r1, 24\n"
	"	ldr r0, _0803F060\n"
	"	ldr r0, [r0]\n"
	"	adds r0, 0x18\n"
	"	mov r8, r0\n"
	"	ldr r0, _0803F064\n"
	"	ldr r1, [r0]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	movs r2, 0x92\n"
	"	lsls r2, 1\n"
	"	adds r0, r2\n"
	"	str r0, [sp, 0x24]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	movs r3, 0x82\n"
	"	lsls r3, 1\n"
	"	adds r0, r3\n"
	"	str r0, [sp, 0x28]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0xE4\n"
	"	str r0, [sp, 0x2C]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0xC4\n"
	"	str r0, [sp, 0x30]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0xA4\n"
	"	str r0, [sp, 0x34]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0x84\n"
	"	str r0, [sp, 0x38]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0x64\n"
	"	str r0, [sp, 0x3C]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0x44\n"
	"	str r0, [sp, 0x40]\n"
	"	ldr r0, [r1, 0x4]\n"
	"	adds r0, 0x24\n"
	"	str r0, [sp, 0x44]\n"
	"	add r4, sp, 0x24\n"
	"	mov r0, sp\n"
	"	adds r1, r4, 0\n"
	"	movs r2, 0x24\n"
	"	bl memcpy\n"
	"	movs r1, 0\n"
	"	movs r6, 0x3\n"
	"	mov r0, r8\n"
	"_0803EFFE:\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	stm r0!, {r1}\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _0803EFFE\n"
	"	ldr r0, _0803F068\n"
	"	ldr r1, [sp, 0x48]\n"
	"	cmp r1, r0\n"
	"	bne _0803F0A6\n"
	"	adds r0, r4, 0\n"
	"	ldr r1, _0803F06C\n"
	"	ldm r1!, {r2,r3,r5}\n"
	"	stm r0!, {r2,r3,r5}\n"
	"	ldr r1, [r1]\n"
	"	str r1, [r0]\n"
	"	movs r5, 0\n"
	"	movs r2, 0\n"
	"	mov r12, r4\n"
	"	movs r0, 0x20\n"
	"	mov r10, r0\n"
	"_0803F032:\n"
	"	mov r3, r8\n"
	"	ldr r0, _0803F064\n"
	"	ldr r1, [r0]\n"
	"	lsls r0, r2, 2\n"
	"	add r0, r12\n"
	"	ldr r0, [r0]\n"
	"	lsls r0, 5\n"
	"	adds r0, 0x4\n"
	"	ldr r1, [r1, 0x4]\n"
	"	adds r4, r1, r0\n"
	"	movs r1, 0x18\n"
	"	adds r1, r5\n"
	"	mov r9, r1\n"
	"	adds r2, 0x1\n"
	"	str r2, [sp, 0x54]\n"
	"	mov r2, r10\n"
	"	subs r7, r2, r5\n"
	"	movs r6, 0x7\n"
	"_0803F056:\n"
	"	cmp r5, 0\n"
	"	bne _0803F070\n"
	"	movs r1, 0\n"
	"	ldr r2, [r4]\n"
	"	b _0803F07A\n"
	"	.align 2, 0\n"
	"_0803F060: .4byte gDungeon\n"
	"_0803F064: .4byte gUnknown_202EC9C\n"
	"_0803F068: .4byte 0x0000270f\n"
	"_0803F06C: .4byte gUnknown_80F6478\n"
	"_0803F070:\n"
	"	ldr r0, [r4]\n"
	"	adds r1, r0, 0\n"
	"	lsrs r1, r7\n"
	"	adds r2, r0, 0\n"
	"	lsls r2, r5\n"
	"_0803F07A:\n"
	"	adds r4, 0x4\n"
	"	ldr r0, [r3]\n"
	"	orrs r0, r2\n"
	"	str r0, [r3]\n"
	"	ldr r0, [r3, 0x20]\n"
	"	orrs r0, r1\n"
	"	str r0, [r3, 0x20]\n"
	"	adds r3, 0x4\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _0803F056\n"
	"	mov r5, r9\n"
	"	cmp r5, 0x1F\n"
	"	ble _0803F09C\n"
	"	subs r5, 0x20\n"
	"	movs r3, 0x20\n"
	"	add r8, r3\n"
	"_0803F09C:\n"
	"	ldr r2, [sp, 0x54]\n"
	"	cmp r2, 0x3\n"
	"	ble _0803F032\n"
	"	movs r0, 0x4\n"
	"	b _0803F26A\n"
	"_0803F0A6:\n"
	"	ldr r0, _0803F0D8\n"
	"	ldr r1, [sp, 0x48]\n"
	"	cmp r1, r0\n"
	"	ble _0803F0B0\n"
	"	str r0, [sp, 0x48]\n"
	"_0803F0B0:\n"
	"	ldr r0, _0803F0DC\n"
	"	ldr r2, [sp, 0x48]\n"
	"	cmp r2, r0\n"
	"	bge _0803F0BA\n"
	"	str r0, [sp, 0x48]\n"
	"_0803F0BA:\n"
	"	ldr r1, _0803F0E0\n"
	"	ldr r0, [r1]\n"
	"	ldr r0, [r0, 0x4]\n"
	"	movs r3, 0xC2\n"
	"	lsls r3, 1\n"
	"	adds r2, r0, r3\n"
	"	cmp r5, 0\n"
	"	beq _0803F0F4\n"
	"	ldr r5, [sp, 0x48]\n"
	"	cmp r5, 0\n"
	"	ble _0803F0E4\n"
	"	movs r1, 0xA2\n"
	"	lsls r1, 1\n"
	"	adds r2, r0, r1\n"
	"	b _0803F0F4\n"
	"	.align 2, 0\n"
	"_0803F0D8: .4byte 0x000003e7\n"
	"_0803F0DC: .4byte 0xfffffc19\n"
	"_0803F0E0: .4byte gUnknown_202EC9C\n"
	"_0803F0E4:\n"
	"	ldr r3, [sp, 0x48]\n"
	"	cmp r3, 0\n"
	"	bge _0803F0F4\n"
	"	movs r5, 0xB2\n"
	"	lsls r5, 1\n"
	"	adds r2, r0, r5\n"
	"	negs r3, r3\n"
	"	str r3, [sp, 0x48]\n"
	"_0803F0F4:\n"
	"	ldm r2!, {r0}\n"
	"	mov r1, r8\n"
	"	str r0, [r1]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0x4]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0x8]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0xC]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0x10]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0x14]\n"
	"	ldm r2!, {r0}\n"
	"	str r0, [r1, 0x18]\n"
	"	ldr r0, [r2]\n"
	"	str r0, [r1, 0x1C]\n"
	"	movs r5, 0x18\n"
	"	movs r2, 0x1\n"
	"	str r2, [sp, 0x4C]\n"
	"	movs r3, 0\n"
	"	str r3, [sp, 0x50]\n"
	"	movs r2, 0\n"
	"_0803F122:\n"
	"	movs r0, 0\n"
	"	mov r10, r0\n"
	"	adds r1, r2, 0x1\n"
	"	str r1, [sp, 0x54]\n"
	"	lsls r0, r2, 3\n"
	"	adds r0, r2\n"
	"	lsls r0, 2\n"
	"	mov r1, sp\n"
	"	ldr r2, _0803F15C\n"
	"	adds r7, r0, r2\n"
	"_0803F136:\n"
	"	ldr r0, [r7]\n"
	"	ldr r3, [sp, 0x48]\n"
	"	cmp r0, r3\n"
	"	bgt _0803F1A2\n"
	"	ldr r4, [r1]\n"
	"	mov r2, r8\n"
	"	movs r0, 0x18\n"
	"	adds r0, r5\n"
	"	mov r9, r0\n"
	"	movs r1, 0x20\n"
	"	subs r1, r5\n"
	"	mov r12, r1\n"
	"	movs r6, 0x7\n"
	"_0803F150:\n"
	"	cmp r5, 0\n"
	"	bne _0803F160\n"
	"	movs r3, 0\n"
	"	ldr r1, [r4]\n"
	"	b _0803F16C\n"
	"	.align 2, 0\n"
	"_0803F15C: .4byte gUnknown_80F6430\n"
	"_0803F160:\n"
	"	ldr r0, [r4]\n"
	"	adds r3, r0, 0\n"
	"	mov r1, r12\n"
	"	lsrs r3, r1\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, r5\n"
	"_0803F16C:\n"
	"	adds r4, 0x4\n"
	"	ldr r0, [r2]\n"
	"	orrs r0, r1\n"
	"	str r0, [r2]\n"
	"	ldr r0, [r2, 0x20]\n"
	"	orrs r0, r3\n"
	"	str r0, [r2, 0x20]\n"
	"	adds r2, 0x4\n"
	"	movs r3, 0x1\n"
	"	str r3, [sp, 0x50]\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _0803F150\n"
	"	mov r5, r9\n"
	"	cmp r5, 0x1F\n"
	"	ble _0803F192\n"
	"	subs r5, 0x20\n"
	"	movs r0, 0x20\n"
	"	add r8, r0\n"
	"_0803F192:\n"
	"	ldr r0, [r7]\n"
	"	ldr r1, [sp, 0x48]\n"
	"	subs r1, r0\n"
	"	str r1, [sp, 0x48]\n"
	"	ldr r2, [sp, 0x4C]\n"
	"	adds r2, 0x1\n"
	"	str r2, [sp, 0x4C]\n"
	"	b _0803F1B0\n"
	"_0803F1A2:\n"
	"	adds r1, 0x4\n"
	"	adds r7, 0x4\n"
	"	movs r3, 0x1\n"
	"	add r10, r3\n"
	"	mov r0, r10\n"
	"	cmp r0, 0x8\n"
	"	ble _0803F136\n"
	"_0803F1B0:\n"
	"	mov r1, r10\n"
	"	cmp r1, 0x9\n"
	"	bne _0803F212\n"
	"	ldr r2, [sp, 0x50]\n"
	"	cmp r2, 0\n"
	"	beq _0803F212\n"
	"	ldr r3, _0803F1DC\n"
	"	ldr r0, [r3]\n"
	"	ldr r0, [r0, 0x4]\n"
	"	adds r4, r0, 0x4\n"
	"	mov r2, r8\n"
	"	movs r0, 0x18\n"
	"	adds r0, r5\n"
	"	mov r9, r0\n"
	"	movs r1, 0x20\n"
	"	subs r7, r1, r5\n"
	"	movs r6, 0x7\n"
	"_0803F1D2:\n"
	"	cmp r5, 0\n"
	"	bne _0803F1E0\n"
	"	movs r3, 0\n"
	"	ldr r1, [r4]\n"
	"	b _0803F1EA\n"
	"	.align 2, 0\n"
	"_0803F1DC: .4byte gUnknown_202EC9C\n"
	"_0803F1E0:\n"
	"	ldr r0, [r4]\n"
	"	adds r3, r0, 0\n"
	"	lsrs r3, r7\n"
	"	adds r1, r0, 0\n"
	"	lsls r1, r5\n"
	"_0803F1EA:\n"
	"	adds r4, 0x4\n"
	"	ldr r0, [r2]\n"
	"	orrs r0, r1\n"
	"	str r0, [r2]\n"
	"	ldr r0, [r2, 0x20]\n"
	"	orrs r0, r3\n"
	"	str r0, [r2, 0x20]\n"
	"	adds r2, 0x4\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _0803F1D2\n"
	"	mov r5, r9\n"
	"	cmp r5, 0x1F\n"
	"	ble _0803F20C\n"
	"	subs r5, 0x20\n"
	"	movs r2, 0x20\n"
	"	add r8, r2\n"
	"_0803F20C:\n"
	"	ldr r3, [sp, 0x4C]\n"
	"	adds r3, 0x1\n"
	"	str r3, [sp, 0x4C]\n"
	"_0803F212:\n"
	"	ldr r2, [sp, 0x54]\n"
	"	cmp r2, 0x1\n"
	"	ble _0803F122\n"
	"	ldr r0, _0803F240\n"
	"	ldr r1, [r0]\n"
	"	ldr r2, [sp, 0x48]\n"
	"	lsls r0, r2, 5\n"
	"	adds r0, 0x4\n"
	"	ldr r1, [r1, 0x4]\n"
	"	adds r1, r0\n"
	"	mov r3, r8\n"
	"	ldr r0, [sp, 0x4C]\n"
	"	adds r0, 0x1\n"
	"	mov r8, r0\n"
	"	movs r0, 0x20\n"
	"	subs r7, r0, r5\n"
	"	movs r6, 0x7\n"
	"_0803F234:\n"
	"	cmp r5, 0\n"
	"	bne _0803F244\n"
	"	movs r4, 0\n"
	"	ldr r2, [r1]\n"
	"	b _0803F24E\n"
	"	.align 2, 0\n"
	"_0803F240: .4byte gUnknown_202EC9C\n"
	"_0803F244:\n"
	"	ldr r0, [r1]\n"
	"	adds r4, r0, 0\n"
	"	lsrs r4, r7\n"
	"	adds r2, r0, 0\n"
	"	lsls r2, r5\n"
	"_0803F24E:\n"
	"	adds r1, 0x4\n"
	"	ldr r0, [r3]\n"
	"	orrs r0, r2\n"
	"	str r0, [r3]\n"
	"	ldr r0, [r3, 0x20]\n"
	"	orrs r0, r4\n"
	"	str r0, [r3, 0x20]\n"
	"	adds r3, 0x4\n"
	"	subs r6, 0x1\n"
	"	cmp r6, 0\n"
	"	bge _0803F234\n"
	"	mov r1, r8\n"
	"	str r1, [sp, 0x4C]\n"
	"	adds r0, r1, 0\n"
	"_0803F26A:\n"
	"	add sp, 0x58\n"
	"	pop {r3-r5}\n"
	"	mov r8, r3\n"
	"	mov r9, r4\n"
	"	mov r10, r5\n"
	"	pop {r4-r7}\n"
	"	pop {r1}\n"
	"	bx r1\n");
}

void sub_803F27C(bool8 a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraPixelPos.x = 0;
    strPtr->cameraPixelPos.y = 0;
    strPtr->cameraPos.x = 0;
    strPtr->cameraPos.y = 0;
    strPtr->cameraPixelPosMirror.x = 0;
    strPtr->cameraPixelPosMirror.y = 0;
    strPtr->cameraPosMirror.x = 0;
    strPtr->cameraPosMirror.y = 0;

    strPtr->unk181FC = 0;
    strPtr->unk18216 = 0;
    strPtr->unk18217 = 1;
    strPtr->unk18218 = 1;
    strPtr->unk18219 = 0;

    strPtr->unk18200 = 0;
    strPtr->unk18204 = 0;
    if (!a0) {
        strPtr->blinded = 0;
        strPtr->hallucinating = 0;
        strPtr->unk1820F = 0;
        strPtr->unk1820D = 0;
        strPtr->unk18211 = 0;
        strPtr->unk1820E = 0;
        strPtr->unk1820B = 0;
        strPtr->unk1820C = 0;
    }

    strPtr->cameraTarget = NULL;
    strPtr->unk18208 = 3;
    strPtr->unk1821A = 0;
    strPtr->unk18212 = 0;
    strPtr->unk1821B = 0;
    strPtr->unk1821C = 0;
    strPtr->unk18214 = 0;
    strPtr->unk18215 = 1;
    sub_803F38C();

    gUnknown_202EDFC = 0xFFFF;
    if (!a0) {
        strPtr->visibilityRange = gDungeon->unk1C574.unk16 & 3;
        if (strPtr->visibilityRange == 0) {
            strPtr->unk1820C = 1;
        }
    }
}

void sub_803F38C(void)
{
    s32 palAdd;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->unk3A = -1;
    strPtr->unk3C = -1;
    strPtr->unk3E = -1;
    strPtr->unk40 = -1;
    strPtr->unk36 = -1;
    strPtr->unk38 = -1;

    palAdd = (gGameOptionsRef->playerGender != MALE) ? 256 : 0;

    SetBGPaletteBufferColorArray(0xFD, &gUnknown_202D06C[0 + palAdd]);
    SetBGPaletteBufferColorArray(0xFE, &gUnknown_202D06C[4 + palAdd]);
    SetBGPaletteBufferColorArray(0xFF, &gUnknown_202D06C[8 + palAdd]);

    nullsub_5(0xFD, &gUnknown_202D06C[0 + palAdd]);
    nullsub_5(0xFE, &gUnknown_202D06C[4 + palAdd]);
    nullsub_5(0xFF, &gUnknown_202D06C[8 + palAdd]);
}

bool8 sub_803F428(Position *pos)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    Entity *cameraEntity = strPtr->cameraTarget;

    if (abs(strPtr->cameraPos.x - pos->x) <= 6 && abs(strPtr->cameraPos.y - pos->y) <= 5) {
        if (strPtr->unk1820B == 0 && strPtr->unk1820C == 0 && cameraEntity != NULL) {
            return IsPositionActuallyInSight(&strPtr->cameraPos, pos);
        }
        return TRUE;
    }

    return FALSE;
}

void sub_803F4A0(Entity *a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraTarget = a0;
    if (a0 == NULL) {
        strPtr->unk18216 = 0;
    }
    else if (!GetEntInfo(a0)->isTeamLeader) {
        strPtr->unk18216 = 0;
    }
    else {
        strPtr->unk18216 = 1;
    }

    sub_803F580(0);
    sub_803F38C();
    if (gDungeon->unk1356C == 0) {
        sub_806CD90();
    }
}

// Very similar to the one above
void sub_803F508(Entity *a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    if (a0 == NULL) {
        strPtr->unk18216 = 0;
    }
    else if (!GetEntInfo(a0)->isTeamLeader) {
        strPtr->unk18216 = 0;
    }
    else {
        strPtr->unk18216 = 1;
    }
    strPtr->cameraTarget = a0;

    sub_803F580(0);
    sub_803F38C();
    if (gDungeon->unk1356C == 0) {
        sub_806CD90();
    }
    sub_8049ED4();
    sub_8040A84();
}

void sub_803F580(u8 a0)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    Entity *cameraTarget = strPtr->cameraTarget;

    if (cameraTarget != NULL && EntityExists(cameraTarget)) {
        s32 i;
        u32 before, unk18214;
        EntityInfo *info = GetEntInfo(cameraTarget);

        strPtr->cameraPixelPosMirror = strPtr->cameraPixelPos;
        strPtr->cameraPosMirror = strPtr->cameraPos;
        strPtr->cameraPos.x = cameraTarget->pos.x;
        strPtr->cameraPos.y = cameraTarget->pos.y;

        strPtr->cameraPixelPos.x = (cameraTarget->pixelPos.x / 256) - 120;
        strPtr->cameraPixelPos.y = (cameraTarget->pixelPos.y / 256) - 96;

        if (HasHeldItem(cameraTarget, ITEM_X_RAY_SPECS) && info->isTeamLeader) {
            strPtr->unk1820D = 1;
            strPtr->unk1820E = 1;
        }
        else {
            strPtr->unk1820D = info->powerEars;
            strPtr->unk1820E = info->scanning;
        }

        strPtr->unk18211 = info->stairSpotter;
        before = strPtr->blinded;
        unk18214 = strPtr->unk18214;
        if (unk18214 == 0) {
            u32 unkVar;
            if (info->eyesightStatus.eyesightStatus == STATUS_BLINKER) {
                strPtr->blinded = 1;
                unkVar = 0xE;
            }
            else {
                strPtr->blinded = unk18214;
                unkVar = 0;
            }

            if (gUnknown_202EDFC != unkVar) {
                gUnknown_202EDFC = unkVar;
                SetBGOBJEnableFlags(unkVar);
            }
        }
        else {
            gUnknown_202EDFC = 0xFFFF;
        }

        if (before != strPtr->blinded) {
            sub_8041888(0);
        }

        before = strPtr->hallucinating;
        if (info->eyesightStatus.eyesightStatus == STATUS_CROSS_EYED) {
            strPtr->hallucinating = 1;
        }
        else {
            strPtr->hallucinating = 0;
        }

        if (before != strPtr->hallucinating) {
            sub_806CC70();
            sub_8041888(0);
        }

        before = strPtr->unk1820F;
        if (CanSeeInvisibleMonsters(cameraTarget)) {
            strPtr->unk1820F = 1;
        }
        else {
            strPtr->unk1820F = 0;
        }

        if (before != strPtr->unk1820F) {
            sub_8049ED4();
            sub_8040A84();
            sub_8041888(0);
        }

        if (a0 && strPtr->unk18213 == 0) {
            if (abs(strPtr->cameraPixelPosMirror.x - strPtr->cameraPixelPos.x) > 7 || abs(strPtr->cameraPixelPosMirror.y - strPtr->cameraPixelPos.y) > 7) {
                sub_8049ED4();
                strPtr->unk18213 = 1;
            }
            else {
                if (strPtr->cameraPixelPosMirror.x < strPtr->cameraPixelPos.x) {
                    sub_804A1F0(240, 0);
                }
                else if (strPtr->cameraPixelPosMirror.x > strPtr->cameraPixelPos.x) {
                    sub_804A1F0(0, 0);
                }

                if (strPtr->cameraPixelPosMirror.y < strPtr->cameraPixelPos.y) {
                    sub_804A49C(0, 160);
                }
                else if (strPtr->cameraPixelPosMirror.y > strPtr->cameraPixelPos.y) {
                    sub_804A49C(0, 0);
                }
            }
        }

        if (strPtr->cameraPos.x != strPtr->cameraPosMirror.x || strPtr->cameraPos.y != strPtr->cameraPosMirror.y) {
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->allPokemon[i];
                if (EntityExists(mon)) {
                    sub_80402AC(mon->pos.x, mon->pos.y);
                }
            }
        }
    }

    sub_80400D4();
    sub_803F7BC();
}

void sub_803F7BC(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    Tile *tile = GetTile(strPtr->cameraPos.x, strPtr->cameraPos.y);
    u32 roomId = tile->room;

    if (strPtr->unk1820B != 0 || strPtr->unk1820C != 0 || strPtr->unk18217 != 0) {
        sub_8005838(NULL, 0);
    }
    else if (roomId == 0xFF) {
        u32 kind = (strPtr->visibilityRange == 2) ? 1 : 2;
        sub_8005838(NULL, kind);
    }
    else {
        s32 sp[4];
        RoomData *room = &gDungeon->roomData[roomId];

        sp[0] = room->unkC - strPtr->cameraPixelPos.x;
        sp[1] = room->unk10 - strPtr->cameraPixelPos.y;
        sp[2] = room->unk14 - strPtr->cameraPixelPos.x;
        sp[3] = room->unk18 - strPtr->cameraPixelPos.y;
        sub_8005838(sp, 3);
    }
}

void sub_803F878(s32 a0, s32 a1)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->cameraPixelPosMirror = strPtr->cameraPixelPos;
    strPtr->cameraPosMirror = strPtr->cameraPos;
    strPtr->cameraPixelPos.x = (a0 / 256) - 120;
    strPtr->cameraPixelPos.y = (a1 / 256) - 96;
    strPtr->cameraPos.x = a0 / 6144;
    strPtr->cameraPos.y = a1 / 6144;
    strPtr->unk1820D = 0;
    strPtr->unk1820E = 0;
    strPtr->unk18211 = 0;
    strPtr->unk18216 = 0;

    if (gUnknown_202EDFC != 0) {
        gUnknown_202EDFC = 0;
        SetBGOBJEnableFlags(0);
    }

    if (abs(strPtr->cameraPixelPosMirror.x - strPtr->cameraPixelPos.x) > 7 || abs(strPtr->cameraPixelPosMirror.y - strPtr->cameraPixelPos.y) > 7) {
        sub_8049ED4();
        strPtr->unk18213 = 1;
    }
    else {
        if (strPtr->cameraPixelPosMirror.x < strPtr->cameraPixelPos.x) {
            sub_804A1F0(240, 0);
        }
        else if (strPtr->cameraPixelPosMirror.x > strPtr->cameraPixelPos.x) {
            sub_804A1F0(0, 0);
        }

        if (strPtr->cameraPixelPosMirror.y < strPtr->cameraPixelPos.y) {
            sub_804A49C(0, 160);
        }
        else if (strPtr->cameraPixelPosMirror.y > strPtr->cameraPixelPos.y) {
            sub_804A49C(0, 0);
        }
    }

    sub_803F7BC();
}

s32 GetCameraXPos(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    return (strPtr->cameraPixelPos.x + 120) * 256;
}

s32 GetCameraYPos(void)
{
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    return (strPtr->cameraPixelPos.y + 96) * 256;
}

void sub_803F9CC(void)
{
    s32 i;
    Entity *cameraTarget = gDungeon->unk181e8.cameraTarget;
    bool32 r5 = FALSE;

    if (gDungeon->unk1356C != 0 || gDungeon->unk181e8.unk18218 != 0 || sub_800EC74() != 0) {
        r5 = FALSE;
    }
    else if (cameraTarget != NULL && GetEntityType(cameraTarget) == ENTITY_MONSTER) {
        r5 = TRUE;
    }

    if (!r5) {
        for (i = 1; i < 30; i++) {
            gUnknown_202B038[0][0][i] = 0;
        }
        sub_803F38C();
    }
    else {
        sub_803FB74();
    }

    gUnknown_20274A5 = 1;
}

void sub_803FA4C(s32 a0, s32 a1, bool8 a2)
{
    s32 i;
    s32 r5;
    u32 r10, r9;
    u32 sp[9];
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    u32 *dst = gUnknown_3001018;
    memcpy(sp, gUnknown_80F6490, sizeof(sp));

    r10 = 0x22222222;
    r9 = 0x44444444;
    if (a0 == strPtr->unk3E && a1 == strPtr->unk40)
        return;
    if (!a2) {
        r9 = 0x55555555;
    }

    strPtr->unk3E = a0;
    strPtr->unk40 = a1;
    r5 = a1;
    if (r5 >= 96) {
        r5 = 96;
        a0 = (a0 * 96) / a1;
    }

    for (i = 0; i < 96; i += 8) {
        u32 val0, val1;
        u32 val6 = 0x77777777;
        s32 id1 = a0;
        s32 id2 = r5;

        if (a0 >= 8) {
            id1 = 8;
        }
        if (r5 >= 8) {
            id2 = 8;
        }

        val1 = sp[id2] & ~(sp[id1]);
        val1 &= r10;
        val0 = (sp[id1] & r9) | val1;
        val6 = sp[id2] & val6;
        *(dst++) = 0;
        *(dst++) = val6;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val0;
        *(dst++) = val6;
        *(dst++) = 0;

        a0 -= 8;
        r5 -= 8;
        if (a0 < 0) {
            a0 = 0;
        }
        if (r5 < 0) {
            r5 = 0;
        }
    }
    sub_80098BC((void *) VRAM + 0x5980, gUnknown_3001018, 0x180);
}

void sub_803FB74(void)
{
    s32 i;
    u16 *arrPtr;
    s32 r5, r6, unkFloor;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;
    bool32 lowHp = FALSE;
    bool32 hungry = FALSE;
    EntityInfo *entInfo = GetEntInfo(strPtr->cameraTarget);
    s32 hp = entInfo->HP;
    s32 maxHp = entInfo->maxHPStat;
    s32 level = entInfo->level;

    if (entInfo->HP > 0 && entInfo->HP <= entInfo->maxHPStat / 4) {
        lowHp = TRUE;
    }
    // reloaded again
    entInfo = GetEntInfo(strPtr->cameraTarget);
    if (FixedPointToInt(entInfo->belly) == 0) {
        hungry = TRUE;
    }

    if (lowHp && (gUnknown_202EDCC & 16) != 0) {
        r5 = 32, r6 = 32;
    }
    else {
        r5 = 0, r6 = 0;
    }

    if (hungry && (gUnknown_202EDCC & 16) != 0) {
        r5 = 48, r6 = 48;
    }

    if (r5 == 0) {
        if (strPtr->unk18212 != 0) {
            r5 = 96;
        }
        else if (gGameOptionsRef->playerGender != MALE) {
            r5 = 64;
        }
    }

    if (r6 == 0) {
        if (gGameOptionsRef->playerGender != MALE) {
            r6 = 64;
        }
    }

    if (strPtr->unk36 != r5) {
        strPtr->unk36 = r5;
        SetBGPaletteBufferColorArray(0xFC, &gUnknown_202D068[0 + r5 * 4]);
        SetBGPaletteBufferColorArray(0xFD, &gUnknown_202D068[4 + r5 * 4]);
        SetBGPaletteBufferColorArray(0xFE, &gUnknown_202D068[8 + r5 * 4]);
        SetBGPaletteBufferColorArray(0xFF, &gUnknown_202D068[12 + r5 * 4]);
    }

    if (strPtr->unk38 != r6) {
        strPtr->unk38 = r6;
        nullsub_5(0xFC, &gUnknown_202D068[0 + r6 * 4]);
        nullsub_5(0xFD, &gUnknown_202D068[4 + r6 * 4]);
        nullsub_5(0xFE, &gUnknown_202D068[8 + r6 * 4]);
        nullsub_5(0xFF, &gUnknown_202D068[12 + r6 * 4]);
    }

    arrPtr = gUnknown_202B038[0][0];
    unkFloor = gDungeon->unk14 + gDungeon->dungeonLocation.floor;
    if (strPtr->unk3A != unkFloor) {
        strPtr->unk3A = unkFloor;
        if (IsStairDirectionUp(gDungeon->dungeonLocation.id)) {
            arrPtr[1] = 0;
        }
        else {
            arrPtr[1] = 0xF2BE;
        }

        if (unkFloor < 10) {
            sub_803FE30(unkFloor, &arrPtr[2], strPtr->unk18216, 1);
            arrPtr[3] = 0xF2B8;
        }
        else {
            sub_803FE30(unkFloor, &arrPtr[2], strPtr->unk18216, 0);
            arrPtr[4] = 0xF2B8;
        }
    }

    if (strPtr->unk3C != level) {
        strPtr->unk3C = level;
        arrPtr[5] = 0xF2B9;
        arrPtr[6] = 0xF2BA;
        sub_803FE30(level, &arrPtr[7], strPtr->unk18216, 0);
    }

    if (strPtr->unk3E != hp) {
        arrPtr[9] = 0xF2BB;
        arrPtr[10] = 0xF2BC;
        sub_803FF18(hp, &arrPtr[11], strPtr->unk18216);
    }

    if (strPtr->unk40 != maxHp) {
        arrPtr[14] = 0xF2BD;
        sub_803FF18(maxHp, &arrPtr[15], strPtr->unk18216);
    }

    sub_803FA4C(hp, maxHp, strPtr->unk18216);
    strPtr->unk40 = maxHp;
    strPtr->unk3E = hp;
    strPtr->unk42 = maxHp / 8;
    if (maxHp % 8 != 0) {
        strPtr->unk42++;
    }

    if (strPtr->unk42 >= 12) {
        strPtr->unk42 = 12;
    }

    for (i = 0; i < 12; i++) {
        gUnknown_202B038[0][0][18 + i] = (0x2CC + i) | 0xF000;
    }
}

void sub_803FE30(s32 a0, u16 *a1, bool8 a2, bool8 a3)
{
    s32 var = (a2) ? 0 : 55;

    if (a0 > 100) {
        if (a2) {
            a1[0] = 0xF291;
            a1[1] = 0xF291;
        }
        else {
            a1[0] = 0xF2C8;
            a1[1] = 0xF2C8;
        }
    }
    else if (a0 == 100) {
        a1[0] = 0xF294;
        a1[1] = 0xF295;
    }
    else {
        // I thought 'ptr' was a compiler generated variable, but I couldn't match the function without declaring it.
        u16 *ptr = a1 + 1;
        s32 varAdd = var + 48;

        if (a0 >= 10) {
            s32 i;
            s32 arrId = (!a2) ? 1 : 0;

            for (i = 0; i < 9; i++) {
                #ifndef NONMATCHING
                a1++;a1--; // Good old matching trick.
                #endif // NONMATCHING
                if (gUnknown_80F64B4[i] <= a0) {
                    *a1 = gUnknown_80F64D8[arrId][i];
                    *ptr  = (((a0 - gUnknown_80F64B4[i]) + varAdd) + 0x258) | 0xF000;
                    return;
                }
            }
        }
        if (!a3) {
            *(a1++) = 0xF278;
        }

        *a1 = (a0 + varAdd + 0x258) | 0xF000;
    }
}

void sub_803FF18(s32 a0, u16 *a1, bool8 a2)
{
    s32 arrId = (!a2) ? 1 : 0;
    s32 var = (a2) ? 0 : 55;

    if (a0 > 999) {
        u16 val = gUnknown_80F6544[arrId][0];
        *(a1++) = val;
        *(a1++) = val;
        *a1 = val;
    }
    else {
        u8 toAdd = 32;
        s32 i = 0;
        s32 varAdd = var + 48;

        for (i = 0; i < 9; i++) {
            if (gUnknown_80F64FC[i] <= a0) {
                *(a1++) = gUnknown_80F6544[arrId][i];
                a0 -= gUnknown_80F64FC[i];
                toAdd = varAdd;
                break;
            }
        }
        if (i == 9) {
            *(a1++) = (toAdd + 0x258) | 0xF000;
        }

        for (i = 0; i < 9; i++) {
            if (gUnknown_80F6520[i] <= a0) {
                *(a1++) = gUnknown_80F6544[arrId][i];
                a0 -= gUnknown_80F6520[i];
                break;
            }
        }
        if (i == 9) {
            *(a1++) = (toAdd + 0x258) | 0xF000;
        }

        *a1 = (a0 + varAdd + 0x258) | 0xF000;
    }
}
