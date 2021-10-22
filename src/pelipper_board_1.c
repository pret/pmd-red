#include "global.h"
#include "mailbox.h"

extern u8 gPelipperBoard_Accepted[];
extern u8 gUnknown_80E03B8[];
extern void xxx_call_draw_string(s32 x, u32 y, u8 *, u32 , u32);
extern void sub_8012BC4(u32 x, u32 y, u32, u32, u32, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_80073E0(u32);
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);
extern void SetPelipperBoardState(u32);
extern u32 sub_802DEE0(void);
extern void sub_802DF24(void);


void sub_802EEA0(void)
{
    switch(sub_802DEE0())
    {
        case 2:
        case 3:
            sub_802DF24();
            SetPelipperBoardState(5);
        case 0:
        case 1:
            break;
    }
}

void sub_802EEBC(void)
{
    switch(sub_802C898())
    {
        case 2:
        case 3:
            sub_802C8F4();
            SetPelipperBoardState(1);
        case 0:
        case 1:
            break;
    }
}


void nullsub_134(void)
{
}

void CreatePelipperAcceptedStatusBox(u32 r0)
{
    sub_8008C54(r0);
    sub_80073B8(r0);
    xxx_call_draw_string(3, 0, gPelipperBoard_Accepted, r0, 0);
    sub_8012BC4(0x12, 0xD, GetNumAcceptedJobs(), 2, 7, r0);
    xxx_call_draw_string(0x16, 0xD, gUnknown_80E03B8, r0, 0); // "/"
    sub_8012BC4(0x23, 0xD, MAX_ACCEPTED_JOBS, 2, 7, r0);
    sub_80073E0(r0);
}
