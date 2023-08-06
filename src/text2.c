#include "global.h"
#include "text1.h"
#include "text2.h"

// data.s
extern const u32 gUnknown_80B8814[];

// text.s
extern void sub_8008C6C(struct UnkTextStruct1 *, u32);

void sub_800677C(struct UnkTextStruct1 *, s32, u16 *, u8);
void sub_80069CC(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006AC4(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006B70(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006C44(struct UnkTextStruct1 *, s32, u16 *, u8);
void sub_8006E94(struct UnkTextStruct1 *, s32, u32, const u8 *, u16 *);

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

#ifdef NONMATCHING
// Not even close but I don't feel like continuing atm https://decomp.me/scratch/F58jg
void sub_8006E94(struct UnkTextStruct1 *a0, s32 a1, u32 a2, const u8 *a3, u16 *a4)
{
    s32 bVar1;
    s32 iVar2;
    s32 iVar3;
    s32 sVar4;
    u16 *puVar5;
    u16 *puVar6;
    u16 *puVar7;
    s32 iVar8;
    u16 *puVar9;
    u16 *puVar10;
    u16 *puVar11;
    s32 local_44;
    u32 local_3c;
    u16 *local_30;
    s32 local_2c;
    u16 *local_24;

    iVar2 = a0->unk0;
    bVar1 = -1;

    if (a1 > 28)
        return;
    if (a1 < 0)
        return;

    (a4 + a1 * 0x20)[iVar2 - 1] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x400] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x20] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x420] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x40] = 0xF2D8;
    (a4 + a1 * 0x20)[iVar2 - 1 + 0x440] = 0xF2DB;

    local_2c = iVar2 * 2;
    puVar5 = a4 + a1 * 0x20 + iVar2 + 0x40;
    puVar7 = a4 + a1 * 0x20 + iVar2 + 0x20;
    local_30 = a4 + a1 * 0x20 + iVar2 + 0x400;
    puVar11 = a4 + a1 * 0x20 + iVar2 + 0x420;
    puVar9 = a4 + a1 * 0x20 + iVar2;
    iVar8 = a1 * 0x40;

    for (local_3c = 0; local_3c < a3[0]; local_3c++) {
        if (local_3c == a3[1]) {
            bVar1 = TRUE;
            *puVar9 = 0xF2E0;
            *local_30 = 0xF2E2;
            *puVar7 = 0xF2DA;
            *puVar11 = 0xF2DB;
            *puVar5 = 0xF6E7;
            puVar9[0x440] = 0xF2DB;
            puVar5++;
            puVar7++;
            local_30++;
            puVar11++;
            puVar9++;
            local_2c += 2;
            iVar2++;

            if (a2 == 0 || ++a2 == 0)
                iVar3 = 0;
            else
                iVar3 = a2 + a0->unk4;
            
            local_24 = a4 + local_2c + iVar8 + 0x80;
            puVar10 = a4 + local_2c + iVar8 + 0x40;
            puVar6 = a4 + local_2c + iVar8;

            for (local_44 = 0; local_44 < a3[2]; local_44++) {
                *puVar6 = 0xF2E1;
                puVar6[0x400] = 0xF2E2;
                *puVar10 = a2 | 0xF000;
                puVar6[0x420] = 0xF2DB;
                *local_24 = iVar3 | 0xF000;
                puVar6[0x440] = 0xF2DB;
                local_24++;
                puVar10++;
                puVar6++;
                puVar5++;
                puVar7++;
                local_30++;
                puVar11++;
                puVar9++;
                local_2c += 2;
                iVar2++;
                if (a2 != 0)
                    a2++;
                
                if (iVar3 != 0)
                    iVar3++;
            }

            *puVar9 = 0xF6E0;
            *local_30 = 0xF2E2;
            *puVar7 = 0xF6DA;
            *puVar11 = 0xF2DB;
            *puVar5 = 0xF2E7;
            puVar9[0x440] = 0xF2DB;
        }
        else {
            if (bVar1) {
                if ((a3[3] >> (local_3c & 0xFF) & 1) == 0) {
                    sVar4 = 107;
                    if (local_3c == a3[0] - 1)
                        sVar4 = 103;

                    *puVar9 = (sVar4 + 0x278) | 0xF000;
                    *puVar7 = 0xF6EF;
                    *puVar5 = 0xF2D9;
                }
                else {
                    sVar4 = 31;
                    if (local_3c == a3[0] - 1)
                        sVar4 = 27;

                    *puVar9 = (sVar4 + 0x278) | 0xF000;
                    *puVar7 = 0xF6B6;
                    *puVar5 = 0xF2D9;
                }
                *local_30 = 0xF27A;
                *puVar11 = 0xF6DB;
            }
            else {
                if ((a3[3] >> (local_3c & 0xFF) & 1) == 0) {
                    sVar4 = 107;
                    if (local_3c == 0)
                        sVar4 = 103;

                    *puVar9 = (sVar4 + 0x278) | 0xF400;
                    *puVar7 = 0xF2EF;
                    *puVar5 = 0xF2D9;
                }
                else {
                    sVar4 = 31;
                    if (local_3c == 0)
                        sVar4 = 27;

                    *puVar9 = (sVar4 + 0x278) | 0xF400;
                    *puVar7 = 0xF2B6;
                    *puVar5 = 0xF2D9;
                }
                *local_30 = 0xF27A;
                *puVar11 = 0xF2DB;
            }
            puVar9[0x440] = 0xF2DB;
        }

        local_2c += 2;
        local_30++;
        iVar2++;
        puVar11++;
        puVar5++;
        puVar7++;
        puVar9++;
        if (a2 != 0)
            a2++;
    }

    iVar8 = a0->unk0 + a0->unk4;
    if (iVar2 < iVar8) {
        for (iVar3 = iVar8 - iVar2; iVar3 != 0; iVar3--) {
            (a4 + a1 * 0x20)[iVar2 + iVar3] = 0xF278;
            (a4 + a1 * 0x20)[iVar2 + 0x400 + iVar3] = 0xF27A;
            (a4 + a1 * 0x20)[iVar2 + 0x20 + iVar3] = 0xF278;
            (a4 + a1 * 0x20)[iVar2 + 0x420 + iVar3] = 0xF27A;
            (a4 + a1 * 0x20)[iVar2 + 0x40 + iVar3] = 0xF2D9;
            (a4 + a1 * 0x20)[iVar2 + 0x440 + iVar3] = 0xF2DB;

            if (a2 != 0)
                a2++;

            iVar2 = iVar8;
        }
    }

    (a4 + a1 * 0x20)[iVar2] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 + 0x400] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 + 0x20] = 0xF278;
    (a4 + a1 * 0x20)[iVar2 + 0x420] = 0xF27A;
    (a4 + a1 * 0x20)[iVar2 + 0x40] = 0xF6D8;
    (a4 + a1 * 0x20)[iVar2 + 0x440] = 0xF2DB;
}
#else
NAKED
void sub_8006E94(struct UnkTextStruct1 *a0, s32 a1, u32 a2, const u8 *a3, u16 *a4)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x30\n"
    "\tstr r0, [sp]\n"
    "\tadds r4, r1, 0\n"
    "\tadds r7, r2, 0\n"
    "\tstr r3, [sp, 0x4]\n"
    "\tmovs r1, 0\n"
    "\tldrsh r0, [r0, r1]\n"
    "\tmov r10, r0\n"
    "\tmovs r2, 0x1\n"
    "\tnegs r2, r2\n"
    "\tadd r2, r10\n"
    "\tmovs r3, 0\n"
    "\tstr r3, [sp, 0x8]\n"
    "\tcmp r4, 0x1C\n"
    "\tble _08006EBE\n"
    "\tb _080072FE\n"
