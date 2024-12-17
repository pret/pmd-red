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
    UnkTextStruct2 unk148[4];
    SpriteOAM unk1A8;
    u32 unk1B0; // sprite count?
} unkStruct_203B360;

static EWRAM_INIT unkStruct_203B360 *sUnknown_203B360 = {NULL};

const UnkTextStruct2 gUnknown_80E6E7C = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const UnkTextStruct2 gUnknown_80E6E94 = {
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
    sUnknown_203B360->unk148[index] = gUnknown_80E6E7C;
  }
  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(sUnknown_203B360->unk148, TRUE, TRUE);
  if (currMenu == 0x25) {
      // Caution!
      // The storage space is empty!
      // Please check again.
    SetMenuItems(sUnknown_203B360->unk8,sUnknown_203B360->unk148,0,&gUnknown_80E6E94,gUnknown_80E6EAC,
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
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
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
#ifdef NONMATCHING // SpriteOAM memes
    u32 r0;
    u32 r2;
#else
    register u32 r0 asm("r0");
    register u32 r2 asm("r2");
#endif
    u32 r1;
    u32 r4;
    u32 r5;
    SpriteOAM *sprite;

    r5 = 0;
    sprite = &sUnknown_203B360->unk1A8;

    r1 = sprite->attrib1;
    r0 = (u16)~SPRITEOAM_MASK_AFFINEMODE1;
    r0 &= r1;

    r0 &= (u16)~SPRITEOAM_MASK_AFFINEMODE2;

    r0 &= (u16)~SPRITEOAM_MASK_OBJMODE;

    r0 &= (u16)~SPRITEOAM_MASK_MOSAIC;

    r0 &= (u16)~SPRITEOAM_MASK_BPP;

    r2 = 1 << SPRITEOAM_SHIFT_SHAPE;
    r0 &= (u16)~SPRITEOAM_MASK_SHAPE;
    r0 |= r2;

    sprite->attrib1 = r0;

    r2 = 0x3F0 << SPRITEOAM_SHIFT_TILENUM;
    r1 = sprite->attrib3;
    r0 = (u16)~SPRITEOAM_MASK_TILENUM;
    r0 &= r1;
    r0 |= r2;

    r0 &= (u16)~SPRITEOAM_MASK_PRIORITY;

    r2 = (u16)~SPRITEOAM_MASK_UNK6_4;

    r4 = 15 << SPRITEOAM_SHIFT_PALETTENUM;
    r0 &= (u16)~SPRITEOAM_MASK_PALETTENUM;
    r0 |= r4;

    sprite->attrib3 = r0;

    sprite->attrib2 = 112; // Set x to 112. Set matrixNum/size to 0

    r1 = 112 << SPRITEOAM_SHIFT_UNK6_4;
    r2 &= sprite->unk6;
    r2 |= r1;
    sprite->unk6 = r2;

    sUnknown_203B360->unk1B0 = r5;
}


void sub_80384D0(void)
{
  if ((sUnknown_203B360->unk1B0 & 8) != 0) {
    AddSprite(&sUnknown_203B360->unk1A8, 0x100, NULL, NULL);
  }
  sUnknown_203B360->unk1B0++;
}

