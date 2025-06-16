#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

#include "structs/str_pokemon.h"
#include "structs/str_wonder_mail.h"

bool8 sub_8098F88(void);
const char *GetCurrentGroundPlaceName(void);

bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 GroundMainRescueRequest(s32 r0, s32 r1);
bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098D80(u32 speed);
bool8 sub_80992E0(s16 *param_1, s16 *param_2);
bool8 sub_8099328(u8 *);

#endif // GUARD_GROUND_MAIN_H
