#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "sprite_oam.h"
#include "structs/str_text.h"
#include "structs/str_position.h"

// size: 0xC
typedef struct MenuInputStructSub
{
    u8 unk0;
    /* 0x1 */ u8 a_button;
    /* 0x2 */ u8 b_button;
    /* 0x3 */ u8 dpad_right;
    /* 0x4 */ u8 dpad_left;
    /* 0x5 */ u8 unk5;
    u8 fill6[2];
    u16 unk8;
    s16 unkA;
} MenuInputStructSub;

// size: 0x34
typedef struct MenuInputStruct
{
    s32 unk0;
    u16 unk4;
    s16 unk6;
    Position unk8; // Maybe Position
    s16 unkC; // Maybe Position
    s16 unkE;
    u32 unk10;
    Position unk14; // Maybe Position
    /* 0x18 */ s16 menuIndex;
    s16 unk1A;
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    s16 unk22;
    u16 unk24;
    u16 unk26;
    MenuInputStructSub unk28;
} MenuInputStruct;

// size: 0x8
typedef struct MenuItem
{
    const u8 *text;
    s32 menuAction; // action??
} MenuItem;

// size: 0x50
typedef struct MenuStruct
{
    const u8 *unk0; // header text?
    /* 0x4 */ const MenuItem *menuItems;
    const u32 *menuTextColorArray;
    u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ MenuInputStruct input;
    /* 0x48 */ s32 menuAction;
    bool8 unk4C;
    bool8 unk4D;
    bool8 unk4E;
} MenuStruct;

// size: 0x30. Seems to be info for a NumericUpDown
typedef struct unkStructFor8013AA0
{
    s32 unk0; // chosenValue?
    s32 unk4; // curValue or initialValue
    s32 unk8; // minInclusive?
    s32 unkC; // maxInclusive?
    s32 unk10;
    s32 unk14; // index of unk18? But read as chosenValue..?
    UnkTextStruct2 *unk18;
    s32 unk1C; // width of prompt?
    s32 unk20; // height of prompt?
    u8 unk24; // related to unk10
    u8 unk25; // related to unk10
    u8 unk26;
    SpriteOAM unk28;
} unkStructFor8013AA0;

#endif // GUARD_MENU_H
