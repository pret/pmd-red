#include "global.h"
#include "memory.h"

struct UnkEventStruct
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ u16 unk6;
    /* 0x8 */ u16 unk8;
    /* 0xA */ s16 unkA;
};

struct UnkEventStruct2
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
};

extern void sub_800226C(u8 r0, u8 r1, u32* r2, u8 u3);
extern void sub_800160C(struct UnkEventStruct2 *r0, u32 r1, u32 r2);

extern u8 gUnknown_2000A88;


//u8 sub_8002718(struct UnkEventStruct *r0)
//{
//    struct UnkEventStruct2 temp;
//    sub_800160C(&temp, 0, 0);
//    MemoryCopy8(&gUnknown_2000A88, (u8 *)r0, (0x80 << 3));
//
//    // TODO fix this comparison to make it match
//    if(r0->unkA != temp.unk4) 
//        return 0;
//    return 1;
//}

void sub_8002758(u32 *r0)
{
    sub_800226C(0, 0x1, r0, 0x9);
}

u8 sub_800276C(void)
{
    return 0;
}

void nullsub_140(void)
{

}
