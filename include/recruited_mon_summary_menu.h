#ifndef GUARD_RECRUITED_MON_SUMMARY_MENU_H
#define GUARD_RECRUITED_MON_SUMMARY_MENU_H

enum RecruitedMonSummaryMenuInputRet
{
    RecruitedMonSummaryMenu_INPUTRET_NONE,
    RecruitedMonSummaryMenu_INPUTRET_LEFTRIGHT,
    RecruitedMonSummaryMenu_INPUTRET_BACK,
    RecruitedMonSummaryMenu_INPUTRET_ACCEPT,
};

bool8 RecruitedMonSummaryMenu_Create(s32 speciesNum, s32 windowID);
// Return: See enum "RecruitedMonSummaryMenuInputRet"
u32 RecruitedMonSummaryMenu_Input(void);
void RecruitedMonSummaryMenu_SetupAndShowWindows(void);
void RecruitedMonSummaryMenu_Destroy(void);

#endif // GUARD_RECRUITED_MON_SUMMARY_MENU_H
