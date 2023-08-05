#include "global.h"
#include "text1.h"
#include "text2.h"

// data.s
extern const u32 gUnknown_80B8814[];

// text.s
extern void sub_800677C(struct UnkTextStruct1 *, s32, u16 *, u8);
extern void sub_80069CC(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
extern void sub_8006AC4(struct UnkTextStruct1 *, s32, s32, u32, u16 *);
extern void sub_8006B70(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
extern void sub_8006C44(struct UnkTextStruct1 *, s32, u16 *, u8);
extern void sub_8006E94(struct UnkTextStruct1 *, s32, u32, const u8 *, u16 *);
extern void sub_8008C6C(struct UnkTextStruct1 *, u32);

void nullsub_152(void)
{
}

void sub_8006518(struct UnkTextStruct2 *unkData)
{
    s32 iVar2;
    for (iVar2 = 0; iVar2 < 4; iVar2++)
        unkData[iVar2] = gUnknown_202AFC0[iVar2];
}

void nullsub_153(void)
{
}

u32 sub_8006544(u32 index)
{
    return gUnknown_80B8814[index];
}

// a1 is a VRAM pointer
void sub_8006554(struct UnkTextStruct1 *a0, void *a1, u8 *a2, u16 *a3, u32 a4, const struct UnkTextStruct2 *a5, u8 a6, u32 a7, struct UnkTextStruct2_sub *a8, u8 a9)
{
    struct UnkTextStruct1 *t1;
    s32 iVar3;
    s32 iVar5;
    s32 iVar6;
    s32 numI;
    u32 uVar1;

    s32 temp;
    s32 i;
    s32 j;

    t1 = &a0[a4];
    iVar3 = a5->unk8.unk0.arr[0] + a8->unk0.arr[0];
    iVar5 =  a5->unk8.unk0.arr[1] + a8->unk0.arr[1];
    t1->unk0 = iVar3;
    t1->unk2 = iVar5;
    t1->unk4 = a5->unkC;
    t1->unk8 = a5->unk10;
    t1->unk6 = a5->unkE;
    t1->unkC = a5->unk4;
    t1->unk10 = a7;

    if (t1->unkC == 6)
        t1->unk14 = a7;
    else
        t1->unk14 = a7 + a5->unk12 * t1->unk4;

    t1->unk18 = &a2[t1->unk10 * 0x20];
    t1->unk1C = &a2[t1->unk14 * 0x20];
    t1->unk24 = a5->unk12;
    t1->unk28 = a1 + (t1->unk14 * 0x20);

    if (t1->unkC == 6)
        t1->unk2C = t1->unk4 * (t1->unk6 + a5->unk12) * 32;
    else
        t1->unk2C = t1->unk4 * t1->unk6 * 32;

    t1->unk30 = 0;
    t1->unk34 = 0;
    t1->unk38 = 0;
    t1->unk20 = (t1->unk4 * 8) - 8;
    t1->unk45 = t1->unkC == 0;

    if (t1->unk8 == 0)
        return;

    if ((a5->unk0 & 0xA0) != 0x80) {
        temp = iVar5 - 1;

        if (t1->unkC == 6) {
            uVar1 = (a6 != 0) ? t1->unk14 : 0;

            sub_8006E94(t1, temp, uVar1, a5->unk14, a3);

            temp = iVar5 + 2;
            uVar1 = (a6 != 0) ? t1->unk14 + t1->unk4 * (a5->unk12 + 2) : 0;
            numI = t1->unk6 - 2;
        }
        else {
            sub_800677C(t1, temp, a3, a9);

            temp = iVar5;
            uVar1 = (a6 != 0) ? t1->unk14 : 0;
            numI = t1->unk6;
        }

        for (i = 0; i < numI; i++) {
            iVar6 = iVar3 - 1;
            sub_80069CC(t1, iVar6, temp, i, a3);
            iVar6 = iVar3;

            for (j = 0; j < t1->unk4; j++) {
                sub_8006AC4(t1, iVar6, temp, uVar1, a3);

                iVar6++;
                if (a6 != 0)
                    uVar1++;
            }

            sub_8006B70(t1, iVar6, temp, i, a3);
            temp++;
        }
        sub_8006C44(t1, temp, a3, a9);
    }

    if ((a5->unk0 & 0x80) == 0)
        sub_8008C6C(a0, a4);

    t1->unk46 = 0;
}