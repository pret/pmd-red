#include "global.h"
#include "personality_test.h"
#include "constants/emotions.h"
#include "random.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"

extern void* MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void sub_801317C(u32 *);
extern void sub_8099690(u32);
extern void sub_8001024(u32 *);
extern s32 sub_8094E4C(void);
extern void sub_8011C40(s32);
extern void sub_8094D28(s32);
extern void sub_8001044(u32 *);



struct UnkSaveStruct1
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 playerGender;
};
extern struct UnkSaveStruct1 *gUnknown_203B46C;

// The frick... This is definitely wrong in terms of members
// There's 5 pointers in the data
struct FaceData
{
    /* 0x0 */ u8 *unk0[5];
};

struct stack_PartnerSprite
{
    // size: 0x60
    u32 unk0;
    u8 padding[0x18 - 4];
    struct unkData data;
    u32 padding2[12];
};

extern void sub_80141B4(const char *text, u32 r1, u32 r2, u16 r3);
extern void sub_8014248(const char *text, u32, u32, u32 *r0, u32, u32, u32, u32, u32);

extern u32 sub_80144A4(s32 *);

extern void sub_803CE6C(void);
extern char* GetMonSpecies(u32);
extern void CopyStringtoBuffer(s32 *r0, char *r1);
extern void sub_801602C(u32, s32 *r0);

extern u32 sub_8016080(void);
extern void sub_80160D8(void);
extern void sub_8099690(u32);
extern void CopySpeciesNametoBuffer(char *r0, u32);

extern void sub_8006518(void *);
extern void sub_800641C(void *, u32, u32);
extern void sub_80073E0(u32);
extern void sub_80073B8(u32);
extern void sub_8008C54(u32);
extern void sub_800836C(u32, u8 *r0, u32);
extern void SetBGPaletteBufferColorArray(s32 index, u8 *colorArray);

extern void sub_803CEAC(void);
extern void RedrawPartnerSelectionMenu(void);
extern void sub_8013818(u32 *r0, s32, u32, u32);

extern u32 GetKeyPress(struct UnkInputStruct **r0);
extern u8 sub_80138B8(struct UnkInputStruct **r0, u32);
extern void sub_80119D4(u32);


extern void sub_8013984(struct UnkInputStruct **r0);
extern void AddMenuCursorSprite(struct UnkInputStruct **r0);

extern const char gStarterReveal;
extern const char gPartnerPrompt;
extern const char gPartnerNickPrompt;
extern const char gEndIntroText;
extern const char gGenderText;
extern u32 gGenderMenu;

extern u8 gNatureQuestionTable[NUM_QUIZ_QUESTIONS];
extern const char *gPersonalityTypeDescriptionTable[];

extern char gAvailablePokemonNames[0x50];


struct unkData gUnknown_80F4244 = 
{
    0, 0, 0, 0,
    5, 0, 0, 0,
    0xC, 0, 6, 0,
    5, 0, 5, 0,
    5, 0, 0, 0,
    0, 0, 0, 0,
};

const u8 filler[8] = 
{
    'p', 'k', 's', 'd', 'i', 'r', '0', 0
};

extern struct unkData gUnknown_80F4278;


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
    sub_80141B4(&gStarterReveal,0,0,0x101);
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
    sub_80141B4(&gPartnerPrompt, 0, 0, 0x301);
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
        sub_80141B4(&gPartnerNickPrompt, 0, 0, 0x301);
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
  char *monName;
  s32 *iVar2;

  iVar2 = &gUnknown_203B400->unk20;
  monName = GetMonSpecies(gUnknown_203B400->PartnerID);
  CopyStringtoBuffer(iVar2, monName);
  sub_801602C(3, &gUnknown_203B400->unk20);
  gUnknown_203B400->TestState = 13;
}

