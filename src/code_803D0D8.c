#include "global.h"
#include "globaldata.h"
#include "structs/str_wonder_mail.h"
#include "code_803D0D8.h"
#include "code_8092334.h"
#include "code_8094F88.h"
#include "code_80958E8.h"
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

bool8 sub_803D204(u8 *buffer,unkStruct_203B480 *param_2)
{
  s32 innerIndex;
  u8 checksum;
  u8 local_c4 [34];
  u8 translateBuffer [PASSWORD_BUFFER_SIZE];
  u8 localBuffer [PASSWORD_BUFFER_SIZE];
  unkStruct_8094924 uStack_30;
  s32 index;

    checksum = 0;
    MemoryCopy8(localBuffer,buffer,sizeof(localBuffer));
    for(index = 0; index < PASSWORD_BUFFER_SIZE; index++)
    {
        for(innerIndex = 0; innerIndex < PASSWORD_BUFFER_SIZE; innerIndex++)
        {
            if (innerIndex == gUnknown_80F43F0[index]) break;
        }
        translateBuffer[index] = localBuffer[innerIndex];
    }


    if (sub_803D110(translateBuffer,local_c4,sizeof(translateBuffer)) != 0) {

        for(index = 1; index < 34; index++)
        {
          checksum += local_c4[index] + index;
        }
        if (local_c4[0] == checksum) {
          xxx_init_struct_8094924_restore_809485C(&uStack_30,&local_c4[1],33);
          sub_8095774(&uStack_30,param_2);
          nullsub_102(&uStack_30);
          return TRUE;
        }
    }
    return FALSE;
}

void sub_803D2C0(u8 *buffer, unkStruct_203B480 *mail)
{
    u8 checksum;
    int index;
    u8 local_c0 [34];
    u8 buffer1 [PASSWORD_BUFFER_SIZE];
    u8 buffer2 [PASSWORD_BUFFER_SIZE];
    unkStruct_8094924 auStack_2c;

    checksum = 0;

    for(index = 0; index < 34; index++)
    {
        local_c0[index] = 0;
    }

    xxx_init_struct_8094924_save_809486C(&auStack_2c,&local_c0[1],33);
    sub_8095824(&auStack_2c,mail);
    nullsub_102(&auStack_2c);
    for(index = 1; index < 34; index++)
    {
        checksum += + local_c0[index] + index;
    }
    local_c0[0] = checksum;
    sub_803D1A8(buffer1,local_c0,sizeof(buffer1));
    for(index = 0; index < PASSWORD_BUFFER_SIZE; index++)
    {
        buffer2[gUnknown_80F43F0[index]] = buffer1[index];
    }
    MemoryCopy8(buffer,buffer2,sizeof(buffer2));
}

bool8 DecodeWonderMailPassword(u8* buffer, WonderMail *mail)
{
    s32 innerIndex;
    int index;
    u8 checksum;
    u8 local_70 [16];
    u8 local_60 [24];
    u8 password [24];
    unkStruct_8094924 puVar1;

    checksum = 0;
    MemoryCopy8(password,buffer,24);

    for(index = 0; index < 24; index++)
    {
        for(innerIndex = 0; innerIndex < 24; innerIndex++)
        {
            if (innerIndex == gUnknown_80F4426[index]) break;
        }
        local_60[index] = password[innerIndex];
    }



    if (sub_803D110(local_60,local_70,24) != 0) {

        for(index = 1; index < 0xF; index++)
        {
            checksum += (local_70[index] + index);
        }
        if (local_70[0] == checksum) {
            xxx_init_struct_8094924_restore_809485C(&puVar1,&local_70[1],0xc);
            RestoreWonderMail(&puVar1,mail);
            nullsub_102(&puVar1);
            return TRUE;
        }
    }
    return FALSE;
}

void sub_803D414(u8 *buffer,WonderMail *mail)
{
    u8 checksum;
    s32 index;
    u8 local_6c [15];
    u8 local_5c [24];
    u8 auStack_44 [24];
    unkStruct_8094924 uStack_2c;

    checksum = 0;
    for(index = 0; index < 0xF; index++)
    {
        local_6c[index] = 0;
    }

    xxx_init_struct_8094924_save_809486C(&uStack_2c,&local_6c[1],12);
    SaveWonderMail(&uStack_2c,mail);
    nullsub_102(&uStack_2c);

    for(index = 1; index < 0xF; index++)
    {
        checksum  += local_6c[index] + index;
    }
    local_6c[0] = checksum;
    sub_803D1A8(local_5c,local_6c, sizeof(local_5c));
    for(index = 0; index < 0x18; index++)
    {
        auStack_44[(gUnknown_80F4426)[index]] = local_5c[index];
    }
    MemoryCopy8(buffer,auStack_44,sizeof(auStack_44));
}

void sub_803D4AC(void)
{
    gDungeon->unk1C570.id = 0x63;
    gDungeon->unk1C570.floor = 0xFF;
}
