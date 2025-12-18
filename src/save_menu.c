#include "global.h"
#include "constants/main_menu.h"
#include "input.h"
#include "main_menu1.h"
#include "memory.h"
#include "menu_input.h"
#include "save.h"
#include "save_menu.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"

static EWRAM_INIT SaveMenuWork *sSaveMenuWork = {NULL};

const WindowTemplate gUnknown_80E6F20 =
{
    0,
    0x03,
    0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const WindowTemplate gUnknown_80E6F38 =
{
    0,
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

void CreateSaveMenu(s32 currMenu)
{
  s32 index;

  if (sSaveMenuWork == NULL) {
    sSaveMenuWork = MemoryAlloc(sizeof(SaveMenuWork), MEMALLOC_GROUP_8);
    MemoryFill8(sSaveMenuWork,0,sizeof(SaveMenuWork));
  }
  for(index = 0; index < 4; index++){
    sSaveMenuWork->unk148.id[index] = gUnknown_80E6F20;
  }
  ResetUnusedInputStruct();
  ShowWindows(&sSaveMenuWork->unk148, TRUE, TRUE);

  if (currMenu == MENU_DELETE_SAVE) {
      // Beware, Deleting your Adventure
    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,gDeletingYourAdventureMenuItems,
                 FALSE,6,FALSE);
  }
  else {
      // Saving your Adventure
    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,gSavingAdventureMenuItems,
                 FALSE,6,FALSE);
  }
  sub_8035CF4(sSaveMenuWork->unk8,0,TRUE);
  sSaveMenuWork->unk4 = 0;
  sSaveMenuWork->currMenu = currMenu;
  sub_8038830();
}

void CleanSaveMenu(void)
{
  ResetUnusedInputStruct();
  ShowWindows(NULL, TRUE, TRUE);
  if (sSaveMenuWork != NULL) {
    MemoryFree(sSaveMenuWork);
    sSaveMenuWork = NULL;
  }
}

// arm9.bin::02052F98
s32 UpdateSaveMenu(void)
{
  s32 saveStatus;
  MainMenu1Work *mainMenu;
  u32 menu;
  u32 uStack_18;
  u32 action;

  menu = MENU_NO_SCREEN_CHANGE;
  action = 3;

  switch(sSaveMenuWork->unk4)
  {
      default:
      case 2:
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 0:
        sub_8012FD8(&sSaveMenuWork->unk8[0]);
        uStack_18 = 0;
        sub_80140F8();
        saveStatus = WriteSavetoPak(&uStack_18,sub_8011C1C());
        sub_8014114();
        switch(saveStatus)
        {
            case SAVE_COMPLETED:
                sub_8035CC0(&sSaveMenuWork->unk148,0);
                if (sSaveMenuWork->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,
                                gDeletedSaveMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,
                                gAdventureSavedMenuItems,FALSE,6,FALSE);
                }
                if (sSaveMenuWork->currMenu == 0x2d) {
                    sSaveMenuWork->unk4 = 1;
                    return MENU_COMMUNICATION_1;
                }
                sub_8035CF4(sSaveMenuWork->unk8,0,TRUE);
                sSaveMenuWork->unk4 = 1;
                break;
            case SAVE_NOT_WRTTEN:
                CreateDialogueBoxAndPortrait(gUnknown_80E7178,0,0,0);
                sSaveMenuWork->unk4 = 5;
                break;
            default:
                sub_8035CC0(&sSaveMenuWork->unk148,0);
                if (sSaveMenuWork->currMenu == MENU_DELETE_SAVE) {
                    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,
                                    gAdventureCouldNotBeDeletedMenuItems,FALSE,6,FALSE);
                }
                else {
                    SetMenuItems(sSaveMenuWork->unk8,&sSaveMenuWork->unk148,0,&gUnknown_80E6F38,
                                    gAdventureCouldNotBeSavedMenuItems,FALSE,6,FALSE);
                }
                sub_8035CF4(sSaveMenuWork->unk8,0,TRUE);
                sSaveMenuWork->unk4 = 1;
                break;
        }
        menu = MENU_NO_SCREEN_CHANGE;
        break;
      case 1:
        if (sub_80130A8(&sSaveMenuWork->unk8[0]) == '\0') {
            sub_8013114(&sSaveMenuWork->unk8[0],&action);
        }
        switch(action)
        {
            case 2:
            case 4:
                if ((sSaveMenuWork->currMenu == 0x29) || (sSaveMenuWork->currMenu == MENU_DELETE_SAVE)) {
                    sSaveMenuWork->unk4 = 1;
                    menu = MENU_MAIN_SCREEN;
                }
                else if (sSaveMenuWork->currMenu == 0x2d) {
                    sSaveMenuWork->unk4 = 1;
                    menu = MENU_COMMUNICATION_1;
                }
                else if (sSaveMenuWork->currMenu == 0x2c) {
                    sSaveMenuWork->unk4 = 1;
                    menu = 0x1f;
                }
                else {
                    mainMenu = GetMainMenu();
                    if (mainMenu->unk3A != 0) {
                        sSaveMenuWork->unk4 = 1;
                        menu = 0x35;
                    }
                    else {
                        sSaveMenuWork->unk4 = 1;
                        menu = sSaveMenuWork->currMenu == 0x2b ? MENU_WONDER_MAIL : MENU_FRIEND_RESCUE;
                    }
                }
                break;
            case 3:
                sSaveMenuWork->unk4 = 1;
                break;
        }
        sub_80388C4();
  }
    return menu;
}

void sub_8038830(void)
{
    SpriteSetAffine1(&sSaveMenuWork->unk1A8, 0);
    SpriteSetAffine2(&sSaveMenuWork->unk1A8, 0);
    SpriteSetObjMode(&sSaveMenuWork->unk1A8, 0);
    SpriteSetMosaic(&sSaveMenuWork->unk1A8, 0);
    SpriteSetBpp(&sSaveMenuWork->unk1A8, 0);
    SpriteSetShape(&sSaveMenuWork->unk1A8, 1);

    SpriteSetTileNum(&sSaveMenuWork->unk1A8, 0x3F0);
    SpriteSetPriority(&sSaveMenuWork->unk1A8, 0);
    SpriteSetPalNum(&sSaveMenuWork->unk1A8, 15);

    SpriteSetMatrixNum(&sSaveMenuWork->unk1A8, 0);
    SpriteSetSize(&sSaveMenuWork->unk1A8, 0);

    SpriteSetX(&sSaveMenuWork->unk1A8, 112);
    SpriteSetY(&sSaveMenuWork->unk1A8, 104);

    sSaveMenuWork->unk1B0 = 0;
    ResetSprites(FALSE);
}

void sub_80388C4(void)
{
    if (sSaveMenuWork->unk1B0 & 8)
        AddSprite(&sSaveMenuWork->unk1A8, 0x100, NULL, NULL);

    sSaveMenuWork->unk1B0++;
}
