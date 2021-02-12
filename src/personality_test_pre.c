#include "global.h"
#include "personality_test.h"
#include "random.h"

extern void* MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void sub_801317C(u32 *);
extern void sub_8099690(u32);
extern void sub_8001024(u32 *);
extern s32 sub_8094E4C(void);
extern void sub_8011C40(s32);
extern void sub_8094D28(s32);
extern void sub_8001044(u32 *);

extern void UpdateNatureTotals(void);
extern void PromptNewQuestion(void);


extern const char gGenderText;
extern u32 gGenderMenu;

extern u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS];

extern void sub_8014248(const char *text, u32, u32, u32 *r0, u32, u32, u32, u32, u32);


u8 CreateTestTracker(void)
{
  gUnknown_203B400 = MemoryAlloc(sizeof(struct PersonalityStruct_203B400),8);
  sub_801317C(&gUnknown_203B400->unkb4);
  InitializeTestStats();
  sub_8099690(1);
  return 1;
}

void InitializeTestStats(void)
{
  s32 counter;

  sub_8001024(&gUnknown_203B400->unk4);
  gUnknown_203B400->FrameCounter = 0;
  gUnknown_203B400->TestState = 0;
  gUnknown_203B400->QuestionCounter = 0;
  for(counter = 0; counter < NUM_PERSONALITIES; counter++){
    gUnknown_203B400->NatureTotals[counter] = 0;
  }
  gUnknown_203B400->currQuestionIndex = 0;
  for(counter = 0; counter < NUM_QUIZ_QUESTIONS; counter++){
    gUnknown_203B400->QuestionTracker[counter] = 0;
  }
  gUnknown_203B400->playerNature = 0;
  gUnknown_203B400->playerGender = 0;
}

u8 HandleTestTrackerState(void)
{
  s32 counter;

  s32 iVar1;

  gUnknown_203B400->FrameCounter++;
  switch(gUnknown_203B400->TestState)
  {
    case 0:
        GenerateNewQuestionOrGender();
        break;
    case 1:
        CallPromptNewQuestion();
        break;
    case 2:
        UpdateNatureTotals();
        break;
    case 3:
        SetPlayerGender();
        break;
    case 4:
        RevealPersonality();
        break;
    case 5:
        RevealStarter();
        break;
    case 6:
        sub_803CA8C();
        break;
    case 7:
        PromptPickPartner();
        break;
    case 8:
        sub_803CAD4();
        break;
    case 9:
        sub_803CAF4();
        break;
    case 10:
        PromptForPartnerNickname();
        break;
    case 11:
        sub_803CB5C();
        break;
    case 12:
        sub_803CB7C();
        break;
    case 13:
        sub_803CBB0();
        break;
    case 14:
        sub_803CBE4();
        break;
    case 15:
        iVar1 = Random() * gUnknown_203B400->FrameCounter;
        sub_8094D28(Random());

        for(counter = 0; counter < NUM_PERSONALITIES; counter++){
            iVar1 *= (gUnknown_203B400->NatureTotals[counter] + counter + 3);
        }

        iVar1 += sub_8094E4C();
        while (iVar1 == -1) {
            iVar1 += sub_8094E4C();
        }
        sub_8011C40(iVar1);
        return 3;
    default:
        break;
  }
  return 0;
}

void DeleteTestTracker(void)
{
  sub_8001044(&gUnknown_203B400->unk4);
  MemoryFree(gUnknown_203B400);
  gUnknown_203B400 = NULL;
}

void GenerateNewQuestionOrGender(void)
{
  u8 category;
  int counter;
  int newQuestion;

  gUnknown_203B400->QuestionCounter++;
  if (gUnknown_203B400->QuestionCounter > MAX_ASKED_QUESTIONS) {
      // We've asked enough questions
        sub_8014248(&gGenderText, 0, 0, &gGenderMenu, 0, 3, 0, 0, 257);
        gUnknown_203B400->TestState = 3;
  }
  else
  {
    do {
        // Generate new question number and make sure we haven't done it
        newQuestion = RandomCapped(NUM_QUIZ_QUESTIONS);
        gUnknown_203B400->currQuestionIndex = newQuestion;
    } while (gUnknown_203B400->QuestionTracker[newQuestion] == 1);

    // Found one so let's get the category
    category = gNatureQuestionTable[gUnknown_203B400->currQuestionIndex];

    // Mark all of the questions in the category as used
    for(counter = 0; counter < NUM_QUIZ_QUESTIONS; counter++){
      if (gNatureQuestionTable[counter] == category)
        gUnknown_203B400->QuestionTracker[counter] = 1;
    }
    gUnknown_203B400->TestState = 1;
  }
}

void CallPromptNewQuestion(void)
{
    PromptNewQuestion();
    gUnknown_203B400->TestState = 2;
}