"_08006EBE:\n"
    "\tcmp r4, 0\n"
    "\tbge _08006EC4\n"
    "\tb _080072FE\n"
"_08006EC4:\n"
    "\tlsls r1, r2, 1\n"
    "\tlsls r4, 6\n"
    "\tldr r6, [sp, 0x50]\n"
    "\tadds r5, r4, r6\n"
    "\tadds r1, r5\n"
    "\tldr r0, _08006F9C\n"
    "\tadds r3, r0, 0\n"
    "\tstrh r3, [r1]\n"
    "\tmovs r2, 0x80\n"
    "\tlsls r2, 4\n"
    "\tadds r0, r1, r2\n"
    "\tldr r6, _08006FA0\n"
    "\tadds r2, r6, 0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r1, 0\n"
    "\tadds r0, 0x40\n"
    "\tstrh r3, [r0]\n"
    "\tmovs r0, 0x84\n"
    "\tlsls r0, 4\n"
    "\tadds r0, r1, r0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r2, r1, 0\n"
    "\tadds r2, 0x80\n"
    "\tldr r3, _08006FA4\n"
    "\tadds r0, r3, 0\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r6, 0x88\n"
    "\tlsls r6, 4\n"
    "\tadds r1, r6\n"
    "\tldr r2, _08006FA8\n"
    "\tadds r0, r2, 0\n"
    "\tstrh r0, [r1]\n"
    "\tmov r12, r10\n"
    "\tmovs r3, 0\n"
    "\tstr r4, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x4]\n"
    "\tldrb r4, [r4]\n"
    "\tcmp r3, r4\n"
    "\tblt _08006F14\n"
    "\tb _08007238\n"
