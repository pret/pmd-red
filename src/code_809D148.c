#include "global.h"
#include "globaldata.h"
#include "structs/str_position.h"
#include "code_8002774.h"
#include "math.h"
#include "memory.h"
#include "other_random.h"
#include "ground_script.h"
#include "ground_lives.h"
#include "ground_effect.h"
#include "ground_object.h"

struct unkStruct_20399E8
{
    u32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    PixelPos unk14;
    PixelPos unk1C;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    PixelPos unk3C;
    u8 unk44;
};

static EWRAM_DATA struct unkStruct_20399E8 gUnknown_20399E8 = {0};

void sub_809D0BC(void);
void sub_809D158(s32 r0, const PixelPos *r1);

void sub_809D0AC(void)
{
    sub_809D0BC();
}

void nullsub_119(void)
{
}

static const PixelPos sPixelPosZero = {0, 0};

void sub_809D0BC(void)
{
    gUnknown_20399E8.unk3C = sPixelPosZero;
    gUnknown_20399E8.unk44 = 0;
    sub_809D158(0, &sPixelPosZero);
    gUnknown_20399E8.unk8 = 0;
    gUnknown_20399E8.unkC = 0;
    gUnknown_20399E8.unk10 = 0;
    gUnknown_20399E8.unk4 = -1;
    gUnknown_20399E8.unk24 = 0;
    gUnknown_20399E8.unk28 = 0;
    gUnknown_20399E8.unk2C = 0;
    gUnknown_20399E8.unk30 = 0;
    gUnknown_20399E8.unk34 = 0;
    gUnknown_20399E8.unk38 = 0;
}

void sub_809D100(s32 r0)
{
    if(gUnknown_20399E8.unk24 != r0)
    {
        gUnknown_20399E8.unk24 = r0;
        gUnknown_20399E8.unk28 = 0;
        gUnknown_20399E8.unk2C = 0;
        gUnknown_20399E8.unk30 = 0;
        gUnknown_20399E8.unk34 = 0;
        gUnknown_20399E8.unk38 = 0;
    }
}

void sub_809D124(s32 r0, s32 r1, s32 r2)
{
    if(gUnknown_20399E8.unk24 != r0)
    {
        gUnknown_20399E8.unk24 = r0;
        gUnknown_20399E8.unk30 = 0;
        gUnknown_20399E8.unk34 = 0;
        gUnknown_20399E8.unk38 = 0;
    }
    gUnknown_20399E8.unk28 = r1;
    gUnknown_20399E8.unk2C = r2;
}

void sub_809D148(s32 r0)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;

}

void sub_809D158(s32 r0, const PixelPos *r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;
    gUnknown_20399E8.unk1C = *r1;
}

