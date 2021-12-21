#include "global.h"
#include "personality_test.h"
#include "constants/emotions.h"
#include "random.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "save.h"
#include "memory.h"
#include "gUnknown_203B46C.h"
#include "text.h"
#include "menu.h"

EWRAM_DATA struct PersonalityStruct_203B400 *gUnknown_203B400;
EWRAM_DATA struct PersonalityStruct_203B404 *gUnknown_203B404;


extern void sub_801317C(u32 *);
extern void sub_8001024(u32 *);
extern s32 sub_8094E4C(void);
extern void sub_8094D28(s32);
extern void sub_8001044(u32 *);

extern void sub_80141B4(const char *text, u32 r1, u32 r2, u16 r3);
extern void sub_8014248(const char *text, u32, u32, const struct MenuItem *r0, u32, u32, u32, u32, u32);

extern u32 sub_80144A4(s32 *);

extern void CopyStringtoBuffer(char *r0, char *r1);
extern void sub_801602C(u32, char *r0);

extern u32 sub_8016080(void);
extern void sub_80160D8(void);
extern void sub_8099690(u32);

extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern void sub_8008C54(u32);
extern void sub_800836C(u32, u8 *r0, u32);
extern void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);

extern void RedrawPartnerSelectionMenu(void);
extern void sub_8013818(struct UnkInputStruct **r0, s32, u32, u32);

extern u32 GetKeyPress(struct UnkInputStruct **r0);
extern u8 sub_80138B8(struct UnkInputStruct **r0, u32);
extern void PlayMenuSoundEffect(u32);


extern void sub_8013984(struct UnkInputStruct **r0);
u32 sub_8013800(struct UnkInputStruct **r0, u32);
extern void AddMenuCursorSprite(struct UnkInputStruct **r0);
extern void xxx_call_draw_string(u32 x, u32 y, const char *text, u32, u32);
extern u32 sub_80095E4(s16, u32);

extern struct UnkSaveStruct1 *gUnknown_203B46C;

extern const char gStarterReveal[];

extern u8 gAvailablePokemonNames[0x50];

extern const char gHardyDescription[];
extern const char gDocileDescription[];
extern const char gBraveDescription[];
extern const char gJollyDescription[];
extern const char gImpishDescription[];
extern const char gNaiveDescription[];
extern const char gTimidDescription[];
extern const char gHastyDescription[];
extern const char gSassyDescription[];
extern const char gCalmDescription[];
extern const char gRelaxedDescription[];
extern const char gLonelyDescription[];
extern const char gQuirkyDescription[];
extern const u8 GirlText[];
extern const u8 BoyText[];

