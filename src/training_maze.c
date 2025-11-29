#include "global.h"
#include "globaldata.h"
#include "training_maze.h"
#include "constants/dungeon.h"
#include "dungeon_info.h"
#include "event_flag.h"
#include "code_80A26CC.h"
#include "rescue_scenario.h"

ALIGNED(4) static const char gMeetNinetalesText[] =  "Meet Ninetales.";
ALIGNED(4) static const char gAvoidCaptureText[] = "Avoid capture.";
ALIGNED(4) static const char gFinalScenarioText[] = _("Defeat the final Pokémon.");

void sub_80974E8(void)
{
    ClearScriptVarArray(NULL, TRAINING_CONQUEST_LIST);
    ClearScriptVarArray(NULL, TRAINING_PRESENT_LIST);
}

UNUSED static void nullsub_208(void)
{
}

bool8 sub_8097504(s16 mazeIndex)
{
    s32 questID;
    s32 mazeIndex_ = Self_s16(mazeIndex); // Needed to match
    if (mazeIndex < 17) {
        switch (mazeIndex) {
            case 2:
            case 10:
            case 11:
            case 12:
                questID = QUEST_MAZE_14;
                break;
            case 0:
            case 1:
            case 5:
            case 7:
            case 9:
            case 14:
                questID = QUEST_MAZE_15;
                break;
            case 3:
            case 4:
            case 6:
            case 8:
                return TRUE;
            case 13:
                questID = QUEST_REACHED_POSTGAME;
                break;
            default:
                return TRUE;
        }
    }
    else {
        if (mazeIndex_ > 22)  return FALSE;
        if (mazeIndex_ == 22) return FALSE;
        if (mazeIndex_ == 21) return FALSE;
        questID = QUEST_REACHED_POSTGAME;
    }

    if (!CheckQuest(questID))
        return FALSE;

    return TRUE;
}

bool8 IsMazeCompleted(s16 mazeIndex)
{
    return (GetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, (u16) mazeIndex) != 0);
}

void sub_80975A8(s16 param_1,u8 param_2)
{
    u16 param_1_u16 = param_1;
    SetScriptVarArrayValue(NULL,TRAINING_CONQUEST_LIST,param_1_u16,param_2);
}

UNUSED static const u8 *sub_80975C4(s16 index)
{
    return GetDungeonName1(sub_80A2728(index));
}

const u8 *sub_80975DC(s16 r0)
{
    if (r0 == 23 || r0 == 24) {
        if (ScriptVarScenarioEqual(SCENARIO_MAIN, 0xE, -1))
            return gMeetNinetalesText;
        else
            return gAvoidCaptureText;
    }
    else
        return gFinalScenarioText;
}

bool8 HasCompletedAllMazes(void)
{
    s32 index;
    for (index = 0; index < NUM_BASIC_DUNGEON_MAZE; index++) {
        if(!IsMazeCompleted(index))
            return FALSE;
    }
    return TRUE;
}

bool8 sub_8097640(void)
{
    if (GetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, 0x1F) == 0 && HasCompletedAllMazes()) {
        SetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, 0x1F, 1);
        return TRUE;
    }
    else {
        return FALSE;
    }
}
