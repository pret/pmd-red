#ifndef GUARD_CODE_800F958_H
#define GUARD_CODE_800F958_H

#include "structs/str_dungeon.h"

// size: 0x8
typedef struct DungeonPokemonStatusSprite
{
    /* 0x0 */ u32 status;
    /* 0x4 */ u32 frame;
} DungeonPokemonStatusSprite;

// size: 0x40
typedef struct DungeonPokemonSprite
{
    /* 0x0 */ u8 exists;
    /* 0x4 */ u32 id;
    /* 0x8 */ u16 species; // Or sprite ID?
    /* 0xA */ u16 unkA;
    /* 0xC */ u32 status;
    /* 0x10 */ u8 visible;
    /* 0x11 */ u8 unk11;
    /* 0x14 */ Position pos;
    /* 0x18 */ Position statusOffsets[2];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ DungeonPokemonStatusSprite statusSprites[2];
    /* 0x38 */ u8 unk38;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
} DungeonPokemonSprite;

// size: 0x584
typedef struct DungeonPokemonSprites
{
    /* 0x0 */ u32 frame;
    /* 0x4 */ DungeonPokemonSprite sprites[22];
} DungeonPokemonSprites;

void sub_800F958(s32 dungeonSpriteID, Position *pos, Position *statusOffsets, u32 a3);

#endif
