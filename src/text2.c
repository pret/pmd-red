#include "global.h"
#include "text1.h"
#include "text2.h"
#include "decompress.h"
#include "code_8009804.h"
#include "cpu.h"
#include "structs/str_text.h"

// data.s
extern const u32 gUnknown_80B853C[16];
extern const struct unkShiftData gCharMasksOffsets[8];
extern const u32 gUnknown_80B8814[];
extern const struct unkStruct_80B8824 gUnknown_80B8824;
extern const struct unkStruct_80B8848 gUnknown_80B8848;

// text.s
void sub_8007E64(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);
extern void PrepareTextbox_8008C6C(UnkTextStruct1 *, u32);

void nullsub_129(u32, s32, s32, s32, u32);
u32 xxx_draw_char(UnkTextStruct1 *, s32, s32, u32, u32, u32);

void sub_800677C(UnkTextStruct1 *, s32, u16 *, u8);
void sub_80069CC(UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006AC4(UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006B70(UnkTextStruct1 *, s32, s32, s32, u16 *);
void sub_8006C44(UnkTextStruct1 *, s32, u16 *, u8);
void sub_8006E94(UnkTextStruct1 *, s32, u32, const UnkTextStruct2_sub2 *, u16 *);
void sub_8007958(UnkTextStruct1 *, u32, s32, s32, s32, u32);
void sub_8007AA4(UnkTextStruct1 *, u32, s32, s32, s32, u32);
void sub_8007BA8(UnkTextStruct1 *, u32, s32, s32, s32, s32);
void sub_8007D00(UnkTextStruct1 *, u32, s32, s32, s32, s32);

void nullsub_152(void)
{
}

void RestoreUnkTextStruct_8006518(UnkTextStruct2 *unkData)
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
void sub_8006554(UnkTextStruct1 *a0, u32 *a1, u32 *a2, u16 *a3, u32 a4, const UnkTextStruct2 *a5, bool8 a6, u32 a7, UnkTextStruct2_sub *a8, u8 a9)
{
    UnkTextStruct1 *t1;
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
            uVar1 = a6 ? t1->unk14 : 0;

            sub_8006E94(t1, temp, uVar1, a5->unk14, a3);

            temp = iVar5 + 2;
            uVar1 = a6 ? t1->unk14 + t1->unk4 * (a5->unk12 + 2) : 0;
            numI = t1->unk6 - 2;
        }
        else {
            sub_800677C(t1, temp, a3, a9);

            temp = iVar5;
            uVar1 = a6 ? t1->unk14 : 0;
            numI = t1->unk6;
        }

        for (i = 0; i < numI; i++) {
            iVar6 = iVar3 - 1;
            sub_80069CC(t1, iVar6, temp, i, a3);
            iVar6 = iVar3;

            for (j = 0; j < t1->unk4; j++) {
                sub_8006AC4(t1, iVar6, temp, uVar1, a3);

                iVar6++;
                if (a6)
                    uVar1++;
            }

            sub_8006B70(t1, iVar6, temp, i, a3);
            temp++;
        }
        sub_8006C44(t1, temp, a3, a9);
    }

    if ((a5->unk0 & 0x80) == 0)
        PrepareTextbox_8008C6C(a0, a4);

    t1->unk46 = 0;
}

