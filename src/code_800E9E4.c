#include "global.h"
#include "code_800E9E4.h"
#include "code_800E9A8.h"

extern s32 sub_800E2C0(u32);
u32 sub_800F19C(s32);
s32 sub_800EBBC(s32);
s32 sub_800EC68(s32);

struct unkStruct_203B0CC *gUnknown_203B0CC;

typedef struct unkStruct_80B9C60
{
    s32 unk0;
    s32 unk1;
    s32 unk2;
} unkStruct_80B9C60;

extern unkStruct_80B9C60 gUnknown_80B9C60;

extern s32 gUnknown_80B9C9C[8];
extern s16 gUnknown_80CE73C[20];

typedef struct unkStruct_80CE37C
{
    s16 unk0;
    s16 unk2;
} unkStruct_80CE37C;
unkStruct_80CE37C gUnknown_80CE37C[1];

extern unkStruct_80BDBC4 gUnknown_80BDBC4[430];
extern unkStruct_80B9CC4 gUnknown_80B9CC4[448];

typedef struct unkStruct_80C183C
{
    // size: 0xc
    s16 unk0;
    s16 unk2;
    u8 fill4[0xc - 0x4];
} unkStruct_80C183C;

extern unkStruct_80C183C gUnknown_80C183C[4336];
unkStruct_80C183C *sub_800ECD0(s32 param_1);

typedef struct unkStruct_800EA44
{
    s16 unk0;
    s16 unk2;
} unkStruct_800EA44;

u8 sub_800EA44(unkStruct_800EA44 param_1, s32 param_2)
{
    s32 a;
    unkStruct_80BDBC4 *ret;
    unkStruct_80C183C *unkStruct2;
    s32 i;

    a = (s32) param_1.unk0;
    ret = sub_800ECB8(param_2);
    unkStruct2 = sub_800ECD0(ret->unk20);

    for (i = 0; i < ret->unk1C; i++, unkStruct2++)
    {
        if (unkStruct2->unk0 == a)
        {
            return unkStruct2->unk2;
        }
    }

    return ret->unk10;
}

typedef struct unkStruct_800E208
{
    s32 unk00[7];
    unkStruct_80B9C60 unk1c;
} unkStruct_800E208;

s32 sub_800E208(s32, unkStruct_800E208*);

s32 sub_800EA84(s32 *param_1)
{
    unkStruct_800E208 stack[2];
    unkStruct_80BDBC4 *ret1;
    u32 size;
    ret1 = sub_800ECB8(param_1[0]);
    
    stack[1].unk00[0] = ret1->unk0;
    stack[1].unk00[1] = param_1[4];
    stack[1].unk00[2] = param_1[3];
    stack[1].unk00[3] = param_1[1];
    stack[1].unk00[4] = param_1[2];
    
    ret1 = sub_800ECB8(param_1[0]);
    stack[1].unk00[5] = sub_800EBBC(ret1->unk0);
    stack[1].unk00[6] = 0x0000ffff;
    stack[1].unk1c = gUnknown_80B9C60;

    size = sizeof(unkStruct_800E208);
    memcpy(&stack[0],&stack[1],size);
    return sub_800E208(5, &stack[0]);
}

void sub_800EAE4(s32 param_1, s32 *param_2, unkStruct_800EAE4 *param_3)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1)
    {
        struct unkStruct_203B0CC_sub *a;
        a = &gUnknown_203B0CC->unk0[idx];
        a->unk18 = param_2[0];
        if (a->unk20 != -1)
        {
            a->unk1c = *param_3;
        }
        else
        {
            a->unk1c.unk0 = 0;
            a->unk1c.unk2 = 0;
        }
    }
}

