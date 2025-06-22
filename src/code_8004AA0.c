#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"

void nullsub_6(void)
{
}

void sub_8004AA4(unkStruct_202EE8C *a0, OpenedFile *a1, s32 a2)
{
    unkDataFor8004AA4 **data;
    unkDataFor8004AA4 *ptr;
    s32 i;

    data = (unkDataFor8004AA4 **)a1->data;
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

bool8 sub_8004AF0(bool8 a0, unkStruct_202EE8C *a1, s32 a2, s32 a3, s32 a4, const RGB *a5)
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
            SetBGPaletteBufferColorRGB(a2, &a1->unk14, a4, a5);
    }

    return ret;
}

UNUSED static bool8 sub_8004B78(bool8 a0, unkStruct_202EE8C *a1, s32 a2, s32 a3, s32 a4, const RGB *a5)
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
            nullsub_4(a2, &a1->unk14, a4, a5);
    }

    return ret;
}

bool8 sub_8004C00(unkStruct_202EE8C *a0, s32 a1, s32 a2, s32 brightness, const RGB *ramp, s16 *a5)
{
    bool8 ret;
    s32 i;
    s32 r;
    s32 g;
    s32 b;
    RGB color;

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

        r = a5[0] + a0->unk14.r;
        g = a5[1] + a0->unk14.g;
        b = a5[2] + a0->unk14.b;

        if (r > 0xFF)
            r = 0xFF;
        if (g > 0xFF)
            g = 0xFF;
        if (b > 0xFF)
            b = 0xFF;
        if (r < 0)
            r = 0;
        if (g < 0)
            g = 0;
        if (b < 0)
            b = 0;

        color.r = r;
        color.g = g;
        color.b = b;

        SetBGPaletteBufferColorRGB(a1, &color, brightness, ramp);
    }

    return ret;
}

UNUSED static void sub_8004CFC(unkStruct_202EE8C *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < a1; a0++, i++) {
        a0->unk0 = 0;
    }
}

bool8 sub_8004D14(unkStruct_202EE8C *a0, s32 a1)
{
    s32 i;

    for (i = 0; i < a1; i++) {
        if (a0->unk0 & 0x80000000)
            return TRUE;
        a0++;
    }
    return FALSE;
}

bool8 sub_8004D40(unkStruct_202EE8C *a0, s32 a1)
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
