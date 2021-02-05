#include "global.h"

#define NUM_PERSONALITIES 13
#define NUM_QUIZ_QUESTIONS 55

struct PersonalityStruct_203B400
{
    u32 unk0;
    u32 unk4;
    u8 padding[0x34 - 8];
    /* 0x34 */ u32 TestState;
    /* 0x38 */ u32 QuestionCounter;
    /* 0x3C */ u32 currQuestionIndex;
    u8 unk40;
    u8 padding2[3];
    /* 0x44 */ u32 NatureTotals[13];
    /* 0x78 */ u8 QuestionTracker[NUM_QUIZ_QUESTIONS];
    u32 unkb0;
    u32 unkb4;
    u32 unkb8;
    u32 unkbc;
};

extern struct PersonalityStruct_203B400 *gUnknown_203B400;
extern void* MemoryAlloc(u32, u32);
extern void MemoryFree(void *);
extern void sub_801317C(u32 *);
extern void sub_8099690(u32);
extern void sub_8001024(u32 *);
extern s32 Random(void);
extern s32 sub_8094E4C(void);
extern void sub_8011C40(s32);
extern void sub_8094D28(s32);
extern void sub_8001044(u32 *);

extern void sub_803C870(void);
extern void sub_803C908(void);
extern void sub_803C920(void);
extern void sub_803C98C(void);
extern void sub_803C9D8(void);
extern void sub_803CA54(void);
extern void sub_803CA8C(void);
extern void sub_803CAAC(void);
extern void sub_803CAD4(void);
extern void sub_803CAF4(void);
extern void sub_803CB14(void);
extern void sub_803CB5C(void);
extern void sub_803CB7C(void);
extern void sub_803CBB0(void);
extern void sub_803CBE4(void);
void InitializeTestStats(void);

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
  gUnknown_203B400->unk0 = 0;
  gUnknown_203B400->TestState = 0;
  gUnknown_203B400->QuestionCounter = 0;
  for(counter = 0; counter < NUM_PERSONALITIES; counter++){
    gUnknown_203B400->NatureTotals[counter] = 0;
  }
  gUnknown_203B400->currQuestionIndex = 0;
  for(counter = 0; counter < NUM_QUIZ_QUESTIONS; counter++){
    gUnknown_203B400->QuestionTracker[counter] = 0;
  }
  gUnknown_203B400->unk40 = 0;
  gUnknown_203B400->unkb0 = 0;
}

