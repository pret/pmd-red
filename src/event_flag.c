#include "global.h"
#include "globaldata.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "constants/ground_map.h"
#include "items.h"
#include "event_flag.h"
#include "debug.h"
#include "memory.h"
#include "friend_area.h"
#include "rescue_team_info.h"
#include "other_random.h"
#include "friend_area.h"
#include "rescue_scenario.h"
#include "adventure_info.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "ground_place.h"
#include "ground_main.h"
#include "script_vars_info.h"
#include "training_maze.h"

EWRAM_DATA u8 gScriptVarBuffer[SCRIPT_VAR_BUFFER_LEN] = {0}; // NDS=020876DC

#include "data/event_flag.h"

// arm9.bin::0200FF68
void ThoroughlyResetScriptVars(void)
{
    s32 i;
    s32 bufferId;

    for (bufferId = 0; bufferId < SCRIPT_VAR_BUFFER_LEN; bufferId++) {
        gScriptVarBuffer[bufferId] = 0;
    }

    // Doesn't touch the last var SUM
    for (i = 0; i < SCRIPT_VARS_COUNT - 1; i = (s16) (i + 1)) {
        const struct ScriptVarInfo *varInfo = &gScriptVarInfo[i];
        if (varInfo->type != SCRIPT_VAR_TYPE_0 && varInfo->type != SCRIPT_VAR_TYPE_SPECIAL) {
            u16 j;
            for (j = 0; j < varInfo->arrayLen; j++) {
                SetScriptVarArrayValue(NULL, i, j, varInfo->defaultValue);
            }
        }
    }
    ClearScriptVarArray(NULL, CONDITION);
    ScenarioCalc(SCENARIO_SELECT,0,0);
    ScenarioCalc(SCENARIO_MAIN,0,0);
    ScenarioCalc(SCENARIO_SUB1,0,0);
    ScenarioCalc(SCENARIO_SUB2,0,0);
    ScenarioCalc(SCENARIO_SUB3,0,0);
    ScenarioCalc(SCENARIO_SUB4,0,0);
    ScenarioCalc(SCENARIO_SUB5,0,0);
    ScenarioCalc(SCENARIO_SUB6,0,0);
    ScenarioCalc(SCENARIO_SUB7,0,0);
    ScenarioCalc(SCENARIO_SUB8,0,0);
    ScenarioCalc(SCENARIO_SUB9,0,0);
    SetScriptVarValue(NULL,GROUND_ENTER,MAP_PERSONALITY_TEST_CYAN);
    SetScriptVarValue(NULL,GROUND_ENTER_LINK,0);
    SetScriptVarValue(NULL,GROUND_GETOUT,MAP_PERSONALITY_TEST_CYAN);
    SetScriptVarValue(NULL,GROUND_MAP,-1);
    SetScriptVarValue(NULL,GROUND_PLACE,GROUND_PLACE_NEW_GAME);
    SetScriptVarValue(NULL,DUNGEON_SELECT,-1);
    SetScriptVarValue(NULL,DUNGEON_ENTER,0);
    SetScriptVarValue(NULL,DUNGEON_ENTER_INDEX,-1);
    SetScriptVarValue(NULL,DUNGEON_RESULT,0);
    SetScriptVarValue(NULL,START_MODE,0);
    SetScriptVarValue(NULL,CLEAR_COUNT,0);
    SetScriptVarValue(NULL,WEATHER_KIND,-1);
    SetScriptVarValue(NULL,PLAYER_KIND,0);
    SetScriptVarValue(NULL,PARTNER1_KIND,0);
    SetScriptVarValue(NULL,PARTNER2_KIND,0);
    SetScriptVarValue(NULL,NEW_FRIEND_KIND,0);
    ClearScriptVarArray(NULL,WARP_LIST);
    SetScriptVarValue(NULL,WARP_LOCK,0);
    SetScriptVarValue(NULL,PARTNER_TALK_KIND,0);
    SetScriptVarValue(NULL,BASE_KIND,0);
    SetScriptVarValue(NULL,BASE_LEVEL,0);
    SetScriptVarValue(NULL,FLAG_KIND,0);
    SetScriptVarValue(NULL,FLAG_KIND_CHANGE_REQUEST,0);
    ClearScriptVarArray(NULL,RESCUE_SCENARIO_ORDER_LIST);
    ClearScriptVarArray(NULL,RESCUE_SCENARIO_JOB_LIST);
    ClearScriptVarArray(NULL,RESCUE_SCENARIO_CONQUEST_LIST);
    ClearScriptVarArray(NULL,TRAINING_CONQUEST_LIST);
    ClearScriptVarArray(NULL,TRAINING_PRESENT_LIST);
    ClearScriptVarArray(NULL,DUNGEON_ENTER_LIST);
    ClearScriptVarArray(NULL,DUNGEON_CLEAR_LIST);
    ClearScriptVarArray(NULL,EVENT_S08E01);
    sub_80972F4();
}

