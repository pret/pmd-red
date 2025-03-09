#include "global.h"
#include "dungeon.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "input.h"
#include "text.h"
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
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "dungeon_items.h"
#include "constants/item.h"
#include "constants/status.h"
#include "code_803E724.h"

extern s32 gDungeonBrightness;
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
extern RGB gUnknown_202ECA4[];
extern u8 gUnknown_203B40C;
extern MenuInputStruct gUnknown_202EE10;
extern SpriteOAM gUnknown_202EDDC;

extern const u32 gUnknown_80F6490[];
extern const s32 gUnknown_80F64B4[];
extern const s32 gUnknown_80F64FC[];
extern const s32 gUnknown_80F6520[];
extern const u16 gUnknown_80F64D8[][9];
extern const u16 gUnknown_80F6544[][9];

extern u8 gUnknown_20274A5;

extern s32 gUnknown_202EDCC;

extern void sub_8040A84();
extern void sub_8083D44(void);
extern void sub_8040A84(void);
extern void sub_80400D4(void);
extern void sub_8041888(u8 param_1);
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

static const RGB sBlackRgb = {0, 0, 0};

void sub_803E874(bool8 r10, s32 r9)
{
    s32 i, index, count;
    const RGB *color;

    color = gDungeonPaletteFile->unk4;
    SetBGPaletteBufferColorRGB(0, &sBlackRgb, gDungeonBrightness, gDungeon->colorRamp);
    color++;
    index = 1;
    count = 159;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, color, gDungeonBrightness, gDungeon->colorRamp);
        color++;
        index++;
    }

    if (gDungeon->unk181e8.unk18215 == 0 || gDungeon->unk1BDD4.unk1C06C == 3) {
        sub_8004AF0(TRUE, gUnknown_202EE8C, 0xA0, 0x20, gDungeonBrightness, gDungeon->colorRamp);
    }

    index += 32;
    color = gUnknown_202ECA4;
    count = 32;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, color, gDungeonBrightness, gDungeon->colorRamp);
        color++;
        index++;
    }

    if (r10) {
        index = 224;
        color = gDungeonNameBannerPalette->unk4;
        count = 16;
        for (i = 0; i < count; i++) {
            SetBGPaletteBufferColorRGB(index, color, r9, NULL);
            color++;
            index++;
        }
    }

    SetBGPaletteBufferColorRGB(248, &gFontPalette[8], gDungeonBrightness, NULL);

    color = ((struct DungeonPalFile*) gDungeon->paletFile)->unk4;
    index = 256;
    count = 208;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, color, gDungeonBrightness, gDungeon->colorRamp);
        nullsub_4(index, color, gDungeonBrightness, NULL);
        color++;
        index++;
    }
}

void BgColorCallNullsub4(void)
{
    s32 i, index, count;
    const RGB *color;

    color = ((struct DungeonPalFile*) gDungeon->paletFile)->unk4;
    index = 256;
    count = 208;
    for (i = 0; i < count; i++) {
        nullsub_4(index, color, gDungeonBrightness, NULL);
        color++;
        index++;
    }
}

void sub_803EA10(void)
{
    s32 i, index, count;
    const RGB *color;

    color= gDungeonPaletteFile->unk4;
    SetBGPaletteBufferColorRGB(0, &sBlackRgb, gDungeonBrightness, gDungeon->colorRamp);
    color++;
    index = 1;
    count = 159;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, color, gDungeonBrightness, gDungeon->colorRamp);
        color++;
        index++;
    }

    if (gDungeon->unk181e8.unk18215 == 0 || gDungeon->unk1BDD4.unk1C06C == 3) {
        sub_8004AF0(TRUE, gUnknown_202EE8C, 0xA0, 0x20, gDungeonBrightness, gDungeon->colorRamp);
    }

    index += 32;
    color = gUnknown_202ECA4;
    count = 32;
    for (i = 0; i < count; i++) {
        SetBGPaletteBufferColorRGB(index, color, gDungeonBrightness, gDungeon->colorRamp);
        color++;
        index++;
    }

    SetBGPaletteBufferColorRGB(248, &gFontPalette[8], gDungeonBrightness, NULL);
}

static const struct Windows gUnknown_80F62B0 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_0,
            .pos = {2, 15},
            .width = 26,
            .height = 5,
            .unk10 = 7,
            .unk12 = 0,
            .unk14 = NULL,
        },
        [1] = WINDOW_DUMMY,
        [2] = WINDOW_DUMMY,
        [3] = WINDOW_DUMMY,
    }
};