void sub_800677C(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
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

void sub_80069CC(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
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

void sub_8006AC4(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
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

void sub_8006B70(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, u16 *a4)
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

void sub_8006C44(UnkTextStruct1 *a0, s32 a1, u16 *a2, u8 a3)
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

// Not even close but I don't feel like continuing atm https://decomp.me/scratch/F58jg
/*
void sub_8006E94(UnkTextStruct1 *a0, s32 a1, u32 a2, const UnkTextStruct2_sub2 *a3, u16 *a4)
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
*/
NAKED
void sub_8006E94(UnkTextStruct1 *a0, s32 a1, u32 a2, const UnkTextStruct2_sub2 *a3, u16 *a4)
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

#ifdef NONMATCHING // https://decomp.me/scratch/zVTOf
void sub_8007334(s32 a0)
{
    s32 r1;
    s32 r2;
    UnkTextStruct1 *r3;
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

UNUSED static void nullsub_154(void)
{
}

void sub_80073B8(s32 a0)
{
    UnkTextStruct1 *r1;

    r1 = &gUnknown_2027370[a0];

    r1->unk3C = &r1->unk1C[(u32)r1->unk2C >> 2];
    r1->unk40 = r1->unk1C;
    r1->unk46 = 1;
}

UNUSED static void nullsub_155(void)
{
}

void sub_80073E0(s32 a0)
{
    UnkTextStruct1 *r1;

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

UNUSED static void nullsub_156(void)
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
u32 xxx_draw_char(UnkTextStruct1 *a0, s32 x, s32 y, u32 a3, u32 color, u32 a5)
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
"_080074FC: .4byte gDrawTextShadow\n"
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
"_08007664: .4byte gCharMasksOffsets\n"
"_08007668: .4byte gCharHeight\n"
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
"_0800788C: .4byte gCharMasksOffsets\n"
"_08007890: .4byte gCharHeight\n"
"_08007894: .4byte gCurrentCharmap\n"
"_08007898: .4byte 0x11111111\n"
"_0800789C: .4byte gTextShadowMask\n"
"_080078A0: .4byte gCharacterSpacing");
}

void sub_80078A4(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_800792C(a0, x, y, a3, color);
    sub_800792C(a0, x, y + 1, a3, gTextShadowMask & 0xF);
}

UNUSED static void sub_80078E8(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    nullsub_129(a0, x, y, a3, color);
    nullsub_129(a0, x, y + 1, a3, gTextShadowMask & 0xF);
}

void sub_800792C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007958(gUnknown_2027370, a0, x, y, a3, color);
}

void nullsub_129(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
}

void sub_8007958(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    u32 uVar4;
    u32 *dest;
    s32 r4;
    const struct unkShiftData *shiftData;
    UnkTextStruct1 *r5;
    s32 r6;
    u32 r9;
    struct unkStruct_80B8824 dataLOL;
    s32 lol;

    r5 = &a0[a1];
    r9 = gUnknown_80B853C[color & 0xF];

    r4 = y / 8;

    dest = r5->unk18 + (((r5->unk4 * r4) + (x / 8)) * 8);
    dest += (r4 * -8) + y;
    r6 = x / 8;

    if (y / 8 >= r5->unk8)
        return;

    dataLOL = gUnknown_80B8824;

    for (; a4 > 0; a4 -= 8) {
        lol = a4;
        if (lol > 7)
            lol = 8;

        shiftData = &gCharMasksOffsets[x + (x / 8 * -8)];

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

UNUSED static void nullsub_157(void)
{
}

// https://decomp.me/scratch/4tFKb
void sub_8007AA4(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, u32 color)
{
    s32 r2;
    s32 r3;
    UnkTextStruct1 *r4;
    u32 ip;
    u32 *dest;
    struct unkStruct_80B8848 dataLOL;

    r4 = &a0[a1];
    ip = gUnknown_80B853C[color & 0xF] + 0x11111111;
    #ifndef NONMATCHING
    asm("":::"r8");
    #endif // NONMATCHING
    dataLOL = gUnknown_80B8848;
    a4++; a4--;
    r3 = y / 8;

    dest = r4->unk18 + ((r4->unk4 * r3 + x / 8) * 8);
    r2 = x / 8;
    dest += r3 * -8 + y;
    ip &= dataLOL.arr[x & 7];

    if (r2 >= r4->unk4)
        return;
    goto thecheck;
label:
    y++;
    dest++;
    if ((y % 8) == 0)
        dest += r4->unk20;
    a4--;
thecheck:
    if (a4 <= 0 || r3 >= r4->unk8)
        return;

    dest[0] |= ip;

    if (r4->unk3C > dest)
        r4->unk3C = dest;
    if (r4->unk40 < dest)
        r4->unk40 = dest;
    goto label;
}

void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color)
{
    sub_8007BA8(gUnknown_2027370, a0, x, y, a3, color);
}

UNUSED static void nullsub_158(void)
{
}

#ifdef NONMATCHING // https://decomp.me/scratch/AU1bH
void sub_8007BA8(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    s32 iVar1; // r1
    s32 iVar3;
    s32 iVar9; // r8?

    u32 *r4;
    u32 r5;
    u32 r6;
    UnkTextStruct1 *ip;
    s32 sp4;
    s32 sp8;
    u32 sp1C; // Used correctly

    s32 yeah;
    u32 *sp10; // r2?

    ip = &a0[a1];

    sp8 = y / 8;

    if (sp8 >= ip->unk8)
        return;

    yeah = ip->unk4 * sp8;

    r4 = ip->unk18 + ((yeah + x / 8) * 8);
    r4 += (sp8 * -8) + y;

    for (sp4 = 0; sp4 < color; sp4++) {
        sp10 = r4;
        iVar1 = x / 8;

        for (iVar9 = 0; iVar9 < a4; iVar9 += 8) {
            if (iVar1 >= ip->unk4)
                break;

            r6 = 0xF0000000;
            r5 = 0xE0000000;
            sp1C = 0;

            for (iVar3 = 0; iVar3 < 8; iVar3++) {
                if ((sp10[0] & r6) == 0)
                    sp1C |= r5;

                r6 >>= 4;
                r5 >>= 4;
            }

            sp10[0] |= sp1C;
            if (ip->unk3C > sp10)
                ip->unk3C = sp10;
            if (ip->unk40 < sp10)
                ip->unk40 = sp10;
            sp10 += 8;
            iVar1++;
        }

        y++;
        r4++;
        if ((y % 8) == 0) {
            r4 += ip->unk20;
            sp8++;
            if (sp8 >= ip->unk8)
                return;
        }

        sp4++;
    }
}
#else
NAKED
void sub_8007BA8(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x20\n"
    "\tstr r2, [sp]\n"
    "\tlsls r2, r1, 3\n"
    "\tadds r2, r1\n"
    "\tlsls r2, 3\n"
    "\tadds r0, r2\n"
    "\tmov r12, r0\n"
    "\tadds r0, r3, 0\n"
    "\tcmp r3, 0\n"
    "\tbge _08007BC8\n"
    "\tadds r0, r3, 0x7\n"
"_08007BC8:\n"
    "\tasrs r0, 3\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmov r1, r12\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r1, r2]\n"
    "\tldr r4, [sp, 0x8]\n"
    "\tcmp r4, r0\n"
    "\tbge _08007CC4\n"
    "\tmovs r7, 0x4\n"
    "\tldrsh r0, [r1, r7]\n"
    "\tadds r1, r4, 0\n"
    "\tmuls r1, r0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007BE8\n"
    "\tadds r0, 0x7\n"
"_08007BE8:\n"
    "\tasrs r0, 3\n"
    "\tadds r0, r1, r0\n"
    "\tlsls r0, 5\n"
    "\tmov r2, r12\n"
    "\tldr r1, [r2, 0x18]\n"
    "\tadds r4, r1, r0\n"
    "\tldr r7, [sp, 0x8]\n"
    "\tlsls r0, r7, 3\n"
    "\tsubs r0, r3, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tmovs r0, 0\n"
    "\tstr r0, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x44]\n"
    "\tcmp r0, r1\n"
    "\tbge _08007CC4\n"
"_08007C08:\n"
    "\tadds r2, r4, 0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007C12\n"
    "\tadds r0, 0x7\n"
"_08007C12:\n"
    "\tasrs r1, r0, 3\n"
    "\tmovs r7, 0\n"
    "\tmov r8, r7\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0xC]\n"
    "\tadds r4, 0x4\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tldr r0, [sp, 0x40]\n"
    "\tcmp r8, r0\n"
    "\tbge _08007C94\n"
"_08007C26:\n"
    "\tmov r3, r12\n"
    "\tmovs r4, 0x4\n"
    "\tldrsh r0, [r3, r4]\n"
    "\tcmp r1, r0\n"
    "\tbge _08007C94\n"
    "\tmovs r6, 0xF0\n"
    "\tlsls r6, 24\n"
    "\tmovs r5, 0xE0\n"
    "\tlsls r5, 24\n"
    "\tmovs r7, 0\n"
    "\tstr r7, [sp, 0x1C]\n"
    "\tldr r4, [r2]\n"
    "\tadds r3, r4, 0\n"
    "\tmov r0, r12\n"
    "\tldr r0, [r0, 0x3C]\n"
    "\tmov r9, r0\n"
    "\tmov r7, r12\n"
    "\tldr r7, [r7, 0x40]\n"
    "\tmov r10, r7\n"
    "\tadds r1, 0x1\n"
    "\tstr r1, [sp, 0x10]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tstr r0, [sp, 0x18]\n"
    "\tmovs r1, 0x8\n"
    "\tadd r8, r1\n"
    "\tmovs r1, 0x7\n"
"_08007C5C:\n"
    "\tadds r0, r4, 0\n"
    "\tands r0, r6\n"
    "\tcmp r0, 0\n"
    "\tbne _08007C6A\n"
    "\tldr r7, [sp, 0x1C]\n"
    "\torrs r7, r5\n"
    "\tstr r7, [sp, 0x1C]\n"
"_08007C6A:\n"
    "\tlsrs r6, 4\n"
    "\tlsrs r5, 4\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r1, 0\n"
    "\tbge _08007C5C\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\torrs r3, r0\n"
    "\tstr r3, [r2]\n"
    "\tcmp r9, r2\n"
    "\tbls _08007C82\n"
    "\tmov r1, r12\n"
    "\tstr r2, [r1, 0x3C]\n"
"_08007C82:\n"
    "\tcmp r10, r2\n"
    "\tbcs _08007C8A\n"
    "\tmov r3, r12\n"
    "\tstr r2, [r3, 0x40]\n"
"_08007C8A:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tldr r2, [sp, 0x18]\n"
    "\tldr r4, [sp, 0x40]\n"
    "\tcmp r8, r4\n"
    "\tblt _08007C26\n"
"_08007C94:\n"
    "\tldr r3, [sp, 0xC]\n"
    "\tldr r4, [sp, 0x14]\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08007CB8\n"
    "\tmov r7, r12\n"
    "\tldr r0, [r7, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tldr r0, [sp, 0x8]\n"
    "\tadds r0, 0x1\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmovs r1, 0x8\n"
    "\tldrsh r0, [r7, r1]\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tcmp r2, r0\n"
    "\tbge _08007CC4\n"
"_08007CB8:\n"
    "\tldr r7, [sp, 0x4]\n"
    "\tadds r7, 0x1\n"
    "\tstr r7, [sp, 0x4]\n"
    "\tldr r0, [sp, 0x44]\n"
    "\tcmp r7, r0\n"
    "\tblt _08007C08\n"
"_08007CC4:\n"
    "\tadd sp, 0x20\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}
#endif // NONMATCHING

UNUSED static void sub_8007CD4(u32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8007D00(gUnknown_2027370, a0, a1, a2, a3, a4);
}

UNUSED static void nullsub_159(void)
{
}

NAKED // Very similar to sub_8007BA8
void sub_8007D00(UnkTextStruct1 *a0, u32 a1, s32 x, s32 y, s32 a4, s32 color)
{
    asm_unified(
    "push {r4-r7,lr}\n"
    "\tmov r7, r10\n"
    "\tmov r6, r9\n"
    "\tmov r5, r8\n"
    "\tpush {r5-r7}\n"
    "\tsub sp, 0x20\n"
    "\tstr r2, [sp]\n"
    "\tlsls r2, r1, 3\n"
    "\tadds r2, r1\n"
    "\tlsls r2, 3\n"
    "\tadds r0, r2\n"
    "\tmov r12, r0\n"
    "\tadds r0, r3, 0\n"
    "\tcmp r3, 0\n"
    "\tbge _08007D20\n"
    "\tadds r0, r3, 0x7\n"
"_08007D20:\n"
    "\tasrs r0, 3\n"
    "\tstr r0, [sp, 0x8]\n"
    "\tmov r1, r12\n"
    "\tmovs r2, 0x8\n"
    "\tldrsh r0, [r1, r2]\n"
    "\tldr r4, [sp, 0x8]\n"
    "\tcmp r4, r0\n"
    "\tbge _08007E0E\n"
    "\tmovs r5, 0x4\n"
    "\tldrsh r0, [r1, r5]\n"
    "\tadds r1, r4, 0\n"
    "\tmuls r1, r0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007D40\n"
    "\tadds r0, 0x7\n"
"_08007D40:\n"
    "\tasrs r0, 3\n"
    "\tadds r0, r1, r0\n"
    "\tlsls r0, 5\n"
    "\tmov r2, r12\n"
    "\tldr r1, [r2, 0x18]\n"
    "\tadds r4, r1, r0\n"
    "\tldr r5, [sp, 0x8]\n"
    "\tlsls r0, r5, 3\n"
    "\tsubs r0, r3, r0\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tmovs r0, 0\n"
    "\tb _08007E06\n"
"_08007D5A:\n"
    "\tadds r2, r4, 0\n"
    "\tldr r0, [sp]\n"
    "\tcmp r0, 0\n"
    "\tbge _08007D64\n"
    "\tadds r0, 0x7\n"
"_08007D64:\n"
    "\tasrs r1, r0, 3\n"
    "\tmovs r5, 0\n"
    "\tmov r8, r5\n"
    "\tadds r3, 0x1\n"
    "\tstr r3, [sp, 0xC]\n"
    "\tadds r4, 0x4\n"
    "\tstr r4, [sp, 0x14]\n"
    "\tldr r0, [sp, 0x40]\n"
    "\tcmp r8, r0\n"
    "\tbge _08007DE0\n"
"_08007D78:\n"
    "\tmov r3, r12\n"
    "\tmovs r4, 0x4\n"
    "\tldrsh r0, [r3, r4]\n"
    "\tcmp r1, r0\n"
    "\tbge _08007DE0\n"
    "\tmovs r4, 0xF0\n"
    "\tlsls r4, 24\n"
    "\tmovs r6, 0xE0\n"
    "\tlsls r6, 24\n"
    "\tmovs r7, 0\n"
    "\tldr r5, [r2]\n"
    "\tstr r5, [sp, 0x1C]\n"
    "\tadds r3, r5, 0\n"
    "\tmov r0, r12\n"
    "\tldr r0, [r0, 0x3C]\n"
    "\tmov r9, r0\n"
    "\tmov r5, r12\n"
    "\tldr r5, [r5, 0x40]\n"
    "\tmov r10, r5\n"
    "\tadds r1, 0x1\n"
    "\tstr r1, [sp, 0x10]\n"
    "\tadds r0, r2, 0\n"
    "\tadds r0, 0x20\n"
    "\tstr r0, [sp, 0x18]\n"
    "\tmovs r1, 0x8\n"
    "\tadd r8, r1\n"
    "\tmovs r1, 0x7\n"
"_08007DAE:\n"
    "\tldr r0, [sp, 0x1C]\n"
    "\tands r0, r4\n"
    "\tcmp r0, r6\n"
    "\tbne _08007DB8\n"
    "\torrs r7, r4\n"
"_08007DB8:\n"
    "\tlsrs r4, 4\n"
    "\tlsrs r6, 4\n"
    "\tsubs r1, 0x1\n"
    "\tcmp r1, 0\n"
    "\tbge _08007DAE\n"
    "\tbics r3, r7\n"
    "\tstr r3, [r2]\n"
    "\tcmp r9, r2\n"
    "\tbls _08007DCE\n"
    "\tmov r3, r12\n"
    "\tstr r2, [r3, 0x3C]\n"
"_08007DCE:\n"
    "\tcmp r10, r2\n"
    "\tbcs _08007DD6\n"
    "\tmov r4, r12\n"
    "\tstr r2, [r4, 0x40]\n"
"_08007DD6:\n"
    "\tldr r1, [sp, 0x10]\n"
    "\tldr r2, [sp, 0x18]\n"
    "\tldr r5, [sp, 0x40]\n"
    "\tcmp r8, r5\n"
    "\tblt _08007D78\n"
"_08007DE0:\n"
    "\tldr r3, [sp, 0xC]\n"
    "\tldr r4, [sp, 0x14]\n"
    "\tmovs r0, 0x7\n"
    "\tands r0, r3\n"
    "\tcmp r0, 0\n"
    "\tbne _08007E02\n"
    "\tmov r1, r12\n"
    "\tldr r0, [r1, 0x20]\n"
    "\tlsls r0, 2\n"
    "\tadds r4, r0\n"
    "\tldr r2, [sp, 0x8]\n"
    "\tadds r2, 0x1\n"
    "\tstr r2, [sp, 0x8]\n"
    "\tmovs r5, 0x8\n"
    "\tldrsh r0, [r1, r5]\n"
    "\tcmp r2, r0\n"
    "\tbge _08007E0E\n"
"_08007E02:\n"
    "\tldr r0, [sp, 0x4]\n"
    "\tadds r0, 0x1\n"
"_08007E06:\n"
    "\tstr r0, [sp, 0x4]\n"
    "\tldr r1, [sp, 0x44]\n"
    "\tcmp r0, r1\n"
    "\tblt _08007D5A\n"
"_08007E0E:\n"
    "\tadd sp, 0x20\n"
    "\tpop {r3-r5}\n"
    "\tmov r8, r3\n"
    "\tmov r9, r4\n"
    "\tmov r10, r5\n"
    "\tpop {r4-r7}\n"
    "\tpop {r0}\n"
    "\tbx r0");
}

void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8007E64(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a5, a6);
}

UNUSED static void nullsub_160(void)
{
}

void sub_8007E64(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        s32 id = (strPtr->unk4 * a4) + a3;
        u32 *unk18Ptr = &strPtr->unk18[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    if (strPtr->unk3C > loopUnk18Ptr) {
                        strPtr->unk3C = loopUnk18Ptr;
                    }
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    if (strPtr->unk40 < loopUnk18Ptr) {
                        strPtr->unk40 = loopUnk18Ptr;
                    }
                    a7++;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

u32 FlipPixelsHorizontally(u32 a0)
{
    u32 r0;

    r0 = (a0 >> 28)  & 0xF;
    r0 |= (a0 >> 20) & 0xF0;
    r0 |= (a0 >> 12) & 0xF00;
    r0 |= (a0 >> 4)  & 0xF000;
    r0 |= (a0 << 4)  & 0xF0000;
    r0 |= (a0 << 12) & 0xF00000;
    r0 |= (a0 << 20) & 0xF000000;
    r0 |= (a0 << 28) & 0xF0000000;

    return r0;
}

void sub_8008030(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8);

UNUSED void sub_8007FEC(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6)
{
    sub_8008030(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a5, a6);
}

void nullsub_161(void) {}

// Similar to sub_8007E64
void sub_8008030(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 *a7, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        u32 *unk18Ptr = &strPtr->unk18[((strPtr->unk4 * a4) + (a3 + a5)) * 8];
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3 + a5;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                xMaybe--;
                loopUnk18Ptr -= 8;
                if (xMaybe < strPtr->unk4) {
                    if (strPtr->unk3C > loopUnk18Ptr) {
                        strPtr->unk3C = loopUnk18Ptr;
                    }
                    loopUnk18Ptr[0] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[1] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[2] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[3] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[4] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[5] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[6] = FlipPixelsHorizontally(*(a7++));
                    loopUnk18Ptr[7] = FlipPixelsHorizontally(*(a7++));
                    if (strPtr->unk40 < loopUnk18Ptr + 8) {
                        strPtr->unk40 = loopUnk18Ptr + 8;
                    }
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                else {
                    a7 += 8;
                }
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

extern const u32 gUnknown_80B86B4[][32];

// Similar to sub_8007E64
UNUSED void sub_80081A4(s32 a0, s32 a3, s32 a4, s32 a7Id)
{
    s32 i, j, a5, a6;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[a0];
    const u32 *a7 = gUnknown_80B86B4[a7Id];

    a3 /= 8;
    a4 /= 8;
    a5 = 2;
    a6 = 2;
    if (a4 < strPtr->unk8) {
        s32 id = (strPtr->unk4 * a4) + a3;
        u32 *unk18Ptr = &strPtr->unk28[id * 8];

        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            u32 *loopUnk18Ptr = unk18Ptr;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *(a7++);
                    *(loopUnk18Ptr++) = *a7;
                    a7++;
                }
                else {
                    loopUnk18Ptr += 8;
                    a7 += 8;
                }
                xMaybe++;
            }
            a4++;
            unk18Ptr += strPtr->unk20;
            unk18Ptr += 8;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

void sub_800829C(UnkTextStruct1 *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4);

void sub_8008274(s32 a0, const u8 *compressedData, s32 a2)
{
    sub_800829C(gUnknown_2027370, gUnknown_202B038[0], a0, compressedData, a2);
}

UNUSED void nullsub_162() {}

void sub_800829C(UnkTextStruct1 *a0, u16 a1[32][32], s32 a2, const u8 *compressedData, u32 a4)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a4 *= 4096;
    DecompressAT((u8 *)strPtr->unk18, (strPtr->unk4 * 32) * strPtr->unk8, compressedData);
    for (i = 0; i < strPtr->unk8; i++) {
        for (j = 0; j < strPtr->unk4; j++) {
            a1[strPtr->unk2 + i][strPtr->unk0 + j] &= 0xFFF;
            a1[strPtr->unk2 + i][strPtr->unk0 + j] |= a4;
        }
    }
    strPtr->unk30 = strPtr->unk28;
    strPtr->unk34 = strPtr->unk1C;
    strPtr->unk38 = strPtr->unk2C;
    strPtr->unk44 = 1;
}

void sub_8008334(u32 *r7, u32 *r12)
{
    s32 i;
    u32 r2, r3;
    u32 r4, r1;

    r4 = *r7;
    r1 = *r12;

    r3 = 0;
    r2 = 0;

    for (i = 0; i < 32; i += 4) {
        r2 <<= 4;
        r3 <<= 4;
        r2 |= r4 & 0xF;
        r3 |= r1 & 0xF;
        r4 >>= 4;
        r1 >>= 4;
    }
    *r7 = r3;
    *r12 = r2;
}

void sub_800838C(UnkTextStruct1 *a0, s32 a1, const u8 *compressedData, s32 a3);

void sub_800836C(s32 a0, const u8 *compressedData, s32 a1)
{
    sub_800838C(gUnknown_2027370, a0, compressedData, a1);
}

UNUSED void nullsub_163(void) {}

void sub_800838C(UnkTextStruct1 *a0, s32 a1, const u8 *compressedData, s32 a3)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a1];

    sub_8008274(a1, compressedData, a3);
    for (i = 0; i < strPtr->unk8; i++) {
        s32 r8 = strPtr->unk4 / 2;
        if (strPtr->unk4 & 1)
            r8++;
        for (j = 0; j < r8; j++) {
            u32 *r4, *r5;
            s32 unk4Mul = strPtr->unk4 * i;

            r4 = &strPtr->unk18[(unk4Mul + j) * 8];
            unk4Mul--;
            r5 = &strPtr->unk18[(unk4Mul + (strPtr->unk4 - j)) * 8];

            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
            sub_8008334(r4++, r5++);
        }
    }
}

void sub_80084A4(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8);

UNUSED void sub_8008468(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a6)
{
    sub_80084A4(gUnknown_2027370, gUnknown_202B038[0], a0, a1, a2, a3, a4, a6);
}

UNUSED void nullsub_164(void) {}

// Effectively unused
void sub_80084A4(UnkTextStruct1 *a0, u16 a1[32][32], u32 a2, s32 a3, s32 a4, s32 a5, s32 a6, u32 a8)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a2];

    a3 /= 8;
    a4 /= 8;
    a5 /= 8;
    a6 /= 8;
    a8 *= 4096;
    if (a4 < strPtr->unk8) {
        for (i = 0; i < a6; i++) {
            s32 xMaybe = a3;
            for (j = 0; j < a5; j++) {
                if (xMaybe < strPtr->unk4) {
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] &= 0xFFF;
                    a1[strPtr->unk2 + a4][strPtr->unk0 + xMaybe] |= a8;
                }
                xMaybe++;
            }
            a4++;
            if (a4 >= strPtr->unk8)
                break;
        }
    }
}

extern const struct unkChar gUnknown_80B86A4;

struct CharMapStruct
{
    s32 unk0;
    struct unkChar *unk4;
};
extern struct CharMapStruct *gCharmaps[];
extern s32 gCurrentCharmap;

// Oddly similar to sub_803DEC8
const struct unkChar *GetCharacter(s32 chr)
{
    s32 r2, r4;
    const struct unkChar *ret;
    const struct unkChar *strPtr = gCharmaps[gCurrentCharmap]->unk4;
    // TODO: create labels for these
    if (chr > 63487 && chr < 65535)
    {
        s32 r2 = chr & 0xFF;
        s32 r1 = (chr & 0xFF00) >> 8;
        r2 -= 32;
        r1 -= 248;
        ret = &strPtr[r1 * 224 + r2];
    }
    else
    {
        r4 = 0;
        r2 = gCharmaps[gCurrentCharmap]->unk0 - 1;
        while (r4 < r2) {
            s32 r1 = (r4 + r2) / 2;
            if (strPtr[r1].unk4 == chr) {
                r4 = r1;
                break;
            }
            else if (strPtr[r1].unk4 < chr) {
                r4 = r1 + 1;
            }
            else {
                r2 = r1;
            }
        }

        ret = &strPtr[r4];
        if (ret->unk4 != chr)
            ret = &gUnknown_80B86A4;

    }
    return ret;
}

s32 HexDigitValue(u8 chr)
{
    if (chr >= '0' && chr <= '9')
        return chr - '0';
    else if (chr >= 'a' && chr <= 'f')
        return (chr - 'a') + 10;
    else
        return 1;
}

const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *a0)
{
    s32 currChr = *a1;
    if (currChr == 0x7E) {
        s32 hexDigit;

        a1++;
        hexDigit = (HexDigitValue(a1[0]) << 4) + HexDigitValue(a1[1]);
        if (*a1 != '\0') {
            a1++;
            if (*a1 != '\0') {
                a1++;
            }
        }
        *a0 = hexDigit;
        return a1;
    }
    else if ((currChr >= 0x81 && currChr <= 0x84) || currChr == 0x87) {
        *a0 = a1[1] | (a1[0] << 8);
        return a1 + 2;
    }
    else {
        *a0 = currChr;
        return a1 + 1;
    }
}

