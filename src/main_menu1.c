#include "global.h"
#include "adventure_log_menu.h"
#include "code_8098BDC.h"
#include "constants/item.h"
#include "constants/main_menu.h"
#include "debug_menu1.h"
#include "ds_menus.h"
#include "friend_rescue.h"
#include "game_options.h"
#include "load_screen.h"
#include "main_menu1.h"
#include "main_menu2.h"
#include "memory.h"
#include "menu_input.h"
#include "other_menus1.h"
#include "rescue_password_menu.h"
#include "save_menu.h"
#include "text1.h"
#include "text2.h"
#include "trade_items_menu.h"
#include "unk_menu_203B360.h"
#include "wonder_mail_main_menu.h"

// NOTE: 0x13 and 0x14
// Communication Screen?
// Got Communication warning when I wrote them to the struct

// NOTE: 0x29, 0x2A, 0x2B, 0x2C
// Triggers a save

// NOTE: 0x2D
// Triggers a save and then goes to 0x13 (comms warning)

// NOTE: 0x2E
// Deletes the Save

static EWRAM_DATA_2 MainMenu1Work *sMainMenu = {0};

#include "data/main_menu1.h"

static s32 sub_8035DB4(u32 currMenu);

void InitMainMenu(void)
{
    if (sMainMenu == NULL) {
        sMainMenu = MemoryAlloc(sizeof(MainMenu1Work), 8);
        MemoryFill8((u8 *)sMainMenu, 0, sizeof(MainMenu1Work));
    }

    sMainMenu->currMenu = MENU_NO_SCREEN_CHANGE;
    sMainMenu->nextMenu = MENU_MAIN_SCREEN;
    sMainMenu->lastMenu = MENU_MAIN_SCREEN;
    sMainMenu->unk38 = -1;
    sMainMenu->unk3C = -1;
    sMainMenu->sub.unk2E = 0;
    sMainMenu->sub.unk2C = 1;
    sMainMenu->sub.unk2D = 0;
    sub_8035DA0();
    sMainMenu->unk3A = 0;
}

void DeleteMainMenu(void)
{
    if (sMainMenu) {
        MemoryFree(sMainMenu);
        sMainMenu = NULL;
    }
}

void SetUpMenu(void)
{
    if (sMainMenu->currMenu == sMainMenu->nextMenu)
        return;

    switch (sMainMenu->nextMenu) {
        case MENU_MAIN_SCREEN:
            SetWindowBGColor();
            sub_8099690(0);
            DrawMainMenu();
            break;
        case MENU_AWAITING_RESCUE:
        case MENU_CONTINUE:
        case MENU_DELETE_SAVE_PROMPT:
        case MENU_DELETE_SAVE_CONFIRM:
            CreateLoadScreen(sMainMenu->nextMenu);
            break;
        case MENU_TRADE_ITEMS:
            CreateTradeItemsMenu();
            break;
        case MENU_COMMUNICATION_1:
        case MENU_COMMUNICATION_2:
            sub_8036FDC(sub_8035DB4(sMainMenu->nextMenu));
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
            CreateRescuePasswordMenu(sMainMenu->nextMenu);
            break;
        case MENU_ADVENTURE_LOG:
            CreateAdventureLogMenu();
            break;
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case MENU_DELETE_SAVE:
            CreateSaveMenu(sMainMenu->nextMenu);
            break;
        case MENU_DEBUG:
            CreateDebugMenu();
            break;
    }

    sMainMenu->currMenu = sMainMenu->nextMenu;
}

