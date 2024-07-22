#include "global.h"
#include "debug.h"
#include "ground_script.h"

extern u8 gUnknown_2039A36;
extern u8 gUnknown_2039A38[];
extern u32 gUnknown_2039B48[];
extern u8 gUnknown_2039AC0[];

extern u32 gUnknown_8116588;
extern u32 gUnknown_8116538;
extern u32 gUnknown_8116560;
extern u8 gUnknown_8116594[];
extern u8 gUnknown_8116544[];
extern u8 gUnknown_811656C[];

extern DebugLocation gUnknown_81165C8;

extern void sub_809D520(void *);
extern void InitScriptData(void *);
extern u8 sub_80AC378(void);
extern u8 sub_80AD290(void);
extern u8 sub_80A8B74(void);
extern u8 sub_809A750(void);
extern ScriptCommand *sub_80A2460(Action *param_1, u32);
void FatalError(u32 *, const char *, ...) __attribute__((noreturn));

void SetPredefinedScript(Action *param_1, s16 index, ScriptCommand *param_3)
{
    param_1->predefinedScripts[index] = param_3;
}

bool8 sub_809D6E4(Action *param_1, ScriptInfoSmall *script, s16 _index)
{
    ScriptCommand *scriptPtr;
    s32 index = _index;

    scriptPtr = param_1->predefinedScripts[index];
    script->ptr = scriptPtr;
    script->state = index;
    script->group = param_1->group;
    script->sector = param_1->sector;
    return scriptPtr != NULL;
}

void sub_809D710(Action *param_1, ScriptInfoSmall *script, s16 index)
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

bool8 InitActionScriptData(Action *param_1, DebugLocation *unused)
{
    InitScriptData(&param_1->scriptData);
    InitScriptData(&param_1->scriptData2);
    return TRUE;
}

bool8 sub_809D770(Action *param_1, DebugLocation *unused)
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

    if (action->callbacks->func14 != 0) {
        action->callbacks->func14(action->parentObject, &action->scriptData.unk26);
    }
    return TRUE;
}

bool8 sub_809D8C0(Action *param_1, s32 *param_2, s16 index, DebugLocation *debug)
{
    ScriptInfoSmall auStack28;

    sub_809D6E4(param_1,&auStack28,index);
    return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

u8 sub_809D8EC(Action *param_1, s16 param_2)
{
    s32 param_2_s32;

    param_2_s32 = param_2;

    if ((param_2 == 0) && (sub_809A750() == 0)) {
        param_1->scriptData.script.ptr = sub_80A2460(param_1, 0);
        return 0;
    }
    else {
        param_1->scriptData.unk22 = param_2_s32;
        param_1->scriptData.savedState = 2;
        gUnknown_2039A36 = 1;
        return 1;
    }
}


bool8 GroundScript_Cancel(Action *r0)
{
    // NOTE: Will always return TRUE
    return sub_809D770(r0, &gUnknown_81165C8);
}

u8 sub_809D940(void)
{
  u8 ret;

  ret = sub_80A8B74();
  ret |= sub_80AC378();
  ret |= sub_80AD290();
  return ret;
}

bool8 sub_809D968(Action *param_1, s16 param_2)
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

void sub_809D9B8(s16 index)
{
  s32 index_s16 = index;
  gUnknown_2039A38[index_s16] = 1;
  gUnknown_2039B48[index_s16] = 0;
  gUnknown_2039A36 = 1;
}

void sub_809D9E0(s16 index, s32 r1)
{
  s32 index_s16 = index;
  gUnknown_2039A38[index_s16] = 1;
  gUnknown_2039B48[index_s16] = r1;
  gUnknown_2039A36 = 1;
}

bool8 sub_809DA08(Action *param_1, s16 index, u32 param_3)
{
  s32 index_s32;
  
  index_s32 = index;
  gUnknown_2039B48[index_s32] = param_3;
  if (index_s32 == 0) {
    if (sub_809A750() == 0) {
      return FALSE;
    }
    param_1->scriptData.unk22 = index_s32;
  }
  else {
    param_1->scriptData.unk22 = index_s32 | 0x80;
    gUnknown_2039A38[index_s32] = 1;
    gUnknown_2039AC0[index_s32] = 1;
  }
  param_1->scriptData.savedState = 2;
  gUnknown_2039A36 = 1;
  return TRUE;
}