"_08006F14:\n"
    "\tadds r2, r5, 0\n"
    "\tmov r5, r12\n"
    "\tlsls r1, r5, 1\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r6, [sp, 0x18]\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1\n"
    "\tmov r9, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1\n"
    "\tmov r8, r0\n"
    "\tldr r4, [sp, 0x50]\n"
    "\tmovs r5, 0x80\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tadds r0, r6, r0\n"
    "\tadds r0, r1, r0\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tmovs r6, 0x84\n"
    "\tlsls r6, 4\n"
    "\tadds r0, r4, r6\n"
    "\tldr r4, [sp, 0x18]\n"
    "\tadds r0, r4, r0\n"
    "\tadds r0, r1\n"
    "\tmov r10, r0\n"
    "\tadds r4, r1, r2\n"
    "\tldr r5, [sp, 0x18]\n"
    "\tstr r5, [sp, 0x10]\n"
    "\tstr r2, [sp, 0x1C]\n"
    "\tstr r1, [sp, 0x24]\n"
"_08006F56:\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrb r6, [r6, 0x1]\n"
    "\tcmp r3, r6\n"
    "\tbne _08006F60\n"
    "\tb _080070C8\n"
"_08006F60:\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tcmp r0, 0\n"
    "\tbne _08007008\n"
    "\tldr r1, [sp, 0x4]\n"
    "\tldrb r0, [r1, 0x3]\n"
    "\tasrs r0, r3\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _08006FB8\n"
    "\tmovs r1, 0x1F\n"
    "\tcmp r3, 0\n"
    "\tbne _08006F7C\n"
    "\tmovs r1, 0x1B\n"
"_08006F7C:\n"
    "\tmovs r2, 0x9E\n"
    "\tlsls r2, 2\n"
    "\tadds r0, r1, r2\n"
    "\tldr r5, _08006FAC\n"
    "\tadds r1, r5, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r6, _08006FB0\n"
    "\tadds r0, r6, 0\n"
    "\tmov r1, r8\n"
    "\tstrh r0, [r1]\n"
    "\tldr r5, _08006FB4\n"
    "\tmov r2, r9\n"
    "\tstrh r5, [r2]\n"
    "\tb _08006FDC\n"
    "\t.align 2, 0\n"
"_08006F9C: .4byte 0x0000f278\n"
"_08006FA0: .4byte 0x0000f27a\n"
"_08006FA4: .4byte 0x0000f2d8\n"
"_08006FA8: .4byte 0x0000f2db\n"
"_08006FAC: .4byte 0xfffff400\n"
"_08006FB0: .4byte 0x0000f2b6\n"
"_08006FB4: .4byte 0x0000f2d9\n"
"_08006FB8:\n"
    "\tmovs r1, 0x6B\n"
    "\tcmp r3, 0\n"
    "\tbne _08006FC0\n"
    "\tmovs r1, 0x67\n"