static const struct Windows gUnknown_80F6310 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 6,
            .height = 7,
            .unk10 = 7,
            .unk12 = 0,
            .unk14 = NULL,
        },
        [1] = WINDOW_DUMMY,
        [2] = WINDOW_DUMMY,
        [3] = WINDOW_DUMMY,
    }
};

static const struct Windows gUnknown_80F6370 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 6,
            .height = 7,
            .unk10 = 7,
            .unk12 = 0,
            .unk14 = NULL,
        },
        [1] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {10, 4},
            .width = 17,
            .height = 2,
            .unk10 = 2,
            .unk12 = 0,
            .unk14 = NULL,
        },
        [2] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 13},
            .width = 26,
            .height = 6,
            .unk10 = 6,
            .unk12 = 0,
            .unk14 = NULL,
        },
        [3] = WINDOW_DUMMY,
    }
};

static const struct Windows gUnknown_80F63D0 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 26,
            .height = 14,
            .unk10 = 18,
            .unk12 = 2,
            .unk14 = NULL,
        },
        [1] = WINDOW_DUMMY,
        [2] = WINDOW_DUMMY,
        [3] = WINDOW_DUMMY,
    }
};

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
            ShowWindows(NULL, TRUE, TRUE);
            break;
        case 0:
            sub_803EC94();
            ShowWindows(NULL, TRUE, TRUE);
            if (gUnknown_203B40C != 0) {
                sub_8040A84();
                sub_8040ABC(0);
            }
            break;
        case 3:
            ShowWindows(&gUnknown_80F62B0, TRUE, TRUE);
            if (gUnknown_203B40C != 0) {
                sub_8040ABC(1);
            }
            break;
        case 6:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            ShowWindows(&gUnknown_80F6310, TRUE, TRUE);
            break;
        case 7:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            ShowWindows(&gUnknown_80F6370, TRUE, TRUE);
            break;
        case 2:
        case 4:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ResetUnusedInputStruct();
            sub_803EC94();
            ShowWindows(NULL, TRUE, TRUE);
            break;
        case 5:
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
            }
            ShowWindows(NULL, TRUE, TRUE);
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
            ShowWindows(&gUnknown_80F63D0, FALSE, TRUE);
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

void sub_803ECB4(Windows *a0, bool8 a1)
{
    gUnknown_202EDD0 = 10;
    sub_8052210(0);
    ResetUnusedInputStruct();
    ShowWindows(a0, TRUE, a1);
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
    if (!EntityIsValid(gUnknown_202EDE8.unk4)) {
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
        SpriteSetY(&gUnknown_202EDDC, y);
        SpriteSetAffine1(&gUnknown_202EDDC, 0);
        SpriteSetAffine2(&gUnknown_202EDDC, 0);
        SpriteSetObjMode(&gUnknown_202EDDC, 0);
        SpriteSetMosaic(&gUnknown_202EDDC, 0);
        SpriteSetBpp(&gUnknown_202EDDC, 0);
        SpriteSetShape(&gUnknown_202EDDC, 1);
        SpriteSetX(&gUnknown_202EDDC, x);
        SpriteSetMatrixNum(&gUnknown_202EDDC, 0);
        SpriteSetSize(&gUnknown_202EDDC, 1);
        SpriteSetTileNum(&gUnknown_202EDDC, 0x216);
        SpriteSetPriority(&gUnknown_202EDDC, gDungeon->unk181e8.priority);
        SpriteSetPalNum(&gUnknown_202EDDC, gUnknown_202EDE8.unk2);

        SpriteSetUnk6_0(&gUnknown_202EDDC, 0);
        SpriteSetUnk6_1(&gUnknown_202EDDC, 0);
        SpriteSetUnk6_2(&gUnknown_202EDDC, 0);

        AddSprite(&gUnknown_202EDDC, 0x100, NULL, NULL);
    }
}

extern OpenedFile *gUnknown_202EC9C;

static const s32 gUnknown_80F6430[][9] =
{
    [0] = {900, 800, 700, 600, 500, 400, 300, 200, 100},
    [1] = {90, 80, 70, 60, 50, 40, 30, 20, 10},
};

