#ifndef GUARD_SAVE_MENU_H
#define GUARD_SAVE_MENU_H

#include "structs/menu.h"

// size: 0x1B4
// for some reason, this is 0x1A4 in NDS, but I (Kermalis) can't find out why yet. It seems like MenuStruct or Windows is smaller in NDS
typedef struct SaveMenuWork
{
    /* 0x0 */ u32 currMenu;
    u32 unk4;
    MenuStruct unk8[4];
    Windows unk148;
    SpriteOAM unk1A8;
    u32 unk1B0; // Sprite count?
} SaveMenuWork;

void CleanSaveMenu(void);
void CreateSaveMenu(s32 currMenu);
s32 UpdateSaveMenu(void);

#endif // GUARD_SAVE_MENU_H
