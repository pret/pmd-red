#include "global.h"
#include "globaldata.h"
#include "bg_palette_buffer.h"
#include "code_8002774.h"

IWRAM_INIT bool8 gUnknown_3001B58 = FALSE;
IWRAM_INIT u16 gUnknown_3001B5A = 0;

typedef struct unkStruct_3000C00_sub
{
    u8 unk0[4];
} unkStruct_3000C00_sub;

typedef struct unkStruct_3000C00
{
    bool8 unk0;
    u8 unk1;
    s16 unk2;
    unkStruct_3000C00_sub unk4;
    s32 unk8;
    void (*unkC)(u32, u32);
    void (*unk10)(u32);
} unkStruct_3000C00;

// TODO: make static once whole file is decompiled
#define UNK_3000400_ARR_COUNT 0x200
#define UNK_3000C00_ARR_COUNT 0x21
IWRAM_DATA struct S gUnknown_3000400[UNK_3000400_ARR_COUNT] = {0};
IWRAM_DATA unkStruct_3000C00 gUnknown_3000C00[UNK_3000C00_ARR_COUNT] = {0};

void sub_8003A34(u32, u32);
void sub_8003AC0(u32, u32);
void sub_8003C18(u32, u32);
void sub_8003E2C(u32, u32);
void sub_8003F60(u32, u32);
void sub_8004170(u32, u32);
void sub_8004388(u32, u32);
void sub_8003B50(u32);
void sub_8003D00(u32);
void sub_8003EC0(u32);
void sub_8004034(u32);
void sub_8004264(u32);
void sub_8004434(u32);
void sub_8003A74(u32);

NAKED
UNUSED static void sub_80035F8(void)
{
    asm_unified("	.text\n"
"	push {lr}\n"
"	pop {r0}\n"
"	bx r0\n");
}

void sub_8003600(void)
{
    unkStruct_3000C00 *it1;
    struct S *it2;
    bool8 *r6;
    s32 i;
    s32 zero;

    it1 = &gUnknown_3000C00[0];
    r6 = &gUnknown_3001B58;
    zero = 0;
    it2 = &gUnknown_3000400[0];

    for (i = 0; i < UNK_3000400_ARR_COUNT; it2++, i++)
    {
        it2->x0.x0[0] = zero;
        it2->x0.x0[1] = zero;
        it2->x0.x0[2] = zero;
        it2->x0.x0[3] = zero;
    }

    for (i = 0; i < UNK_3000C00_ARR_COUNT; i++, it1++)
    {
        it1->unk0 = FALSE;
        it1->unk2 = 0x100;
        it1->unk4.unk0[0] = 0;
        it1->unk4.unk0[1] = 0;
        it1->unk4.unk0[2] = 0;
        it1->unk4.unk0[3] = 0;
        it1->unk8 = 0;
        it1->unkC = &sub_8003A34;
        it1->unk10 = &sub_8003A74;
    }

    *r6 = TRUE;
}

void sub_8003664(s32 param_1, s16 param_2)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4.unk0[0] = 0;
    ptr->unk4.unk0[1] = 0;
    ptr->unk4.unk0[2] = 0;
    ptr->unk4.unk0[3] = 0;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003AC0;
    ptr->unk10 = &sub_8003B50;

    gUnknown_3001B58 = TRUE;
}

void sub_80036AC(s32 param_1, s16 param_2, unkStruct_3000C00_sub param_3)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003C18;
    ptr->unk10 = &sub_8003D00;

    gUnknown_3001B58 = TRUE;
}

void sub_80036F4(s32 param_1, s16 param_2, unkStruct_3000C00_sub param_3)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8003E2C;
    ptr->unk10 = &sub_8003EC0;

    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_800373C(s32 param_1, s16 param_2, s32 param_3)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4.unk0[0] = 0;
    ptr->unk4.unk0[1] = 0;
    ptr->unk4.unk0[2] = 0;
    ptr->unk4.unk0[3] = 0;
    ptr->unk8 = param_3;
    ptr->unkC = &sub_8003F60;
    ptr->unk10 = &sub_8004034;

    gUnknown_3001B58 = TRUE;
}

void sub_8003780(s32 param_1, s16 param_2, unkStruct_3000C00_sub param_3)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8004170;
    ptr->unk10 = &sub_8004264;

    gUnknown_3001B58 = TRUE;
}

void sub_80037C8(s32 param_1, s16 param_2, unkStruct_3000C00_sub param_3)
{
    u16 idx;
    unkStruct_3000C00 *ptr;
    idx = param_1;
    ptr = &gUnknown_3000C00[idx];

    ptr->unk0 = TRUE;
    ptr->unk2 = param_2;
    ptr->unk4 = param_3;
    ptr->unk8 = 0;
    ptr->unkC = &sub_8004388;
    ptr->unk10 = &sub_8004434;

    gUnknown_3001B58 = TRUE;
}

