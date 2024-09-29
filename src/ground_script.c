#include "global.h"
#include "debug.h"
#include "ground_script.h"

extern u8 gAnyScriptLocked;
extern u8 gScriptLocks[];
extern u32 gUnlockBranchLabels[];
extern u8 gScriptLockConds[];

extern u32 gUnknown_8116588;
extern u32 gUnknown_8116538;
extern u32 gUnknown_8116560;
extern u8 gUnknown_8116594[];
extern u8 gUnknown_8116544[];
extern u8 gUnknown_811656C[];

extern DebugLocation gUnknown_81165C8;

extern void sub_809D520(void *);
extern u8 GroundObjectsCancellAll(void);
extern u8 GroundEffectsCancelAll(void);
extern u8 GroundLivesCancelAll(void);
extern u8 IsTextboxOpen_809A750(void);
extern s32 sub_80A882C(s16);
extern s32 sub_80AC240(s16);
extern s32 sub_80AD158(s16);
void FatalError(u32 *, const char *, ...) __attribute__((noreturn));

// -1 didn't match
void sub_809D520(void *a0)
{
    u16 *ptr = a0;
    u16 v = 0xFFFF;
    *ptr = v;
}

s32 sub_809D52C(void *a0)
{
    s16 *ptr = a0;

    switch (ptr[0])
    {
    case 0: return 0;
    case 1: return sub_80A882C(ptr[1]);
    case 2: return sub_80AC240(ptr[1]);
    case 3: return sub_80AD158(ptr[1]);
    }
    return 0;
}

void InitScriptData(ScriptData *a0)
{
    s32 i;

    a0->state = -1;
    a0->savedState = 0;
    a0->script.ptr2 = 0;
    a0->script.ptr = 0;
    a0->savedScript.ptr2 = 0;
    a0->savedScript.ptr = 0;
    a0->curScriptOp = 0;
    a0->curPtr = 0;
    a0->unk22 = -1;
    a0->unk24 = 0;
    a0->unk26 = 0xFF;
    a0->branchDiscriminant = 0;
    a0->unk2A = 0;
    a0->unk2C = 0;
    a0->unk30 = 0;
    for (i = 0; i < 4; i++) {
        a0->localVars.val[i] = 0;
    }
}

void InitAction(Action *a0)
{
    s32 i;

    a0->callbacks = NULL;
    a0->parentObject = NULL;
    a0->group = -1;
    a0->sector = 0xFF;
    sub_809D520(&a0->unkC);

    for (i = 0; i < 4; i++) {
        a0->predefinedScripts[i] = NULL;
    }

    InitScriptData(&a0->scriptData);
    InitScriptData(&a0->scriptData2);
}

void InitActionWithParams(Action *action, const CallbackData *callbacks, void *parent, s16 group, s8 sector)
{
    s32 group_s32;
    s32 sector_s32;

    group_s32 = group;
    sector_s32 = sector;

    InitAction(action);

    action->callbacks = callbacks;
    action->parentObject = parent;
    action->group = group_s32;
    action->sector = sector_s32;
    action->unk8[0] = callbacks->maybeId;

    if(callbacks->getIndex)
        action->unk8[1] = callbacks->getIndex(parent);
    else
        action->unk8[1] = 0;
}

void InitAction2(Action *action)
{
    InitAction(action);
}

UNUSED s16 sub_809D654(Action *action)
{
    return action->scriptData.savedState;
}

UNUSED s16 sub_809D65C(Action *action)
{
    if(action->scriptData.savedState != 0)
        return action->scriptData.state;
    else
        return -1;
}

bool8 sub_809D678(Action *action)
{
    return action->scriptData.savedState == 0 ? FALSE : TRUE;
}

bool8 sub_809D684(Action *action, ScriptCommand **scriptPtr)
{
    if(action->scriptData.savedState != 0)
    {
        if(action->scriptData.savedScript.ptr != 0)
        {
            if(action->scriptData.savedScript.ptr2 == *scriptPtr) return 1;
        }
        else
        {
            if(action->scriptData.script.ptr2 == *scriptPtr) return 1;
        }
    }
    if(action->scriptData2.savedState != 0)
    {
        if(action->scriptData2.savedScript.ptr != 0)
        {
            if(action->scriptData2.savedScript.ptr2 == *scriptPtr) return 1;
        }
        else
        {
            if(action->scriptData2.script.ptr2 == *scriptPtr) return 1;
        }
    }
    return 0;
}

void SetPredefinedScript(Action *param_1, s16 index, ScriptCommand *param_3)
{
    param_1->predefinedScripts[index] = param_3;
}

bool8 GetPredefinedScript(Action *param_1, ScriptInfoSmall *script, s16 _index)
{
    const ScriptCommand *scriptPtr;
    s32 index = _index;

    scriptPtr = param_1->predefinedScripts[index];
    script->ptr = scriptPtr;
    script->state = index;
    script->group = param_1->group;
    script->sector = param_1->sector;
    return scriptPtr != NULL;
}

void GetFunctionScript(Action *param_1, ScriptInfoSmall *script, s16 index)
{
    s32 index_s32 = index;
    script->ptr = gFunctionScriptTable[index_s32].script;
    script->state = 2;
    if (param_1 != NULL) {
        script->group = param_1->group;
        script->sector = param_1->sector;
    }
    else {
        script->group = -1;
        script->sector = -1;
    }
}

