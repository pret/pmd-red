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

void AddSprite(SpriteOAM *, s32, UnkSpriteMem *, unkStruct_2039DB0 *);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void InitSprites(void);
void ResetSprites(bool8);
void SetSavingIconCoords(DungeonPos *);
void sub_8004E8C(unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);
void sub_800533C(ax_pose **, UnkSpriteMem **, axdata1 *, u16 *, bool8);
void AxResInitFile(axdata *, OpenedFile *, u32, u32, u32, u32, bool8);
void AxResInit(axdata *, axmain *, u32, u32, u32, u32, bool8);
void AxResInitUnorientedFile(axdata *, OpenedFile *, u32, u32, u32, bool8);
void RunAxAnimationFrame(struct axObject *);

#endif // GUARD_SPRITE_H
