#include "global.h"
#include "input.h"
#include "main_menu.h"
#include "memory.h"
#include "menu.h"
#include "text1.h"
#include "menu_input.h"
#include "sprite.h"

// Similar to RescuePasswordMenu
struct unkStruct_203B360
{
    // size: 0x1b4
    u32 currMenu;
    u32 unk4; // state
    struct MenuStruct unk8[4];
    struct UnkTextStruct2 unk148[4];
    struct unkSprite unk1A8;
    u32 unk1B0; // sprite count?
};

EWRAM_DATA_2 struct unkStruct_203B360 *gUnknown_203B360 = {0};
const struct UnkTextStruct2 gUnknown_80E6E7C = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E6E94 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x05, 0x09,
   0x13, 0x05,
   0x05, 0x00,
   NULL
};

const u8 CheckAgain_80E6ECC[];
const u8 StorageEmpty_80E6EE4[];
const u8 Caution_80E6F04[];

const struct MenuItem gUnknown_80E6EAC[4] = {
    {Caution_80E6F04, 0x3},
    {StorageEmpty_80E6EE4, 0x3},
    {CheckAgain_80E6ECC, 0x3},
    {NULL, 1}
};

ALIGNED(4) const u8 CheckAgain_80E6ECC[] = _("{CENTER_ALIGN}Please check again.");
ALIGNED(4) const u8 StorageEmpty_80E6EE4[] = _("{CENTER_ALIGN}The storage space is empty!");
ALIGNED(4) const u8 Caution_80E6F04[] = _("{CENTER_ALIGN}{COLOR_1 RED}Caution!{END_COLOR_TEXT_1} ");
static const u8 fill0[] = "pksdir0";

extern void sub_8038440();
extern void sub_80384D0();

void sub_80382E4(s32 currMenu)
{
  s32 index;
  
  if (gUnknown_203B360 == NULL) {
    gUnknown_203B360 = MemoryAlloc(sizeof(struct unkStruct_203B360), 8);
    MemoryFill8((u8 *)gUnknown_203B360, 0, sizeof(struct unkStruct_203B360));
  }
  for(index = 0; index < 4; index++){
    gUnknown_203B360->unk148[index] = gUnknown_80E6E7C;
  } 
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B360->unk148,1,1);
  if (currMenu == 0x25) {
      // Caution!
      // The storage space is empty!
      // Please check again.
    SetMenuItems(gUnknown_203B360->unk8,gUnknown_203B360->unk148,0,&gUnknown_80E6E94,gUnknown_80E6EAC,
                 0,4,0);
  }
  sub_8035CF4(gUnknown_203B360->unk8,0,TRUE);
  gUnknown_203B360->currMenu = currMenu;
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
    if (sub_80130A8(&gUnknown_203B360->unk8[0]) == '\0') {
        sub_8013114(&gUnknown_203B360->unk8[0], &menuAction);
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

void sub_8038440(void)
{
#ifdef NONMATCHING
    u32 r0;
    u32 r2;
#else
    register u32 r0 asm("r0");
    register u32 r2 asm("r2");
#endif
    u32 r1;
    u32 r4;
    u32 r5;
    struct unkSprite *sprite;
    
    r5 = 0;
    sprite = &gUnknown_203B360->unk1A8;

    r1 = sprite->unk0;
    r0 = 0xfeff;
    r0 &= r1;
    r0 &= 0xfdff;
    r0 &= 0xf3ff;
    r0 &= 0xefff;
    r0 &= 0xdfff;
    r2 = 0x4000;
    r0 &= 0x3fff;
    r0 |= r2;
    sprite->unk0 = r0;

    r2 = 0x3F0;
    r1 = sprite->unk4;
    r0 = 0xFC00;
    r0 &= r1;
    r0 |= r2;
    r0 &= 0xf3ff;
    r2 = 0xF;
    r4 = 0xF000;
    r0 &= 0xfff;
    r0 |= r4;

    sprite->unk4 = r0;
    
    sprite->unk2 = 0x70;
    
    r1 = 0x700;
    r2 &= sprite->unk6;
    r2 |= r1;
    sprite->unk6 = r2;
    
    gUnknown_203B360->unk1B0 = r5;
}


void sub_80384D0(void)
{
  if ((gUnknown_203B360->unk1B0 & 8) != 0) {
    AddSprite(&gUnknown_203B360->unk1A8, 0x100, NULL, NULL);
  }
  gUnknown_203B360->unk1B0++;
}

