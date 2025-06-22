#ifndef GUARD_GROUND_LIVES_HELPER_H
#define GUARD_GROUND_LIVES_HELPER_H

#include "structs/str_position.h"
#include "structs/str_ground_lives.h"

void nullsub_117(void);
void nullsub_118(void);
void sub_809CD68(struct GroundLives_Sub120 *dst);
void sub_809CD8C(struct GroundLives_Sub120 *dst, s32 a1);
s32 sub_809CDB8(struct GroundLives_Sub120 *dst);
u32 sub_809CDC8(struct GroundLives_Sub120 *strPtr, u32 *r6, s8 *direction, s32 *param_4, PixelPos *unused, u32 flags);
s32 DpadToDirection(u16 dpad);

#endif
