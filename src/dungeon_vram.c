#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "structs/str_dungeon.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_803E668.h"
#include "code_803E724.h"
#include "dungeon_map.h"
#include "dungeon_music.h"
#include "game_options.h"
#include "input.h"
#include "play_time.h"
#include "sprite.h"
#include "text_1.h"
#include "text_2.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_logic.h"
#include "dungeon_range.h"
#include "dungeon_util.h"
#include "menu_input.h"
#include "code_801602C.h"

// File split is correct. This technical file deals with windows, advancing frames(v-blanks) and vram / pal set-up.

struct DungeonPalFile
{
    void *unk0;
    const void *unk4;
};

extern struct DungeonPalFile *gDungeonPaletteFile;
extern struct DungeonPalFile *gDungeonNameBannerPalette;
extern struct DungeonPalFile *gUnknown_202EC94;
extern RGB gUnknown_202ECA4[];
extern MenuInputStruct gDungeonMenu;
extern SpriteOAM gUnknown_202EDDC;
extern OpenedFile *gUnknown_202EC9C;

void xxx_draw_string_80524F0(void);
void sub_8085F78(void);
void sub_803F580(s32);
void sub_806CC10();
void sub_804522C();
void sub_803F9CC();
void sub_803ECE0();
void sub_803EDF0();
void sub_800E90C();
void sub_8042E5C();
void sub_800F7D0(DungeonPos *);

static void sub_803E490(u32);
static s32 sub_803EF90(s32 a0, u8 a1);
static void sub_803EC94(void);
void sub_803E874(bool8 r10, s32 r9);

EWRAM_DATA struct unkStruct_202ED28 gUnknown_202ED28[2][6] = {0};
EWRAM_DATA SpriteOAM gUnknown_202EDB8 = {0};
EWRAM_DATA SpriteOAM gUnknown_202EDC0 = {0};
EWRAM_DATA s32 gDungeonBrightness = 0;
EWRAM_DATA s32 gDungeonFramesCounter = 0;
EWRAM_DATA s32 gUnknown_202EDD0 = 0;
EWRAM_DATA s32 gUnknown_202EDD4 = 0;
EWRAM_DATA s32 gUnknown_202EDD8 = 0;

EWRAM_INIT u8 gUnknown_203B40C = 0;
EWRAM_INIT u8 gUnknown_203B40D = 0;

static const DungeonPos gUnknown_80F61EC[2][6] = {
    [0] = {{-4, -4}, {-8, -4}, {-16, -4}, {-16, -4}, {-16, -4}, {-16, -4}},
    [1] = {{-4, -4}, {-8, -4}, {-16, -8}, {-16, -8}, {-16, -8}, {-16, -8}},
};

struct SpriteInfo
{
    s32 shape;
    s32 size;
    s32 tileNum;
};

static const struct SpriteInfo gUnknown_80F621C[2][6] = {
    [0] = {{0, 0, 0x200}, {1, 0, 0x201}, {1, 1, 0x203}, {1, 1, 0x223}, {1, 1, 0x223}, {1, 1, 0x223}},
    [1] = {{0, 0, 0x207}, {1, 0, 0x208}, {1, 2, 0x20A}, {1, 2, 0x22A}, {1, 2, 0x22A}, {1, 2, 0x22A}},
};