UNUSED void nullsub_165(void) {}
UNUSED void nullsub_166(void) {}
UNUSED void nullsub_167(void) {}
UNUSED void nullsub_168(void) {}

extern const u32 gUnknown_80B8868[];

UNUSED void sub_80086C8(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    u32 *r5;
    s32 r2, r0, r1;
    UnkTextStruct1 *strPtr = &a0[a1];

    if (a2 < 0) {
        a4 += a2;
        a2 = 0;
    }
    if (a3 < 0) {
        a5 += a3;
        a3 = 0;
    }

    if (a4 + a2 > strPtr->unk4 * 8) {
        a4 = (strPtr->unk4 * 8) - a2;
    }
    if (a3 + a5 > strPtr->unk8 * 8) {
        a5 = (strPtr->unk8 * 8) - a3;
    }

    r2 = strPtr->unk4 * (a3 / 8);
    r0 = 8 * (r2 + (a2 / 8));
    r1 = a3 - ((a3 / 8) * 8);
    r5 = &strPtr->unk18[r0 + r1];
    while (a5 > 0) {
        u32 *loopPtr;
        s32 r4, r6;

        loopPtr = r5;
        r4 = a4;
        r6 = a2;
        if (strPtr->unk3C > r5) {
            strPtr->unk3C = r5;
        }

        while (r4 > 0) {
            s32 r3;
            if (r4 < 8) {
                r3 = r4;
                *loopPtr &= gUnknown_80B8868[(r4 & 7) + 8];
            }
            else if ((r6 & 7) != 0) {
                r3 = 8 - (r6 & 7);
                *loopPtr &= gUnknown_80B8868[r6 & 7];
            }
            else {
                r3 = 8;
                *loopPtr = r6 & 7;
            }

            loopPtr += 8;
            r4 -= r3;
            r6 += r3;
        }
        a5--;
        a3++;
        if (strPtr->unk40 < r5) {
            strPtr->unk40 = r5;
        }
        r5++;
        if (!(a3 & 7)) {
            r5 = &r5[strPtr->unk20];
        }
    }
}

