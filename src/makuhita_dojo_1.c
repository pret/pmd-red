#include "global.h"
#include "text.h"

struct unkStruct_203B31C
{
    // Size: 0xD0
    u16 unk0[2];
    u8 fill4[0x30 - 0x4];
    u32 unk30;
    u8 fill34[0x48 - 0x34];
    s16 unk48;
    s16 unk4A;
    s16 unk4C;
    s16 unk4E;
    u16 unk50;
    u16 unk52;
    u8 fill54[0x64 - 0x54];    
    u32 unk64;
    struct UnkTextStruct2 *unk68;
    struct UnkTextStruct2 unk6C[4];
    u8 unkCC[4];
};

extern struct unkStruct_203B31C *gUnknown_203B31C;


extern bool8 sub_8097504(s16);
extern s16 sub_80A26CC(s16 r0);


s32 sub_8030668(void)
{
  s32 index;
  s32 counter;
  
  counter = 0;

  for(index = 0; index < 0x17; index++)
  {
    if (sub_8097504(index)) {
      gUnknown_203B31C->unk0[counter] = sub_80A26CC(index);
      counter++;
    }
  }
  return counter;
}

s32 sub_80306A4(void)
{
    return 0;
}

