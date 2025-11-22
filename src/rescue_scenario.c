#include "global.h"
#include "globaldata.h"
#include "rescue_scenario.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "exclusive_pokemon.h"
#include "code_80958E8.h"
#include "code_80A26CC.h"

// Size: R=0x8 | B=0x6
typedef struct MissionText
{
    /* 0x0 */ const u8 *text;
    /* 0x4 */ u8 cutsceneFlag1; // See enum "CutsceneFlagID"
    /* 0x5 */ u8 cutsceneFlag2; // See enum "CutsceneFlagID"
} MissionText;

static const MissionText sStoryMissionText[NUM_STORY_MISSIONS + 1] = {
    [RESCUE_DUNGEON_TINY_WOODS] = { _("Rescue Caterpie."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_THUNDERWAVE_CAVE] = { _("Rescue Magnemite."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_MT_STEEL] = { _("Rescue Diglett."), CUTSCENE_FLAG_MT_STEEL_REACHED, CUTSCENE_FLAG_MT_STEEL_COMPLETE },
    [RESCUE_DUNGEON_SINISTER_WOODS] = { _("Rescue Metapod."), CUTSCENE_FLAG_SINISTER_WOODS_REACHED, CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE },
    [RESCUE_DUNGEON_SILENT_CHASM] = { _("Rescue Jumpluff."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_MT_THUNDER] = { _("Rescue Shiftry."), CUTSCENE_FLAG_MT_THUNDER_PEAK_REACHED, CUTSCENE_FLAG_MT_THUNDER_PEAK_COMPLETE },
    [RESCUE_DUNGEON_GREAT_CANYON] = { _("Meet Xatu."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_LAPIS_CAVE] = { _("Fugitive"), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_MT_BLAZE] = { _("Fugitive"), CUTSCENE_FLAG_MT_BLAZE_PEAK_REACHED, CUTSCENE_FLAG_MT_BLAZE_PEAK_COMPLETE },
    [RESCUE_DUNGEON_FROSTY_FOREST] = { _("Fugitive"), CUTSCENE_FLAG_FROSTY_GROTTO_REACHED, CUTSCENE_FLAG_FROSTY_GROTTO_COMPLETE },
    [RESCUE_DUNGEON_MT_FREEZE] = { _("Meet Ninetales."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_MT_FREEZE_PEAK_COMPLETE },
    [RESCUE_DUNGEON_MAGMA_CAVERN] = { _("Rescue Alakazam."), CUTSCENE_FLAG_MAGMA_CAVERN_PIT_REACHED, CUTSCENE_FLAG_MAGMA_CAVERN_PIT_COMPLETE },
    [RESCUE_DUNGEON_SKY_TOWER] = { _("Seek Rayquaza's help."), CUTSCENE_FLAG_SKY_TOWER_SUMMIT_REACHED, CUTSCENE_FLAG_SKY_TOWER_SUMMIT_COMPLETE },
    [RESCUE_DUNGEON_DUMMY] = { _("{COLOR YELLOW_C}Scenario Progress Dummy{RESET}"), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_UPROAR_FOREST] = { _("Punish bad Mankey."), CUTSCENE_FLAG_UPROAR_FOREST_REACHED, CUTSCENE_FLAG_UPROAR_FOREST_COMPLETE },
    [RESCUE_DUNGEON_HOWLING_FOREST] = { _("Rescue Smeargle."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_HOWLING_FOREST_COMPLETE },
    [RESCUE_DUNGEON_STORMY_SEA] = { _("Explore seafloor."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_SILVER_TRENCH] = { _("Meet sea guardian."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_METEOR_CAVE] = { _("Check mystery Pokémon."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_GREAT_CANYON_2] = { _("Meet Xatu."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_FIERY_FIELD] = { _("Mirage Pokémon 1"), CUTSCENE_FLAG_FIERY_FIELD_REACHED, CUTSCENE_FLAG_FIERY_FIELD_COMPLETE },
    [RESCUE_DUNGEON_LIGHTNING_FIELD] = { _("Mirage Pokémon 2"), CUTSCENE_FLAG_LIGHTNING_FIELD_REACHED, CUTSCENE_FLAG_LIGHTNING_FIELD_COMPLETE },
    [RESCUE_DUNGEON_NORTHWIND_FIELD] = { _("Mirage Pokémon 3"), CUTSCENE_FLAG_NORTHWIND_FIELD_REACHED, CUTSCENE_FLAG_NORTHWIND_FIELD_COMPLETE },
    [RESCUE_DUNGEON_MT_FARAWAY] = { _("Mirage Pokémon 4"), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_MT_FARAWAY_COMPLETE },
    [RESCUE_DUNGEON_WESTERN_CAVE] = { _("Meet toughest Pokémon."), CUTSCENE_FLAG_WESTERN_CAVE_REACHED, CUTSCENE_FLAG_WESTERN_CAVE_COMPLETE },
    [RESCUE_DUNGEON_NORTHERN_RANGE] = { _("Catch thief."), CUTSCENE_FLAG_NORTHERN_RANGE_REACHED, CUTSCENE_FLAG_NORTHERN_RANGE_COMPLETE },
    [RESCUE_DUNGEON_PITFALL_VALLEY] = { _("Rescue Latias."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_BURIED_RELIC] = { _("Investigate Relic."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_WISH_CAVE] = { _("Rescue Medicham."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_MEDICHAM_COMPLETE },
    [RESCUE_DUNGEON_MT_FREEZE_2] = { _("Meet Ninetales."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [RESCUE_DUNGEON_MURKY_CAVE] = { _("Break Gardevoir's curse."), CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
    [NUM_STORY_MISSIONS] = { NULL, CUTSCENE_FLAG_INVALID, CUTSCENE_FLAG_INVALID },
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

    if (param_1_s32 == 13)
        return FALSE;

    return GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_ORDER_LIST, (u16)param_1_s32) != 0;
}

void sub_809733C(s32 _rescueDungId, bool32 param_2)
{
    s32 param_1_s32 = (s16)_rescueDungId;
    bool8 param_2_u8 = (bool8)param_2;

    if (param_1_s32 != RESCUE_DUNGEON_DUMMY) {

        if (GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, (u16)param_1_s32) == 0) {
            SetScriptVarArrayValue(NULL, RESCUE_SCENARIO_ORDER_LIST, (u16)param_1_s32, param_2_u8);

            if (param_2_u8) {
                switch (param_1_s32) {
                    case RESCUE_DUNGEON_UPROAR_FOREST:
                    case RESCUE_DUNGEON_HOWLING_FOREST:
                    case RESCUE_DUNGEON_WISH_CAVE:
                        GeneratePelipperJobs();
                        break;
                }
            }
        }
    }
}

bool8 sub_8097384(s32 param_1)
{
    s32 param1 = (s16)param_1;

    if (param1 == RESCUE_DUNGEON_DUMMY)
        return FALSE;

    return GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, (u16)param1) != FALSE;
}

void sub_80973A8(s32 _rescueDungId, bool32 param_2)
{
    s32 rescueDungId = (s16)_rescueDungId;
    bool8 param_2_u8 = (bool8)param_2;

    if (rescueDungId != RESCUE_DUNGEON_DUMMY) {
        if (param_2_u8) {
            s32 scriptDungeon = RescueDungeonToScriptDungeonId(_rescueDungId);
            SetScriptVarArrayValue(NULL, RESCUE_SCENARIO_ORDER_LIST, (u16)rescueDungId, 0);
            if (scriptDungeon != SCRIPT_DUNGEON_INVALID)
                SetScriptVarValue(NULL, DUNGEON_SELECT, scriptDungeon);
        }

        SetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, (u16)rescueDungId, param_2_u8);
    }
}

bool8 RescueScenarioConquered(s32 rescueDungeonID_)
{
    s32 rescueDungeonID = (s16) rescueDungeonID_;

    if (rescueDungeonID == RESCUE_DUNGEON_DUMMY)
        return FALSE;

    return (GetScriptVarArrayValue(NULL, RESCUE_SCENARIO_CONQUEST_LIST, (u16)rescueDungeonID) != FALSE);
}

void SetRescueScenarioConquered(s32 rescueDungeonID_, bool32 conquered)
{
    s32 rescueDungeonID_s32 = (s16)rescueDungeonID_;
    bool8 param_2_u8 = (bool8)conquered;

    if (rescueDungeonID_s32 != RESCUE_DUNGEON_DUMMY) {
        if (param_2_u8) {
            SetScriptVarArrayValue(NULL, RESCUE_SCENARIO_JOB_LIST, (u16)rescueDungeonID_s32, 0);

            if (rescueDungeonID_s32 < NUM_STORY_MISSIONS) {
                const MissionText *mt = &sStoryMissionText[rescueDungeonID_s32];

                if (mt->cutsceneFlag1 != CUTSCENE_FLAG_INVALID)
                    SetTempCutsceneFlag(mt->cutsceneFlag1);

                if (mt->cutsceneFlag2 != CUTSCENE_FLAG_INVALID)
                    SetTempCutsceneFlag(mt->cutsceneFlag2);

                if (rescueDungeonID_s32 == RESCUE_DUNGEON_FROSTY_FOREST)
                    SetTempCutsceneFlag(CUTSCENE_FLAG_FROSTY_FOREST_INTRUDED);

                FlushTempCutsceneFlags();
            }
        }

        SetScriptVarArrayValue(NULL, RESCUE_SCENARIO_CONQUEST_LIST, (u16)rescueDungeonID_s32, param_2_u8);
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

const u8 *GetCurrentMissionText(s16 rescueDungeonId)
{
    if (rescueDungeonId < NUM_STORY_MISSIONS) {
        const MissionText *mt = &sStoryMissionText[rescueDungeonId];
        return mt->text;
    }

    return gBlankMission;
}
