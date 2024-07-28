#include "global.h"
#include "code_803E668.h"

#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_803E46C.h"
#include "game_options.h"
#include "input.h"
#include "play_time.h"
#include "sprite.h"
#include "structs/str_dungeon.h"

extern s32 gUnknown_202EDCC;
extern s32 gUnknown_202EDD4;

extern void xxx_call_update_bg_vram(void);

void sub_803E668(u32 a0)
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
