#ifndef GUARD_STR_TEXT_H
#define GUARD_STR_TEXT_H

#include "structs/str_position.h"

#define WINDOW_HEADER_HEIGHT 2

enum WinTemplateFlag
{
    WINTEMPLATE_FLAG_NONE = 0,
    WINTEMPLATE_FLAG_x20 = (1 << 5),
    WINTEMPLATE_FLAG_x40 = (1 << 6),
    WINTEMPLATE_FLAG_x80 = (1 << 7), // Appears to skip the border and preparation in `AddWindow()`
};

// size: 0xC
typedef struct unkChar
{
    const u16 *unk0;
    u16 unk4;
    s16 width;
    u8 unk8;
    u8 fill9;
    u8 unkA;
    u8 fillB;
} unkChar;

// size: 0x48
typedef struct Window
{
    /* 0x0 */ s16 x;
    /* 0x2 */ s16 y;
    /* 0x4 */ s16 width;
    /* 0x6 */ s16 height; // Inner height
    /* 0x8 */ s16 totalHeight; // Including header
    /* 0xC */ s32 type;
    /* 0x10 */ u32 unk10; // winGFX start tile?
    /* 0x14 */ u32 unk14; // unk1C start tile?
    /* 0x18 */ u32 *winGFX; // 8 packed pixels. Each pixel is 4 bits wide.
    /* 0x1C */ u32 *unk1C; // Similar to winGFX
    /* 0x20 */ s32 unk20; // Some width relation to winGFX (stride?)
    /* 0x24 */ s32 unk24; // Set from winTemplate unk12
    /* 0x28 */ u32 *unk28; // Somewhere in VRAM
    /* 0x2C */ s32 unk2C; // Related to unk38
    /* 0x30 */ u32 *unk30; // Somewhere in VRAM
    /* 0x34 */ u32 *unk34; // Related to unk1C and unk3C
    /* 0x38 */ s32 unk38; // Related to unk2C and unk44
    /* 0x3C */ u32 *unk3C; // Somewhere in winGFX or unk1C
    /* 0x40 */ u32 *unk40; // Somewhere in winGFX or unk1C
    /* 0x44 */ bool8 unk44; // Related to unk38 not being 0
    /* 0x45 */ bool8 isWinType0;
    /* 0x46 */ bool8 unk46;
} Window;

// size: 0x4
typedef struct WindowHeader
{
    /* 0x0 */ u8 count; // How many headers there are, it's used for windows which can be scrolled left/right
    /* 0x1 */ u8 currId; // Id of the current header
    /* 0x2 */ u8 width;
    /* 0x3 */ u8 f3; // Always set to 0?
} WindowHeader;

// size: 0x18
typedef struct WindowTemplate
{
    /* 0x00 */ u8 flags; // See enum "WinTemplateFlag"
    /* 0x04 */ s32 type;
    /* 0x08 */ DungeonPos pos;
    /* 0x0C */ s16 width;
    /* 0x0E */ s16 height; // Inner height
    /* 0x10 */ s16 totalHeight; // Including header
    /* 0x12 */ s16 unk12; // Related to startTileNum and width
    /* 0x14 */ const WindowHeader *header;
} WindowTemplate;

#define WINDOW_TYPE_0                0
#define WINDOW_TYPE_WITHOUT_BORDER   1
#define WINDOW_TYPE_ONLY_TEXT        2 // No border, no fill, prints pure text on bg
#define WINDOW_TYPE_NORMAL           3
#define WINDOW_TYPE_4                4
#define WINDOW_TYPE_FILL_TRANSPARENT 5
#define WINDOW_TYPE_WITH_HEADER      6
#define WINDOW_TYPE_7                7

#define MAX_WINDOWS 4

// All fields are zeroed out except for type which is set to WINDOW_TYPE_NORMAL.
#define WIN_TEMPLATE_DUMMY (WindowTemplate) { .flags = WINTEMPLATE_FLAG_NONE, .type = WINDOW_TYPE_NORMAL, .pos = { .x = 0, .y = 0 }, .width = 0, .height = 0, .totalHeight = 0, .unk12 = 0, .header = NULL }

// size: 0x60
typedef struct WindowTemplates
{
    /* 0x0 */ WindowTemplate id[MAX_WINDOWS];
} WindowTemplates;

#endif // GUARD_STR_TEXT_H
