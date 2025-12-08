#ifndef GUARD_GROUND_MAIN_H
#define GUARD_GROUND_MAIN_H

#include "constants/rescue_dungeon_id.h"
#include "structs/str_dungeon_setup.h"

// startMode: See enum "StartModeVal"
u32 xxx_script_related_8098468(s32 startMode);
void sub_8098C58(void);
void sub_8098CC8(void);
bool8 GroundMainGroundRequest(s32 r0, s32 r1, s32 r2);
bool8 sub_8098D80(u32 speed);
bool8 sub_8098DCC(u32 speed);
// scriptDungeon: See enum "ScriptDungeonId"
bool8 GroundMainRescueRequest(s32 scriptDungeon, s32 r1);
bool32 GroundMainGameEndRequest(u32 r0);
bool32 GroundMainGameCancelRequest(u32 r0);
bool8 sub_8098F88(void);
bool8 GetScriptMode(void);
const char *GetCurrentGroundPlaceName(void);
// scriptDungeon: See enum "ScriptDungeonId"
u8 sub_80990EC(DungeonSetupInfo *param_1, s32 scriptDungeon);
// scriptDungeon: See enum "ScriptDungeonId"
u8 sub_80991E0(DungeonSetupInfo *param_1, s16 *scriptDungeon);
// scriptDungeon: See enum "ScriptDungeonId"
void sub_8099220(DungeonSetupInfo *param_1, s32 scriptDungeon);
void sub_809927C(u8 param_1);
// See enum "RescueDungeonId"
bool8 sub_80992E0(s16 *param_1, s16 *rescueDungeonId);
bool8 sub_8099328(u8 *dungeonId);
bool8 sub_8099360(u8 *dungeonId);
bool8 sub_8099394(u8 *param);
void sub_80993C0(bool8 param);
void sub_80993D8(void);
void sub_80993E4(void);

#endif // GUARD_GROUND_MAIN_H
