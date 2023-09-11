#include "global.h"
#include "adventure_log_menu.h"
#include "code_803D0D8.h"
#include "code_8098BDC.h"
#include "constants/wonder_mail.h"
#include "debug_menu1.h"
#include "ds_menus.h"
#include "friend_rescue.h"
#include "load_screen.h"
#include "main_menu.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus1.h"
#include "pokemon.h"
#include "rescue_password_menu.h"
#include "save.h"
#include "text1.h"
#include "text2.h"
#include "trade_items_menu.h"

// NOTE: 0x13 and 0x14
// Communication Screen?
// Got Communication warning when I wrote them to the struct

// NOTE: 0x29, 0x2A, 0x2B, 0x2C
// Triggers a save

// NOTE: 0x2D
// Triggers a save and then goes to 0x13 (comms warning)

// NOTE: 0x2E
// Deletes the Save

EWRAM_DATA_2 MainMenu *gMainMenu = {0};
EWRAM_DATA_2 struct unkStruct_203B34C *gUnknown_203B34C = {0};
EWRAM_DATA_2 u32 gUnknown_203B350 = {0};
EWRAM_DATA_2 u32 gUnknown_203B354 = {0}; // unused everywhere else except here..

extern void SetWindowBGColor(void);
extern void CreateWonderMailMenu(void);
extern void CreateSaveMenu(u32);
extern u32 UpdateMainMenu(void);
extern s32 UpdateWonderMailMenu(void);
extern s32 sub_80383D4(void);
extern s32 UpdateSaveMenu(void);
extern void CleanWonderMailMenu(void);
extern void sub_80383A8(void);
extern void CleanSaveMenu(void);

void CleanMainMenu(void);
void DrawMainMenu(void);
s32 sub_8035DB4(u32);
void sub_803623C(void);
bool8 SetMainMenuText();
void SetMainMenuItems();

static const u8 sUnknown_80E5CE4[];
static const u8 sUnknown_80E5CE8[];
static const u8 sUnknown_80E5D24[];
static const u8 sUnknown_80E5D60[];
static const u8 sUnknown_80E5D88[];
static const u8 sUnknown_80E5DB8[];
static const u8 sUnknown_80E5DCC[];
static const u8 sUnknown_80E5E08[];
static const u8 sUnknown_80E5E34[];
static const u8 sUnknown_80E5EA0[];
static const u8 sUnknown_80E5E74[];
static const u8 sUnknown_80E5EF8[];
static const u8 sUnknown_80E5ED4[];
static const u8 sUnknown_80E5F58[];
static const u8 sUnknown_80E5F34[];
static const u8 sUnknown_80E5FB0[];
static const u8 sUnknown_80E5F98[];
static const u8 sUnknown_80E5FE4[];
static const u8 sUnknown_80E6008[];
static const u8 sUnknown_80E6048[];
static const u8 sUnknown_80E6070[];

const UnkTextStruct2 gUnknown_80E59A8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

static const char main_menu_fill[] = "pksdir0";

const UnkTextStruct2 gUnknown_80E59C8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const UnkTextStruct2 gUnknown_80E59E0 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const MenuItem gUnknown_80E59F8[] =
{
    {"New Game", MENU_NEW_GAME},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5A29 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0A, 0x02,
   0x02, 0x00,
   NULL
};

const MenuItem gUnknown_80E5A44[] =
{
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5A60 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 
   0x02, 0x02,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const UnkTextStruct2 gUnknown_80E5A78 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0B, 0x09,
   0x09, 0x00,
   NULL
};

