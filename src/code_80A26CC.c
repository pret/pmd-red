#include "global.h"

struct unkStruct_80A2608
{
    /* 0x0 */ s16 unk0;
    /* 0x2 */ u16 padding;
    /* 0x4 */ u32 padding2;
    /* 0x8 */ u16 padding3;
    /* 0xA */ u16 padding4;
    /* 0xC */ u8 unkC;
    /* 0xD */ u8 padding5;
    /* 0xE */ s16 unkE;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
};

extern u8 sub_80023E4(u32);
extern u8 sub_80973F4(s16);
extern u8 sub_8097384(s16);
s16 sub_80A26B8(s16);
extern s16 gUnknown_8116F9A[];
extern s16 gUnknown_8116F24[];
extern struct unkStruct_80A2608 gUnknown_81168A8[];

struct unkStruct_80A2608 *sub_80A2608(s16 r0)
{
    return &gUnknown_81168A8[r0];
}

struct unkStruct_80A2608 *sub_80A2620(s16 r0)
{
    u32 temp;
    temp = sub_80A26B8(r0);
    return &gUnknown_81168A8[temp];
}

s16 sub_80A2644(u32 r0)
{
    return gUnknown_8116F24[r0];
}

s16 sub_80A2654(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    temp = sub_80A2608(r0);
    return temp->unkE;
}

// This is very ugly
s32 sub_80A2668(u32 r0)
{
    u32 temp;
    temp = 0xffc90000 + (r0 << 16);
    if(temp >> 16 < 0x19)
    {
        return ((s32)temp >> 16);
    }
    else
    {
        return -1;
    }
}

u32 sub_80A2688(u8 r0)
{
  u32 uVar1;
  
  uVar1 = r0 - 0x4B;

  // u8 cast is needed for only this compare
  if ((u8)uVar1 < 0x17)
      return uVar1;
  else if(r0 == 0x2F)
    return 0x17;
  else if (r0 == 0x30)
    return 0x18;
  else
    return -1;
}

s16 sub_80A26B8(s16 r0)
{
    // Useless cast that forces correct ordering
    s32 temp;
    temp = r0;

    return gUnknown_8116F9A[r0];
}

s16 sub_80A26CC(s16 r0)
{
    return (0xDC >> 2) + r0;
}


s32 sub_80A26D8(u8 r0)
{
    s32 counter;
    s32 counter2;
    s32 temp2;
    struct unkStruct_80A2608 *temp;
    for(counter = 0; counter <= 0x52; counter++)
    {
        temp2 = counter <<  0x10;
        counter2 = temp2 >> 0x10;
        temp = sub_80A2608(counter2);
        if(temp->unk11 != 0)
        {
            if(temp->unkC == r0)
            {
                return counter2;
            }
        }
    }
    return -1;
}

u8 sub_80A270C(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s32 temp_number;

    temp_number = r0; // forcing a shift before addressing
    temp = sub_80A2608(gUnknown_8116F9A[temp_number]);
    return temp->unkC;
}

u8 sub_80A2728(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s16 temp_number = (0xDC >> 2) + r0;
    temp = sub_80A2608(temp_number);
    return temp->unkC;
}

u8 sub_80A2740(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    temp = sub_80A2608(r0);
    return temp->unkC;
}

s16 sub_80A2750(s16 r0)
{
    struct unkStruct_80A2608 *temp;
    s32 temp_32;
    s32 temp_2;

    // so dumb but it matches
    temp_32 = r0;
    temp_2 = temp_32;

    if(r0 == 0x50)
        return 3;
    if(r0 == 0x51)
        return 2;
    if(r0 == 0x52)
        return 4;
    if((u16)(r0 - 0x28) <= 0xE)
        return 2;
    if((u16)(r0 - 0x37) <= 0x18)
        return 4;

    temp = sub_80A2608(temp_2);
    if(temp->unkE == -1)
        return 1;
    if(sub_80023E4(5) != 0)
        return 1;
    if(sub_80973F4(temp->unkE) == 0)
        return 1;
    if(sub_80023E4(1) == 0)
        return 1;
    return 2;
}

u8 sub_80A27CC(s16 r0)
{
    s32 temp;
    s32 temp2;
    struct unkStruct_80A2608 *return_var;

    // Same dumbness as above to get a match
    temp2 = r0;
    temp = temp2;

    return_var = sub_80A2620(r0);
    if(return_var->unk0 == -1)
        return 0;
    if(sub_80023E4(5) != 0)
        return 0;
    if(sub_8097384(r0) != 0)
        return 1;
    if(sub_80023E4(1) == 0)
        return 0;
    if(sub_80973F4(temp) == 0)
        return 0;
    return 1;
}

u8 sub_80A2824(u8 r0)
{
    s32 counter;
    struct unkStruct_80A2608 *temp;

    if(sub_80023E4(5) != 0)
        return 0;
    if(sub_80023E4(1) != 0)
    {
        for(counter = 0; counter <= 0x2D; counter++)
        {
            temp = sub_80A2620(counter);
            if(temp->unk11 != 0)
            {
                if(temp->unkC == r0)
                {
                    if(sub_8097384(counter) != 0)
                        return 1;
                    if(sub_80973F4(counter) != 0)
                        return 1;
                }
            }
        }
    }
    else
    {
        for(counter = 0; counter <= 0x2D; counter++)
        {
            temp = sub_80A2620(counter);
            if(temp->unk11 != 0)
                if(temp->unkC == r0)
                    if(sub_8097384(counter) != 0)
                        return 1;
        }
    }
    return 0;

}

u32 sub_80A28B4(s16 r0)
{
    struct unkStruct_80A2608 *temp;

    temp = sub_80A2620(r0);
    if(temp->unk0 != -1)
    {
        if(sub_8097384(r0) == 0 && sub_80973F4(r0) == 0)
            return 0;
        else
            return 1;
    }
    return 0;
}

u32 sub_80A28F0(u8 r0)
{
    s32 counter;
    struct unkStruct_80A2608 *temp;

    for(counter = 0; counter < 0x2E; counter++)
    {
        temp = sub_80A2620(counter);
        if(temp->unk11 != 0)
        {
            if(temp->unkC == r0)
            {
                if(sub_8097384(counter) != 0)
                    return 1;
                if(sub_80973F4(counter) != 0)
                    return 1;
            }
        }
    }
    return 0;
}
