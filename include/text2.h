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

// size: 0xC
struct unkChar
{
    u32 *unk0;
    u16 unk4;
    s16 unk6;
    u32 fill8;
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

struct UnkDrawStringStruct;

struct UnkDrawStringStruct
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    s16 unkA;
    s32 unkC;
    u32 unk10;
    u32 unk14;
    u32 unk18;
    u32 unk1C;
    u8 unk20;
    u8 unk21;
    u8 fill22;
    u8 fill23;
    const u8* (*unk24)(const u8 *, const u8 *, struct UnkDrawStringStruct*);
    s32 unk28;
    s32 unk2C;
    s32 unk30;
    u32 unk34;
};


void RestoreUnkTextStruct_8006518(UnkTextStruct2 *);
void sub_8006554(UnkTextStruct1 *, u32 *, u32 *, u16 *, u32, const UnkTextStruct2 *, u8, u32, UnkTextStruct2_sub *, u8);
void sub_80073B8(s32);
void sub_80073E0(s32);
void sub_80078A4(u32, s32, s32, s32, u32);
void sub_800792C(u32, s32, s32, s32, u32);
void sub_8007A78(u32, s32, s32, s32, u32);
void sub_8007B7C(u32, s32, s32, s32, u32);
void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6);
const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *a0);
const u8 *xxx_handle_format_global(const u8 *str, struct UnkDrawStringStruct *unkStrPtr);

// text.s
extern const struct unkChar *GetCharacter(s32);
extern void InitGraphics(void);
void sub_800836C(s32 a0, const u8 *compressedData, s32 a1);
extern void sub_800898C(void);
extern void sub_80089AC(const UnkTextStruct2 *, UnkTextStruct2_sub *);
extern void CallPrepareTextbox_8008C54(u32);
extern s32 sub_8008ED0(const u8 *);
extern void sub_8009388(void);
void sub_8008F8C(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing);
void PrintStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr);

#endif // GUARD_TEXT2_H