s32 sub_803EF90(s32 a0, u8 a1)
{
    s32 i, id;
    const u32 *r2;
    s32 bitsNo;
    s32 ret;
    bool8 unkBool;
    u32 *mainDst = gDungeon->unk18;
    u32 *sp[] = {(u32 *)(gUnknown_202EC9C->data + 0x124),
               (u32 *)(gUnknown_202EC9C->data + 0x104),
               (u32 *)(gUnknown_202EC9C->data + 0xE4),
               (u32 *)(gUnknown_202EC9C->data + 0xC4),
               (u32 *)(gUnknown_202EC9C->data + 0xA4),
               (u32 *)(gUnknown_202EC9C->data + 0x84),
               (u32 *)(gUnknown_202EC9C->data + 0x64),
               (u32 *)(gUnknown_202EC9C->data + 0x44),
               (u32 *)(gUnknown_202EC9C->data + 0x24)};
    s32 dstId = 0;
    u32 *clearDst = mainDst;
    for (i = 0; i < 4; i++) {
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
        clearDst[dstId++] = 0;
    }

    if (a0 == 9999) {
        u32 r12[] = {13, 14, 15, 15};

        bitsNo = 0;
        for (id = 0; id < 4; id++) {
            u32 *dst = mainDst;
            const u32 *src = (u32 *)((&((u8 *)gUnknown_202EC9C->data)[4] + r12[id] * 32));

            for (i = 0; i < 8; i++) {
                u32 toOr1, toOr2;
                if (bitsNo == 0) {
                    toOr1 = 0;
                    toOr2 = *src;
                }
                else {
                    toOr1 = *src >> (32 - bitsNo);
                    toOr2 = *src << bitsNo;
                }

                src++;
                dst[0] |= toOr2;
                dst[8] |= toOr1;
                dst++;
            }

            bitsNo += 24;
            if (bitsNo >= 32) {
                bitsNo -= 32;
                mainDst += 8;
            }
        }

        return 4;
    }

    if (a0 > 999) a0 = 999;
    if (a0 < -999) a0 = -999;

    r2 = (u32 *)((u8 *)gUnknown_202EC9C->data + 0x184);
    if (a1) {
        if (a0 > 0) {
            r2 = (u32 *)((u8 *)gUnknown_202EC9C->data + 0x144);
        }
        else if (a0 < 0) {
            r2 = (u32 *)((u8 *)gUnknown_202EC9C->data + 0x164);
            a0 = -a0;
        }
    }

    mainDst[0] = *r2++;
    mainDst[1] = *r2++;
    mainDst[2] = *r2++;
    mainDst[3] = *r2++;
    mainDst[4] = *r2++;
    mainDst[5] = *r2++;
    mainDst[6] = *r2++;
    mainDst[7] = *r2++;

    bitsNo = 24;
    ret = 1;
    unkBool = FALSE;
    for (id = 0; id < 2; id++) {
        s32 arrId;

        for (arrId = 0; arrId < 9; arrId++) {
            if (gUnknown_80F6430[id][arrId] <= a0) {
                const u32 *src = sp[arrId];
                u32 *dst = mainDst;

                for (i = 0; i < 8; i++) {
                    u32 toOr1, toOr2;
                    if (bitsNo == 0) {
                        toOr1 = 0;
                        toOr2 = *src;
                    }
                    else {
                        toOr1 = *src >> (32 - bitsNo);
                        toOr2 = *src << bitsNo;
                    }

                    src++;
                    dst[0] |= toOr2;
                    dst[8] |= toOr1;
                    dst++;
                    unkBool = TRUE;
                }

                bitsNo += 24;
                if (bitsNo >= 32) {
                    bitsNo -= 32;
                    mainDst += 8;
                }

                a0 -= gUnknown_80F6430[id][arrId];
                ret++;
                break;
            }
        }

        if (arrId == 9 && unkBool) {
            const u32 *src = (u32 *)(&((u8 *)gUnknown_202EC9C->data)[4]);
            u32 *dst = mainDst;
            for (i = 0; i < 8; i++) {
                u32 toOr1, toOr2;
                if (bitsNo == 0) {
                    toOr1 = 0;
                    toOr2 = *src;
                }
                else {
                    toOr1 = *src >> (32 - bitsNo);
                    toOr2 = *src << bitsNo;
                }

                src++;
                dst[0] |= toOr2;
                dst[8] |= toOr1;
                dst++;
            }

            bitsNo += 24;
            if (bitsNo >= 32) {
                bitsNo -= 32;
                mainDst += 8;
            }

            ret++;
        }
    }

    {
        const u32 *src = (u32 *)(&((u8 *)gUnknown_202EC9C->data)[4] + (a0 * 32));
        u32 *dst = mainDst;
        for (i = 0; i < 8; i++) {
            u32 toOr1, toOr2;
            if (bitsNo == 0) {
                toOr1 = 0;
                toOr2 = *src;
            }
            else {
                toOr1 = *src >> (32 - bitsNo);
                toOr2 = *src << bitsNo;
            }

            src++;
            dst[0] |= toOr2;
            dst[8] |= toOr1;
            dst++;
        }
    }

    ret++;
    return ret;
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
        strPtr->unk1820D = FALSE;
        strPtr->unk18211 = 0;
        strPtr->unk1820E = FALSE;
        strPtr->unk1820B = 0;
        strPtr->unk1820C = 0;
    }

    strPtr->cameraTarget = NULL;
    strPtr->priority = 3;
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
    s32 palId;
    UnkDungeonGlobal_unk181E8_sub *strPtr = &gDungeon->unk181e8;

    strPtr->unk3A = -1;
    strPtr->unk3C = -1;
    strPtr->unk3E = -1;
    strPtr->unk40 = -1;
    strPtr->unk36 = -1;
    strPtr->unk38 = -1;

    palId = (gGameOptionsRef->playerGender != MALE) ? 4 : 0;

    SetBGPaletteBufferColorArray(0xFD, &gFontPalette[16 * palId + 13]);
    SetBGPaletteBufferColorArray(0xFE, &gFontPalette[16 * palId + 14]);
    SetBGPaletteBufferColorArray(0xFF, &gFontPalette[16 * palId + 15]);

    nullsub_5(0xFD, &gFontPalette[16 * palId + 13]);
    nullsub_5(0xFE, &gFontPalette[16 * palId + 14]);
    nullsub_5(0xFF, &gFontPalette[16 * palId + 15]);
}

