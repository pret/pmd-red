#include "global.h"
#include "debug_menu.h"
#include "ds_menus.h"
#include "load_screen.h"
#include "main_menu.h"
#include "adventure_log.h"
#include "input.h"
#include "menu.h"
#include "memory.h"
#include "text.h"
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


struct unkStruct_Menu
{
    // size 0x50;
    u8 fil0[0x4C];
    u8 unk4C;
    u8 fill4D[0x50 - 0x4D];
};

struct unkStruct_203B34C
{
    // size: 0x1A8
    u32 unk0;
    u32 unk4;
    struct MenuItem *unk8; // Array of menu choices??
    u8 fillC[0x30 - 0xC];
    s16 menuIndex;
    u8 fill32[0x54 - 0x32];

    u32 unk54;
    u8 fill58[0xA4 - 0x58];

    u32 unkA4;
    u32 unkA8;
    u8 fillAC[0x144 - 0xAC];
    struct UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u32 currMenuChoice;
};

EWRAM_DATA struct MainMenu *gMainMenu;
EWRAM_DATA struct unkStruct_203B34C *gUnknown_203B34C;
EWRAM_DATA u32 gUnknown_203B350;
EWRAM_DATA u32 gUnknown_203B354; // unused everywhere else except here..


extern void sub_8094C14(void);
extern void sub_8099690(u32);
extern void sub_8036FDC(s32);
extern void CreateFriendRescueMenu(void);
extern void CreateWonderMailMenu(void);
extern void CreateRescuePasswordMenu(u32);
extern void CreateSaveMenu(u32);
extern u32 UpdateMainMenu(void);
extern s32 UpdateFriendRescueMenu(void);
extern s32 UpdateWonderMailMenu(void);
extern s32 UpdateRescuePasswordMenu(void);
extern s32 sub_80383D4(void);
extern s32 UpdateSaveMenu(void);
extern void sub_80370D4(void);
extern void CleanFriendRescueMenu(void);
extern void CleanWonderMailMenu(void);
extern void CleanRescuePasswordMenu(void);
extern void sub_80383A8(void);
extern void CleanSaveMenu(void);
extern u8 sub_8012FD8(u32 *);
extern void sub_8013114(u32 *, s32 *);
extern u8 sub_803D0D8();
extern s32 sub_8011C34();
extern s32 sub_8095324(u32);
extern void sub_8012D60(struct unkStruct_Menu *, const struct MenuItem *, u32, u32, u32, u32);
extern void sub_8012E04(struct unkStruct_Menu *, const struct MenuItem *, u32, u32, u32, u32);

void CleanMainMenu(void);
void DrawMainMenu(void);
s32 sub_8035DB4(u32);
void sub_803623C(void);
bool8 SetMainMenuText();
void SetMainMenuItems();
void sub_8035DA0(void);

static const char NewGame_80E5A20[];
static const char AdventureLog_80E5A10[];
static const char WonderMail_80E5A54[];
static const char Continue_80E5AF0[];
static const char DeleteSaveData_80E5ADC[];
static const char FriendRescue_80E5ACC[];
static const char TradeItems_80E5AC0[];
static const char ReviveTeam_80E5C0C[];
static const char SendItems_80E5C90[];
static const char ReceiveItems_80E5C80[];
static const char AwaitingRescue_80E5B7C[];
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

const struct UnkTextStruct2 gUnknown_80E59A8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const char main_menu_fill[] = "pksdir0";

const struct UnkTextStruct2 gUnknown_80E59C8 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x00, 0x00, 0x00, 0x00,
   0x00, 0x00,
   0x00, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E59E0 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E59F8[] =
{
    {NewGame_80E5A20, MENU_NEW_GAME},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {NULL, 0xffdd},
};

const char AdventureLog_80E5A10[] = "Adventure Log";
const char NewGame_80E5A20[] = "New Game";