void sub_8008818(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5);

void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4)
{
    sub_8008818(gUnknown_2027370, a0, a1, a2, a3, a4);
}

UNUSED void nullsub_176(void) {}

void sub_8008818(UnkTextStruct1 *a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &a0[a1];
    s32 a2Div = a2 / 8;
    s32 a3Div = a3 / 8;

    for (i = 0; i < a5; i += 8) {
        u32 *ptr = &strPtr->unk18[((strPtr->unk4 * a3Div) + a2Div) * 8];
        for (j = 0; j < a4; j += 8) {
            if (strPtr->unk3C > ptr) {
                strPtr->unk3C = ptr;
            }
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *ptr = 0;
            if (strPtr->unk40 < ptr) {
                strPtr->unk40 = ptr;
            }
            ptr++;
        }
        a3Div++;
    }
}

extern u8 gUnknown_20274A5;
bool8 xxx_update_bg_vram(UnkTextStruct1 *a0);

bool8 xxx_call_update_bg_vram(void)
{
    bool8 ret = FALSE;
    if (gUnknown_20274A5 != 0) {
        gUnknown_20274A5 = 0;
        sub_80099C0();
    }
    ret = xxx_update_bg_vram(gUnknown_2027370);
    return ret;
}

bool8 xxx_update_bg_vram(UnkTextStruct1 *a0)
{
    s32 i, j;
    u32 r5;
    bool8 ret = FALSE;

    for (i = 0; i < 4; i++) {
        UnkTextStruct1 *strPtr = &a0[i];
        if (strPtr->unk4 == 0)
            continue;
        r5 = strPtr->unk38;
        if (r5 == 0)
            continue;

        if (strPtr->unk45) {
            u32 *r2, *r1;

            CpuCopy(strPtr->unk28, strPtr->unk18, 0xD00);
            // The reason for void casts is because we want to add 0xD00/r5 directly to pointers. Because pointers are u32, without the casts, it would multiply the value by 4.
            r2 = (void *)(strPtr->unk18) + 0xD00;
            r1 = (void *)(strPtr->unk28) + 0xD00;
            for (j = 0; j < strPtr->unk4; j++) {
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = *(r2++);
                *(r1++) = 0xDDDDDDDD;
                *(r1++) = 0xEEEEEEEE;
                *(r1++) = 0xFFFFFFFF;
                r2 += 3;
            }
            strPtr->unk38 = 0;
        }
        else {
            CpuCopy(strPtr->unk30, strPtr->unk34, r5);
            strPtr->unk34 += (r5 / 4);
            strPtr->unk30 = (void *)(strPtr->unk30) + r5;
            strPtr->unk38 -= r5;
        }

        if (strPtr->unk38 == 0) {
            strPtr->unk44 = 0;
        }
        ret = TRUE;
    }

    return ret;
}