extern const struct PersonalityQuestion HardyQuest1;
extern const struct PersonalityQuestion HardyQuest2;
extern const struct PersonalityQuestion HardyQuest3;
extern const struct PersonalityQuestion HardyQuest4;
extern const struct PersonalityQuestion DocileQuest1;
extern const struct PersonalityQuestion DocileQuest2;
extern const struct PersonalityQuestion DocileQuest3;
extern const struct PersonalityQuestion DocileQuest4;
extern const struct PersonalityQuestion BraveQuest1;
extern const struct PersonalityQuestion BraveQuest2A;
extern const struct PersonalityQuestion BraveQuest3;
extern const struct PersonalityQuestion BraveQuest4;
extern const struct PersonalityQuestion JollyQuest1;
extern const struct PersonalityQuestion JollyQuest2;
extern const struct PersonalityQuestion JollyQuest3;
extern const struct PersonalityQuestion JollyQuest4;
extern const struct PersonalityQuestion ImpishQuest1;
extern const struct PersonalityQuestion ImpishQuest2;
extern const struct PersonalityQuestion ImpishQuest3;
extern const struct PersonalityQuestion ImpishQuest4;
extern const struct PersonalityQuestion NaiveQuest1;
extern const struct PersonalityQuestion NaiveQuest2;
extern const struct PersonalityQuestion NaiveQuest3;
extern const struct PersonalityQuestion NaiveQuest4;
extern const struct PersonalityQuestion TimidQuest1;
extern const struct PersonalityQuestion TimidQuest2;
extern const struct PersonalityQuestion TimidQuest3;
extern const struct PersonalityQuestion TimidQuest4;
extern const struct PersonalityQuestion HastyQuest1;
extern const struct PersonalityQuestion HastyQuest2;
extern const struct PersonalityQuestion HastyQuest3;
extern const struct PersonalityQuestion HastyQuest4;
extern const struct PersonalityQuestion SassyQuest1;
extern const struct PersonalityQuestion SassyQuest2;
extern const struct PersonalityQuestion SassyQuest3;
extern const struct PersonalityQuestion SassyQuest4;
extern const struct PersonalityQuestion CalmQuest1;
extern const struct PersonalityQuestion CalmQuest2;
extern const struct PersonalityQuestion CalmQuest3;
extern const struct PersonalityQuestion CalmQuest4;
extern const struct PersonalityQuestion RelaxedQuest1;
extern const struct PersonalityQuestion RelaxedQuest2;
extern const struct PersonalityQuestion RelaxedQuest3;
extern const struct PersonalityQuestion RelaxedQuest4;
extern const struct PersonalityQuestion LonelyQuest1;
extern const struct PersonalityQuestion LonelyQuest2;
extern const struct PersonalityQuestion LonelyQuest3;
extern const struct PersonalityQuestion LonelyQuest4;
extern const struct PersonalityQuestion QuirkyQuest1;
extern const struct PersonalityQuestion QuirkyQuest2;
extern const struct PersonalityQuestion QuirkyQuest3;
extern const struct PersonalityQuestion QuirkyQuest4;
extern const struct PersonalityQuestion MiscQuest1;
extern const struct PersonalityQuestion MiscQuest2;
extern const struct PersonalityQuestion MiscQuest3;
extern const struct PersonalityQuestion BraveQuest2B;


const struct PersonalityQuestion * const gPersonalityQuestionPointerTable[NUM_QUIZ_QUESTIONS + 1] =
{
    &HardyQuest1,
    &HardyQuest2,
    &HardyQuest3,
    &HardyQuest4,
    &DocileQuest1,
    &DocileQuest2,
    &DocileQuest3,
    &DocileQuest4,
    &BraveQuest1,
    &BraveQuest2A,
    &BraveQuest3,
    &BraveQuest4,
    &JollyQuest1,
    &JollyQuest2,
    &JollyQuest3,
    &JollyQuest4,
    &ImpishQuest1,
    &ImpishQuest2,
    &ImpishQuest3,
    &ImpishQuest4,
    &NaiveQuest1,
    &NaiveQuest2,
    &NaiveQuest3,
    &NaiveQuest4,
    &TimidQuest1,
    &TimidQuest2,
    &TimidQuest3,
    &TimidQuest4,
    &HastyQuest1,
    &HastyQuest2,
    &HastyQuest3,
    &HastyQuest4,
    &SassyQuest1,
    &SassyQuest2,
    &SassyQuest3,
    &SassyQuest4,
    &CalmQuest1,
    &CalmQuest2,
    &CalmQuest3,
    &CalmQuest4,
    &RelaxedQuest1,
    &RelaxedQuest2,
    &RelaxedQuest3,
    &RelaxedQuest4,
    &LonelyQuest1,
    &LonelyQuest2,
    &LonelyQuest3,
    &LonelyQuest4,
    &QuirkyQuest1,
    &QuirkyQuest2,
    &QuirkyQuest3,
    &QuirkyQuest4,
    &MiscQuest1,
    &MiscQuest2,
    &MiscQuest3,
    &BraveQuest2B
};


