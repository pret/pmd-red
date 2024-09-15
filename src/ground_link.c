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

EWRAM_DATA_2 struct unkStruct_203B4B8 gCurrentGroundLink = {0};
extern DebugLocation gUnknown_8118798;
extern struct unkStruct_80A77D0 *GetGroundScript(s16 r0, DebugLocation *r1);

void sub_80AD868(void)
{
    gCurrentGroundLink.unk0 = 0;
}

void sub_80AD874(void)
{
    gCurrentGroundLink.unk0 = 0;
}

void GroundLink_Select(s16 r0)
{
    gCurrentGroundLink.unk0 = GetGroundScript(r0, &gUnknown_8118798)->unk8;
}

u32 GetCurrentGroundLink(s16 r0)
{
    u32 a = r0;
    return gCurrentGroundLink.unk0 + a * 8;
}