s32 UpdateMenu(void)
{
    s32 nextMenu1;
    s32 nextMenu;

    nextMenu = MENU_NO_SCREEN_CHANGE;

    switch (sMainMenu->nextMenu) {
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
            if (nextMenu1 != 3)
                nextMenu = MENU_NO_SCREEN_CHANGE;
            break;
        case MENU_FRIEND_RESCUE:
            nextMenu1 = UpdateFriendRescueMenu();
            nextMenu = MENU_MAIN_SCREEN;
            if (nextMenu1 != 3)
                nextMenu = MENU_NO_SCREEN_CHANGE;
            break;
        case MENU_WONDER_MAIL:
            nextMenu1 = UpdateWonderMailMenu();
            nextMenu = MENU_MAIN_SCREEN;
            if (nextMenu1 != 3)
                nextMenu = MENU_NO_SCREEN_CHANGE;
            break;
        case MENU_DUAL_SLOT:
            nextMenu1 = UpdateDualSlotMenu();
            nextMenu = MENU_MAIN_SCREEN;
            if (nextMenu1 != 3)
                nextMenu = MENU_NO_SCREEN_CHANGE;
            break;
        case MENU_WIRELESS_COMMS:
            nextMenu1 = UpdateWirelessCommsMenu();
            nextMenu = 5;
            if (nextMenu1 != 3) {
                nextMenu = MENU_NO_SCREEN_CHANGE;
                if (nextMenu1 == 2)
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
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case MENU_DELETE_SAVE:
            nextMenu = UpdateSaveMenu();
            break;
        case MENU_DEBUG:
            nextMenu = UpdateDebugMenu();
            break;
    }

    if (nextMenu != MENU_NO_SCREEN_CHANGE)
        sMainMenu->nextMenu = nextMenu;

    return nextMenu;
}

void CleanUpMenu(void)
{
    if (sMainMenu->lastMenu == sMainMenu->nextMenu)
        return;

    switch (sMainMenu->lastMenu) {
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
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2D:
        case MENU_DELETE_SAVE:
            CleanSaveMenu();
            break;
        case MENU_DEBUG:
            DeleteDebugMenu();
            break;
    }

    sMainMenu->lastMenu = sMainMenu->nextMenu;
}

UNUSED static void sub_8035C00(MainMenuSub *a0)
{
    sMainMenu->sub = *a0;
}

UNUSED static MainMenuSub *sub_8035C10(void)
{
   return &sMainMenu->sub;
}

void sub_8035C1C(void)
{
    sMainMenu->sub.unk2E = 0;
    sMainMenu->sub.unk2C = 1;
    sMainMenu->sub.unk2D = 0;
}

void SetMenuItems(MenuStruct *a0, UnkTextStruct2 *a1, s32 index, const UnkTextStruct2 *a3, const MenuItem *menuItems, bool8 a5, u32 menuAction, u32 unused)
{
    a1[index] = *a3;
    ResetUnusedInputStruct();
    sub_800641C(a1, TRUE, TRUE);

    if (a5)
        sub_8012D60(&a0[index], menuItems, 0, 0, menuAction, index);
    else
        sub_8012E04(&a0[index], menuItems, 0, 0, 0, index);

    a0[index].unk4C = TRUE;
}

void sub_8035CC0(UnkTextStruct2 *dataArray, u32 index)
{
    sub_8006518(dataArray);
    dataArray[index] = sUnknown_80E59A8;
    ResetUnusedInputStruct();
    sub_800641C(dataArray, TRUE, TRUE);
}

void sub_8035CF4(MenuStruct *menu, u32 index, bool8 a2)
{
    menu[index].unk4C = a2;
    menu[index].unk4D = 1;
    menu[index].menuAction = -1;
    sub_8012EBC(&menu[index]);
}

void sub_8035D1C(void)
{
    sMainMenu->unk38 = -1;
}

UNUSED static void sub_8035D30(s32 a0)
{
    sMainMenu->unk38 = a0;
}

s16 sub_8035D3C(void)
{
    return sMainMenu->unk38;
}

MainMenu1Work *GetMainMenu(void)
{
    return sMainMenu;
}

UNUSED static void sub_8035D58(void)
{
    sMainMenu->unk3C = -1;
}

UNUSED static void sub_8035D68(s32 a0)
{
    sMainMenu->unk3C = a0;
}

s32 sub_8035D74(void)
{
    return sMainMenu->unk3C;
}

UNUSED static void sub_8035D80(unkStruct_8035D94 *item)
{
#ifndef NONMATCHING
    register u32 numItem asm("r1");
#else
    u32 numItem;
#endif

    u32 itemIndex;
    MainMenu1Work *preload;

    preload = sMainMenu;
    numItem = item->numItems;
    itemIndex = item->itemIndex.itemIndex_u32;
    preload->unk30.itemIndex.itemIndex_u32 = itemIndex;
    preload->unk30.numItems = numItem;
}

unkStruct_8035D94 *sub_8035D94(void)
{
    return &sMainMenu->unk30;
}

void sub_8035DA0(void)
{
    sMainMenu->unk30.itemIndex.itemIndex_u8 = ITEM_NOTHING;
    sMainMenu->unk30.numItems = 0;
}

static s32 sub_8035DB4(u32 currMenu)
{
    s32 returnVar = 8;

    switch (currMenu) {
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
        case 0x1A:
            returnVar = 7;
            break;
    }
    return returnVar;
}