void sub_8003810(u32 param_1, struct S param_2)
{
    u16 idx;
    unkStruct_3000C00 *a;
    idx = (u16) param_1;
    a = &gUnknown_3000C00[idx / 16];
    a->unk0 = TRUE;

    gUnknown_3000400[idx] = param_2;
    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_8003844(u32 param_1, u32 param_2)
{
    u16 idx1;
    u16 idx2;
    unkStruct_3000C00 *a;
    idx1 = param_1;
    idx2 = param_2;
    a = &gUnknown_3000C00[idx1 / 16];
    a->unk0 = TRUE;

    gUnknown_3000400[idx1] = sub_80027A0(idx2);
    gUnknown_3001B58 = TRUE;
}

void sub_800388C(u32 param_1, struct S *param_2, s32 param_3)
{
    u16 idx1;
    u16 idx2;
    s32 sVar1;
    u16 sVar2;
    struct S *ptr1;
    unkStruct_3000C00 *ptr3;
    s32 i;

    idx1 = param_1;
    idx2 = idx1 / 16;
    sVar1 = idx1 + param_3 - 1;
    if (sVar1 < 0)
    {
        sVar1 += 0xf;
    }

    sVar1 = (sVar1 << 0xc) >> 0x10;
    sVar2 = sVar1;
    ptr1 = &gUnknown_3000400[idx1];

    for (i = 0; i < param_3; param_2++, ptr1++, i++)
    {
        *ptr1 = *param_2;
    }

    ptr3 = &gUnknown_3000C00[idx2];

    for (i = idx2; i <= sVar2; i++, ptr3++)
    {
        ptr3->unk0 = TRUE;
    }

    gUnknown_3001B58 = TRUE;
}

static UNUSED void sub_80038F0(u32 param_1, s16 *param_2, s32 param_3)
{
    u16 idx1;
    u16 idx2;
    u16 uVar;
    struct S *ptr1;
    unkStruct_3000C00 *ptr2;
    s32 i;

    idx1 = param_1;
    idx2 = idx1 / 16;
    uVar = (idx1 + param_3 - 1) / 16;
    ptr1 = &gUnknown_3000400[idx1];

    for (i = 0; i < param_3; i++)
    {
        *ptr1 = sub_80027A0(*param_2++);
        ptr1++;
    }

    ptr2 = &gUnknown_3000C00[idx2];

    for (i = idx2; i <= uVar; i++, ptr2++)
    {
        ptr2->unk0 = TRUE;
    }

    gUnknown_3001B58 = TRUE;
}

static UNUSED struct S_sub sub_8003978(u32 param_1)
{
    u16 idx;
    idx = param_1;
    return gUnknown_3000400[idx].x0;
}

static UNUSED u16 sub_8003988(u32 param_1)
{
    u16 idx;
    idx = param_1;
    return sub_8002774(gUnknown_3000400[idx].x0);
}

static UNUSED void sub_80039A4(u32 param_1)
{
    u16 idx;
    idx = param_1;
    gUnknown_3001B5A |= idx;
}

void sub_80039B8(void)
{
    s32 i;
    unkStruct_3000C00* ptr1;
    unkStruct_3000C00* ptr2;

    if (gUnknown_3001B58)
    {
        ptr1 = gUnknown_3000C00;
        if (gUnknown_3000C00[0xf].unk0)
        {
            gUnknown_3000C00[0x20].unk0 = TRUE;
        }

        for (i = 0; i < 0x20; i++, ptr1++)
        {
            if (ptr1->unk0)
            {
                ptr1->unk10((u16) i);
                ptr1->unk0 = FALSE;
            }
        }

        if (gUnknown_3000C00[0x20].unk0)
        {
            ptr2 = &gUnknown_3000C00[0x20];
            // here ptr2 == ptr1
            ptr1->unkC(0x20, 0xf0);
            ptr2->unk0 = FALSE;
        }

        gUnknown_3001B5A = 3;
        gUnknown_3001B58 = FALSE;
    }
}

void sub_8003A34(u32 param_1, u32 param_2)
{
    u16 idx;
    struct S *ptr1;
    u32 blue;
    u32 green;
    u32 red;
    u16 color;

    idx = param_2;
    ptr1 = &gUnknown_3000400[idx];
    blue = (ptr1->x0.x0[2] & 0xf8) << 7;
    green = (ptr1->x0.x0[1] & 0xf8) << 2;
    blue |= green;
    red = (ptr1->x0.x0[0] & 0xf8) >> 3;
    color = red | blue;
    SetBGPaletteBufferColor(idx, &color);
}

void sub_8003A74(u32 param_1)
{
    u16 idx;
    struct S *ptr1;
    u32 red;
    u32 green;
    u32 blue;
    s32 i;
    u16 color;

    idx = param_1 * 16;
    ptr1 = &gUnknown_3000400[idx];

    for (i = 0; i < 16; ptr1++, i++)
    {
        blue = (ptr1->x0.x0[2] & 0xf8) << 7;
        green = (ptr1->x0.x0[1] & 0xf8) << 2;
        blue |= green;
        red = (ptr1->x0.x0[0] & 0xf8) >> 3;
        color = red | blue;
        SetBGPaletteBufferColor(idx + i, &color);
    }
}
