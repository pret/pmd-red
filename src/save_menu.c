#include "global.h"
#include "string_format.h"
#include "constants/main_menu.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "save.h"
#include "save_menu.h"
#include "sprite.h"
#include "text.h"

static EWRAM_INIT SaveMenuWork *sUnknown_203B364 = {NULL};

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
ALIGNED(4) const u8 sUnknown_80E6F70[] = _("{CENTER_ALIGN}Don't turn off the power.");
ALIGNED(4) const u8 sUnknown_80E6F90[] = _("{CENTER_ALIGN}Saving your adventure!");
ALIGNED(4) const u8 sUnknown_80E6FAC[] = _("{CENTER_ALIGN}{COLOR RED}Beware!{RESET} ");

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
ALIGNED(4) const u8 sUnknown_80E7008[] = _("{CENTER_ALIGN}{COLOR CYAN_G}Success!{RESET} ");

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
ALIGNED(4) const u8 sUnknown_80E7078[] = _("{CENTER_ALIGN}{COLOR RED}Save failed!{RESET} ");


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
ALIGNED(4) const u8 sUnknown_80E715C[] = _("{CENTER_ALIGN}{COLOR RED}Deletion failed!{RESET} ");

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
    MemoryFill8(sUnknown_203B364,0,sizeof(SaveMenuWork));
  }
  for(index = 0; index < 4; index++){
    sUnknown_203B364->unk148.a0[index] = gUnknown_80E6F20;
  }
  ResetUnusedInputStruct();
  xxx_call_save_unk_text_struct_800641C(&sUnknown_203B364->unk148, TRUE, TRUE);

  if (currMenu == MENU_DELETE_SAVE) {
      // Beware, Deleting your Adventure
    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,gDeletingYourAdventureMenuItems,
                 FALSE,6,FALSE);
  }
  else {
      // Saving your Adventure
    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,gSavingAdventureMenuItems,
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
                sub_8035CC0(&sUnknown_203B364->unk148,0);
                if (sUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                gDeletedSaveMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
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
                CreateDialogueBoxAndPortrait(gUnknown_80E7178,0,0,0);
                sUnknown_203B364->unk4 = 5;
                break;
            default:
                sub_8035CC0(&sUnknown_203B364->unk148,0);
                if (sUnknown_203B364->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
                                    gAdventureCouldNotBeDeletedMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sUnknown_203B364->unk8,&sUnknown_203B364->unk148,0,&gUnknown_80E6F38,
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
    SpriteSetAffine1(&sUnknown_203B364->unk1A8, 0);
    SpriteSetAffine2(&sUnknown_203B364->unk1A8, 0);
    SpriteSetObjMode(&sUnknown_203B364->unk1A8, 0);
    SpriteSetMosaic(&sUnknown_203B364->unk1A8, 0);
    SpriteSetBpp(&sUnknown_203B364->unk1A8, 0);
    SpriteSetShape(&sUnknown_203B364->unk1A8, 1);

    SpriteSetTileNum(&sUnknown_203B364->unk1A8, 0x3F0);
    SpriteSetPriority(&sUnknown_203B364->unk1A8, 0);
    SpriteSetPalNum(&sUnknown_203B364->unk1A8, 15);

    SpriteSetMatrixNum(&sUnknown_203B364->unk1A8, 0);
    SpriteSetSize(&sUnknown_203B364->unk1A8, 0);

    SpriteSetX(&sUnknown_203B364->unk1A8, 112);
    SpriteSetY(&sUnknown_203B364->unk1A8, 104);

    sUnknown_203B364->unk1B0 = 0;
    ResetSprites(FALSE);
}

void sub_80388C4(void)
{
    if (sUnknown_203B364->unk1B0 & 8)
        AddSprite(&sUnknown_203B364->unk1A8, 0x100, NULL, NULL);

    sUnknown_203B364->unk1B0++;
}
