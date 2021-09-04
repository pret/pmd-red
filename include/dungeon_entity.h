#ifndef GUARD_DUNGEON_ENTITY_H
#define GUARD_DUNGEON_ENTITY_H

struct subStruct_8048524
{
    u8 fill0[0x6];
    u8 unk6;
    u8 unk7;
    u8 fill8[0xE - 0x8];
    /* 0xE */ s16 HP; // HP??
    s16 unk10;
    u8 fill12[0x46 - 0x12];
    s8 unk46;
    u8 fill47[0xA4 - 0x47];
    u8 unkA4;
    u8 fillA5[0xAC - 0xA5];
    /* 0xAC */ u8 statusCondition;
    u8 fillAD[0xFB - 0xAD];
    u8 unkFB;
    u8 fillFC[0x112 - 0xFC];
    u8 unk112;
    u8 fill113[0x13C - 0x113];
    u32 unk13C;
    u8 fill140[0x15C - 0x140];
    u8 unk15C;
    u8 unk15D;
    u8 unk15E;
    u8 unk15F;
    u8 fill160[0x174 - 0x160];
    u32 unk174;
};

// Used for Pokémon, items, and traps.
struct DungeonEntity
{
    /* 0x0 */ u8 entityType;
    u8 fill1[0x4 - 0x1];
    /* 0x4 */ s16 posWorldX;
    /* 0x6 */ s16 posWorldY;
    /* 0x8 */ s16 prevPosWorldX;
    /* 0xA */ s16 prevPosWorldY;
    // The center of the entity acccording to pixel-space coordinates, using the same origin as posWorld.
    // X = (posWorld * 24 + 16) * 256, while Y = (posWorld * 24 + 12) * 256.
    /* 0xC */ s32 posPixelX;
    /* 0x10 */ s32 posPixelY;
    /* 0x14 */ s32 prevPosPixelX;
    /* 0x18 */ s32 prevPosPixelY;
    u8 fill1C[0x20 - 0x1C];
    /* 0x20 */ bool8 active; // Turned off when a Pokémon faints.
    u8 fill21[0x25 - 0x21];
    /* 0x25 */ u8 roomIndex;
    // The global spawn index counter starts at 10. Each Pokémon that spawns increments the counter and
    // gets assigned the current counter value as its spawn index.
    /* 0x26 */ u16 spawnIndex;
    u8 fill28[0x2A - 0x28];
    // 0x2A and 0x2E seem to be related to the sprite animation, though not sure how they're related.
    /* 0x2A */ u16 spriteAnimationCounter;
    // Each animation has a few different sprites that it transitions between.
    // This is the index of the currently displayed sprite within the animation.
    // Differs from 0x34 as this index is only between the sprites used by the animation,
    // while 0x34 is a shared index among all sprites.
    /* 0x2C */ u16 spriteAnimationIndex;
    /* 0x2E */ u16 spriteAnimationCounter2;
    // The position of the sprite within the tile. The animation may change the position slightly.
    /* 0x30 */ u16 spritePosX;
    /* 0x32 */ u16 spritePosY;
    // Offset of the sprite from its position at the start of the animation. Changes alongside spritePos.
    /* 0x34 */ s16 spritePosOffsetX;
    /* 0x36 */ s16 spritePosOffsetY;
    u8 fill38[0x48 - 0x38];
    // The sprite index to display, among the Pokémon's possible sprites.
    /* 0x48 */ u16 spriteIndexForEntity;
    /* 0x4A */ u16 spriteIndexForEntity2;
    // Some kind of base sprite index depending on which way the Pokémon is facing.
    // and which animation is playing (e.g., idle, moving).
    // Compared to 0x48, 0x50 and 0x54 are much larger and could be global indexes among all sprites in the game.
    /* 0x50 */ u16 spriteBaseForDirection;
    u8 fill52[0x54 - 0x52];
    /* 0x54 */ u16 spriteGlobalIndex;
    u8 fill56[0x6C - 0x56];
    /* 0x6C */ u8 facingDirection;
    /* 0x6D */ u8 facingDirection2; // Duplicate of 0x6C?
    u8 fill6D[0x70 - 0x6D];
    struct subStruct_8048524 *unk70;
};

enum EntityType
{
    POKEMON = 1,
    ITEM = 2,
    TRAP = 3
};

enum FacingDirection
{
    SOUTH,
    SOUTHEAST,
    EAST,
    NORTHEAST,
    NORTH,
    NORTHWEST,
    WEST,
    SOUTHWEST
};

#endif
