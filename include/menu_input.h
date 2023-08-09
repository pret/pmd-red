#include "menu.h"
#include "text.h"

u32 sub_8012A64(struct MenuInputStructSub *r0, s32 r1);
s32 GetKeyPress(struct MenuInputStruct *r0);
s32 sub_8012AE8(void);
void sub_8012BC4(u32 x, u32 y, s32 n, s32 len, u32 color, u32 param_6);
void sub_8012C60(u32 x, u32 y, u32 param_3, u32 color, u32 param_5);
void sub_8012CAC(struct UnkTextStruct2 *param_1, const struct MenuItem *param_2);
void sub_8012D08(struct UnkTextStruct2 *param_1, s32 param_2);
void sub_8012D34(struct UnkTextStruct2 *param_1, s32 param_2);
void sub_8012D60(struct MenuStruct *param_1, const struct MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012E04(struct MenuStruct *param_1, const struct MenuItem *menuItems, u32 *colorArray, u16 *param_4, s32 menuAction, s32 index);
void sub_8012EA4(struct MenuStruct *param_1, bool8 r1);
void sub_8012EBC(struct MenuStruct *param_1);
bool8 sub_8012FD8(struct MenuStruct *param_1);
bool8 sub_80130A8(struct MenuStruct *param_1);
bool8 sub_8013114(struct MenuStruct *param_1, s32 *menuAction);
void sub_801317C(struct MenuInputStructSub *param_1);
void AddMenuCursorSprite(struct MenuInputStruct *param_1);
void sub_8013660(struct MenuInputStruct *param_1);
void UpdateMenuCursorSpriteCoords(struct MenuInputStruct *param_1);
void MoveMenuCursorDown(struct MenuInputStruct *param_1);
void sub_80136E0(struct MenuInputStruct *param_1, u8 param_2);
void MoveMenuCursorUp(struct MenuInputStruct *param_1);
void sub_8013744(struct MenuInputStruct *param_1, u8 param_2);
void sub_8013780(struct MenuInputStruct *param_1, s32 param_2);
s32 sub_80137A8(struct MenuInputStruct *param_1);
void sub_80137B0(struct MenuInputStruct *param_1, s32 param_2);
void sub_80137F8(struct MenuInputStruct *param_1, u32 param_2);
s32 sub_8013800(struct MenuInputStruct *param_1, s32 param_2);
void sub_8013818(struct MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4);
void sub_8013848(struct MenuInputStruct *param_1, s32 param_2, u32 param_3, s32 param_4);
void sub_8013878(struct MenuInputStruct *param_1, s32 param_2);
bool8 sub_80138B8(struct MenuInputStruct *param_1, bool8 param_2);
bool8 sub_8013938(struct MenuInputStruct *param_1);
void sub_8013984(struct MenuInputStruct * param_1);
void sub_8013A54(struct MenuInputStruct *param_1);
void sub_8013A7C(struct MenuInputStruct *param_1);
