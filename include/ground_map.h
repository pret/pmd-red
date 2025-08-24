#ifndef GUARD_GROUND_MAP_H
#define GUARD_GROUND_MAP_H

#include "structs/str_position.h"

void GroundMap_Reset(void);
void AllocGroundMapAction(void);
void FreeGroundMapAction(void);
void sub_80A4B38(void);
void sub_80A4B54(void);
void sub_80A56C0(PixelPos *pos);
s16 GetAdjustedGroundMap(s32 mapId);
s16 GetGroundMapID(void);

void GroundMap_ExecuteEnter(s16);
void GroundMap_ExecuteEvent(s16 scriptIndex, u32);
void GroundMap_ExecuteStation(s32 _map, s32 _group, s32 _sector, bool32 _setScriptState);
bool8 GroundMapNotifyAll(s16);
bool8 sub_80A4D48(s16 index);
void GroundMap_Action(void);

#endif // GUARD_GROUND_MAP_H
