#include "global.h"
#include "text1.h"
#include "text2.h"

// data.s
extern const u32 gUnknown_80B853C[16];
extern const struct unkShiftData gUnknown_80B85DC[8];
extern const u32 gUnknown_80B8814[];
extern const struct unkStruct_80B8824 gUnknown_80B8824;
extern const struct unkStruct_80B8848 gUnknown_80B8848;

// text.s
extern void sub_8008C6C(struct UnkTextStruct1 *, u32);

void nullsub_129(u32, s32, s32, s32, u32);
u32 xxx_draw_char(struct UnkTextStruct1 *, s32, s32, u32, u32, u32);

void sub_800677C(struct UnkTextStruct1 *, s32, u16 *, u8);
void sub_80069CC(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006AC4(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006B70(struct UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006C44(struct UnkTextStruct1 *, s32, u16 *, u8);
void sub_8006E94(struct UnkTextStruct1 *, s32, u32, const u8 *, u16 *);
void sub_8007958(struct UnkTextStruct1 *, u32, s32, s32, s32, u32);
void sub_8007AA4(struct UnkTextStruct1 *, u32, s32, s32, s32, u32);
void sub_8007BA8(struct UnkTextStruct1 *, u32, s32, s32, s32, u32);

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
void sub_8006554(struct UnkTextStruct1 *a0, u32 *a1, u32 *a2, u16 *a3, u32 a4, const struct UnkTextStruct2 *a5, u8 a6, u32 a7, struct UnkTextStruct2_sub *a8, u8 a9)
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

    t1->unk18 = &a2[t1->unk10 * 8];
    t1->unk1C = &a2[t1->unk14 * 8];
    t1->unk24 = a5->unk12;
    t1->unk28 = &a1[t1->unk14 * 8];

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

#ifdef NONMATCHING // https://decomp.me/scratch/zVTOf
void sub_8007334(s32 a0)
{
    s32 r1;
    s32 r2;
    struct UnkTextStruct1 *r3;
    s32 r4;
    u32 r5;
    s32 r6;
    s16 typeCheater;

    r3 = &gUnknown_2027370[a0];
    r5 = r3->unk14;
    r6 = r3->unk2;
    for (r2 = 0; r2 < r3->unk6; r6++, r2++) {
        typeCheater = r3->unk0;
        r1 = typeCheater;
        for (r4 = 0; r4 < r3->unk4; r4++) {
            typeCheater = r1;
            gUnknown_202B038[0][r6][typeCheater + r4] &= 0xFC00;
            gUnknown_202B038[0][r6][typeCheater + r4] |= r5++;
        }
    }
}
#else
NAKED
void sub_8007334(s32 a0)
{
    asm_unified(
    "\tpush {r4-r7,lr}\n"
    "\tmov r7, r9\n"
    "\tmov r6, r8\n"
    "\tpush {r6,r7}\n"
    "\tlsls r1, r0, 3\n"
    "\tadds r1, r0\n"
    "\tlsls r1, 3\n"
    "\tldr r0, _080073AC\n"
    "\tadds r3, r1, r0\n"
    "\tldr r5, [r3, 0x14]\n"
    "\tmovs r0, 0x2\n"
    "\tldrsh r6, [r3, r0]\n"
    "\tmovs r2, 0\n"
    "\tmovs r1, 0x6\n"
    "\tldrsh r0, [r3, r1]\n"
    "\tcmp r2, r0\n"
    "\tbge _080073A0\n"
    "\tldr r7, _080073B0\n"
    "\tmov r9, r7\n"
"_0800735A:\n"
    "\tmovs r0, 0\n"
    "\tldrsh r1, [r3, r0]\n"
    "\tmovs r4, 0\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r3, r7]\n"
    "\tadds r7, r6, 0x1\n"
    "\tadds r2, 0x1\n"
    "\tmov r12, r2\n"
    "\tcmp r4, r0\n"
    "\tbge _08007394\n"
    "\tmovs r0, 0xFC\n"
    "\tlsls r0, 8\n"
    "\tmov r8, r0\n"
    "\tlsls r1, 1\n"
    "\tlsls r0, r6, 6\n"
    "\tadd r0, r9\n"
    "\tadds r2, r1, r0\n"
"_0800737C:\n"
    "\tldrh r0, [r2]\n"
    "\tmov r1, r8\n"
    "\tands r1, r0\n"
    "\torrs r1, r5\n"
    "\tstrh r1, [r2]\n"
    "\tadds r2, 0x2\n"
    "\tadds r5, 0x1\n"
    "\tadds r4, 0x1\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r3, r1]\n"
    "\tcmp r4, r0\n"
    "\tblt _0800737C\n"
"_08007394:\n"
    "\tadds r6, r7, 0\n"
    "\tmov r2, r12\n"
    "\tmovs r7, 0x6\n"
    "\tldrsh r0, [r3, r7]\n"
    "\tcmp r2, r0\n"
    "\tblt _0800735A\n"
"_080073A0:\n"
    "\tpop {r3,r4}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_080073AC: .4byte gUnknown_2027370\n"
"_080073B0: .4byte gUnknown_202B038");
}
#endif // NONMATCHING

// Unused
void nullsub_154(void)
{
}

void sub_80073B8(s32 a0)
{
    struct UnkTextStruct1 *r1;

    r1 = &gUnknown_2027370[a0];

    r1->unk3C = &r1->unk1C[(u32)r1->unk2C >> 2];
    r1->unk40 = r1->unk1C;
    r1->unk46 = 1;
}

// Unused
void nullsub_155(void)
{
}

void sub_80073E0(s32 a0)
{
    struct UnkTextStruct1 *r1;

    r1 = &gUnknown_2027370[a0];

    if (r1->unk44 == 0) {
        r1->unk30 = &r1->unk28[r1->unk3C - r1->unk1C];
        r1->unk34 = r1->unk3C;
        r1->unk38 = (r1->unk40 - r1->unk3C + 1) * 4;

        if (r1->unk38 >= r1->unk2C)
            r1->unk38 = r1->unk2C;

        if (r1->unk38 < 0)
            r1->unk38 = 0;
    }

    r1->unk46 = 0;
}

// Unused
void nullsub_156(void)
{
}

u32 xxx_call_draw_char(s32 x, s32 y, u32 a2, u32 color, u32 a4)
{ 
    return xxx_draw_char(gUnknown_2027370, x, y, a2, color, a4);
}

// Unused
bool8 sub_8007464(void)
{
    return FALSE;
}

// https://decomp.me/scratch/F06Ty
NAKED
u32 xxx_draw_char(struct UnkTextStruct1 *a0, s32 x, s32 y, u32 a3, u32 color, u32 a5)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x28\n"
    "\tadds r6, r1, 0\n"
    "\tmov r10, r2\n"
    "\tadds r4, r3, 0\n"
    "\tldr r2, [sp, 0x48]\n"
    "\tldr r3, [sp, 0x4C]\n"
    "\tlsls r1, r3, 3\n"
    "\tadds r1, r3\n"
    "\tlsls r1, 3\n"
    "\tadds r5, r0, r1\n"
    "\tldr r1, _080074B8\n"
    "\tmovs r0, 0xF\n"
    "\tands r2, r0\n"
    "\tlsls r2, 2\n"
    "\tadds r2, r1\n"
    "\tldr r2, [r2]\n"
    "\tstr r2, [sp, 0x18]\n"
    "\tldr r0, _080074BC\n"
    "\tldr r0, [r0]\n"
    "\tcmp r0, 0x1\n"
    "\tbne _080074CC\n"
    "\tcmp r4, 0x70\n"
    "\tbeq _080074B0\n"
    "\tcmp r4, 0x6A\n"
    "\tbeq _080074B0\n"
    "\tcmp r4, 0x71\n"
    "\tbeq _080074B0\n"
    "\tcmp r4, 0x79\n"
    "\tbeq _080074B0\n"
    "\tcmp r4, 0x67\n"
    "\tbne _080074C0\n"
"_080074B0:\n"
    "\tmovs r0, 0x2\n"
    "\tadd r10, r0\n"
    "\tb _080074CC\n"
    "\t.align 2, 0\n"
"_080074B8: .4byte gUnknown_80B853C\n"
"_080074BC: .4byte gCurrentCharmap\n"
"_080074C0:\n"
    "\tldr r0, _080074F8\n"
    "\tcmp r4, r0\n"
    "\tbne _080074CC\n"
    "\tmovs r1, 0x2\n"
    "\tnegs r1, r1\n"
    "\tadd r10, r1\n"
"_080074CC:\n"
    "\tadds r0, r4, 0\n"
    "\tbl GetCharacter\n"
    "\tstr r0, [sp]\n"
    "\tldr r2, [r0]\n"
    "\tstr r2, [sp, 0x4]\n"
    "\tstr r2, [sp, 0xC]\n"
    "\tadds r3, r2, 0\n"
    "\tsubs r3, 0x6\n"
    "\tstr r3, [sp, 0x8]\n"
    "\tldr r0, _080074FC\n"
    "\tldrb r0, [r0]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08007500\n"
    "\tldr r4, [sp]\n"
    "\tldrb r1, [r4, 0xA]\n"
    "\tlsrs r7, r1, 1\n"
    "\tmovs r0, 0x1\n"
    "\tadds r2, r7, 0\n"
    "\tands r2, r0\n"
    "\tstr r2, [sp, 0x1C]\n"
    "\tb _08007508\n"
    "\t.align 2, 0\n"
"_080074F8: .4byte 0x00008199\n"
"_080074FC: .4byte gUnknown_202B034\n"
"_08007500:\n"
    "\tmovs r3, 0\n"
    "\tstr r3, [sp, 0x1C]\n"
    "\tldr r4, [sp]\n"
    "\tldrb r1, [r4, 0xA]\n"
"_08007508:\n"
    "\tmovs r0, 0x1\n"
    "\tands r0, r1\n"
    "\tcmp r0, 0\n"
    "\tbne _08007512\n"
    "\tb _08007670\n"
"_08007512:\n"
    "\tmov r0, r10\n"
    "\tcmp r0, 0\n"
    "\tbge _0800751A\n"
    "\tadds r0, 0x7\n"
"_0800751A:\n"
    "\tasrs r4, r0, 3\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r5, r7]\n"
    "\tmuls r0, r4\n"
    "\tadds r2, r6, 0\n"
    "\tcmp r6, 0\n"
    "\tbge _0800752A\n"
    "\tadds r2, r6, 0x7\n"
"_0800752A:\n"
    "\tasrs r2, 3\n"
    "\tadds r0, r2\n"
    "\tlsls r0, 5\n"
    "\tldr r1, [r5, 0x18]\n"
    "\tadds r3, r1, r0\n"
    "\tlsls r0, r4, 3\n"
    "\tmov r1, r10\n"
    "\tsubs r0, r1, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r3, r0\n"
    "\tlsls r0, r2, 3\n"
    "\tsubs r0, r6, r0\n"
    "\tlsls r0, 4\n"
    "\tldr r1, _08007664\n"
    "\tadds r0, r1\n"
    "\tmov r12, r0\n"
    "\tmov r9, r2\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r5, r2]\n"
    "\tcmp r4, r0\n"
    "\tblt _08007558\n"
    "\tb _0800786C\n"
"_08007558:\n"
    "\tmovs r4, 0\n"
    "\tstr r4, [sp, 0x10]\n"
    "\tldr r2, _08007668\n"
    "\tldr r1, _0800766C\n"
    "\tldr r0, [r1]\n"
    "\tlsls r0, 2\n"
    "\tadds r0, r2\n"
    "\tldr r0, [r0]\n"
    "\tcmp r4, r0\n"
    "\tblt _0800756E\n"
    "\tb _0800786C\n"
"_0800756E:\n"
    "\tadds r4, r2, 0\n"
"_08007570:\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrh r0, [r6, 0x2]\n"
    "\tlsls r2, r0, 16\n"
    "\tldrh r0, [r6]\n"
    "\torrs r2, r0\n"
    "\tcmp r2, 0\n"
    "\tbeq _080075CC\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r5, r7]\n"
    "\tcmp r9, r0\n"
    "\tbge _080075A6\n"
    "\tmov r0, r12\n"
    "\tldr r1, [r0]\n"
    "\tands r1, r2\n"
    "\tldr r0, [r0, 0x8]\n"
    "\tlsls r1, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r1\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x3C]\n"
    "\tcmp r0, r3\n"
    "\tbls _0800759E\n"
    "\tstr r3, [r5, 0x3C]\n"
"_0800759E:\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _080075A6\n"
    "\tstr r3, [r5, 0x40]\n"
"_080075A6:\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r9, r0\n"
    "\tbge _080075CC\n"
    "\tadds r3, 0x20\n"
    "\tmov r6, r12\n"
    "\tldr r0, [r6, 0x4]\n"
    "\tands r2, r0\n"
    "\tldr r0, [r6, 0xC]\n"
    "\tlsrs r2, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r2\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _080075CA\n"
    "\tstr r3, [r5, 0x40]\n"
"_080075CA:\n"
    "\tsubs r3, 0x20\n"
"_080075CC:\n"
    "\tldr r7, [sp, 0x4]\n"
    "\tldrh r2, [r7, 0x4]\n"
    "\tcmp r2, 0\n"
    "\tbeq _08007620\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r9, r0\n"
    "\tbge _080075FA\n"
    "\tadds r3, 0x20\n"
    "\tmov r6, r12\n"
    "\tldr r1, [r6]\n"
    "\tands r1, r2\n"
    "\tldr r0, [r6, 0x8]\n"
    "\tlsls r1, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r1\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _080075F8\n"
    "\tstr r3, [r5, 0x40]\n"
"_080075F8:\n"
    "\tsubs r3, 0x20\n"
"_080075FA:\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r5, r7]\n"
    "\tsubs r0, 0x2\n"
    "\tcmp r9, r0\n"
    "\tbge _08007620\n"
    "\tadds r3, 0x40\n"
    "\tmov r1, r12\n"
    "\tldr r0, [r1, 0x4]\n"
    "\tands r2, r0\n"
    "\tldr r0, [r1, 0xC]\n"
    "\tlsrs r2, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r2\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _0800761E\n"
    "\tstr r3, [r5, 0x40]\n"
"_0800761E:\n"
    "\tsubs r3, 0x40\n"
"_08007620:\n"
    "\tldr r2, [sp, 0x4]\n"
    "\tadds r2, 0x6\n"
    "\tstr r2, [sp, 0x4]\n"
    "\tadds r3, 0x4\n"
    "\tmovs r6, 0x1\n"
    "\tadd r10, r6\n"
    "\tmovs r0, 0x7\n"
    "\tmov r7, r10\n"
    "\tands r0, r7\n"
    "\tcmp r0, 0\n"
    "\tbne _0800764E\n"
    "\tldr r0, [r5, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r3, r0\n"
    "\tldr r0, [sp, 0x14]\n"
    "\tadds r0, 0x1\n"
    "\tstr r0, [sp, 0x14]\n"
    "\tmovs r1, 0x8\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tldr r2, [sp, 0x14]\n"
    "\tcmp r2, r0\n"
    "\tblt _0800764E\n"
    "\tb _0800786C\n"
"_0800764E:\n"
    "\tldr r6, [sp, 0x10]\n"
    "\tadds r6, 0x1\n"
    "\tstr r6, [sp, 0x10]\n"
    "\tldr r7, _0800766C\n"
    "\tldr r0, [r7]\n"
    "\tlsls r0, 2\n"
    "\tadds r0, r4\n"
    "\tldr r0, [r0]\n"
    "\tcmp r6, r0\n"
    "\tblt _08007570\n"
    "\tb _0800786C\n"
    "\t.align 2, 0\n"
"_08007664: .4byte gUnknown_80B85DC\n"
"_08007668: .4byte gUnknown_202B028\n"
"_0800766C: .4byte gCurrentCharmap\n"
"_08007670:\n"
    "\tmovs r0, 0\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tmov r0, r10\n"
    "\tcmp r0, 0\n"
    "\tbge _0800767C\n"
    "\tadds r0, 0x7\n"
"_0800767C:\n"
    "\tasrs r4, r0, 3\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tadds r1, r4, 0\n"
    "\tmuls r1, r0\n"
    "\tadds r0, r6, 0\n"
    "\tcmp r6, 0\n"
    "\tbge _0800768E\n"
    "\tadds r0, r6, 0x7\n"
"_0800768E:\n"
    "\tasrs r2, r0, 3\n"
    "\tadds r0, r1, r2\n"
    "\tlsls r0, 5\n"
    "\tldr r1, [r5, 0x18]\n"
    "\tadds r3, r1, r0\n"
    "\tlsls r0, r4, 3\n"
    "\tmov r7, r10\n"
    "\tsubs r0, r7, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r3, r0\n"
    "\tlsls r0, r2, 3\n"
    "\tsubs r0, r6, r0\n"
    "\tlsls r0, 4\n"
    "\tldr r1, _0800788C\n"
    "\tadds r0, r1\n"
    "\tmov r12, r0\n"
    "\tmov r9, r2\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tmovs r1, 0x8\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tcmp r4, r0\n"
    "\tblt _080076BC\n"
    "\tb _0800786C\n"
"_080076BC:\n"
    "\tmovs r2, 0\n"
    "\tstr r2, [sp, 0x10]\n"
    "\tldr r2, _08007890\n"
    "\tldr r1, _08007894\n"
    "\tldr r0, [r1]\n"
    "\tlsls r0, 2\n"
    "\tadds r0, r2\n"
    "\tldr r0, [r0]\n"
    "\tldr r4, [sp, 0x10]\n"
    "\tcmp r4, r0\n"
    "\tblt _080076D4\n"
    "\tb _0800786C\n"
"_080076D4:\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrh r0, [r6, 0x2]\n"
    "\tlsls r4, r0, 16\n"
    "\tldrh r0, [r6]\n"
    "\torrs r4, r0\n"
    "\tldr r1, _08007898\n"
    "\tands r1, r4\n"
    "\tldr r0, [sp, 0x18]\n"
    "\tands r0, r4\n"
    "\tadds r2, r1, r0\n"
    "\tldr r7, [sp, 0x1C]\n"
    "\tcmp r7, 0\n"
    "\tbeq _08007724\n"
    "\tldr r1, [sp, 0xC]\n"
    "\tldrh r0, [r1, 0x2]\n"
    "\tlsls r0, 16\n"
    "\tldrh r1, [r1]\n"
    "\torrs r0, r1\n"
    "\tlsls r1, r0, 4\n"
    "\tmvns r6, r4\n"
    "\tmov r8, r6\n"
    "\tbics r1, r4\n"
    "\tldr r7, _0800789C\n"
    "\tldr r6, [r7]\n"
    "\tands r1, r6\n"
    "\torrs r2, r1\n"
    "\tldr r0, [sp, 0x20]\n"
    "\tcmp r0, 0\n"
    "\tbeq _08007724\n"
    "\tldr r1, [sp, 0x8]\n"
    "\tldrh r0, [r1, 0x2]\n"
    "\tlsls r0, 16\n"
    "\tldrh r1, [r1]\n"
    "\torrs r0, r1\n"
    "\tlsls r1, r0, 4\n"
    "\teors r1, r4\n"
    "\tmov r4, r8\n"
    "\tands r1, r4\n"
    "\tands r1, r6\n"
    "\torrs r2, r1\n"
"_08007724:\n"
    "\tcmp r2, 0\n"
    "\tbeq _08007776\n"
    "\tmovs r6, 0x4\n"
    "\tldrsh r0, [r5, r6]\n"
    "\tcmp r9, r0\n"
    "\tbge _08007750\n"
    "\tmov r7, r12\n"
    "\tldr r1, [r7]\n"
    "\tands r1, r2\n"
    "\tldr r0, [r7, 0x8]\n"
    "\tlsls r1, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r1\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x3C]\n"
    "\tcmp r0, r3\n"
    "\tbls _08007748\n"
    "\tstr r3, [r5, 0x3C]\n"
"_08007748:\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _08007750\n"
    "\tstr r3, [r5, 0x40]\n"
"_08007750:\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r9, r0\n"
    "\tbge _08007776\n"
    "\tadds r3, 0x20\n"
    "\tmov r4, r12\n"
    "\tldr r0, [r4, 0x4]\n"
    "\tands r2, r0\n"
    "\tldr r0, [r4, 0xC]\n"
    "\tlsrs r2, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r2\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _08007774\n"
    "\tstr r3, [r5, 0x40]\n"
"_08007774:\n"
    "\tsubs r3, 0x20\n"
"_08007776:\n"
    "\tldr r6, [sp, 0x4]\n"
    "\tldrh r4, [r6, 0x4]\n"
    "\tldr r1, _08007898\n"
    "\tands r1, r4\n"
    "\tldr r0, [sp, 0x18]\n"
    "\tands r0, r4\n"
    "\tadds r2, r1, r0\n"
    "\tldr r7, [sp, 0x1C]\n"
    "\tcmp r7, 0\n"
    "\tbeq _080077CC\n"
    "\tldr r1, [sp, 0xC]\n"
    "\tldrh r0, [r1, 0x4]\n"
    "\tlsls r1, r0, 4\n"
    "\tldr r6, [sp, 0xC]\n"
    "\tldrh r0, [r6, 0x2]\n"
    "\tmovs r7, 0xF\n"
    "\tmov r8, r7\n"
    "\tlsrs r0, 12\n"
    "\torrs r1, r0\n"
    "\tmvns r0, r4\n"
    "\tstr r0, [sp, 0x24]\n"
    "\tbics r1, r4\n"
    "\tldr r7, _0800789C\n"
    "\tldr r6, [r7]\n"
    "\tands r1, r6\n"
    "\torrs r2, r1\n"
    "\tldr r0, [sp, 0x20]\n"
    "\tcmp r0, 0\n"
    "\tbeq _080077CC\n"
    "\tldr r1, [sp, 0x8]\n"
    "\tldrh r0, [r1, 0x4]\n"
    "\tlsls r1, r0, 4\n"
    "\tldr r7, [sp, 0x8]\n"
    "\tldrh r0, [r7, 0x2]\n"
    "\tlsrs r0, 12\n"
    "\tmov r7, r8\n"
    "\tands r0, r7\n"
    "\torrs r1, r0\n"
    "\teors r1, r4\n"
    "\tldr r0, [sp, 0x24]\n"
    "\tands r1, r0\n"
    "\tands r1, r6\n"
    "\torrs r2, r1\n"
"_080077CC:\n"
    "\tcmp r2, 0\n"
    "\tbeq _0800781C\n"
    "\tmovs r1, 0x4\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tsubs r0, 0x1\n"
    "\tcmp r9, r0\n"
    "\tbge _080077F6\n"
    "\tadds r3, 0x20\n"
    "\tmov r4, r12\n"
    "\tldr r1, [r4]\n"
    "\tands r1, r2\n"
    "\tldr r0, [r4, 0x8]\n"
    "\tlsls r1, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r1\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _080077F4\n"
    "\tstr r3, [r5, 0x40]\n"
"_080077F4:\n"
    "\tsubs r3, 0x20\n"
"_080077F6:\n"
    "\tmovs r6, 0x4\n"
    "\tldrsh r0, [r5, r6]\n"
    "\tsubs r0, 0x2\n"
    "\tcmp r9, r0\n"
    "\tbge _0800781C\n"
    "\tadds r3, 0x40\n"
    "\tmov r7, r12\n"
    "\tldr r0, [r7, 0x4]\n"
    "\tands r2, r0\n"
    "\tldr r0, [r7, 0xC]\n"
    "\tlsrs r2, r0\n"
    "\tldr r0, [r3]\n"
    "\torrs r0, r2\n"
    "\tstr r0, [r3]\n"
    "\tldr r0, [r5, 0x40]\n"
    "\tcmp r0, r3\n"
    "\tbcs _0800781A\n"
    "\tstr r3, [r5, 0x40]\n"
"_0800781A:\n"
    "\tsubs r3, 0x40\n"
"_0800781C:\n"
    "\tmovs r0, 0x1\n"
    "\tstr r0, [sp, 0x20]\n"
    "\tldr r1, [sp, 0x4]\n"
    "\tadds r1, 0x6\n"
    "\tstr r1, [sp, 0x4]\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tadds r2, 0x6\n"
    "\tstr r2, [sp, 0x8]\n"
    "\tldr r4, [sp, 0xC]\n"
    "\tadds r4, 0x6\n"
    "\tstr r4, [sp, 0xC]\n"
    "\tadds r3, 0x4\n"
    "\tadd r10, r0\n"
    "\tmovs r0, 0x7\n"
    "\tmov r6, r10\n"
    "\tands r0, r6\n"
    "\tcmp r0, 0\n"
    "\tbne _08007854\n"
    "\tldr r0, [r5, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r3, r0\n"
    "\tldr r7, [sp, 0x14]\n"
    "\tadds r7, 0x1\n"
    "\tstr r7, [sp, 0x14]\n"
    "\tmovs r1, 0x8\n"
    "\tldrsh r0, [r5, r1]\n"
    "\tcmp r7, r0\n"
    "\tbge _0800786C\n"
"_08007854:\n"
    "\tldr r2, [sp, 0x10]\n"
    "\tadds r2, 0x1\n"
    "\tstr r2, [sp, 0x10]\n"
    "\tldr r4, _08007894\n"
    "\tldr r0, [r4]\n"
    "\tlsls r0, 2\n"
    "\tldr r6, _08007890\n"
    "\tadds r0, r6\n"
    "\tldr r0, [r0]\n"
    "\tcmp r2, r0\n"
    "\tbge _0800786C\n"
    "\tb _080076D4\n"
"_0800786C:\n"
    "\tldr r7, [sp]\n"
    "\tmovs r1, 0x6\n"
    "\tldrsh r0, [r7, r1]\n"
    "\tldr r2, _080078A0\n"
    "\tmovs r3, 0\n"
    "\tldrsh r1, [r2, r3]\n"
    "\tadds r0, r1\n"
    "\tadd sp, 0x28\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r1}\n"
    "\tbx r1\n"
    "\t.align 2, 0\n"
"_0800788C: .4byte gUnknown_80B85DC\n"
"_08007890: .4byte gUnknown_202B028\n"
"_08007894: .4byte gCurrentCharmap\n"
"_08007898: .4byte 0x11111111\n"
"_0800789C: .4byte gUnknown_202B030\n"
"_080078A0: .4byte gCharacterSpacing");
}

void sub_80078A4(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_800792C(a0, x, y, a3, color);
    sub_800792C(a0, x, y + 1, a3, gUnknown_202B030 & 0xF);
}

// Unused
void sub_80078E8(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    nullsub_129(a0, x, y, a3, color);
    nullsub_129(a0, x, y + 1, a3, gUnknown_202B030 & 0xF);
}

void sub_800792C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{ 
    sub_8007958(gUnknown_2027370, a0, x, y, a3, color);
}

void nullsub_129(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
}

void sub_8007958(struct UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    u32 uVar4;
    u32 *dest;
    s32 r4;
    const struct unkShiftData *shiftData;
    struct UnkTextStruct1 *r5;
    s32 r6;
    u32 r9;
    struct unkStruct_80B8824 dataLOL;

    r5 = &a0[a1];
    r9 = gUnknown_80B853C[color & 0xf];

    r4 = y / 8;

    dest = r5->unk18 + ((r5->unk4 * r4 + x / 8) * 8);
    dest += (r4 * -8 + y);
    r6 = x / 8;

    if (y / 8 >= r5->unk8)
        return;

    dataLOL = gUnknown_80B8824;

    for (; a4 > 0; a4 -= 8) {
        s32 lol = a4;
        if (lol > 7)
            lol = 8;

        shiftData = &gUnknown_80B85DC[x + (x / 8 * -8)];

        uVar4 = dataLOL.arr[lol];
        uVar4 = (uVar4 & 0x11111111) + (uVar4 & r9);

        if (uVar4 != 0) {
            if (r6 < r5->unk4) {
                dest[0] |= (shiftData->bytesA & uVar4) << shiftData->shift_left;

                if (r5->unk3C > dest)
                    r5->unk3C = dest;
                if (r5->unk40 < dest)
                    r5->unk40 = dest;
            }

            if (r6 < r5->unk4 - 1) {
                dest += 8;
                dest[0] |= (uVar4 & shiftData->bytesB) >> shiftData->shift_right;

                if (r5->unk40 < dest)
                    r5->unk40 = dest;
                dest -= 8;
            }
        }

        r6++;
        dest += 8;
    }
}

void sub_8007A78(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007AA4(gUnknown_2027370, a0, x, y, a3, color);
}

// Unused
void nullsub_157(void)
{
}

NAKED // https://decomp.me/scratch/xE2Tn
void sub_8007AA4(struct UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r9\n"
    "\tmov r6, r8\n"
    "\tpush {r6,r7}\n"
    "\tsub sp, 0x20\n"
    "\tmov r9, r2\n"
    "\tadds r5, r3, 0\n"
    "\tldr r7, [sp, 0x3C]\n"
    "\tldr r3, [sp, 0x40]\n"
    "\tlsls r2, r1, 3\n"
    "\tadds r2, r1\n"
    "\tlsls r2, 3\n"
    "\tadds r4, r0, r2\n"
    "\tldr r1, _08007B28\n"
    "\tmovs r0, 0xF\n"
    "\tands r3, r0\n"
    "\tlsls r3, 2\n"
    "\tadds r3, r1\n"
    "\tldr r0, [r3]\n"
    "\tldr r1, _08007B2C\n"
    "\tadds r1, r0\n"
    "\tmov r12, r1\n"
    "\tmov r1, sp\n"
    "\tldr r0, _08007B30\n"
    "\tldm r0!, {r2,r3,r6}\n"
    "\tstm r1!, {r2,r3,r6}\n"
    "\tldm r0!, {r2,r3,r6}\n"
    "\tstm r1!, {r2,r3,r6}\n"
    "\tldm r0!, {r2,r3}\n"
    "\tstm r1!, {r2,r3}\n"
    "\tadds r0, r5, 0\n"
    "\tcmp r5, 0\n"
    "\tbge _08007AE8\n"
    "\tadds r0, r5, 0x7\n"
"_08007AE8:\n"
    "\tasrs r3, r0, 3\n"
    "\tmovs r0, 0x4\n"
    "\tldrsh r6, [r4, r0]\n"
    "\tmov r8, r6\n"
    "\tmov r0, r8\n"
    "\tmuls r0, r3\n"
    "\tmov r2, r9\n"
    "\tcmp r2, 0\n"
    "\tbge _08007AFC\n"
    "\tadds r2, 0x7\n"
"_08007AFC:\n"
    "\tasrs r2, 3\n"
    "\tadds r0, r2\n"
    "\tlsls r0, 5\n"
    "\tldr r1, [r4, 0x18]\n"
    "\tadds r1, r0\n"
    "\tlsls r0, r3, 3\n"
    "\tsubs r0, r5, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r1, r0\n"
    "\tmovs r0, 0x7\n"
    "\tmov r6, r9\n"
    "\tands r0, r6\n"
    "\tlsls r0, 2\n"
    "\tadd r0, sp\n"
    "\tldr r0, [r0]\n"
    "\tmov r6, r12\n"
    "\tands r6, r0\n"
    "\tmov r12, r6\n"
    "\tcmp r2, r8\n"
    "\tbge _08007B6E\n"
    "\tb _08007B48\n"
    "\t.align 2, 0\n"
"_08007B28: .4byte gUnknown_80B853C\n"
"_08007B2C: .4byte 0x11111111\n"
"_08007B30: .4byte gUnknown_80B8848\n"
"_08007B34:\n"
    "\tadds r5, 0x1\n"
    "\tadds r1, 0x4\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r5\n"
    "\tcmp r0, 0\n"
    "\tbne _08007B46\n"
    "\tldr r0, [r4, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r1, r0\n"
"_08007B46:\n"
    "\tsubs r7, 0x1\n"
"_08007B48:\n"
    "\tcmp r7, 0\n"
    "\tble _08007B6E\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r4, r2]\n"
    "\tcmp r3, r0\n"
    "\tbge _08007B6E\n"
    "\tldr r0, [r1]\n"
    "\tmov r6, r12\n"
    "\torrs r0, r6\n"
    "\tstr r0, [r1]\n"
    "\tldr r0, [r4, 0x3C]\n"
    "\tcmp r0, r1\n"
    "\tbls _08007B64\n"
    "\tstr r1, [r4, 0x3C]\n"
"_08007B64:\n"
    "\tldr r0, [r4, 0x40]\n"
    "\tcmp r0, r1\n"
    "\tbcs _08007B34\n"
    "\tstr r1, [r4, 0x40]\n"
    "\tb _08007B34\n"
"_08007B6E:\n"
    "\tadd sp, 0x20\n"
    "\tpop {r3,r4}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}

void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007BA8(gUnknown_2027370, a0, x, y, a3, color);
}

// Unused
void nullsub_158(void)
{
}