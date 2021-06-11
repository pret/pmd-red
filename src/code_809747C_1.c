#include "global.h"
#include "dungeon.h"

extern u8 sub_80A2728(s16);
extern const char gFinalScenarioText[];
extern const char gMeetNinetalesText[];
extern const char gAvoidCaptureText[];
extern u8 sub_8001D08(u32, u32 ,s32);
extern bool8 sub_809761C(void);
extern u32 sub_8001784(u32, u32, u16);
extern void sub_800199C(u32, u32, u32, u32);
extern bool8 sub_809758C(s16);

const u8 *sub_80975C4(s16 r0)
{
    return GetDungeonName1(sub_80A2728(r0));
}

const char *sub_80975DC(u32 r0)
{
    // TODO: slight hack but matches
    r0 <<= 16;
    if((0xffe90000 + r0) >> 16 < 2)
        if(sub_8001D08(0x3, 0xE, -1) != 0)
            return gMeetNinetalesText;
        else
            return gAvoidCaptureText;
    else
        return gFinalScenarioText;
}

bool8 sub_809761C(void)
{
    s32 iVar2;
    for(iVar2 = 0; iVar2 < 17; iVar2++)
    {
        if(!sub_809758C(iVar2))
            return FALSE;
    }
    return TRUE;
}

u32 sub_8097640(void)
{
    if(sub_8001784(0, 0x2E, 0x1F) == 0 && sub_809761C())
    {
        sub_800199C(0, 0x2E, 0x1F, 1);
        return 1;
    }
    else
    {
        return 0;
    }
}
