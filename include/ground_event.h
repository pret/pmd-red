#ifndef GUARD_GROUND_EVENT_H
#define GUARD_GROUND_EVENT_H

#include "structs/str_position.h"
#include "structs/str_ground_script.h"

void AllocGroundEvents(void);
void DeleteGroundEvents(void);
void FreeGroundEvents(void);
void GroundEvent_Select(s32 scriptID, s32 group, s32 sector);
void GroundEvent_Cancel(s32 scriptID, s32 sector);
bool8 sub_80ADC64(s32 id, ScriptInfoSmall *dst);
s16 FindGroundEvent(u32 flags, PixelPos *arg1, PixelPos *arg2);
void nullsub_124(void);

#endif // GUARD_GROUND_EVENT_H