// NOTE: 2nd Part of Brave is included at the end so it isn't actually chosen
const u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS + 1] =
{
    HARDY,
    HARDY,
    HARDY,
    HARDY,
    DOCILE,
    DOCILE,
    DOCILE,
    DOCILE,
    BRAVE,
    BRAVE,
    BRAVE,
    BRAVE,
    JOLLY,
    JOLLY,
    JOLLY,
    JOLLY,
    IMPISH,
    IMPISH,
    IMPISH,
    IMPISH,
    NAIVE,
    NAIVE,
    NAIVE,
    NAIVE,
    TIMID,
    TIMID,
    TIMID,
    TIMID,
    HASTY,
    HASTY,
    HASTY,
    HASTY,
    SASSY,
    SASSY,
    SASSY,
    SASSY,
    CALM,
    CALM,
    CALM,
    CALM,
    RELAXED,
    RELAXED,
    RELAXED,
    RELAXED,
    LONELY,
    LONELY,
    LONELY,
    LONELY,
    QUIRKY,
    QUIRKY,
    QUIRKY,
    QUIRKY,
    MISC,
    MISC,
    MISC,
    BRAVE
};

ALIGNED(4) const u8 gGenderText[] = "Are you a boy or a girl?";
const char * const gGenderTextPtr = gGenderText;


const struct MenuItem gGenderMenu[] =
{
    {BoyText, 0},
    {GirlText, 1},
    {NULL, -1},
};

ALIGNED(4) const u8 GirlText[] = "Girl.";
ALIGNED(4) const u8 BoyText[] = "Boy.";

const u8 unknownPersonality[] = 
{
    1, 2, 3, 4, 5, 6, 7, 8, 9, 0xA, 0xB, 0xC, 0xD
};

const s16 gStarters[NUM_PERSONALITIES][2] =
{
    //          MALE / FEMALE
    [HARDY]  =  {SPECIES_CHARMANDER, SPECIES_PIKACHU},
    [DOCILE] =  {SPECIES_BULBASAUR, SPECIES_CHIKORITA},
    [BRAVE]  =  {SPECIES_MACHOP, SPECIES_CHARMANDER},
    [JOLLY]  =  {SPECIES_SQUIRTLE, SPECIES_TOTODILE},
    [IMPISH] =  {SPECIES_PIKACHU, SPECIES_CUBONE},
    [NAIVE]  =  {SPECIES_TOTODILE, SPECIES_EEVEE},
    [TIMID]  =  {SPECIES_CYNDAQUIL, SPECIES_MUDKIP},
    [HASTY]  =  {SPECIES_TORCHIC, SPECIES_SKITTY},
    [SASSY]  =  {SPECIES_TREECKO, SPECIES_TORCHIC},
    [CALM]   =  {SPECIES_MUDKIP, SPECIES_BULBASAUR},
    [RELAXED] = {SPECIES_PSYDUCK, SPECIES_SQUIRTLE},
    [LONELY]  = {SPECIES_CUBONE, SPECIES_PSYDUCK},
    [QUIRKY]  = {SPECIES_MEOWTH, SPECIES_TREECKO}
};


ALIGNED(4) const char gStarterReveal[] = _("\n{CENTER_ALIGN}The Pokémon {ARG_POKEMON_0}!");
const char * const gStarterRevealPtr = gStarterReveal;

ALIGNED(4) const char gPartnerPrompt[] = _(
        "{CENTER_ALIGN}This is the final step.{WAIT_PRESS}\n"
        "{CENTER_ALIGN}Who would you like to have as a partner?{EXTRA_MSG}"
        "{CENTER_ALIGN}Choose the Pokémon you want\n"
        "{CENTER_ALIGN}as your partner from this group.");
const char * const gPartnerPromptPtr = gPartnerPrompt;

ALIGNED(4) const char gPartnerNickPrompt[] = _("{CENTER_ALIGN}What is your partner{APOSTROPHE}s nickname?");
const char * const gPartnerNickPromptPtr = gPartnerNickPrompt;

ALIGNED(4) const char gEndIntroText[] = _(
        "{CENTER_ALIGN}OK! We{APOSTROPHE}re all set!{EXTRA_MSG}"
        "{CENTER_ALIGN}Let{APOSTROPHE}s get you into the\n"
        "{CENTER_ALIGN}world of Pokémon!{EXTRA_MSG}"
        "{CENTER_ALIGN}Go for it!");
