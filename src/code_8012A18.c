#include "global.h"
#include "bg_palette_buffer.h"
#include "code_800558C.h"
#include "graphics_memory.h"
#include "code_800C9CC.h"
#include "music_util.h"
#include "string_format.h"
#include "game_options.h"
#include "sprite.h"
#include "text_2.h"

void sub_8012A18()
{
    UpdateSoundEffectCounters();
    DrawDialogueBoxString();
    nullsub_8(gGameOptionsRef->touchScreen);
    sub_8005180();
    sub_80060EC();
    WaitForNextFrameAndAdvanceRNG();
    LoadBufferedInputs(); // Input related
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    DoScheduledMemCopies();
    xxx_call_update_bg_sound_input();
    ResetSprites(FALSE);
}