#ifdef NONMATCHING
u8 HandleTestTrackerState(void)
{
  s32 counter;

  s32 iVar1;

  gUnknown_203B400->unk0++;
  switch(gUnknown_203B400->TestState)
  {
    case 0:
        sub_803C870();
        break;
    case 1:
        sub_803C908();
        break;
    case 2:
        sub_803C920();
        break;
    case 3:
        sub_803C98C();
        break;
    case 4:
        sub_803C9D8();
        break;
    case 5:
        sub_803CA54();
        break;
    case 6:
        sub_803CA8C();
        break;
    case 7:
        sub_803CAAC();
        break;
    case 8:
        sub_803CAD4();
        break;
    case 9:
        sub_803CAF4();
        break;
    case 10:
        sub_803CB14();
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
        iVar1 = Random() * gUnknown_203B400->unk0;
        sub_8094D28(Random());

        // TODO fix this math..
        for(counter = 0; counter < 13; counter++){
            iVar1 *= (gUnknown_203B400->NatureTotals[counter] + 3);
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

#else
NAKED
u8 HandleTestTrackerState(void)
{
        asm_unified(
        "\tpush {r4,r5,lr}\n"
        "\tldr r0, _0803C750\n"
        "\tldr r1, [r0]\n"
        "\tldr r0, [r1]\n"
        "\tadds r0, 0x1\n"
        "\tstr r0, [r1]\n"
        "\tldr r0, [r1, 0x34]\n"
        "\tcmp r0, 0xF\n"
        "\tbls _0803C744\n"
        "\tb _0803C848\n"
    "_0803C744:\n"
        "\tlsls r0, 2\n"
        "\tldr r1, _0803C754\n"
        "\tadds r0, r1\n"
        "\tldr r0, [r0]\n"
        "\tmov pc, r0\n"
        "\t.align 2, 0\n"
    "_0803C750: .4byte gUnknown_203B400\n"
    "_0803C754: .4byte _0803C758\n"
        "\t.align 2, 0\n"
    "_0803C758:\n"
        "\t.4byte _0803C798\n"
        "\t.4byte _0803C79E\n"
        "\t.4byte _0803C7A4\n"
        "\t.4byte _0803C7AA\n"
        "\t.4byte _0803C7B0\n"
        "\t.4byte _0803C7B6\n"
        "\t.4byte _0803C7BC\n"
        "\t.4byte _0803C7C2\n"
        "\t.4byte _0803C7C8\n"
        "\t.4byte _0803C7CE\n"
        "\t.4byte _0803C7D4\n"
        "\t.4byte _0803C7DA\n"
        "\t.4byte _0803C7E0\n"
        "\t.4byte _0803C7E6\n"
        "\t.4byte _0803C7EC\n"
        "\t.4byte _0803C7F2\n"
    "_0803C798:\n"
        "\tbl sub_803C870\n"
        "\tb _0803C848\n"
    "_0803C79E:\n"
        "\tbl sub_803C908\n"
        "\tb _0803C848\n"
    "_0803C7A4:\n"
        "\tbl sub_803C920\n"
        "\tb _0803C848\n"
    "_0803C7AA:\n"
        "\tbl sub_803C98C\n"
        "\tb _0803C848\n"
    "_0803C7B0:\n"
        "\tbl sub_803C9D8\n"
        "\tb _0803C848\n"
    "_0803C7B6:\n"
        "\tbl sub_803CA54\n"
        "\tb _0803C848\n"
    "_0803C7BC:\n"
        "\tbl sub_803CA8C\n"
        "\tb _0803C848\n"
    "_0803C7C2:\n"
        "\tbl sub_803CAAC\n"
        "\tb _0803C848\n"
    "_0803C7C8:\n"
        "\tbl sub_803CAD4\n"
        "\tb _0803C848\n"
    "_0803C7CE:\n"
        "\tbl sub_803CAF4\n"
        "\tb _0803C848\n"
    "_0803C7D4:\n"
        "\tbl sub_803CB14\n"
        "\tb _0803C848\n"
    "_0803C7DA:\n"
        "\tbl sub_803CB5C\n"
        "\tb _0803C848\n"
    "_0803C7E0:\n"
        "\tbl sub_803CB7C\n"
        "\tb _0803C848\n"
    "_0803C7E6:\n"
        "\tbl sub_803CBB0\n"
        "\tb _0803C848\n"
    "_0803C7EC:\n"
        "\tbl sub_803CBE4\n"
        "\tb _0803C848\n"
    "_0803C7F2:\n"
        "\tbl Random\n"
        "\tldr r4, _0803C844\n"
        "\tldr r1, [r4]\n"
        "\tldr r1, [r1]\n"
        "\tadds r5, r0, 0\n"
        "\tmuls r5, r1\n"
        "\tbl Random\n"
        "\tbl sub_8094D28\n"
        "\tmovs r1, 0\n"
        "\tldr r0, [r4]\n"
        "\tadds r2, r0, 0\n"
        "\tadds r2, 0x44\n"
    "_0803C810:\n"
        "\tldm r2!, {r0}\n"
        "\tadds r0, r1\n"
        "\tadds r0, 0x3\n"
        "\tmuls r5, r0\n"
        "\tadds r1, 0x1\n"
        "\tcmp r1, 0xC\n"
        "\tble _0803C810\n"
        "\tbl sub_8094E4C\n"
        "\tadds r5, r0\n"
        "\tmovs r0, 0x1\n"
        "\tnegs r0, r0\n"
        "\tcmp r5, r0\n"
        "\tbne _0803C838\n"
        "\tadds r4, r5, 0\n"
    "_0803C82E:\n"
        "\tbl sub_8094E4C\n"
        "\tadds r5, r0\n"
        "\tcmp r5, r4\n"
        "\tbeq _0803C82E\n"
    "_0803C838:\n"
        "\tadds r0, r5, 0\n"
        "\tbl sub_8011C40\n"
	"\tmovs r0, 0x3\n"
	"\tb _0803C84A\n"
	"\t.align 2, 0\n"
"_0803C844: .4byte gUnknown_203B400\n"
"_0803C848:\n"
	"\tmovs r0, 0\n"
"_0803C84A:\n"
	"\tpop {r4,r5}\n"
	"\tpop {r1}\n"
	"\tbx r1");
#endif

}

void DeleteTestTracker(void)
{
  sub_8001044(&gUnknown_203B400->unk4);
  MemoryFree(gUnknown_203B400);
  gUnknown_203B400 = NULL;
}
