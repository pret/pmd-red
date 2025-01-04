#ifndef GUARD_DUNGEON_POKEMON_SPRITES_H
#define GUARD_DUNGEON_POKEMON_SPRITES_H

#include "structs/str_position.h"

// size: 0x8
typedef struct DungeonPokemonStatusSprite
{
    /* 0x0 */ u32 status;
    /* 0x4 */ s32 frame;
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
    /* 0x14 */ DungeonPos pos;
    /* 0x18 */ DungeonPos statusOffsets[2];
    /* 0x20 */ u32 unk20;
    /* 0x24 */ u32 unk24;
    /* 0x28 */ DungeonPokemonStatusSprite statusSprites[2];
    /* 0x38 */ u8 unk38;
    u16 fill3A;
    /* 0x3C */ u16 unk3C;
    /* 0x3E */ u16 unk3E;
} DungeonPokemonSprite;

// size: 0x584
typedef struct DungeonPokemonSprites
{
    /* 0x0 */ s32 frame;
    /* 0x4 */ DungeonPokemonSprite sprites[22];
} DungeonPokemonSprites;

extern DungeonPokemonSprites *gDungeonPokemonSprites;

#endif // GUARD_DUNGEON_POKEMON_SPRITES_H
