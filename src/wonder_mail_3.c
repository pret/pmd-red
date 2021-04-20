#include "global.h"

struct unkStruct_203B2F8
{
    // size: 0x208
    u32 unk0; // state
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 unkA;
    u8 unkB;
    u32 unkC;
    u8 fill10[0x6C - 0x10];
    u32 unk6C;
    u32 unk70;
    u32 unk74;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;

extern void *MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern u8 sub_8099328(u8 *);
extern u32 sub_8011C1C();
extern void sub_802D1A0(u32);

extern void sub_802D7D0();
extern void sub_802D8CC();
extern void sub_802D940();
extern void sub_802D9F0();
extern void sub_802DA60();
extern void sub_802D82C();
extern void sub_802DA84();
extern void sub_802D1B8();
extern void sub_802D2A8();


u32 sub_802D098(u32 param_1)
{
  gUnknown_203B2F8 = MemoryAlloc(0x208,8);
  gUnknown_203B2F8->unk6C = 0;
  gUnknown_203B2F8->unk70 = 0;
  gUnknown_203B2F8->unk74 = 0;
  gUnknown_203B2F8->unkC  = param_1;
  gUnknown_203B2F8->unk8 = 0;
  gUnknown_203B2F8->unk9 = sub_8099328(&gUnknown_203B2F8->unkA);
  if (sub_8011C1C() != 2) {
    gUnknown_203B2F8->unk9 = 0;
  }
  sub_802D1A0(0);
  return 1;
}

u32 sub_802D0E0(void)
{
  switch(gUnknown_203B2F8->unk0) {
    case 0:
        break;
    case 1:
        sub_802D7D0();
        break;
    case 0xb:
    case 0xc:
        sub_802D8CC();
        break;
    case 0xd:
        sub_802D940();
        break;
    case 0xe:
        sub_802D9F0();
        break;
    case 0xf:
    case 0x10:
        sub_802DA60();
        break;
    case 9:
        sub_802D82C();
        break;
    case 2:
        return 3;
    default:
        sub_802DA84();
        break;
  }
  return 0;
}

u8 sub_802D178(void)
{
    return gUnknown_203B2F8->unk8;
}

void sub_802D184(void)
{
    if(gUnknown_203B2F8 != NULL)
    {
        MemoryFree(gUnknown_203B2F8);
        gUnknown_203B2F8 = NULL;
    }
}

void sub_802D1A0(u32 newState)
{
    gUnknown_203B2F8->unk0 = newState;
    sub_802D1B8();
    sub_802D2A8();
}
