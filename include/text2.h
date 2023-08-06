#ifndef GUARD_TEXT2_H
#define GUARD_TEXT2_H

#include "text.h"

void sub_8006518(struct UnkTextStruct2 *);
void sub_8006554(struct UnkTextStruct1 *, void *, u8 *, u16 *, u32, const struct UnkTextStruct2 *, u8, u32, struct UnkTextStruct2_sub *, u8);

// text.s
extern void InitGraphics(void);
extern void xxx_call_draw_string(s32 x, u32 y, const u8 *str, u32 , u32);

#endif // GUARD_TEXT2_H