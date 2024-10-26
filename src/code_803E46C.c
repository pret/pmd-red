#include "global.h"
#include "structs/str_dungeon.h"
#include "code_803E46C.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_803E668.h"

#include "bg_palette_buffer.h"
#include "bg_control.h"
#include "dungeon_music.h"
#include "game_options.h"
#include "input.h"
#include "play_time.h"
#include "sprite.h"

extern u8 gUnknown_203B40C;
extern u8 gUnknown_203B40D;
extern s32 gUnknown_202EDC8;
extern s32 gUnknown_202EDCC;
extern u32 gUnknown_202EDD0;
extern s32 gUnknown_202EDD4;

extern void sub_803E490(u32);
void xxx_draw_string_80524F0(void);
void sub_8085F78(void);
void sub_803F580(s32);
void sub_806CC10();
void sub_804522C();
void sub_803F9CC();
extern void xxx_call_update_bg_vram(void);
void sub_8040894();
void sub_803ECE0();
void sub_803EDF0();
void sub_800E90C();
void sub_8042E5C();
void sub_8040B60();
void sub_8040788();
void sub_800F7D0(Position *);
void sub_803E874(s32, s32);
void sub_803EAF0(s32, s32);

void sub_803E46C(u32 a0)
{
    if (gUnknown_203B40C != 0)
        sub_803E490(a0);
    else
        sub_803E668(a0);
}

void sub_803E490(u32 unused)
{
    gUnknown_202EDD4++;
    xxx_draw_string_80524F0();
    sub_8085F78();
    sub_803F580(1);

    if(gDungeon->unk181e8.unk1821A)
    {
        gDungeon->unk181e8.unk18208 = 2;
        SetBG2RegOffsets(gDungeon->unk181e8.cameraPixelPos.x, gDungeon->unk181e8.cameraPixelPos.y);
    }
    else
    {
        gDungeon->unk181e8.unk18208 = 3;
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
        sub_8040894();
    sub_803ECE0();
    sub_803EDF0();


    if(gDungeon->unk181e8.unk18215 != 0 && gDungeon->unk1BDD4.unk1C06C != 3)
        sub_8004AF0(gUnknown_203B40D, gUnknown_202EE8C, 0xA0, 0x20, gUnknown_202EDC8, (u8 *)gDungeon->unk17C);

    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    nullsub_12();
    sub_80060EC();

    gUnknown_202EDCC++;

    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    nullsub_13();
    sub_8005304();
    nullsub_14();

    TransferBGPaletteBuffer();
    sub_8009908();
    xxx_call_update_bg_vram();
    sub_8040788();
    xxx_call_update_bg_sound_input();

    gDungeon->unk181e8.unk18213 = 0;
    UpdateDungeonMusic();
    sub_8011860();
    sub_8040B60();
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
    gUnknown_202EDCC++;
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
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

void sub_803E708(s32 a0, u32 a1)
{
    while (a0 != 0) {
        sub_803E46C(a1);
        a0--;
    }
}

void sub_803E724(s32 r0)
{
    do
    {
        sub_803E46C(r0);
    } while (gRealInputs.held & 0xF0);
}

void sub_803E748(void) {

    s32 index1;
    s32 index2;

    index2 = 0x1F;
    gUnknown_203B40D = 1;
    gUnknown_202EDC8 = 0;

    sub_803E874(1, 0x1F);

    for(index1 = 0; index1 < 0x2C; index1++)
    {
        if(index1 < 0x20)
        {
            index2 -= 2;
            if(index2 <= 0)
            {
                index2 = 0;
                sub_803EAF0(1, 0);
                gDungeon->unk181e8.unk18217 = index2;
            }
        }
        if(index1 > 0xB)
            if(gUnknown_202EDC8 <= 0x1E)
                gUnknown_202EDC8++;
        sub_803E874(1, index2);
        sub_803E46C(5);
    }
    gUnknown_203B40D = 0;
    gUnknown_202EDC8 = 0x1F;
}

void sub_803E7C8(void)
{

    s32 index1;
    s32 index2;

    index2 = 0x1F;
    gUnknown_203B40D = 1;
    gUnknown_202EDC8 = 0;

    sub_803E46C(5);

    for(index1 = 0; index1 < 0x2C; index1++)
    {
        sub_803E874(1, index2);
        if(index1 < 0x20)
        {
            index2 -= 2;
            if(index2 <= 0)
            {
                index2 = 0;
                sub_803EAF0(1, 0);
                gDungeon->unk181e8.unk18217 = index2;
            }
        }
        sub_803E46C(5);
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
        sub_803E46C(5);
        if(gUnknown_202EDC8 > 0)
            gUnknown_202EDC8--;
    }
    gUnknown_202EDC8 = 0;
    gUnknown_203B40D = 0;
}
