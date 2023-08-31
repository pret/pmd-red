#include "global.h"
#include "bg_control.h"
#include "code_800558C.h"

extern u8 gUnknown_2026E38;
extern u32 *gUnknown_2026E3C;
extern u16 gUnknown_2026E4E;
extern bool32 gUnknown_2026E50;
extern bool32 gUnknown_2026E54;
extern u32 *gUnknown_2026E58;

UNUSED static void sub_80060A8(void)
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
    SetBldAlphaReg((gUnknown_2026E4E & 0x1F00) >> 8, gUnknown_2026E4E & 0x1F);
    gUnknown_2026E38 = TRUE;
}