"_08006FC0:\n"
    "\tmovs r6, 0x9E\n"
    "\tlsls r6, 2\n"
    "\tadds r0, r1, r6\n"
    "\tldr r2, _08006FF4\n"
    "\tadds r1, r2, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r5, _08006FF8\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08006FFC\n"
    "\tmov r0, r9\n"
    "\tstrh r1, [r0]\n"
"_08006FDC:\n"
    "\tldr r2, _08007000\n"
    "\tadds r0, r2, 0\n"
    "\tldr r5, [sp, 0x20]\n"
    "\tstrh r0, [r5]\n"
    "\tldr r0, _08007004\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r4, r1\n"
    "\tadds r2, 0x61\n"
    "\tb _0800708E\n"
    "\t.align 2, 0\n"
"_08006FF4: .4byte 0xfffff400\n"
"_08006FF8: .4byte 0x0000f2ef\n"
"_08006FFC: .4byte 0x0000f2d9\n"
"_08007000: .4byte 0x0000f27a\n"
"_08007004: .4byte 0x0000f2db\n"
"_08007008:\n"
    "\tldr r5, [sp, 0x4]\n"
    "\tldrb r0, [r5, 0x3]\n"
    "\tasrs r0, r3\n"
    "\tmovs r1, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbeq _0800704C\n"
    "\tldrb r0, [r5]\n"
    "\tsubs r0, 0x1\n"
    "\tmovs r1, 0x1F\n"
    "\tcmp r3, r0\n"
    "\tbne _08007022\n"
    "\tmovs r1, 0x1B\n"
"_08007022:\n"
    "\tmovs r6, 0x9E\n"
    "\tlsls r6, 2\n"
    "\tadds r0, r1, r6\n"
    "\tldr r2, _08007040\n"
    "\tadds r1, r2, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r5, _08007044\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007048\n"
    "\tmov r0, r9\n"
    "\tstrh r1, [r0]\n"
    "\tb _08007076\n"
    "\t.align 2, 0\n"
"_08007040: .4byte 0xfffff000\n"
"_08007044: .4byte 0x0000f6b6\n"
"_08007048: .4byte 0x0000f2d9\n"
"_0800704C:\n"
    "\tldr r2, [sp, 0x4]\n"
    "\tldrb r0, [r2]\n"
    "\tsubs r0, 0x1\n"
    "\tmovs r1, 0x6B\n"
    "\tcmp r3, r0\n"
    "\tbne _0800705A\n"
    "\tmovs r1, 0x67\n"
"_0800705A:\n"
    "\tmovs r5, 0x9E\n"
    "\tlsls r5, 2\n"
    "\tadds r0, r1, r5\n"
    "\tldr r6, _080070B0\n"
    "\tadds r1, r6, 0\n"
    "\torrs r0, r1\n"
    "\tstrh r0, [r4]\n"
    "\tldr r1, _080070B4\n"
    "\tadds r0, r1, 0\n"
    "\tmov r2, r8\n"
    "\tstrh r0, [r2]\n"
    "\tldr r6, _080070B8\n"
    "\tmov r5, r9\n"
    "\tstrh r6, [r5]\n"
"_08007076:\n"
    "\tldr r1, _080070BC\n"
    "\tadds r0, r1, 0\n"
    "\tldr r2, [sp, 0x20]\n"
    "\tstrh r0, [r2]\n"
    "\tldr r5, _080070C0\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r4, r1\n"
    "\tldr r2, _080070C4\n"
"_0800708E:\n"
    "\tstrh r2, [r0]\n"
    "\tmovs r5, 0x2\n"
    "\tadd r9, r5\n"
    "\tadd r8, r5\n"
    "\tldr r6, [sp, 0x20]\n"
    "\tadds r6, 0x2\n"
    "\tstr r6, [sp, 0x20]\n"
    "\tadd r10, r5\n"
    "\tadds r4, 0x2\n"
    "\tldr r0, [sp, 0x24]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x24]\n"
    "\tmovs r1, 0x1\n"
    "\tadd r12, r1\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0x14]\n"
    "\tb _08007226\n"
    "\t.align 2, 0\n"
