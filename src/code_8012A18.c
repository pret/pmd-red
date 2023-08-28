#include "global.h"
#include "code_800558C.h"
#include "code_80118A4.h"
#include "game_options.h"
#include "input.h"
#include "sprite.h"

extern void xxx_draw_string_80144C4();
extern void nullsub_8(u8);
extern void sub_800CB20();
extern void TransferBGPaletteBuffer();
extern void xxx_call_update_bg_vram();
extern void sub_8009908();
extern void xxx_call_update_bg_sound_input();

extern struct GameOptions *gGameOptionsRef;


void sub_8012A18()
{
    sub_8011860();
    xxx_draw_string_80144C4();
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    sub_800CB20();
    LoadBufferedInputs(); // Input related
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    ResetSprites(FALSE);
}