#if (GAME_VERSION == VERSION_RED)
UNUSED void sub_8001564(void)
{
    nullsub_128();
}
#endif

// arm9.bin::0200FEB4
void ResetScriptVarArray(u8 *localVarBuf, s16 varId_)
{
    const struct ScriptVarInfo *infoPtr;
    u16 i;
    s32 varId = varId_;

    if (varId < LOCAL0) {
        infoPtr = &gScriptVarInfo[varId];
    }
    else {
        infoPtr = &sLocalScriptVarInfo[varId - LOCAL0];
    }

    for (i = 0; i < infoPtr->arrayLen; i++) {
        SetScriptVarArrayValue(localVarBuf,varId,i,infoPtr->defaultValue);
    }
}

// arm9.bin::0200FE04
void ClearScriptVarArray(u8 *localVarBuf, s16 varId_)
{
    const struct ScriptVarInfo *infoPtr;
    u16 i;
    s32 varId = varId_;

    if (varId < LOCAL0) {
        infoPtr = &gScriptVarInfo[varId];
    }
    else {
        infoPtr = &sLocalScriptVarInfo[varId - LOCAL0];
    }

    for (i = 0; i < infoPtr->arrayLen; i++) {
        SetScriptVarArrayValue(localVarBuf,varId,i,0);
    }
}

// arm9.bin::0200FD60
void GetScriptVarRef(struct ScriptVarPtr *out, u8 *localVarBuf, s32 varId_)
{
    const struct ScriptVarInfo *infoPtr;
    s32 varId = (s16) varId_;

    if (varId < LOCAL0) {
        infoPtr = &gScriptVarInfo[varId];
        out->info = infoPtr;
        out->ptr = &gScriptVarBuffer[infoPtr->bufOffset];
    }
    else {
        infoPtr = &sLocalScriptVarInfo[varId - LOCAL0];
        out->info = infoPtr;
        out->ptr = &localVarBuf[infoPtr->bufOffset * 4];
    }
}

// arm9.bin::0200FC00
s32 GetScriptVarValue(u8 *localVarBuf, s32 varId_)
{
    struct ScriptVarPtr sp;
    s32 varId = (s16) varId_;

    GetScriptVarRef(&sp, localVarBuf, varId);

    switch (sp.info->type) {
        case SCRIPT_VAR_TYPE_BIT: {
            s32 bitOffset = sp.info->bitOffset;
            u8 a = 1 << bitOffset;
            return (*sp.ptr & a) != FALSE; // Read bit-packed bool flag
        }
        case SCRIPT_VAR_TYPE_U8:
        case SCRIPT_VAR_TYPE_U8_2:
            return *((u8 *)sp.ptr);
        case SCRIPT_VAR_TYPE_S8:
            return *((s8 *)sp.ptr);
        case SCRIPT_VAR_TYPE_U16:
            return *((u16 *)sp.ptr);
        case SCRIPT_VAR_TYPE_S16:
            return *((s16 *)sp.ptr);
        case SCRIPT_VAR_TYPE_S32:
            return *((s32 *)sp.ptr);
        case SCRIPT_VAR_TYPE_SPECIAL:
            switch ((s16)varId) {
                case SCRIPT_MODE:
                    return GetScriptMode() != FALSE;
                case FRIEND_SUM:
                    return GetFriendSum_808D480();
                case UNIT_SUM:
                    return GetUnitSum_808D544(0);
                case GOLD:
                    return gTeamInventoryRef->teamMoney;
                case BANK_GOLD:
                    return gTeamInventoryRef->teamSavings;
            }
        default:
            return 0;
    }
}

