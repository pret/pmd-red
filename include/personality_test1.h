#ifndef GUARD_PERSONALITY_TEST1_H
#define GUARD_PERSONALITY_TEST1_H

#include "constants/personality_test.h"
#include "structs/menu.h"

typedef u8 PersonalityEffects[NUM_PERSONALITY_TEST_EFFECTS];

// size: 0xC
typedef struct PersonalityQuestion
{
    /* 0x0 */ const u8 *question;
    /* 0x4 */ const MenuItem *answers;
    /* 0x8 */ const PersonalityEffects *effects;
} PersonalityQuestion;

struct PersonalityRelated
{
    u32 unk4;
    s16 StarterID;
    s16 PartnerID;
    u8 StarterName[0x14];
    u8 PartnerNick[0x14];
};

struct PersonalityTestTracker
{
    /* 0x0 */ s32 FrameCounter;
    struct PersonalityRelated unk4;
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
u32 HandleTestTrackerState(void);

#endif // GUARD_PERSONALITY_TEST1_H
