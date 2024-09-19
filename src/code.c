#include "global.h"
#include "event_flag.h"

extern void xxx_dungeon_8042F6C(u32 r0);
extern void NDS_LoadOverlay_GroundMain();
extern u32 xxx_script_related_8098468(u32);

void NDS_LoadOverlay_GroundMain()
{

}

void nullsub_2(u32 r0)
{

}

u32 xxx_script_related_8001334(u32 r0)
{
    return xxx_script_related_8098468(r0);
}

void xxx_dungeon_8001340(u32 r0)
{
    nullsub_2(r0);
    xxx_dungeon_8042F6C(r0);
    NDS_LoadOverlay_GroundMain();
}

void nullsub_3(s32 a0, s32 a1)
{

}

/////////////////////////////////
/// TODO merge with event_flag
/////////////////////////////////

extern void sub_80972F4(void);
extern void nullsub_128(void);

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

void sub_8001564(void)
{
    nullsub_128();
}
