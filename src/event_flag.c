#include "global.h"
#include "constants/friend_area.h"
#include "constants/item.h"
#include "items.h"
#include "event_flag.h"
#include "debug.h"
#include "memory.h"
#include "friend_area.h"
#include "rescue_team_info.h"
#include "other_random.h"
#include "friend_area.h"
#include "code_80972F4.h"
#include "code_8097670.h"
#include "pokemon.h"
#include "pokemon_3.h"

EWRAM_DATA u8 gScriptVarBuffer[0x400] = {0}; // NDS=020876DC

struct GroundEventTableEntry
{
    // size: 0x4
    s16 groundEnterId;
    u8 value; // Seems like friend area number
};

extern struct GroundEventTableEntry gGroundEnterLookupTable[58];

struct unkStruct_80B6D90
{
    u8 *text;
    s32 num;
};
extern struct unkStruct_80B6D90 gUnknown_80B6D90[];

extern u8 gUnknown_80B7144[];
extern u8 *gUnknown_80B714C[];
extern u8 *gUnknown_80B71A0[];
extern u8 gUnknown_80B72CC[];
extern DebugLocation gUnknown_80B7318;
extern u8 gUnknown_80B7324[];
extern DebugLocation gUnknown_80B7350;
extern u8 gUnknown_80B735C[];
extern u8 gUnknown_80B7378[];
extern u8 gUnknown_80B7388[];

extern bool8 GetScriptMode(void);
extern bool8 HasCompletedAllMazes(void);
extern u8 sub_8002658(s16);
extern void sub_809733C(u32, u32);
extern void sub_80973A8(u32, u32);
extern void sub_80972F4(void);
extern void nullsub_128(void);

// A fakematch? Debugging leftover? A bug? No clue.
#define GET_PTR_x400VAR(varId)(((void*) (&gScriptVarInfo[varId - 0x466])) - 4)