const char * const gEndIntroTextPtr = gEndIntroText;

const char * const gPersonalityTypeDescriptionTable[NUM_PERSONALITIES] =
{
    [HARDY] = gHardyDescription,
    [DOCILE] = gDocileDescription,
    [BRAVE] = gBraveDescription,
    [JOLLY] = gJollyDescription,
    [IMPISH] = gImpishDescription,
    [NAIVE] = gNaiveDescription,
    [TIMID] = gTimidDescription,
    [HASTY] = gHastyDescription,
    [SASSY] = gSassyDescription,
    [CALM] = gCalmDescription,
    [RELAXED] = gRelaxedDescription,
    [LONELY] = gLonelyDescription,
    [QUIRKY] = gQuirkyDescription
};

#include "data/nature_description.h"

const struct UnkTextStruct2 gUnknown_80F4244 =
{
    0x00, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00,
    0x0C, 0x00, 0x06, 0x00,
    0x05, 0x05,
    0x05, 0x00,
    NULL
};

const char filler[] = "pksdir0"; // CHUNSOFT inserted for aligning data

const s16 gPartners[NUM_PARTNERS] =
{
    SPECIES_CHARMANDER,
    SPECIES_BULBASAUR,
    SPECIES_SQUIRTLE,
    SPECIES_PIKACHU,
    SPECIES_CHIKORITA,
    SPECIES_TOTODILE,
    SPECIES_CYNDAQUIL,
    SPECIES_TORCHIC,
    SPECIES_TREECKO,
    SPECIES_MUDKIP
};

const struct UnkTextStruct2 gUnknown_80F4278 =
{
    0x00, 0x00, 0x00, 0x00,
    0x03, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00,
    0x00, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80F4290 =
{
    0x00, 0x00, 0x00, 0x00,
    0x06, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x02, 0x00,
    0x09, 0x0B,
    0x0D, 0x00,
    NULL
};

const struct UnkTextStruct2 gUnknown_80F42A8 =
{
    0x00, 0x00, 0x00, 0x00,
    0x05, 0x00, 0x00, 0x00,
    0x0E, 0x00, 0x04, 0x00,
    0x05, 0x05,
    0x05, 0x00,
    NULL
};

const char gPartnerSelectionHeaderText[] = _("Pokémon");
const char personality_test_fill[] = "pksdir0";

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
        AdvanceToPickPartnerPrompt();
        break;
    case 7:
        PromptPickPartner();
        break;
    case 8:
        AdvanceToPartnerSelection();
        break;
    case 9:
        CallCreatePartnerSelectionMenu();
        break;
    case 10:
        PromptForPartnerNickname();
        break;
    case 11:
        AdvanceToPartnerNickhameScreen();
        break;
    case 12:
        NicknamePartner();
        break;
    case 13:
        PrintEndIntroText();
        break;
    case 14:
        AdvanceToTestEnd();
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
        sub_8014248(gGenderText, 0, 0, gGenderMenu, 0, 3, 0, 0, 257);
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

void UpdateNatureTotals()
{
    s32 answerIndex;
    s32 natureIndex;
    const u8 *pointArray;

    if (!sub_80144A4(&answerIndex))
    {
        // This is for the second part of Brave 2 Question if you fight..
        if (answerIndex == BRAVE_2B_TRIGGER)
        {
            // Set question to BRAVE_2B and ask the question..
            gUnknown_203B400->currQuestionIndex = NUM_QUIZ_QUESTIONS;
            gUnknown_203B400->TestState = 1;
        }
        else
        {
            pointArray = gPersonalityQuestionPointerTable[gUnknown_203B400->currQuestionIndex]->effects;
            // Skip until we get to the one for our answer
            // Each Answer has 16 bytes. 13 are currently used with 3 remaining
            pointArray += (NUM_PERSONALITIES + 3) * answerIndex;
            for (natureIndex = 0; natureIndex < NUM_PERSONALITIES; natureIndex++)
            {
                gUnknown_203B400->NatureTotals[natureIndex] += pointArray[natureIndex];
            }
            gUnknown_203B400->TestState = 0;
        }
    }
}

void SetPlayerGender(void)
{

    int gender;

    if (sub_80144A4(&gender) == 0) {
        if (gender == MALE) {
            gUnknown_203B400->playerGender = MALE;
            gUnknown_203B46C->playerGender = MALE;
        }
        else
        {
            gUnknown_203B400->playerGender = FEMALE;
            gUnknown_203B46C->playerGender = FEMALE;
        }
        sub_8099690(0);
        gUnknown_203B400->TestState = 4;
    }
}

void RevealPersonality(void)
{
  s32 currentNature;
  s32 counter;

  gUnknown_203B400->playerNature = RandomCapped(NUM_PERSONALITIES);
  currentNature = gUnknown_203B400->playerNature;

  for(counter = 0; counter < NUM_PERSONALITIES - 1; counter++){
    currentNature++;

    // Wraparound check
    if (currentNature > QUIRKY) {
      currentNature = HARDY;
    }

    if (gUnknown_203B400->NatureTotals[currentNature] > gUnknown_203B400->NatureTotals[gUnknown_203B400->playerNature]) {
      gUnknown_203B400->playerNature = currentNature;
    }
  }
  gUnknown_203B400->StarterID = gStarters[gUnknown_203B400->playerNature][gUnknown_203B400->playerGender];
  PrintPersonalityTypeDescription();
  gUnknown_203B400->TestState = 5;
}

void RevealStarter(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    sub_80141B4(gStarterReveal,0,0,0x101);
    PersonalityTest_DisplayStarterSprite();
    gUnknown_203B400->TestState = 6;
  }
}

