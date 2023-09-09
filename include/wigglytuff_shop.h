#ifndef GUARD_WIGGLYTUFF_SHOP_H
#define GUARD_WIGGLYTUFF_SHOP_H

#include "file_system.h"
#include "menu.h"
#include "text.h"

enum WigglytuffStates
{
    WIGGLYTUFF_INIT = 0,
    WIGGLYTUFF_MAIN_MENU = 1,
    WIGGLYTUFF_INFO = 2,
    WIGGLYTUFF_PRE_EXIT = 3,
    WIGGLYTUFF_EXIT = 4,
    WIGGLYTUFF_CANT_ADD_FRIEND_AREA = 5,
    NO_MONEY = 6,
    FRIEND_AREA_SELECT_BUY = 7,
    FRIEND_AREA_SELECT_BUY_AGAIN = 8,
    WIGGLYTUFF_UNK9 = 9,
    WIGGLYTUFF_UNKA = 10,
    WIGGLYTUFF_UNKB = 11,
    CONFIRM_BUY_FRIEND_AREA = 12,
    WIGGLYTUFF_UNKD = 13,
    WIGGLYTUFF_UNKE = 14,
    FRIEND_AREA_UNLOCKED = 15,
    FRIEND_AREA_INFO = 16,
    BUY_FRIEND_AREA = 17,
    NO_FRIEND_AREAS = 18,
    NOT_ENOUGH_MONEY = 19,
    WIGGLYTUFF_CHECK = 20,
    WIGGLYTUFF_CHECK_AGAIN = 21,
    WIGGLYTUFF_UNK16 = 22,
    WIGGLYTUFF_UNK17 = 23,
    DISPLAY_POKEMON_FRIEND_AREA_INFO = 24,
    WIGGLYTUFF_CHECK_HAS_FRIEND_AREA = 25,
    WIGGLYTUFF_CHECK_POST_GAME = 26,
    WIGGLYTUFF_CHECK_WONDER_MAIL = 27,
    WIGGLYTUFF_CHECK_LEGENDARY = 28,
};

// size: 0x138
typedef struct WigglytuffShop
{
    bool32 isAsleep;
    s32 state;
    s32 fallbackState;
    s32 friendAreaPrice;
    u8 chosenFriendArea;
    s16 chosenSpecies;
    u32 menuAction1;
    u32 menuAction2;
    MenuItem unk1C[8];
    u16 unk5C[0x8];
    MenuStruct unk6C;
    /* 0xBC */ OpenedFile *faceFile;
    /* 0xC0 */ u8 *faceData;
    u16 unkC4;
    u16 unkC6;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 fillCB;
    OpenedFile **unkCC;
    UnkTextStruct2 unkD0[4];
    u32 unk130;
    u32 unk134;
} WigglytuffShop;

bool8 sub_80211AC(u32 mode, u32);
bool8 sub_8021774(u8 friendArea, bool8, s32);
u32 sub_8021274(bool8);
u8 sub_802132C(void);
void sub_8021354(bool8);
void sub_80213A0(void);
void sub_8021494(void);
u32 sub_80217EC(void);
void sub_8021830(void);

#endif // GUARD_WIGGLYTUFF_SHOP_H