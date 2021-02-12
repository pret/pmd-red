#include "global.h"
#include "personality_test.h"
#include "random.h"


struct UnkSaveStruct1
{
    /* 0x0 */ u32 unk0;
    /* 0x4 */ u32 unk4;
    /* 0x8 */ u16 unk8;
    /* 0xA */ u8 unkA;
    /* 0xB */ u8 playerGender;
};
extern struct UnkSaveStruct1 *gUnknown_203B46C;

extern const char gStarterReveal;
extern const char gPartnerPrompt;
extern const char gPartnerNickPrompt;
extern const char gUnknown_80F2898;

extern void sub_80141B4(const char *r0, u32 r1, u32 r2, u16 r3);
extern void sub_803CC80(void);
extern u32 sub_80144A4(s32 *);
extern void sub_803CD08(s16);

extern s16 sub_803CDC0(void);
extern void sub_803CE6C(void);
extern u32 sub_808D994(u32);
extern void sub_80922F4(s32 *r0, u32);
extern void sub_801602C(u32, s32 *r0);

extern u32 sub_8016080(void);
extern void sub_80160D8(void);
extern void sub_8099690(u32);

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
    sub_803CC80();
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

void sub_803CAF4(void)
{
    sub_803CD08(gUnknown_203B400->StarterID);
    gUnknown_203B400->TestState = 10;
}

void PromptForPartnerNickname(void)
{
  u16 sVar1;

  sVar1 = sub_803CDC0();
  if (sVar1 != 0xffff)
  {
      if(sVar1 != 0xfffe) {
        sub_803CE6C();
        gUnknown_203B400->unkA = sVar1;
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
  u32 uVar1;
  s32 *iVar2;

  iVar2 = &gUnknown_203B400->unk20;
  uVar1 = sub_808D994(gUnknown_203B400->unkA);
  sub_80922F4(iVar2,uVar1);
  sub_801602C(3, &gUnknown_203B400->unk20);
  gUnknown_203B400->TestState = 13;
}

void sub_803CBB0(void)
{
  if (sub_8016080() != 0) {
    sub_80160D8();
    sub_80141B4(&gUnknown_80F2898, 0, 0, 0x301);
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

