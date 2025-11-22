#include "global.h"
#include "globaldata.h"
#include "rescue_scenario.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"

// size: 0x8
typedef struct MissionText
{
    /* 0x0 */ const u8 *text;
    u8 unk4;
    u8 unk5;
    u8 unk6;
    u8 unk7;
} MissionText;

static const MissionText sStoryMissionText[] = {
    { _("Rescue Caterpie."), -1, -1, 0, 0 },
    { _("Rescue Magnemite."), -1, -1, 0, 0 },
    { _("Rescue Diglett."), 0, 1, 0, 0 },
    { _("Rescue Metapod."), 2, 3, 0, 0 },
    { _("Rescue Jumpluff."), -1, -1, 0, 0 },
    { _("Rescue Shiftry."), 4, 5, 0, 0 },
    { _("Meet Xatu."), -1, -1, 0, 0 },
    { _("Fugitive"), -1, -1, 0, 0 },
    { _("Fugitive"), 6, 7, 0, 0 },
    { _("Fugitive"), 8, 9, 0, 0 },
    { _("Meet Ninetales."), -1, 10, 0, 0 },
    { _("Rescue Alakazam."), 11, 12, 0, 0 },
    { _("Seek Rayquaza's help."), 14, 15, 0, 0 },
    { _("{COLOR YELLOW_C}Scenario Progress Dummy{RESET}"), -1, -1, 0, 0 },
    { _("Punish bad Mankey."), 16, 17, 0, 0 },
    { _("Rescue Smeargle."), -1, 33, 0, 0 },
    { _("Explore seafloor."), -1, -1, 0, 0 },
    { _("Meet sea guardian."), -1, -1, 0, 0 },
    { _("Check mystery Pokémon."), -1, -1, 0, 0 },
    { _("Meet Xatu."), -1, -1, 0, 0 },
    { _("Mirage Pokémon 1"), 20, 21, 0, 0 },
    { _("Mirage Pokémon 2"), 22, 23, 0, 0 },
    { _("Mirage Pokémon 3"), 24, 25, 0, 0 },
    { _("Mirage Pokémon 4"), -1, 26, 0, 0 },
    { _("Meet toughest Pokémon."), 18, 19, 0, 0 },
    { _("Catch thief."), 27, 28, 0, 0 },
    { _("Rescue Latias."), -1, -1, 0, 0 },
    { _("Investigate Relic."), -1, -1, 0, 0 },
    { _("Rescue Medicham."), -1, 32, 0, 0 },
    { _("Meet Ninetales."), -1, -1, 0, 0 },
    { _("Break Gardevoir's curse."), -1, -1, 0, 0 },
    { NULL, -1, -1, 0, 0 },
};

ALIGNED(4) const u8 gDummyScenarioText[] = _("{COLOR YELLOW_C}Scenario try dummy{RESET}");
ALIGNED(4) const u8 gBlankMission[] = _("{COLOR RED_W}???{RESET}");

// arm9.bin::020688A8
void sub_80972F4(void)
{
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_ORDER_LIST);
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_JOB_LIST);
    ClearScriptVarArray(NULL, RESCUE_SCENARIO_CONQUEST_LIST);
}

void nullsub_128(void)
{}

bool8 sub_8097318(s16 param_1)
{
    s32 param_1_s32 = param_1;

    if (param_1_s32 == 0xd)
        return FALSE;

    return GetScriptVarArrayValue(NULL,RESCUE_SCENARIO_ORDER_LIST, (u16) param_1_s32) != 0;
}

void sub_809733C(s16 param_1, u32 param_2)
{
  s32 uVar2;
  u8 param_2_u8;
  u16 uVar2_u16;

  uVar2 = param_1;
  param_2_u8 = param_2;

  if (uVar2 != 0xd) {
    uVar2_u16 = uVar2;
    if (GetScriptVarArrayValue(NULL,RESCUE_SCENARIO_JOB_LIST, (u16) uVar2_u16) == 0) {
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

bool8 sub_8097384(s32 param_1)
{
    s32 param1 = (s16) param_1;

    if (param1 == RESCUE_DUNGEON_DUMMY) {
        return FALSE;
    }
    else {
        return (GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, (u16) param1) != FALSE);
    }
}

void sub_80973A8(s32 param_1, u32 param_2)
{
  s32 sVar1;
  s32 param_1_s32 = (s16)param_1;
  u8 param_2_u32 = param_2;

  if (param_1_s32 != 0xd) {
    if (param_2_u32 != 0) {
      sVar1 = RescueDungeonToScriptDungeonId(param_1);
      SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_ORDER_LIST,(u16)param_1_s32,0);
      if (sVar1 != -1) {
        SetScriptVarValue(NULL,DUNGEON_SELECT,sVar1);
      }
    }
    SetScriptVarArrayValue(NULL,RESCUE_SCENARIO_JOB_LIST,(u16)param_1_s32,param_2_u32);
  }
}

bool8 RescueScenarioConquered(s32 rescueDungeonID_)
{
    s32 rescueDungeonID = (s16) rescueDungeonID_;

    if (rescueDungeonID == RESCUE_DUNGEON_DUMMY)
        return FALSE;

    return (GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_CONQUEST_LIST, (u16)rescueDungeonID) != FALSE);
}

void sub_8097418(s32 index, bool32 param_2)
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

// These two are literally the same
UNUSED static const u8 *UnusedGetRescueDungeonName(s16 index)
{
    if (index == RESCUE_DUNGEON_DUMMY) {
        return gDummyScenarioText;
    }
    else {
        return GetDungeonName1(RescueDungeonToDungeonId(index));
    }
}

const u8 *GetRescueDungeonName(s16 rescueDungeonId)
{
    if (rescueDungeonId == RESCUE_DUNGEON_DUMMY) {
        return gDummyScenarioText;
    }
    else {
        return GetDungeonName1(RescueDungeonToDungeonId(rescueDungeonId));
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
