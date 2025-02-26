#include "global.h"
#include "globaldata.h"
#include "constants/main_menu.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "sprite.h"
#include "text.h"
#include "unk_menu_203B360.h"

// Size: 0x1B4. Similar to SaveMenuWork
typedef struct unkStruct_203B360
{
    /* 0x0 */ u32 currMenu;
    u32 unk4; // state
    MenuStruct unk8[4];
    Windows unk148;
    SpriteOAM unk1A8;
    u32 unk1B0; // sprite count?
} unkStruct_203B360;

static EWRAM_INIT unkStruct_203B360 *sUnknown_203B360 = {NULL};

const Window gUnknown_80E6E7C = {
   0,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const Window gUnknown_80E6E94 = {
   0,
   0x03,
   0x05, 0x09,
   0x13, 0x05,
   0x05, 0x00,
   NULL
};

const u8 CheckAgain_80E6ECC[];
const u8 StorageEmpty_80E6EE4[];
const u8 Caution_80E6F04[];

const MenuItem gUnknown_80E6EAC[4] = {
    {Caution_80E6F04, 0x3},
    {StorageEmpty_80E6EE4, 0x3},
    {CheckAgain_80E6ECC, 0x3},
    {NULL, 1}
};

ALIGNED(4) const u8 CheckAgain_80E6ECC[] = _("{CENTER_ALIGN}Please check again.");
ALIGNED(4) const u8 StorageEmpty_80E6EE4[] = _("{CENTER_ALIGN}The storage space is empty!");
ALIGNED(4) const u8 Caution_80E6F04[] = _("{CENTER_ALIGN}{COLOR RED}Caution!{RESET} ");
static const u8 fill0[] = "pksdir0";

extern void sub_8038440();
extern void sub_80384D0();

void sub_80382E4(s32 currMenu)
{
  s32 index;

  if (sUnknown_203B360 == NULL) {
    sUnknown_203B360 = MemoryAlloc(sizeof(unkStruct_203B360), 8);
    MemoryFill8(sUnknown_203B360, 0, sizeof(unkStruct_203B360));
  }
  for(index = 0; index < 4; index++){
    sUnknown_203B360->unk148.id[index] = gUnknown_80E6E7C;
  }
  ResetUnusedInputStruct();
  ShowWindows(&sUnknown_203B360->unk148, TRUE, TRUE);
  if (currMenu == 0x25) {
      // Caution!
      // The storage space is empty!
      // Please check again.
    SetMenuItems(sUnknown_203B360->unk8,&sUnknown_203B360->unk148,0,&gUnknown_80E6E94,gUnknown_80E6EAC,
                 FALSE,4,FALSE);
  }
  sub_8035CF4(sUnknown_203B360->unk8,0,TRUE);
  sUnknown_203B360->currMenu = currMenu;
  sUnknown_203B360->unk4 = 0;
  sub_8038440();
}

void sub_80383A8(void)
{
  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  if (sUnknown_203B360 != 0) {
    MemoryFree(sUnknown_203B360);
    sUnknown_203B360 = 0;
  }
}

u32 sub_80383D4(void)
{
  u32 nextMenu;
  u32 menuAction;

  menuAction = 2;
  nextMenu = MENU_NO_SCREEN_CHANGE;

  if (sUnknown_203B360->unk4 == 0){
    if (sub_80130A8(&sUnknown_203B360->unk8[0]) == '\0') {
        sub_8013114(&sUnknown_203B360->unk8[0], &menuAction);
    }
    switch(menuAction)
    {
        case 3:
        case 1:
            sUnknown_203B360->unk4  = 0;
            nextMenu = MENU_MAIN_SCREEN;
            break;
        case 2:
            sUnknown_203B360->unk4  = 0;
        default:
            break;
    }
    sub_80384D0();
  }

  return nextMenu;
}

void sub_8038440(void)
{
    SpriteSetAffine1(&sUnknown_203B360->unk1A8, 0);
    SpriteSetAffine2(&sUnknown_203B360->unk1A8, 0);
    SpriteSetObjMode(&sUnknown_203B360->unk1A8, 0);
    SpriteSetMosaic(&sUnknown_203B360->unk1A8, 0);
    SpriteSetBpp(&sUnknown_203B360->unk1A8, 0);
    SpriteSetShape(&sUnknown_203B360->unk1A8, 1);

    SpriteSetTileNum(&sUnknown_203B360->unk1A8, 0x3F0);
    SpriteSetPriority(&sUnknown_203B360->unk1A8, 0);
    SpriteSetPalNum(&sUnknown_203B360->unk1A8, 15);

    SpriteSetMatrixNum(&sUnknown_203B360->unk1A8, 0);
    SpriteSetSize(&sUnknown_203B360->unk1A8, 0);

    SpriteSetX(&sUnknown_203B360->unk1A8, 112);
    SpriteSetY(&sUnknown_203B360->unk1A8, 112);

    sUnknown_203B360->unk1B0 = 0;
}

void sub_80384D0(void)
{
  if ((sUnknown_203B360->unk1B0 & 8) != 0) {
    AddSprite(&sUnknown_203B360->unk1A8, 0x100, NULL, NULL);
  }
  sUnknown_203B360->unk1B0++;
}