// arm9.bin::0200FA50
s32 GetScriptVarArrayValue(u8 *localVarBuf, s32 varId_, s32 idx_)
{
    struct ScriptVarPtr sp;
    s32 varId = (s16) varId_;
    s32 idx = (u16) (idx_);

    GetScriptVarRef(&sp, localVarBuf, varId);

    switch (sp.info->type) {
        case SCRIPT_VAR_TYPE_BIT: {
            s32 bitOffset = (u16) sp.info->bitOffset;
            u16 flagNum = idx + bitOffset;
            u8 *a = &sp.ptr[flagNum / 8];
            u8 b = 1 << (flagNum % 8);
            return (*a & b) != FALSE; // Read bit-packed bool flag
        }
        case SCRIPT_VAR_TYPE_U8:
        case SCRIPT_VAR_TYPE_U8_2:
            return ((u8 *)sp.ptr)[idx];
        case SCRIPT_VAR_TYPE_S8:
            return ((s8 *)sp.ptr)[idx];
        case SCRIPT_VAR_TYPE_U16:
            return ((u16 *)sp.ptr)[idx];
        case SCRIPT_VAR_TYPE_S16:
            return ((s16 *)sp.ptr)[idx];
        case SCRIPT_VAR_TYPE_S32:
            return ((u32 *)sp.ptr)[idx];
        case SCRIPT_VAR_TYPE_SPECIAL:
            switch ((s16)varId) {
                case SCRIPT_MODE:
                    return GetScriptMode() != FALSE;
                case FRIEND_SUM:
                    return GetFriendSum_808D480();
                case UNIT_SUM:
                    return GetUnitSum_808D544(0);
                case GOLD:
                    return gTeamInventoryRef->teamMoney;
                case BANK_GOLD:
                    return gTeamInventoryRef->teamSavings;
            }
        default:
            return 0;
    }
}

