#include "global.h"
#include "personality_test.h"
#include "constants/emotions.h"
#include "constants/species.h"
#include "random.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "save.h"
#include "memory.h"
#include "gUnknown_203B46C.h"
#include "text.h"

extern void sub_801317C(u32 *);
extern void sub_8001024(u32 *);
extern s32 sub_8094E4C(void);
extern void sub_8094D28(s32);
extern void sub_8001044(u32 *);

extern void sub_80141B4(const char *text, u32 r1, u32 r2, u16 r3);
extern void sub_8014248(const char *text, u32, u32, u32 *r0, u32, u32, u32, u32, u32);

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
extern void xxx_call_draw_string(u32 size, u32, const char *text, u32, u32);
extern u32 sub_80095E4(s16, u32);

extern struct PersonalityQuestion *gPersonalityQuestionPointerTable[NUM_QUIZ_QUESTIONS];

extern struct UnkSaveStruct1 *gUnknown_203B46C;

extern const char gStarterReveal[];
extern const char gGenderText[];
extern u32 gGenderMenu;
extern const char gUnknown_80F42C0;

extern u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS];
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

const char gStarterReveal[] = _("\n{CENTER_ALIGN}The Pokémon $m0!");
const char * const gStarterRevealPtr = gStarterReveal;

const char gPartnerPrompt[] = _(
        "{CENTER_ALIGN}This is the final step.{WAIT_PRESS}\n"
        "{CENTER_ALIGN}Who would you like to have as a partner?{EXTRA_MSG}"
        "{CENTER_ALIGN}Choose the Pokémon you want\n"
        "{CENTER_ALIGN}as your partner from this group.");
const char * const gPartnerPromptPtr = gPartnerPrompt;

const char gPartnerNickPrompt[] = _("{CENTER_ALIGN}What is your partner~27s nickname?");
const char * const gPartnerNickPromptPtr = gPartnerNickPrompt;

ALIGNED(4) const char gEndIntroText[] = _(
        "{CENTER_ALIGN}OK! We~27re all set!{EXTRA_MSG}"
        "{CENTER_ALIGN}Let~27s get you into the\n"
        "{CENTER_ALIGN}world of Pokémon!{EXTRA_MSG}"
        "{CENTER_ALIGN}Go for it!");
const char * const gEndIntroTextPtr = gEndIntroText;

