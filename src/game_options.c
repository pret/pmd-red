#include "global.h"
#include "gUnknown_203B46C.h"
#include "code_8092334.h"

struct unkStruct_8109954
{
    // size: 0x10
    u32 unk0[4];
};

struct unkStruct_8094CB0
{
    u16 unk0;
    s16 unk2;
};

extern struct unkStruct_8109954 gUnknown_8109954;

extern struct UnkSaveStruct1 *gUnknown_203B46C;
extern struct UnkSaveStruct1 gUnknown_2038C70;
extern void sub_8094C14(void);
extern void sub_80099F0(u32);

void LoadGameOptions(void)
{
    gUnknown_203B46C = &gUnknown_2038C70;
}

struct UnkSaveStruct1 * GetGameOptions(void)
{
    return &gUnknown_2038C70;
}

void InitializeGameOptions(u8 r0)
{
    gUnknown_203B46C->unk8 = 0;
    if(r0 != 0)
    {
        gUnknown_203B46C->playerGender = 0;
    }
    gUnknown_203B46C->unk9 = 0;
    gUnknown_203B46C->unkA = 0;
    gUnknown_203B46C->unk0 = 0; 
    gUnknown_203B46C->unk1 = 1;
    gUnknown_203B46C->unk2 = 1;
    gUnknown_203B46C->unk3 = 1;
    gUnknown_203B46C->unk4 = 1;
    gUnknown_203B46C->unkC = 0;
    sub_8094C14();
}

bool32 GameOptionsNotChange(struct UnkSaveStruct1 *r0)
{
    // NOTE: had to nest to match
    if(gUnknown_203B46C->unk8 == r0->unk8)
        if(gUnknown_203B46C->unk9 == r0->unk9)
            if(gUnknown_203B46C->unkA == r0->unkA) 
                if(gUnknown_203B46C->playerGender == r0->playerGender)
                    if(gUnknown_203B46C->unk0 == r0->unk0)
                        if(gUnknown_203B46C->unk1 == r0->unk1) 
                            if(gUnknown_203B46C->unk2 == r0->unk2)
                                if(gUnknown_203B46C->unk3 == r0->unk3)
                                    if(gUnknown_203B46C->unk4 == r0->unk4)
                                        if(gUnknown_203B46C->unkC == r0->unkC)
                                            return TRUE;
    return FALSE;
}

void WriteGameOptions(struct unkStruct_8094924 *param_1)
{  
    u8 zero;
    u8 neg_1;
    u8 *puVar2;


    neg_1 = -1;
    zero = 0;

    SaveIntegerBits(param_1, &gUnknown_203B46C->unk8, 2);

    if(gUnknown_203B46C->unk9 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->unkA != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->playerGender != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->unk0 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->unk1 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->unk2 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    if(gUnknown_203B46C->unk3 != 0)
    {
        puVar2 = &neg_1;
    }
    else
    {
        puVar2 = &zero;
    }
    SaveIntegerBits(param_1, puVar2, 1);

    SaveIntegerBits(param_1, &gUnknown_203B46C->unk4, 3);
    SaveIntegerBits(param_1, &gUnknown_203B46C->unkC, 2);
}

void ReadGameOptions(struct unkStruct_8094924 *param_1)
{
    u8 byteArray[4];
    RestoreIntegerBits(param_1, byteArray, 2);
    gUnknown_203B46C->unk8  = byteArray[0] & 3;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unk9  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unkA  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->playerGender  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unk0  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unk1  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unk2  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 1);
    gUnknown_203B46C->unk3  = byteArray[0] & 1;

    RestoreIntegerBits(param_1, byteArray, 3);
    gUnknown_203B46C->unk4  = byteArray[0] & 7;

    RestoreIntegerBits(param_1, byteArray, 2);
    gUnknown_203B46C->unkC  = byteArray[0] & 3;

    sub_8094C14();
}

void sub_8094C14(void)
{
    struct unkStruct_8109954 temp;

    temp = gUnknown_8109954;

    sub_80099F0(temp.unk0[gUnknown_203B46C->unk8 & 3]);
}

u32 sub_8094C48(void)
{
    switch(gUnknown_203B46C->unk4)
    {
        default:
            return 1;
        case 0:
        case 3:
            return 0;
    }
}

u32 sub_8094C68(void)
{
    switch(gUnknown_203B46C->unk4)
    {
        default:
            return 1;
        case 2:
        case 5:
            return 0;
    }
}

void sub_8094C88(void)
{
    if(gUnknown_203B46C->unk4 < 3)
        gUnknown_203B46C->unk4 = 1;
    else
        {
            if((u8)(gUnknown_203B46C->unk4 - 3) > 2)
                return;
            else
                gUnknown_203B46C->unk4 = 4;
        }
}

void sub_8094CB0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CC0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CD0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CE0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094CF0(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

void sub_8094D00(struct unkStruct_8094CB0 *r0)
{
    r0->unk0 = -1;
    r0->unk2 = -1;
}

u32 sub_8094D10(void)
{
    return 0;
}

u32 sub_8094D14(void)
{
    return 0;
}

u32 sub_8094D18(void)
{
    return 0;
}

u32 sub_8094D1C(void)
{
    return 0;
}

u32 sub_8094D20(void)
{
    return 0;
}

u32 sub_8094D24(void)
{
    return 0;
}

