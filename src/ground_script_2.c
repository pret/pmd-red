#include "debug.h"
#include "global.h"
#include "event_flag.h"
#include "ground_map_1.h"
#include "ground_script.h"

extern u8 gAnyScriptLocked;
extern u8 gScriptLocks[];
extern u32 gUnlockBranchLabels[];
extern u8 gScriptLockConds[];
extern u8 gUnknown_8116848[];

s32 GroundLivesNotifyAll(s16);
s32 GroundObjectsNotifyAll(s16);
s32 GroundEffectsNotifyAll(s16);

// TODO: this is still WIP

// void GroundScript_Unlock(void) 
// {
//     s32 index;
//     u8 temp;
//     s16 temp_s16;
// 
//     if(gAnyScriptLocked != 0)
//     {
//         gAnyScriptLocked = 0;
//         for(index = 0; index < 0x81; index++)
//         {
//             if(gScriptLocks[index] != 0)
//             {
//                 Log(1, gUnknown_8116848, index);
//                 temp = GroundMapNotifyAll(index);
//                 temp |= GroundLivesNotifyAll(index);
//                 temp |= GroundObjectsNotifyAll(index);
//                 temp |= GroundEffectsNotifyAll(index);
// 
//                 if(gScriptLockConds[index] != 0)
//                 {
//                    if (temp != 0)
//                    {
//                         temp_s16 = index;
//                         temp_s16 |= 0x80;
//                         GroundMapNotifyAll(temp_s16);
//                         GroundLivesNotifyAll(temp_s16);
//                         GroundObjectsNotifyAll(temp_s16);
//                         GroundEffectsNotifyAll(temp_s16);
//                         gScriptLockConds[index] = 0;
//                    }
//                 }
//                 else {
//                    gScriptLocks[index] = 0;
//                 }
//             }
//         }
//     }
// }

const ScriptCommand *FindLabel(Action *action, s32 r1)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr2;
    const ScriptCommand *scriptPtr;

    scriptPtr2 = action->scriptData.script.ptr2;
    scriptPtr = scriptPtr2 + 1;

    while(1) {
        script = *scriptPtr;
        scriptPtr++;

        if(script.op == 0xF4)
        {
            if(r1 == script.argShort)
                return scriptPtr;
        }
    }
}

const ScriptCommand *ResolveJump(Action *action, s32 r1)
{
    ScriptCommand script;
    const ScriptCommand *scriptPtr;
    s32 temp;

    scriptPtr = action->scriptData.script.ptr;

    while(1) {
        script = *scriptPtr;

        if (script.op == 0xCC)
        {
            if(FlagJudge(r1, script.arg1, JUDGE_EQ))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == 0xCD)
        {
            if(FlagJudge(r1, script.arg1, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else if (script.op == 0xCE)
        {
            temp = GetScriptVarValue(action->scriptData.localVars.buf, (s16)script.arg1);
            if(FlagJudge(r1, temp, script.argByte))
                return FindLabel(action, script.argShort);
        }
        else
        {
            return scriptPtr;
        }
        scriptPtr++;
    }
}

