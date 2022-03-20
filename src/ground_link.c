#include "global.h"
#include "debug.h"

struct unkStruct_80A77D0
{
    u32 unk0;
    u32 unk4;
    u32 unk8;
};

struct unkStruct_203B4B8
{
    u32 unk0;
};

extern struct unkStruct_203B4B8 gUnknown_203B4B8;
extern struct DebugLocation gUnknown_8118798;
extern struct unkStruct_80A77D0 *sub_80A77D0(s16 r0, struct DebugLocation *r1);

void sub_80AD868(void)
{
    gUnknown_203B4B8.unk0 = 0;
}

void sub_80AD874(void)
{
    gUnknown_203B4B8.unk0 = 0;
}

void GroundLink_Select(s16 r0)
{
    gUnknown_203B4B8.unk0 = sub_80A77D0(r0, &gUnknown_8118798)->unk8;
}

u32 sub_80AD8A0(s16 r0)
{
    u32 a = r0;
    return gUnknown_203B4B8.unk0 + a * 8;
}
