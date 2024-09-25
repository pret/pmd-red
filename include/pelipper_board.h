#ifndef GUARD_PELIPPER_BOARD_H
#define GUARD_PELIPPER_BOARD_H

#include "structs/menu.h"
#include "structs/str_802C39C.h"

// Guessing based off of 203B304
struct unkStruct_203B308
{
    // size: 0xB6 << 1
    u32 state;
    u32 unk4;
    u8 jobIndex;
    unkStruct_802C39C unkC;
    u32 menuAction1;
    u32 menuAction2;
    MenuStruct unk6C;
    MenuItem menuItems[8];
    u16 unkFC[8];
    UnkTextStruct2 unk10C[4];
};
extern struct unkStruct_203B308 *gPelipperBoard;


enum PelipperBoardStates
{
    INITIALIZE_PELIPPER_BOARD,
    MAIN_PELIPPER_BOARD_MENU,
    // 2
    PELIPPER_BOARD_EXIT = 3,
    // 4 - 6
    PELIPPER_JOB_INFO = 7,
    PELIPPER_JOB_LIST_MENU,
};

enum PelipperBoardActions
{
    PELIPPER_BOARD_NULL = 1,
    PELIPPER_BOARD_BULLETIN_BOARD,
    PELIPPER_BOARD_JOB_LIST,
    PELIPPER_BOARD_ACCEPT,
    PELIPPER_BOARD_INFO,
};
#endif // GUARD_PELIPPER_BOARD_H
