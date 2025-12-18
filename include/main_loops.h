#ifndef GUARD_MAIN_LOOPS_H
#define GUARD_MAIN_LOOPS_H

#include "personality_test1.h"

enum MainLoopsUnk
{
    MAINLOOPS_UNK_0,
    MAINLOOPS_UNK_1,
    MAINLOOPS_UNK_2,
};

void GameLoop_Async(void);
void nullsub_3(s32 yPos, s32 a1);
// Return: See enum "MainLoopsUnk"
s32 GetMainLoopsUnk(void);
void ReadTeamBasicInfo(TeamBasicInfo *dst);
void WriteTeamBasicInfo(TeamBasicInfo *src);
void sub_8001064(void);

#endif // GUARD_MAIN_LOOPS_H