// Todo fix gUnknown_3000E94 being accessed as s16/u8
extern s16 gUnknown_3000E94[];

void sub_800898C(void)
{
    s32 i;

    for (i = 0; i < 161; i++) {
        gUnknown_3000E94[i] = 0xF0F0;
    }
}

void sub_80089AC(const UnkTextStruct2 *r4, UnkTextStruct2_sub *r5_Str)
{
    u8 *r6;

    if (r4->unk0 & 0x40)
        return;

    r6 = (void*) &gUnknown_3000E94;
    if (r4->unk4 == 1) {
        s32 r12 = (r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0) * 8;
        s32 r5 = (r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2) * 8;
        s32 r7 = (r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0 + r4->unkC) * 8;
        s32 r2 = (r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2 + r4->unkE) * 8;
        if (r4->unkE != 0) {
            if (r5 < 0)
                r5 = 0;
            if (r2 < 0)
                r2 = 0;
            if (r5 > 160)
                r5 = 160;
            if (r2 > 160)
                r2 = 160;
            while (r5 < r2) {
                s32 id = r5 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r7;
                    r6[id] = r12;
                }
                else {
                    if (r6[id] < r7) {
                        r6[id] = r7;
                    }
                    id++;
                    if (r6[id] > r12) {
                        r6[id] = r12;
                    }
                }
                r5++;
            }
        }
    }
    else if (r4->unk4 == 6) {
        s32 i;
        s32 r9 = ((r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0) * 8) - 5;
        s32 r5 = ((r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2) * 8) - 4;
        s32 var_24 = ((r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0 + r4->unkC) * 8) + 5;
        s32 r8 = ((r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2 + r4->unkE) * 8) + 5;
        s32 r12 = ((r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0) * 8) + 3;
        const UnkTextStruct2_sub2 *r2 = r4->unk14;
        s32 tmp = r2->f2 - 1;
        s32 r10 = (((tmp + r2->f0 + 2) * 8) + r12) - 4;
        s32 r4 = r9 + ((r2->f1 + 1) * 8);
        s32 r7 = (r4 + ((r2->f2 + 2) * 8)) - 4;

        if (r5 < 0)
            r5 = 0;
        if (r8 < 0)
            r8 = 0;
        if (r5 > 160)
            r5 = 160;
        if (r8 > 160)
            r8 = 160;

        for (i = 0; i < 4; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r7;
                r6[id] = r4;
            }
            else {
                if (r6[id] < r7) {
                    r6[id] = r7;
                }
                id++;
                if (r6[id] > r4) {
                    r6[id] = r4;
                }
            }
            r5++;
        }
        for (i = 0; i < 8; i++) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = r10;
                r6[id] = r12;
            }
            else {
                if (r6[id] < r10) {
                    r6[id] = r10;
                }
                id++;
                if (r6[id] > r12) {
                    r6[id] = r12;
                }
            }
            r5++;
        }

        while (r5 < r8) {
            s32 id = r5 * 2;
            if (r6[id] == 240 && r6[id + 1] == 240) {
                r6[id++] = var_24;
                r6[id] = r9;
            }
            else {
                if (r6[id] < var_24) {
                    r6[id] = var_24;
                }
                id++;
                if (r6[id] > r9) {
                    r6[id] = r9;
                }
            }
            r5++;
        }
    }
    else {
        s32 r8 = ((r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0) * 8) - 5;
        s32 r3 = ((r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2) * 8) - 5;
        s32 r12 = ((r4->unk8.unk0.separate.unk0 + r5_Str->unk0.separate.unk0 + r4->unkC) * 8) + 5;
        s32 r5 = ((r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2 + r4->unkE) * 8) + 5;
        if (r4->unkE != 0) {
            if (r4->unk4 == 0) {
                r3 += 8;
                r5 = ((r4->unk8.unk0.separate.unk2 + r5_Str->unk0.separate.unk2 + r4->unkE) * 8) - 3;
            }
            if (r3 < 0)
                r3 = 0;
            if (r5 < 0)
                r5 = 0;
            if (r3 > 160)
                r3 = 160;
            if (r5 > 160)
                r5 = 160;
            while (r3 < r5) {
                s32 id = r3 * 2;
                if (r6[id] == 240 && r6[id + 1] == 240) {
                    r6[id++] = r12;
                    r6[id] = r8;
                }
                else {
                    if (r6[id] < r12) {
                        r6[id] = r12;
                    }
                    id++;
                    if (r6[id] > r8) {
                        r6[id] = r8;
                    }
                }
                r3++;
            }
        }
    }
}

void PrepareTextbox_8008C6C(UnkTextStruct1 *strArr, u32 strId);

void CallPrepareTextbox_8008C54(u32 strId)
{
    PrepareTextbox_8008C6C(gUnknown_2027370, strId);
}

UNUSED void nullsub_169(void) {}

