#ifndef GUARD_WIGGLYTUFF_SHOP3_H
#define GUARD_WIGGLYTUFF_SHOP3_H

#include "file_system.h"
#include "menu.h"
#include "structs/str_text.h"

enum WigglytuffStates
{
    WIGGLYTUFF_INIT,
    WIGGLYTUFF_MAIN_MENU,
    WIGGLYTUFF_INFO,
    WIGGLYTUFF_PRE_EXIT,
    WIGGLYTUFF_EXIT,
    WIGGLYTUFF_CANT_ADD_FRIEND_AREA,
    NO_MONEY,
    FRIEND_AREA_SELECT_BUY,
    FRIEND_AREA_SELECT_BUY_AGAIN,
    WIGGLYTUFF_UNK9,
    WIGGLYTUFF_UNKA,
    WIGGLYTUFF_UNKB,
    CONFIRM_BUY_FRIEND_AREA,
    WIGGLYTUFF_UNKD,
    WIGGLYTUFF_UNKE,
    FRIEND_AREA_UNLOCKED,
    FRIEND_AREA_INFO,
    BUY_FRIEND_AREA,
    NO_FRIEND_AREAS,
    NOT_ENOUGH_MONEY,
    WIGGLYTUFF_CHECK,
    WIGGLYTUFF_CHECK_AGAIN,
    WIGGLYTUFF_UNK16,
    WIGGLYTUFF_UNK17,
    DISPLAY_POKEMON_FRIEND_AREA_INFO,
    WIGGLYTUFF_CHECK_HAS_FRIEND_AREA,
    WIGGLYTUFF_CHECK_POST_GAME,
    WIGGLYTUFF_CHECK_WONDER_MAIL,
    WIGGLYTUFF_CHECK_LEGENDARY,
};

// size: 0x138
typedef struct WigglytuffShop3Work
{
    u32 mode;
    s32 state;
    s32 fallbackState;
    s32 friendAreaPrice;
    u8 chosenFriendArea;
    s16 chosenSpecies;
    u32 menuAction1;
    u32 menuAction2;
    MenuItem unk1C[8];
    u16 unk5C[8];
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
} WigglytuffShop3Work;

bool8 CreateWigglytuffShop(u32 mode);
u32 sub_8021C5C(void);
void sub_8021D1C(void);

#endif // GUARD_WIGGLYTUFF_SHOP3_H