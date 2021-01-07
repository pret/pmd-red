#include "global.h"

struct unkDungeon_8041D5C
{
    u8 padding[0x70];
    u8 *unk70[100];
};

extern u32 gUnknown_80F89F4;
extern u32 gUnknown_202DF98;
extern u32 gUnknown_80FB580;

extern void sub_807D148(u32 r0, u32 r1, u32 r2, u32 r3);
extern void sub_8075FCC(void);
extern void sub_8077AE4(u32 r0, u32 r1, u32 r2);
extern void sub_8072008(u32 r0, u32 r1, u32 r2, u8 r3);
extern void sub_8076D10(void);
extern void sub_807232C(u32 r0, u32 r1, u32 r2);

extern void sub_8045B94(u32 *r0, struct unkDungeon_8041D5C *r1, u32);
extern void sub_807A290(u32);
extern void sub_80522F4(u32 r0, struct unkDungeon_8041D5C *r1, u32);

void sub_8048480(u32 r0, u32 r1)
{
    sub_807D148(r0, r1, 0, 0);
}

void sub_8048490(void)
{
    sub_8075FCC();
}

void sub_804849C(u32 r0, u32 r1)
{
    sub_8077AE4(r0, r1, 1);
}

void sub_80484A8(u32 r0, u32 r1)
{   
    volatile u32 temp;
    temp = 1;
    sub_8072008(r0, r1, 1, 1);
}

void sub_80484BC(void)
{
    sub_8076D10();
}

void sub_80484C8(u32 r0, struct unkDungeon_8041D5C *r1)
{
    sub_80522F4(r0, r1, gUnknown_80F89F4);
}

void sub_80484DC(u32 r0, u32 r1)
{
    sub_807232C(r0, r1, 1);
}

void sub_80484E8(u32 r0, struct unkDungeon_8041D5C *r1)
{
    u8 *temp;
    temp = r1->unk70[0];
    if(temp[0xAC] == 1)
    {
        sub_807A290(r0);
        return;
    }
    sub_8045B94(&gUnknown_202DF98, r1, 0);
    sub_80522F4(r0, r1, gUnknown_80FB580);
}
