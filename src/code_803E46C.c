#include "global.h"
#include "globaldata.h"
#include "structs/str_dungeon.h"
#include "bg_control.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_803E724.h"
#include "dungeon_map.h"
#include "dungeon_music.h"
#include "game_options.h"
#include "input.h"
#include "play_time.h"
#include "sprite.h"
#include "text_2.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"

extern s32 gDungeonBrightness;
extern s32 gDungeonFramesCounter;
extern u32 gUnknown_202EDD0;
extern s32 gUnknown_202EDD4;

static void sub_803E490(u32);
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
void sub_803E874(s32, s32);

struct Unk80F6224Struct
{
    s32 shape;
    s32 size;
    s32 tileNum;
};

extern const struct Unk80F6224Struct gUnknown_80F621C[2][6];

extern const DungeonPos gUnknown_80F61EC[2][6];

EWRAM_DATA struct unkStruct_202ED28 gUnknown_202ED28[2][6] = {0};
EWRAM_DATA SpriteOAM gUnknown_202EDB8 = {0};
EWRAM_DATA SpriteOAM gUnknown_202EDC0 = {0};

EWRAM_INIT u8 gUnknown_203B40C = 0;
EWRAM_INIT u8 gUnknown_203B40D = 0;

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