void PrintEndIntroText(void)
{
  if (sub_8016080() != 0) {
    sub_80160D8();
    sub_80141B4(&gEndIntroText, 0, 0, 0x301);
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

NAKED
void PromptNewQuestion(void)
{
    asm_unified(
	"\tpush {lr}\n"
	"\tsub sp, 0x14\n"
	"\tldr r1, _0803CC38\n"
	"\tldr r0, _0803CC3C\n"
	"\tldr r0, [r0]\n"
	"\tldr r0, [r0, 0x3C]\n"
	"\tlsls r0, 2\n"
	"\tadds r0, r1\n"
	"\tldr r1, [r0]\n"
	"\tldr r0, [r1]\n"
	"\tldr r3, [r1, 0x4]\n"
	"\tmovs r2, 0\n"
	"\tstr r2, [sp]\n"
	"\tmovs r1, 0x3\n"
	"\tstr r1, [sp, 0x4]\n"
	"\tstr r2, [sp, 0x8]\n"
	"\tstr r2, [sp, 0xC]\n"
	"\tadds r1, 0xFE\n"
	"\tstr r1, [sp, 0x10]\n"
	"\tmovs r1, 0\n"
	"\tbl sub_8014248\n"
	"\tadd sp, 0x14\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0803CC38: .4byte gPersonalityQuestionPointerTable\n"
"_0803CC3C: .4byte gUnknown_203B400"
    );
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
  struct stack_PartnerSprite stackArray;

  starterID = gUnknown_203B400->StarterID;
  sub_8006518(&stackArray);
  stackArray.data = gUnknown_80F4244;
  ResetUnusedInputStruct();
  sub_800641C(&stackArray, 1, 0);
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

#ifdef NONMATCHING
void CreatePartnerSelectionMenu(s16 starterID)
{
    s32 starterID_s32;
    starterID_s32 = starterID; // force an asr shift.. does lsr without it

    sub_803CEAC(); // creates 203B404
    gUnknown_203B404->StarterID = starterID_s32;
    gUnknown_203B404->unk4C = 0;
    gUnknown_203B404->unk50 = &gUnknown_203B404->unk54;

    gUnknown_203B404->unk54[0] = gUnknown_80F4290;
    gUnknown_203B404->unk54[1] = gUnknown_80F42A8;
    gUnknown_203B404->unk54[2] = gUnknown_80F4278;
    gUnknown_203B404->unk54[3] = gUnknown_80F4278;

    // TODO this is the problem area
    //gUnknown_203B404->unk50[5] = (u32 *) &gUnknown_203B404->sub; // so weird but think they store the substruct

    gUnknown_203B404->sub.unkb4 = 1;
    gUnknown_203B404->sub.unkb5 = 0;
    gUnknown_203B404->sub.unkb6 = 6;
    gUnknown_203B404->sub.unkb7 = 0;
    ResetUnusedInputStruct();
    sub_800641C(gUnknown_203B404->unk54, 1, 1);
    sub_8013818(&gUnknown_203B404->unk18, GetValidPartners(), 0xA, gUnknown_203B404->unk4C);
    RedrawPartnerSelectionMenu();
    PersonalityTest_DisplayPartnerSprite();
}
#else
NAKED
void CreatePartnerSelectionMenu(s16 starterID)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tadds r4, r0, 0\n"
	"\tlsls r4, 16\n"
	"\tasrs r4, 16\n"
	"\tbl sub_803CEAC\n"
	"\tldr r5, _0803CDB0\n"
	"\tldr r0, [r5]\n"
	"\tmovs r3, 0\n"
	"\tmovs r1, 0\n"
	"\tstrh r4, [r0]\n"
	"\tstr r1, [r0, 0x4C]\n"
	"\tadds r1, r0, 0\n"
	"\tadds r1, 0x54\n"
	"\tstr r1, [r0, 0x50]\n"
	"\tldr r0, _0803CDB4\n"
	"\tldm r0!, {r2,r4,r6}\n"
	"\tstm r1!, {r2,r4,r6}\n"
	"\tldm r0!, {r2,r4,r7}\n"
	"\tstm r1!, {r2,r4,r7}\n"
	"\tldr r1, [r5]\n"
	"\tadds r1, 0x6C\n"
	"\tldr r0, _0803CDB8\n"
	"\tldm r0!, {r2,r6,r7}\n"
	"\tstm r1!, {r2,r6,r7}\n"
	"\tldm r0!, {r4,r6,r7}\n"
	"\tstm r1!, {r4,r6,r7}\n"
	"\tldr r1, [r5]\n"
	"\tldr r2, _0803CDBC\n"
	"\tadds r1, 0x84\n"
	"\tadds r0, r2, 0\n"
	"\tldm r0!, {r4,r6,r7}\n"
	"\tstm r1!, {r4,r6,r7}\n"
	"\tldm r0!, {r4,r6,r7}\n"
	"\tstm r1!, {r4,r6,r7}\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0x9C\n"
	"\tldm r2!, {r1,r4,r6}\n"
	"\tstm r0!, {r1,r4,r6}\n"
	"\tldm r2!, {r1,r4,r7}\n"
	"\tstm r0!, {r1,r4,r7}\n"
	"\tldr r0, [r5]\n"
	"\tldr r1, [r0, 0x50]\n"
	"\tadds r0, 0xB4\n"
	"\tstr r0, [r1, 0x14]\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0xB5\n"
	"\tstrb r3, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0xB6\n"
	"\tmovs r1, 0x6\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0xB7\n"
	"\tstrb r3, [r0]\n"
	"\tbl ResetUnusedInputStruct\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, 0x54\n"
	"\tmovs r1, 0x1\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_800641C\n"
	"\tldr r4, [r5]\n"
	"\tadds r4, 0x18\n"
	"\tbl GetValidPartners\n"
	"\tadds r1, r0, 0\n"
	"\tldr r0, [r5]\n"
	"\tldr r3, [r0, 0x4C]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r2, 0xA\n"
	"\tbl sub_8013818\n"
	"\tbl RedrawPartnerSelectionMenu\n"
	"\tbl PersonalityTest_DisplayPartnerSprite\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0803CDB0: .4byte gUnknown_203B404\n"
"_0803CDB4: .4byte gUnknown_80F4290\n"
"_0803CDB8: .4byte gUnknown_80F42A8\n"
"_0803CDBC: .4byte gUnknown_80F4278");
}

#endif

u16 HandlePartnerSelectionInput(void)
{
  s32 sVar1;

  sVar1 = gUnknown_203B404->currPartnerSelection;
  gUnknown_203B404->unk16 = 0;
  if (GetKeyPress(&gUnknown_203B404->unk18) == A_BUTTON) {
    sub_80119D4(0);
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
      return 0xfffe;
    }
    else {
      return 0xffff;
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
