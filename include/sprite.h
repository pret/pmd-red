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

void AddSprite(struct unkSprite *, s32, struct UnkSpriteMem *, struct unkStruct_2039DB0 *);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void InitSprites(void);
void ResetSprites(bool8);
void SetSavingIconCoords(struct Position *);
void sub_8004E8C(struct unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);

#endif // GUARD_SPRITE_H