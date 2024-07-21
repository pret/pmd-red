#include "global.h"
#include "globaldata.h"
#include "code_803D0D8.h"
#include "code_8092334.h"
#include "memory.h"

static EWRAM_DATA_2 u8 sUnknown_203B408 = {0};

#include "data/code_803D0D8.h"

u8 sub_803D0D8()
{
    return sUnknown_203B408;
}

UNUSED static void sub_803D0E4(u8 a0)
{
    sUnknown_203B408 = a0;
}

u8 sub_803D0F0(u8 r0)
{
    return sUnknown_80F42F0[r0];
}

u8 sub_803D100(u8 r0)
{
    return sUnknown_80F42D0[r0];
}

u8 sub_803D110(u8 *param_1, u8 *param_2, s32 size)
{
    s32 index1;
    s32 newSize;
    s32 save;
    unkStruct_8094924 auStack_88;
    u8 local_78 [56];
    u8 auStack_40 [36];


    for(index1 = 0; index1 < 34; index1++)
    {
        auStack_40[index1] = 0;
    }

    for (index1 = 0; index1 < size; index1++) 
    {
        local_78[index1] = sub_803D0F0(*param_1);
        if (local_78[index1] == 0xff) {
            return 0;
        }
        param_1++;
    }

    newSize = size * 5 + 5;
    if (newSize < 0) {
        newSize = size * 5 + 0xc;
    }

    newSize >>= 3;
    save = newSize;
    xxx_init_struct_8094924_save_809486C(&auStack_88,auStack_40, save);

    for(index1 = 0; index1 < size; index1++)
    {
        SaveIntegerBits(&auStack_88, &local_78[index1], 5);
    }
    nullsub_102(&auStack_88);
    MemoryCopy8(param_2, auStack_40, save);
    return 1;
}

void sub_803D1A8(u8 *param_1, u8 *param_2, s32 size)
{
    s32 index;
    s32 newSize;
    unkStruct_8094924 auStack_5c;
    u8 local_4c [56];

    newSize = size * 5 + 5;
    if (newSize < 0) {
        newSize = size * 5 + 0xc;
    }
    newSize >>= 3;
    xxx_init_struct_8094924_restore_809485C(&auStack_5c, param_2, newSize);
    for(index = 0; index < size; index++)
    {
        RestoreIntegerBits(&auStack_5c, &local_4c[index], 5);
    }

    nullsub_102(&auStack_5c);
    for(index = 0; index < size; index++)
    {
        *param_1++ = sub_803D100(local_4c[index]);
    }
}

// Probably continues in code_803D110.s
