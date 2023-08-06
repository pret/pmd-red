#include "global.h"
#include "text1.h"
#include "text2.h"

// data.s
extern const u32 gUnknown_80B8814[];

// text.s
extern void sub_8006E94(struct UnkTextStruct1 *, s32, u32, const u8 *, u16 *);
extern void sub_8008C6C(struct UnkTextStruct1 *, u32);

void sub_800677C(struct UnkTextStruct1 *, s32, u16 *, u8);
void sub_80069CC(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006AC4(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006B70(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006C44(struct UnkTextStruct1 *, s32, u16 *, u8);

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

void sub_800677C(struct UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = a0->unk0 - 1;

    if (a1 > 28)
        return;
    // Cannot combine these ifs for matching
    if (a1 < 0)
        return;

    switch (a0->unkC) {
        case 0:
        case 1:
        case 2:
        case 6:
            break;
        case 3:
            (a2 + a1 * 0x20)[iVar5] = 0xF2D8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF293;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2D9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6D8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF693;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a2 + a1 * 0x20)[iVar5] = 0xF2E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2E9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6E8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a2 + a1 * 0x20)[iVar5] = 0xF2DC;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF2DD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF6DC;
            break;
        case 7:
           (a2 + a1 * 0x20)[iVar5] = 0xF293;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xF297;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xF693;
            break;
    }
}

void sub_80069CC(struct UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    // Cannot combine these ifs for matching
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 1:
        case 2:
            break;
        case 0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF297;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == a0->unk6 - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFA97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case 3:
        case 6:
            (a4 + a2 * 0x20)[a1] = 0xF2DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a4 + a2 * 0x20)[a1] = 0xF2EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a4 + a2 * 0x20)[a1] = 0xF2DE;
            break;
        case 7:
            (a4 + a2 * 0x20)[a1] = 0xF2B6;
            break;
    }
}

void sub_8006AC4(struct UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    // Cannot combine these ifs for matching
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 2:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF278;
            break;
        case 0:
        case 1:
        case 3:
        case 4:
        case 6:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
        case 7:
            (a4 + a2 * 0x20)[a1] = a3 | 0xF000;
            break;
    }
}

void sub_8006B70(struct UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
{
    if (a2 > 28)
        return;
    // Cannot combine these ifs for matching
    if (a2 < 0)
        return;

    switch (a0->unkC) {
        case 1:
        case 2:
            break;
        case 0:
            if (a3 == 0) {
                (a4 + a2 * 0x20)[a1] = 0xF697;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            if (a3 == a0->unk6 - 1) {
                (a4 + a2 * 0x20)[a1] = 0xFE97;
                (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
                break;
            }
            // Fallthrough
        case 3:
        case 6:
            (a4 + a2 * 0x20)[a1] = 0xF6DA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a4 + a2 * 0x20)[a1] = 0xF6EA;
            (a4 + a2 * 0x20)[a1 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a4 + a2 * 0x20)[a1] = 0xF6DE;
            break;
        case 7:
            (a4 + a2 * 0x20)[a1] = 0xF6B6;
            break;
    }
}

void sub_8006C44(struct UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
{
    s32 iVar5;
    s32 i;

    iVar5 = a0->unk0 - 1;

    if (a1 > 28)
        return;
    // Cannot combine these ifs for matching
    if (a1 < 0)
        return;

    switch (a0->unkC) {
        case 0:
        case 1:
        case 2:
            break;
        case 3:
        case 6:
            (a2 + a1 * 0x20)[iVar5] = 0xFAD8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xFA93;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFAD9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFED8;
            if (a3 != 0)
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xFE93;
            else
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 4:
            (a2 + a1 * 0x20)[iVar5] = 0xFAE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFAE9;
                (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEE8;
            (a2 + a1 * 0x20)[iVar5 + 0x400] = 0xF2DB;
            break;
        case 5:
            (a2 + a1 * 0x20)[iVar5] = 0xFADC;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFADD;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFEDC;
            break;
        case 7:
           (a2 + a1 * 0x20)[iVar5] = 0xFA93;
            iVar5++;
            for (i = 0; i < a0->unk4; i++) {
                (a2 + a1 * 0x20)[iVar5] = 0xFA97;
                iVar5++;
            }

            (a2 + a1 * 0x20)[iVar5] = 0xFE93;
            break;
    }
}