const char * const gPersonalityTypeDescriptionTable[NUM_PERSONALITIES] = 
{
    gHardyDescription,
    gDocileDescription,
    gBraveDescription,
    gJollyDescription,
    gImpishDescription,
    gNaiveDescription,
    gTimidDescription,
    gHastyDescription,
    gSassyDescription,
    gCalmDescription,
    gRelaxedDescription,
    gLonelyDescription,
    gQuirkyDescription
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
        CallCreatePartnerSelectionMenu();
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
        PrintEndIntroText();
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
        sub_8014248(gGenderText, 0, 0, &gGenderMenu, 0, 3, 0, 0, 257);
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

NAKED
void UpdateNatureTotals(void)
{
    asm_unified(
	"\tpush {r4-r6,lr}\n"
	"\tsub sp, 0x4\n"
	"\tmov r0, sp\n"
	"\tbl sub_80144A4\n"
	"\tcmp r0, 0\n"
	"\tbne _0803C97C\n"
	"\tldr r3, [sp]\n"
	"\tcmp r3, 0x63\n"
	"\tbne _0803C944\n"
	"\tldr r0, _0803C940\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x37\n"
	"\tstr r0, [r1, 0x3C]\n"
	"\tmovs r0, 0x1\n"
	"\tb _0803C97A\n"
	"\t.align 2, 0\n"
"_0803C940: .4byte gUnknown_203B400\n"
"_0803C944:\n"
	"\tldr r1, _0803C984\n"
	"\tldr r2, _0803C988\n"
	"\tldr r0, [r2]\n"
	"\tldr r0, [r0, 0x3C]\n"
	"\tlsls r0, 2\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tldr r4, [r0, 0x8]\n"
	"\tlsls r0, r3, 4\n"
	"\tadds r4, r0\n"
	"\tmovs r3, 0\n"
	"\tadds r6, r2, 0\n"
	"\tadds r5, r6, 0\n"
"_0803C95E:\n"
	"\tldr r1, [r5]\n"
	"\tlsls r0, r3, 2\n"
	"\tadds r1, 0x44\n"
	"\tadds r1, r0\n"
	"\tadds r0, r4, r3\n"
	"\tldrb r2, [r0]\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, r2\n"
	"\tstr r0, [r1]\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0xC\n"
	"\tble _0803C95E\n"
	"\tldr r1, [r6]\n"
	"\tmovs r0, 0\n"
"_0803C97A:\n"
	"\tstr r0, [r1, 0x34]\n"
"_0803C97C:\n"
	"\tadd sp, 0x4\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0803C984: .4byte gPersonalityQuestionPointerTable\n"
"_0803C988: .4byte gUnknown_203B400"
    );
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

#ifdef NONMATCHING
void RevealPersonality(void)
{
  s32 currentNature;
  s32 counter;

  gUnknown_203B400->playerNature = RandomCapped(NUM_PERSONALITIES);
  currentNature = gUnknown_203B400->playerNature;

  // 2 Statements flip-flop but is functionaly equivalent
  // Struct saving into register and intialize of the counter
  for(counter = NUM_PERSONALITIES - 2; counter >= 0; counter--){
    currentNature = currentNature++;

    // Wraparound check
    if (currentNature > NUM_PERSONALITIES - 1) {
      currentNature = 0;
    }

    if (gUnknown_203B400->NatureTotals[currentNature] > gUnknown_203B400->NatureTotals[gUnknown_203B400->playerNature]) {
      gUnknown_203B400->playerNature = currentNature;
    }
  }
  gUnknown_203B400->StarterID = gStarters[gUnknown_203B400->playerNature][gUnknown_203B400->playerGender];
  PrintPersonalityTypeDescription();
  gUnknown_203B400->TestState = 5;
}
#else
NAKED
void RevealPersonality(void)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmovs r0, 0xD\n"
	"\tbl RandomCapped\n"
	"\tldr r2, _0803CA4C\n"
	"\tldr r1, [r2]\n"
	"\tadds r1, 0x40\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, [r2]\n"
	"\tadds r0, 0x40\n"
	"\tldrb r3, [r0]\n"
	"\tadds r7, r2, 0\n"
	"\tmovs r5, 0xB\n"
"_0803C9F2:\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0xC\n"
	"\tble _0803C9FA\n"
	"\tmovs r3, 0\n"
"_0803C9FA:\n"
	"\tldr r0, [r7]\n"
	"\tlsls r2, r3, 2\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x44\n"
	"\tadds r2, r1, r2\n"
	"\tadds r4, r0, 0\n"
	"\tadds r4, 0x40\n"
	"\tldrb r0, [r4]\n"
	"\tlsls r0, 2\n"
	"\tadds r1, r0\n"
	"\tldr r2, [r2]\n"
	"\tldr r0, [r1]\n"
	"\tldr r6, _0803CA4C\n"
	"\tcmp r2, r0\n"
	"\tble _0803CA1A\n"
	"\tstrb r3, [r4]\n"
"_0803CA1A:\n"
	"\tsubs r5, 0x1\n"
	"\tcmp r5, 0\n"
	"\tbge _0803C9F2\n"
	"\tldr r3, [r6]\n"
	"\tldr r2, _0803CA50\n"
	"\tadds r0, r3, 0\n"
	"\tadds r0, 0xB0\n"
	"\tldr r1, [r0]\n"
	"\tlsls r1, 1\n"
	"\tsubs r0, 0x70\n"
	"\tldrb r0, [r0]\n"
	"\tlsls r0, 2\n"
	"\tadds r1, r0\n"
	"\tadds r1, r2\n"
	"\tldrh r0, [r1]\n"
	"\tstrh r0, [r3, 0x8]\n"
	"\tbl PrintPersonalityTypeDescription\n"
	"\tldr r1, [r6]\n"
	"\tmovs r0, 0x5\n"
	"\tstr r0, [r1, 0x34]\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0803CA4C: .4byte gUnknown_203B400\n"
"_0803CA50: .4byte gStarters");
}
#endif

void RevealStarter(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    sub_80141B4(gStarterReveal,0,0,0x101);
    PersonalityTest_DisplayStarterSprite();
    gUnknown_203B400->TestState = 6;
  }
}

void sub_803CA8C(void)
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

void sub_803CAD4(void)
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

void sub_803CB5C(void)
{
  s32 temp;

  if (sub_80144A4(&temp) == 0) {
    gUnknown_203B400->TestState = 12;
  }
}

void sub_803CB7C(void)
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

void sub_803CBE4(void)
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
              (void *)gPersonalityQuestionPointerTable[gUnknown_203B400->currQuestionIndex]->answers,
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
  s32 sVar1;

  sVar1 = gUnknown_203B404->currPartnerSelection;
  gUnknown_203B404->unk16 = 0;
  if (GetKeyPress(&gUnknown_203B404->unk18) == A_BUTTON) {
    PlayMenuSoundEffect(0);
    return gUnknown_203B404->PartnerArray[gUnknown_203B404->currPartnerSelection];
  }
  else {
    if (sub_80138B8(&gUnknown_203B404->unk18, 1) != '\0') {
      RedrawPartnerSelectionMenu();
    }
    if (sVar1 != gUnknown_203B404->currPartnerSelection) {
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
  u32 uVar2;
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
  xxx_call_draw_string(0xc, 0, &gUnknown_80F42C0, gUnknown_203B404->unk4C, 0);

  monCounter = 0;
  while (monCounter < gUnknown_203B404->unk32) {
    uVar2 = sub_8013800(&gUnknown_203B404->unk18, monCounter);
    monName = GetMonSpecies(gUnknown_203B404->PartnerArray[monCounter]);
    xxx_call_draw_string(8, uVar2, monName, gUnknown_203B404->unk4C, 0);
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
"_0803CF64: .4byte gUnknown_80F42C0\n"
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
