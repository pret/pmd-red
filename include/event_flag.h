#ifndef GUARD_EVENT_FLAG_H
#define GUARD_EVENT_FLAG_H

// size: 0x10
struct ScriptVarInfo {
    s16 type;
    s16 unk2;
    s16 bufOffset;
    s16 bitOffset;
    s16 arrayLen;
    s16 defaultValue;
    char *name;
};

// size: 0x8
struct ScriptVarPtr
{
    /* 0x0 */ struct ScriptVarInfo *info;
    /* 0x4 */ u8 *ptr;
};

// event_flag.s

void ThoroughlyResetScriptVars(void);
void ResetScriptVarArray(u8 *localVarBuf, s16 varId);
void ClearScriptVarArray(u8 *localVarBuf, s16 varId);
void GetScriptVarRef(struct ScriptVarPtr *out, u8 *localVarBuf, s32 varId);
s32 GetScriptVarValue(u8 *localVarBuf, s32 varId);
s32 GetScriptVarArrayValue(u8 *localVarBuf, s32 varId, u16 idx);
void SetScriptVarValue(u8 *localVarBuf, s32 varId, s32 val);
void SetScriptVarArrayValue(u8 *localVarBuf, s32 varId, u16 idx, s32 val);
s32 GetScriptVarArraySum(u8 *localVarBuf, s16 varId);
void GetScriptVarScenario(s32 varId,u32 *outMain,u32 *outSub);
void ScenarioCalc(s16 varId, s32 param_2, s32 param_3);
bool8 ScriptVarScenarioBefore(s16 param_1, u32 param_2, s32 param_3);
bool8 ScriptVarScenarioEqual(s16 param_1, u32 param_2, s32 param_3);
bool8 ScriptVarScenarioAfter(s16 param_1, u32 param_2, s32 param_3);
void sub_8001D88(void);
u32 _FlagCalc(s32 param_1, s32 param_2, u32 operation);
bool8 _FlagJudge(s32 param_1, s32 param_2, u32 operation);
u32 FlagCalc(s32 r0, s32 r1, u32 operation);
void UpdateScriptVarWithImmediate(u8 *localVarBuf, s16 varId, s32 val, u32 operation);
void UpdateScriptVarWithVar(u8 *localVarBuf, s16 dstVarId, s16 srcVarId, u32 operation);
bool8 FlagJudge(s32 r0, s32 r1, u32 operation);
bool8 sub_80022F8(u8 *param_1, s16 param_2, s32 param_3, u32 operation);
bool8 sub_8002318(u8 *param_1, s16 param_2, s16 param_3, u32 operation);
bool8 sub_80023E4(u32 param_1);
u8 sub_8002658(s16 param_1);
s16 sub_8002694(u8 param_1);
bool8 sub_80026CC(s16 r0);
void sub_80026E8(s16 r0, bool8 r1);
bool8 sub_8002700(void *r0);
bool8 sub_8002718(u8 *r0);
void sub_8002758(s32 r0);
u8 sub_800276C(void);

// .rodata
extern struct ScriptVarInfo gScriptVarInfo[];

// EWRAM
extern u8 gScriptVarBuffer[0x400];

#endif // GUARD_EVENT_FLAG_H