bool8 ActionResetScriptData(Action *param_1, const DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    return TRUE;
}

bool8 ActionResetScriptDataForDeletion(Action *param_1, DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    param_1->scriptData.savedState = 4;
    return TRUE;
}

bool8 GroundScript_ExecutePP(Action *action, s32 *param_2, ScriptInfoSmall *param_3, const DebugLocation *unused)
{
    if ((param_3 == NULL) || (param_3->ptr == NULL)) {
        return FALSE;
    }
    switch(param_3->state) {
        case 2:
        case 3:
            if (action->scriptData.state == 1) {
                action->scriptData2 = action->scriptData;
                break;
            }
            if (action->scriptData.state == 5) {
                InitScriptData(&action->scriptData2);
            }
            break;
        case 5:
            if (action->scriptData.state != 2) {
                // "execute script type error B" at ../ground/ground_script.c:688
                FatalError(&gUnknown_8116538, gUnknown_8116544);
            }
            if (action->scriptData2.state != -1) {
                // "execute script type error C" at ../ground/ground_script.c:689
                FatalError(&gUnknown_8116560, gUnknown_811656C);
            }
            action->scriptData2 = action->scriptData;
            break;
        case 0:
            if (action->scriptData.state != 1) goto _0809D84A;
            action->scriptData2 = action->scriptData;
            break;
        case 1:
        _0809D84A:
            InitScriptData(&action->scriptData2);
            break;
        default:
            // "execute script type error %d" at ../ground/ground_script.c:708
            FatalError(&gUnknown_8116588, gUnknown_8116594, param_3->state);
    }
    InitScriptData(&action->scriptData);
    if (param_2 != NULL) {
        action->unkC.raw = param_2[0];
    }
    else {
        sub_809D520(&action->unkC);
    }
    action->scriptData.state = param_3->state;
    action->scriptData.savedState = 3;
    action->scriptData.script.group = param_3->group;
    action->scriptData.script.sector = param_3->sector;
    action->scriptData.script.ptr = param_3->ptr;
    action->scriptData.script.ptr2 = param_3->ptr;
    action->scriptData.savedScript.ptr = 0;
    action->scriptData.savedScript.ptr2 = NULL;

    if (action->callbacks->getDirection != 0) {
        action->callbacks->getDirection(action->parentObject, &action->scriptData.unk26);
    }
    return TRUE;
}

bool8 ExecutePredefinedScript(Action *param_1, s32 *param_2, s16 index, DebugLocation *debug)
{
    ScriptInfoSmall auStack28;

    GetPredefinedScript(param_1,&auStack28,index);
    return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

u8 GroundScriptCheckLockCondition(Action *param_1, s16 param_2)
{
    s32 param_2_s32;

    param_2_s32 = param_2;

    if ((param_2 == 0) && (IsTextboxOpen_809A750() == 0)) {
        param_1->scriptData.script.ptr = ResolveJump(param_1, 0);
        return 0;
    }
    else {
        param_1->scriptData.unk22 = param_2_s32;
        param_1->scriptData.savedState = 2;
        gAnyScriptLocked = 1;
        return 1;
    }
}


bool8 GroundScript_Cancel(Action *r0)
{
    // NOTE: Will always return TRUE
    return ActionResetScriptDataForDeletion(r0, &gUnknown_81165C8);
}

u8 GroundCancelAllEntities(void)
{
  u8 ret;

  ret = GroundLivesCancelAll();
  ret |= GroundObjectsCancellAll();
  ret |= GroundEffectsCancelAll();
  return ret;
}

bool8 GroundScriptNotify(Action *param_1, s16 param_2)
{
  s16 sVar1;
  s16 sVar2;
  bool8 ret;

  s32 param_2_s16 = param_2;
  
  ret = FALSE;
  sVar1 = param_1->scriptData.unk22;
  if ((sVar1 != -1) && (sVar1 == param_2_s16)) {
    param_1->scriptData.unk22 = -1;
    ret = TRUE;
  }
  sVar2 = param_1->scriptData2.unk22;
  if ((sVar2 != -1) && (sVar2 == param_2_s16)) {
    param_1->scriptData2.unk22 = -1;
    ret = TRUE;
  }
  return ret;
}

void GroundScriptLockJumpZero(s16 index)
{
  s32 index_s16 = index;
  gScriptLocks[index_s16] = 1;
  gUnlockBranchLabels[index_s16] = 0;
  gAnyScriptLocked = 1;
}

void GroundScriptLock(s16 index, s32 r1)
{
  s32 index_s16 = index;
  gScriptLocks[index_s16] = 1;
  gUnlockBranchLabels[index_s16] = r1;
  gAnyScriptLocked = 1;
}

bool8 GroundScriptLockCond(Action *param_1, s16 index, u32 param_3)
{
  s32 index_s32;
  
  index_s32 = index;
  gUnlockBranchLabels[index_s32] = param_3;
  if (index_s32 == 0) {
    if (IsTextboxOpen_809A750() == 0) {
      return FALSE;
    }
    param_1->scriptData.unk22 = index_s32;
  }
  else {
    param_1->scriptData.unk22 = index_s32 | 0x80;
    gScriptLocks[index_s32] = 1;
    gScriptLockConds[index_s32] = 1;
  }
  param_1->scriptData.savedState = 2;
  gAnyScriptLocked = 1;
  return TRUE;
}
