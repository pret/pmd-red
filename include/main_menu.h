#ifndef GUARD_MAIN_MENU_H
#define GUARD_MAIN_MENU_H

enum MainMenuScreens
{
    MENU_MAIN_SCREEN = 1,
    MENU_NEW_GAME = 3,
    MENU_AWAITING_RESCUE = 6,
    MENU_CONTINUE = 7,
    MENU_DELETE_SAVE_PROMPT,
    MENU_DELETE_SAVE_CONFIRM,
    MENU_ADVENTURE_LOG = 10,
    MENU_FRIEND_RESCUE,
    MENU_TRADE_ITEMS,
    MENU_WONDER_MAIL,
    MENU_DUAL_SLOT,
    MENU_WIRELESS_COMMS,
    MENU_DEBUG = 16,
    MENU_COMMUNICATION_1 = 19,
    MENU_COMMUNICATION_2,
    MENU_DISPLAY_RESCUE_PASSWORD = 33,
    MENU_RESCUE_PASSWORD_ENTRY,
    MENU_DELETE_SAVE = 46,
    MENU_DEBUG_DUNGEON,
    MENU_DEBUG_FIELD,
    MENU_DEBUG_FIELD_MAP,
    MENU_DEBUG_FIELD_SCRIPT,
    MENU_DEBUG_DEBUG_MENU,
    MENU_DEBUG_UNKNOWN_1,
    MENU_NO_SCREEN_CHANGE = 0xffdc
};

struct MainMenuSub
{
    u8 unk2C;
    u8 unk2D;
    u8 unk2E;
};

struct MainMenu
{
    /* 0x0 */ s32 currMenu;
    /* 0x4 */ s32 nextMenu;
    /* 0x8 */ s32 lastMenu;
    u8 padding[0x20];
    /* 0x2C */ struct MainMenuSub sub;
    u8 unk30;
    u32 unk34;
    s16 unk38;
    u8 unk3A;
    u8 unk3B;
    s32 unk3C;
};


#endif // GUARD_MAIN_MENU_H
