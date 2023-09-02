#ifndef GUARD_DUNGEON_POKEMON_SPRITES_H
#define GUARD_DUNGEON_POKEMON_SPRITES_H

#include "position.h"

DungeonPokemonStatusSprite
{
    u32 status;
    u32 frame;
};

DungeonPokemonSprite
{
    /* 0x0000 */ u8 exists;
    /* 0x0004 */ u32 id;
    /* 0x0008 */ u16 species; // Or sprite ID?
    /* 0x000A */ u16 unkA;
    /* 0x000C */ u32 status;
    /* 0x0010 */ u8 visible;
    /* 0x0011 */ u8 unk11;
    /* 0x0014 */ Position pos;
    /* 0x0018 */ Position statusOffsets[2];
    /* 0x0020 */ u32 unk20;
    /* 0x0024 */ u32 unk24;
    /* 0x0028 */ DungeonPokemonStatusSprite statusSprites[2];
    /* 0x0038 */ u8 unk38;
    /* 0x003C */ u16 unk3C;
    /* 0x003E */ u16 unk3E;
}

DungeonPokemonSprites
{
    u32 frame;
    DungeonPokemonSprites sprites[22];
};

extern DungeonPokemonSprites *gDungeonPokemonSprites;

#endif
