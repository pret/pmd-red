#include "global.h"
#include "other_random.h"
#include "math.h"
#include "memory.h"

struct unkStruct_809D158
{
    s32 a0;
    s32 a4;
};

struct unkStruct_20399E8
{
    u32 unk0;
    s32 unk4;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    struct unkStruct_809D158 unk14;
    struct unkStruct_809D158 unk1C;
    s32 unk24;
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    s32 unk34;
    s32 unk38;
    struct unkStruct_809D158 unk3C;
    u8 unk44;
};

extern struct unkStruct_20399E8 gUnknown_20399E8;

void sub_809D0BC(void);
void sub_809D4B0(void);
void sub_809D158(s32 r0, const struct unkStruct_809D158 *r1);

s32 sub_809CFE8(u16 param_1)
{
  if ((param_1 & 0x40) != 0) {
    if ((param_1 & 0x10) != 0)
        return 3;
    else if ((param_1 & 0x20) != 0)
        return 5;
    else
        return 4;
  }
  else if ((param_1 & 0x80) != 0) {
    if ((param_1 & 0x10) != 0)
        return 1;
    else if ((param_1 & 0x20) != 0)
        return 7;
    else
        return 0;
  }
  else if ((param_1 & 0x10) != 0)
    return 2;
  else if ((param_1 & 0x20) != 0)
    return 6;
  else
    return -1;
}

// Unused
s32 sub_809D058(s32 *param_1)
{
  if (param_1[1] < 0x40) {
    if (param_1[0]  < 0x68) {
        return 5;
    }
    else if (param_1[0]  > 0x88) {
        return 3;
    }
    else {
        return 4;
    }
  }
  else if (param_1[1] > 0x60) {
    if (param_1[0]  < 0x68) {
        return 7;
    }
    else if (param_1[0]  > 0x88) {
        return 1;
    }
    else {
        return 0;
    }
  }
  else if (param_1[0]  < 0x68) {
        return 6;
  }
  else if (param_1[0]  > 0x88) {
       return 2;
  }
  else {
       return -1;
  }
}

void sub_809D0AC(void)
{
    sub_809D0BC();
}

void nullsub_119(void)
{
}

extern const struct unkStruct_809D158 gZeroPos_8116478;

void sub_809D0BC(void)
{
    gUnknown_20399E8.unk3C = gZeroPos_8116478;
    gUnknown_20399E8.unk44 = 0;
    sub_809D158(0, &gZeroPos_8116478);
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

struct Test1
{
    u64 ukn0;
};

void sub_809D158(s32 r0, const struct unkStruct_809D158 *r1)
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

void sub_809D190(s32 r0, struct unkStruct_809D158 *r1, s32 r2)
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

void sub_809D1CC(s32 r0, struct unkStruct_809D158 *r1, s32 r2)
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

void sub_809D208(s32 r0, struct unkStruct_809D158 *r1, s32 r2)
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

bool32 sub_809D234(void)
{
    return gUnknown_20399E8.unk8 != 0;
}

u8 sub_809D248(struct unkStruct_809D158 *r0)
{
    *r0 = gUnknown_20399E8.unk3C;
    return gUnknown_20399E8.unk44;
}

// Todo: move these to appropriate header files
extern s32 sub_80A8FD8(s16 a0, struct unkStruct_809D158 *a1);
extern s32 sub_80AC448(s16 a0, struct unkStruct_809D158 *a1);
extern s32 sub_80AD360(s16 a0, struct unkStruct_809D158 *a1);
extern void sub_800290C(struct unkStruct_809D158 *a0, s32 a1);
extern void sub_8002934(struct unkStruct_809D158 *a0, struct unkStruct_809D158 *a1, struct unkStruct_809D158 *a2, u32 a3, u32 a4);
extern bool8 sub_80A579C(struct unkStruct_809D158 *a0, struct unkStruct_809D158 *a1);

void sub_809D25C(void)
{
    s32 r2, r1, r3;
    struct unkStruct_809D158 sp4;
    struct unkStruct_809D158 spC;
    struct unkStruct_809D158 sp14;
    struct unkStruct_809D158 sp1C;
    u16 val;
    // For some reason I have to compare with 0xFFFF instead of -1. Maybe it has to do with return value of the functions?
    switch (gUnknown_20399E8.unk0)
    {
    case 1:
        val = sub_80A8FD8(gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    case 2:
        val = sub_80AC448(gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    case 3:
        val = sub_80AD360(gUnknown_20399E8.unk4, &gUnknown_20399E8.unk1C);
        if (val == (u16) -1)
            gUnknown_20399E8.unk0 = 0;
        break;
    }

    switch (gUnknown_20399E8.unk8)
    {
    case 1:
        sp4.a0 = gUnknown_20399E8.unk1C.a0 - gUnknown_20399E8.unk14.a0;
        sp4.a4 = gUnknown_20399E8.unk1C.a4 - gUnknown_20399E8.unk14.a4;
        sub_800290C(&sp4, gUnknown_20399E8.unkC);
        if (sp4.a0 == 0 && sp4.a4 == 0)
        {
            gUnknown_20399E8.unk8 = 0;
        }
        else
        {
            gUnknown_20399E8.unk14.a0 += sp4.a0;
            gUnknown_20399E8.unk14.a4 += sp4.a4;
        }
        break;
    case 3:
        r2 = (gUnknown_20399E8.unk1C.a0 - gUnknown_20399E8.unk14.a0) / 256;
        r1 = (gUnknown_20399E8.unk1C.a4 - gUnknown_20399E8.unk14.a4) / 256;
        gUnknown_20399E8.unk10 = ((sub_8009FB8(r2 << 8, r1 << 8) / 256) << 8) / gUnknown_20399E8.unkC;
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
        r2 = gUnknown_20399E8.unk14.a0 + gUnknown_20399E8.unk34 - 0x80;
        r3 = gUnknown_20399E8.unk14.a4 + gUnknown_20399E8.unk38 - 2944;

        if (r2 < sp14.a0)
            r2 = sp14.a0;
        if (r2 >= sp1C.a0)
            r2 = sp1C.a0 - 1;

        if (r3 < sp14.a4)
            r3 = sp14.a4;
        if (r3 >= sp1C.a4)
            r3 = sp1C.a4 - 1;

        gUnknown_20399E8.unk3C.a0 = (r2 - 30976) / 256;
        gUnknown_20399E8.unk3C.a4 = (r3 - 20480) / 256;
        gUnknown_20399E8.unk44 = 1;
    }
}

void nullsub_120(void)
{}

// Different file below?

extern void *gUnknown_203B4B0;

void sub_809D490(void)
{
    UNUSED void *oldPtr = gUnknown_203B4B0; // Needed to match
    gUnknown_203B4B0 = MemoryAlloc(0x400, 6);
    sub_809D4B0();
}

extern s16 gCurrentMap;
extern s16 gUnknown_2039A32;
extern s16 gUnknown_2039A34;
extern u8 gAnyScriptLocked;
extern u8 gScriptLocks[];
extern u8 gScriptLockConds[];
extern u32 gUnlockBranchLabels[];

void sub_809D4B0(void)
{
    s32 i;

    gCurrentMap = -1;
    gUnknown_2039A32 = -1;
    gUnknown_2039A34 = -1;
    gAnyScriptLocked = 0;
    for (i = 0; i < 0x81; i++) {
        gScriptLocks[i] = 0;
        gScriptLockConds[i] = 0;
        gUnlockBranchLabels[i] = 0;
    }
}

void sub_809D508(void)
{
    MemoryFree(gUnknown_203B4B0);
    gUnknown_203B4B0 = NULL;
}
