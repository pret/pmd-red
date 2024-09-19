#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "dungeon.h"
#include "event_flag.h"
#include "code_80A26CC.h"

ALIGNED(4) const char gMeetNinetalesText[] =  "Meet Ninetales.";
ALIGNED(4) const char gAvoidCaptureText[] = "Avoid capture.";
ALIGNED(4) const char gFinalScenarioText[] = _("Defeat the final Pokémon.");


bool8 sub_8097504(s16 mazeIndex)
{
    s32 mazeIndex_s32;

#ifndef NONMATCHING
    register s32 mazeIndex_s32_1 asm("r1");
#else
    s32 mazeIndex_s32_1;
#endif
    s32 uVar3;

    mazeIndex_s32 = mazeIndex;
    mazeIndex_s32_1 = mazeIndex_s32;

    if(mazeIndex_s32 < 17)
    {
        switch(mazeIndex_s32) {
            case 2:
            case 10:
            case 11:
            case 12:
                uVar3 = 14;
                break;
            case 0:
            case 1:
            case 5:
            case 7:
            case 9:
            case 14:
                uVar3 = 15;
                break;
            case 3:
            case 4:
            case 6:
            case 8:
                return TRUE;
            case 13:
                uVar3 = 6;
                break;
            default:
                return TRUE;
        }
    }
    else
    {
        if (mazeIndex_s32_1 > 22)  return FALSE;
        if (mazeIndex_s32_1 == 22) return FALSE;
        if (mazeIndex_s32_1 == 21) return FALSE;
        uVar3 = 6;
    }

    if (!sub_80023E4(uVar3)) {
        return FALSE;
    }
    else {
        return TRUE;
    }
}

// TODO: this should probably be bool8 but can't get a match just yet
bool32 IsMazeCompleted(s16 mazeIndex)
{
    bool32 mazeCompletion;

    mazeCompletion = GetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, mazeIndex);
    if (mazeCompletion) {
        mazeCompletion = TRUE;
    }
    return mazeCompletion;
}

void sub_80975A8(s16 param_1,u8 param_2)
{
    u16 param_1_u16 = param_1;
    SetScriptVarArrayValue(NULL,TRAINING_CONQUEST_LIST,param_1_u16,param_2);
}

const u8 *sub_80975C4(s16 index)
{
    return GetDungeonName1(sub_80A2728(index));
}

const u8 *sub_80975DC(u32 r0)
{
    // TODO: slight hack but matches
    r0 <<= 16;
    if((0xffe90000 + r0) >> 16 < 2)
        if(ScriptVarScenarioEqual(SCENARIO_MAIN, 0xE, -1))
            return gMeetNinetalesText;
        else
            return gAvoidCaptureText;
    else
        return gFinalScenarioText;
}

bool8 HasCompletedAllMazes(void)
{
    s32 index;
    for(index = 0; index < NUM_BASIC_DUNGEON_MAZE; index++)
    {
        if(!(bool8)IsMazeCompleted(index))
            return FALSE;
    }
    return TRUE;
}

bool8 sub_8097640(void)
{
    if(GetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, 0x1F) == 0 && HasCompletedAllMazes())
    {
        SetScriptVarArrayValue(NULL, TRAINING_CONQUEST_LIST, 0x1F, 1);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

