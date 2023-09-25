#include "global.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "code_80130A8.h"
#include "game_options.h"
#include "input.h"
#include "sprite.h"

extern void nullsub_8(u8);
extern void xxx_call_update_bg_vram();

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