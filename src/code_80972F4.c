#include "global.h"
#include "globaldata.h"
#include "dungeon.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "code_80A26CC.h"
#include "code_80972F4.h"

#include "data/story_missions.h"

ALIGNED(4) const u8 gDummyScenarioText[] = _("{COLOR YELLOW_C}Scenario try dummy{RESET}");
ALIGNED(4) const u8 gBlankMission[] = _("{COLOR RED_W}???{RESET}");

extern void GeneratePelipperJobs(void);

void sub_80972F4(void)
{
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_ORDER_LIST);
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_JOB_LIST);
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_CONQUEST_LIST);
}

void nullsub_128(void)
{}

s32 sub_8097318(s16 param_1)
{
  s32 iVar1;
  s32 param_1_s32;

  param_1_s32 = param_1;
  
  if (param_1_s32 == 0xd) {
    iVar1 = 0;
  }
  else {
    iVar1 = GetScriptVarArrayValue(NULL,RESCUE_SCENARIO_ORDER_LIST,param_1_s32);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  return iVar1;
}

void sub_809733C(s16 param_1,u32 param_2)
{
  s32 uVar2;
  u8 param_2_u8;
  u16 uVar2_u16;

  uVar2 = param_1;
  param_2_u8 = param_2;

  if (uVar2 != 0xd) {
    uVar2_u16 = uVar2;
    if (GetScriptVarArrayValue(NULL,RESCUE_SCENARIO_JOB_LIST,uVar2_u16) == 0) {
      SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_ORDER_LIST,uVar2_u16,param_2_u8);
      if (param_2_u8) {
        switch(uVar2)
        {
        case 0xE:
        case 0xF:
        case 0x1C:
            GeneratePelipperJobs();
            break;
        }
      }
    }
  }
}

bool32 sub_8097384(s16 param_1)
{
    bool32 val;

    if (param_1 == 13)
        val = FALSE;
    else {
        // May not need the & 0xFFFF if the 3rd param is s16
        val = GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, param_1 & 0xFFFF);
        if (val != 0)
            val = TRUE;
    }

    return val;
}

void sub_80973A8(s32 param_1,u32 param_2)
{
  s32 sVar1;
  s32 param_1_s32 = (s16)param_1;
  u8 param_2_u32 = param_2;
  
  if (param_1_s32 != 0xd) {
    if (param_2_u32 != 0) {
      sVar1 = sub_80A26B8(param_1);
      SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_ORDER_LIST,(u16)param_1_s32,0);
      if (sVar1 != -1) {
        SetScriptVarValue(NULL,DUNGEON_SELECT,sVar1);
      }
    }
    SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_JOB_LIST,(u16)param_1_s32,param_2_u32);
  }
}

bool32 RescueScenarioConquered(s16 param_1)
{
    bool32 val;

    if (param_1 == 13)
        val = FALSE;
    else {
        // May not need the & 0xFFFF if the 3rd param is s16
        // But it doesn't work
        val = GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_CONQUEST_LIST, param_1 & 0xFFFF);
        if (val != 0)
            val = TRUE;
    }

    return val;
}

void sub_8097418(s32 index,bool32 param_2)
{
  int index_s32 = (s16)index;
  bool8 param_2_u8 = param_2;
  if (index_s32 != 0xd) {
    if ((param_2_u8) && (SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_JOB_LIST,(u16)index_s32,0), index_s32 < 0x1f)) {
      const MissionText *mt = &sStoryMissionText[index_s32];
      if (mt->unk4 != 0xFF) {
        sub_8097FA8(mt->unk4);
      }
      if (mt->unk5 != 0xFF) {
        sub_8097FA8(mt->unk5);
      }
      if (index_s32 == 9) {
        sub_8097FA8(0x1f);
      }
      sub_8097FF8();
    }
    SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_CONQUEST_LIST,(u16)index_s32,param_2_u8);
  }
}

const u8 *sub_809747C(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *sub_80974A0(s16 index)
{
    if(index == 0xD)
    {
        return gDummyScenarioText;
    }
    else
    {
        return GetDungeonName1(sub_80A270C(index));
    }
}

const u8 *GetCurrentMissionText(s16 index)
{
    if(index < 0x1F)
    {
        const MissionText *mt = &sStoryMissionText[index];
        return mt->text;
    }
    else
    {
        return gBlankMission;
    }
}

void sub_80974E8(void)
{
    ClearScriptVarArray(NULL, TRAINING_CONQUEST_LIST);
    ClearScriptVarArray(NULL, TRAINING_PRESENT_LIST);
}

void nullsub_208(void)
{
}
