#include "global.h"
#include "debug_menu.h"
#include "main_menu.h"
#include "adventure_log.h"
#include "input.h"
#include "menu.h"
#include "memory.h"
#include "text.h"

// NOTE: 0x13 and 0x14 
// Communication Screen?
// Got Communication warning when I wrote them to the struct

// NOTE: 0x29, 0x2A, 0x2B, 0x2C
// Triggers a save 

// NOTE: 0x2D
// Triggers a save and then goes to 0x13 (comms warning)

// NOTE: 0x2E
// Deletes the Save


extern struct MainMenu *gMainMenu;
void sub_8035DA0(void);

extern void sub_8094C14(void);
extern void sub_8099690(u32);
extern void DrawMainMenu(void);
extern void CreateTradeItemsMenu(void);
extern void sub_8036FDC(s32);
extern void CreateWirelessCommsMenu(void);
extern void CreateFriendRescueMenu(void);
extern void CreateDualSlotMenu(void);
extern void CreateWonderMailMenu(void);
extern void CreateLoadScreen(u32);
extern s32 sub_8035DB4(u32);
extern void CreateRescuePasswordMenu(u32);
extern void CreateSaveMenu(u32);
extern s32 UpdateMainMenu(void);
extern s32 UpdateLoadScreenMenu(void);
extern s32 UpdateTradeItemsMenu(void);
extern s32 UpdateFriendRescueMenu(void);
extern s32 UpdateWonderMailMenu(void);
extern s32 UpdateDualSlotMenu(void);
extern s32 UpdateWirelessCommsMenu(void);
extern s32 UpdateRescuePasswordMenu(void);
extern s32 sub_80383D4(void);
extern s32 UpdateSaveMenu(void);

extern void CleanMainMenu(void);
extern void CleanLoadScreen(void);
extern void CleanTradeItemsMenu(void);
extern void sub_80370D4(void);
extern void CleanFriendRescueMenu(void);
extern void CleanWonderMailMenu(void);
extern void CleanDualSlotMenu(void);
extern void CleanWirelessCommsMenu(void);
extern void CleanRescuePasswordMenu(void);
extern void sub_80383A8(void);
extern void CleanSaveMenu(void);

struct unkSubStruct
{
    u32 unk0;
    u32 unk4;
};

struct unkStruct_203B34C
{
    // size: 0x1A8
    u32 unk0;
    u32 unk4;
    struct unkSubStruct *unk8; // Array of menu choices??
    u8 fillC[0x30 - 0xC];
    s16 menuIndex;
    u8 fill32[0x144 - 0x32];
    struct UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u32 currMenuChoice;
};

extern struct unkStruct_203B34C *gUnknown_203B34C;

extern struct MainMenu *gMainMenu;
extern struct UnkTextStruct2 gUnknown_80E59A8;
extern struct UnkTextStruct2 gUnknown_80E59C8;

extern bool8 SetMainMenuText();
extern void SetMainMenuItems();

struct unkStruct_Menu
{
    // size 0x50;
    u8 fil0[0x4C];
    u8 unk4C;
    u8 fill4D[0x50 - 0x4D];
};

extern void sub_8012D60(struct unkStruct_Menu *, const struct MenuItem *, u32, u32, u32, u32);
extern void sub_8012E04(struct unkStruct_Menu *, const struct MenuItem *, u32, u32, u32, u32);


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

void sub_8035D58(void)
{
    gMainMenu->unk3C = -1;
}

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

