#ifndef GUARD_GROUND_SCRIPT_H
#define GUARD_GROUND_SCRIPT_H

#include "number_util.h"
#include "structs/str_ground_script.h"

// NOTE: F248 macros can match but has to be written this way to match in Blue
static inline void SetUnkInGroundEvent(const CompactPos *posPtr, PixelPos *dst)
{
    if (!(posPtr->xFlags & 4)) {
        s32 x = posPtr->xTiles << 11;
        dst->x = x;
        if (posPtr->xFlags & 2) {
            dst->x += 0x400;
        }
    }
    if (!(posPtr->yFlags & 4)) {
        s32 y = posPtr->yTiles << 11;
        dst->y = y;
        if (posPtr->yFlags & 2) {
            dst->y += 0x400;
        }
    }
}

#include "debug.h"

void sub_809D4B0(void);
void InitScriptData(ScriptData *a0);
u8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2);
void InitAction2(Action *action);
void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 index);
bool8 sub_809D684(Action *action, ScriptInfoSmall *scriptInfo);
bool8 GroundScriptLockCond(Action *param_1, s16 index, s32 param_3);
bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused);
bool8 GroundScript_ExecutePP(Action *action, ActionUnkIds *param_2, ScriptInfoSmall *param_3, const DebugLocation *unused);
bool8 ExecutePredefinedScript(Action *param_1, ActionUnkIds *param_2, s16 index, DebugLocation *debug);
void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s32 group, s32 sector);

#endif // GUARD_GROUND_SCRIPT_H