void sub_809D170(s32 r0, s32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 0;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D180(s32 r0, s32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r1;
}

void sub_809D190(s32 r0, PixelPos *r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk14 = *r1;
}

void sub_809D1A8(s32 r0, s32 r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 1;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D1BC(s32 r0, s32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r1;
}

void sub_809D1CC(s32 r0, PixelPos *r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r2;
    gUnknown_20399E8.unk14 = *r1;
}

void sub_809D1E4(s32 r0, s32 r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 2;
    gUnknown_20399E8.unk10 = r2;
    gUnknown_20399E8.unk4 = r1;
}

void sub_809D1F8(s32 r0, s32 r1)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r1;
}

void sub_809D208(s32 r0, PixelPos *r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk14 = *r1;
}

void sub_809D220(s32 r0, s32 r1, s32 r2)
{
    gUnknown_20399E8.unk0 = r0;
    gUnknown_20399E8.unk8 = 3;
    gUnknown_20399E8.unkC = r2;
    gUnknown_20399E8.unk4 = r1;
}

bool8 sub_809D234(void)
{
    return gUnknown_20399E8.unk8 != 0;
}

u8 sub_809D248(PixelPos *r0)
{
    *r0 = gUnknown_20399E8.unk3C;
    return gUnknown_20399E8.unk44;
}

// Todo: move these to appropriate header files
extern bool8 sub_80A579C(PixelPos *a0, PixelPos *a1);

void sub_809D25C(void)
{
    s32 r2, r1, r3;
    PixelPos sp4;
    PixelPos spC;
    PixelPos sp14;
    PixelPos sp1C;
    u16 val;
    // For some reason I have to compare with 0xFFFF instead of -1. Maybe it has to do with return value of the functions?
    switch (gUnknown_20399E8.unk0)
    {
    case 1:
        val = sub_80A8FD8((s16) gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    case 2:
        val = sub_80AC448((s16) gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    case 3:
        val = sub_80AD360((s16) gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    }

    switch (gUnknown_20399E8.unk8)
    {
    case 1:
        sp4.x = gUnknown_20399E8.unk1C.x - gUnknown_20399E8.unk14.x;
        sp4.y = gUnknown_20399E8.unk1C.y - gUnknown_20399E8.unk14.y;
        sub_800290C(&sp4, gUnknown_20399E8.unkC);
        if (sp4.x == 0 && sp4.y == 0)
        {
            gUnknown_20399E8.unk8 = 0;
        }
        else
        {
            gUnknown_20399E8.unk14.x += sp4.x;
            gUnknown_20399E8.unk14.y += sp4.y;
        }
        break;
    case 3:
        r2 = (gUnknown_20399E8.unk1C.x - gUnknown_20399E8.unk14.x) / 256;
        r1 = (gUnknown_20399E8.unk1C.y - gUnknown_20399E8.unk14.y) / 256;
        gUnknown_20399E8.unk10 = (F248ToInt(FP24_8_Hypot(IntToF248(r2), IntToF248(r1))) << 8) / gUnknown_20399E8.unkC;
        if (gUnknown_20399E8.unk10 <= 0)
            gUnknown_20399E8.unk10 = 1;
        gUnknown_20399E8.unk8 = 2;
    // Breakthrough
    case 2:
        sub_8002934(&spC, &gUnknown_20399E8.unk14, &gUnknown_20399E8.unk1C, gUnknown_20399E8.unk10, 1);
        gUnknown_20399E8.unk14 = spC;
        if (--gUnknown_20399E8.unk10 <= 0)
            gUnknown_20399E8.unk8 = 0;
        break;
    default:
        gUnknown_20399E8.unk14 = gUnknown_20399E8.unk1C;
        break;
    }

    switch (gUnknown_20399E8.unk24)
    {
    default:
        gUnknown_20399E8.unk34 = 0;
        gUnknown_20399E8.unk38 = 0;
        break;
    case 1:
        if (--gUnknown_20399E8.unk30 <= 0)
        {
            gUnknown_20399E8.unk30 = 4;
            gUnknown_20399E8.unk34 = OtherRandRange(-2, 2) << 0xA;
            gUnknown_20399E8.unk38 = OtherRandRange(-2, 2) << 0xA;
        }
        break;
    case 2:
        if (--gUnknown_20399E8.unk30 <= 0)
        {
            gUnknown_20399E8.unk30 = gUnknown_20399E8.unk2C;
            gUnknown_20399E8.unk34 = (OtherRandRange(-2, 2) * gUnknown_20399E8.unk28) << 0x8;
            gUnknown_20399E8.unk38 = (OtherRandRange(-2, 2) * gUnknown_20399E8.unk28) << 0x8;
        }
        break;
    }

    if (sub_80A579C(&sp14, &sp1C))
    {
        r2 = gUnknown_20399E8.unk14.x + gUnknown_20399E8.unk34 - 0x80;
        r3 = gUnknown_20399E8.unk14.y + gUnknown_20399E8.unk38 - 2944;

        if (r2 < sp14.x)
            r2 = sp14.x;
        if (r2 >= sp1C.x)
            r2 = sp1C.x - 1;

        if (r3 < sp14.y)
            r3 = sp14.y;
        if (r3 >= sp1C.y)
            r3 = sp1C.y - 1;

        gUnknown_20399E8.unk3C.x = (r2 - 30976) / 256;
        gUnknown_20399E8.unk3C.y = (r3 - 20480) / 256;
        gUnknown_20399E8.unk44 = 1;
    }
}

void nullsub_120(void)
{}
