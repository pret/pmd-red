#include "global.h"

extern u32 sub_8022860();
extern void sub_8022908();
extern void sub_801D208(u8);
extern void sub_8027168();
extern u32 sub_80270A4();
extern u32 sub_8025F68();
extern u8 sub_802604C();
extern void sub_8026058();

struct unk_203B250
{
    u32 unk0;
    u16 unk4;
    u8 unk6;
    u8 unk7;
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
