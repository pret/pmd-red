#ifndef GUARD_WIGGLYTUFF_SHOP_H
#define GUARD_WIGGLYTUFF_SHOP_H

#include "file_system.h"
#include "menu.h"
#include "text.h"

// size: 0x138
struct WigglytuffShop
{
    bool32 isAsleep;
    s32 state;
    s32 fallbackState;
    s32 friendAreaPrice;
    u8 chosenFriendArea;
    s16 chosenSpecies;
    u32 menuAction1;
    u32 menuAction2;
    struct MenuItem unk1C[8];
    u16 unk5C[0x8];
    struct MenuStruct unk6C;
    /* 0xBC */ struct OpenedFile *faceFile;
    /* 0xC0 */ u8 *faceData;
    u16 unkC4;
    u16 unkC6;
    u8 unkC8;
    u8 unkC9;
    u8 unkCA;
    u8 fillCB;
    struct OpenedFile **unkCC;
    struct UnkTextStruct2 unkD0[4];
    u32 unk130;
    u32 unk134;
};

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
    WIGGLYTUFF_UNKA = 0xA,
    WIGGLYTUFF_UNKB = 0xB,
    CONFIRM_BUY_FRIEND_AREA = 0xC,
    WIGGLYTUFF_UNKD = 0xD,
    WIGGLYTUFF_UNKE = 0xE,
    FRIEND_AREA_UNLOCKED = 0xF,
    FRIEND_AREA_INFO = 0x10,
    BUY_FRIEND_AREA = 0x11,
    NO_FRIEND_AREAS = 0x12,
    NOT_ENOUGH_MONEY = 0x13,
    WIGGLYTUFF_CHECK = 0x14,
    WIGGLYTUFF_CHECK_AGAIN = 0x15,
    WIGGLYTUFF_UNK16 = 0x16,
    WIGGLYTUFF_UNK17 = 0x17,
    DISPLAY_POKEMON_FRIEND_AREA_INFO = 0x18,
    WIGGLYTUFF_CHECK_HAS_FRIEND_AREA = 0x19,
    WIGGLYTUFF_CHECK_POST_GAME = 0x1A,
    WIGGLYTUFF_CHECK_WONDER_MAIL = 0x1B,
    WIGGLYTUFF_CHECK_LEGENDARY = 0x1C,
};

bool8 sub_80211AC(u32 mode, u32 param_2);
bool8 sub_8021774(u8 friendArea, bool8 param_2, s32 param_3);
u32 sub_8021274(bool8 param_1);
u8 sub_802132C(void);
void sub_8021354(bool8 param_1);
void sub_80213A0(void);
void sub_8021494(void);
u32 sub_80217EC(void);
void sub_8021830(void);

#endif // GUARD_WIGGLYTUFF_SHOP_H
