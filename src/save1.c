#include "global.h"


struct UnkSaveStruct1
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u8 unkA;
};

struct UnkStruct
{
    /* 0x0 */ u8 unk0;
    /* 0x1 */ u8 unk1;
    /* 0x2 */ u8 unk2;
    /* 0x3 */ u8 unk3;
    /* 0x4 */ u8 unk4;
    /* 0x5 */ u32 unk5;
    /* 0x9 */ u32 unk9;
    /* 0xD */ u32 unkD;
    /* 0x12 */ u32 unk11;
    /* 0x16 */ u32 unk15;
    /* 0x1A */ u32 unk19;
    /* 0x1E */ u32 unk1D;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ u8 unk29;
    /* 0x2A */ u8 unk2A;
    /* 0x2B */ u8 unk2B;
    /* 0x2C */ u8 unk2C;
};

extern void MemoryFree(void *);
extern void sub_8011860();
extern void xxx_draw_string_80144C4();
extern void nullsub_8(u8);
extern void sub_8005180();
extern void sub_80060EC();
extern void sub_800CB20();
extern void sub_800485C();
extern void CopySpritesToOam();
extern void sub_8005304();
extern void TransferBGPaletteBuffer();
extern void xxx_call_update_bg_vram();
extern void sub_8009908();
extern void xxx_call_update_bg_sound_input();
extern void ResetSprites(u8 r0);
extern u32 sub_8012AE8(void);
extern void nullsub_34(struct UnkStruct *r0);

extern struct UnkSaveStruct1 *gUnknown_203B46C;

extern u8 *gUnknown_203B194;

void sub_80129FC()
{
    if (gUnknown_203B194) {
        MemoryFree(gUnknown_203B194);
        gUnknown_203B194 = NULL;
    }
}

void sub_8012A18()
{
    sub_8011860();
    xxx_draw_string_80144C4();
    nullsub_8(gUnknown_203B46C->unkA);
    sub_8005180();
    sub_80060EC();
    sub_800CB20();
    sub_800485C();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    ResetSprites(0);
}

u32 sub_8012A64(struct UnkStruct *r0, u32 r1)
{
    if(r0 == NULL)
    {
        return sub_8012AE8();
    }
    if(r1 != -1)
    {
        nullsub_34(r0);
    }
    if(r0->unk1 != 0)
    {
        r0->unk1 = 0;
        return 1;
    }
    if(r0->unk2 == 0)
    {
        return sub_8012AE8();
    }
    r0->unk2 = r0->unk1;
    return 2;
}

// TODO match that one line
//u32 GetKeyPress(struct UnkStruct *r0)
//{
//    if(r0 == NULL)
//    {
//        return sub_8012AE8();
//    }
//    // TODO it's not a struct access..
//    if(r0->unk29 != 0)
//    {
//        return 1;
//    }
//    if(r0->unk2A != 0)
//    {
//        return 2;
//    }
//    if(r0->unk2C != 0)
//    {
//        return 9;
//    }
//    if(r0->unk2B == 0)
//    {
//        return sub_8012AE8();
//    }
//    return 0xA;
//}
