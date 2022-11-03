#include "global.h"
#include "code_80A26CC.h"

extern u8 sub_80023E4(u32);
extern u8 sub_80973F4(s16);
extern u8 sub_8097384(s16);
s16 sub_80A26B8(s16);
extern struct unkStruct_80A2608 gUnknown_81168A8[];
extern u8 sub_8098F88(void);
extern u32 sub_8001658(u32, u32);

extern s16 gUnknown_8116F9A[];
extern s16 gUnknown_8116F24[];
extern const u8 *gUnknown_8117000[];

extern void sub_809AC18(s32, s32);
extern void sub_809ABB4(s32, s32);

void sub_80A2584(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809ABB4(iVar1, iVar2);
}

void sub_80A2598(s16 r0, s16 r1)
{
    s32 iVar2 = r1;
    s32 iVar1 = r0;
    sub_809AC18(iVar1, iVar2);
}

u32 sub_80A25AC(u16 param_1)
{
  if (sub_8098F88() != 0) {
      return param_1;
  }
  else
  {
    if (param_1 == 0x32) {
        return 0x32;
    }
    else if (sub_80023E4(0xc) == 0) {
        return 999;
    }
    else if (sub_80023E4(0xd) != 0) {
        return 0x13;
    }
    else if (param_1 != 1) {
        return param_1;
    }
    else
    {
        sub_8001658(0,0x28);
        return 1;
    }
  }
}

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

u8 sub_80A2740(s32 r0)
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

s32 sub_80A293C(u8 *param_1)
{
  u8 *pcVar2;
  struct unkStruct_80A2608 * iVar3;
  s32 index;
  s32 counter;
  u8 local_68 [0x40];
  u8 zero;

  counter = 0;
  zero = 0;

  pcVar2 = &local_68[0x3e];
  do {
    *pcVar2 = zero;
    pcVar2--;
  } while ((int)pcVar2 >= (int)local_68);


    for(index = 0; index < 0x2E; index++)
    {
      iVar3 = sub_80A2620(index);
      if ((iVar3->unk11 != 0) &&
         (sub_8097384(index) != 0)) {
        local_68[iVar3->unkC] = 1;
      }
    }

  for(index = 0; index < 0x3F; index++)
  {
    if (local_68[index] != 0) {
      param_1[counter] = index;
      counter++;
    }
  }
  return counter;
}

s32 sub_80A29B0(u8 *param_1)
{
  u8 *pcVar2;
  struct unkStruct_80A2608 * iVar3;
  s32 index;
  s32 counter;
  u8 *local1;
  u8 *local2;
  u8 *local3;
  u8 *local4;
  u8 local_68 [0x40];
  u8 zero;

  counter = 0;
  local1 = &local_68[0x2B];
  local2 = &local_68[0x2C];
  local3 = &local_68[0x2D];
  local4 = &local_68[0x2E];
  zero = 0;

  pcVar2 = &local_68[0x3e];
  do {
    *pcVar2 = zero;
    pcVar2 = pcVar2 + -1;
  } while ((int)pcVar2 >= (int)local_68);


  if (sub_80023E4(1) != 0) {
    for(index = 0; index < 0x2E; index++)
    {
      iVar3 = sub_80A2620(index);
      if ((iVar3->unk11 != 0) &&
         (sub_80973F4(index) != 0)) {
        local_68[iVar3->unkC] = 1;
      }
    }
  }
  *local1 = 0;
  *local2 = 0;
  *local3 = 0;
  *local4 = 0;

  for(index = 0; index < 0x3F; index++)
  {
    if (local_68[index] != 0) {
      param_1[counter] = index;
      counter++;
    }
  }
  return counter;
}

s32 sub_80A2A5C(u8 *param_1)
{
  u8 *pcVar2;
  struct unkStruct_80A2608 *iVar3;
  s32 index;
  s32 counter;
  u8 local_58 [0x40];
  u8 zero;

  counter = 0;
  zero = 0;
  
  pcVar2 = &local_58[0x3E];
  do {
    *pcVar2 = zero;
    pcVar2--;
  } while ((s32)pcVar2 >= (s32)local_58);

  if (sub_80023E4(1) != 0) {
    for(index = 0; index < 0x2E; index++)
    {
      iVar3 = sub_80A2620(index);
      if ((iVar3->unk11 != 0) && ((sub_8097384(index) != 0) || (sub_80973F4(index) != 0)))
      {
        local_58[iVar3->unkC] = 1;
      }
    }
  }
  else {
    for(index = 0; index < 0x2E; index++)
    {
      iVar3 = sub_80A2620(index);
      if ((iVar3->unk11 != 0) && (sub_8097384(index) != 0)) 
      {
        local_58[iVar3->unkC] = 1;
      }
    }
  }
  for(index = 0; index < 0x3F; index++)
  {
    if (local_58[index] != 0) {
      param_1[counter] = index;
      counter++;
    }
  }
  return counter;
}

// Returns Location string for the pause menu
const u8 *sub_80A2B18(s16 param_1)
{
    s32 param_1_s32 = param_1;
    const u8 **preload = gUnknown_8117000;
    return preload[param_1_s32];
}

const u8 *sub_80A2B28(u16 r0)
{
    return sub_80A2B18(sub_8001658(0, 17));
}

