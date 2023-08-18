#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "axdata.h"
#include "ground_sprite.h"
#include "position.h"

// size: 0x8
struct unkSprite
{
    // y/affineMode/objMode/mosaic/bpp/shape
    u16 unk0;
    // x/matrixNum/size
    u16 unk2;
    // tileNum/priority/paletteNum
    u16 unk4;
    u16 unk6;
};

// size: 0x8
struct UnkSpriteLink
{
    struct UnkSpriteLink *unk0;
    struct unkSprite *unk4;
};

// size: 0x808
struct SpriteList
{
    struct UnkSpriteLink sprites[256];
    u32 unk800;
    u32 unk804;
};

// size: 0xC
struct unkStruct_20266B0
{
    /* 0x0 */ s32 byteCount;
    /* 0x4 */ void *src;
    /* 0x8 */ void *dest;
};

// size: ? 0x3C for now
struct Entity_Sub28
{
    u16 unk0;
    // 0x2 and 0x6 seem to be related to the sprite animation, though not sure how they're related.
    /* 0x2 */ u16 spriteAnimationCounter;
    // Each animation has a few different sprites that it transitions between.
    // This is the index of the currently displayed sprite within the animation.
    // Differs from 0xC as this index is only between the sprites used by the animation,
    // while 0xC is a shared index among all sprites.
    /* 0x4 */ u16 spriteAnimationIndex;
    /* 0x6 */ u16 spriteAnimationCounter2;
    // The position of the sprite within the tile. The animation may change the position slightly.
    /* 0x8 */ struct Position spritePos;
    // Offset of the sprite from its position at the start of the animation. Changes alongside spritePos.
    /* 0xC */ struct Position spritePosOffset;
    u8 fill10[0x20 - 0x10];
    // The sprite index to display, among the Pokémon's possible sprites.
    /* 0x20 */ u16 spriteIndexForEntity;
    /* 0x22 */ u16 spriteIndexForEntity2;
    u8 unk24[0x28 - 0x24];
    // Some kind of base sprite index depending on which way the Pokémon is facing.
    // and which animation is playing (e.g., idle, moving).
    // Compared to 0x20, 0x28 and 0x2C are much larger and could be global indexes among all sprites in the game.
    /* 0x28 */ u16 spriteBaseForDirection;
    u8 fill2A[0x2C - 0x2A];
    /* 0x2C */ u16 spriteGlobalIndex;
    u8 fill2E[0x3C - 0x2E];
};

// size: ?
struct Dungeon_Sub17B44_Sub4
{
    u32 unk0;
    u32 unk4;
    u8 fill8[0xC - 0x8];
    u32 unkC;
    u32 unk10;
};

// size: ?
struct Dungeon_Sub17B44
{
    u8 fill0[0x4 - 0x0];
    struct Dungeon_Sub17B44_Sub4 *unk4;
};

void AddSprite(struct unkSprite *, s32, struct UnkSpriteMem *, struct unkStruct_2039DB0 *);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void InitSprites(void);
void ResetSprites(bool8);
void SetSavingIconCoords(struct Position *);
void sub_8004E8C(struct unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);
void sub_80053AC(struct Entity_Sub28 *, struct Dungeon_Sub17B44 *, u32, u32, u32, u32, bool8);
extern void sub_80053D0(struct Entity_Sub28 *a0, struct Dungeon_Sub17B44_Sub4 *a1, u32 a2, u32 a3, u32 a4, u32 spriteAnimIndex, bool8 a6);

#endif // GUARD_SPRITE_H