// arm9.bin::0200FF68
void ThoroughlyResetScriptVars(void)
{
  s32 iVar1;
  s32 iVar3;
  u16 uVar2;
  struct ScriptVarInfo *puVar1;

  for(iVar3 = 0; iVar3 < 0x400; iVar3++)
  {
    gScriptVarBuffer[iVar3] = 0;
  }

  for(iVar1 = 0; iVar1 < 0x51; iVar1 = (iVar1 + 1) * 0x10000 >> 0x10)
  {
    puVar1 = &gScriptVarInfo[iVar1];
    if (((puVar1->type != 0) && ((puVar1->type != 8)))) {
      for (uVar2 = 0; uVar2 < puVar1->arrayLen; uVar2++) {
        SetScriptVarArrayValue(NULL, iVar1, uVar2, puVar1->defaultValue);
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
  SetScriptVarValue(NULL,GROUND_ENTER,0xa2);
  SetScriptVarValue(NULL,GROUND_ENTER_LINK,0);
  SetScriptVarValue(NULL,GROUND_GETOUT,0xa2);
  SetScriptVarValue(NULL,GROUND_MAP,-1);
  SetScriptVarValue(NULL,GROUND_PLACE,0x24);
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
void sub_8001564(void)
{
    nullsub_128();
}
#endif

// arm9.bin::0200FEB4
void ResetScriptVarArray(u8 *localVarBuf, s16 varId_)
{
    struct ScriptVarInfo *infoPtr;
    u16 i;
    s32 varId = varId_;

    if (varId < 0x400) {
        infoPtr = &(gScriptVarInfo)[varId];
    }
    else {
        infoPtr = GET_PTR_x400VAR(varId);
    }

    for (i = 0; i < infoPtr->arrayLen; i++) {
        SetScriptVarArrayValue(localVarBuf,varId,i,infoPtr->defaultValue);
    }
}

// arm9.bin::0200FE04
void ClearScriptVarArray(u8 *localVarBuf, s16 varId_)
{
    struct ScriptVarInfo *infoPtr;
    u16 i;
    s32 varId = varId_;

    if (varId < 0x400) {
        infoPtr = &(gScriptVarInfo)[varId];
    }
    else {
        infoPtr = GET_PTR_x400VAR(varId);
    }

    for (i = 0; i < infoPtr->arrayLen; i++) {
        SetScriptVarArrayValue(localVarBuf,varId,i,0);
    }
}

// arm9.bin::0200FD60
void GetScriptVarRef(struct ScriptVarPtr *out, u8 *localVarBuf, s32 varId_)
{
    struct ScriptVarInfo *infoPtr;
    s32 varId = (s16) varId_;

    if (varId < 0x400) {
        infoPtr = &gScriptVarInfo[varId];
        out->info = infoPtr;
        out->ptr = &gScriptVarBuffer[infoPtr->bufOffset];
    }
    else {
        infoPtr = GET_PTR_x400VAR(varId);
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
        case 1: {
            s32 bitOffset = sp.info->bitOffset;
            u8 a = 1 << bitOffset;
            return (*sp.ptr & a) != FALSE; // Read bit-packed bool flag
        }
        case 2:
        case 7:
            return *((u8 *)sp.ptr);
        case 3:
            return *((s8 *)sp.ptr);
        case 4:
            return *((u16 *)sp.ptr);
        case 5:
            return *((s16 *)sp.ptr);
        case 6:
            return *((u32 *)sp.ptr);
        case 8:
            switch ((s16)varId) {
                case 23:
                    return GetScriptMode() != FALSE;
                case 32:
                    return GetFriendSum_808D480();
                case 33:
                    return GetUnitSum_808D544(0);
                case 34:
                    return gTeamInventoryRef->teamMoney;
                case 35:
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
        case 1: {
            s32 bitOffset = (u16) sp.info->bitOffset;
            u16 flagNum = idx + bitOffset;
            u8 *a = &sp.ptr[flagNum / 8];
            u8 b = 1 << (flagNum % 8);
            return (*a & b) != FALSE; // Read bit-packed bool flag
        }
        case 2:
        case 7:
            return ((u8 *)sp.ptr)[idx];
        case 3:
            return ((s8 *)sp.ptr)[idx];
        case 4:
            return ((u16 *)sp.ptr)[idx];
        case 5:
            return ((s16 *)sp.ptr)[idx];
        case 6:
            return ((u32 *)sp.ptr)[idx];
        case 8:
            switch ((s16)varId) {
                case 23:
                    return GetScriptMode() != FALSE;
                case 32:
                    return GetFriendSum_808D480();
                case 33:
                    return GetUnitSum_808D544(0);
                case 34:
                    return gTeamInventoryRef->teamMoney;
                case 35:
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
        case 1: {
            u8 bVar1 = 1 << sp.info->bitOffset;

            if (val != 0)
                *sp.ptr |= bVar1;
            else
                *sp.ptr = (bVar1 | *sp.ptr) ^ bVar1;
            break;
        }
        case 2: {
            *((s8 *)sp.ptr) = val;
            break;
        }
        case 3: {
            *((u8 *)sp.ptr) = val;
            break;
        }
        case 7: {
            *((bool8 *)sp.ptr) = val;
            break;
        }
        case 4: {
            *((s16 *)sp.ptr) = val;
            break;
        }
        case 5: {
            *((u16 *)sp.ptr) = val;
            break;
        }
        case 6: {
            *((s32 *)sp.ptr) = val;
            break;
        }
        case 8: {
            switch (varID) {
                case 0x22: {
                    gTeamInventoryRef->teamMoney = val;
                    break;
                }
                case 0x23: {
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
        case 1: {
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
        case 2: {
            ((s8 *)sp.ptr)[idx] = val;
            break;
        }
        case 3: {
            ((u8 *)sp.ptr)[idx] = val;
            break;
        }
        case 7: {
            ((bool8 *)sp.ptr)[idx] = val;
            break;
        }
        case 4: {
            ((s16 *)sp.ptr)[idx] = val;
            break;
        }
        case 5: {
            ((u16 *)sp.ptr)[idx] = val;
            break;
        }
        case 6: {
            ((s32 *)sp.ptr)[idx] = val;
            break;
        }
        case 8: {
            switch (varID) {
                case 0x22: {
                    gTeamInventoryRef->teamMoney = val;
                    break;
                }
                case 0x23: {
                    gTeamInventoryRef->teamSavings = val;
                    break;
                }
            }
        }
    }
}

#if (GAME_VERSION == VERSION_RED)
UNUSED u8 *GetScriptVarPointer(s16 varId)
{
    struct ScriptVarPtr local_1c;

    GetScriptVarRef(&local_1c,0,varId);
    return local_1c.ptr;
}

UNUSED s16 GetScriptVarArrayLength(s16 varId)
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
UNUSED void GetScriptVarString(s16 varId, u8 *buf, s32 maxLen)
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

UNUSED void ScriptVarStringPopFirstChar(s16 varId,u32 param_2,s32 maxLen)
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
void GetScriptVarScenario(s32 param_1,u32 *param_2,u32 *param_3)
{
  *param_2 = GetScriptVarArrayValue(NULL, (s16)param_1, 0);
  *param_3 = GetScriptVarArrayValue(NULL, (s16)param_1, 1);
}

// arm9.bin::0200F36C
void ScenarioCalc(s16 param_1,s32 param_2,s32 param_3)
{
  s32 param_1_s32;
  u32 local_18;
  u32 local_14;

  param_1_s32 = param_1;
  GetScriptVarScenario(param_1_s32,&local_18,&local_14);
  Log(6,gUnknown_80B72CC,param_1_s32,local_18,local_14,param_2,param_3); // SCENARIO CALC [%3d] %4d %4d -> %4d %4d
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
        if (ScriptVarScenarioBefore(SCENARIO_SUB1,31,0) == 0) {
            SetAdventureAchievement(AA_TEAM_BASE_DONE);
        }
        if (ScriptVarScenarioBefore(SCENARIO_SUB1,32,0) == 0) {
            SetAdventureAchievement(AA_SMEARGLE);
        }
        break;
      case 0xC:
        if(ScriptVarScenarioBefore(SCENARIO_SUB9,55,2) == 0) {
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
bool8 ScriptVarScenarioAfter(s16 varId,u32 pMain,s32 pSub)
{
  s32 sMain;
  s32 sSub;

  sMain = GetScriptVarArrayValue(NULL, varId, 0);
  sSub = GetScriptVarArrayValue(NULL, varId, 1);
  if (sMain == 0x3a) {
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
  u32 local_c;
  u32 auStack8;

  GetScriptVarScenario(3, &auStack8, &local_c);
  if (auStack8 - 1 < 0x1b) {
    if (ScriptVarScenarioBefore(SCENARIO_SUB1,0x1f,0) != 0) {
      if (ScriptVarScenarioAfter(SCENARIO_MAIN,0xf,7) != 0) {
        ScenarioCalc(SCENARIO_SUB1,0x1f,0);
        sub_8097418(0xe,1);
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
      sub_809733C(0xf,1);
    }
    if (auStack8 > 0x11) {
      sub_80973A8(0x25,1);
      if (((FindItemInInventory(ITEM_HM_DIVE) != -1) || (gTeamInventoryRef->teamStorage[ITEM_HM_DIVE] != 0)) ||
         (ScriptVarScenarioAfter(SCENARIO_SUB2,0x21,3) != 0)) {
        sub_80973A8(0x22,1);
      }
      if (GetFriendAreaStatus(FURNACE_DESERT) != 0) {
        sub_80973A8(0x1f,1);
      }
      if (GetFriendAreaStatus(BOULDER_CAVE)) {
        sub_80973A8(0x20,1);
      }
      if (GetFriendAreaStatus(DRAGON_CAVE)) {
        sub_80973A8(0x21,1);
      }
      if (GetFriendAreaStatus(SECRETIVE_FOREST)) {
        sub_80973A8(0x23,1);
      }
      if (GetFriendAreaStatus(SERENE_SEA)) {
        sub_80973A8(0x24,1);
        sub_80973A8(0x28,1);
      }
      if ((GetFriendAreaStatus(AGED_CHAMBER_AN)) && (GetFriendAreaStatus(AGED_CHAMBER_O_EXCLAIM))) {
        sub_80973A8(0x26,1);
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
        if ((ScriptVarScenarioEqual(SCENARIO_SUB2,0x22,0)) && HasRecruitedMon(MONSTER_ARTICUNO) && HasRecruitedMon(MONSTER_ZAPDOS) && HasRecruitedMon(MONSTER_MOLTRES)) {
          ScenarioCalc(SCENARIO_SUB2,0x22,1);
        }
        if (((ScriptVarScenarioEqual(SCENARIO_SUB8,0,0)) && (ScriptVarScenarioAfter(SCENARIO_SUB2,0x21,3) != 0)) &&
           (GetFriendAreaStatus(SKY_BLUE_PLAINS))) {
          ScenarioCalc(SCENARIO_SUB8,0x33,1);
        }
        if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
          sub_80973A8(0x27,1);
        }
        if (GetFriendAreaStatus(SKY_BLUE_PLAINS)) {
          sub_80973A8(0x29,1);
        }
      }
      if (!ScriptVarScenarioBefore(SCENARIO_SUB2,0x22,0)) {
        if (ScriptVarScenarioEqual(SCENARIO_SUB7,0,0)) {
          ScenarioCalc(SCENARIO_SUB7,0x31,1);
          sub_809733C(0x1b,1);
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
        FatalError(&gUnknown_80B7318,gUnknown_80B7324, operation); // event flag expansion error %d
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
        FatalError(&gUnknown_80B7350,gUnknown_80B735C, operation); // event flag rule error %d
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
UNUSED s32 sub_8002354(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].num;
  }
  else {
    return -1;
  }
}

UNUSED u8 *sub_8002374(u32 param_1)
{
  if (param_1 < 0x3b) {
    return gUnknown_80B6D90[param_1].text;
  }
  else {
    return gUnknown_80B7378; // error number
  }
}

UNUSED u8 *sub_8002394(u32 param_1)
{
  if (param_1 - 0x12 < 9) {
    return  gUnknown_80B714C[param_1 - 0x12];
  }
  else if (param_1 == 0xf) {
    return gUnknown_80B7388; // 1-1
  }
  else {
    return gUnknown_80B7144; // NONE
  }
}

UNUSED u8 *sub_80023C4(u32 param_1)
{
  if (param_1 < 4) {
   return gUnknown_80B71A0[param_1]; // CISTART, CECONTINUE, CNLAST, CWEND
  }
  else {
    return gUnknown_80B7144; // NONE
  }
}
#endif

// arm9.bin::0200E654
// 6 checks for post game being reached
bool8 sub_80023E4(u32 param_1)
{
  switch(param_1) {
    case 0:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,2,-1);
    case 1:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,3,3);
    case 2:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,4,3);
    case 3:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,5,0);
    case 4:
        return (ScriptVarScenarioAfter(SCENARIO_MAIN,0xb,0) && ScriptVarScenarioBefore(SCENARIO_MAIN,0xd,0));
    case 5:
        return (ScriptVarScenarioAfter(SCENARIO_MAIN,0xb,3) && ScriptVarScenarioBefore(SCENARIO_MAIN,0xf,0));
    case 6:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0x11,-1);
    case 7:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0x12,2);
    case 8:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0x12,3);
    case 9:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0x12,-1);
    case 10:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,5,4);
    case 0xb:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,5,4);
    case 0xc:
        return (!ScriptVarScenarioEqual(SCENARIO_MAIN,0xb,2) && !ScriptVarScenarioEqual(SCENARIO_MAIN,0xb,3));
    case 0xd:
        return ScriptVarScenarioEqual(SCENARIO_MAIN,0x10,2);
    case 0xe:
        return !ScriptVarScenarioBefore(SCENARIO_MAIN,5,7);
    case 0xf:
        return !ScriptVarScenarioBefore(SCENARIO_MAIN,0xf,0);
    case 0x10:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,7,-1);
    case 0x11:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0xc,-1);
    case 0x12:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0xd,-1);
    case 0x13:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0xf,-1);
    case 0x14:
        return ScriptVarScenarioAfter(SCENARIO_MAIN,0x10,-1);
    case 0x15:
        return ScriptVarScenarioAfter(SCENARIO_SUB2,0x21,-1);
    case 0x16:
        return ScriptVarScenarioAfter(SCENARIO_SUB2,0x22,-1);
    case 0x17:
        return ScriptVarScenarioAfter(SCENARIO_SUB3,0x24,-1);
    case 0x18:
        return ScriptVarScenarioAfter(SCENARIO_SUB4,0x2a,-1);
    case 0x19:
        return ScriptVarScenarioAfter(SCENARIO_SUB5,0x2c,-1);
    case 0x1a:
        return ScriptVarScenarioAfter(SCENARIO_SUB7,0x31,-1);
    case 0x1b:
        return RescueScenarioConquered(0x29);
    case 0x1c:
        return GetRescueTeamRank() == LUCARIO_RANK;
    case 0x1d:
        return HasCompletedAllMazes();
    default:
        return FALSE;
  }
}

// arm9.bin::0200E620
u8 sub_8002658(s16 param_1)
{
  short sVar1;
  s32 param_1_s32;
  struct GroundEventTableEntry *ptr;

  param_1_s32 = param_1;

  ptr = gGroundEnterLookupTable;
  sVar1 = gGroundEnterLookupTable[0].groundEnterId;
  if (sVar1 != -1) {
    do {
      if (sVar1 == param_1_s32) {
        return ptr->value;
      }
      ptr++;
      sVar1 = ptr->groundEnterId;
    } while (sVar1 != -1);
  }
  return 0;
}

// arm9.bin::0200E5E8
s16 sub_8002694(u8 param_1)
{
    struct GroundEventTableEntry *puVar2 = gGroundEnterLookupTable;

    while (puVar2->groundEnterId != -1) {
        if (puVar2->value == param_1) {
            return puVar2->groundEnterId;
        }
        puVar2++;
    }

    return -1;
}

// arm9.bin::0200E5A8
bool8 sub_80026CC(s16 r0)
{
    return GetFriendAreaStatus(sub_8002658(r0));
}

// arm9.bin::0200E568
void sub_80026E8(s16 r0, bool8 r1)
{
    UnlockFriendArea(sub_8002658(r0));
}

// arm9.bin::0200E544
bool8 SaveGlobalScriptVars(void *r0)
{
    MemoryCopy8(r0, gScriptVarBuffer, 0x400);
    return TRUE;
}

// arm9.bin::0200E4DC
bool8 RestoreGlobalScriptVars(u8 *r0)
{
    struct ScriptVarPtr temp;
    GetScriptVarRef(&temp, NULL, VERSION);
    MemoryCopy8(gScriptVarBuffer, r0, 0x400);
    if (temp.info->defaultValue != *(u32 *)temp.ptr)
        return FALSE;
    return TRUE;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED void SetConditionBit(s32 r0)
{
    UpdateScriptVarWithImmediate(NULL, CONDITION, r0, CALC_SETBIT);
}

UNUSED u8 sub_800276C(void)
{
    return 0;
}

UNUSED void nullsub_140(void)
{

}
#endif



// TODO: Merge with main_loops.c (below) and code_8002774.c (above)
