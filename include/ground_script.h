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

void sub_809D490(void);
void sub_809D4B0(void);
void sub_809D508(void);
void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s32 group, s32 sector);
void InitAction2(Action *action);
bool8 Action_SavedStateIsNot0(Action *action);
bool8 sub_809D684(Action *action, ScriptInfoSmall *scriptInfo);
void SetPredefinedScript(Action *param_1, s16 index, const ScriptCommand *param_3);
bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s32 _index);
void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 scriptID);
bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused);
bool8 GroundScript_ExecutePP(Action *action, ActionUnkIds *param_2, ScriptInfoSmall *param_3, const DebugLocation *unused);
bool8 ExecutePredefinedScript(Action *param_1, ActionUnkIds *param_2, s16 index, const DebugLocation *debug);
bool8 GroundScript_Cancel(Action *r0);
bool8 GroundScriptNotify(Action *param_1, s32 param_2);
void GroundScriptLockJumpZero(s32 index);
void GroundScriptLock(s32 index, s32 unlockVal);
// Return value is enum "ESC_RetID"
s16 HandleAction(Action *action, const DebugLocation *debug);
void GroundScript_Unlock(void);

#endif // GUARD_GROUND_SCRIPT_H
