#include "global.h"

struct unkStruct_203B45C
{
    u8 unk0;
    u8 padding1;
    u8 unk2;
    u8 padding2;
    u8 unk4;
    u8 array[0x53];
};

extern struct unkStruct_203B45C *gUnknown_203B45C;

extern void sub_808DE50(void* r0, struct unkStruct_203B45C *r1, u32 r2, u32 r3);


void sub_808DE30(void* r0, u32 r1)
{
    sub_808DE50(r0, &gUnknown_203B45C[r1], r1, r1 * sizeof(struct unkStruct_203B45C));
}
