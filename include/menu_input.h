#ifndef GUARD_MENU_INPUT_H
#define GUARD_MENU_INPUT_H

#include "structs/menu.h"
#include "structs/str_text.h"

void sub_8012A18(s32 unused);
u32 sub_8012A64(TouchScreenMenuInput *r0, s32 r1);
s32 GetKeyPress(MenuInputStruct *r0);
s32 GetMenuInput(void);
void PrintNumOnWindow(s32 x, s32 y, s32 num, s32 len, u32 color, u32 windowId);
void DrawCharOnWindowWidth12(u32 x, u32 y, u32 param_3, u32 color, u32 param_5);
void sub_8012CAC(WindowTemplate *param_1, const MenuItem *param_2);
void sub_8012D08(WindowTemplate *param_1, s32 param_2);
void sub_8012D34(WindowTemplate *param_1, s32 param_2);
void sub_8012D60(MenuStruct *param_1, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012E04(MenuStruct *param_1, const MenuItem *menuItems, const u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012EA4(MenuStruct *param_1, bool8 r1);
void sub_8012EBC(MenuStruct *param_1);
bool8 sub_8012FD8(MenuStruct *param_1);
bool8 sub_80130A8(MenuStruct *param_1);
bool8 sub_8013114(MenuStruct *param_1, s32 *menuAction);
void ResetTouchScreenMenuInput(TouchScreenMenuInput *param_1);
void AddMenuCursorSprite(MenuInputStruct *param_1);
void sub_8013660(MenuInputStruct *param_1);
void UpdateMenuCursorSpriteCoords(MenuInputStruct *param_1);
void MoveMenuCursorDown(MenuInputStruct *param_1);
void MoveMenuCursorDownWrapAround(MenuInputStruct *param_1, u8 param_2);
void MoveMenuCursorUp(MenuInputStruct *param_1);
void MoveMenuCursorUpWrapAround(MenuInputStruct *param_1, u8 param_2);
void sub_8013780(MenuInputStruct *param_1, s32 param_2);
void sub_80137B0(MenuInputStruct *param_1, s32 param_2);
s32 GetMenuEntryYCoord(MenuInputStruct *menu, s32 entryId);
void CreateMenuOnWindow(MenuInputStruct *menuInput, s32 totalCount, u32 perPageCount, s32 windowId);
void CreateMenuOnWindowTwoLinesEntry(MenuInputStruct *menuInput, s32 totalCount, u32 perPageCount, s32 windowId);
void MoveMenuToEntryId(MenuInputStruct *param_1, s32 param_2);
bool8 MenuCursorUpdate(MenuInputStruct *param_1, bool8 param_2);
bool8 MenuCursorUpdateOnlyLeftRight(MenuInputStruct *param_1);
void MenuUpdatePagesData(MenuInputStruct * param_1);
void AddMenuCursorSprite_(MenuInputStruct *, u8 *);
void GetTouchScreenMenuInput(TouchScreenMenuInput *touchScreen, s32 a1);
void sub_8013AA0(unkStructFor8013AA0 *);
u32 sub_8013BBC(unkStructFor8013AA0 *);
void sub_8013C68(unkStructFor8013AA0 *);
void sub_8013D10(unkStructFor8013AA0 *);
void sub_8013E54(void);
void sub_8013F84(void);
void sub_80140B4(WindowTemplates *);
void sub_80140DC(void);
void sub_80140F8(void);
void sub_8014114(void);

#define TOUCH_SCREEN_ARROW_UP_PRESS 1
#define TOUCH_SCREEN_ARROW_DOWN_PRESS 2
u32 GetTouchScreenArrowPress(s32 a0, const void *a1);

#define GET_CURRENT_MENU_ENTRY(menuInput)((menuInput.currPage * menuInput.entriesPerPage) + menuInput.menuIndex)

#endif // GUARD_MENU_INPUT_H