bool8 sub_803F428(DungeonPos *pos)
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

    if (cameraTarget != NULL && EntityIsValid(cameraTarget)) {
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
            strPtr->unk1820D = TRUE;
            strPtr->unk1820E = TRUE;
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
            if (info->blinkerClassStatus.status == STATUS_BLINKER) {
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
        if (info->blinkerClassStatus.status == STATUS_CROSS_EYED) {
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
                Entity *mon = gDungeon->activePokemon[i];
                if (EntityIsValid(mon)) {
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
    const Tile *tile = GetTile(strPtr->cameraPos.x, strPtr->cameraPos.y);
    u32 roomId = tile->room;

    if (strPtr->unk1820B != 0 || strPtr->unk1820C != 0 || strPtr->unk18217 != 0) {
        sub_8005838(NULL, 0);
    }
    else if (roomId == CORRIDOR_ROOM) {
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
    strPtr->unk1820D = FALSE;
    strPtr->unk1820E = FALSE;
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

    gUnknown_20274A5 = TRUE;
}

IWRAM_DATA static u32 gUnknown_3001018[96] = {0};

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
    sub_80098BC((void *) VRAM + 0x5980, gUnknown_3001018, sizeof(gUnknown_3001018));
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
        SetBGPaletteBufferColorArray(0xFC, &gFontPalette[12 + r5]);
        SetBGPaletteBufferColorArray(0xFD, &gFontPalette[13 + r5]);
        SetBGPaletteBufferColorArray(0xFE, &gFontPalette[14 + r5]);
        SetBGPaletteBufferColorArray(0xFF, &gFontPalette[15 + r5]);
    }

    if (strPtr->unk38 != r6) {
        strPtr->unk38 = r6;
        nullsub_5(0xFC, &gFontPalette[12 + r6]);
        nullsub_5(0xFD, &gFontPalette[13 + r6]);
        nullsub_5(0xFE, &gFontPalette[14 + r6]);
        nullsub_5(0xFF, &gFontPalette[15 + r6]);
    }

    arrPtr = gUnknown_202B038[0][0];
    unkFloor = gDungeon->unk14 + gDungeon->unk644.dungeonLocation.floor;
    if (strPtr->unk3A != unkFloor) {
        strPtr->unk3A = unkFloor;
        if (IsStairDirectionUp(gDungeon->unk644.dungeonLocation.id)) {
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
                ASM_MATCH_TRICK(a1);
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
