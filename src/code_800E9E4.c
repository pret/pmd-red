#include "global.h"
#include "structs/code_800E9E4.h"
#include "code_800E9E4.h"

extern s16 gUnknown_80CE73C[20];

extern unkStruct_80CE37C gUnknown_80CE37C[1];

extern unkStruct_80BDBC4 gUnknown_80BDBC4[430];
extern unkStruct_80B9CC4 gUnknown_80B9CC4[448];


extern unkStruct_80C183C gUnknown_80C183C[4336];

// FILE SPLIT

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
