#include "global.h"
#include "code_80130A8.h"
#include "constants/main_menu.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "save.h"
#include "save_menu.h"
#include "sprite.h"
#include "text1.h"

static EWRAM_DATA_2 SaveMenuWork *sUnknown_203B364 = {0};

const UnkTextStruct2 gUnknown_80E6F20 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const UnkTextStruct2 gUnknown_80E6F38 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03,
    0x05, 0x08,
    0x15, 0x05,
    0x05, 0x00,
    NULL
};

const u8 sUnknown_80E6F70[];
const u8 sUnknown_80E6F90[];
const u8 sUnknown_80E6FAC[];

const MenuItem gSavingAdventureMenuItems[] = {
    {sUnknown_80E6FAC, 4},
    {sUnknown_80E6F90, 4},
    {sUnknown_80E6F70, 4},
    {NULL, 2}
};
ALIGNED(4) const u8 sUnknown_80E6F70[] = _("{CENTER_ALIGN}Don{APOSTROPHE}t turn off the power.");
ALIGNED(4) const u8 sUnknown_80E6F90[] = _("{CENTER_ALIGN}Saving your adventure!");
ALIGNED(4) const u8 sUnknown_80E6FAC[] = _("{CENTER_ALIGN}{COLOR_1 RED}Beware!{END_COLOR_TEXT_1} ");

extern const u8 sUnknown_80E6FDC[];
extern const u8 sUnknown_80E7008[];
extern const u8 sUnknown_80E6FF0[];

const MenuItem gAdventureSavedMenuItems[] = {
    {sUnknown_80E7008, 4},
    {sUnknown_80E6FF0, 4},
    {sUnknown_80E6FDC, 4},
    {NULL, 2}
};
ALIGNED(4) const u8 sUnknown_80E6FDC[] = _("{CENTER_ALIGN}has been saved.");
ALIGNED(4) const u8 sUnknown_80E6FF0[] = _("{CENTER_ALIGN}Your adventure so far");
ALIGNED(4) const u8 sUnknown_80E7008[] = _("{CENTER_ALIGN}{COLOR_1 LIGHT_BLUE}Success!{END_COLOR_TEXT_1} ");

extern const u8 sUnknown_80E7078[];
extern const u8 sUnknown_80E7050[];
extern const u8 sUnknown_80E703C[];

const MenuItem gAdventureCouldNotBeSavedMenuItems[] = {
    {sUnknown_80E7078, 4},
    {sUnknown_80E7050, 4},
    {sUnknown_80E703C, 4},
    {NULL, 2}
};
ALIGNED(4) const u8 sUnknown_80E703C[] = _("{CENTER_ALIGN}Please try again.");
ALIGNED(4) const u8 sUnknown_80E7050[] = _("{CENTER_ALIGN}Your adventure could not be saved.");
ALIGNED(4) const u8 sUnknown_80E7078[] = _("{CENTER_ALIGN}{COLOR_1 RED}Save failed!{END_COLOR_TEXT_1} ");


extern const u8 DeletingAdventure_80E70B0[];

const MenuItem gDeletingYourAdventureMenuItems[] = {
    {sUnknown_80E6FAC, 4},
    {DeletingAdventure_80E70B0, 4},
    {sUnknown_80E6F70, 4},
    {NULL, 2}
};
ALIGNED(4) const u8 DeletingAdventure_80E70B0[] = _("{CENTER_ALIGN}Deleting your adventure!");

extern const u8 Data_80E70EC[];
extern const u8 AdventureDeleted_80E70F0[];

const MenuItem gDeletedSaveMenuItems[] = {
    {sUnknown_80E7008, 4},
    {AdventureDeleted_80E70F0, 4},
    {Data_80E70EC, 4},
    {NULL, 2},
};

ALIGNED(4) const u8 Data_80E70EC[] = _("  ");
ALIGNED(4) const u8 AdventureDeleted_80E70F0[] = _("{CENTER_ALIGN}Your adventure has been deleted.");

extern const u8 sUnknown_80E7134[];
extern const u8 sUnknown_80E715C[];

const MenuItem gAdventureCouldNotBeDeletedMenuItems[] = {
    {sUnknown_80E715C, 4},
    {sUnknown_80E7134, 4},
    {sUnknown_80E703C, 4},
    {NULL, 2},
};
ALIGNED(4) const u8 sUnknown_80E7134[] = _("{CENTER_ALIGN}Your adventure could not be deleted.");
ALIGNED(4) const u8 sUnknown_80E715C[] = _("{CENTER_ALIGN}{COLOR_1 RED}Deletion failed!{END_COLOR_TEXT_1} ");

ALIGNED(4) const u8 gUnknown_80E7178[] = _("{CENTER_ALIGN}The data could not be written.\n"
                                           "{CENTER_ALIGN}Please turn off the power and remove\n"
                                           "{CENTER_ALIGN}and reinsert the DS Card.");

static void sub_8038830(void);
static void sub_80388C4(void);

extern void sub_8038440(void);
extern void sub_80384D0(void);
extern void sub_80140F8(void);