#ifdef NONMATCHING // 99,32% match, r4/r5 regswap https://decomp.me/scratch/0cu86
void sub_800EB24(s32 param_1, s32 *param_2, unkStruct_800EAE4 *param_3, s32 param_4, s32 param_5)
{
    s32 idx;
    idx = sub_800E2C0(param_1);
    if (idx != -1)
    {
        struct unkStruct_203B0CC_sub *curStruct;
        curStruct = &gUnknown_203B0CC->unk0[idx];
        if (curStruct->unkCC == 0)
        {
            curStruct->unk18 = param_2[0];
        }

        if (curStruct->unk0 != 6 && (curStruct->unk8 & 0x7) == 0)
        {
            s32 newStruct[8];
            memcpy(newStruct, gUnknown_80B9C9C, sizeof(s32) * 8);
            param_4 += newStruct[param_5 & 0x7];
        }
        else
        {
            param_4 += 1;
        }

        curStruct->unk24 = param_4;

        if (curStruct->unk20 != -1)
        {
            curStruct->unk1c = *param_3;
        }
        else
        {
            curStruct->unk1c.unk0 = 0;
            curStruct->unk1c.unk2 = 0;
        }
    }
}
#else
NAKED
void sub_800EB24(s32 param_1, s32 *param_2, unkStruct_800EAE4 *param_3, s32 param_4, s32 param_5)
{
    asm_unified(	"\n"
"	push {r4-r7,lr}\n"
"	mov r7, r8\n"
"	push {r7}\n"
"	sub sp, 0x20\n"
"	adds r6, r1, 0\n"
"	mov r8, r2\n"
"	adds r5, r3, 0\n"
"	ldr r4, [sp, 0x38]\n"
"	bl sub_800E2C0\n"
"	adds r1, r0, 0\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r1, r0\n"
"	beq _0800EBB0\n"
"	ldr r2, _0800EB8C\n"
"	movs r0, 0xD0\n"
"	muls r1, r0\n"
"	ldr r0, [r2]\n"
"	adds r2, r0, r1\n"
"	adds r0, r2, 0\n"
"	adds r0, 0xCC\n"
"	ldr r0, [r0]\n"
"	cmp r0, 0\n"
"	bne _0800EB5A\n"
"	ldr r0, [r6]\n"
"	str r0, [r2, 0x18]\n"
"_0800EB5A:\n"
"	ldr r0, [r2]\n"
"	cmp r0, 0x6\n"
"	beq _0800EB94\n"
"	ldr r0, [r2, 0x8]\n"
"	movs r1, 0x7\n"
"	mov r12, r1\n"
"	ands r0, r1\n"
"	cmp r0, 0\n"
"	bne _0800EB94\n"
"	mov r1, sp\n"
"	ldr r0, _0800EB90\n"
"	ldm r0!, {r3,r6,r7}\n"
"	stm r1!, {r3,r6,r7}\n"
"	ldm r0!, {r3,r6,r7}\n"
"	stm r1!, {r3,r6,r7}\n"
"	ldm r0!, {r3,r6}\n"
"	stm r1!, {r3,r6}\n"
"	mov r7, r12\n"
"	ands r4, r7\n"
"	lsls r0, r4, 2\n"
"	add r0, sp\n"
"	ldr r0, [r0]\n"
"	adds r0, r5, r0\n"
"	b _0800EB96\n"
"	.align 2, 0\n"
"_0800EB8C: .4byte gUnknown_203B0CC\n"
"_0800EB90: .4byte gUnknown_80B9C9C\n"
"_0800EB94:\n"
"	adds r0, r5, 0x1\n"
"_0800EB96:\n"
"	str r0, [r2, 0x24]\n"
"	ldr r1, [r2, 0x20]\n"
"	movs r0, 0x1\n"
"	negs r0, r0\n"
"	cmp r1, r0\n"
"	beq _0800EBAA\n"
"	mov r1, r8\n"
"	ldr r0, [r1]\n"
"	str r0, [r2, 0x1C]\n"
"	b _0800EBB0\n"
"_0800EBAA:\n"
"	movs r0, 0\n"
"	strh r0, [r2, 0x1C]\n"
"	strh r0, [r2, 0x1E]\n"
"_0800EBB0:\n"
"	add sp, 0x20\n"
"	pop {r3}\n"
"	mov r8, r3\n"
"	pop {r4-r7}\n"
"	pop {r0}\n"
"	bx r0\n"
);
}
#endif // NONMATCHING

s32 sub_800EBBC(s32 param_1)
{
    unkStruct_80B9CC4 *ret = sub_800ECA4(param_1);
    return ret->unk1c;
}

s32 sub_800EBC8(s32 *param_1)
{
    unkStruct_800E208 stack[2];
    unkStruct_80BDBC4 *ret1;
    u32 size;
    ret1 = sub_800ECB8(param_1[0]);
    
    stack[1].unk00[0] = ret1->unk4;
    stack[1].unk00[1] = param_1[4];
    stack[1].unk00[2] = param_1[3];
    stack[1].unk00[3] = param_1[1];
    stack[1].unk00[4] = param_1[2];
    
    ret1 = sub_800ECB8(param_1[0]);
    stack[1].unk00[5] = sub_800EC68(ret1->unk4);
    stack[1].unk00[6] = 0x0000ffff;
    stack[1].unk1c = gUnknown_80B9C60;

    size = sizeof(unkStruct_800E208);
    memcpy(&stack[0],&stack[1],size);
    return sub_800E208(6, &stack[0]);
}

void sub_800EC28(u32 param_1, s32 *param_2, unkStruct_800EAE4 *param_3)
{
    s32 idx;
    idx = sub_800E2C0(param_1);
    if (idx != -1)
    {
        struct unkStruct_203B0CC_sub *struct203B0CC;
        struct203B0CC = &gUnknown_203B0CC->unk0[idx];
        struct203B0CC->unk18 = param_2[0];
        if (struct203B0CC->unk20 != -1)
        {
            struct203B0CC->unk1c = *param_3;
        }
        else
        {
            struct203B0CC->unk1c.unk0 = 0;
            struct203B0CC->unk1c.unk2 = 0;
        }
    }
}

s32 sub_800EC68(s32 param_1)
{
    unkStruct_80B9CC4 *ret = sub_800ECA4(param_1);
    return ret->unk1c;
}

u8 sub_800EC74(void)
{
    return sub_800F19C(1);
}

u8 sub_800EC84(s32 param_1)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(param_1);
    return ret->unk8;
}

u8 sub_800EC94(s32 param_1)
{
    unkStruct_80BDBC4 *ret;
    ret = sub_800ECB8(param_1);
    return ret->unk9;
}

unkStruct_80B9CC4 *sub_800ECA4(s32 param_1)
{
    return &gUnknown_80B9CC4[param_1];
}

unkStruct_80BDBC4 *sub_800ECB8(u16 param_1)
{
    return &gUnknown_80BDBC4[param_1];
}

unkStruct_80C183C *sub_800ECD0(s32 param_1)
{
    return &gUnknown_80C183C[param_1];
}

s16 sub_800ECE4(u8 param_1)
{
    return gUnknown_80CE73C[param_1];
}

s16 sub_800ECF8(u8 param_1)
{
    return gUnknown_80CE37C[param_1].unk0;
}

s16 sub_800ED0C(u8 param_1)
{
    return gUnknown_80CE37C[param_1].unk2;
}

s32 sub_800ED20(u16 param_1)
{
    return gUnknown_80BDBC4[param_1].unkC;
}
