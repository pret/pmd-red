#include "global.h"
#include "code_800558C.h"
#include "input.h"

struct UnkStruct_203B46C
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u8 unkA;
};


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

extern struct UnkStruct_203B46C *gUnknown_203B46C;


void sub_8012A18()
{
    sub_8011860();
    xxx_draw_string_80144C4();
    nullsub_8(gUnknown_203B46C->unkA);
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

