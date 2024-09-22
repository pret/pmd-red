#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "structs/axdata.h"
#include "ground_sprite.h"
#include "structs/str_position.h"
#include "sprite_oam.h"

// size: 0x8
typedef struct UnkSpriteLink
{
    struct UnkSpriteLink *unk0;
    SpriteOAM *unk4;
} UnkSpriteLink;

// size: 0x808
typedef struct SpriteList
{
    UnkSpriteLink sprites[256];
    u32 unk800;
    u32 unk804;
} SpriteList;

// size: 0xC
typedef struct unkStruct_20266B0
{
    /* 0x0 */ s32 byteCount;
    /* 0x4 */ void *src;
    /* 0x8 */ void *dest;
} unkStruct_20266B0;

// size: ? 0x3C for now
typedef struct EntitySpriteInfo
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
    /* 0x8 */ Position spritePos;
    // Offset of the sprite from its position at the start of the animation. Changes alongside spritePos.
    /* 0xC */ Position spritePosOffset;
    u8 fill10[0x14 - 0x10];
    u32 unk14;
    u32 unk18;
    u16 unk1C;
    u8 fill1E[0x20 - 0x1E];
    // The sprite index to display, among the Pokémon's possible sprites.
    /* 0x20 */ u16 spriteIndexForEntity;
    /* 0x22 */ u16 spriteIndexForEntity2;
    u8 unk24[0x28 - 0x24];
    // Some kind of base sprite index depending on which way the Pokémon is facing.
    // and which animation is playing (e.g., idle, moving).
    // Compared to 0x20, 0x28 and 0x2C are much larger and could be global indexes among all sprites in the game.
    /* 0x28 */ u32 spriteBaseForDirection;
    /* 0x2C */ u32 spriteGlobalIndex;
    u32 unk30;
    u32 unk34;
    u32 unk38;
} EntitySpriteInfo;

void AddSprite(SpriteOAM *, s32, UnkSpriteMem *, unkStruct_2039DB0 *);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void InitSprites(void);
void ResetSprites(bool8);
void SetSavingIconCoords(Position *);
void sub_8004E8C(unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);
void sub_800533C(ax_pose **, UnkSpriteMem **, axdata1 *, u16 *, bool8);
void AxResInitFile(EntitySpriteInfo *, OpenedFile *, u32, u32, u32, u32, bool8);
void AxResInit(EntitySpriteInfo *, axmain *, u32, u32, u32, u32, bool8);
void AxResInitUnorientedFile(EntitySpriteInfo *, OpenedFile *, u32, u32, u32, bool8);
void RunAxAnimationFrame(struct axPokemon *);

#endif // GUARD_SPRITE_H
