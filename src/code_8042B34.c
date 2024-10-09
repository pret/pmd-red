#include "global.h"
#include "dungeon_util_1.h"
#include "memory.h"
#include "code_803E46C.h"
#include "code_800E9E4.h"
#include "code_800DAC0.h"
#include "random.h"

extern void sub_800EE5C(s32);
extern void sub_800EF64(void);
extern void sub_800F15C(s32);

struct Sub_UnkStruct_203B414
{
    s16 a0;
    s16 a2;
};

struct UnkStruct_203B414
{
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC[16];
    s32 unk4C[16];
    struct Sub_UnkStruct_203B414 unk8C[16];
};

extern struct UnkStruct_203B414 *gUnknown_203B414;

struct UnkStruct_80F6624
{
    s16 unk0;
    s32 unk4;
};

extern const struct UnkStruct_80F6624 gUnknown_80F6624[][3];

extern const unkStruct_2039DB0 gUnknown_80F683C;

void sub_8042B34(s32 a0, s32 a1, s32 a2)
{
    unkStruct_80416E0 spStruct;
    s32 i;
    s32 r8 = 0;
    Entity *leader = xxx_call_GetLeader();
    gUnknown_203B414 = MemoryAlloc(sizeof(*gUnknown_203B414), 7);

    gUnknown_203B414->unk0 = a0;
    gUnknown_203B414->unk8 = (a1 + 1) * 4;
    sub_800EE5C(gUnknown_80F6624[a0][0].unk0);
    sub_800EF64();
    sub_803E46C(0x46);
    gUnknown_203B414->unk4 = a2;
    for (i = 0; i < gUnknown_203B414->unk8; i++) {
        s32 rnd;

        spStruct.unk0 = gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk0;
        spStruct.unk4 = i;
        spStruct.unk8 = 0;
        spStruct.x = leader->pixelPos.x / 256;
        spStruct.y = leader->pixelPos.y / 256;

        rnd = RandInt(2);
        gUnknown_203B414->unk4C[i] = (gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk4 * 2) + rnd;
        gUnknown_203B414->unk8C[i].a0 = RandInt(240) + 152;
        gUnknown_203B414->unk8C[i].a2 = RandInt(8 + (i * 2)) - (((i - (i / 4 * 4)) * 40) - 24);

        spStruct.unk10 = gUnknown_203B414->unk8C[i].a0;
        spStruct.unk12 = gUnknown_203B414->unk8C[i].a2;
        spStruct.unk14 = 4;
        spStruct.unk18 = 0xFFFF;
        spStruct.unk1C = gUnknown_80F683C;
        gUnknown_203B414->unkC[i] = sub_800E890(&spStruct);

        r8++;
        if (r8 >= 3 || gUnknown_80F6624[gUnknown_203B414->unk0][r8].unk0 == 0) {
            r8 = 0;
        }

        sub_800F15C(sub_800ECA4(spStruct.unk0)->unk4);
    }
}
