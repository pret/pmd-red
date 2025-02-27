#ifndef GUARD_STR_TEXT_H
#define GUARD_STR_TEXT_H

// size: 0x48
typedef struct UnkTextStruct1
{
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u32 unkC;
    u32 unk10;
    u32 unk14;
    u32 *unk18;
    u32 *unk1C;
    s32 unk20;
    s32 unk24;
    u32 *unk28; // Somewhere in VRAM
    s32 unk2C;
    u32 *unk30; // Somewhere in VRAM?
    u32 *unk34;
    s32 unk38;
    u32 *unk3C;
    u32 *unk40;
    u8 unk44;
    bool8 unk45;
    u8 unk46;
} UnkTextStruct1;

typedef struct WindowHeader
{
    u8 f0;
    u8 f1;
    u8 f2;
    u8 f3;
} WindowHeader;

#include "structs/str_position.h"

// size: 0x18
typedef struct Window
{
    u8 unk0;
    s32 type;
    DungeonPos pos;
    s16 width;
    s16 height;
    s16 unk10; // In most cases it's the same as height. If it's smaller than height, the window may look glitchy. Maybe something with tile allocation/how the window is filled?
    s16 unk12;
    const WindowHeader *unk14;
} Window;

#define WINDOW_DUMMY (Window) {.type = WINDOW_TYPE_NORMAL, .width = 0}

#define WINDOW_TYPE_WITHOUT_BORDER      1
#define WINDOW_TYPE_NORMAL              3
#define WINDOW_TYPE_FILL_TRANSPARENT    5
#define WINDOW_TYPE_WITH_HEADER         6
#define WINDOW_TYPE_7                   7

#define MAX_WINDOWS 4

typedef struct Windows {
    Window id[MAX_WINDOWS];
    // Something ugly, so that sub_805FD74 could match weird compiler memcpy/stack initialization
    #ifndef NONMATCHING
    u8 fakeMatch[0];
    #endif // NONMATCHING
} Windows;

#endif // GUARD_STR_TEXT_H