const MenuItem gUnknown_80E5A90[] = 
{
    {"Continue", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

const MenuItem gUnknown_80E5AFC[] =
{
    {"Continue", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5B34 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const MenuItem gUnknown_80E5B4C[] =
{
    {"Awaiting Rescue", MENU_AWAITING_RESCUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

const MenuItem gUnknown_80E5B8C[] = 
{
    {"Awaiting Rescue", MENU_AWAITING_RESCUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5BC4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const MenuItem gUnknown_80E5BDC[] =
{
    {"Revive Team", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

const MenuItem gUnknown_80E5C18[] =
{
    {"Revive Team", MENU_CONTINUE},
    {"Delete Save Data", MENU_DELETE_SAVE_PROMPT},
    {"Adventure Log", MENU_ADVENTURE_LOG},
    {"Friend Rescue", MENU_FRIEND_RESCUE},
    {"Trade Items", MENU_TRADE_ITEMS},
    {"Wonder Mail", MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5C50 = { 
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x02,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const MenuItem gUnknown_80E5C68[] = 
{
    {"Send Items", MENU_SEND_ITEMS},
    {"Receive Items", MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

const MenuItem gUnknown_80E5C9C[] = 
{
    {"Send Items", -1},
    {"Receive Items", MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

const UnkTextStruct2 gUnknown_80E5CB4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03,
   0x02, 0x0F,
   0x1A, 0x03,
   0x03, 0x00,
   NULL
};

const MenuItem gUnknown_80E5CCC[] = 
{
    {sUnknown_80E5CE8, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5CE4[] = "  ";
static const u8 sUnknown_80E5CE8[] = "Start an entirely new adventure.";

const MenuItem gUnknown_80E5D0C[] = 
{
    {sUnknown_80E5D24, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D24[] = "Check your career as an adventurer.";

const MenuItem gUnknown_80E5D48[] = 
{
    {sUnknown_80E5D88, 0xffde},
    {sUnknown_80E5D60, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D60[] = _("It won{APOSTROPHE}t be in the release version.");
static const u8 sUnknown_80E5D88[] = "This is the Debug Mode.";

const MenuItem gUnknown_80E5DA0[] = 
{
    {sUnknown_80E5DCC, 0xffde},
    {sUnknown_80E5DB8, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5DB8[] = "you last saved.  ";
static const u8 sUnknown_80E5DCC[] = "Resume your adventure from where";

const MenuItem gUnknown_80E5DF0[] = {
    {sUnknown_80E5E34, 0xFFDE},
    {sUnknown_80E5E08, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5E08[] = _("{COLOR_1 RED}Beware{END_COLOR_TEXT_1}! This will delete it forever!");
static const u8 sUnknown_80E5E34[] = "This will delete your saved game data.";

const MenuItem gUnknown_80E5E5C[] = {
    {sUnknown_80E5EA0, 0xFFDE},
    {sUnknown_80E5E74, 0xFFDE},
    {0, 0xFFDD}
};

ALIGNED(4) static const u8 sUnknown_80E5E74[] = _("passwords{COMMA} friends may rescue each other.");
static const u8 sUnknown_80E5EA0[] = "Using a Game Link cable or";

const MenuItem gUnknown_80E5EBC[] = {
    {sUnknown_80E5EF8, 0xFFDE},
    {sUnknown_80E5ED4, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5ED4[] = "trade stored items with a friend.";
ALIGNED(4) static const u8 sUnknown_80E5EF8[] = _("Using a Game Link cable{COMMA} you can");

const MenuItem gUnknown_80E5F1C[] = {
    {sUnknown_80E5F58, 0xFFDE},
    {sUnknown_80E5F34, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F34[] = "You can give up waiting for rescue.";
static const u8 sUnknown_80E5F58[] = "You are awaiting rescue by a friend.";

const MenuItem gUnknown_80E5F80[] = {
    {sUnknown_80E5FB0, 0xFFDE},
    {sUnknown_80E5F98, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F98[] = "receive Wonder Mail.";
ALIGNED(4) static const u8 sUnknown_80E5FB0[] = _("Using passwords{COMMA} you can");

const MenuItem gUnknown_80E5FCC[] = {
    {sUnknown_80E6008, 0xFFDE},
    {sUnknown_80E5FE4, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E5FE4[] = "receive teams from your friends.";
ALIGNED(4) static const u8 sUnknown_80E6008[] = _("Using the Dual Slot function{COMMA} you can");

const MenuItem gUnknown_80E6030[] = {
    {sUnknown_80E6070, 0xFFDE},
    {sUnknown_80E6048, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E6048[] = "go on an adventure to unknown worlds.";
ALIGNED(4) static const u8 sUnknown_80E6070[] = _("Using wireless communication{COMMA} you can");


void InitMainMenu(void)
{
  if (gMainMenu == NULL) {
    gMainMenu = MemoryAlloc(sizeof(MainMenu),8);
    MemoryFill8((u8 *)gMainMenu, 0, sizeof(MainMenu));
  }
  gMainMenu->currMenu = MENU_NO_SCREEN_CHANGE;
  gMainMenu->nextMenu = MENU_MAIN_SCREEN;
  gMainMenu->lastMenu = MENU_MAIN_SCREEN;
  gMainMenu->unk38 = -1;
  gMainMenu->unk3C = -1;
  gMainMenu->sub.unk2E = 0;
  gMainMenu->sub.unk2C = 1;
  gMainMenu->sub.unk2D = 0;
  sub_8035DA0();
  gMainMenu->unk3A = 0;
}

void DeleteMainMenu(void)
{
    if(gMainMenu){
        MemoryFree(gMainMenu);
        gMainMenu = NULL;
    }
}

void SetUpMenu(void)
{
  if (gMainMenu->currMenu != gMainMenu->nextMenu) {
    switch(gMainMenu->nextMenu) {
        case MENU_MAIN_SCREEN:
            SetWindowBGColor();
            sub_8099690(0);
            DrawMainMenu();
            break;
        case MENU_AWAITING_RESCUE:
        case MENU_CONTINUE:
        case MENU_DELETE_SAVE_PROMPT:
        case MENU_DELETE_SAVE_CONFIRM:
            CreateLoadScreen(gMainMenu->nextMenu);
            break;
        case MENU_TRADE_ITEMS:
            CreateTradeItemsMenu();
            break;
        case MENU_COMMUNICATION_1:
        case MENU_COMMUNICATION_2:
            sub_8036FDC(sub_8035DB4(gMainMenu->nextMenu));
            break;
        case MENU_FRIEND_RESCUE:
            CreateFriendRescueMenu();
            break;
        case MENU_WONDER_MAIL:
            CreateWonderMailMenu();
            break;
        case MENU_DUAL_SLOT:
            CreateDualSlotMenu();
            break;
        case MENU_WIRELESS_COMMS:
            CreateWirelessCommsMenu();
            break;
        case MENU_DISPLAY_RESCUE_PASSWORD:
        case MENU_RESCUE_PASSWORD_ENTRY:
            CreateRescuePasswordMenu(gMainMenu->nextMenu);
            break;
        case MENU_ADVENTURE_LOG:
            CreateAdventureLogMenu();
            break;
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case MENU_DELETE_SAVE:
            CreateSaveMenu(gMainMenu->nextMenu);
            break;
        case MENU_DEBUG:
            CreateDebugMenu();
            break;
    }
    gMainMenu->currMenu = gMainMenu->nextMenu;
  }
}

s32 UpdateMenu(void)
{
  s32 nextMenu1;
  s32 nextMenu;

  nextMenu = MENU_NO_SCREEN_CHANGE;
  switch(gMainMenu->nextMenu) {
    case MENU_MAIN_SCREEN:
        nextMenu = UpdateMainMenu();
        break;
    case MENU_AWAITING_RESCUE:
    case MENU_CONTINUE:
    case MENU_DELETE_SAVE_PROMPT:
    case MENU_DELETE_SAVE_CONFIRM:
        nextMenu = UpdateLoadScreenMenu();
        break;
    case MENU_TRADE_ITEMS:
        nextMenu1 = UpdateTradeItemsMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (nextMenu1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_FRIEND_RESCUE:
        nextMenu1 = UpdateFriendRescueMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (nextMenu1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_WONDER_MAIL:
        nextMenu1 = UpdateWonderMailMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (nextMenu1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_DUAL_SLOT:
        nextMenu1 = UpdateDualSlotMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (nextMenu1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_WIRELESS_COMMS:
        nextMenu1 = UpdateWirelessCommsMenu();
        nextMenu = 5;
        if ((nextMenu1 != 3) && (nextMenu = MENU_NO_SCREEN_CHANGE, nextMenu1 == 2)) {
            nextMenu = MENU_MAIN_SCREEN;
        }
        break;
    case MENU_DISPLAY_RESCUE_PASSWORD:
    case MENU_RESCUE_PASSWORD_ENTRY:
        nextMenu = UpdateRescuePasswordMenu();
        break;
    case MENU_ADVENTURE_LOG:
        nextMenu = UpdateAdventureLogMenu();
        break;
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
        nextMenu = sub_80383D4();
        break;
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case MENU_DELETE_SAVE:
        nextMenu = UpdateSaveMenu();
        break;
    case MENU_DEBUG:
        nextMenu = UpdateDebugMenu();
        break;
  }
  if (nextMenu != MENU_NO_SCREEN_CHANGE) {
    gMainMenu->nextMenu = nextMenu;
  }
  return nextMenu;
}

void CleanUpMenu(void)
{
  if (gMainMenu->lastMenu != gMainMenu->nextMenu) {
    switch(gMainMenu->lastMenu) {
    case MENU_MAIN_SCREEN:
      CleanMainMenu();
      break;
    case MENU_AWAITING_RESCUE:
    case MENU_CONTINUE:
    case MENU_DELETE_SAVE_PROMPT:
    case MENU_DELETE_SAVE_CONFIRM:
      CleanLoadScreen();
      break;
    case MENU_TRADE_ITEMS:
      CleanTradeItemsMenu();
      break;
    case MENU_COMMUNICATION_1:
    case MENU_COMMUNICATION_2:
      sub_80370D4();
      break;
    case MENU_FRIEND_RESCUE:
      CleanFriendRescueMenu();
      break;
    case MENU_WONDER_MAIL:
      CleanWonderMailMenu();
      break;
    case MENU_DUAL_SLOT:
      CleanDualSlotMenu();
      break;
    case MENU_WIRELESS_COMMS:
      CleanWirelessCommsMenu();
      break;
    case MENU_DISPLAY_RESCUE_PASSWORD:
    case MENU_RESCUE_PASSWORD_ENTRY:
      CleanRescuePasswordMenu();
      break;
    case MENU_ADVENTURE_LOG:
      CleanAdventureLogMenu();
      break;
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
      sub_80383A8();
      break;
    case 0x29:
    case 0x2a:
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case MENU_DELETE_SAVE:
      CleanSaveMenu();
      break;
    case MENU_DEBUG:
      DeleteDebugMenu();
      break;
    }
    gMainMenu->lastMenu = gMainMenu->nextMenu;
  }
}

// Unused
void sub_8035C00(MainMenuSub *param)
{
    gMainMenu->sub = *param;
}

// Unused
MainMenuSub *sub_8035C10(void)
{
   return &gMainMenu->sub;
}

void sub_8035C1C(void)
{
    gMainMenu->sub.unk2E = 0;
    gMainMenu->sub.unk2C = 1;
    gMainMenu->sub.unk2D = 0;
}

void SetMenuItems(MenuStruct *param_1, UnkTextStruct2 *unkData, s32 index,
        const UnkTextStruct2 *param_4, const MenuItem *menuItems, u8 param_6, u32 menuAction, u32 unused_8)
{
  unkData[index] = *param_4;
  ResetUnusedInputStruct();
  sub_800641C(unkData, TRUE, TRUE);
  if (param_6 != 0) {
       sub_8012D60(&param_1[index],menuItems,0,0,menuAction,index);
  }
  else {
       sub_8012E04(&param_1[index],menuItems,0,0,0,index);
  }
  param_1[index].unk4C = TRUE;
}

void sub_8035CC0(UnkTextStruct2 *dataArray, u32 index)
{
    sub_8006518(dataArray);
    dataArray[index] = gUnknown_80E59A8;
    ResetUnusedInputStruct();
    sub_800641C(dataArray, TRUE, TRUE);
}

void sub_8035CF4(MenuStruct * Menu, u32 index, bool8 r2)
 {
    Menu[index].unk4C = r2;
    Menu[index].unk4D = 1;
    Menu[index].menuAction = -1;
    sub_8012EBC(&Menu[index]);
}

void sub_8035D1C(void)
{
    gMainMenu->unk38 = -1;
}

// Unused
void sub_8035D30(s32 r0)
{
    gMainMenu->unk38 = r0;
}

s16 sub_8035D3C(void)
{
    return gMainMenu->unk38;
}

MainMenu *GetMainMenu(void)
{
    return gMainMenu;
}

// Unused
void sub_8035D58(void)
{
    gMainMenu->unk3C = -1;
}

// Unused
void sub_8035D68(s32 r0)
{
    gMainMenu->unk3C = r0;
}

s32 sub_8035D74(void)
{
    return gMainMenu->unk3C;
}

// Unused
void sub_8035D80(unkStruct_8035D94 *item)
{

#ifndef NONMATCHING
    register u32 numItem asm("r1");
#else
    u32 numItem;
#endif

    u32 itemIndex;
    MainMenu *preload;

    preload = gMainMenu;
    numItem = item->numItems;
    itemIndex = item->itemIndex.itemIndex_u32;
    preload->unk30.itemIndex.itemIndex_u32 = itemIndex;
    preload->unk30.numItems = numItem;
}

unkStruct_8035D94 *sub_8035D94(void)
{
    return &gMainMenu->unk30;
}

void sub_8035DA0(void)
{
    gMainMenu->unk30.itemIndex.itemIndex_u8 = ITEM_NOTHING;
    gMainMenu->unk30.numItems = 0;
}

s32 sub_8035DB4(u32 currMenu)
{
    s32 returnVar = 8;
    switch(currMenu)
    {
    case MENU_COMMUNICATION_1:
        returnVar = 0;
        break;
    case MENU_COMMUNICATION_2:
        returnVar = 1;
        break;
    case 0x15:
        returnVar = 2;
        break;
    case 0x16:
        returnVar = 3;
        break;
    case 0x17:
        returnVar = 4;
        break;
    case 0x18:
        returnVar = 5;
        break;
    case 0x19:
        returnVar = 6;
        break;
    case 0x1a:
        returnVar = 7;
        break;
    }
    return returnVar;
}

void DrawMainMenu(void)
{
    s32 index;

    if(gUnknown_203B34C == NULL)
    {
        gUnknown_203B34C = MemoryAlloc(sizeof(struct unkStruct_203B34C), 8);
        MemoryFill8((u8 *)gUnknown_203B34C, 0, sizeof(struct unkStruct_203B34C));
    }

    for(index = 0; index < 4; index++)
    {
        gUnknown_203B34C->unk144[index] = gUnknown_80E59C8;
    }

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B34C->unk144, TRUE, TRUE);
    SetMainMenuItems();
    gUnknown_203B34C->currMenuChoice = -1;

    if(SetMainMenuText())
    {
        sub_8035CF4(gUnknown_203B34C->unk4,2,FALSE);
    }

    sub_8035CF4(gUnknown_203B34C->unk4,0,TRUE);
    gUnknown_203B34C->unk0 = 1;
}

void CleanMainMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, TRUE, TRUE);
    if(gUnknown_203B34C != NULL)
    {
        MemoryFree(gUnknown_203B34C);
        gUnknown_203B34C = NULL;
    }
}

u32 UpdateMainMenu(void)
{
    u32 nextMenu = MENU_NO_SCREEN_CHANGE;
    switch(gUnknown_203B34C->unk0)
    {
        case 1:
            sub_8012FD8(&gUnknown_203B34C->unk4[2]);
            if(!sub_8012FD8(gUnknown_203B34C->unk4))
                sub_8013114(gUnknown_203B34C->unk4, &nextMenu);

            if(SetMainMenuText())
            {
                sub_8035CF4(gUnknown_203B34C->unk4, 0, TRUE);
                sub_8035CF4(gUnknown_203B34C->unk4, 2, FALSE);
            }
            switch(nextMenu)
            {
                case MENU_NO_SCREEN_CHANGE:
                     nextMenu = MENU_NO_SCREEN_CHANGE;
                     break;
                case 0xffdd:
                    gUnknown_203B34C->unk0 = 1;
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    ResetUnusedInputStruct();
                    sub_8035CF4(gUnknown_203B34C->unk4, 0, TRUE);
                    sub_8035CF4(gUnknown_203B34C->unk4, 2, FALSE);
                    break;
                case MENU_TRADE_ITEMS:
                    sub_8035DA0();
                    gUnknown_203B350 = nextMenu;
                    break;
                case MENU_NEW_GAME:
                case MENU_AWAITING_RESCUE:
                case MENU_CONTINUE:
                case MENU_DELETE_SAVE_PROMPT:
                case MENU_DELETE_SAVE_CONFIRM:
                case MENU_ADVENTURE_LOG:
                case MENU_FRIEND_RESCUE:
                case MENU_WONDER_MAIL:
                case MENU_DUAL_SLOT:
                case MENU_WIRELESS_COMMS:
                case MENU_DEBUG:
                    gUnknown_203B350 = nextMenu;
                    break;

            }
            break;
        case 0xC:
            if(!sub_8012FD8(&gUnknown_203B34C->unk4[1]))
                sub_8013114(&gUnknown_203B34C->unk4[1], &nextMenu);
            switch(nextMenu)
            {
                case 0xffdd:
                    sub_803623C();
                    gUnknown_203B34C->unk0 = 1;
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    break;
                case MENU_SEND_ITEMS:
                    gUnknown_203B354 = nextMenu;
                    nextMenu = MENU_TRADE_ITEMS;
                    break;
                case MENU_RECEIVE_ITEMS:
                    gUnknown_203B354 = nextMenu;
                    nextMenu = MENU_COMMUNICATION_2;
                    break;
                case MENU_NO_SCREEN_CHANGE:
                    nextMenu = MENU_NO_SCREEN_CHANGE;
                    break;
                default:
                    break;
            }
            break;
        default:
        case 0xD: // forces the bls switch
            break;
    }
    return nextMenu;
}

bool8 SetMainMenuText(void)
{
  u32 menuChoice;
  const MenuItem *preload;

 // Have to load the pointer before the index
  preload = gUnknown_203B34C->unk4[0].menuItems;
  menuChoice = preload[gUnknown_203B34C->unk4[0].input.menuIndex].menuAction; // chosen menu action?
  if (gUnknown_203B34C->currMenuChoice == menuChoice) {
    return FALSE;
  }

  gUnknown_203B34C->currMenuChoice = menuChoice;
  sub_8035CC0(gUnknown_203B34C->unk144,2);
  sub_8035CC0(gUnknown_203B34C->unk144,3);
  switch(menuChoice) {
    case MENU_WIRELESS_COMMS:
        // Using wireless communications, you can go on an adventure to unknown worlds.
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E6030,0,0,0);
        break;
    case MENU_WONDER_MAIL:
        // Using passwords, you can receive Wonder Mail
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F80,0,0,0);
        break;
    case MENU_AWAITING_RESCUE:
        // You are awaiting resuce by a friend
        // You can give up waiting for rescue
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F1C,0,0,0);
        break;
    case MENU_NEW_GAME:
        // Start an entirely new adventure
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5CCC,0,0,0);
        break;
    case MENU_CONTINUE:
        // Resume your adventure from where you last saved
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DA0,0,0,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        // This will delete your saved game data.
        // Beware! This will delete it forever
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DF0,0,0,0);
        break;
    case MENU_ADVENTURE_LOG:
        // Check your career as an adventurer
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D0C,0,0,0);
        break;
    case MENU_FRIEND_RESCUE:
        // Using a Game Link cable or passwords, friends may rescue each other
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5E5C,0,0,0);
        break;
    case MENU_TRADE_ITEMS:
        // Using a Game Link cable you can trade stored items with a friend
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5EBC,0,0,0);
        break;
    case MENU_DUAL_SLOT:
        // Using Dual Slot function, you can receive teams from your friends
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5FCC,0,0,0);
        break;
    case MENU_DEBUG:
        // This is the Debug Mode.
        // It won't be in the release version
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D48,0,0,0);
        break;
    default:
        break;
  }
  return TRUE;
}

void sub_803623C(void)
{
  sub_8035CC0(gUnknown_203B34C->unk144,1);
  SetMainMenuItems();
  gUnknown_203B34C->currMenuChoice = -1;
  if (SetMainMenuText()) {
    sub_8035CF4(gUnknown_203B34C->unk4,2,FALSE);
  }
  sub_8035CF4(gUnknown_203B34C->unk4,0,TRUE);
}

void SetMainMenuItems(void)
{ 
  if (sub_8011C34() != -1) {
    if (CountMailType(WONDER_MAIL_TYPE_SOS) == 0) {
      if (CountMailType(WONDER_MAIL_TYPE_OKD) != 0) {
        if (sub_803D0D8() != 0) {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
          SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5C18,1,gUnknown_203B350,1);
        }
        else {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5BC4,gUnknown_80E5BDC,1,gUnknown_203B350,1);
        }
      }
      else {
        if (sub_803D0D8() != 0) {
            // Continue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
          SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5AFC,1,gUnknown_203B350,1);
        }
        else {
            // Continue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A60,gUnknown_80E5A90,1,gUnknown_203B350,1);
        }
      }
    }
    else {
      if (sub_803D0D8() != 0) {
            // Awaiting Rescue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5B8C,1,gUnknown_203B350,1);
      }
      else {
            // Awaiting Rescue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
        SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5B34,gUnknown_80E5B4C,1,gUnknown_203B350,1);
      }
    }
  }
  else
  {
      // New Game
      // Adventure Log
    SetMenuItems(gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E59E0,gUnknown_80E59F8,1,gUnknown_203B350,1);
  }
}

bool8 sub_80363E0(void)
{
    if(gUnknown_203B34C == NULL)
        return FALSE;
    if(gUnknown_203B34C->unk0 == 0xC)
        return FALSE;
    return TRUE;
}
