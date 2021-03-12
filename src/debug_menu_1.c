#include "global.h"

struct subStruct
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
};

struct unkStruct_203B3F8
{
    u8 fill0[8];
    struct subStruct *unk8;
    u8 fill4[4];
    u32 unk10;
    u8 fill14[0x60 - 0x14];
    u32 unk60;
};
extern struct unkStruct_203B3F8 *gUnknown_203B3F8;
extern u32 sub_8013BBC(u32 *);
extern void sub_8023A94(u32);
extern u8 sub_8012FD8(u32 *);
extern void sub_803AE58(void);
extern u32 sub_8016080(void);
extern void sub_803ACD0(u32);
extern void sub_80160D8(void);
extern void sub_8013114(u32 *, s32 *);

void sub_803AF88(void)
{
  s32 local_c;
  
  local_c = 0;
  sub_8023A94(local_c);
  if (sub_8012FD8(&gUnknown_203B3F8->unk10) == 0) {
    sub_8013114(&gUnknown_203B3F8->unk10, &local_c);
  }
  switch(local_c)
  {
      case 4:
        sub_803ACD0(5);
        break;
      case 5:
        sub_803ACD0(6);
        break;
      case 1:
        sub_803ACD0(2);
        break;
      default:
        break;
  }
}

void sub_803AFE8(void)
{
  sub_8023A94(0);
  sub_8012FD8(&gUnknown_203B3F8->unk10);
  switch(sub_8013BBC(&gUnknown_203B3F8->unk60))
  {
      default:
        break;
      case 3:
        gUnknown_203B3F8->unk8->unk3 = gUnknown_203B3F8->unk60;
        // Fallthrough is needed to match
      case 2:
        sub_803ACD0(2);
        break;
      case 1:
        sub_803AE58();
        break;
  }
}

void sub_803B034(void)
{
    switch(sub_8016080())
    {
        case 2:
        case 3:
            sub_80160D8();
            sub_803ACD0(2);
            break;
    }
}
