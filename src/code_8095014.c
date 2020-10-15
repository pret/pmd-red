#include "global.h"

struct unk_8094FB4
{
    s16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
};


extern u32 *gUnknown_203B480;
extern u32 *gUnknown_203B484;
extern u32 *gUnknown_203B488;
extern u32 *gUnknown_203B48C;

extern u32 gUnknown_203B47C;
extern u32 gUnknown_2038C88;
extern u32 gUnknown_2039288;
extern u32 gUnknown_20392E8;
extern u32 gUnknown_20393C0;

extern void sub_809488C(u32, u32, u32);
extern void sub_8094924(u32, u32, u32);

void sub_8095014(struct unk_8094FB4 *r0, u32 *r1, u32 *r2, u32 *r3)
{
    u32 temp;
    if(r0->unk0 <= 0x270f)
    {
        *r1 = r0->unk0;
        *r2 = r0->unk2;
        temp = r0->unk3;
    }
    else
    {
        *r1 = 0x270f;
        *r2 = 0x3B;
        temp = 0x3B;
    }
    *r3 = temp;
}

void sub_8095044(u32 r0)
{
    sub_809488C(r0, gUnknown_203B47C + 4, 0x6);
    sub_809488C(r0, gUnknown_203B47C + 3, 0x6);
    sub_809488C(r0, gUnknown_203B47C + 2, 0x6);
    sub_809488C(r0, gUnknown_203B47C, 0xE);
}

void sub_8095080(u32 r0)
{
    sub_8094924(r0, gUnknown_203B47C + 4, 0x6);
    sub_8094924(r0, gUnknown_203B47C + 3, 0x6);
    sub_8094924(r0, gUnknown_203B47C + 2, 0x6);
    sub_8094924(r0, gUnknown_203B47C, 0xE);
}

void sub_80950BC(void)
{
    gUnknown_203B480 = &gUnknown_2038C88;
    gUnknown_203B484 = &gUnknown_2039288;
    gUnknown_203B488 = &gUnknown_20392E8;
    gUnknown_203B48C = &gUnknown_20393C0;
}

u32 *sub_80950F8(void)
{
    return &gUnknown_2038C88;
}

u32 *sub_8095100(void)
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

