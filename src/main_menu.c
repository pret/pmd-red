#include "global.h"
#include "debug_menu.h"
#include "main_menu.h"

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
extern void* MemoryAlloc(u32 a, u32 b);
extern void MemoryFill8(u8 *dest, u8 value, s32 size);
void sub_8035DA0(void);
extern void MemoryFree(void *);

extern void sub_8094C14(void);
extern void sub_8099690(u32);
extern void DrawMainMenu(void);
extern void CreateTradeItemsMenu(void);
extern void sub_8036FDC(s32);
extern void sub_803A1E4(void);
extern void CreateFriendRescueMenu(void);
extern void sub_803A1D8(void);
extern void CreateWonderMailMenu(void);
extern void CreateAdventureLogMenu(void);
extern void CreateLoadScreen(u32);
extern s32 sub_8035DB4(u32);
extern void CreateRescuePasswordMenu(u32);
extern void sub_803850C(u32);
extern s32 UpdateMainMenu(void);
extern s32 sub_803941C(void);
extern s32 UpdateTradeItemsMenu(void);
extern s32 UpdateFriendRescueMenu(void);
extern s32 UpdateWonderMailMenu(void);
extern s32 sub_803A1DC(void);
extern s32 sub_803A1E8(void);
extern s32 UpdateRescuePasswordMenu(void);
extern s32 UpdateAdventureLogMenu(void);
extern s32 sub_80383D4(void);
extern s32 sub_8038630(void);

extern void CleanMainMenu(void);
extern void CleanLoadScreen(void);
extern void CleanTradeItemsMenu(void);
extern void sub_80370D4(void);
extern void CleanFriendRescueMenu(void);
extern void CleanWonderMailMenu(void);
extern void nullsub_55(void);
extern void sub_803A1EC(void);
extern void CleanRescuePasswordMenu(void);
extern void CleanAdventureLogMenu(void);
extern void sub_80383A8(void);
extern void sub_8038604(void);

void InitMainMenu(void)
{
  if (gMainMenu == NULL) {
    gMainMenu = MemoryAlloc(sizeof(struct MainMenu),8);
    MemoryFill8((u8 *)gMainMenu, 0, sizeof(struct MainMenu));
  }
  gMainMenu->currMenu = 0xffdc;
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
        case 6:
        case MENU_CONTINUE:
        case MENU_DELETE_SAVE_PROMPT:
        case 9:
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
        case 0xe:
            sub_803A1D8();
            break;
        case 0xf:
            sub_803A1E4();
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
        case 0x2e:
            sub_803850C(gMainMenu->nextMenu);
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
    case 6:
    case MENU_CONTINUE:
    case MENU_DELETE_SAVE_PROMPT:
    case 9:
        nextMenu = sub_803941C();
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
    case 0xe:
        iVar1 = sub_803A1DC();
        nextMenu = MENU_MAIN_SCREEN;
        if (iVar1 != 3) {
            nextMenu = MENU_NO_SCREEN_CHANGE;
        }
        break;
    case 0xf:
        iVar1 = sub_803A1E8();
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
    case 0x2e:
        nextMenu = sub_8038630();
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
    case 6:
    case MENU_CONTINUE:
    case MENU_DELETE_SAVE_PROMPT:
    case 9:
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
    case 0xe:
      nullsub_55();
      break;
    case 0xf:
      sub_803A1EC();
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
    case 0x2e:
      sub_8038604();
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
