#include "global.h"
#include "input.h"
#include "main_menu.h"

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
    u32 unk4; // state
    u32 unk8;
    u8 fill8[0x148 - 0xC];
    struct unkData unk148[4];
    u32 unk1A8;
    u32 unk1AC;
    u32 unk1B0; // sprite count?
};

extern struct unkStruct_203B360 *gUnknown_203B360;
extern struct unkData gUnknown_80E6E7C;
extern u32 gUnknown_80E6E94;
extern u32 gUnknown_80E6EAC;

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

void sub_80382E4(s32 param_1)
{
  s32 iVar4;
  
  if (gUnknown_203B360 == NULL) {
    gUnknown_203B360 = MemoryAlloc(sizeof(struct unkStruct_203B360), 8);
    MemoryFill8((u8 *)gUnknown_203B360, 0, sizeof(struct unkStruct_203B360));
  }
  for(iVar4 = 0; iVar4 < 4; iVar4++){
    gUnknown_203B360->unk148[iVar4] = gUnknown_80E6E7C;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B360->unk148,1,1);
  if (param_1 == 0x25) {
    SetMenuItems(&gUnknown_203B360->unk8,gUnknown_203B360->unk148,0,&gUnknown_80E6E94,&gUnknown_80E6EAC,
                 0,4,0);
  }
  sub_8035CF4(&gUnknown_203B360->unk8,0,1);
  gUnknown_203B360->currMenu = param_1;
  gUnknown_203B360->unk4 = 0;
  sub_8038440();
}

void sub_80383A8(void)
{
  ResetUnusedInputStruct();
  sub_800641C(0,1,1);
  if (gUnknown_203B360 != 0) {
    MemoryFree(gUnknown_203B360);
    gUnknown_203B360 = 0;
  }
}

u32 sub_80383D4(void)
{
  u32 nextMenu;
  u32 menuAction;
  
  menuAction = 2;
  nextMenu = MENU_NO_SCREEN_CHANGE;

  if (gUnknown_203B360->unk4 == 0){
    if (sub_80130A8(&gUnknown_203B360->unk8) == '\0') {
        sub_8013114(&gUnknown_203B360->unk8, &menuAction);
    }
    switch(menuAction)
    {
        case 3:
        case 1:
            gUnknown_203B360->unk4  = 0;
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 2:
            gUnknown_203B360->unk4  = 0;
        default:
            break;
    }
    sub_80384D0();
  }

  return nextMenu;
}