const struct UnkTextStruct2 gUnknown_80E5A29 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x02,
   0x02, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5A44[] =
{
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const char WonderMail_80E5A54[] = "Wonder Mail";

const struct UnkTextStruct2 gUnknown_80E5A60 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct UnkTextStruct2 gUnknown_80E5A78 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0B, 0x09,
   0x09, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5A90[] = 
{
    {Continue_80E5AF0, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};

static const char TradeItems_80E5AC0[] = "Trade Items";
static const char FriendRescue_80E5ACC[] = "Friend Rescue";
static const char DeleteSaveData_80E5ADC[] = "Delete Save Data";
static const char Continue_80E5AF0[] = "Continue";

const struct MenuItem gUnknown_80E5AFC[] =
{
    {Continue_80E5AF0, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5B34 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5B4C[] =
{
    {AwaitingRescue_80E5B7C, MENU_AWAITING_RESCUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};
const char AwaitingRescue_80E5B7C[] = "Awaiting Rescue";

const struct MenuItem gUnknown_80E5B8C[] = 
{
    {AwaitingRescue_80E5B7C, MENU_AWAITING_RESCUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5BC4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x08,
   0x08, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5BDC[] =
{
    {ReviveTeam_80E5C0C, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {NULL, 0xffdd},
};
const char ReviveTeam_80E5C0C[] = "Revive Team";

const struct MenuItem gUnknown_80E5C18[] =
{
    {ReviveTeam_80E5C0C, MENU_CONTINUE},
    {DeleteSaveData_80E5ADC, MENU_DELETE_SAVE_PROMPT},
    {AdventureLog_80E5A10, MENU_ADVENTURE_LOG},
    {FriendRescue_80E5ACC, MENU_FRIEND_RESCUE},
    {TradeItems_80E5AC0, MENU_TRADE_ITEMS},
    {WonderMail_80E5A54, MENU_WONDER_MAIL},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5C50 = { 
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x02, 0x00,
   0x0A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5C68[] = 
{
    {SendItems_80E5C90, MENU_SEND_ITEMS},
    {ReceiveItems_80E5C80, MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

static const char ReceiveItems_80E5C80[] = "Receive Items";
static const char SendItems_80E5C90[] = "Send Items";

const struct MenuItem gUnknown_80E5C9C[] = 
{
    {SendItems_80E5C90, -1},
    {ReceiveItems_80E5C80, MENU_RECEIVE_ITEMS},
    {NULL, 0xffdd},
};

const struct UnkTextStruct2 gUnknown_80E5CB4 = {
   0x00, 0x00, 0x00, 0x00,
   0x03, 0x00, 0x00, 0x00,
   0x02, 0x00, 0x0F, 0x00,
   0x1A, 0x03,
   0x03, 0x00,
   NULL
};

const struct MenuItem gUnknown_80E5CCC[] = 
{
    {sUnknown_80E5CE8, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5CE4[] = "  ";
static const u8 sUnknown_80E5CE8[] = "Start an entirely new adventure.";

const struct MenuItem gUnknown_80E5D0C[] = 
{
    {sUnknown_80E5D24, 0xffde},
    {sUnknown_80E5CE4, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D24[] = "Check your career as an adventurer.";

const struct MenuItem gUnknown_80E5D48[] = 
{
    {sUnknown_80E5D88, 0xffde},
    {sUnknown_80E5D60, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5D60[] = _("It won{APOSTROPHE}t be in the release version.");
static const u8 sUnknown_80E5D88[] = "This is the Debug Mode.";

const struct MenuItem gUnknown_80E5DA0[] = 
{
    {sUnknown_80E5DCC, 0xffde},
    {sUnknown_80E5DB8, 0xffde},
    {NULL, 0xffdd},
};

static const u8 sUnknown_80E5DB8[] = "you last saved.  ";
static const u8 sUnknown_80E5DCC[] = "Resume your adventure from where";

const struct MenuItem gUnknown_80E5DF0[] = {
    {sUnknown_80E5E34, 0xFFDE},
    {sUnknown_80E5E08, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5E08[] = _("#C2Beware#R! This will delete it forever!");
static const u8 sUnknown_80E5E34[] = "This will delete your saved game data.";

const struct MenuItem gUnknown_80E5E5C[] = {
    {sUnknown_80E5EA0, 0xFFDE},
    {sUnknown_80E5E74, 0xFFDE},
    {0, 0xFFDD}
};

ALIGNED(4) static const u8 sUnknown_80E5E74[] = _("passwords{COMMA} friends may rescue each other.");
static const u8 sUnknown_80E5EA0[] = "Using a Game Link cable or";

const struct MenuItem gUnknown_80E5EBC[] = {
    {sUnknown_80E5EF8, 0xFFDE},
    {sUnknown_80E5ED4, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5ED4[] = "trade stored items with a friend.";
ALIGNED(4) static const u8 sUnknown_80E5EF8[] = _("Using a Game Link cable{COMMA} you can");

const struct MenuItem gUnknown_80E5F1C[] = {
    {sUnknown_80E5F58, 0xFFDE},
    {sUnknown_80E5F34, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F34[] = "You can give up waiting for rescue.";
static const u8 sUnknown_80E5F58[] = "You are awaiting rescue by a friend.";

const struct MenuItem gUnknown_80E5F80[] = {
    {sUnknown_80E5FB0, 0xFFDE},
    {sUnknown_80E5F98, 0xFFDE},
    {0, 0xFFDD}
};

static const u8 sUnknown_80E5F98[] = "receive Wonder Mail.";
ALIGNED(4) static const u8 sUnknown_80E5FB0[] = _("Using passwords{COMMA} you can");

const struct MenuItem gUnknown_80E5FCC[] = {
    {sUnknown_80E6008, 0xFFDE},
    {sUnknown_80E5FE4, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E5FE4[] = "receive teams from your friends.";
ALIGNED(4) static const u8 sUnknown_80E6008[] = _("Using the Dual Slot function{COMMA} you can");

const struct MenuItem gUnknown_80E6030[] = {
    {sUnknown_80E6070, 0xFFDE},
    {sUnknown_80E6048, 0xFFDE},
    {NULL, 0xFFDD}
};

static const u8 sUnknown_80E6048[] = "go on an adventure to unknown worlds.";
ALIGNED(4) static const u8 sUnknown_80E6070[] = _("Using wireless communication{COMMA} you can");
static const u8 sMainMenu_fill0[] = "pksdir0";

void InitMainMenu(void)
{
  if (gMainMenu == NULL) {
    gMainMenu = MemoryAlloc(sizeof(struct MainMenu),8);
    MemoryFill8((u8 *)gMainMenu, 0, sizeof(struct MainMenu));
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
            sub_8094C14();
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
  s32 iVar1;
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
        iVar1 = UpdateTradeItemsMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (iVar1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_FRIEND_RESCUE:
        iVar1 = UpdateFriendRescueMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (iVar1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_WONDER_MAIL:
        iVar1 = UpdateWonderMailMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (iVar1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_DUAL_SLOT:
        iVar1 = UpdateDualSlotMenu();
        nextMenu = MENU_MAIN_SCREEN;
        if (iVar1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case MENU_WIRELESS_COMMS:
        iVar1 = UpdateWirelessCommsMenu();
        nextMenu = 5;
        if ((iVar1 != 3) && (nextMenu = MENU_NO_SCREEN_CHANGE, iVar1 == 2)) {
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
void sub_8035C00(struct MainMenuSub *param)
{
    gMainMenu->sub = *param;
}

// Unused
struct MainMenuSub *sub_8035C10(void)
{
   return &gMainMenu->sub;
}

void sub_8035C1C(void)
{
    gMainMenu->sub.unk2E = 0;
    gMainMenu->sub.unk2C = 1;
    gMainMenu->sub.unk2D = 0;
}

void
SetMenuItems(struct unkStruct_Menu *param_1, struct UnkTextStruct2 *unkData, int param_3, const struct UnkTextStruct2 *param_4, const struct MenuItem *param_5, char param_6 ,u32 param_7, u32 unused_8)
{
  unkData[param_3] = *param_4;
  ResetUnusedInputStruct();
  sub_800641C(unkData,1,1);
  if (param_6 != '\0') {
       sub_8012D60(&param_1[param_3],param_5,0,0,param_7,param_3);
  }
  else {
       sub_8012E04(&param_1[param_3],param_5,0,0,0,param_3);
  }
  param_1[param_3].unk4C = 1;
}

void sub_8035CC0(struct UnkTextStruct2 *dataArray, u32 index)
{
    sub_8006518(dataArray);
    dataArray[index] = gUnknown_80E59A8;
    ResetUnusedInputStruct();
    sub_800641C(dataArray, 1, 1);
}

NAKED
void sub_8035CF4(void * Menu, u32 index, u8 r2)
{
	asm_unified("\tpush {lr}\n"
	"\tadds r3, r0, 0\n"
	"\tlsls r0, r1, 2\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 4\n"
	"\tadds r0, r3\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x4C\n"
	"\tstrb r2, [r1]\n"
	"\tadds r2, r0, 0\n"
	"\tadds r2, 0x4D\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r2]\n"
	"\tsubs r1, 0x2\n"
	"\tstr r1, [r0, 0x48]\n"
	"\tbl sub_8012EBC\n"
	"\tpop {r0}\n"
	"\tbx r0");
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

struct MainMenu *GetMainMenu(void)
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
NAKED
void sub_8035D80(void *r0)
{
    asm_unified(
	"\tldr r1, _08035D90\n"
	"\tldr r2, [r1]\n"
	"\tldr r1, [r0, 0x4]\n"
	"\tldr r0, [r0]\n"
	"\tstr r0, [r2, 0x30]\n"
	"\tstr r1, [r2, 0x34]\n"
	"\tbx lr\n"
	"\t.align 2, 0\n"
"_08035D90: .4byte gMainMenu");
}

u8 *sub_8035D94(void)
{
    return &gMainMenu->unk30;
}


void sub_8035DA0(void)
{
    gMainMenu->unk30 = 0;
    gMainMenu->unk34 = 0;
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
    s32 iVar3;

    if(gUnknown_203B34C == NULL)
    {
        gUnknown_203B34C = MemoryAlloc(sizeof(struct unkStruct_203B34C), 8);
        MemoryFill8((u8 *)gUnknown_203B34C, 0, sizeof(struct unkStruct_203B34C));
    }

    for(iVar3 = 0; iVar3 < 4; iVar3++)
    {
        gUnknown_203B34C->unk144[iVar3] = gUnknown_80E59C8;
    }

    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B34C->unk144, 1, 1);
    SetMainMenuItems();
    gUnknown_203B34C->currMenuChoice = -1;

    if(SetMainMenuText())
    {
        sub_8035CF4(&gUnknown_203B34C->unk4,2,0);
    }

    sub_8035CF4(&gUnknown_203B34C->unk4,0,1);
    gUnknown_203B34C->unk0 = 1;
}

void CleanMainMenu(void)
{
    ResetUnusedInputStruct();
    sub_800641C(NULL, 1, 1);
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
            sub_8012FD8(&gUnknown_203B34C->unkA4);
            if(!sub_8012FD8(&gUnknown_203B34C->unk4))
                sub_8013114(&gUnknown_203B34C->unk4, &nextMenu);

            if(SetMainMenuText())
            {
                sub_8035CF4(&gUnknown_203B34C->unk4, 0, 1);
                sub_8035CF4(&gUnknown_203B34C->unk4, 2, 0);
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
                    sub_8035CF4(&gUnknown_203B34C->unk4, 0, 1);
                    sub_8035CF4(&gUnknown_203B34C->unk4, 2, 0);
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
            if(!sub_8012FD8(&gUnknown_203B34C->unk54))
                sub_8013114(&gUnknown_203B34C->unk54, &nextMenu);
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
  struct MenuItem *preload;

 // Have to load the pointer before the index
  preload = gUnknown_203B34C->unk8;
  menuChoice = preload[gUnknown_203B34C->menuIndex].menuAction; // chosen menu action?
  if (gUnknown_203B34C->currMenuChoice == menuChoice) {
    return FALSE;
  }

  gUnknown_203B34C->currMenuChoice = menuChoice;
  sub_8035CC0(gUnknown_203B34C->unk144,2);
  sub_8035CC0(gUnknown_203B34C->unk144,3);
  switch(menuChoice) {
    case MENU_WIRELESS_COMMS:
        // Using wireless communications, you can go on an adventure to unknown worlds.
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E6030,0,0,0);
        break;
    case MENU_WONDER_MAIL:
        // Using passwords, you can receive Wonder Mail
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F80,0,0,0);
        break;
    case MENU_AWAITING_RESCUE:
        // You are awaiting resuce by a friend
        // You can give up waiting for rescue
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5F1C,0,0,0);
        break;
    case MENU_NEW_GAME:
        // Start an entirely new adventure
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5CCC,0,0,0);
        break;
    case MENU_CONTINUE:
        // Resume your adventure from where you last saved
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DA0,0,0,0);
        break;
    case MENU_DELETE_SAVE_PROMPT:
        // This will delete your saved game data.
        // Beware! This will delete it forever
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5DF0,0,0,0);
        break;
    case MENU_ADVENTURE_LOG:
        // Check your career as an adventurer
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D0C,0,0,0);
        break;
    case MENU_FRIEND_RESCUE:
        // Using a Game Link cable or passwords, friends may rescue each other
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5E5C,0,0,0);
        break;
    case MENU_TRADE_ITEMS:
        // Using a Game Link cable you can trade stored items with a friend
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5EBC,0,0,0);
        break;
    case MENU_DUAL_SLOT:
        // Using Dual Slot function, you can receive teams from your friends
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5FCC,0,0,0);
        break;
    case MENU_DEBUG:
        // This is the Debug Mode.
        // It won't be in the release version
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,2,&gUnknown_80E5CB4,gUnknown_80E5D48,0,0,0);
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
    sub_8035CF4(&gUnknown_203B34C->unk4,2,0);
  }
  sub_8035CF4(&gUnknown_203B34C->unk4,0,1);
}

void SetMainMenuItems(void)
{ 
  if (sub_8011C34() != -1) {
    if (sub_8095324(1) == 0) {
      if (sub_8095324(7) != 0) {
        if (sub_803D0D8() != 0) {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
            // Wonder Mail
          SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5C18,1,gUnknown_203B350,1);
        }
        else {
            // Revive Team
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5BC4,gUnknown_80E5BDC,1,gUnknown_203B350,1);
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
          SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5AFC,1,gUnknown_203B350,1);
        }
        else {
            // Continue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
          SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A60,gUnknown_80E5A90,1,gUnknown_203B350,1);
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
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5A78,gUnknown_80E5B8C,1,gUnknown_203B350,1);
      }
      else {
            // Awaiting Rescue
            // Delete Save Data
            // Adventure Log
            // Friend Rescue
            // Trade Items
        SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E5B34,gUnknown_80E5B4C,1,gUnknown_203B350,1);
      }
    }
  }
  else
  {
      // New Game
      // Adventure Log
    SetMenuItems((struct unkStruct_Menu *)&gUnknown_203B34C->unk4,gUnknown_203B34C->unk144,0,&gUnknown_80E59E0,gUnknown_80E59F8,1,gUnknown_203B350,1);
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
