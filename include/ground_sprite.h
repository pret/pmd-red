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

// size: 0xC
typedef struct unkStruct_3001B7C_sub0
{
    u32 unk0;
    s32 unk4;
    struct UnkGroundSpriteStruct *unk8;
} unkStruct_3001B7C_sub0;

// size: 0x4
typedef struct unkStruct_3001B7C_sub108
{
    u16 unk0;
    s16 unk2;
} unkStruct_3001B7C_sub108;

#define UNK_3001B7C_SUB0_COUNT 22
#define UNK_3001B7C_SUB108_COUNT 2

// size: 0x110
typedef struct unkStruct_3001B7C
{
    unkStruct_3001B7C_sub0 unk0[UNK_3001B7C_SUB0_COUNT];
    unkStruct_3001B7C_sub108 unk108[UNK_3001B7C_SUB108_COUNT];
} unkStruct_3001B7C;

void GroundSprite_Reset(s32);
void GroundSprite_ExtendPaletteAdd(struct UnkGroundSpriteStruct *ptr, u16);
void GroundSprite_ExtendPaletteDelete(struct UnkGroundSpriteStruct *ptr);
void sub_80A67CC(struct UnkGroundSpriteStruct *ptr, struct UnkGroundSpriteSubStructx48 *a1, s32 a2);
void sub_80A68A0(struct UnkGroundSpriteStruct *ptr);
void sub_80A6EFC(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_);
void sub_80A7040(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_, s32 a3);
bool8 sub_80A7094(struct UnkGroundSpriteStruct *ptr, PixelPos *r10, PixelPos *posArg, s32 a3);
bool8 sub_80A7310(struct UnkGroundSpriteStruct *ptr, PixelPos *posArg1, PixelPos *posArg2, s32 a3);

#endif // GUARD_GROUND_SPRITE_H
