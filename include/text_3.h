#ifndef GUARD_TEXT_3_H
#define GUARD_TEXT_3_H

// size: 0x34
typedef struct UnkDrawStringStruct
{
    s16 x;
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
    const u8 * (*unk24)(const u8 *, const u8 *, struct UnkDrawStringStruct *);
    s32 unk28;
    s32 unk2C;
    s32 unk30;
} UnkDrawStringStruct;

void PrintStringOnWindow(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr);
void PrintStringOnWindow2(s32 x, s32 y, const u8 *str, u32 windowId, u32 terminatingChr, s32 lineSpacing);
bool8 sub_8008D8C(s32 windowId);
void sub_8008DC8(s32 x, s32 y, u16 bg0Val, u16 bg1Val);
s32 GetStringLineWidth(const u8 *str);
void sub_8009388(void);
void sub_8009408(s32 from, s32 to);
void sub_8009524(s32 windowId);
void sub_80095CC(s32 a0, s32 a1);
s32 CalcEntriesTotalHeight(s32 entriesCount, s32 entryHeight);
s32 CalcTwoLinesEntriesTotalHeight(s32 entriesCount, s32 entryHeight);
const u8 *xxx_handle_format_global(const u8 *str, UnkDrawStringStruct *unkStrPtr);

#endif // GUARD_TEXT_3_H