"_080070B0: .4byte 0xfffff000\n"
"_080070B4: .4byte 0x0000f6ef\n"
"_080070B8: .4byte 0x0000f2d9\n"
"_080070BC: .4byte 0x0000f27a\n"
"_080070C0: .4byte 0x0000f6db\n"
"_080070C4: .4byte 0x0000f2db\n"
"_080070C8:\n"
    "\tmovs r2, 0x1\n"
    "\tstr r2, [sp, 0x8]\n"
    "\tldr r5, _08007128\n"
    "\tadds r0, r5, 0\n"
    "\tstrh r0, [r4]\n"
    "\tldr r6, _0800712C\n"
    "\tadds r0, r6, 0\n"
    "\tldr r1, [sp, 0x20]\n"
    "\tstrh r0, [r1]\n"
    "\tldr r2, _08007130\n"
    "\tadds r0, r2, 0\n"
    "\tmov r5, r8\n"
    "\tstrh r0, [r5]\n"
    "\tldr r0, _08007134\n"
    "\tmov r6, r10\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007138\n"
    "\tadds r0, r1, 0\n"
    "\tmov r2, r9\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r5, 0x88\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tldr r6, _08007134\n"
    "\tstrh r6, [r0]\n"
    "\tmovs r0, 0x2\n"
    "\tadd r9, r0\n"
    "\tadd r8, r0\n"
    "\tldr r1, [sp, 0x20]\n"
    "\tadds r1, 0x2\n"
    "\tstr r1, [sp, 0x20]\n"
    "\tadd r10, r0\n"
    "\tadds r4, 0x2\n"
    "\tldr r2, [sp, 0x24]\n"
    "\tadds r2, 0x2\n"
    "\tstr r2, [sp, 0x24]\n"
    "\tmovs r5, 0x1\n"
    "\tadd r12, r5\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800713C\n"
    "\tadds r7, 0x1\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800713C\n"
    "\tldr r6, [sp]\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r6, r1]\n"
    "\tadds r2, r7, r0\n"
    "\tb _0800713E\n"
    "\t.align 2, 0\n"
"_08007128: .4byte 0x0000f2e0\n"
"_0800712C: .4byte 0x0000f2e2\n"
"_08007130: .4byte 0x0000f2da\n"
"_08007134: .4byte 0x0000f2db\n"
"_08007138: .4byte 0x0000f6e7\n"
"_0800713C:\n"
    "\tmovs r2, 0\n"
"_0800713E:\n"
    "\tmovs r5, 0\n"
    "\tstr r5, [sp, 0xC]\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0x14]\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrb r6, [r6, 0x2]\n"
    "\tcmp r5, r6\n"
    "\tbge _080071E0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tadds r0, r1, r0\n"
    "\tldr r3, [sp, 0x24]\n"
    "\tadds r0, r3, r0\n"
    "\tstr r0, [sp, 0x2C]\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r1, r0\n"
    "\tadds r5, r3, r0\n"
    "\tldr r6, [sp, 0x1C]\n"
    "\tadds r3, r6\n"
