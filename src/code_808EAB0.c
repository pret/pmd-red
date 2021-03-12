#include "global.h"

extern u32 gIQSkillNames[];
extern u32 gIQSkillDescriptions[];
extern u32 gTacticsDescriptions[];
extern u8 *gTactics[];
extern u8 gUnknown_810A36B[];

extern s16 gUnknown_810A378[];
extern s32 gUnknown_810A390[];
extern u32 gUnknown_81076E4[];

extern bool8 sub_808ECD0(u8 *, u32);
extern void sub_808EC30(u8 *, u32);

u32 sub_808EAB0(u8 r0)
{
    return gIQSkillNames[r0];
}

void sub_808EAC0(char *r0, u8 r1)
{
    strncpy(r0, gTactics[r1], 0x14);
}

u32 sub_808EADC(u8 r0)
{
    return gIQSkillDescriptions[r0];
}

u32 sub_808EAEC(u8 r0)
{
    return gTacticsDescriptions[r0];
}

u8 sub_808EAFC(u8 r0)
{
    return gUnknown_810A36B[r0];
}

void sub_808EB0C(u8 *r0, s32 r1)
{
    s32 counter;
    s32 storage;
    u32 index;
    storage = 0;
    index = 0;
    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[index] <= r1)
        {
            r0[storage] = counter;
            storage++;
        }
        index++;
    }
    if(storage > 0xB)
    {
        return;
    }
    while(storage <= 0xB)
    {
        r0[storage] = 0xB;
        storage++;
    }
}

void sub_808EB48(u8 *r0, s32 r1)
{
    s32 counter;

    for(counter = 0; counter <= 0xB; counter++)
    {
        if(gUnknown_810A378[counter] <= r1)
        {
            r0[counter] = TRUE;
        }
        else
        {
            r0[counter] = FALSE;
        }
    }
}

bool8 sub_808EB7C(s32 r0, u8 r1)
{
    if(r1 == 0)
    {
        return FALSE;
    }

    return gUnknown_810A390[r1] <= r0;
}

s32 sub_808EBA8(u8 param_1[], s32 param_2)
{
  s32 counter_2;
  s32 counter_1;
  u8 cast_u8;
  s32 index;
  
  index = 0;

  for(counter_1 = 1; counter_1 < 0x18; counter_1++) {
    cast_u8 = counter_1; // force this cast to be in a reg
    if (sub_808EB7C(param_2, cast_u8)) {
      param_1[index] = cast_u8;
      index++;
    }
  }

  counter_2 = index; // set counter to where the first loop ended

  while (counter_2 < 0x18) {
    param_1[counter_2] = 0;
    counter_2++;
  }
  return index;
}

void sub_808EBF4(u8 *param_1, u32 param_2)
{
  int iVar2; // a mask?

  iVar2 = 1 << (param_2);
  if (sub_808ECD0(param_1,iVar2)) {
    param_1[0] = param_1[0] & ~iVar2;
    param_1[1] = param_1[1] & ~(iVar2 >> 8);
    param_1[2] = param_1[2] & ~(iVar2 >> 0x10);
  }
  else
  {
    sub_808EC30(param_1,param_2);
  }
}

void sub_808EC30(u8 *param_1, u32 param_2)
{
  s32 iVar1;
  s32 counter;
  s32 iVar4;
  s32 iVar5;

  counter = 0;
  iVar4 = gUnknown_81076E4[param_2];
  do {
    if (iVar4 == gUnknown_81076E4[counter]) {
      iVar1 = 1 << (counter);
      param_1[0] = param_1[0] & ~iVar1;
      param_1[1] = param_1[1] & ~(iVar1 >> 8);
      param_1[2] = param_1[2] & ~(iVar1 >> 0x10);
    }
    counter++;
  } while (counter < 0x18);

  iVar5 = 1 << (param_2);
  param_1[0] = iVar5           | param_1[0];
  param_1[1] = (iVar5 >> 8)    | param_1[1];
  param_1[2] = (iVar5 >> 0x10) | param_1[2];
}

void sub_808EC94(u8 *param_1, u8 param_2)
{

  param_1[0] = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  sub_808EC30(param_1, 2);
  sub_808EC30(param_1, 3);
  sub_808EC30(param_1, 0x16);
  if (param_2 != 0) {
    sub_808EC30(param_1, 0x12);
  }
}

bool8 sub_808ECD0(u8 *param_1, u32 param_2)
{

  if ((((param_1[0] & param_2) == 0) && 
       ((param_1[1] & param_2 >> 8) == 0)) &&
       ((param_1[2] & param_2 >> 0x10) == 0)) 
  {
    return 0;
  }
  else {
    return 1;
  }
}

u32 sub_808ECFC(void)
{
    return 0;
}
