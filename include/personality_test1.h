#ifndef GUARD_PERSONALITY_TEST1_H
#define GUARD_PERSONALITY_TEST1_H

#include "constants/personality_test.h"
#include "structs/menu.h"

// size: 0xC
typedef struct PersonalityQuestion
{
    /* 0x0 */ const u8 *question;
    /* 0x4 */ const MenuItem *answers;
    /* 0x8 */ const u8 (*effects)[16];
} PersonalityQuestion;

struct PersonalityTestTracker
{
    /* 0x0 */ s32 FrameCounter;
    u32 unk4;
    /* 0x8 */ s16 StarterID;
    /* 0xA */ s16 PartnerID;
    u8 fillC[0x20 - 0xC];
    /* 0x20 */ u8 PartnerNick[20];
    /* 0x34 */ u32 TestState;
    /* 0x38 */ s32 QuestionCounter;
    /* 0x3C */ u32 currQuestionIndex;
    /* 0x40 */ u8 playerNature;
    /* 0x44 */ s32 NatureTotals[NUM_PERSONALITIES];
    /* 0x78 */ u8 QuestionTracker[NUM_QUIZ_QUESTIONS];
    /* 0xB0 */ u32 playerGender; // 1 = Female, 0 = Male
    /* 0xB4 */ MenuInputStructSub input;
};

bool8 CreateTestTracker(void);
void DeleteTestTracker(void);
u8 HandleTestTrackerState(void);

#endif // GUARD_PERSONALITY_TEST1_H
