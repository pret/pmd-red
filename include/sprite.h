#ifndef GUARD_SPRITE_H
#define GUARD_SPRITE_H

#include "structs/axdata.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"

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

void AddAxSprite(ax_pose *, axdata1 *, UnkSpriteMem *, unkStruct_2039DB0 *spriteMasks);
void AddSprite(SpriteOAM *, s32, UnkSpriteMem *, unkStruct_2039DB0 *spriteMasks);
void AxResInit(axdata *, axmain *, u32, u32 direction, u32, u32 spriteAnimIndex, bool8);
void AxResInitFile(axdata *, OpenedFile *, u32, u32, u32, u32 spriteAnimIndex, bool8);
void AxResInitUnorientedFile(axdata *, OpenedFile *, u32, u32, u32 spriteAnimIndex, bool8);
void BlinkSavingIcon(void);
void CopySpritesToOam(void);
void DoAxFrame_800558C(axdata *, s32 spriteX, s32 spriteY, u32, u32 paletteNum, unkStruct_2039DB0 *spriteMasks);
void InitSprites(void);
void nullsub_7(DungeonPos *);
void nullsub_8(u32);
void nullsub_9(void);
void nullsub_10(bool8);
void nullsub_11(SpriteOAM *, s32, UnkSpriteMem *, unkStruct_2039DB0 *);
void nullsub_12(void);
void nullsub_13(void);
void nullsub_14(void);
void ResetSprites(bool8);
void RunAxAnimationFrame(axdata *);
void SetSavingIconCoords(DungeonPos *pos);
void sub_8004E8C(unkStruct_2039DB0 *);
void sub_8005180(void);
void sub_8005304(void);
void sub_8005610(OpenedFile *, s32 vramIdx, s32 brightness, const RGB *ramp);
const RGB *sub_8005674(const EfoFileData *, s32 vramIdx);
void sub_800569C(DungeonPos *, axObject *, u8);
void sub_8005700(DungeonPos *, axObject *);
void sub_8005770(s32, const RGB *color, s32 brightness, const RGB *ramp);

#endif // GUARD_SPRITE_H