void AdvanceToPickPartnerPrompt(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    gUnknown_203B400->TestState = 7;
  }
}

void PromptPickPartner(void)
{
    sub_80141B4(gPartnerPrompt, 0, 0, 0x301);
    gUnknown_203B400->TestState = 8;
}

void AdvanceToPartnerSelection(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    gUnknown_203B400->TestState = 9;
  }
}

void CallCreatePartnerSelectionMenu(void)
{
    CreatePartnerSelectionMenu(gUnknown_203B400->StarterID);
    gUnknown_203B400->TestState = 10;
}

void PromptForPartnerNickname(void)
{
  u16 selectedPartner;

  selectedPartner = HandlePartnerSelectionInput();
  if (selectedPartner != 0xffff)
  {
      if(selectedPartner != 0xfffe) {
        sub_803CE6C();
        gUnknown_203B400->PartnerID = selectedPartner;
        sub_80141B4(gPartnerNickPrompt, 0, 0, 0x301);
        gUnknown_203B400->TestState = 11;
      }
  }
}

void AdvanceToPartnerNickhameScreen(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    gUnknown_203B400->TestState = 12;
  }
}

void NicknamePartner(void)
{
  CopyStringtoBuffer(gUnknown_203B400->PartnerNick, GetMonSpecies(gUnknown_203B400->PartnerID));
  sub_801602C(3, gUnknown_203B400->PartnerNick);
  gUnknown_203B400->TestState = 13;
}

void PrintEndIntroText(void)
{
  if (sub_8016080() != 0) {
    sub_80160D8();
    sub_80141B4(gEndIntroText, 0, 0, 0x301);
    gUnknown_203B400->TestState = 14;
  }
}

void AdvanceToTestEnd(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    gUnknown_203B400->TestState = 15;
  }
}

void PromptNewQuestion(void)
{
  sub_8014248(gPersonalityQuestionPointerTable[gUnknown_203B400->currQuestionIndex]->question,
              0, 0,
              (struct MenuItem *)gPersonalityQuestionPointerTable[gUnknown_203B400->currQuestionIndex]->answers,
              0, 3, 0, 0, 0x101);
}

