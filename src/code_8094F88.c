#include "global.h"
#include "time.h"

extern struct PlayTimeStruct *gUnknown_203B47C;
extern struct PlayTimeStruct gPlayTime;

extern u8 gUnknown_2038C88;
extern u8 gUnknown_2039288;
extern u32 gUnknown_20392E8;
extern u32 gUnknown_20393C0;
extern u8 *gUnknown_203B480;
extern u8 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern u32 *gUnknown_203B48C;


extern void sub_809488C(u32, u32, u32);
extern void sub_8094924(u32, u32, u32);


// Forward Declaration
void ResetPlayTime(struct PlayTimeStruct *Time);


void sub_8094F88(void)
{
    gUnknown_203B47C = &gPlayTime;
    ResetPlayTime(&gPlayTime);
}

struct PlayTimeStruct *sub_8094FA0(void)
{
    return &gPlayTime;
}

void ResetPlayTime(struct PlayTimeStruct *Time)
{
    Time->seconds = 0;
    Time->minutes = 0;
    Time->hours = 0;
    Time->unk0 = 0;
}

void sub_8094FB4(struct PlayTimeStruct *Time)
{
    u16 temp_store16;

    Time->seconds++;
    if(Time->seconds <= 59)
        return;
    Time->seconds = 0;

    Time->minutes++;
    if(Time->minutes <= 59)
        return;
    Time->minutes = 0;

    Time->hours++;
    if(Time->hours <= 59)
        return;
    Time->hours = 0;

    // ???
    temp_store16 = Time->unk0;
    if(Time->unk0 <= 9998)
    {
        temp_store16++;
        Time->unk0 = temp_store16;
    }
    else
    {
        Time->minutes = 59;
        Time->hours = 59;
        Time->unk0 = 9999;
    }
}

void sub_8095014(struct PlayTimeStruct *r0, u32 *r1, u32 *r2, u32 *r3)
{
    u32 temp;
    if(r0->unk0 <= 9999)
    {
        *r1 = r0->unk0;
        *r2 = r0->hours;
        temp = r0->minutes;
    }
    else
    {
        *r1 = 9999;
        *r2 = 59;
        temp = 59;
    }
    *r3 = temp;
}

void sub_8095044(u32 r0)
{
    sub_809488C(r0, (u32)(gUnknown_203B47C) + 4, 0x6);
    sub_809488C(r0, (u32)(gUnknown_203B47C) + 3, 0x6);
    sub_809488C(r0, (u32)(gUnknown_203B47C) + 2, 0x6);
    sub_809488C(r0, (u32)(gUnknown_203B47C), 0xE);
}

void sub_8095080(u32 r0)
{
    sub_8094924(r0, (u32)(gUnknown_203B47C) + 4, 0x6);
    sub_8094924(r0, (u32)(gUnknown_203B47C) + 3, 0x6);
    sub_8094924(r0, (u32)(gUnknown_203B47C) + 2, 0x6);
    sub_8094924(r0, (u32)(gUnknown_203B47C), 0xE);
}

void sub_80950BC(void)
{
    gUnknown_203B480 = &gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = &gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

u8 *sub_80950F8(void)
{
    return &gUnknown_2038C88;
}

u8 *sub_8095100(void)
{
    return &gUnknown_2039288;
}

u32 *sub_8095108(void)
{
    return &gUnknown_20392E8;
}

u32 *sub_8095110(void)
{
    return &gUnknown_20393C0;
}


