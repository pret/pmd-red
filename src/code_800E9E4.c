#include "global.h"
#include "structs/code_800E9E4.h"
#include "code_800E9E4.h"
#include "code_800E9A8.h"

extern s32 sub_800E2C0(u32);
u32 sub_800F19C(s32);
s32 sub_800EBBC(s32);
s32 sub_800EC68(s32);

extern struct unkStruct_203B0CC *gUnknown_203B0CC;

extern unkStruct_80B9C60 gUnknown_80B9C60;

extern s32 gUnknown_80B9C9C[8];
extern s16 gUnknown_80CE73C[20];

extern unkStruct_80CE37C gUnknown_80CE37C[1];

extern unkStruct_80BDBC4 gUnknown_80BDBC4[430];
extern unkStruct_80B9CC4 gUnknown_80B9CC4[448];


extern unkStruct_80C183C gUnknown_80C183C[4336];
unkStruct_80C183C *sub_800ECD0(s32 param_1);


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

void sub_800EAE4(s32 param_1, DungeonPos *param_2, DungeonPos *param_3)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1)
    {
        struct unkStruct_203B0CC_sub *a;
        a = &gUnknown_203B0CC->unk0[idx];
        a->unk18 = *param_2;
        if (a->unk20 != -1)
        {
            a->unk1c = *param_3;
        }
        else
        {
            a->unk1c.x = 0;
            a->unk1c.y = 0;
        }
    }
}

void sub_800EB24(s32 param_1, DungeonPos *param_2, DungeonPos *param_3, s32 r5, s32 r4)
{
    s32 idx = sub_800E2C0(param_1);
    if (idx != -1) {
        struct unkStruct_203B0CC_sub *curStruct;
        curStruct = &gUnknown_203B0CC->unk0[idx];
        if (curStruct->unkCC[0] == 0 && curStruct->unkCC[1] == 0) {
            curStruct->unk18 = *param_2;
        }

        if (curStruct->unk0 == 6) {
            curStruct->unk24 = r5 + 1;
        }
        else if ((curStruct->unk8 & 0x7) == 0) {
            s32 newStruct[8];
            memcpy(newStruct, gUnknown_80B9C9C, sizeof(s32) * 8);
            curStruct->unk24 = r5 + newStruct[r4 & 7];
        }
        else {
            curStruct->unk24 = r5 + 1;
        }

        if (curStruct->unk20 != -1) {
            curStruct->unk1c = *param_3;
        }
        else {
            curStruct->unk1c.x = 0;
            curStruct->unk1c.y = 0;
        }
    }
}

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

void sub_800EC28(u32 param_1, DungeonPos *param_2, DungeonPos *param_3)
{
    s32 idx;
    idx = sub_800E2C0(param_1);
    if (idx != -1)
    {
        struct unkStruct_203B0CC_sub *struct203B0CC;
        struct203B0CC = &gUnknown_203B0CC->unk0[idx];
        struct203B0CC->unk18 = *param_2;
        if (struct203B0CC->unk20 != -1)
        {
            struct203B0CC->unk1c = *param_3;
        }
        else
        {
            struct203B0CC->unk1c.x = 0;
            struct203B0CC->unk1c.y = 0;
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
