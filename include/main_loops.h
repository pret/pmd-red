#ifndef GUARD_MAIN_LOOPS_H
#define GUARD_MAIN_LOOPS_H

#include "personality_test1.h"
#ifdef PLATFORM_PC
#include "boot_pc.h"
#endif

enum MainLoopsUnk
{
    MAINLOOPS_UNK_0,
    MAINLOOPS_UNK_1,
    MAINLOOPS_UNK_2,
};

void GameLoop_Async(void);
void nullsub_3(s32 yPos, s32 a1);
// Return: See enum "MainLoopsUnk"
#ifdef PLATFORM_PC
// Host hooks implemented at the bottom of src/main_loops.c.
void Pc_GameBootStage(void);
void Pc_FrameActions(void);
void Pc_TitleSmoke(int menuFrames);
// Play the real boot sequence (health & safety warning, logos, intro/title
// opening) before the title screen. Each stage renders paced via the ground
// engine and is skippable via the PcBootConfig flags and A/Start.
void Pc_RunBootSequence(const PcBootConfig *cfg);
// One interactive title/menu frame. Returns a real selection (2, 4 or
// MENU_NEW_GAME) when the player confirms a menu item, else MENU_NO_SCREEN_CHANGE.
s32 Pc_MenuStep(void);
// Full PC game driver: title -> interactive main menu -> (on selection) the
// real post-menu flow (title fade-out + RunGameMode_Async dispatch) -> title,
// repeating until quit or --frames is exhausted. Renders/paces/inputs itself.
// With autoload set, a valid save skips the menu once at launch and continues.
void Pc_RunTitleAndGame(int maxFrames, int autoload);
#endif
s32 GetMainLoopsUnk(void);
void ReadTeamBasicInfo(TeamBasicInfo *dst);
void WriteTeamBasicInfo(TeamBasicInfo *src);
void sub_8001064(void);

#endif // GUARD_MAIN_LOOPS_H