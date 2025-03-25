#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "structs/sprite_oam.h"
#include "structs/str_text.h"
#include "structs/str_position.h"

// size: R=0xC | NDS=0xA?
typedef struct MenuInputStructSub
{
    /* R=0x0 | B=0x0 */ u8 unk0;
    /* R=0x1 | B=0x1 */ u8 a_button;
    /* R=0x2 | B=0x2 */ u8 b_button;
    /* R=0x3 | B=0x3 */ u8 dpad_right;
    /* R=0x4 | B=0x4 */ u8 dpad_left;
    /* R=0x5 | B=0x5 */ u8 unk5;
    /* R=0x8 | B=0x6 */ DungeonPos unk8;
} MenuInputStructSub;

// size: R=0x34 | NDS=0x32?
typedef struct MenuInputStruct
{
    /* 0x0  */ s32 unk0;
    /* 0x4  */ u16 unk4;
    /* 0x6  */ s16 firstEntryY;
    /* 0x8  */ DungeonPos unk8;
    /* 0xC  */ s16 unkC; // Maybe DungeonPos
    /* 0xE  */ s16 unkE;
    /* 0x10 */ u32 unk10;
    /* 0x14 */ DungeonPos unk14;
    /* 0x18 */ s16 menuIndex;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u16 unk24;
    /* 0x26 */ u16 unk26;
    /* 0x28 */ MenuInputStructSub unk28;
} MenuInputStruct;

// size: 0x8
typedef struct MenuItem
{
    const u8 *text;
    s32 menuAction;
} MenuItem;

// size: R=0x50 | B=0x4C?
typedef struct MenuStruct
{
    /* 0x0 */ const u8 *unk0; // header text?
    /* 0x4 */ const MenuItem *menuItems;
    /* 0x8 */ const u32 *menuTextColorArray;
    /* 0xC */ u16 *unkC;
    /* 0x10 */ s32 index;
    /* 0x14 */ MenuInputStruct input;
    /* 0x48 */ s32 menuAction;
    /* 0x4C */ bool8 unk4C;
    /* 0x4D */ bool8 unk4D;
    /* 0x4E */ bool8 unk4E;
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
    WindowTemplate *unk18;
    s32 unk1C; // width of prompt?
    s32 unk20; // height of prompt?
    u8 unk24; // related to unk10
    u8 unk25; // related to unk10
    u8 unk26;
    SpriteOAM unk28;
} unkStructFor8013AA0;

#endif // GUARD_MENU_H
