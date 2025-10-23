#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

#include "structs/str_position.h"
#include "structs/str_ground_script.h"
#include "structs/str_dungeon_location.h"

void AllocGroundMapAction(void);
void FreeGroundMapAction(void);
void GroundMap_Reset(void);
void sub_80A4B38(void);
void sub_80A4B54(void);
void GroundMap_GetStationScript(ScriptInfoSmall *r0, s32 _groundScriptId, s32 _groupId, s32 _sectorId);
void GroundMap_ExecuteEvent(s16 scriptIndex, u32 param_2);
void GroundMap_ExecuteStation(s32 _map, s32 _group, s32 _sector, bool32 _setScriptState);
void GroundMap_ExecuteEnter(s16 param_1);
bool8 GroundMapNotifyAll(s16 param_1);
bool8 sub_80A4D48(s16 index);
s16 GetAdjustedGroundMap(s32 mapId);
void GroundMap_Select(s32 mapId_);
void GroundMap_SelectDungeon(s32 mapId_, const DungeonLocation *loc, u32 param_2);
void sub_80A56A0(u8 param_1, u8 param_2);
void sub_80A56C0(PixelPos *pos);
void sub_80A56F0(PixelPos *pos);
void sub_80A5704(PixelPos *pos);
s16 GetGroundMapID(void);
bool8 GetCurrentDungeonBounds(PixelPos *pos1, PixelPos *pos2);
bool8 sub_80A579C(PixelPos *pos1, PixelPos *pos2);
bool8 CheckMapCollision_80A585C(PixelPos *pixPos1, PixelPos *boundary);
bool8 sub_80A58C8(PixelPos *pixPos1, PixelPos *boundary);
u8 sub_80A5934(u8 param_1, PixelPos *param_2, PixelPos *param_3);
u8 sub_80A595C(u8 param_1, PixelPos *param_2, PixelPos *param_3);
u16 sub_80A5984(s32 param_1, PixelPos *param_2);
void sub_80A59A0(s32 param_1, PixelPos *param_2, u16 param_3);
void GroundMap_Action(void);
void sub_80A59DC(void);
void sub_80A5E70(void);

#endif // GUARD_GROUND_MAP_H
