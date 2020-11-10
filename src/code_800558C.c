#include "global.h"
#include "code_800558C.h"

extern u32 gUnknown_203B47C;

extern u8 gUnknown_2026E38;
extern u32 gUnknown_2026E3C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 gUnknown_2026E58;

extern void sub_800CC44(s32 r0, s32 r1);

// Unused
void sub_80060A8(void)
{

    bool32 temp;
    bool32 preload;
    bool32 preload2;

    gUnknown_2026E3C = gUnknown_2026E58;

    preload = gUnknown_2026E54;
    temp = FALSE;
    if (!gUnknown_2026E54)
    {
        temp = TRUE;
    }
    gUnknown_2026E54 = temp;

    preload2 = gUnknown_2026E50;
    temp = FALSE;
    if (!gUnknown_2026E50)
    {
        temp = TRUE;
    }
    gUnknown_2026E50 = temp;
    
    gUnknown_2026E38 = FALSE;
}

void sub_80060EC(void)
{
    bool32 temp;
    bool32 preload;
    bool32 preload2;

    gUnknown_2026E3C = gUnknown_2026E58;

    preload = gUnknown_2026E54;
    temp = FALSE;

    if (!gUnknown_2026E54)
    {
        temp = TRUE;
    }
    gUnknown_2026E54 = temp;

    
    preload2 = gUnknown_2026E50;
    temp = FALSE;

    if (!gUnknown_2026E50)
    {
        temp = TRUE;
    }
    gUnknown_2026E50 = temp;
    
    sub_800CC44((gUnknown_2026E4E & (0xF8 << 5)) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = TRUE;
}
