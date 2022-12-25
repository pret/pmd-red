#include "global.h"
#include "code_800558C.h"
#include "input.h"
#include "game_options.h"

extern void sub_8011860();
extern void xxx_draw_string_80144C4();
extern void nullsub_8(u8);
extern void sub_8005180();
extern void sub_800CB20();
extern void CopySpritesToOam();
extern void sub_8005304();
extern void TransferBGPaletteBuffer();
extern void xxx_call_update_bg_vram();
extern void sub_8009908();
extern void xxx_call_update_bg_sound_input();
extern void ResetSprites(u8 r0);

extern struct GameOptions *gGameOptions;


void sub_8012A18()
{
    sub_8011860();
    xxx_draw_string_80144C4();
    nullsub_8(gGameOptions->unkA);
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
    ResetSprites(0);
}

