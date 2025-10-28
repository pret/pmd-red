#ifndef GUARD_GROUND_SPRITE_H
#define GUARD_GROUND_SPRITE_H

#include "structs/axdata.h"
#include "structs/sprite_oam.h"
#include "structs/str_position.h"

// TODO: Clean up these structs

struct UnkGroundSpriteSubStructx48
{
    s16 unk0;
    u16 unk2;
    axmain *axmain;
};

// size: 0x80 (probably the last sub-struct of GroundLives)
struct UnkGroundSpriteStruct
{
    axdata axdata;
    unkStruct_2039DB0 unk3C;
    struct UnkGroundSpriteSubStructx48 unk48;
    u16 flags_0x50;
    s16 unk52;
    OpenedFile *unk54;
    s16 unk58;
    u8 unk5A;
    s32 unk5C;
    s32 unk60;
    s16 unk64;
    s16 unk66;
    u16 unk68;
    s16 unk6A;
    u16 unk6C;
    s16 unk6E;
    u8 unk70;
    PixelPos unk74;
    s32 unk7C;
};

void sub_80A62F0(void);
void GroundSprite_Reset(s32 a0);
void sub_80A658C(void);
void sub_80A6688(struct UnkGroundSpriteStruct *ptr, s32 a0);
bool8 SpriteHasPokemonSize_80A66A4(struct UnkGroundSpriteStruct *ptr);
bool8 sub_80A66D4(struct UnkGroundSpriteStruct *ptr);
bool8 sub_80A66F8(struct UnkGroundSpriteStruct *ptr);
bool8 sub_80A671C(struct UnkGroundSpriteStruct *ptr);
bool8 IsOnscreen_80A675C(struct UnkGroundSpriteStruct *ptr, PixelPos *pixPosArg);
void sub_80A67CC(struct UnkGroundSpriteStruct *ptr, struct UnkGroundSpriteSubStructx48 *a1, s32 a2);
void sub_80A68A0(struct UnkGroundSpriteStruct *ptr);
void GroundSprite_ExtendPaletteAdd(struct UnkGroundSpriteStruct *ptr, u16 a1);
void GroundSprite_ExtendPaletteDelete(struct UnkGroundSpriteStruct *ptr);
void sub_80A6E68(void);
void sub_80A6E80(void);
void sub_80A6EC8(struct UnkGroundSpriteStruct *ptr, s32 a1);
void sub_80A6EFC(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_);
void sub_80A7040(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_, s32 a3);
bool8 sub_80A7094(struct UnkGroundSpriteStruct *ptr, PixelPos *r10, PixelPos *posArg, s32 a3);
bool8 sub_80A7310(struct UnkGroundSpriteStruct *ptr, PixelPos *posArg1, PixelPos *posArg2, s32 a3);
void sub_80A73EC(void);

#endif // GUARD_GROUND_SPRITE_H