// arm9.bin::0200F808
void SetScriptVarValue(u8 *localVarBuf, s32 varId_, s32 val)
{
    s32 varID;
    struct ScriptVarPtr sp;

    varID = (s16)varId_;
    GetScriptVarRef(&sp, localVarBuf, varID);

    switch (sp.info->type) {
        case SCRIPT_VAR_TYPE_BIT: {
            u8 bVar1 = 1 << sp.info->bitOffset;

            if (val != 0)
                *sp.ptr |= bVar1;
            else
                *sp.ptr = (bVar1 | *sp.ptr) ^ bVar1;
            break;
        }
        case SCRIPT_VAR_TYPE_U8: {
            *((u8 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S8: {
            *((s8 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_U8_2: {
            *((u8 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_U16: {
            *((u16 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S16: {
            *((s16 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S32: {
            *((s32 *)sp.ptr) = val;
            break;
        }
        case SCRIPT_VAR_TYPE_SPECIAL: {
            switch (varID) {
                case GOLD: {
                    gTeamInventoryRef->teamMoney = val;
                    break;
                }
                case BANK_GOLD: {
                    gTeamInventoryRef->teamSavings = val;
                    break;
                }
            }
        }
    }
}

// arm9.bin::0200F5A8
void SetScriptVarArrayValue(u8 *localVarBuf, s32 varId_, s32 idx_, s32 val)
{
    s32 varID;
    struct ScriptVarPtr sp;
    s32 idx;

    varID = (s16)varId_;
    idx = (u16)idx_;
    GetScriptVarRef(&sp, localVarBuf, varID);

    switch (sp.info->type) {
        case SCRIPT_VAR_TYPE_BIT: {
            s32 bitOffset = (u16)sp.info->bitOffset;
            u16 flagNum = idx + bitOffset;
            u8 *a = &sp.ptr[flagNum / 8];
            u8 bVar1 = 1 << (flagNum % 8);
            if (val != 0)
                *a |= bVar1;
            else
                *a = (bVar1 | *a) ^ bVar1;
            break;
        }
        case SCRIPT_VAR_TYPE_U8: {
            ((u8 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S8: {
            ((s8 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_U8_2: {
            ((u8 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_U16: {
            ((u16 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S16: {
            ((s16 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_S32: {
            ((s32 *)sp.ptr)[idx] = val;
            break;
        }
        case SCRIPT_VAR_TYPE_SPECIAL: {
            switch (varID) {
                case GOLD: {
                    gTeamInventoryRef->teamMoney = val;
                    break;
                }
                case BANK_GOLD: {
                    gTeamInventoryRef->teamSavings = val;
                    break;
                }
            }
        }
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static u8 *GetScriptVarPointer(s16 varId)
{
    struct ScriptVarPtr local_1c;

    GetScriptVarRef(&local_1c,0,varId);
    return local_1c.ptr;
}

UNUSED static s16 GetScriptVarArrayLength(s16 varId)
{
    struct ScriptVarPtr local_1c;

    GetScriptVarRef(&local_1c,0,varId);
    return local_1c.info->arrayLen;
}
#endif

// arm9.bin::0200F544
s32 GetScriptVarArraySum(u8 *localVarBuf, s16 varId)
{
    s32 counter;
    s32 total;
    struct ScriptVarPtr local_1c;
    s32 varId_s32;

    varId_s32 = varId;

    total = 0;
    GetScriptVarRef(&local_1c, 0, varId_s32);
    for(counter = 0; counter < local_1c.info->arrayLen; counter++)
    {
        total += GetScriptVarArrayValue(localVarBuf, varId_s32, (u16) counter);
    }
    return total;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void GetScriptVarString(s16 varId, u8 *buf, s32 maxLen)
{
  u8 *r1;
  s32 r2;
  u8 r0;
  struct ScriptVarPtr local_10;

  GetScriptVarRef(&local_10,0,varId);
  for (r1 = local_10.ptr, r2 = 0; r2 < maxLen; r2++) {
    r0 = *r1;
    if (*r1++ == 0) break;
    *buf = r0;
    buf++;
  }
 *buf = 0;
}

UNUSED static void ScriptVarStringPopFirstChar(s16 varId,u32 param_2,s32 maxLen)
{
  u8 *r1;
  s32 r2;
  u8 r0;
  struct ScriptVarPtr local_10;

  GetScriptVarRef(&local_10,0,varId);
  for (r1 = local_10.ptr, r2 = 0; r2 < maxLen; r1++, r2++) {
    r0 = *r1;
    if (*r1++ == 0) break;
    *r1 = r0;
  }
  if (r2 < local_10.info->arrayLen) {
    for(; r2 < local_10.info->arrayLen; r1++, r2++)
    {
      *r1 = 0;
    }
  }
}
#endif

// arm9.bin::0200F508
void GetScriptVarScenario(s32 varID, u32 *outMain, u32 *outSub)
{
  *outMain = GetScriptVarArrayValue(NULL, (s16)varID, 0);
  *outSub = GetScriptVarArrayValue(NULL, (s16)varID, 1);
}

// arm9.bin::0200F36C
void ScenarioCalc(s16 param_1,s32 param_2,s32 param_3)
{
  s32 param_1_s32;
  u32 local_18;
  u32 local_14;

  param_1_s32 = param_1;
  GetScriptVarScenario(param_1_s32,&local_18,&local_14);
  Log(6,"SCENARIO CALC [%3d] %4d %4d -> %4d %4d",param_1_s32,local_18,local_14,param_2,param_3);
  if ((param_1_s32 == 3) && ((param_2 != local_18 || (param_3 != local_14)))) {
    SetScriptVarValue(NULL,CLEAR_COUNT,0);
  }
  SetScriptVarArrayValue(NULL,param_1_s32,0,param_2);
  SetScriptVarArrayValue(NULL,param_1_s32,1,param_3);

  switch(param_1_s32)
  {
      case 3:
        if (param_2 > 0 && param_2 < 28) {
            if (ScriptVarScenarioAfter(SCENARIO_MAIN,8,-1)) {
                SetAdventureAchievement(AA_HILL_OF_ANCIENTS);
            }
            if (ScriptVarScenarioAfter(SCENARIO_MAIN,11,3)) {
                SetAdventureAchievement(AA_FUGITIVE);
            }
            if (ScriptVarScenarioAfter(SCENARIO_MAIN,17,0)) {
                SetAdventureAchievement(AA_PREVENT_METEOR);
            }
        }
        break;
      case 4:
        if (!ScriptVarScenarioBefore(SCENARIO_SUB1,31,0)) {
            SetAdventureAchievement(AA_TEAM_BASE_DONE);
        }
        if (!ScriptVarScenarioBefore(SCENARIO_SUB1,32,0)) {
            SetAdventureAchievement(AA_SMEARGLE);
        }
        break;
      case 0xC:
        if(!ScriptVarScenarioBefore(SCENARIO_SUB9,55,2)) {
            SetAdventureAchievement(AA_BROKE_CURSE);
        }
        break;
  }
}

// arm9.bin::0200F2D4
bool8 ScriptVarScenarioBefore(s16 varId,u32 pMain,s32 pSub)
{
  s32 sMain;
  s32 sSub;

  sMain = GetScriptVarArrayValue(NULL, varId, 0);
  sSub = GetScriptVarArrayValue(NULL, varId, 1);
  if (sMain == 0x3a) {
    // DS: Assert(FALSE, "debug mode scenario comp %3d %3d %3d", varId, pMain, pSub)
    return FALSE;
  } else if (sMain < pMain) {
    return TRUE;
  } else if (pSub >= 0 && sMain == pMain && sSub < pSub) {
    return TRUE;
  } else {
    return FALSE;
  }
}

// arm9.bin::0200F270
bool8 ScriptVarScenarioEqual(s16 varId,u32 pMain,s32 pSub)
{
  s32 sMain;
  s32 sSub;

  sMain = GetScriptVarArrayValue(NULL, varId, 0);
  sSub = GetScriptVarArrayValue(NULL, varId, 1);
  if (sMain == pMain) {
    if (pSub < 0) return TRUE;
    if (sSub == pSub) return TRUE;
  }
  return FALSE;
}

// arm9.bin::0200F1d8
bool8 ScriptVarScenarioAfter(s16 varId, u32 pMain, s32 pSub)
{
  s32 sMain;
  s32 sSub;

  sMain = GetScriptVarArrayValue(NULL, varId, 0);
  sSub = GetScriptVarArrayValue(NULL, varId, 1);
  if (sMain == 58) {
    // DS: Assert(FALSE, "debug mode scenario comp %3d %3d %3d", varId, pMain, pSub)
    return FALSE;
  } else if (sMain > pMain) {
    return TRUE;
  } else if (pSub >= 0 && sMain == pMain && sSub > pSub) {
    return TRUE;
  } else {
    return FALSE;
  }
}

// arm9.bin::0200ECE0
void sub_8001D88(void)
{
    u32 sMain_sub;
    u32 sMain_main;

    GetScriptVarScenario(SCENARIO_MAIN, &sMain_main, &sMain_sub);
    if (sMain_main < 1 || sMain_main > 0x1b)
        return;

    if (ScriptVarScenarioBefore(SCENARIO_SUB1,31,0) != 0) {
        if (ScriptVarScenarioAfter(SCENARIO_MAIN,0xf,7) != 0) {
            ScenarioCalc(SCENARIO_SUB1,31,0);
            SetRescueScenarioConquered(RESCUE_DUNGEON_UPROAR_FOREST, TRUE);
            SetScriptVarValue(NULL,BASE_LEVEL,2);
        }
        else {
            if ((ScriptVarScenarioEqual(SCENARIO_SUB1,0,0)) && (ScriptVarScenarioAfter(SCENARIO_MAIN,0xf,3))) {
                ScenarioCalc(SCENARIO_SUB1,0x1d,1);
            }
        }
    }
    if ((ScriptVarScenarioEqual(SCENARIO_SUB1,0x1f,0)) && (GetFriendAreaStatus(SKY_BLUE_PLAINS))) {
        ScenarioCalc(SCENARIO_SUB1,0x1f,1);
        sub_809733C(RESCUE_DUNGEON_HOWLING_FOREST, TRUE);
    }
    if (sMain_main > 0x11) {
        sub_80973A8(RESCUE_DUNGEON_WATERFALL_POND, TRUE);
        if (FindItemInInventory(ITEM_HM_DIVE) != -1 || gTeamInventoryRef->teamStorage[ITEM_HM_DIVE] != 0 || ScriptVarScenarioAfter(SCENARIO_SUB2,0x21,3)) {
            sub_80973A8(RESCUE_DUNGEON_SOLAR_CAVE, TRUE);
        }
        if (GetFriendAreaStatus(FURNACE_DESERT) != 0) {
            sub_80973A8(RESCUE_DUNGEON_DESERT_REGION, TRUE);
        }
        if (GetFriendAreaStatus(BOULDER_CAVE)) {
            sub_80973A8(RESCUE_DUNGEON_SOUTHERN_CAVERN, TRUE);
        }
        if (GetFriendAreaStatus(DRAGON_CAVE)) {
            sub_80973A8(RESCUE_DUNGEON_WYVERN_HILL, TRUE);
        }
        if (GetFriendAreaStatus(SECRETIVE_FOREST)) {
            sub_80973A8(RESCUE_DUNGEON_DARKNIGHT_RELIC, TRUE);
        }
        if (GetFriendAreaStatus(SERENE_SEA)) {
            sub_80973A8(RESCUE_DUNGEON_GRAND_SEA, TRUE);
            sub_80973A8(RESCUE_DUNGEON_FAR_OFF_SEA, TRUE);
        }
        if (GetFriendAreaStatus(AGED_CHAMBER_AN) && GetFriendAreaStatus(AGED_CHAMBER_O_EXCLAIM)) {
            sub_80973A8(RESCUE_DUNGEON_UNOWN_RELIC, TRUE);
        }
        if (ScriptVarScenarioEqual(SCENARIO_SUB2,0,0)) {
            ScenarioCalc(SCENARIO_SUB2,0x21,1);
        }
        if ((FindItemInInventory(ITEM_HM_SURF) != -1) || (gTeamInventoryRef->teamStorage[ITEM_HM_SURF] != 0)) {
            if (ScriptVarScenarioEqual(SCENARIO_SUB4,0,0)) {
                ScenarioCalc(SCENARIO_SUB4,0x26,1);
            }
            if ((ScriptVarScenarioEqual(SCENARIO_SUB6,0,0)) && (GetFriendAreaStatus(SOUTHERN_ISLAND))) {
                ScenarioCalc(SCENARIO_SUB6,0x2e,1);
            }
        }
        if (!ScriptVarScenarioBefore(SCENARIO_SUB6,0x30,0)) {
            if (ScriptVarScenarioEqual(SCENARIO_SUB2,0x22,0) && HasRecruitedMon(MONSTER_ARTICUNO) && HasRecruitedMon(MONSTER_ZAPDOS) && HasRecruitedMon(MONSTER_MOLTRES)) {
                ScenarioCalc(SCENARIO_SUB2,0x22,1);
            }
            if ((ScriptVarScenarioEqual(SCENARIO_SUB8,0,0) && (ScriptVarScenarioAfter(SCENARIO_SUB2,0x21,3))) &&
                 (GetFriendAreaStatus(SKY_BLUE_PLAINS))) {
                ScenarioCalc(SCENARIO_SUB8,0x33,1);
            }
            if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
                sub_80973A8(RESCUE_DUNGEON_JOYOUS_TOWER, TRUE);
            }
            if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
                sub_80973A8(RESCUE_DUNGEON_PURITY_FOREST, TRUE);
            }
        }
        if (!ScriptVarScenarioBefore(SCENARIO_SUB2,0x22,0)) {
            if (ScriptVarScenarioEqual(SCENARIO_SUB7,0,0)) {
                ScenarioCalc(SCENARIO_SUB7,0x31,1);
                sub_809733C(RESCUE_DUNGEON_BURIED_RELIC, TRUE);
            }
            if ((ScriptVarScenarioEqual(SCENARIO_SUB9,0,0)) && (!ScriptVarScenarioBefore(SCENARIO_SUB8,0x34,0))) {
                ScenarioCalc(SCENARIO_SUB9,0x35,1);
            }
        }
        if ((ScriptVarScenarioEqual(SCENARIO_SUB3,0,0)) && (HasRecruitedMon(MONSTER_LUGIA))) {
            ScenarioCalc(SCENARIO_SUB3,0x24,1);
        }
        if ((ScriptVarScenarioEqual(SCENARIO_SUB5,0,0)) && (HasRecruitedMon(MONSTER_HO_OH))) {
            ScenarioCalc(SCENARIO_SUB5,0x2c,1);
        }
    }
}

// arm9.bin::0200EC08
s32 _FlagCalc(s32 param_1, s32 param_2, enum FlagCalcOperation operation)
{
  switch(operation) {
    case CALC_SET:
        return param_2;
    case CALC_SUB:
        return param_1 - param_2;
    case CALC_ADD:
        return param_1 + param_2;
    case CALC_MUL:
        return param_1 * param_2;
    case CALC_DIV:
        return param_1 / param_2;
    case CALC_MOD:
        return param_1 % param_2;
    case CALC_AND:
        return param_1 & param_2;
    case CALC_OR:
        return param_1 | param_2;
    case CALC_XOR:
        return param_1 ^ param_2;
    case CALC_SETBIT:
        return (1 << param_2) | param_1;
    case CALC_CLEARBIT:
        return param_1 & ~(1 << param_2);
    case CALC_RANDOM:
        return OtherRandInt(param_2);
    default:
        FATAL_ERROR_ARGS("../main/event_flag.c", 1361, "event flag expansion error %d", operation);
  }
}

// arm9.bin::0200EAE4
bool8 _FlagJudge(s32 param_1, s32 param_2, enum FlagJudgeOperation operation)
{
  switch(operation) {
      case JUDGE_TRUE:
        return TRUE;
      case JUDGE_FALSE:
        return FALSE;
      case JUDGE_EQ:
        return param_1 == param_2;
      case JUDGE_NE:
        return param_1 != param_2;
      case JUDGE_GT:
        return param_1 > param_2;
      case JUDGE_GE:
        return param_1 >= param_2;
      case JUDGE_LT:
        return param_1 < param_2;
      case JUDGE_LE:
        return param_1 <= param_2;
      case JUDGE_AND_NONZERO:
          return (param_1 & param_2) != 0;
      case JUDGE_XOR_NONZERO:
        return (param_1 ^ param_2) != 0;
      case JUDGE_BIT_SET:
        return param_1 >> (param_2) & 1;
      default:
        FATAL_ERROR_ARGS("../main/event_flag.c", 1404, "event flag rule error %d", operation);
  }
}

// arm9.bin::0200EAD8
s32 FlagCalc(s32 r0, s32 r1, enum FlagCalcOperation operation)
{
    return _FlagCalc(r0, r1, operation);
}

// arm9.bin::0200EA98
void UpdateScriptVarWithImmediate(u8 *param_1, s16 param_2, s32 param_3, enum FlagCalcOperation operation)
{
  u32 uVar1;
  u32 uVar3;

  uVar1 = GetScriptVarValue(param_1,param_2);
  uVar3 = _FlagCalc(uVar1,param_3,operation);
  SetScriptVarValue(param_1,param_2,uVar3);
}

// arm9.bin::0200EA4C
void UpdateScriptVarWithVar(u8 *param_1, s16 param_2, s16 param_3, enum FlagCalcOperation operation)
{
  s32 uVar1;
  s32 uVar2;
  s32 uVar3;

  s32 param_2_s32 = param_2;
  s32 param_3_s32 = param_3;


  uVar1 = GetScriptVarValue(param_1,param_2_s32);
  uVar2 = GetScriptVarValue(param_1,param_3_s32);
  uVar3 = _FlagCalc(uVar1,uVar2,operation);
  SetScriptVarValue(param_1,param_2_s32,uVar3);
}

// arm9.bin::0200EA40
bool8 FlagJudge(s32 r0, s32 r1, enum FlagJudgeOperation operation)
{
    return _FlagJudge(r0, r1, operation);
}

// arm9.bin::0200EA18
bool8 JudgeVarWithImmediate(u8 *param_1, s16 param_2, s32 param_3, enum FlagJudgeOperation operation)
{
  s32 uVar1;

  uVar1 = GetScriptVarValue(param_1, param_2);
  return _FlagJudge(uVar1,param_3,operation);
}

// arm9.bin::0200E9D8
bool8 JudgeVarWithVar(u8 *param_1, s16 param_2, s16 param_3, enum FlagJudgeOperation operation)
{
  s32 uVar1;
  s32 uVar2;

  s32 param_2_s32 = param_2;
  s32 param_3_s32 = param_3;

  uVar1 = GetScriptVarValue(param_1,param_2_s32);
  uVar2 = GetScriptVarValue(param_1,param_3_s32);
  return _FlagJudge(uVar1,uVar2,operation);
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static s32 sub_8002354(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].num;
  }
  else {
    return -1;
  }
}

UNUSED static const u8 *sub_8002374(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].text;
  }
  else {
    return "error number"; // error number
  }
}

UNUSED static const u8 *sub_8002394(u32 param_1)
{
  if (param_1 - 0x12 < 9) {
    return  gUnknown_80B714C[param_1 - 0x12];
  }
  else if (param_1 == 0xf) {
    return "1-1"; // 1-1
  }
  else {
    return "NONE";
  }
}

UNUSED static const u8 *sub_80023C4(u32 param_1)
{
  if (param_1 < 4) {
   return gUnknown_80B71A0[param_1]; // CISTART, CECONTINUE, CNLAST, CWEND
  }
  else {
    return "NONE";
  }
}
#endif

// arm9.bin::0200E654
bool8 CheckQuest(s32 questID)
{
  switch (questID) {
    case QUEST_SET_TEAM_NAME:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 2, -1);
    case QUEST_UNK1:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 3, 3);
    case QUEST_CAN_ACCESS_JOBS:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 4, 3);
    case QUEST_CAN_RECRUIT:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 5, 0);
    case QUEST_SQUARE_ASLEEP:
        return (ScriptVarScenarioAfter(SCENARIO_MAIN, 11, 0) && ScriptVarScenarioBefore(SCENARIO_MAIN, 13, 0));
    case QUEST_UNK5:
        return (ScriptVarScenarioAfter(SCENARIO_MAIN, 11, 3) && ScriptVarScenarioBefore(SCENARIO_MAIN, 15, 0));
    case QUEST_REACHED_POSTGAME:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 17, -1);
    case QUEST_UNLOCKED_EVOLUTIONS:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 18, 2);
    case QUEST_CAN_CHANGE_LEADER:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 18, 3);
    case QUEST_CAN_DEPOSIT_PARTNER:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 18, -1);
    case QUEST_UNK10:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 5, 4);
    case QUEST_UNK11: // Never checked? Same as above.
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 5, 4);
    case QUEST_UNK12:
        return (!ScriptVarScenarioEqual(SCENARIO_MAIN, 11, 2) && !ScriptVarScenarioEqual(SCENARIO_MAIN, 11, 3));
    case QUEST_IN_WORLD_CALAMITY:
        return ScriptVarScenarioEqual(SCENARIO_MAIN, 16, 2);
    case QUEST_MAZE_14:
        return !ScriptVarScenarioBefore(SCENARIO_MAIN, 5, 7);
    case QUEST_MAZE_15:
        return !ScriptVarScenarioBefore(SCENARIO_MAIN, 15, 0);
    case QUEST_LEGEND_ZAPDOS:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 7, -1);
    case QUEST_LEGEND_MOLTRES:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 12, -1);
    case QUEST_LEGEND_ARTICUNO:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 13, -1);
    case QUEST_LEGEND_GROUDON:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 15, -1);
    case QUEST_LEGEND_RAYQUAZA:
        return ScriptVarScenarioAfter(SCENARIO_MAIN, 16, -1);
    case QUEST_LEGEND_KYOGRE:
        return ScriptVarScenarioAfter(SCENARIO_SUB2, 33, -1);
    case QUEST_LEGEND_LUGIA:
        return ScriptVarScenarioAfter(SCENARIO_SUB2, 34, -1);
    case QUEST_LEGEND_DEOXYS:
        return ScriptVarScenarioAfter(SCENARIO_SUB3, 36, -1);
    case QUEST_LEGEND_HO_OH:
        return ScriptVarScenarioAfter(SCENARIO_SUB4, 42, -1);
    case QUEST_LEGEND_MEWTWO:
        return ScriptVarScenarioAfter(SCENARIO_SUB5, 44, -1);
    case QUEST_LEGEND_MEW:
        return ScriptVarScenarioAfter(SCENARIO_SUB7, 49, -1);
    case QUEST_LEGEND_CELEBI:
        return RescueScenarioConquered(RESCUE_DUNGEON_PURITY_FOREST);
    case QUEST_LUCARIO_RANK: // Never checked?
        return GetRescueTeamRank() == LUCARIO_RANK;
    case QUEST_COMPLETED_ALL_MAZES:
        return HasCompletedAllMazes();
    default:
        return FALSE;
  }
}

// arm9.bin::0200E620
u8 MapIdToFriendAreaId(s16 mapId_)
{
    s32 mapId = mapId_;
    const struct MapIdToFriendAreaIdStruct *ptr;

    for (ptr = sMapIdToFriendAreaIdTable; ptr->mapId != -1; ptr++) {
        if (ptr->mapId == (s16) mapId) {
            return ptr->friendAreaId;
        }
        ASM_MATCH_TRICK(ptr);
    }

    return FRIEND_AREA_NONE;
}

// arm9.bin::0200E5E8
s16 FriendAreaIdToMapId(u8 friendAreaId)
{
    const struct MapIdToFriendAreaIdStruct *ptr = sMapIdToFriendAreaIdTable;

    while (ptr->mapId != -1) {
        if (ptr->friendAreaId == friendAreaId) {
            return ptr->mapId;
        }
        ptr++;
    }

    return -1;
}

// arm9.bin::0200E5A8
bool8 sub_80026CC(s16 r0)
{
    return GetFriendAreaStatus(MapIdToFriendAreaId(r0));
}

// arm9.bin::0200E568
void ScriptUnlockFriendArea(s16 r0, bool8 r1)
{
    UnlockFriendArea(MapIdToFriendAreaId(r0));
}

// arm9.bin::0200E544
bool8 SaveGlobalScriptVars(void *dest)
{
    MemoryCopy8(dest, gScriptVarBuffer, SCRIPT_VAR_BUFFER_LEN);
    return TRUE;
}

// arm9.bin::0200E4DC
bool8 RestoreGlobalScriptVars(u8 *src)
{
    struct ScriptVarPtr temp;
    GetScriptVarRef(&temp, NULL, VERSION);
    MemoryCopy8(gScriptVarBuffer, src, SCRIPT_VAR_BUFFER_LEN);
    if (temp.info->defaultValue != *(u32 *)temp.ptr)
        return FALSE;
    return TRUE;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static void SetConditionBit(s32 r0)
{
    UpdateScriptVarWithImmediate(NULL, CONDITION, r0, CALC_SETBIT);
}

UNUSED static u8 sub_800276C(void)
{
    return 0;
}

UNUSED static void nullsub_140(void)
{

}
#endif
