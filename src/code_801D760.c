#include "global.h"

extern u32 sub_801BF48(void);
extern void sub_801BF98(void);
extern void sub_801D208(u8);
extern u32 sub_801DCE8(void);
extern void sub_801DD50(void);
extern u32 sub_80217EC(void);
extern void sub_8021830(void);
extern u32 sub_8022860();
extern void sub_8022908();
extern u32 sub_80244E4(void);
extern void sub_802453C(void);
extern u32 sub_8025354(void);
extern u8 sub_802540C(void);
extern void sub_8025418(void);
extern u32 sub_8025F68();
extern u8 sub_802604C();
extern void sub_8026058();
extern void sub_8027168();
extern u32 sub_80270A4();
extern u32 sub_802C898(void);
extern void sub_802C8F4(void);

struct unk_203B250
{
    u32 unk0;
    u16 unk4;
    u8 unk6;
    u8 unk7;
    u32 padding[3];
    u32 unk14;
    u32 unk18;
};

struct unk_203B250 *gUnknown_203B250;

void sub_801D760()
{
    u32 temp;
    temp = sub_8022860();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    sub_8022908();
    sub_801D208(1);

}

void sub_801D77C()
{
    u32 temp;
    temp = sub_80270A4();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    sub_8027168();
    sub_801D208(1);

}

void sub_801D798(void)
{
    u32 temp;
    temp = sub_8025F68();
    if (temp <= 1)
        return;
    if (temp > 3)
        return;
    if(sub_802604C() != 0)
        gUnknown_203B250->unk7 = gUnknown_203B250->unk6;
    sub_8026058();
    sub_801D208(2);
}

void sub_801D7CC()
{
    u32 check;
    u32 temp2;

    check = sub_8025354();
    if(check <= 1)
        return;
    if(check > 3)
        return;

    temp2 = sub_802540C();
    gUnknown_203B250->unk7 = temp2;

    sub_8025418();

    if(gUnknown_203B250->unk7 != 0)
    {
        sub_801D208(2);
    }
    else
    {
        sub_801D208(1);
    }
}

void sub_801D808(void)
{
    u32 check;

    check = sub_80244E4();
    if(check <= 1)
        return;
    if(check > 3)
        return;

    sub_802453C();
    sub_801D208(1);
}

void sub_801D824(void)
{
    u32 check;
    check = sub_801BF48();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_801BF98();
    sub_801D208(1);
}

void sub_801D840(void)
{
    u32 check;
    check = sub_80217EC();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_8021830();
    sub_801D208(1);
}

void sub_801D85C(void)
{
    u32 check;
    check = sub_802C898();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_802C8F4();
    sub_801D208(1);
}

void sub_801D878(void)
{
    u32 check;
    check = sub_801DCE8();
    if(check <= 1)
        return;
    if(check > 3)
        return;
    sub_801DD50();
    sub_801D208(1);
}