"_08007168:\n"
    "\tldr r1, _08007310\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r3]\n"
    "\tmovs r6, 0x80\n"
    "\tlsls r6, 4\n"
    "\tadds r6, r3, r6\n"
    "\tstr r6, [sp, 0x28]\n"
    "\tadds r1, 0x1\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r6]\n"
    "\tadds r0, r7, 0\n"
    "\tldr r6, _08007314\n"
    "\torrs r0, r6\n"
    "\tstrh r0, [r5]\n"
    "\tmovs r1, 0x84\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r3, r1\n"
    "\tldr r6, _08007318\n"
    "\tstrh r6, [r0]\n"
    "\tadds r0, r2, 0\n"
    "\tldr r1, _08007314\n"
    "\torrs r0, r1\n"
    "\tldr r6, [sp, 0x2C]\n"
    "\tstrh r0, [r6]\n"
    "\tmovs r1, 0x88\n"
    "\tlsls r1, 4\n"
    "\tadds r0, r3, r1\n"
    "\tldr r6, _08007318\n"
    "\tstrh r6, [r0]\n"
    "\tldr r0, [sp, 0x2C]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x2C]\n"
    "\tadds r5, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tmovs r1, 0x2\n"
    "\tadd r9, r1\n"
    "\tadd r8, r1\n"
    "\tldr r6, [sp, 0x20]\n"
    "\tadds r6, 0x2\n"
    "\tstr r6, [sp, 0x20]\n"
    "\tadd r10, r1\n"
    "\tadds r4, 0x2\n"
    "\tldr r0, [sp, 0x24]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x24]\n"
    "\tmovs r1, 0x1\n"
    "\tadd r12, r1\n"
    "\tcmp r7, 0\n"
    "\tbeq _080071CC\n"
    "\tadds r7, 0x1\n"
"_080071CC:\n"
    "\tcmp r2, 0\n"
    "\tbeq _080071D2\n"
    "\tadds r2, 0x1\n"
"_080071D2:\n"
    "\tldr r6, [sp, 0xC]\n"
    "\tadds r6, 0x1\n"
    "\tstr r6, [sp, 0xC]\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tldrb r0, [r0, 0x2]\n"
    "\tcmp r6, r0\n"
    "\tblt _08007168\n"
"_080071E0:\n"
    "\tldr r1, _0800731C\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r4]\n"
    "\tldr r2, _08007320\n"
    "\tadds r0, r2, 0\n"
    "\tldr r3, [sp, 0x20]\n"
    "\tstrh r0, [r3]\n"
    "\tldr r5, _08007324\n"
    "\tadds r0, r5, 0\n"
    "\tmov r6, r8\n"
    "\tstrh r0, [r6]\n"
    "\tldr r1, _08007318\n"
    "\tmov r0, r10\n"
    "\tstrh r1, [r0]\n"
    "\tadds r2, 0x5\n"
    "\tadds r0, r2, 0\n"
    "\tmov r3, r9\n"
    "\tstrh r0, [r3]\n"
    "\tmovs r5, 0x88\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r4, r5\n"
    "\tstrh r1, [r0]\n"
    "\tmovs r6, 0x2\n"
    "\tadd r9, r6\n"
    "\tadd r8, r6\n"
    "\tldr r0, [sp, 0x20]\n"
    "\tadds r0, 0x2\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tadd r10, r6\n"
    "\tadds r4, 0x2\n"
    "\tldr r1, [sp, 0x24]\n"
    "\tadds r1, 0x2\n"
    "\tstr r1, [sp, 0x24]\n"
    "\tmovs r2, 0x1\n"
    "\tadd r12, r2\n"
"_08007226:\n"
    "\tcmp r7, 0\n"
    "\tbeq _0800722C\n"
    "\tadds r7, 0x1\n"
"_0800722C:\n"
    "\tldr r3, [sp, 0x14]\n"
    "\tldr r5, [sp, 0x4]\n"
    "\tldrb r5, [r5]\n"
    "\tcmp r3, r5\n"
    "\tbge _08007238\n"
    "\tb _08006F56\n"
"_08007238:\n"
    "\tldr r6, [sp]\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r6, r0]\n"
    "\tmovs r2, 0x4\n"
    "\tldrsh r0, [r6, r2]\n"
    "\tadds r0, r1, r0\n"
    "\tcmp r12, r0\n"
    "\tbge _080072BC\n"
    "\tldr r3, _08007328\n"
    "\tadds r4, r3, 0\n"
    "\tmov r8, r0\n"
    "\tmov r5, r12\n"
    "\tlsls r1, r5, 1\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x80\n"
    "\tldr r6, [sp, 0x18]\n"
    "\tadds r0, r6, r0\n"
    "\tadds r5, r1, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r0, 0x40\n"
    "\tadds r0, r6, r0\n"
    "\tadds r3, r1, r0\n"
    "\tldr r0, [sp, 0x50]\n"
    "\tadds r6, r0\n"
    "\tadds r2, r1, r6\n"
    "\tmovs r1, 0x80\n"
    "\tlsls r1, 4\n"
    "\tmov r10, r1\n"
    "\tmovs r6, 0x84\n"
    "\tlsls r6, 4\n"
    "\tmov r9, r6\n"
    "\tmov r0, r8\n"
    "\tmov r1, r12\n"
    "\tsubs r0, r1\n"
    "\tmov r12, r0\n"
