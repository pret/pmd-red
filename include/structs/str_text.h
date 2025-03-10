#ifndef GUARD_STR_TEXT_H
#define GUARD_STR_TEXT_H

// size: 0x48
typedef struct Window
{
    s16 x;
    s16 y;
    s16 width;
    s16 height;
    s16 unk8;
    s32 type;
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
} Window;

// size: 0x4
typedef struct WindowHeader
{
    /* 0x0 */ u8 count; // How many headers there are, it's used for windows which can be scrolled left/right
    /* 0x1 */ u8 currId; // Id of the current header
    /* 0x2 */ u8 width;
    /* 0x3 */ u8 f3;
} WindowHeader;

#include "structs/str_position.h"

// size: 0x18
typedef struct WindowTemplate
{
    u8 unk0;
    /* 0x4 */ s32 type;
    /* 0x8 */ DungeonPos pos;
    /* 0xC */ s16 width;
    /* 0xE */ s16 height;
    s16 unk10; // In most cases it's the same as height. If it's smaller than height, the window may look glitchy. Maybe something with tile allocation/how the window is filled?
    s16 unk12;
    const WindowHeader *header;
} WindowTemplate;

#define WINDOW_TYPE_0                   0
#define WINDOW_TYPE_WITHOUT_BORDER      1
#define WINDOW_TYPE_2                   2
#define WINDOW_TYPE_NORMAL              3
#define WINDOW_TYPE_4                   4
#define WINDOW_TYPE_FILL_TRANSPARENT    5
#define WINDOW_TYPE_WITH_HEADER         6
#define WINDOW_TYPE_7                   7

#define MAX_WINDOWS 4

// All fields are zeroed out except for type which is set to WINDOW_TYPE_NORMAL.
#define WINDOW_DUMMY (Window) { .unk0 = 0, .type = WINDOW_TYPE_NORMAL, .pos = { .x = 0, .y = 0 }, .width = 0, .height = 0, .unk10 = 0, .unk12 = 0, .header = NULL }

// size: 0x60
typedef struct WindowTemplates
{
    /* 0x0 */ sWindowTemplate id[MAX_WINDOWS];
} WindowTemplates;

#endif // GUARD_STR_TEXT_H