#ifndef GUARD_PERSONALITY_TEST_H
#define GUARD_PERSONALITY_TEST_H

#include "constants/personality_test.h"
#include "input.h"
#include "text.h"

// Definitely wrong but need to figure out better structure later
struct FaceData
{
    /* 0x0 */ u8 *unk0[5];
};

struct PersonalityAnswer
{
  const char * text;
  int effect;
};

struct PersonalityQuestion
{
  const char * question;
  const struct PersonalityAnswer * answers;
  const u8 (*effects);
};

struct PersonalityTestTracker
{
    /* 0x0 */ s32 FrameCounter;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ s16 StarterID;
    /* 0xA */ s16 PartnerID;
    u8 padding[0x20 - 0xC];
    /* 0x20 */ char PartnerNick[0x14];
    /* 0x34 */ u32 TestState;
    /* 0x38 */ s32 QuestionCounter;
    /* 0x3C */ u32 currQuestionIndex;
    /* 0x40 */ u8 playerNature;
    /* 0x44 */ s32 NatureTotals[NUM_PERSONALITIES];
    /* 0x78 */ u8 QuestionTracker[NUM_QUIZ_QUESTIONS];
    /* 0xB0 */ u32 playerGender; // 1 = Female, 0 = Male
    /* 0xB4 */ MenuInputStructSub input;
};

struct PersonalityStruct_203B404
{
    // Size: 0xB8
    /* 0x0 */ s16 StarterID;
    /* 0x2 */ s16 PartnerArray[NUM_PARTNERS];
    u8 unk16;
    /* 0x18 */ MenuInputStruct input;
    u32 unk4C;
    /* 0x50 */ UnkTextStruct2 *unk50;
    /* 0x54 */ UnkTextStruct2 unk54[4];
    /* 0xB4 */ u8 unkb4[4];
};

void InitializeTestStats(void);
void GenerateNewQuestionOrGender(void);
void CallPromptNewQuestion(void);
void PrintPersonalityTypeDescription(void);
void SetPlayerGender(void);
void RevealPersonality(void);
void RevealStarter(void);
void AdvanceToPickPartnerPrompt(void);
void PromptPickPartner(void);
void AdvanceToPartnerSelection(void);
void CallCreatePartnerSelectionMenu(void);
void PromptForPartnerNickname(void);
void AdvanceToPartnerNickhameScreen(void);
void NicknamePartner(void);
void PrintEndIntroText(void);
void AdvanceToTestEnd(void);
s32 GetValidPartners(void);
void UpdateNatureTotals(void);
void PromptNewQuestion(void);
void PersonalityTest_DisplayPartnerSprite(void);
u16 HandlePartnerSelectionInput(void);
void PersonalityTest_DisplayStarterSprite(void);
void CreatePartnerSelectionMenu(s16);
void sub_803CE6C(void);
void sub_803CEAC(void);
void sub_803CECC(void);
void nullsub_135(void);


#endif
