#ifndef GUARD_OPTIONS_MENU2_H
#define GUARD_OPTIONS_MENU2_H

#include "game_options.h"
#include "structs/menu.h"

// size: 0xAC
struct unkStruct_203B260
{
    /* 0x0 */ GameOptions *optionsMenu;
    /* 0x4 */ MenuInputStructSub unk4;
    /* 0x10 */ MenuInputStruct input;
    u32 unk44;
    UnkTextStruct2 *unk48;
    UnkTextStruct3 unk4C;
};

bool8 sub_801E198(GameOptions *optionsMenu);
u32 sub_801E218(void);
void sub_801E2C4(void);

#endif // GUARD_OPTIONS_MENU2_H