void CreateSaveMenu(s32 currMenu)
{
  s32 index;

  if (sUnknown_203B364 == NULL) {
    sUnknown_203B364 = MemoryAlloc(sizeof(SaveMenuWork),8);
    MemoryFill8((u8 *)sUnknown_203B364,0,sizeof(SaveMenuWork));
  }
  for(index = 0; index < 4; index++){
    sUnknown_203B364->unk148[index] = gUnknown_80E6F20;
  }
  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(sUnknown_203B364->unk148, TRUE, TRUE);

  if (currMenu == MENU_DELETE_SAVE) {
      // Beware, Deleting your Adventure
    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,gDeletingYourAdventureMenuItems,
                 FALSE,6,FALSE);
  }
  else {
      // Saving your Adventure
    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,gSavingAdventureMenuItems,
                 FALSE,6,FALSE);
  }
  sub_8035CF4(sUnknown_203B364->unk8,0,TRUE);
  sUnknown_203B364->unk4 = 0;
  sUnknown_203B364->currMenu = currMenu;
  sub_8038830();
}

void CleanSaveMenu(void)
{
  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(NULL, TRUE, TRUE);
  if (sUnknown_203B364 != NULL) {
    MemoryFree(sUnknown_203B364);
    sUnknown_203B364 = NULL;
  }
}

s32 UpdateSaveMenu(void)
{
  s32 saveStatus;
  MainMenu1Work *mainMenu;
  u32 menu;
  u32 uStack_18;
  u32 action;

  menu = MENU_NO_SCREEN_CHANGE;
  action = 3;

  switch(sUnknown_203B364->unk4)
  {
      default:
      case 2:
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 0:
        sub_8012FD8(&sUnknown_203B364->unk8[0]);
        uStack_18 = 0;
        sub_80140F8();
        saveStatus = WriteSavetoPak(&uStack_18,sub_8011C1C());
        sub_8014114();
        switch(saveStatus)
        {
            case SAVE_COMPLETED:
                sub_8035CC0(sUnknown_203B364->unk148,0);
                if (sUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                gDeletedSaveMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                gAdventureSavedMenuItems,FALSE,6,FALSE);
                }
                if (sUnknown_203B364->currMenu == 0x2d) {
                    sUnknown_203B364->unk4 = 1;
                    return MENU_COMMUNICATION_1;
                }
                sub_8035CF4(sUnknown_203B364->unk8,0,TRUE);
                sUnknown_203B364->unk4 = 1;
                break;
            case SAVE_NOT_WRTTEN:
                xxx_info_box_80141B4(gUnknown_80E7178,0,0,0);
                sUnknown_203B364->unk4 = 5;
                break;
            default:
                sub_8035CC0(sUnknown_203B364->unk148,0);
                if (sUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                    gAdventureCouldNotBeDeletedMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sUnknown_203B364->unk8,sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                    gAdventureCouldNotBeSavedMenuItems,FALSE,6,FALSE);
                }
                sub_8035CF4(sUnknown_203B364->unk8,0,TRUE);
                sUnknown_203B364->unk4 = 1;
                break;
        }
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 1:
        if (sub_80130A8(&sUnknown_203B364->unk8[0]) == '\0') {
            sub_8013114(&sUnknown_203B364->unk8[0],&action);
        }
        switch(action)
        {
            case 2:
            case 4:
                if ((sUnknown_203B364->currMenu == 0x29) || (sUnknown_203B364->currMenu == MENU_DELETE_SAVE)) {
                    sUnknown_203B364->unk4 = 1;
                    menu = MENU_MAIN_SCREEN;
                }
                else if (sUnknown_203B364->currMenu == 0x2d) {
                    sUnknown_203B364->unk4 = 1;
                    menu = MENU_COMMUNICATION_1;
                }
                else if (sUnknown_203B364->currMenu == 0x2c) {
                    sUnknown_203B364->unk4 = 1;
                    menu = 0x1f;
                }
                else {
                    mainMenu = GetMainMenu();
                    if (mainMenu->unk3A != 0) {
                        sUnknown_203B364->unk4 = 1;
                        menu = 0x35;
                    }
                    else {
                        sUnknown_203B364->unk4 = 1;
                        menu = sUnknown_203B364->currMenu == 0x2b ? MENU_WONDER_MAIL : MENU_FRIEND_RESCUE;
                    }
                }
                break;
            case 3:
                sUnknown_203B364->unk4 = 1;
                break;
        }
        sub_80388C4();
  }
    return menu;
}

void sub_8038830(void)
{
#ifdef NONMATCHING // SpriteOAM memes. TODO: Match like sub_8039174 with multiple vars and while(0)
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
    sprite = &sUnknown_203B364->unk1A8;

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

    r1 = 104 << SPRITEOAM_SHIFT_UNK6_4;
    r2 &= sprite->unk6;
    r2 |= r1;
    sprite->unk6 = r2;

    sUnknown_203B364->unk1B0 = r5;
    ResetSprites(FALSE);
}

void sub_80388C4(void)
{
    if (sUnknown_203B364->unk1B0 & 8)
        AddSprite(&sUnknown_203B364->unk1A8, 0x100, NULL, NULL);

    sUnknown_203B364->unk1B0++;
}