void PrepareTextbox_8008C6C(UnkTextStruct1 *strArr, u32 strId)
{
    s32 i;
    UnkTextStruct1 *strPtr = &strArr[strId];

    if (!strPtr->unk45) {
        s32 count = (strPtr->unk4 * strPtr->unk8) * 32;
        for (i = 0; i < count; i += 32) {
            CpuClear(&strPtr->unk18[i / 4u], 32);
        }
    }
    else {
        s32 count = (strPtr->unk4 * (strPtr->unk8 - 1)) * 32;
        u32 *ptr = strPtr->unk18;
        for (i = 0; i < strPtr->unk4; i++) {
            *(ptr++) = 0xFFFFFFFF;
            *(ptr++) = 0xEEEEEEEE;
            *(ptr++) = 0xDDDDDDDD;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
            *(ptr++) = 0;
        }
        for (i = 0; i < count; i += 32) {
            CpuClear(ptr, 32);
            ptr += 8;
        }
    }

    if (strPtr->unkC == 6) {
        strPtr->unk46 = 1;
        sub_8007958(strArr, strId, 0, 10, strPtr->unk4 * 8, 0xE);
        sub_8007958(strArr, strId, 0, 11, strPtr->unk4 * 8, 0xD);
        strPtr->unk46 = 0;
    }

    strPtr->unk30 = strPtr->unk28;
    strPtr->unk34 = strPtr->unk1C;
    strPtr->unk38 = strPtr->unk2C;
    strPtr->unk44 = 1;
}

bool8 sub_8008D8C(u32 strId)
{
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strId];
    return (strPtr->unk38 != 0);
}

UNUSED bool8 sub_8008DA8(void)
{
    return FALSE;
}

UNUSED void sub_8008DAC(s32 a0, s32 a1, s32 a2)
{
    gUnknown_202B038[0][a1][a0] = a2;
    gUnknown_20274A5 = 1;
}

void sub_8008DC8(s32 a0, s32 a1, s32 a2, s32 a3)
{
    gUnknown_202B038[0][a1][a0] = a2;
    gUnknown_202B038[1][a1][a0] = a3;
    gUnknown_20274A5 = 1;
}

UNUSED void sub_8008DF4(s32 a0, s32 a1, u8 *a2)
{
    u8 r1;

    while (1) {
        if (*a2 == 0)
            break;

        r1 = *a2;
        if (r1 >= 97 && r1 <= 122) {
            r1 -= 32;
        }
        gUnknown_202B038[0][a1][a0] = 0xF000 | (r1 + 0x258);
        a2++;
        a0++;
    }
    gUnknown_20274A5 = 1;
}

UNUSED void sub_8008E58(s32 a0, s32 a1, u8 *a2, s32 a3)
{
    u8 r1;

    while (1) {
        if (*a2 == 0)
            break;

        r1 = *a2;
        if (a3 == 0)
            break;

        if (r1 >= 97 && r1 <= 122) {
            r1 -= 32;
        }
        gUnknown_202B038[0][a1][a0] = 0xF000 | (r1 + 0x258);
        a2++;
        a0++;
        a3--;
    }
    gUnknown_20274A5 = 1;
}

extern s16 gCharacterSpacing;

s32 sub_8008ED0(const u8 *str)
{
    s32 ret = 0;

    while (1) {
        const u8 *strPtr;
        u32 chr;

        strPtr = xxx_get_next_char_from_string(str, &chr);
        str = strPtr;
        if (chr == 0)
            break;
        if (chr == 0xD)
            break;
        if (chr == '\n')
            break;
        if (chr == 0x82A0 || chr == 0x82A2)
            continue;
        if (chr == 0x1B)
            break;

        if (chr == '#') {
            if (*strPtr == 0x6E || *strPtr == 0x5B || *strPtr == 0x50)
                break;
            switch (*strPtr) {
                case 0x3D:
                case 0x7E:
                    str = strPtr + 2;
                    break;
                case 0x43:
                case 0x63:
                    str += 2;
                    break;
                case 0x52:
                case 0x72:
                    str++;
                    break;
                case 0x2B:
                case 0x57:
                    str = strPtr + 1;
                    break;
            }
        }
        else if (chr == '`') {
            ret += 6;
        }
        else {
            const struct unkChar *ptr = GetCharacter(chr);
            if (ptr != NULL) {
                ret += ptr->unk6 + gCharacterSpacing;
            }
        }
    }

    return ret;
}

void xxx_draw_string(UnkTextStruct1 *strArr, s32 x, s32 y, const u8 *str, u32 windowId, s32 a5, s32 a6, s32 a7);

void sub_8008F8C(s32 x, s32 y, const u8 *str, u32 windowId, s32 a4, s32 a5)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, a4, 0, a5);
}

void PrintStringOnWindow(s32 x, u32 y, const u8 *str, u32 windowId, u32 a4)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, a4, 0, 0xD);
}

UNUSED void nullsub_170(void) {}

// Identical to PrintStringOnWindow
UNUSED void sub_8008FF0(s32 x, u32 y, const u8 *str, u32 windowId, u32 a4)
{
    xxx_draw_string(gUnknown_2027370, x, y, str, windowId, a4, 0, 0xD);
}

UNUSED void nullsub_171(void) {}

struct UnkDrawStringStruct;

struct UnkDrawStringStruct
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 fill22;
    u8 fill23;
    const u8* (*unk24)(const u8 *, const u8 *, struct UnkDrawStringStruct*);
    u8 fill28;
    u8 fill29;
    u8 fill2A;
    u8 fill2B;
    u32 unk2C;
    u8 fill30;
    u8 fill31;
    u8 fill32;
    u8 fill33;
    u32 unk34;
};

const u8 *HandleTextFormat(UnkTextStruct1 *strArr, const u8 *str, struct UnkDrawStringStruct *sp);

void xxx_draw_string(UnkTextStruct1 *strArr, s32 x, s32 y, const u8 *str, u32 windowId, s32 a5, s32 a6, s32 a7)
{
    struct UnkDrawStringStruct sp;

    sp.unk0 = x;
    sp.unk2 = y;
    sp.unkC = x;
    sp.unk10 = 7;
    while (1) {
        str = HandleTextFormat(strArr, str, &sp);
        str = xxx_get_next_char_from_string(str, &sp.unk34);
        if (sp.unk34 == '\0' || sp.unk34 == a5)
            break;

        if (sp.unk34 == 0x82A0) {
            gCurrentCharmap = 0;
        }
        else if (sp.unk34 == 0x82A2) {
            gCurrentCharmap = 1;
        }
        else if (sp.unk34 == 0x1B) {
            break;
        }
        else if (sp.unk34 == 0xD || sp.unk34 == '\n') {
            sp.unk0 = sp.unkC;
            sp.unk2 += a7;
        }
        else if (sp.unk34 == 0x1D) {
            sp.unk0 = sp.unkC;
            sp.unk2 += 5;
        }
        else if (sp.unk34 == '`') {
            sp.unk0 += 6;
        }
        else if (a6 == 0) {
            sp.unk0 += xxx_draw_char(strArr, sp.unk0, sp.unk2, sp.unk34, sp.unk10, windowId);
        }
        else {
            const struct unkChar *chrPtr = GetCharacter(sp.unk34);
            if (chrPtr != NULL) {
                s32 x = sp.unk0;
                s32 x2 = gCharacterSpacing + 10;
                x +=((x2 - chrPtr->unk6) / 2);
                xxx_draw_char(strArr, x, sp.unk2, sp.unk34, sp.unk10, windowId);
                sp.unk0 += a6;
            }
        }
    }
}

const u8 *sub_800915C(s16 *a0, const u8 *str)
{
    s32 a = 0;

    while (1)
    {
        if (*str == '.') {
            str++;
            break;
        }
        else if (*str >= '0' && *str <= '9') {
            a *= 10;
            a += (*str - '0');
            str++;
        }
        else {
            break;
        }
    }

    *a0 = a;
    return str;
}

const u8 *xxx_handle_format_global(const u8 *str, struct UnkDrawStringStruct *unkStrPtr)
{
    return HandleTextFormat(gUnknown_2027370, str, unkStrPtr);
}

UNUSED s32 sub_80091A8(s32 a0)
{
    return a0 + 1;
}

extern u8 gUnknown_202749A[];
extern u8 gUnknown_20274A6[];

s32 InterpretColorChar(u8 a0);

