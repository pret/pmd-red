#ifndef GUARD_EVENT_FLAG_H
#define GUARD_EVENT_FLAG_H

#include "constants/event_flag.h"

// size: 0x8
struct ScriptVarPtr
{
    /* 0x0 */ const struct ScriptVarInfo *info;
    /* 0x4 */ u8 *ptr;
};

// event_flag.c
void ThoroughlyResetScriptVars(void);
void ResetScriptVarArray(u8 *localVarBuf, s16 varId);
void ClearScriptVarArray(u8 *localVarBuf, s16 varId);
void GetScriptVarRef(struct ScriptVarPtr *out, u8 *localVarBuf, s32 varId);
s32 GetScriptVarValue(u8 *localVarBuf, s32 varId);
s32 GetScriptVarArrayValue(u8 *localVarBuf, s32 varId, s32 idx);
void SetScriptVarValue(u8 *localVarBuf, s32 varId, s32 val);
void SetScriptVarArrayValue(u8 *localVarBuf, s32 varId, s32 idx, s32 val);
s32 GetScriptVarArraySum(u8 *localVarBuf, s16 varId);
void GetScriptVarScenario(s32 varId,u32 *outMain,u32 *outSub);
void ScenarioCalc(s16 varId, s32 main, s32 sub);
bool8 ScriptVarScenarioBefore(s16 varId, u32 main, s32 sub);
bool8 ScriptVarScenarioEqual(s16 varId, u32 main, s32 sub);
bool8 ScriptVarScenarioAfter(s16 varId, u32 main, s32 sub);
void sub_8001D88(void);
s32 _FlagCalc(s32 param_1, s32 param_2, enum FlagCalcOperation operation);
bool8 _FlagJudge(s32 param_1, s32 param_2, enum FlagJudgeOperation operation);
s32 FlagCalc(s32 r0, s32 r1, enum FlagCalcOperation operation);
void UpdateScriptVarWithImmediate(u8 *localVarBuf, s16 varId, s32 val, enum FlagCalcOperation operation);
void UpdateScriptVarWithVar(u8 *localVarBuf, s16 dstVarId, s16 srcVarId, enum FlagCalcOperation operation);
bool8 FlagJudge(s32 r0, s32 r1, enum FlagJudgeOperation operation);
bool8 JudgeVarWithImmediate(u8 *localVarBuf, s16 varId, s32 val, enum FlagJudgeOperation operation);
bool8 JudgeVarWithVar(u8 *localVarBuf, s16 varId1, s16 varId2, enum FlagJudgeOperation operation);
bool8 sub_80023E4(u32 param_1); // some kind of helper for predefined scenario checks
u8 MapIdToFriendAreaId(s16 mapId_); // map -> friend area lookup
s16 FriendAreaIdToMapId(u8 friendAreaId); // friend area -> map lookup
bool8 sub_80026CC(s16 r0);
void sub_80026E8(s16 r0, bool8 r1);
bool8 SaveGlobalScriptVars(void *dest);
bool8 RestoreGlobalScriptVars(u8 *src);

// EWRAM
#define SCRIPT_VAR_BUFFER_LEN 0x400
extern u8 gScriptVarBuffer[SCRIPT_VAR_BUFFER_LEN];

#endif // GUARD_EVENT_FLAG_H
