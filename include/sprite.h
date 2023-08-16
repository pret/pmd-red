#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

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

// size: 0x8
struct UnkSpriteMem
{
    /* 0x0 */ void *src;
    /* 0x4 */ s32 byteCount;
};

// size: 0x20
struct axdata1
{
    /* 0x0 */ s16 xPos;
    /* 0x2 */ s16 yPos;
    /* 0x4 */ u16 xOffset;
    /* 0x6 */ u16 yOffset;
    /* 0x8 */ u16 xShadow;
    /* 0xA */ u16 yShadow;
    u32 unkC;
    u32 unk10;
    /* 0x14 */ s16 vramTileOrMaybeAnimTimer;
    s16 unk16;
    /* 0x18 */ s16 poseId;
    /* 0x1A */ s16 lastPoseId;
    u8 fill1C[0x1E - 0x1C];
    u8 paletteNum;
};

// size: 0xA
struct __attribute__ ((packed, aligned(2))) ax_pose
{
    s16 sprite;
    u16 unk2; // Always 0 in red (except for end markers which are 0xFFFF)
    u16 flags1;
    u16 flags2;
    u16 flags3;
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