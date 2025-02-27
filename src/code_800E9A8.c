#include "global.h"
#include "structs/code_800E9E4.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "code_800E9E4.h"
#include "structs/str_position.h"

s32 sub_800E2C0(u32);

extern struct unkStruct_203B0CC *gUnknown_203B0CC;

void sub_800DE38(struct unkStruct_203B0CC_sub *);
void sub_800DE8C(struct unkStruct_203B0CC_sub *, DungeonPos *);
void sub_800DD0C(struct unkStruct_203B0CC_sub *, DungeonPos *);
void sub_800DCD0(struct unkStruct_203B0CC_sub *);

s32 sub_800E900(s32 r0);
s32 sub_800E208(s32, unkStruct_800E208*);

bool8 sub_800E7D0(u16 *param_1)
{
    int local_1c [4];
    bool8 flag;
    s32 index;

    flag = FALSE;
    local_1c[0] = sub_800ECB8(*param_1)->unk0;
    local_1c[1] = sub_800ECB8(*param_1)->unk2;
    local_1c[2] = sub_800ECB8(*param_1)->unk4;
    local_1c[3] = sub_800ECB8(*param_1)->unk6;
    for(index = 0; index < 4; index++)
    {
        flag = (sub_800ECA4(local_1c[index])->animType == 4);
        if(flag) break;
    }
    return flag;
}

bool8 sub_800E838(u16 *param_1, s32 param_2)
{
    s32 local_1c [4];

    local_1c[0] = sub_800ECB8(*param_1)->unk0;
    local_1c[1] = sub_800ECB8(*param_1)->unk2;
    local_1c[2] = sub_800ECB8(*param_1)->unk4;
    local_1c[3] = sub_800ECB8(*param_1)->unk6;
    return sub_800ECA4(local_1c[param_2])->animType == 4;
}

// TODO: look at this later
// https://decomp.me/scratch/luz2f
u32 sub_800E890(unkStruct_80416E0 *param_1)
{
    param_1->unk14 = sub_800E900(param_1->unk0);
    return sub_800E208(7, (void*)&param_1->unk0);
}

void sub_800E8AC(s32 a0, DungeonPos *a1, DungeonPos *a2, s32 a3, unkStruct_2039DB0 *a4)
{
    s32 index;
    struct unkStruct_203B0CC_sub *ptr;

    index = sub_800E2C0(a0);
    if(index != -1)
    {
        ptr = &gUnknown_203B0CC->unk0[index];

        if(a1 != NULL) ptr->unk18 = *a1;
        if(a2 != NULL) ptr->unk1c = *a2;
        if(a3 != 0xFFFF) ptr->unk24 = a3;
        if(a4 != NULL) ptr->spriteMasks = *a4;
    }
}

s32 sub_800E900(s32 r0)
{
    return sub_800ECA4(r0)->unk1c;
}

bool8 sub_800E90C(DungeonPos *param_1)
{
    bool8 flag;
    s32 iVar1;
    struct unkStruct_203B0CC_sub *ptr;

    flag = FALSE;

    for(iVar1 = 0, ptr = &gUnknown_203B0CC->unk0[iVar1]; iVar1 < 0x20; iVar1++, ptr++)
    {
        if(ptr->unk4 != -1)
        {
            if(ptr->unk10 <= 0)
            {
                if(ptr->unk34 == 4)
                {
                    sub_800DE8C(ptr, param_1);
                }
                else
                {
                    sub_800DD0C(ptr, param_1);
                }

            }
            if(ptr->unk10 > 0)
                ptr->unk10--;
            sub_800DCD0(ptr);
            if(ptr->unk54 == 0)
                flag = TRUE;
        }
    }

    return flag;
}

void sub_800E970(void)
{
    s32 iVar1;
    struct unkStruct_203B0CC_sub *ptr;

    for(iVar1 = 0, ptr = &gUnknown_203B0CC->unk0[iVar1]; iVar1 < 0x20; iVar1++, ptr++)
    {
        if(ptr->unk4 != -1)
            if(ptr->unk10 <= 0)
                if(ptr->unk34 != 4)
                    sub_800DE38(ptr);
    }
}

bool8 sub_800E9A8(s32 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;

    if (a0 == -1)
        return FALSE;

    ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < 32; i++, ptr++) {
        if (ptr->unk4 == a0) {
            if (ptr->unk54 != 0)
                return FALSE;
            return TRUE;
        }
    }

    return FALSE;
}

bool8 sub_800E9E4(u32 param_1)
{
    if(sub_800E2C0(param_1) != -1)
    {
        return TRUE;
    }
    else {
        return FALSE;
    }
}

bool8 sub_800E9FC(u8 a0)
{
    s32 i;
    struct unkStruct_203B0CC_sub *ptr;


    ptr = gUnknown_203B0CC->unk0;
    for (i = 0; i < 32; i++, ptr++) {
        if (ptr->unk4 != -1) {
            if(a0 != 0)
                return TRUE;
            if (ptr->unk54 == 0)
                return TRUE;
        }
    }

    if(sub_800EC74())
        return TRUE;
    return FALSE;
}
