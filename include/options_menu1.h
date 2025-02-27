#ifndef GUARD_OPTIONS_MENU1_H
#define GUARD_OPTIONS_MENU1_H

#include "game_options.h"
#include "structs/menu.h"

// size: 0x11C
struct unkStruct_203B25C
{
    /* 0x0 */ u32 state;
    /* 0x4 */ u32 chosenHintIndex;
    /* 0x8 */ GameOptions newOptions;
    /* 0x18 */ u32 menuAction;
    /* 0x1C */ MenuStruct menu;
    /* 0x6C */ MenuItem menuItems[8];
    u16 unkAC[8];
    Windows unkBC;
};

bool8 sub_801DCC4(void);
u32 sub_801DCE8(void);
void sub_801DD50(void);

#endif // GUARD_OPTIONS_MENU1_H