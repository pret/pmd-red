#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

#include "structs/str_dungeon_setup.h"

u32 xxx_script_related_8098468(s32 param_1);
void sub_8098C58(void);
void sub_8098CC8(void);
bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 sub_8098D80(u32 speed);
bool8 sub_8098DCC(u32 speed);
bool8 GroundMainRescueRequest(s32 dungeonId_, s32 r1);
bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098F88(void);
bool8 GetScriptMode(void);
const char *GetCurrentGroundPlaceName(void);
u8 sub_80990EC(struct DungeonSetupInfo *param_1, s32 param_2);
u8 sub_80991E0(struct DungeonSetupInfo *param_1, s16 *param_2);
void sub_8099220(struct DungeonSetupInfo *param_1, s32 param_2);
void sub_809927C(u8 param_1);
bool8 sub_80992E0(s16 *param_1, s16 *param_2);
bool8 sub_8099328(u8 *dungeonId);
bool8 sub_8099360(u8 *dungeonId);
bool8 sub_8099394(u8 *param);
void sub_80993C0(bool8 param);
void sub_80993D8(void);
void sub_80993E4(void);

#endif // GUARD_GROUND_MAIN_H
