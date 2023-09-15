#ifndef GUARD_MAIN_MENU1_H
#define GUARD_MAIN_MENU1_H

#include "menu.h"
#include "text.h"

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
typedef struct MainMenu1Work
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
} MainMenu1Work;

void CleanUpMenu(void);
void DeleteMainMenu(void);
MainMenu1Work *GetMainMenu(void);
void InitMainMenu(void);
void SetMenuItems(MenuStruct *, UnkTextStruct2 *, s32 index, const UnkTextStruct2 *, const MenuItem *menuItems, bool8, u32 menuAction, bool8 unused);
void SetUpMenu(void);
s32 UpdateMenu(void);

void sub_8035C1C(void);
void sub_8035CC0(UnkTextStruct2 *dataArray, u32 index);
void sub_8035CF4(MenuStruct *menu, u32 index, bool8);
void sub_8035D1C(void);
s16 sub_8035D3C(void);
s32 sub_8035D74(void);
unkStruct_8035D94 *sub_8035D94(void);
void sub_8035DA0(void);

#endif // GUARD_MAIN_MENU1_H