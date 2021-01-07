#include "global.h"

struct unkStruct_80EBA18
{
    u32 unk0;
    u32 unk4;
};

extern struct unkStruct_80EBA18 gUnknown_80EBA18[];
extern s32 sub_80908D8(u32);

u32 sub_803C190(u8 r0)
{
    return gUnknown_80EBA18[r0].unk0;
}


u32 sub_803C1A0(u8 r0)
{
    return gUnknown_80EBA18[r0].unk4;
}

s32 sub_803C1B4(s32 r0, u8 r1)
{
    s32 temp;
    temp = sub_80908D8(r0);
    if(r1 == 2)
    {
        temp += 2;
    }
    if(temp > 0xF)
        temp = 0xF;
    return temp;
}
