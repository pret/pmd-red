#ifndef GUARD_GROUND_EFFECT_H
#define GUARD_GROUND_EFFECT_H

#include "structs/str_ground_script.h"

void AllocGroundEffects(void);
void DeleteGroundEffects(void);
void FreeGroundEffects(void);
void GroundEffect_Select(s32 scriptID, s32 group, s32 sector);
void GroundEffect_Cancel(s32 scriptID, s32 sector);
void GroundEffect_CancelBlank(void);
s32 GroundEffect_Add(s32 _id, const GroundEffectData *effectData, s32 _group, s32 _sector);
void sub_80AD0C8(s32 _id, s32 flags);
Action *sub_80AD158(s32 index_);
bool8 GroundEffect_ExecuteScript(s32 index_, ActionUnkIds *a1, ScriptInfoSmall *script);
bool8 GroundEffectsNotifyAll(s32 index_);
bool8 GroundEffectsCancelAll(void);
s16 sub_80AD360(s32 index_, PixelPos *pos);
s16 sub_80AD3B4(s32 index_, PixelPos *pos);
void GroundEffect_Action(void);
void sub_80AD7AC(void);

#endif // GUARD_GROUND_EFFECT_H
