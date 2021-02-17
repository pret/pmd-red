#ifndef GUARD_PERSONALITY_TEST_H
#define GUARD_PERSONALITY_TEST_H

#include "constants/personality_test.h"

struct PersonalityStruct_203B400
{
    s32 FrameCounter;
    u32 unk4;
    /* 0x8 */ s16 StarterID;
    s16 unkA;
    u8 padding[0x20 - 0xC];
    s32 unk20;
    u8 padding2[0x34 - 0x24];
    /* 0x34 */ u32 TestState;
    /* 0x38 */ s32 QuestionCounter;
    /* 0x3C */ u32 currQuestionIndex;
    /* 0x40 */ u8 playerNature;
    u8 padding3[3];
    /* 0x44 */ s32 NatureTotals[13];
    /* 0x78 */ u8 QuestionTracker[NUM_QUIZ_QUESTIONS];
    /* 0xB0 */ u32 playerGender; // 1 = Female, 0 = Male
    u32 unkb4;
    u32 unkb8;
    u32 unkbc;
};
extern struct PersonalityStruct_203B400 *gUnknown_203B400;

void InitializeTestStats(void);
void GenerateNewQuestionOrGender(void);
void CallPromptNewQuestion(void);
void PrintPersonalityTypeDescription(void);
void SetPlayerGender(void);
void RevealPersonality(void);
void RevealStarter(void);
void sub_803CA8C(void);
void PromptPickPartner(void);
void sub_803CAD4(void);
void sub_803CAF4(void);
void PromptForPartnerNickname(void);
void sub_803CB5C(void);
void sub_803CB7C(void);
void PrintEndIntroText(void);
void sub_803CBE4(void);
s32 GetValidPartners(void);
void UpdateNatureTotals(void);
void PromptNewQuestion(void);



#endif
