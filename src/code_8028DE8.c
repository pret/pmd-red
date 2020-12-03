#include "global.h"

extern u32 sub_80144A4(s32 *r0);
extern void sub_8028B04(u32);
extern void sub_8011C28(u32);
extern void sub_8012574(u32);
extern u8 sub_8012600();
extern void sub_8012750();
extern void sub_8095240(u8);

extern void sub_809927C(u8);
extern u32 *gUnknown_203B2C0;

void sub_8028DE8(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(r0);
}

void sub_8028E08(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x12);
}

void sub_8028E24(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x8:
            sub_8028B04(0x13);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E54(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    switch(temp)
    {
        case 0x8:
            sub_8028B04(0x14);
            break;
        case 0xA:
            sub_8028B04(1);
            break;
        default:
            break;
    }
}

void sub_8028E84(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x18);
    sub_8011C28(1);
    sub_8012574(0);
}

void sub_8028EAC(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(sub_8012600() == 0)
    {
        sub_8012750();
        sub_8028B04(0x19);
    }
}

void sub_8028ED4(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(temp == 8)
    {
        sub_8028B04(0xB);
    }
    else
    {
        switch(temp){
            case 0x8:
                sub_8028B04(0x2);
                break;
            case 0x9:
            case 0xA:
                sub_8028B04(0x2);
                break;
            default:
                break;
        }
    }
}

void sub_8028F04(u32 r0)
{
    s32 temp;
    s32 counter;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    for(counter = 0; counter <= 0x1F; counter++)
    {
        sub_8095240(counter);
    }
    sub_8028B04(0x15);
}

void sub_8028F30(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(0x16);
    sub_8011C28(1);
    sub_8012574(0);
}

void sub_8028F58(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    if(sub_8012600() == 0)
    {
        sub_8012750();
        sub_8028B04(2);
    }
}

void sub_8028F80(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_809927C(gUnknown_203B2C0[0x86]);
    gUnknown_203B2C0[335] = 1;
    sub_8028B04(3);
}

void sub_8028FC0(u32 r0)
{
    s32 temp;

    if(sub_80144A4(&temp) != 0)
    {
        return;
    }
    sub_8028B04(1);
}

