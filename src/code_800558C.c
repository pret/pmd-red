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

    gUnknown_2026E3C = gUnknown_2026E58;
    gUnknown_2026E54 = !gUnknown_2026E54;
    gUnknown_2026E50 = !gUnknown_2026E50;
    gUnknown_2026E38 = FALSE;
}

void sub_80060EC(void)
{
    gUnknown_2026E3C = gUnknown_2026E58;
    gUnknown_2026E54 = !gUnknown_2026E54;
    gUnknown_2026E50 = !gUnknown_2026E50;
    sub_800CC44((gUnknown_2026E4E & (0xF8 << 5)) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = TRUE;
}
