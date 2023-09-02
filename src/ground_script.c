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
extern void sub_809D568(void *);
extern u8 sub_80AC378(void);
extern u8 sub_80AD290(void);
extern u8 sub_80A8B74(void);
extern u8 sub_809A750(void);
extern u8 *sub_80A2460(GroundScript_ExecutePP_1 *param_1, u32);
void FatalError(u32 *, const char *, ...) __attribute__((noreturn));

typedef struct FunctionScript
{
    u32 unk0;
    u8 *funcName;
    u8 *script;
} FunctionScript;

extern FunctionScript gFunctionScriptTable[];

void sub_809D6D8(GroundScript_ExecutePP_1 *param_1, s16 index, u8 *param_3)
{
    param_1->unk14[index] = param_3;
}

bool8 sub_809D6E4(GroundScript_ExecutePP_1 *param_1, GroundScript_ExecutePP_3 *script, s16 _index)
{
    u8 *scriptPtr;
    s32 index = _index;

    scriptPtr = param_1->unk14[index];
    script->scriptPointer = scriptPtr;
    script->scriptType = index;
    script->unk6 = param_1->unk10;
    script->unk8 = param_1->unk12;
    return scriptPtr != NULL;
}

void sub_809D710(GroundScript_ExecutePP_1 *param_1, GroundScript_ExecutePP_3 *script, s16 index)
{
    s32 index_s32 = index;
    script->scriptPointer = gFunctionScriptTable[index_s32].script;
    script->scriptType = 2;
    if (param_1 != NULL) {
        script->unk6 = param_1->unk10;
        script->unk8 = param_1->unk12;
    }
    else {
        script->unk6 = -1;
        script->unk8 = -1;
    }
}

bool8 sub_809D754(GroundScript_ExecutePP_1 *param_1, DebugLocation *unused)
{
    sub_809D568(&param_1->unk24);
    sub_809D568(&param_1->unk84);
    return TRUE;
}

bool8 sub_809D770(GroundScript_ExecutePP_1 *param_1, DebugLocation *unused)
{
    sub_809D568(&param_1->unk24);
    sub_809D568(&param_1->unk84);
    param_1->unk24.unk2 = 4;
    return TRUE;
}

bool8 GroundScript_ExecutePP(GroundScript_ExecutePP_1 *param_1, s32 *param_2, GroundScript_ExecutePP_3 *param_3, const DebugLocation *unused)
{
    if ((param_3 == NULL) || (param_3->scriptPointer == NULL)) {
        return FALSE;
    }
    switch(param_3->scriptType) {
        case 2:
        case 3:
            if (param_1->unk24.scriptType == 1) {
                param_1->unk84 = param_1->unk24;
                break;
            }
            if (param_1->unk24.scriptType == 5) {
                sub_809D568(&param_1->unk84);
            }
            break;
        case 5:
            if (param_1->unk24.scriptType != 2) {
                // "execute script type error B"
                FatalError(&gUnknown_8116538, gUnknown_8116544);
            }
            if (param_1->unk84.scriptType != -1) {
                // "execute script type error C"
                FatalError(&gUnknown_8116560, gUnknown_811656C);
            }
            param_1->unk84 = param_1->unk24;
            break;
        case 0:
            if (param_1->unk24.scriptType != 1) goto _0809D84A;
            param_1->unk84 = param_1->unk24;
            break;
        case 1:
        _0809D84A:
            sub_809D568(&param_1->unk84);
            break;
        default:
            // "execute script type error %d"
            FatalError(&gUnknown_8116588, gUnknown_8116594, param_3->scriptType);
    }
    sub_809D568(&param_1->unk24);
    if (param_2 != NULL) {
        param_1->unkC = param_2[0];
    }
    else {
        sub_809D520(&param_1->unkC);
    }
    param_1->unk24.scriptType = param_3->scriptType;
    param_1->unk24.unk2 = 3;
    param_1->unk24.unkC = param_3->unk6;
    param_1->unk24.unkE = param_3->unk8;
    param_1->unk24.scriptPointer1 = param_3->scriptPointer;
    param_1->unk24.scriptPointer2 = param_3->scriptPointer;
    param_1->unk24.unk10 = 0;
    param_1->unk24.unk14 = NULL;

    if (param_1->unk0->callbacks[5] != 0) {
        param_1->unk0->callbacks[5](param_1->unk4, &param_1->unk24.unk26);
    }
    return TRUE;
}

bool8 sub_809D8C0(GroundScript_ExecutePP_1 *param_1, s32 *param_2, s16 index, DebugLocation *debug)
{
    GroundScript_ExecutePP_3 auStack28;

    sub_809D6E4(param_1,&auStack28,index);
    return GroundScript_ExecutePP(param_1, param_2, &auStack28, debug);
}

u8 sub_809D8EC(GroundScript_ExecutePP_1 *param_1, s16 param_2)
{
    s32 param_2_s32;

    param_2_s32 = param_2;

    if ((param_2 == 0) && (sub_809A750() == 0)) {
        param_1->unk24.scriptPointer1 = sub_80A2460(param_1, 0);
        return 0;
    }
    else {
        param_1->unk24.unk22 = param_2_s32;
        param_1->unk24.unk2 = 2;
        gUnknown_2039A36 = 1;
        return 1;
    }
}


bool8 GroundScript_Cancel(GroundScript_ExecutePP_1 *r0)
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

bool8 sub_809D968(GroundScript_ExecutePP_1 *param_1, s16 param_2)
{
  s16 sVar1;
  s16 sVar2;
  bool8 ret;

  s32 param_2_s16 = param_2;
  
  ret = FALSE;
  sVar1 = param_1->unk24.unk22;
  if ((sVar1 != -1) && (sVar1 == param_2_s16)) {
    param_1->unk24.unk22 = -1;
    ret = TRUE;
  }
  sVar2 = param_1->unk84.unk22;
  if ((sVar2 != -1) && (sVar2 == param_2_s16)) {
    param_1->unk84.unk22 = -1;
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

bool8 sub_809DA08(GroundScript_ExecutePP_1 *param_1, s16 index, u32 param_3)
{
  s32 index_s32;
  
  index_s32 = index;
  gUnknown_2039B48[index_s32] = param_3;
  if (index_s32 == 0) {
    if (sub_809A750() == 0) {
      return FALSE;
    }
    param_1->unk24.unk22 = index_s32;
  }
  else {
    param_1->unk24.unk22 = index_s32 | 0x80;
    gUnknown_2039A38[index_s32] = 1;
    gUnknown_2039AC0[index_s32] = 1;
  }
  param_1->unk24.unk2 = 2;
  gUnknown_2039A36 = 1;
  return TRUE;
}