#ifndef GUARD_TEXT_H
#define GUARD_TEXT_H

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
    const u16 *unk0;
    u16 unk4;
    s16 unk6;
    u8 unk8;
    u8 fill9;
    u8 unkA;
    u8 fillB;
};

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
};

extern UnkTextStruct1 gUnknown_2027370[4];
extern u8 gUnknown_202749A[11];
extern bool8 gUnknown_20274A5;
extern u16 gUnknown_202B038[4][32][32]; // Usage points to these dimensions

void LoadCharmaps(void);
u32 UpdateFadeInTile(u32 a0);
u32 sub_80063B0(void);
void SelectCharmap(u32 a0);
void SetCharacterMask(int a0);
void xxx_call_save_unk_text_struct_800641C(const UnkTextStruct2 *a0, bool8 a1, bool8 a2);
void RestoreUnkTextStruct_8006518(UnkTextStruct2 *unkData);
u32 sub_8006544(u32 index);
void sub_8007334(s32 a0);
void sub_80073B8(s32 a0);
void sub_80073E0(s32 a0);
u32 xxx_call_draw_char(s32 x, s32 y, u32 a2, u32 color, u32 a4);
void sub_80078A4(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_800792C(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_8007A78(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_8007B7C(u32 a0, s32 x, s32 y, s32 a3, u32 color);
void sub_8007E20(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 *a5, u32 a6);
void DisplayMonPortraitSprite(s32 a0, const u8 *compressedData, s32 a2);
void DisplayMonPortraitSpriteFlipped(s32 a0, const u8 *compressedData, s32 a1);
const struct unkChar *GetCharacter(s32 chr);
const u8 *xxx_get_next_char_from_string(const u8 *a1, u32 *a0);
void sub_80087EC(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
bool8 xxx_call_update_bg_vram(void);
void CallPrepareTextbox_8008C54(u32 strId);
bool8 sub_8008D8C(u32 strId);
void sub_8008DC8(s32 a0, s32 a1, u16 a2, s32 a3);
s32 sub_8008ED0(const u8 *str);
void PrintStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing);
void PrintStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr);
const u8 *xxx_handle_format_global(const u8 *str, struct UnkDrawStringStruct *unkStrPtr);
void sub_8009408(s32 from, s32 to);
void sub_8009524(s32 strArrId);
void sub_80095CC(s32 a0, s32 a1);
s32 sub_80095E4(s32 a0, s32 a1);
s32 sub_8009614(s32 a0, s32 a1);

#endif // GUARD_TEXT_H
