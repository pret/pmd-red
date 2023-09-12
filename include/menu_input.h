#ifndef GUARD_MENU_INPUT_H
#define GUARD_MENU_INPUT_H

#include "menu.h"
#include "text.h"

// size: 0x1A8
struct unkStruct_203B34C
{
    u32 unk0;
    MenuStruct unk4[4];
    UnkTextStruct2 unk144[4];
    /* 0x1A4 */ u32 currMenuChoice;
};

u32 sub_8012A64(MenuInputStructSub *r0, s32 r1);
s32 GetKeyPress(MenuInputStruct *r0);
s32 sub_8012AE8(void);
void sub_8012BC4(u32 x, u32 y, s32 n, s32 len, u32 color, u32 param_6);
void sub_8012C60(u32 x, u32 y, u32 param_3, u32 color, u32 param_5);
void sub_8012CAC(UnkTextStruct2 *param_1, const MenuItem *param_2);
void sub_8012D08(UnkTextStruct2 *param_1, s32 param_2);
void sub_8012D34(UnkTextStruct2 *param_1, s32 param_2);
void sub_8012D60(MenuStruct *param_1, const MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012E04(MenuStruct *param_1, const MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012EA4(MenuStruct *param_1, bool8 r1);
void sub_8012EBC(MenuStruct *param_1);
bool8 sub_8012FD8(MenuStruct *param_1);
bool8 sub_80130A8(MenuStruct *param_1);
bool8 sub_8013114(MenuStruct *param_1, s32 *menuAction);
void sub_801317C(MenuInputStructSub *param_1);
void AddMenuCursorSprite(MenuInputStruct *param_1);
void sub_8013660(MenuInputStruct *param_1);
void UpdateMenuCursorSpriteCoords(MenuInputStruct *param_1);
void MoveMenuCursorDown(MenuInputStruct *param_1);
void sub_80136E0(MenuInputStruct *param_1, u8 param_2);
void MoveMenuCursorUp(MenuInputStruct *param_1);
void sub_8013744(MenuInputStruct *param_1, u8 param_2);
void sub_8013780(MenuInputStruct *param_1, s32 param_2);
s32 sub_80137A8(MenuInputStruct *param_1);
void sub_80137B0(MenuInputStruct *param_1, s32 param_2);
void sub_80137F8(MenuInputStruct *param_1, u32 param_2);
s32 sub_8013800(MenuInputStruct *param_1, s32 param_2);
void sub_8013818(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4);
void sub_8013848(MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4);
void sub_8013878(MenuInputStruct *param_1, s32 param_2);
bool8 sub_80138B8(MenuInputStruct *param_1, bool8 param_2);
bool8 sub_8013938(MenuInputStruct *param_1);
void sub_8013984(MenuInputStruct * param_1);
void sub_8013A54(MenuInputStruct *param_1);
void sub_8013A7C(MenuInputStruct *param_1);
void AddMenuCursorSprite_(MenuInputStruct *, u32);
void nullsub_34(MenuInputStructSub *);

void sub_8013AA0(unkStructFor8013AA0 *);
u32 sub_8013BBC(unkStructFor8013AA0 *);

#endif // GUARD_MENU_INPUT_H