"_0800727E:\n"
    "\tstrh r4, [r2]\n"
    "\tmov r6, r10\n"
    "\tadds r0, r2, r6\n"
    "\tldr r1, _0800732C\n"
    "\tstrh r1, [r0]\n"
    "\tstrh r4, [r3]\n"
    "\tmov r6, r9\n"
    "\tadds r0, r2, r6\n"
    "\tstrh r1, [r0]\n"
    "\tadds r1, 0x5F\n"
    "\tadds r0, r1, 0\n"
    "\tstrh r0, [r5]\n"
    "\tmovs r6, 0x88\n"
    "\tlsls r6, 4\n"
    "\tadds r1, r2, r6\n"
    "\tldr r6, _08007318\n"
    "\tadds r0, r6, 0\n"
    "\tstrh r0, [r1]\n"
    "\tadds r5, 0x2\n"
    "\tadds r3, 0x2\n"
    "\tadds r2, 0x2\n"
    "\tmovs r0, 0x1\n"
    "\tnegs r0, r0\n"
    "\tadd r12, r0\n"
    "\tcmp r7, 0\n"
    "\tbeq _080072B4\n"
    "\tadds r7, 0x1\n"
"_080072B4:\n"
    "\tmov r1, r12\n"
    "\tcmp r1, 0\n"
    "\tbne _0800727E\n"
    "\tmov r12, r8\n"
"_080072BC:\n"
    "\tmov r2, r12\n"
    "\tlsls r1, r2, 1\n"
    "\tldr r3, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x50]\n"
    "\tadds r0, r3, r4\n"
    "\tadds r1, r0\n"
    "\tldr r5, _08007328\n"
    "\tadds r3, r5, 0\n"
    "\tstrh r3, [r1]\n"
    "\tmovs r6, 0x80\n"
    "\tlsls r6, 4\n"
    "\tadds r0, r1, r6\n"
    "\tldr r4, _0800732C\n"
    "\tadds r2, r4, 0\n"
    "\tstrh r2, [r0]\n"
    "\tadds r0, r1, 0\n"
    "\tadds r0, 0x40\n"
    "\tstrh r3, [r0]\n"
    "\tmovs r5, 0x84\n"
    "\tlsls r5, 4\n"
    "\tadds r0, r1, r5\n"
    "\tstrh r2, [r0]\n"
    "\tadds r2, r1, 0\n"
    "\tadds r2, 0x80\n"
    "\tldr r6, _08007330\n"
    "\tadds r0, r6, 0\n"
    "\tstrh r0, [r2]\n"
    "\tmovs r0, 0x88\n"
    "\tlsls r0, 4\n"
    "\tadds r1, r0\n"
    "\tldr r2, _08007318\n"
    "\tadds r0, r2, 0\n"
    "\tstrh r0, [r1]\n"
"_080072FE:\n"
    "\tadd sp, 0x30\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08007310: .4byte 0x0000f2e1\n"
"_08007314: .4byte 0xfffff000\n"
"_08007318: .4byte 0x0000f2db\n"
"_0800731C: .4byte 0x0000f6e0\n"
"_08007320: .4byte 0x0000f2e2\n"
"_08007324: .4byte 0x0000f6da\n"
"_08007328: .4byte 0x0000f278\n"
"_0800732C: .4byte 0x0000f27a\n"
"_08007330: .4byte 0x0000f6d8");
}
#endif // NONMATCHING