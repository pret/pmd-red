#ifndef GUARD_EVENT_FLAG_H
#define GUARD_EVENT_FLAG_H

enum FlagCalcOperation {
    CALC_SET,
    CALC_SUB,
    CALC_ADD,
    CALC_MUL,
    CALC_DIV,
    CALC_MOD,
    CALC_AND,
    CALC_OR,
    CALC_XOR,
    CALC_SETBIT,
    CALC_CLEARBIT,
    CALC_RANDOM,
};

enum FlagJudgeOperation {
    JUDGE_TRUE,
    JUDGE_FALSE,
    JUDGE_EQ,
    JUDGE_GT,
    JUDGE_LT,
    JUDGE_GE,
    JUDGE_LE,
    JUDGE_NE,
    JUDGE_AND_NONZERO,
    JUDGE_XOR_NONZERO, // logically identical to JUDGE_NE
    JUDGE_BIT_SET,
};

enum ScriptVarId {
    /* 0x00 */ VERSION,
    /* 0x01 */ CONDITION,
    /* 0x02 */ SCENARIO_SELECT,
    /* 0x03 */ SCENARIO_MAIN,
    /* 0x04 */ SCENARIO_SUB1,
    /* 0x05 */ SCENARIO_SUB2,
    /* 0x06 */ SCENARIO_SUB3,
    /* 0x07 */ SCENARIO_SUB4,
    /* 0x08 */ SCENARIO_SUB5,
    /* 0x09 */ SCENARIO_SUB6,
    /* 0x0a */ SCENARIO_SUB7,
    /* 0x0b */ SCENARIO_SUB8,
    /* 0x0c */ SCENARIO_SUB9,
    /* 0x0d */ GROUND_ENTER,
    /* 0x0e */ GROUND_ENTER_LINK,
    /* 0x0f */ GROUND_GETOUT,
    /* 0x10 */ GROUND_MAP,
    /* 0x11 */ GROUND_PLACE,
    /* 0x12 */ DUNGEON_SELECT,
    /* 0x13 */ DUNGEON_ENTER,
    /* 0x14 */ DUNGEON_ENTER_INDEX,
    /* 0x15 */ DUNGEON_ENTER_FREQUENCY,
    /* 0x16 */ DUNGEON_RESULT,
    /* 0x17 */ SCRIPT_MODE,
    /* 0x18 */ START_MODE,
    /* 0x19 */ CLEAR_COUNT,
    /* 0x1a */ CONDITION_KIND,
    /* 0x1b */ WEATHER_KIND,
    /* 0x1c */ PLAYER_KIND,
    /* 0x1d */ PARTNER1_KIND,
    /* 0x1e */ PARTNER2_KIND,
    /* 0x1f */ NEW_FRIEND_KIND,
    /* 0x20 */ FRIEND_SUM,
    /* 0x21 */ UNIT_SUM,
    /* 0x22 */ GOLD,
    /* 0x23 */ BANK_GOLD,
    /* 0x24 */ WARP_LIST,
    /* 0x25 */ WARP_LOCK,
    /* 0x26 */ PARTNER_TALK_KIND,
    /* 0x27 */ BASE_KIND,
    /* 0x28 */ BASE_LEVEL,
    /* 0x29 */ FLAG_KIND,
    /* 0x2a */ FLAG_KIND_CHANGE_REQUEST,
    /* 0x2b */ RESCUE_SCENARIO_ORDER_LIST,
    /* 0x2c */ RESCUE_SCENARIO_JOB_LIST,
    /* 0x2d */ RESCUE_SCENARIO_CONQUEST_LIST,
    /* 0x2e */ TRAINING_CONQUEST_LIST,
    /* 0x2f */ TRAINING_PRESENT_LIST,
    /* 0x30 */ DUNGEON_ENTER_LIST,
    /* 0x31 */ DUNGEON_CLEAR_LIST,
    /* 0x32 */ POSITION_X,
    /* 0x33 */ POSITION_Y,
    /* 0x34 */ POSITION_HEIGHT,
    /* 0x35 */ POSITION_DIRECTION,
    /* 0x36 */ GROUND_LOCAL,
    /* 0x37 */ MAP_LOCAL,
    /* 0x38 */ MAP_LOCAL_DOOR,
    /* 0x39 */ EVENT_LOCAL,
    /* 0x3a */ STATION_ITEM_STATIC,
    /* 0x3b */ STATION_ITEM_TEMP,
    /* 0x3c */ DELIVER_ITEM_STATIC,
    /* 0x3d */ DELIVER_ITEM_TEMP,
    /* 0x3e */ SHOP_TEMP,
    /* 0x3f */ INN_TEMP,
    /* 0x40 */ EVENT_S07E01,
    /* 0x41 */ EVENT_S08E01,
    /* 0x42 */ EVENT_GONBE,
    /* 0x43 */ EVENT_ORNAMENT_01,
    /* 0x44 */ EVENT_ORNAMENT_02,
    /* 0x45 */ EVENT_ORNAMENT_03,
    /* 0x46 */ EVENT_ORNAMENT_04,
    /* 0x47 */ EVENT_B01P01,
    /* 0x48 */ EVENT_T01P01,
    /* 0x49 */ EVENT_T01P02,
    /* 0x4a */ EVENT_T01P03,
    /* 0x4b */ EVENT_M01E09A_2N,
    /* 0x4c */ EVENT_M01E09A_8N,
    /* 0x4d */ EVENT_M01E10A_1N,
    /* 0x4e */ EVENT_M01E10A_3N,
    /* 0x4f */ EVENT_M01E10A_5N,
    /* 0x50 */ EVENT_M02E01A_2N,
    /* 0x51 */ SUM,
    /* 0x400 */ LOCAL0 = 0x400,
    /* 0x401 */ LOCAL1,
    /* 0x402 */ LOCAL2,
    /* 0x403 */ LOCAL3,
};

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
    /* 0x0 */ const struct ScriptVarInfo *info;
    /* 0x4 */ u8 *ptr;
};

// event_flag.s

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
bool8 SaveGlobalScriptVars(void *r0);
bool8 RestoreGlobalScriptVars(u8 *r0);

// script_vars_info.c
extern const struct ScriptVarInfo gScriptVarInfo[]; // NDS=0210FAC4

// EWRAM
extern u8 gScriptVarBuffer[0x400];

#endif // GUARD_EVENT_FLAG_H
