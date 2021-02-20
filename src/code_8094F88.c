#include "global.h"
#include "time.h"

extern struct PlayTimeStruct *gPlayTimeRef;
extern struct PlayTimeStruct gPlayTime;

extern u8 gUnknown_2038C88;
extern u8 gUnknown_2039288;
extern u32 gUnknown_20392E8;
extern u32 gUnknown_20393C0;
extern u8 *gUnknown_203B480;
extern u8 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern u32 *gUnknown_203B48C;


extern void sub_809488C(u32 *r0, u32 *r1, u32);
extern void sub_8094924(u32 *r0, u32 *r1, u32);


void InitializePlayTime(void)
{
    gPlayTimeRef = &gPlayTime;
    ResetPlayTime(&gPlayTime);
}

struct PlayTimeStruct *GetPlayTime(void)
{
    return &gPlayTime;
}

void ResetPlayTime(struct PlayTimeStruct *Time)
{
    Time->frames = 0;
    Time->seconds = 0;
    Time->minutes = 0;
    Time->hours = 0;
}

void IncrementPlayTime(struct PlayTimeStruct *Time)
{
    u16 temp_store16;

    Time->frames++;
    if(Time->frames <= 59)
        return;
    Time->frames = 0;

    Time->seconds++;
    if(Time->seconds <= 59)
        return;
    Time->seconds = 0;

    Time->minutes++;
    if(Time->minutes <= 59)
        return;
    Time->minutes = 0;

    // Casting here for unsigned comparison
    temp_store16 = Time->hours;
    if(Time->hours <= 9998)
    {
        temp_store16++;
        Time->hours = temp_store16;
    }
    else
    {
        Time->seconds = 59;
        Time->minutes = 59;
        Time->hours= 9999;
    }
}

void DeconstructPlayTime(struct PlayTimeStruct *r0, u32 *outHours, u32 *outMinutes, u32 *outSeconds)
{
    if(r0->hours <= 9999)
    {
        *outHours = r0->hours;
        *outMinutes = r0->minutes;
        *outSeconds = r0->seconds;
    }
    else
    {
        *outHours = 9999;
        *outMinutes = 59;
        *outSeconds = 59;
    }
}

void sub_8095044(u32 *r0)
{
    sub_809488C(r0, (u32 *)(&(gPlayTimeRef->frames)), 6);
    sub_809488C(r0, (u32 *)(&(gPlayTimeRef->seconds)), 6);
    sub_809488C(r0, (u32 *)(&(gPlayTimeRef->minutes)), 6);
    sub_809488C(r0, (u32 *)(&(gPlayTimeRef->hours)), 14);
}

void sub_8095080(u32 *r0)
{
    sub_8094924(r0, (u32 *)(&(gPlayTimeRef->frames)), 6);
    sub_8094924(r0, (u32 *)(&(gPlayTimeRef->seconds)), 6);
    sub_8094924(r0, (u32 *)(&(gPlayTimeRef->minutes)), 6);
    sub_8094924(r0, (u32 *)(&(gPlayTimeRef->hours)), 14);
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


