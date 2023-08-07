#ifndef GUARD_TEXT2_H
#define GUARD_TEXT2_H

#include "text.h"

// size: 0x10
struct unkShiftData
{
    u32 bytesA;
    u32 bytesB;
    u32 shift_left;
    u32 shift_right;
};

// size: 0x8
struct unkChar
{
    u32 *unk0;
    s16 unk4;
    s16 unk6;
};

struct unkStruct_80B8824
{
    u32 arr[9];
};

u32 xxx_call_draw_char(s32, s32, u32, u32, u32);

void sub_8006518(struct UnkTextStruct2 *);
void sub_8006554(struct UnkTextStruct1 *, u32 *, u32 *, u16 *, u32, const struct UnkTextStruct2 *, u8, u32, struct UnkTextStruct2_sub *, u8);
void sub_80073B8(s32);
void sub_80073E0(s32);
void sub_80078A4(u32, s32, s32, u32, u32);
void sub_800792C(u32, s32, s32, u32, u32);
void sub_8007A78(u32, u32, u32, u32, u32);

// text.s
extern struct unkChar *GetCharacter(u32);
extern void InitGraphics(void);
extern void xxx_call_draw_string(s32 x, u32 y, const u8 *str, u32 , u32);

#endif // GUARD_TEXT2_H