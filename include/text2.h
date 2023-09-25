#ifndef GUARD_TEXT2_H
#define GUARD_TEXT2_H

#include "structs/str_text.h"

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
struct unkStruct_80B8848
{
    u32 arr[8];
};

u32 xxx_call_draw_char(s32, s32, u32, u32, u32);

void sub_8006518(UnkTextStruct2 *);
void sub_8006554(UnkTextStruct1 *, u32 *, u32 *, u16 *, u32, const UnkTextStruct2 *, u8, u32, UnkTextStruct2_sub *, u8);
void sub_80073B8(s32);
void sub_80073E0(s32);
void sub_80078A4(u32, s32, s32, s32, u32);
void sub_800792C(u32, s32, s32, s32, u32);
void sub_8007A78(u32, s32, s32, s32, u32);
void sub_8007B7C(u32, s32, s32, s32, u32);
void sub_8007E20(u32, u32, u32, u32, u32, u8 *, u32);

// text.s
extern struct unkChar *GetCharacter(u32);
extern void InitGraphics(void);
extern void sub_800898C(void);
extern void sub_80089AC(const UnkTextStruct2 *, UnkTextStruct2_sub *);
extern void sub_8008C54(u32);
extern s32 sub_8008ED0(const u8 *);
extern void sub_8009388(void);
extern void xxx_call_draw_string(s32 x, u32 y, const u8 *str, u32 , u32);

#endif // GUARD_TEXT2_H