#ifdef NONMATCHING
// https://decomp.me/scratch/AJ2km
const u8 *HandleTextFormat(UnkTextStruct1 *strArr, const u8 *str, struct UnkDrawStringStruct *sp)
{
    while (*str == 0x23) {
        if (str[1] == 0x5B) {
            const u8 *strBefore = str;
            str += 2;
            sp->unk21 = 0;
            while (*str != '\0') {
                if (*str == 0x5D) {
                    str++;
                    break;
                }
                str++;
            }
            if (sp->unk24 != NULL) {
                const u8 *strNew = sp->unk24(strBefore, str, sp);
                if (strNew != NULL) {
                    str = strNew;
                }
            }

            if (sp->unk21 != 0)
                break;
        }
        else if (str[1] == 0x3D) {
            sp->unk0 = str[2];
            str += 3;
            if (*str == 0x2E)
                str++;
        }
        else if (str[1] == 0x79) {
            sp->unk2 = str[2];
            str += 3;
            if (*str == 0x2E)
                str++;
        }
        else if (str[1] == 0x3E) {
            str = sub_800915C(&sp->unk0, str + 2);
        }
        else if (str[1] == 0x2E) {
            sp->unk0 += str[2];
            str += 3;
        }
        else if (str[1] == 0x6E) {
            sp->unk0 = sp->unkC;
            sp->unk2 += 11;
            str += 2;
        }
        else if (str[1] == 0x3A) {
            sp->unk0 = sp->unk4;
            str += 2;
        }
        else if (str[1] == 0x3B) {
            sp->unk0 = sp->unk4 + str[2];
            str += 3;
        }
        else if (str[1] == 0x2B) {
            str += 2;
            sp->unk0 = (strArr[0].unk4 * 8) - sub_8008ED0(str);
            sp->unk0 /= 2;
        }
        else if (str[1] == 0x43) {
            sp->unk14 = sp->unk10;
            sp->unk10 = InterpretColorChar(str[2]);
            str += 3;
        }
        else if (str[1] == 0x5F) {
            sp->unk14 = sp->unk10;
            sp->unk10 = gUnknown_202749A[str[2]];
            str += 3;
            if (*str == 0x2E)
                str++;
        }
        else if (str[1] == 0x52) {
            sp->unk10 = sp->unk14;
            str += 2;
        }
        else if (str[1] == 0x63) {
            sp->unk18 = sp->unk10;
            sp->unk10 = InterpretColorChar(str[2]);
            str += 3;
        }
        else if (str[1] == 0x72) {
            sp->unk10 = sp->unk18;
            str += 2;
        }
        else if (str[1] == 0x53) {
            gUnknown_20274A6[str[2] & 0x7F] = str[3] & 0x7F;
            str += 4;
        }
        else if (str[1] == 0x57) {
            str += 2;
            sp->unk8 = ((strArr[0].unk0 * 8) + sp->unk0) - 2;
            sp->unkA = ((strArr[0].unk2 * 8) + sp->unk2) + 3;
            sp->unk20 = 1;
            break;
        }
        else if (str[1] == 0x50) {
            str += 2;
            sp->unk2 = 9999;
            sp->unk1C = 0;
            sp->unk20 = 1;
            break;
        }
        else if (str[1] == 0x70) {
            str += 2;
            sp->unk2 = 9999;
            sp->unk1C = 1;
            sp->unk20 = 1;
            break;
        }
        else if (str[1] == 0x7E) {
            sp->unk2C = str[2];
            sp->unk21 = 1;
            str += 3;
        }
        else {
            break;
        }
    }

    return str;
}

#else
NAKED const u8 *HandleTextFormat(UnkTextStruct1 *strArr, const u8 *str, struct UnkDrawStringStruct *sp)
{
    asm_unified("push {r4-r7,lr}\n"
"	mov r7, r9\n"
"	mov r6, r8\n"
"	push {r6,r7}\n"
"	mov r8, r0\n"
"	adds r4, r1, 0\n"
"	adds r5, r2, 0\n"
"	movs r0, 0\n"
"	mov r9, r0\n"
"	movs r7, 0x1\n"
"_080091C0:\n"
"	ldrb r0, [r4]\n"
"	cmp r0, 0x23\n"
"	beq _080091C8\n"
"	b _0800937A\n"
"_080091C8:\n"
"	ldrb r0, [r4, 0x1]\n"
"	adds r1, r0, 0\n"
"	cmp r1, 0x5B\n"
"	bne _08009216\n"
"	adds r2, r4, 0\n"
"	adds r4, 0x2\n"
"	adds r0, r5, 0\n"
"	adds r0, 0x21\n"
"	mov r1, r9\n"
"	strb r1, [r0]\n"
"	ldrb r1, [r4]\n"
"	adds r6, r0, 0\n"
"	cmp r1, 0\n"
"	beq _080091F6\n"
"	cmp r1, 0x5D\n"
"	beq _080091F4\n"
"_080091E8:\n"
"	adds r4, 0x1\n"
"	ldrb r0, [r4]\n"
"	cmp r0, 0\n"
"	beq _080091F6\n"
"	cmp r0, 0x5D\n"
"	bne _080091E8\n"
"_080091F4:\n"
"	adds r4, 0x1\n"
"_080091F6:\n"
"	ldr r3, [r5, 0x24]\n"
"	cmp r3, 0\n"
"	beq _0800920C\n"
"	adds r0, r2, 0\n"
"	adds r1, r4, 0\n"
"	adds r2, r5, 0\n"
"	bl _call_via_r3\n"
"	cmp r0, 0\n"
"	beq _0800920C\n"
"	adds r4, r0, 0\n"
"_0800920C:\n"
"	ldrb r0, [r6]\n"
"	cmp r0, 0\n"
"	beq _08009214\n"
"	b _0800937A\n"
"_08009214:\n"
"	b _080091C0\n"
"_08009216:\n"
"	cmp r1, 0x3D\n"
"	bne _08009220\n"
"	ldrb r0, [r4, 0x2]\n"
"	strh r0, [r5]\n"
"	b _080092BA\n"
"_08009220:\n"
"	cmp r1, 0x79\n"
"	bne _0800922A\n"
"	ldrb r0, [r4, 0x2]\n"
"	strh r0, [r5, 0x2]\n"
"	b _080092BA\n"
"_0800922A:\n"
"	cmp r1, 0x3E\n"
"	bne _0800923A\n"
"	adds r1, r4, 0x2\n"
"	adds r0, r5, 0\n"
"	bl sub_800915C\n"
"	adds r4, r0, 0\n"
"	b _080091C0\n"
"_0800923A:\n"
"	cmp r1, 0x2E\n"
"	bne _08009246\n"
"	ldrh r0, [r5]\n"
"	ldrb r2, [r4, 0x2]\n"
"	adds r0, r2\n"
"	b _0800926E\n"
"_08009246:\n"
"	cmp r1, 0x6E\n"
"	bne _08009258\n"
"	ldr r0, [r5, 0xC]\n"
"	strh r0, [r5]\n"
"	ldrh r0, [r5, 0x2]\n"
"	adds r0, 0xB\n"
"	strh r0, [r5, 0x2]\n"
"	adds r4, 0x2\n"
"	b _080091C0\n"
"_08009258:\n"
"	cmp r1, 0x3A\n"
"	bne _08009264\n"
"	ldrh r0, [r5]\n"
"	strh r0, [r5, 0x4]\n"
"	adds r4, 0x2\n"
"	b _080091C0\n"
"_08009264:\n"
"	cmp r1, 0x3B\n"
"	bne _08009274\n"
"	ldrh r0, [r5, 0x4]\n"
"	ldrb r3, [r4, 0x2]\n"
"	adds r0, r3\n"
"_0800926E:\n"
"	strh r0, [r5]\n"
"	adds r4, 0x3\n"
"	b _080091C0\n"
"_08009274:\n"
"	cmp r1, 0x2B\n"
"	bne _0800929A\n"
"	adds r4, 0x2\n"
"	adds r0, r4, 0\n"
"	bl sub_8008ED0\n"
"	mov r2, r8\n"
"	movs r3, 0x4\n"
"	ldrsh r1, [r2, r3]\n"
"	lsls r1, 3\n"
"	subs r1, r0\n"
"	strh r1, [r5]\n"
"	movs r1, 0\n"
"	ldrsh r0, [r5, r1]\n"
"	lsrs r1, r0, 31\n"
"	adds r0, r1\n"
"	asrs r0, 1\n"
"	strh r0, [r5]\n"
"	b _080091C0\n"
"_0800929A:\n"
"	cmp r1, 0x43\n"
"	bne _080092A4\n"
"	ldr r0, [r5, 0x10]\n"
"	str r0, [r5, 0x14]\n"
"	b _080092DC\n"
"_080092A4:\n"
"	lsls r0, 24\n"
"	lsrs r0, 24\n"
"	cmp r0, 0x5F\n"
"	bne _080092CC\n"
"	ldr r0, [r5, 0x10]\n"
"	str r0, [r5, 0x14]\n"
"	ldr r1, _080092C8\n"
"	ldrb r0, [r4, 0x2]\n"
"	adds r0, r1\n"
"	ldrb r0, [r0]\n"
"	str r0, [r5, 0x10]\n"
"_080092BA:\n"
"	adds r4, 0x3\n"
"	ldrb r0, [r4]\n"
"	cmp r0, 0x2E\n"
"	beq _080092C4\n"
"	b _080091C0\n"
"_080092C4:\n"
"	adds r4, 0x1\n"
"	b _080091C0\n"
"	.align 2, 0\n"
"_080092C8: .4byte gUnknown_202749A\n"
"_080092CC:\n"
"	cmp r0, 0x52\n"
"	bne _080092D4\n"
"	ldr r0, [r5, 0x14]\n"
"	b _080092EE\n"
"_080092D4:\n"
"	cmp r0, 0x63\n"
"	bne _080092E8\n"
"	ldr r0, [r5, 0x10]\n"
"	str r0, [r5, 0x18]\n"
"_080092DC:\n"
"	ldrb r0, [r4, 0x2]\n"
"	bl InterpretColorChar\n"
"	str r0, [r5, 0x10]\n"
"	adds r4, 0x3\n"
"	b _080091C0\n"
"_080092E8:\n"
"	cmp r0, 0x72\n"
"	bne _080092F4\n"
"	ldr r0, [r5, 0x18]\n"
"_080092EE:\n"
"	str r0, [r5, 0x10]\n"
"	adds r4, 0x2\n"
"	b _080091C0\n"
"_080092F4:\n"
"	cmp r0, 0x53\n"
"	bne _08009314\n"
"	ldr r3, _08009310\n"
"	ldrb r2, [r4, 0x2]\n"
"	movs r0, 0x7F\n"
"	adds r1, r0, 0\n"
"	ands r1, r2\n"
"	adds r1, r3\n"
"	ldrb r2, [r4, 0x3]\n"
"	ands r0, r2\n"
"	strb r0, [r1]\n"
"	adds r4, 0x4\n"
"	b _080091C0\n"
"	.align 2, 0\n"
"_08009310: .4byte gUnknown_20274A6\n"
"_08009314:\n"
"	cmp r0, 0x57\n"
"	bne _0800933A\n"
"	adds r4, 0x2\n"
"	mov r2, r8\n"
"	movs r3, 0\n"
"	ldrsh r0, [r2, r3]\n"
"	lsls r0, 3\n"
"	ldrh r1, [r5]\n"
"	adds r0, r1\n"
"	subs r0, 0x2\n"
"	strh r0, [r5, 0x8]\n"
"	movs r3, 0x2\n"
"	ldrsh r0, [r2, r3]\n"
"	lsls r0, 3\n"
"	ldrh r1, [r5, 0x2]\n"
"	adds r0, r1\n"
"	adds r0, 0x3\n"
"	strh r0, [r5, 0xA]\n"
"	b _0800935C\n"
"_0800933A:\n"
"	cmp r0, 0x50\n"
"	bne _08009350\n"
"	adds r4, 0x2\n"
"	ldr r0, _0800934C\n"
"	strh r0, [r5, 0x2]\n"
"	mov r2, r9\n"
"	str r2, [r5, 0x1C]\n"
"	b _0800935C\n"
"	.align 2, 0\n"
"_0800934C: .4byte 0x0000270f\n"
"_08009350:\n"
"	cmp r0, 0x70\n"
"	bne _08009368\n"
"	adds r4, 0x2\n"
"	ldr r0, _08009364\n"
"	strh r0, [r5, 0x2]\n"
"	str r7, [r5, 0x1C]\n"
"_0800935C:\n"
"	adds r0, r5, 0\n"
"	adds r0, 0x20\n"
"	strb r7, [r0]\n"
"	b _0800937A\n"
"	.align 2, 0\n"
"_08009364: .4byte 0x0000270f\n"
"_08009368:\n"
"	cmp r0, 0x7E\n"
"	bne _0800937A\n"
"	ldrb r0, [r4, 0x2]\n"
"	str r0, [r5, 0x2C]\n"
"	adds r0, r5, 0\n"
"	adds r0, 0x21\n"
"	strb r7, [r0]\n"
"	adds r4, 0x3\n"
"	b _080091C0\n"
"_0800937A:\n"
"	adds r0, r4, 0\n"
"	pop {r3,r4}\n"
"	mov r8, r3\n"
"	mov r9, r4\n"
"	pop {r4-r7}\n"
"	pop {r1}\n"
"	bx r1\n");
}
#endif // NONMATCHING

