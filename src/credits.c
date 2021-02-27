#include "global.h"
#include "input.h"

extern struct Inputs gRealInputs;

struct unkStruct_203B344
{
    u32 unk0; // state variable
    u32 unk4; // timer??
};

struct unkStruct_203B340
{
    // size: 0x84
    u32 unk0;
};

extern void MemoryFree(void *);
extern void* MemoryAlloc(u32, u32);
extern void sub_80015C0(u32, u32);

extern u16 gUnknown_80E5990[];
extern struct unkStruct_203B344 *gUnknown_203B344;
extern struct unkStruct_203B340 *gUnknown_203B340;
extern s32 sub_8001658(u32, u32);

void sub_803565C(void)
{
    if(gUnknown_203B340 != NULL)
    {
        MemoryFree(gUnknown_203B340);
        gUnknown_203B340 = NULL;
    }
}


u32 sub_8035678(void)
{
    gUnknown_203B344 = MemoryAlloc(sizeof(struct unkStruct_203B344), 8);
    gUnknown_203B344->unk0 = 0;
    gUnknown_203B344->unk4 = 0;
    sub_80015C0(0, 0x39);
    return 1;
}

u32 sub_80356A0(void)
{
  u16 uVar1;
  u16 held_input;

  held_input = gRealInputs.held;
  uVar1 = gUnknown_80E5990[gUnknown_203B344->unk4];

  switch(gUnknown_203B344->unk0) {
  case 0:
    gUnknown_203B344->unk0 = 3;
    break;
  case 1:
    if (uVar1 == 0)
      gUnknown_203B344->unk0 = 4;
    else {
      if (held_input == uVar1)
        gUnknown_203B344->unk0 = 2;
      else {
        // NOTE: couldn't match with OR'd condition so split up to match
        if ((uVar1 & held_input) != held_input)
            gUnknown_203B344->unk0 = 3;
        else
        {
            if (gUnknown_203B344->unk4 == 0)
                gUnknown_203B344->unk0 = 3;
        }
      }
    }
    break;
  case 2:
    if (held_input == 0) {
      gUnknown_203B344->unk0 = 1;
      gUnknown_203B344->unk4++;
    }
    else {
      if ((uVar1 & held_input) != held_input)
          gUnknown_203B344->unk0 = 3;
    }
    break;
  case 3:
    return 2;
  case 4:
    return 3; // sub_809C478 clears the flash data when this is returned
  }

  if (sub_8001658(0,0x39) != 0) {
    gUnknown_203B344->unk0 = 3;
    return 2;
  }
  else {
    return 0;
  }
}

void sub_8035758(void)
{
    if(gUnknown_203B344 != NULL)
    {
        MemoryFree(gUnknown_203B344);
        gUnknown_203B344 = NULL;
    }
}
