#include "global.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"

void nullsub_6(void)
{}

void sub_8004AA4(struct unkStruct_202EE8C *a0, struct OpenedFile *a1, s32 a2)
{
    struct unkDataFor8004AA4 **data;
    struct unkDataFor8004AA4 *ptr;
    s32 i;

    data = (struct unkDataFor8004AA4 **)a1->data;
    for (i = 0; i < a2; i++) {
        ptr = *data++;

        if (ptr->colorCount != 0) {
            a0->unk0 = 0x80000000;
            a0->unk6 = ptr->unk2;
            a0->unk4 = ptr->unk2;
            a0->unk8 = ptr->colors;
            a0->unkC = ptr->colors;
            a0->unk10 = &ptr->colors[ptr->colorCount];
            a0->unk14 = ptr->colors[0];
        }
        else
            a0->unk0 = 0;

        a0++;
    }
}

bool8 sub_8004AF0(bool8 a0, struct unkStruct_202EE8C *a1, s32 a2, s32 a3, s32 a4, u8 *a5)
{
    bool8 bVar3;
    bool8 ret;
    s32 i;

    ret = FALSE;

    for (i = 0; i < a3; i++, a1++, a2++) {
        if (!sub_8004D14(a1, 1) || sub_8004D40(a1, 1))
            continue;

        bVar3 = a0;
        a1->unk6--;

        if (a1->unk6 <= 0) {
            a1->unk6 = a1->unk4;
            if (a1->unkC >= a1->unk10)
                a1->unkC = a1->unk8;

            a1->unk14 = *a1->unkC++;
            bVar3 = TRUE;
            ret = TRUE;
        }

        if (bVar3)
            SetBGPaletteBufferColorRGB(a2, (u8 *)&a1->unk14, a4, a5);
    }

    return ret;
}

UNUSED static bool8 sub_8004B78(bool8 a0, struct unkStruct_202EE8C *a1, s32 a2, s32 a3, s32 a4, u8 *a5)
{
    bool8 bVar3;
    bool8 ret;
    s32 i;

    ret = FALSE;

    for (i = 0; i < a3; i++, a1++, a2++) {
        if (!sub_8004D14(a1, 1) || sub_8004D40(a1, 1))
            continue;

        bVar3 = a0;
        a1->unk6--;

        if (a1->unk6 <= 0) {
            a1->unk6 = a1->unk4;
            if (a1->unkC >= a1->unk10)
                a1->unkC = a1->unk8;

            a1->unk14 = *a1->unkC++;
            bVar3 = TRUE;
            ret = TRUE;
        }

        if (bVar3)
            nullsub_4(a2, (u8 *)&a1->unk14, a4, a5);
    }

    return ret;
}

bool8 sub_8004C00(struct unkStruct_202EE8C *a0, s32 a1, s32 a2, s32 a3, u8 *a4, s16 *a5)
{
    bool8 ret;
    s32 i;
    s32 r1;
    s32 r3;
    s32 r5;
    u32 color32;
    u32 val;
    u32 val2;
    u32 val3;

    ret = FALSE;

    for (i = 0; i < a2; i++, a0++, a1++) {
        if (!sub_8004D14(a0, 1) || sub_8004D40(a0, 1))
            continue;

        a0->unk6--;

        if (a0->unk6 <= 0) {
            a0->unk6 = a0->unk4;
            if (a0->unkC >= a0->unk10)
                a0->unkC = a0->unk8;

            a0->unk14 = *a0->unkC++;
            ret = TRUE;
        }

        r1 = a5[0] + a0->unk14.unk0;
        r3 = a5[1] + a0->unk14.unk1;
        r5 = a5[2] + a0->unk14.unk2;

        if (r1 > 0xFF)
            r1 = 0xFF;
        if (r3 > 0xFF)
            r3 = 0xFF;
        if (r5 > 0xFF)
            r5 = 0xFF;
        if (r1 < 0)
            r1 = 0;
        if (r3 < 0)
            r3 = 0;
        if (r5 < 0)
            r5 = 0;

        val = (u8)r1;
        color32 &= 0xFFFFFF00;
        color32 |= val;

        val2 = (u8)r3 << 8;
        color32 &= 0xFFFF00FF;
        color32 |= val2;

        val3 = (u8)r5 << 16;
        color32 &= 0xFF00FFFF;
        color32 |= val3;

        SetBGPaletteBufferColorRGB(a1, (u8 *)&color32, a3, a4);
    }

    return ret;
}

UNUSED static void sub_8004CFC(struct unkStruct_202EE8C *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < a1; a0++, i++) {
        a0->unk0 = 0;
    }
}

bool8 sub_8004D14(struct unkStruct_202EE8C *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < a1; i++) {
        if (a0->unk0 & 0x80000000)
            return TRUE;
        a0++;
    }
    return FALSE;
}

bool8 sub_8004D40(struct unkStruct_202EE8C *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < a1; i++) {
        if (a0->unk0 & 0x80000000) {
            if (!(a0->unk0 & 0x20000000))
                return FALSE;
            a0++;
        }
    }
    return TRUE;
}