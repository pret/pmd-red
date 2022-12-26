#include "global.h"
#include "memory.h"
#include "text.h"
#include "input.h"

struct unkStruct_3001B5C
{
    // size: 0x3fC
    u8 unk0;
    u32 unk4;
    u32 unk8;
    s16 unkC[2];
    u32 unk10;
    u8 fill14[0x354 - 0x14];
    u8 unk354;
    u8 fill355[0x35C - 0x355];
    u8 unk35C;
    u8 fill35D[0x374 - 0x35D];
    s16 unk374;
    s16 unk376;
    s16 unk378;
    s16 unk37A;
    u8 fill37C[0x390 - 0x37C];
    u32 unk390;
    struct UnkTextStruct2 *unk394;
    struct UnkTextStruct2 unk398[4];
    u8 unk3F8[4];
};

extern struct unkStruct_3001B5C *gUnknown_3001B5C;

extern u32 gUnknown_203B298;
extern u16 gUnknown_203B29C;
extern u16 gUnknown_203B29E;
extern struct UnkTextStruct2 gUnknown_80DC91C;
extern struct UnkTextStruct2 gUnknown_80DC904;

extern u8 sub_8023704();
extern void sub_8012D08(void *, u32);
extern void sub_8013818(void *, u32, u32, u32);
extern void sub_8013984(u8 *);
extern void sub_8023420(void);
extern void sub_80234BC(void);
extern u32 sub_80236A4(void);
extern u8 sub_80138B8(void *, u32);
extern void PlayMenuSoundEffect(u32);
extern s32 GetKeyPress(void *);
extern void sub_8013660(void *);
extern void AddMenuCursorSprite(void *);

bool8 sub_8023144(s32 param_1, s32 index, struct UnkTextStruct2_sub *sub, u32 param_4)
{
  u8 param_1_u8 = param_1;

  if (sub_8023704(param_1_u8)) {
    return 0;
  }
  if (gUnknown_3001B5C == NULL) {
    gUnknown_3001B5C = MemoryAlloc(sizeof(struct unkStruct_3001B5C), 8);
  }
  gUnknown_3001B5C->unk0 = param_1_u8;
  gUnknown_3001B5C->unk4 = gUnknown_203B298;

  gUnknown_3001B5C->unk390 = index;
  gUnknown_3001B5C->unk394 = &gUnknown_3001B5C->unk398[index];
  sub_8006518(gUnknown_3001B5C->unk398);
  gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC91C;

  gUnknown_3001B5C->unk394->unk14 = gUnknown_3001B5C->unk3F8;
  if (sub != NULL) {
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390].unk08 = *sub;
  }
  sub_8012D08(gUnknown_3001B5C->unk394,param_4);
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,1,1);
  sub_8013818(&gUnknown_3001B5C->unk35C,sub_80236A4(),param_4,index);
  gUnknown_3001B5C->unk374 = gUnknown_203B29C;
  gUnknown_3001B5C->unk37A = gUnknown_203B29E;
  sub_8013984(&gUnknown_3001B5C->unk35C);
  sub_8023420();
  sub_80234BC();
  return 1;
}


u8 sub_8023278(u8 param_1)
{
  s32 iVar3;
  u32 temp;
  
  if (param_1 == 0) {
    sub_8013660(&gUnknown_3001B5C->unk35C);
    return 0;
  }
  switch(GetKeyPress(&gUnknown_3001B5C->unk35C))
  {
    case 2:
        PlayMenuSoundEffect(1);
        return 2;
    case 1:
      PlayMenuSoundEffect(0);
      return 3;
    case 3:
        PlayMenuSoundEffect(5);
        if (temp = gUnknown_3001B5C->unk4, iVar3 = 1, temp < 2) {
            iVar3 = temp + 1;
        }
        gUnknown_3001B5C->unk4 = iVar3;
        sub_80236A4();
        break;
    default:
        if (sub_80138B8(&gUnknown_3001B5C->unk35C, 1) == 0) {
            return 0;
        }
        break;
  }
  sub_8023420();
  sub_80234BC();
  return 1;
}

s16 sub_802331C(void)
{
  return gUnknown_3001B5C->unkC[gUnknown_3001B5C->unk37A * gUnknown_3001B5C->unk378 + gUnknown_3001B5C->unk374];
}

void sub_8023354(u8 param_1)
{
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_3001B5C->unk398,0,0);
  sub_8013984(&gUnknown_3001B5C->unk35C);
  sub_8023420();
  sub_80234BC();
  if (param_1 != 0) {
    AddMenuCursorSprite(&gUnknown_3001B5C->unk35C);
  }
}


void sub_80233A0(void)
{
  if (gUnknown_3001B5C != NULL) {
    gUnknown_203B298 = gUnknown_3001B5C->unk4;
    gUnknown_203B29C = gUnknown_3001B5C->unk374;
    gUnknown_203B29E = gUnknown_3001B5C->unk37A;
    gUnknown_3001B5C->unk398[gUnknown_3001B5C->unk390] = gUnknown_80DC904;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_3001B5C->unk398,1,1);
    MemoryFree(gUnknown_3001B5C);
    gUnknown_3001B5C = NULL;
  }
}
