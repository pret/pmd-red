#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"

struct unkStruct_203B2F8
{
    // size: 0x208
    s32 state; // state
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
    u8 fill78[0x118 - 0x78];
    u32 unk118;
    u8 fill11C[0x158 - 0x11C];
    u32 unk158;
    u8 fill15C[0x198 - 0x15C];
    u16 unk198[8];
    struct UnkTextStruct2 unk1A8[4];
    u32 unk1E4;
};
extern struct unkStruct_203B2F8 *gUnknown_203B2F8;
extern struct UnkTextStruct2 gUnknown_80DFE04;
extern struct UnkTextStruct2 gUnknown_80DFE1C;
extern struct UnkTextStruct2 gUnknown_80DFDD4;
extern void sub_8012CAC(struct UnkTextStruct2 *, u32 *);
extern void sub_802D63C(void);
extern void sub_802D5A4(void);

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
  switch(gUnknown_203B2F8->state) {
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
    gUnknown_203B2F8->state = newState;
    sub_802D1B8();
    sub_802D2A8();
}

void sub_802D1B8(void)
{
    s32 iVar2;
    sub_8006518(gUnknown_203B2F8->unk1A8);
    switch(gUnknown_203B2F8->state)
    {
        case 0xD:
           sub_802D5A4();
           gUnknown_203B2F8->unk1A8[2] = gUnknown_80DFE04;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[2], &gUnknown_203B2F8->unk118);
           gUnknown_203B2F8->unk1A8[2].unk0c = 6;
           break;
        case 0xE:
           sub_802D63C();
           gUnknown_203B2F8->unk1A8[3] = gUnknown_80DFE1C;
           sub_8012CAC(&gUnknown_203B2F8->unk1A8[3], &gUnknown_203B2F8->unk158);
           gUnknown_203B2F8->unk1A8[3].unk0c = 6;
           break;
        default:
           for(iVar2 = 0; iVar2 < 4; iVar2++)
           {
               gUnknown_203B2F8->unk1A8[iVar2] = gUnknown_80DFDD4;
           }
           break;
        case 2:
           break;
    }
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B2F8->unk1A8, 1, 1);
}