void PrintPersonalityTypeDescription(void)
{
  CopySpeciesNametoBuffer(gAvailablePokemonNames, gUnknown_203B400->StarterID);
  sub_80141B4(gPersonalityTypeDescriptionTable[gUnknown_203B400->playerNature],0,
              0,0x101);
}

void PersonalityTest_DisplayStarterSprite(void)
{
  s32 starterID;
  struct OpenedFile *faceFile;
  int palleteIndex;
  u8 *r6;
  u32 faceIndex;
  struct UnkTextStruct2 stackArray[4];

  starterID = gUnknown_203B400->StarterID;
  sub_8006518(stackArray);
  stackArray[1] = gUnknown_80F4244;
  ResetUnusedInputStruct();
  sub_800641C(stackArray, 1, 0);
  sub_8008C54(1);
  sub_80073B8(1);
  faceFile = GetDialogueSpriteDataPtr(starterID);
  r6 = ((struct FaceData *)(faceFile->data))->unk0[1 + EMOTION_HAPPY];
  faceIndex = EMOTION_HAPPY;
  for(palleteIndex = 0; palleteIndex < 16; palleteIndex++){
    SetBGPaletteBufferColorArray(palleteIndex + 224, &((struct FaceData *)(faceFile->data))->unk0[faceIndex][palleteIndex << 2]);
  }
  sub_800836C(1, r6, 0xe);
  CloseFile(faceFile);
  sub_80073E0(1);
}

void CreatePartnerSelectionMenu(s16 starterID)
{
    s32 starterID_s32;
    starterID_s32 = starterID; // force an asr shift.. does lsr without it

    sub_803CEAC(); // creates 203B404
    gUnknown_203B404->StarterID = starterID_s32;
    gUnknown_203B404->unk4C = 0;
    gUnknown_203B404->unk50 = gUnknown_203B404->unk54;

    gUnknown_203B404->unk54[0] = gUnknown_80F4290;
    gUnknown_203B404->unk54[1] = gUnknown_80F42A8;
    gUnknown_203B404->unk54[2] = gUnknown_80F4278;
    gUnknown_203B404->unk54[3] = gUnknown_80F4278;

    gUnknown_203B404->unk50->unk14 = gUnknown_203B404->unkb4;

    gUnknown_203B404->unkb4[0] = 1;
    gUnknown_203B404->unkb4[1] = 0;
    gUnknown_203B404->unkb4[2] = 6;
    gUnknown_203B404->unkb4[3] = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B404->unk54, 1, 1);
    sub_8013818(&gUnknown_203B404->unk18, GetValidPartners(), 0xA, gUnknown_203B404->unk4C);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();
}


u16 HandlePartnerSelectionInput(void)
{
  s32 partnerID;

  partnerID = gUnknown_203B404->currPartnerSelection;
  gUnknown_203B404->unk16 = 0;
  if (GetKeyPress(&gUnknown_203B404->unk18) == A_BUTTON) {
    PlayMenuSoundEffect(0);
    return gUnknown_203B404->PartnerArray[gUnknown_203B404->currPartnerSelection];
  }
  else {
    if (sub_80138B8(&gUnknown_203B404->unk18, 1) != '\0') {
      RedrawPartnerSelectionMenu();
    }
    if (partnerID != gUnknown_203B404->currPartnerSelection) {
      PersonalityTest_DisplayPartnerSprite();
    }
    if (gUnknown_203B404->unk16 != '\0') {
      return -2;
    }
    else {
      return -1;
    }
  }
}

void sub_803CE34(u8 param_1)
{
  gUnknown_203B404->numPartners = GetValidPartners();
  sub_8013984(&gUnknown_203B404->unk18);
  RedrawPartnerSelectionMenu();
  PersonalityTest_DisplayPartnerSprite();
  if (param_1 != 0) {
    AddMenuCursorSprite(&gUnknown_203B404->unk18);
  }
}

