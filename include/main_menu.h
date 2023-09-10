#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

#include "menu.h"
#include "text.h"

enum MainMenuScreens
{
    MENU_MAIN_SCREEN = 1,
    MENU_NEW_GAME = 3,
    MENU_AWAITING_RESCUE = 6,
    MENU_CONTINUE = 7, // used by Revive Team/Continue
    MENU_DELETE_SAVE_PROMPT,
    MENU_DELETE_SAVE_CONFIRM,
    MENU_ADVENTURE_LOG = 10,
    MENU_FRIEND_RESCUE,
    MENU_TRADE_ITEMS,
    MENU_WONDER_MAIL,
    MENU_DUAL_SLOT,
    MENU_WIRELESS_COMMS,
    MENU_DEBUG = 16,
    MENU_SEND_ITEMS,
    MENU_RECEIVE_ITEMS,
    MENU_COMMUNICATION_1 = 19,
    MENU_COMMUNICATION_2,
    // NOTE: 0x1B - 0x22 used by Rescue Password Menu
    MENU_DISPLAY_RESCUE_PASSWORD = 33,
    MENU_RESCUE_PASSWORD_ENTRY,
    MENU_DELETE_SAVE = 46,
    MENU_DEBUG_DUNGEON,
    MENU_DEBUG_FIELD,
    MENU_DEBUG_FIELD_MAP,
    MENU_DEBUG_FIELD_SCRIPT,
    MENU_DEBUG_DEBUG_MENU,
    MENU_DEBUG_UNKNOWN_1,
    MENU_NO_SCREEN_CHANGE = 65500
};

// size: 0x8
typedef struct unkStruct_8035D94
{
    union {
        u8 itemIndex_u8;
        u32 itemIndex_u32;
    } itemIndex;
    s32 numItems;
} unkStruct_8035D94;

// size: 0x4
typedef struct MainMenuSub
{
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
} MainMenuSub;

// size: 0x40
typedef struct MainMenu
{
    /* 0x0 */ s32 currMenu;
    /* 0x4 */ s32 nextMenu;
    /* 0x8 */ s32 lastMenu;
    u8 padding[0x20];
    /* 0x2C */ MainMenuSub sub;
    unkStruct_8035D94 unk30;
    s16 unk38;
    u8 unk3A;
    u8 unk3B;
    s32 unk3C;
} MainMenu;

void CleanUpMenu(void);
void DeleteMainMenu(void);
MainMenu *GetMainMenu(void);
void InitMainMenu(void);
void SetMenuItems(MenuStruct *, UnkTextStruct2 *, s32, const UnkTextStruct2 *, const MenuItem *, u8, u32, u32);
void SetUpMenu(void);
s32 UpdateMenu(void);

void sub_8035CC0(UnkTextStruct2 *, u32);
void sub_8035CF4(MenuStruct*, u32, bool8);
s16 sub_8035D3C(void);
s32 sub_8035D74(void);
unkStruct_8035D94 *sub_8035D94(void);
void sub_8035DA0(void);
bool8 sub_80363E0(void);

#endif // GUARD_MAIN_MENU_H
