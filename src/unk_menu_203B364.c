#include "global.h"
#include "input.h"

struct unkData
{
    u8 unk0[14];
    u16 unkD;
    u16 unk10;
    u16 unk12;
    u8 *unk14;
};

struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4;
    u32 unk8;
    u8 fill8[0x148 - 0xC];
    struct unkData unk148[4];
    u16 unk1A8;
    u16 unk1AA;
    u16 unk1AC;
    u16 unk1AE;
    u32 unk1B0; // Sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B364;
extern struct unkData gUnknown_80E6F20;
extern u32 gUnknown_80E6F38;
extern u32 gUnknown_80E7090;
extern u32 gUnknown_80E6F50;

extern void *MemoryAlloc(u32, u32);
extern void MemoryFill8(u8 *, u8, u32);
extern void MemoryFree(void *);
extern void sub_8038440();
extern void sub_8035CF4(u32 *, u32, u32);
extern void sub_800641C(void *, u32, u32);
extern void SetMenuItems(void *, void *, u32, u32 *, u32 *, u32, u32, u32);
extern u8 sub_80130A8(u32 *);
extern void sub_8013114(u32 *, u32 *);
extern void sub_80384D0();
extern void sub_8038830();

void sub_803850C(s32 param_1)
{
  s32 iVar4;
  
  if (gUnknown_203B364 == NULL) {
    gUnknown_203B364 = MemoryAlloc(sizeof(struct unkStruct_203B360),8);
    MemoryFill8((u8 *)gUnknown_203B364,0,sizeof(struct unkStruct_203B360));
  }
  for(iVar4 = 0; iVar4 < 4; iVar4++){
    gUnknown_203B364->unk148[iVar4] = gUnknown_80E6F20;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B364->unk148,1,1);

  if (param_1 == 0x2e) {
      // Beware, Deleting your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,&gUnknown_80E7090,
                 0,6,0);
  }
  else {
      // Saving your Adventure
    SetMenuItems(&gUnknown_203B364->unk8,gUnknown_203B364->unk148,0,&gUnknown_80E6F38,&gUnknown_80E6F50,
                 0,6,0);
  }
  sub_8035CF4(&gUnknown_203B364->unk8,0,1);
  gUnknown_203B364->unk4 = 0;
  gUnknown_203B364->currMenu = param_1;
  sub_8038830();
}

void sub_8038604(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gUnknown_203B364 != 0) {
    MemoryFree(gUnknown_203B364);
    gUnknown_203B364 = 0;
  }
}

