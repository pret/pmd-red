#ifndef GUARD_GROUND_OBJECT_H
#define GUARD_GROUND_OBJECT_H

#include "structs/str_ground_script.h"

void AllocGroundObjects(void);
void DeleteGroundObjects(void);
void FreeGroundObjects(void);
void GroundObject_Select(s32 scriptID, s32 group, s32 sector);
void GroundObject_Cancel(s32 scriptID, s32 sector);
void GroundObject_CancelBlank(void);
s32 GroundObject_Add(s32 id_, const GroundObjectData *objectData, s32 group_, s32 sector_);
void sub_80AC1B0(s32 index_, s32 flag);
Action *GroundObject_GetAction(s32 index_);
bool8 GroundObject_GetScript(s32 index_, ScriptInfoSmall *scriptInfo, s32 a2_);
bool8 GroundObject_ExecuteScript(s32 index_, ActionUnkIds *a1, ScriptInfoSmall *script);
bool8 GroundObjectsNotifyAll(s32 index_);
bool8 GroundObjectsCancelAll(void);
s16 GroundObject_GetFlags(s32 index_, s32 *flags);
s16 sub_80AC448(s32 index_, PixelPos *pos);
s16 sub_80AC49C(s32 index_, PixelPos *pos);
s32 sub_80AC4C8(s32 index, PixelPos *a0, PixelPos *a1);
s32 sub_80AC554(s32 flag, PixelPos *param_2,PixelPos *param_3);
void GroundObject_Action(void);
void sub_80ACAD4(void);

#endif // GUARD_GROUND_OBJECT_H
