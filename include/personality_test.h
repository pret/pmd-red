#ifndef GUARD_PERSONALITY_TEST_H
#define GUARD_PERSONALITY_TEST_H

#include "constants/personality_test.h"

struct unkData
{
    u8 unk0[24];
};

extern const struct unkData gUnknown_80F4244;

struct PersonalityStruct_203B400
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
    u32 unkb4;
    u32 unkb8;
    u32 unkbc;
};
extern struct PersonalityStruct_203B400 *gUnknown_203B400;

struct PersonalitySubStruct
{
    u8 unkb4;
    u8 unkb5;
    u8 unkb6;
    u8 unkb7;
};

struct PersonalityStruct_203B404
{
    // Size: 0xB8
    /* 0x0 */ s16 StarterID;
    /* 0x2 */ s16 PartnerArray[NUM_PARTNERS];
    u8 unk16;
    u8 unk17;
    /* 0x18 */ struct UnkInputStruct *unk18; // something menu related (seems to be some struct)
    u8 padding[0x30 - 0x1C];
    /* 0x30 */ s16 currPartnerSelection;
    s16 unk32;
    u8 padding2[0x3A - 0x34];
    /* 0x3A */ s16 numPartners;
    u8 padding3[0x4C - 0x3C];
    u32 unk4C;
    /* 0x50 */ struct unkData *unk50;
    /* 0x54 */ struct unkData unk54[4];
    /* 0xB4 */ struct PersonalitySubStruct sub;
};
extern struct PersonalityStruct_203B404 *gUnknown_203B404;

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
void CallCreatePartnerSelectionMenu(void);
void PromptForPartnerNickname(void);
void sub_803CB5C(void);
void sub_803CB7C(void);
void PrintEndIntroText(void);
void sub_803CBE4(void);
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