void sub_803CE6C()
{
  gUnknown_203B404->unk54[gUnknown_203B404->unk4C] = gUnknown_80F4278;
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B404->unk54, 1, 1);
  sub_803CECC(); // Free 203B404
}

void sub_803CEAC(void)
{
    gUnknown_203B404 = MemoryAlloc(sizeof(struct PersonalityStruct_203B404), 8);
    nullsub_135();
}

void nullsub_135(void)
{
}


void sub_803CECC(void)
{
    if(gUnknown_203B404 != NULL){
        nullsub_135();
        MemoryFree(gUnknown_203B404);
        gUnknown_203B404 = NULL;
    }
}

#ifdef NONMATCHING
void RedrawPartnerSelectionMenu(void)
{
  s32 sVar1;
  u32 yCoord;
  const char *monName;
  s32 monCounter;

  sVar1 = sub_80095E4(gUnknown_203B404->unk32, 0xc);

  // Have a feeling this is some graphical thing but
  // still not sure structure so it's not matching yet bc of that
  // and some casting stuff
  sVar1 += 2;
  sVar1 <<= 16;
  gUnknown_203B404->unk54[gUnknown_203B404->unk4C].unk0[7] = sVar1;
  gUnknown_203B404->unk54[gUnknown_203B404->unk4C].unk0[8] = sVar1 + 2;

  // Everything after this matches
  ResetUnusedInputStruct();
  sub_800641C(gUnknown_203B404->unk54,1,1);
  sub_8008C54(gUnknown_203B404->unk4C);
  sub_80073B8(gUnknown_203B404->unk4C);
  xxx_call_draw_string(0xc, 0, gPartnerSelectionHeaderText, gUnknown_203B404->unk4C, 0);

  monCounter = 0;
  while (monCounter < gUnknown_203B404->unk32) {
    yCoord = sub_8013800(&gUnknown_203B404->unk18, monCounter);
    monName = GetMonSpecies(gUnknown_203B404->PartnerArray[monCounter]);
    xxx_call_draw_string(8, yCoord, monName, gUnknown_203B404->unk4C, 0);
    monCounter++;
  }
  sub_80073E0(gUnknown_203B404->unk4C);
  gUnknown_203B404->unk16 = 1;
}
#else
NAKED
void RedrawPartnerSelectionMenu(void)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tsub sp, 0x4\n"
	"\tldr r6, _0803CF60\n"
	"\tldr r0, [r6]\n"
	"\tmovs r1, 0x32\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tmovs r1, 0xC\n"
	"\tbl sub_80095E4\n"
	"\tadds r0, 0x2\n"
	"\tlsls r0, 16\n"
	"\tldr r2, [r6]\n"
	"\tldr r3, [r2, 0x4C]\n"
	"\tlsls r1, r3, 1\n"
	"\tadds r1, r3\n"
	"\tlsls r1, 3\n"
	"\tadds r1, r2, r1\n"
	"\tadds r1, 0x62\n"
	"\tmovs r4, 0\n"
	"\tasrs r3, r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tstrh r0, [r1]\n"
	"\tldr r1, [r2, 0x4C]\n"
	"\tlsls r0, r1, 1\n"
	"\tadds r0, r1\n"
	"\tlsls r0, 3\n"
	"\tadds r2, r0\n"
	"\tadds r3, 0x2\n"
	"\tadds r2, 0x64\n"
	"\tstrh r3, [r2]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r6]\n"
	"\tadds r0, 0x54\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r0, [r6]\n"
	"\tldr r0, [r0, 0x4C]\n"
	"\tbl sub_8008C54\n"
	"\tldr r0, [r6]\n"
	"\tldr r0, [r0, 0x4C]\n"
	"\tbl sub_80073B8\n"
	"\tldr r2, _0803CF64\n"
	"\tldr r0, [r6]\n"
	"\tldr r3, [r0, 0x4C]\n"
	"\tstr r4, [sp]\n"
	"\tmovs r0, 0xC\n"
	"\tmovs r1, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tmovs r5, 0\n"
	"\tb _0803CF98\n"
	"\t.align 2, 0\n"
