#include "global.h"
#include "constants/species.h"
#include "gUnknown_203B418.h"
#include "code_8041D5C.h"

extern struct unkDungeon_8041D5C *sub_8085480(void);
extern struct unkDungeon_8041D5C *sub_8085680(u32);
extern char gUnknown_202E038[0x50];
extern struct unkStruct_203B418 *gUnknown_203B418;

extern u32 gUnknown_8106778;
extern u32 gUnknown_81067BC;
extern u32 gUnknown_81067E0;
extern u32 gUnknown_8106834;
extern u32 gUnknown_810688C;
extern u32 gUnknown_81068D0;
extern u32 gUnknown_8106918;
extern u32 gUnknown_8106934;
extern u32 gUnknown_8106720;

extern void sub_8086A3C(struct unkDungeon_8041D5C *r0);
extern void CopySpeciesNametoBuffer(char *r0, u32 r1);
extern void sub_8083E88(u32);
extern void sub_80854D4(void);
extern void sub_80855E4(void *);
extern void sub_8085930(u32);
extern void sub_8068FE0(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_8085860(s16 r0, u32 r1);

extern void sub_803E708(u32, u32);
extern void sub_8052910(u32 *r0);
extern void sub_8086448(void);
extern void sub_8086598(void);
extern void sub_808696C();
extern void sub_80862BC(struct unkDungeon_8041D5C *);
extern void sub_8083E38(u32);
extern void sub_806CDD4(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_80869E4(struct unkDungeon_8041D5C *, u32, u32, u32);
extern void sub_806CE68(struct unkDungeon_8041D5C *, u32);
extern void sub_804539C(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_803E46C(u32);
extern void sub_8042B0C(struct unkDungeon_8041D5C *);
extern void sub_8085918(struct unkDungeon_8041D5C *, u32);

extern void sub_806CE68(struct unkDungeon_8041D5C *r0, u32);
extern void sub_8052910(u32 *);
extern void sub_803E708(u32, u32);


extern u8 sub_80450E0();

void sub_808C9B0();

void sub_808C8E0(struct unkDungeon_8041D5C *param_1)
{
  s32 iVar1;

  sub_8083E38(0x1a5);
  sub_806CDD4(param_1, 0, 0);
  for(iVar1 = 0; iVar1 < 16; iVar1++){
    param_1->unk70->unk174 = iVar1 << 8;
    sub_803E46C(0x46);
  }
  for(iVar1 = 16; iVar1 < 200; iVar1 += 4){
    param_1->unk70->unk174 = iVar1 << 8;
    sub_803E46C(0x46);
  }
  sub_8086A3C(param_1);
}

void sub_808C938(void)
{
    sub_80855E4(sub_808C9B0);
}

void sub_808C948(s32 param_1, u8 param_2)
{
  bool8 flag;
  s32 iVar3;

  if (param_2 == 0x37) {
    flag = FALSE;
    for(iVar3 = 0; iVar3 < 0x10; iVar3++){
      if ((gUnknown_203B418->unk1358C[iVar3] != param_1) && (sub_80450E0() != 0)) {
        flag = TRUE;
        break;
      }
    }
    if (!flag) {
      gUnknown_203B418->unk2 = 1;
    }
  }
}

void sub_808C998(void)
{
    // Defeat the opposing team to win
    // Be careful, your opponents are tough
    sub_8052910(&gUnknown_8106720);
    sub_803E708(0xA, 0x46);
}

void sub_808C9B0(struct unkDungeon_8041D5C *param_1)
{
    param_1->unk70->unk46 = 4;
    sub_806CE68(param_1, 4);
}

void sub_808C9C4(void)
{
    struct unkDungeon_8041D5C *temp;
    struct unkDungeon_8041D5C *temp_2;

    temp = sub_8085480();
    temp_2 = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    sub_8085918(temp_2, 0);
    sub_8085860(temp->unk4, temp->unk6 - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

// Medicham Rescue Dialogue?
void MedichamResuceDialogue(void)
{
    struct unkDungeon_8041D5C *temp;
    s32 counter;

    temp = sub_8085680(7);
    sub_808696C();
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    sub_8052910(&gUnknown_8106778);
    sub_803E708(0xA, 0x46);
    sub_80869E4(temp, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    sub_8052910(&gUnknown_81067BC);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(temp);
    sub_803E708(0x20, 0x46);
    sub_80869E4(temp, 4, 2, 0);
    sub_8052910(&gUnknown_81067E0);
    sub_803E708(0xA, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_806CE68(temp, 0);
    sub_803E708(0x4, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    // Yes Yes
    // I am so lucky
    //
    // There appears to be no one here
    sub_8052910(&gUnknown_8106834);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(temp, 0, 0);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(temp, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(temp, 0);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(temp);
    sub_8068FE0(temp, 0x87 << 2, 0);
    gUnknown_203B418->unk4 = 1;
    gUnknown_203B418->unk11 = 4;
}

void sub_808CB5C(void)
{
    struct unkDungeon_8041D5C *temp;
    struct unkDungeon_8041D5C *temp_2;

    temp = sub_8085480();
    temp_2 = sub_8085680(7);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(4);
    sub_8068FE0(temp_2, 0x87 << 2, 0);
    sub_8085860(temp->unk4, temp->unk6);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MEDICHAM);
}

void nullsub_101(void)
{
}

void sub_808CBB0(void)
{
    struct unkDungeon_8041D5C *temp;
    struct unkDungeon_8041D5C *temp_2;

    temp = sub_8085480();
    temp_2 = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    sub_8085918(temp_2, 0);
    sub_8085860(temp->unk4, temp->unk6 - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

// Smeargle Rescue dialogue scene
void SmeargleRescueDialogue(void)
{
    struct unkDungeon_8041D5C *temp;
    s32 counter;

    temp = sub_8085680(0x1F);
    sub_808696C();
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    sub_8052910(&gUnknown_810688C);
    sub_803E708(0xA, 0x46);
    sub_80869E4(temp, 4, 2, 4);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    sub_8052910(&gUnknown_81068D0);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    sub_80862BC(temp);
    sub_803E708(0x20, 0x46);
    sub_80869E4(temp, 4, 2, 0);
    // Oh! You are?
    sub_8052910(&gUnknown_8106918);
    sub_803E708(0xA, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    sub_806CE68(temp, 0);
    sub_803E708(0x4, 0x46);
    sub_8083E38(0x1c7);
    sub_806CDD4(temp, 0xA, 0);
    sub_803E708(0x14, 0x46);
    // Did you maybe come to rescue me?
    // Am I glad to see you
    sub_8052910(&gUnknown_8106934);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(temp, 0, 0);
    for(counter = 0x17; counter >= 0; counter--)
    {
        sub_804539C(temp, 0, 0x80 << 1);
        sub_803E46C(0x46);
    }
    sub_806CE68(temp, 0);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(temp);
    sub_8068FE0(temp, 0x87 << 2, 0);
    gUnknown_203B418->unk4 = 1;
    gUnknown_203B418->unk11 = 4;

}

void sub_808CD44(void)
{
    struct unkDungeon_8041D5C *temp;
    struct unkDungeon_8041D5C *temp_2;

    temp = sub_8085480();
    temp_2 = sub_8085680(0x1F);
    sub_8083E88(0x72);
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    sub_8068FE0(temp_2, 0x87 << 2, 0);
    sub_8085860(temp->unk4, temp->unk6 - 3);
    CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SMEARGLE);
}

