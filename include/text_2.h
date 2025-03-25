#ifndef GUARD_TEXT_2_H
#define GUARD_TEXT_2_H

#include "structs/str_text.h"

void AddDoubleUnderScoreHighlight(u32 windowId, s32 x, s32 y, s32 width, u32 color);
void AddUnderScoreHighlight(u32 windowId, s32 x, s32 y, s32 width, u32 color);
void CallPrepareTextbox_8008C54(u32 windowId);
void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2);
void DisplayMonPortraitSpriteFlipped(s32 a0, const u8 *compressedData, s32 a1);
const unkChar *GetCharacter(s32 chr);
void PrepareTextbox_8008C6C(Window *windows, u32 windowId);
void ResetWindowBgData(void);
void sub_8007A78(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6);
void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
void sub_80089AC(const WindowTemplate *r4, DungeonPos *r5_Str);
u32 xxx_call_draw_char(s32 x, s32 y, u32 chr, u32 color, u32 windowId);
bool8 xxx_call_update_bg_vram(void);
u32 xxx_draw_char(Window *windows, s32 x, s32 y, u32 chr, u32 color, u32 windowId);
const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *dstChr);

#endif // GUARD_TEXT_2_H