extern s32 gUnknown_202B020;
extern s32 gUnknown_202B024;

void sub_8009388(void)
{
    s32 i, j;

    gUnknown_202B038[0][0][0] = 0xF279;
    gUnknown_202B038[1][0][0] = 0xF27A;
    for (i = gUnknown_202B020; i < gUnknown_202B024; i++) {
        gUnknown_202B038[0][i][0] = 0xF279;
        gUnknown_202B038[1][i][0] = 0xF27A;
        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xF27A;
        }
    }
}

void sub_8009408(s32 from, s32 to)
{
    s32 i, j;

    gUnknown_202B038[0][0][0] = 0xF279;
    gUnknown_202B038[1][0][0] = 0xF27A;
    for (i = from; i < to; i++) {
        gUnknown_202B038[0][i][0] = 0xF279;
        gUnknown_202B038[1][i][0] = 0xF27A;
        for (j = 1; j < 32; j++) {
            gUnknown_202B038[0][i][j] = 0;
            gUnknown_202B038[1][i][j] = 0xF27A;
        }
    }
    gUnknown_20274A5 = 1;
}

UNUSED void sub_8009488(s32 strArrId)
{
    s32 i, j;
    s32 id0, id1;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strArrId];

    id0 = strPtr->unk2;
    for (i = 0; i < strPtr->unk6; i++) {
        id1 = strPtr->unk0;
        for (j = 0; j < strPtr->unk4; j++) {
            gUnknown_202B038[0][id0][id1] &= 0xFC00;
            gUnknown_202B038[1][id0][id1] = 0xF27A;
            id1++;
        }
        id0++;
    }
}

UNUSED void nullsub_172(void) {}

void sub_8009524(s32 strArrId)
{
    s32 i, j;
    UnkTextStruct1 *strPtr = &gUnknown_2027370[strArrId];
    s32 id0 = strPtr->unk2 - 1;

    for (i = 0; i < strPtr->unk6 + 2; i++) {
        s32 id1 = strPtr->unk0 - 1;
        for (j = 0; j < strPtr->unk4 + 2; j++) {
            gUnknown_202B038[0][id0][id1] &= 0xFC00;
            gUnknown_202B038[1][id0][id1] = 0xF27A;
            id1++;
        }
        id0++;
    }
}

UNUSED void nullsub_173(void) {}

void sub_80095CC(s32 a0, s32 a1)
{
    gUnknown_202B020 = a0;
    gUnknown_202B024 = a1;
}

UNUSED void nullsub_174(void) {}

s32 sub_80095E4(s32 a0, s32 a1)
{
    s32 r1;

    if (a1 == 0)
        a1 = 10;
    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

// Same as sub_80095E4 except it doesn't check for a1 == 0
s32 sub_8009614(s32 a0, s32 a1)
{
    s32 r1;

    r1 = a0 * a1;

    if ((r1 % 8) != 0)
        return (r1 / 8) + 1;
    else
        return r1 / 8;
}

s32 InterpretColorChar(u8 a0)
{
    if (a0 < 16)
        return a0;
    if (a0 >= '0' && a0 <= '?')
        return a0 - '0';

    switch (a0) {
        case 72:
        case 73:
            return 4;
        case 69:
        case 83:
        case 84:
            return 15;
        case 71:
        case 77:
            return 5;
        case 67:
        case 68:
        case 78:
            return 6;
        case 87:
            return 2;

    }
    return 7;
}
