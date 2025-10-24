#ifndef GUARD_GROUND_SPRITE_MONSTER_H
#define GUARD_GROUND_SPRITE_MONSTER_H

#include "ground_sprite.h"
#include "structs/str_position.h"

void sub_80A7428(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 monsterId_, s32 a3);
void sub_80A74E4(struct UnkGroundSpriteStruct *ptr);
void sub_80A74F0(struct UnkGroundSpriteStruct *ptr, s32 a1_, s32 a2_, s32 a3);
void sub_80A7524(struct UnkGroundSpriteStruct *ptr, s32 monsterId_, PixelPos *pixelPosArg, s32 a3);

#endif // GUARD_GROUND_SPRITE_MONSTER_H