void sub_803E250(void)
{
    s32 i, j;

    gUnknown_202EDD0 = 999;
    gUnknown_202EDD4 = 0;
    gUnknown_203B40D = 0;
    gUnknown_202EDE8.unk0 = 0;

    SpriteSetY(&gUnknown_202EDC0, 0);
    SpriteSetAffine1(&gUnknown_202EDC0, 0);
    SpriteSetAffine2(&gUnknown_202EDC0, 0);
    SpriteSetObjMode(&gUnknown_202EDC0, 0);
    SpriteSetMosaic(&gUnknown_202EDC0, 0);
    SpriteSetBpp(&gUnknown_202EDC0, 0);
    SpriteSetShape(&gUnknown_202EDC0, 0);
    SpriteSetMatrixNum(&gUnknown_202EDC0, 0);
    SpriteSetSize(&gUnknown_202EDC0, 1);
    SpriteSetX(&gUnknown_202EDC0, 0);
    SpriteSetTileNum(&gUnknown_202EDC0, 0);
    SpriteSetPriority(&gUnknown_202EDC0, 0);
    SpriteSetPalNum(&gUnknown_202EDC0, 0);
    SpriteSetUnk6_0(&gUnknown_202EDC0, 0);
    SpriteSetUnk6_1(&gUnknown_202EDC0, 0);
    SpriteSetUnk6_2(&gUnknown_202EDC0, 0);

    SpriteSetY(&gUnknown_202EDB8, 0);
    SpriteSetAffine1(&gUnknown_202EDB8, 0);
    SpriteSetAffine2(&gUnknown_202EDB8, 0);
    SpriteSetObjMode(&gUnknown_202EDB8, 0);
    SpriteSetMosaic(&gUnknown_202EDB8, 0);
    SpriteSetBpp(&gUnknown_202EDB8, 0);
    SpriteSetShape(&gUnknown_202EDB8, 0);
    SpriteSetMatrixNum(&gUnknown_202EDB8, 0);
    SpriteSetSize(&gUnknown_202EDB8, 0);
    SpriteSetX(&gUnknown_202EDB8, 0);
    SpriteSetTileNum(&gUnknown_202EDB8, 0);
    SpriteSetPriority(&gUnknown_202EDB8, 3);
    SpriteSetPalNum(&gUnknown_202EDB8, 5);
    SpriteSetUnk6_0(&gUnknown_202EDB8, 0);
    SpriteSetUnk6_1(&gUnknown_202EDB8, 0);
    SpriteSetUnk6_2(&gUnknown_202EDB8, 0);

    for (i = 0; i < 2; i++) {
        for (j = 0; j < 6; j++) {
            SpriteSetAffine1(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetAffine2(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetObjMode(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetMosaic(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetBpp(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetShape(&gUnknown_202ED28[i][j].sprite, gUnknown_80F621C[i][j].shape);
            SpriteSetMatrixNum(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetSize(&gUnknown_202ED28[i][j].sprite, gUnknown_80F621C[i][j].size);
            SpriteSetTileNum(&gUnknown_202ED28[i][j].sprite, gUnknown_80F621C[i][j].tileNum);
            SpriteSetPriority(&gUnknown_202ED28[i][j].sprite, 3);
            SpriteSetPalNum(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetUnk6_0(&gUnknown_202ED28[i][j].sprite, 0);
            SpriteSetUnk6_1(&gUnknown_202ED28[i][j].sprite, 0);

            gUnknown_202ED28[i][j].pos = gUnknown_80F61EC[i][j];
        }
    }

    gDungeon->unk181e8.unk18217 = 1;
    gDungeon->unk181e8.unk18218 = 1;
    gDungeonBrightness = 0;
    SetBGPaletteBufferColorRGB(0xf8, &gFontPalette[8],0,NULL);
}

void DungeonRunFrameActions(u32 a0)
{
    if (gUnknown_203B40C != 0)
        sub_803E490(a0);
    else
        sub_803E668(a0);
}

static void sub_803E490(u32 unused)
{
    gUnknown_202EDD4++;
    xxx_draw_string_80524F0();
    sub_8085F78();
    sub_803F580(1);

    if(gDungeon->unk181e8.unk1821A)
    {
        gDungeon->unk181e8.priority = 2;
        SetBG2RegOffsets(gDungeon->unk181e8.cameraPixelPos.x, gDungeon->unk181e8.cameraPixelPos.y);
    }
    else
    {
        gDungeon->unk181e8.priority = 3;
        SetBG2RegOffsets(0, 0);
    }
    SetBG3RegOffsets(gDungeon->unk181e8.cameraPixelPos.x, gDungeon->unk181e8.cameraPixelPos.y - gDungeon->unk181e8.unk181FC);
    sub_806CC10();
    sub_804522C();
    sub_803F9CC();

    sub_800F7D0(&gDungeon->unk181e8.cameraPixelPos);

    if(gDungeon->unk12 <= 0x63)
        gDungeon->unk12++;

    sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
    sub_8042E5C();

    if(gUnknown_202EDD0 == 0 || gUnknown_202EDD0 == 3 || gGameOptionsRef->mapOption == TOP_MAP_AND_TEAM_NO_BOTTOM)
        ShowPlayerDotOnMap();
    sub_803ECE0();
    sub_803EDF0();


    if(gDungeon->unk181e8.unk18215 != 0 && gDungeon->unk1BDD4.unk1C06C != 3)
        sub_8004AF0(gUnknown_203B40D, gUnknown_202EE8C, 0xA0, 0x20, gDungeonBrightness, gDungeon->colorRamp);

    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    nullsub_12();
    sub_80060EC();

    gDungeonFramesCounter++;

    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    CopySpritesToOam();
    nullsub_13();
    sub_8005304();
    nullsub_14();

    TransferBGPaletteBuffer();
    sub_8009908();
    xxx_call_update_bg_vram();
    CopyDungeonMapToVram();
    xxx_call_update_bg_sound_input();

    gDungeon->unk181e8.unk18213 = 0;
    UpdateDungeonMusic();
    sub_8011860();
    TryResetDungeonMapTilesScheduledForCopy();
    ResetSprites(FALSE);
    nullsub_10(FALSE);
    gUnknown_202EDD4--;
}

void sub_803E668(u32 unused)
{
    gUnknown_202EDD4++;
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    nullsub_12();
    sub_8005838(NULL, 0);
    sub_80060EC();
    gDungeonFramesCounter++;
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs();
    CopySpritesToOam();
    nullsub_13();
    sub_8005304();
    nullsub_14();
    TransferBGPaletteBuffer();
    sub_8009908();
    xxx_call_update_bg_vram();
    xxx_call_update_bg_sound_input();
    gDungeon->unk181e8.unk18213 = 0;
    sub_8011860();
    ResetSprites(FALSE);
    nullsub_10(FALSE);
    gUnknown_202EDD4--;
}

void sub_803E708(s32 numFrames, u32 a1)
{
    while (numFrames != 0) {
        DungeonRunFrameActions(a1);
        numFrames--;
    }
}

void sub_803E724(s32 r0)
{
    do
    {
        DungeonRunFrameActions(r0);
    } while (gRealInputs.held & 0xF0);
}

void sub_803E748(void)
{
    s32 index1;
    s32 index2;

    index2 = 0x1F;
    gUnknown_203B40D = 1;
    gDungeonBrightness = 0;

    sub_803E874(1, 0x1F);

    for(index1 = 0; index1 < 0x2C; index1++)
    {
        if(index1 < 0x20)
        {
            index2 -= 2;
            if(index2 <= 0)
            {
                index2 = 0;
                sub_803EAF0(1, NULL);
                gDungeon->unk181e8.unk18217 = index2;
            }
        }
        if(index1 > 0xB)
            if(gDungeonBrightness <= 0x1E)
                gDungeonBrightness++;
        sub_803E874(1, index2);
        DungeonRunFrameActions(5);
    }
    gUnknown_203B40D = 0;
    gDungeonBrightness = 0x1F;
}

void sub_803E7C8(void)
{
    s32 index1;
    s32 index2;

    index2 = 0x1F;
    gUnknown_203B40D = 1;
    gDungeonBrightness = 0;

    DungeonRunFrameActions(5);

    for(index1 = 0; index1 < 0x2C; index1++)
    {
        sub_803E874(1, index2);
        if(index1 < 0x20)
        {
            index2 -= 2;
            if(index2 <= 0)
            {
                index2 = 0;
                sub_803EAF0(1, NULL);
                gDungeon->unk181e8.unk18217 = index2;
            }
        }
        DungeonRunFrameActions(5);
    }
    gUnknown_203B40D = 0;
}

void sub_803E830(void)
{
    s32 index;

    gUnknown_203B40D = 1;
    for(index = 0; index < 0x20; index++)
    {
        sub_803E874(0, 0);
        DungeonRunFrameActions(5);
        if(gDungeonBrightness > 0)
            gDungeonBrightness--;
    }
    gDungeonBrightness = 0;
    gUnknown_203B40D = 0;
}

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

static const WindowTemplates gUnknown_80F62B0 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_0,
            .pos = {2, 15},
            .width = 26,
            .height = 5,
            .unk10 = 7,
            .unk12 = 0,
            .header = NULL,
        },
        [1] = WIN_TEMPLATE_DUMMY,
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

static const WindowTemplates gUnknown_80F6310 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 6,
            .height = 7,
            .unk10 = 7,
            .unk12 = 0,
            .header = NULL,
        },
        [1] = WIN_TEMPLATE_DUMMY,
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

static const WindowTemplates gUnknown_80F6370 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 6,
            .height = 7,
            .unk10 = 7,
            .unk12 = 0,
            .header = NULL,
        },
        [1] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {10, 4},
            .width = 17,
            .height = 2,
            .unk10 = 2,
            .unk12 = 0,
            .header = NULL,
        },
        [2] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 13},
            .width = 26,
            .height = 6,
            .unk10 = 6,
            .unk12 = 0,
            .header = NULL,
        },
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

static const WindowTemplates gUnknown_80F63D0 =
{
    .id = {
        [0] = {
            .type = WINDOW_TYPE_NORMAL,
            .pos = {2, 3},
            .width = 26,
            .height = 14,
            .unk10 = 18,
            .unk12 = 2,
            .header = NULL,
        },
        [1] = WIN_TEMPLATE_DUMMY,
        [2] = WIN_TEMPLATE_DUMMY,
        [3] = WIN_TEMPLATE_DUMMY,
    }
};

// kind==8 uses the `name` param.
void sub_803EAF0(u32 kind, u8 *name)
{
    if (kind == gUnknown_202EDD0)
        return;

    switch (kind) {
        case 1: {
            if (gUnknown_203B40C != 0)
                sub_8052210(0);

            ResetUnusedInputStruct();
            sub_803EC94();
            ShowWindows(NULL, TRUE, TRUE);
            break;
        }
        case 0: {
            sub_803EC94();
            ShowWindows(NULL, TRUE, TRUE);
            if (gUnknown_203B40C != 0) {
                ShowWholeRevealedDungeonMap();
                UpdateBgTilemapForDungeonMap(FALSE);
            }
            break;
        }
        case 3: {
            ShowWindows(&gUnknown_80F62B0, TRUE, TRUE);
            if (gUnknown_203B40C != 0)
                UpdateBgTilemapForDungeonMap(TRUE);
            break;
        }
        case 6: {
            if (gUnknown_203B40C != 0)
                sub_8052210(0);

            ResetUnusedInputStruct();
            ShowWindows(&gUnknown_80F6310, TRUE, TRUE);
            break;
        }
        case 7: {
            if (gUnknown_203B40C != 0)
                sub_8052210(0);

            ResetUnusedInputStruct();
            ShowWindows(&gUnknown_80F6370, TRUE, TRUE);
            break;
        }
        case 2:
        case 4: {
            if (gUnknown_203B40C != 0)
                sub_8052210(0);

            ResetUnusedInputStruct();
            sub_803EC94();
            ShowWindows(NULL, TRUE, TRUE);
            break;
        }
        case 5: {
            if (gUnknown_203B40C != 0)
                sub_8052210(0);

            ShowWindows(NULL, TRUE, TRUE);
            break;
        }
        case 8: {
            if (gUnknown_203B40C != 0) {
                PlayDungeonStartButtonSE();
                sub_8052210(0);
            }

            CreateConfirmNameMenu(2, name);
            break;
        }
        case 9: {
            if (gUnknown_203B40C != 0) {
                sub_8052210(0);
                PlayDungeonStartButtonSE();
            }

            ResetUnusedInputStruct();
            ShowWindows(&gUnknown_80F63D0, FALSE, TRUE);
            break;
        }
        case 10: {
            PlayDungeonStartButtonSE();
            break;
        }
        case 150: { // Dummy case put here to match, any value >= 150 works
            break;
        }
    }

    gUnknown_202EDD0 = kind;
}

static void sub_803EC94(void)
{
    gDungeonMenu.unk1E = 0;
    gDungeonMenu.unk20 = 0;
    gDungeonMenu.unkC = 0;
    gDungeonMenu.unkE = 0;
    gDungeonMenu.unk14.x = 0;
    sub_801317C(&gDungeonMenu.unk28);
}

void DungeonShowWindows(WindowTemplates *a0, bool8 a1)
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

void sub_803ED30(s32 a0, Entity *mon, u8 a2, s32 a3)
{
    s32 i, var;

    if (a0 == 0 || gDungeon->unk181e8.blinded)
        return;

    for (i = 0; i < 20; i++) {
        if (gUnknown_202EDE8.unk0 == 0)
            break;
        DungeonRunFrameActions(0x29);
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

static const s32 gUnknown_80F6430[][9] =
{
    [0] = {900, 800, 700, 600, 500, 400, 300, 200, 100},
    [1] = {90, 80, 70, 60, 50, 40, 30, 20, 10},
};

static s32 sub_803EF90(s32 a0, u8 a1)
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