"_0803CF60: .4byte gUnknown_203B404\n"
"_0803CF64: .4byte gPartnerSelectionHeaderText\n"
"_0803CF68:\n"
	"\tldr r0, [r6]\n"
	"\tadds r0, 0x18\n"
	"\tadds r1, r5, 0\n"
	"\tbl sub_8013800\n"
	"\tadds r4, r0, 0\n"
	"\tldr r0, [r6]\n"
	"\tlsls r1, r5, 1\n"
	"\tadds r0, 0x2\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tbl GetMonSpecies\n"
	"\tadds r2, r0, 0\n"
	"\tldr r0, [r6]\n"
	"\tldr r3, [r0, 0x4C]\n"
	"\tmovs r0, 0\n"
	"\tstr r0, [sp]\n"
	"\tmovs r0, 0x8\n"
	"\tadds r1, r4, 0\n"
	"\tbl xxx_call_draw_string\n"
	"\tadds r5, 0x1\n"
"_0803CF98:\n"
	"\tldr r0, [r6]\n"
	"\tmovs r1, 0x32\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tcmp r5, r0\n"
	"\tblt _0803CF68\n"
	"\tldr r4, _0803CFBC\n"
	"\tldr r0, [r4]\n"
	"\tldr r0, [r0, 0x4C]\n"
	"\tbl sub_80073E0\n"
	"\tldr r1, [r4]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x16]\n"
	"\tadd sp, 0x4\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0803CFBC: .4byte gUnknown_203B404");
}
#endif

void PersonalityTest_DisplayPartnerSprite(void)
{
  s32 partnerID;
  struct OpenedFile *faceFile;
  int palleteIndex;
  u8 *r6;
  u32 faceIndex;

  partnerID = gUnknown_203B404->PartnerArray[gUnknown_203B404->currPartnerSelection];
  sub_8008C54(1);
  sub_80073B8(1);
  faceFile = GetDialogueSpriteDataPtr(partnerID);
  r6 = ((struct FaceData *)(faceFile->data))->unk0[1 + EMOTION_NORMAL];
  faceIndex = EMOTION_NORMAL;
  for(palleteIndex = 0; palleteIndex < 16; palleteIndex++){
    SetBGPaletteBufferColorArray(palleteIndex + 224,&((struct FaceData *)(faceFile->data))->unk0[faceIndex][palleteIndex << 2]);
  }
  sub_800836C(1,r6,0xe);
  CloseFile(faceFile);
  sub_80073E0(1);
  gUnknown_203B404->unk16 = 1;
}

s32 GetValidPartners(void)
{
  u8 PlayerType[2];
  u8 currentPartnerTypes[2];
  s32 counter;
  s32 ValidPartnerCounter;
  s32 CurrentPartnerID;

  ValidPartnerCounter = 0;
  PlayerType[0] = GetPokemonType(gUnknown_203B404->StarterID, 0);
  PlayerType[1] = GetPokemonType(gUnknown_203B404->StarterID, 1);
  for(counter = 0; counter < NUM_PARTNERS; counter++){
    CurrentPartnerID = gPartners[counter];
    currentPartnerTypes[0] = GetPokemonType(CurrentPartnerID, 0);
    currentPartnerTypes[1] = GetPokemonType(CurrentPartnerID, 1);
    if (((currentPartnerTypes[0] == '\0') || ((currentPartnerTypes[0] != PlayerType[0] && (currentPartnerTypes[0] != PlayerType[1]))))
       && ((currentPartnerTypes[1] == '\0' || ((currentPartnerTypes[1] != PlayerType[0] && (currentPartnerTypes[1] != PlayerType[1])))
           ))) {
      gUnknown_203B404->PartnerArray[ValidPartnerCounter] = CurrentPartnerID;
      ValidPartnerCounter++;
    }
  }
  return ValidPartnerCounter;
}
