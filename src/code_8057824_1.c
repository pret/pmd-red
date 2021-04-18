#include "global.h"
#include "gUnknown_203B418.h"
#include "code_8041D5C.h"
#include "constants/species.h"

extern struct unkStruct_203B418 *gUnknown_203B418;

extern u32 gUnknown_202EDC8;
extern u8 gUnknown_202E038[0x50];
extern u8 gAvailablePokemonNames[0x58]; 

extern u32 gUnknown_8105244;
extern u32 gUnknown_810517C;
extern u32 gUnknown_81050B4;
extern u32 gUnknown_81051D0;
extern u32 gUnknown_810510C;
extern u32 gUnknown_8105040;
extern u32 gUnknown_810554C;
extern u32 gUnknown_8105558;
extern u32 gUnknown_81055F4;
extern u32 gUnknown_8105028;
extern u32 gUnknown_8104FD4;
extern u32 gUnknown_8104930;
extern u32 gUnknown_8104980;
extern u32 gUnknown_8104998;
extern u32 gUnknown_8105034;
extern u32 gUnknown_8105438;
extern u32 gUnknown_81054A0;
extern u32 gUnknown_81054E4;
extern u32 gUnknown_810550C;
extern u32 gUnknown_8104F64;
extern u32 gUnknown_8104EFC;
extern u32 gUnknown_8104F30;
extern u32 gUnknown_8104E60;
extern u32 gUnknown_8104CEC;
extern u32 gUnknown_8104D60;
extern u32 gUnknown_8104DDC;
extern u32 gUnknown_8104E0C;
extern u32 gUnknown_8104E54;
extern u32 gUnknown_8104AD4;
extern u32 gUnknown_8104BEC;
extern u32 gUnknown_8104C10;
extern u32 gUnknown_8104C54;
extern u32 gUnknown_8104CB4;
extern u32 gUnknown_8104CE0;
extern u32 gUnknown_8104AC8;
extern u32 gUnknown_81049D4;
extern u32 gUnknown_8104A80;
extern u32 gUnknown_8104A9C;
extern u32 gUnknown_8104784;
extern u32 gUnknown_8104790;
extern u32 gUnknown_81047B0;
extern u32 gUnknown_810484C;
extern u32 gUnknown_8104888;
extern u32 gUnknown_81048C8;
extern u32 gUnknown_8104914;
extern u32 gUnknown_810476C;
extern u32 gUnknown_8104778;
extern u32 gUnknown_81046CC;
extern u32 gUnknown_8104744;
extern u32 gUnknown_81045F8;
extern u32 gUnknown_8104674;
extern u32 gUnknown_81046A0;
extern u32 gUnknown_8104450;
extern u32 gUnknown_81044B4;
extern u32 gUnknown_8104510;
extern u32 gUnknown_810453C;
extern u32 gUnknown_8104570;
extern u32 gUnknown_81045B0;
extern u32 gUnknown_81043DC;
extern u32 gUnknown_8104310;
extern u32 gUnknown_810439C;
extern u32 gUnknown_81043C0;
extern u32 gUnknown_8104240;
extern u32 gUnknown_81042AC;
extern u32 gUnknown_81042B8;
extern u32 gUnknown_8104FC8;
extern u32 gUnknown_8104150;
extern u32 gUnknown_81041AC;
extern u32 gUnknown_81041F8;
extern u32 gUnknown_8104144;
extern u32 gUnknown_8104114;
extern u32 gUnknown_81040CC;
extern u32 gUnknown_8104050;
extern u32 gUnknown_8104044;
extern u32 gUnknown_8104008;
extern u32 gUnknown_8103EA4;
extern u32 gUnknown_8103F0C;
extern u32 gUnknown_8103F4C;
extern u32 gUnknown_8103FCC;
extern u32 gUnknown_8103E34;

extern struct unkDungeon_8041D5C *sub_8085480(void);
extern struct unkDungeon_8041D5C *sub_8085680(u32);
extern void sub_808BBA8(struct unkDungeon_8041D5C * );
extern void CopySpeciesNametoBuffer(char *r0, u32 r1);
extern void sub_80855E4(void *);
extern void sub_8041888(u32);
extern void sub_80861B8(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_8083ED8(u32);
extern void sub_803E708(u32, u32);
extern void sub_8052910(u32 *r0);
extern void sub_8083E88(u32);
extern void sub_808BC20(struct unkDungeon_8041D5C *);

extern void sub_80862BC(struct unkDungeon_8041D5C *);
extern void sub_8086448();
extern void sub_808696C();
extern u32 sub_80861F8(u32, struct unkDungeon_8041D5C *, u32);
extern void sub_8086A70(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_80858AC(u32 *, u32);

extern void sub_8097FA8(u32);
extern void JirachiWish();
extern u8 sub_80860A8(u32);
extern void sub_8040A84();
extern void sub_8086A3C(struct unkDungeon_8041D5C *);
extern u8 HasRecruitedMon(u32);
extern void sub_80854D4();
extern void sub_8085930(u32);
extern void sub_8068FE0(struct unkDungeon_8041D5C *, u32, u32);
extern void sub_8085918(struct unkDungeon_8041D5C *, u32);
extern void sub_8049ED4();
extern void sub_8085860(s16 r0, u32 r1);
extern void sub_806CE68(struct unkDungeon_8041D5C *, u32);

extern void sub_8052D44(u8 *, struct unkDungeon_8041D5C *, u32);
extern void sub_8097FD0(u32);
extern void sub_8045B94(u8 *, struct unkDungeon_8041D5C *, u32);
extern struct unkDungeon_8041D5C *sub_8083600();
extern void sub_80421C0(struct unkDungeon_8041D5C *, u32);
extern void sub_8046D20();
extern void sub_808B1CC(u8);
extern void sub_8090A8C(u8 *, u32, u32);
extern void sub_80464C8(struct unkDungeon_8041D5C *, u32, u8 *);
extern void sub_8098044(u32);
extern void sub_8083E38(u32);
extern void sub_8085C54(u32, u32, u32, u32, u32);
extern void sub_803E46C(u32);
extern void sub_8085EB0();
extern void sub_80866C4(u32 *);
extern void sub_808692C();

extern void sub_8083E58(u32);
extern void sub_80868F4();
extern void sub_8086910();
extern u32 sub_8085EC8(u32, u32, u32, u32 *, u32);
extern void sub_808680C();
extern void sub_808682C();
extern void sub_8086854();
extern void sub_80867F4();
extern void sub_8086838(u32, u32, u32);
extern void sub_80426C8(u32, u32);
extern void sub_807EAA0(u32, u32);

extern void sub_808563C(void *);
extern void sub_808BCE4(void);
extern void sub_808BBB8(struct unkDungeon_8041D5C *param_1);
extern u8 sub_8098100(u32);
extern void sub_8086794();

void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(struct unkDungeon_8041D5C * param_1);
void SuicuneScreenFlash();
void sub_808A904(struct unkDungeon_8041D5C * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void sub_808B2B0(struct unkDungeon_8041D5C *r0);
void sub_808B2C4(struct unkDungeon_8041D5C *r0);
void sub_808B2D4(struct unkDungeon_8041D5C *r0);
void sub_808B2E4(struct unkDungeon_8041D5C *r0);
void sub_808B50C(void);
void sub_8089B64(struct unkDungeon_8041D5C *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(struct unkDungeon_8041D5C *r0);
void sub_8089908(struct unkDungeon_8041D5C *r0);
void sub_8089620(struct unkDungeon_8041D5C *param_1);
void RaquazaScreenFlash(void);

extern void sub_8083F14();
extern u8 sub_80450E0(struct unkDungeon_8041D5C *);
extern u8 sub_8086AE4(u32);

extern u32 gUnknown_8103D8C;
extern u32 gUnknown_8103D98;
extern u32 gUnknown_8103DD8;
extern u32 gUnknown_8103E28;
extern u32 gUnknown_8103BD8;
extern u32 gUnknown_8103C00;
extern u32 gUnknown_8103C3C;
extern u32 gUnknown_8103C74;
extern u32 gUnknown_8103CC4;
extern u32 gUnknown_8103D0C;
extern u32 gUnknown_8103D50;
extern u32 gUnknown_8103B58;
extern u32 gUnknown_8103904;
extern u32 gUnknown_8103938;
extern u32 gUnknown_8103AA4;
extern u32 gUnknown_8103AE4;
extern u32 gUnknown_8103B30;
extern u32 gUnknown_8103690;
extern u32 gUnknown_8103844;
extern u32 gUnknown_8103874;
extern u32 gUnknown_81038A8;
extern u32 gUnknown_81038F8;

extern u32 gUnknown_8103500;
extern u32 gUnknown_810352C;
extern u32 gUnknown_8103578;
extern u32 gUnknown_81035D4;
extern u32 gUnknown_8103618;
extern u32 gUnknown_810367C;
extern u32 gUnknown_8103690;
extern u32 gUnknown_81036C8;
extern u32 gUnknown_81037A0;
extern u32 gUnknown_81037D4;
extern u32 gUnknown_8103820;

extern struct unkDungeon_8041D5C *sub_808548C();
extern void sub_80856E0(struct unkDungeon_8041D5C *, u32);
extern void sub_80869E4(struct unkDungeon_8041D5C *, u32, u32, u32);

void sub_80893B4(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE9000000U) >> 0x18 < 3) && (param_1 == 0xF)) {
    sub_8097FA8(0xF);
    gUnknown_203B418->unk2 = 1;
  }
}

void RaquazaPreFightDialogue(void)
{
  struct unkDungeon_8041D5C *iVar1;
  struct unkDungeon_8041D5C *uVar2;
  struct unkDungeon_8041D5C *uVar3;
  
  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(0xf);
  sub_8086448();
  sub_8052910(&gUnknown_8103500);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_810352C);
  sub_80856E0(uVar2,4);
  sub_808696C(uVar2);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(iVar1,4,2,6);
  sub_8052910(&gUnknown_8103578);
  sub_80869E4(uVar2,4,2,4);
  sub_80869E4(iVar1,4,1,4);
  sub_8052910(&gUnknown_81035D4);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8103618);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_810367C);
  RaquazaScreenFlash();
  sub_8083E38(0x1da);
  sub_8052910(&gUnknown_8103690);
  sub_8089620(uVar3);
  sub_8052910(&gUnknown_81036C8);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_81037A0);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_81037D4);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_8103820);
  sub_8086A70(uVar3,600,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void RaquazaReFightDialogue(void)
{
  struct unkDungeon_8041D5C *iVar1;
  struct unkDungeon_8041D5C *uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xf);
  sub_8086448();
  RaquazaScreenFlash();
  sub_8083E38(0x1da);
  sub_8052910(&gUnknown_8103690);
  sub_803E708(10,0x46);
  sub_8089620(uVar2);
  sub_8052910(&gUnknown_8103844);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_8103874);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_81038A8);
  RaquazaScreenFlash();
  sub_8052910(&gUnknown_81038F8);
  sub_8086A70(uVar2,600,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void RaquazaPostStoryPreFightDialogue(void)
{
  struct unkDungeon_8041D5C *iVar2;
  struct unkDungeon_8041D5C *uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xf);
  sub_8086448();
  if (sub_8086AE4(SPECIES_RAYQUAZA)) {
    sub_80866C4(&gUnknown_8103B58);
  }
  else {
    sub_8083E38(0x1da);
    sub_8052910(&gUnknown_8103904);
    sub_8089620(uVar3);
    sub_8052910(&gUnknown_8103938);
    RaquazaScreenFlash();
    sub_8052910(&gUnknown_8103AA4);
    RaquazaScreenFlash();
    sub_8052910(&gUnknown_8103AE4);
    RaquazaScreenFlash();
    sub_8052910(&gUnknown_8103B30);
    sub_8086A70(uVar3,600,0xb);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void sub_8089620(struct unkDungeon_8041D5C *param_1)
{
  s32 iVar1;
  s32 iVar2;
  
  param_1->unk70->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x600;
  sub_8083E38(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 = iVar1 -= 0x18;
    if (iVar1 < 0x14) {
      iVar1 = 0x14;
    }
    if (iVar2 < 0) break;
    param_1->unk70->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  param_1->unk70->unk174 = 0;
}

void RaquazaScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1 / 2, iVar1, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1 / 2, iVar1, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}


void sub_808970C(void)
{
  struct unkDungeon_8041D5C *iVar1;
  
  iVar1 = sub_8085480();
  sub_8083E88(0x7D);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(iVar1->unk4,iVar1->unk6 + -3);
}

void sub_808974C(void)
{
  struct unkDungeon_8041D5C *iVar1;
  
  iVar1 = sub_8085480();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(iVar1->unk4,iVar1->unk6 + -3);
}

void sub_8089788(struct unkDungeon_8041D5C *param_1, u8 param_2, s32 param_3)
{
  struct unkDungeon_8041D5C *iVar2;
  s32 iVar3;
  u32 unk1;

  unk1 = 0;
  
  if ((((param_3 * 0x1000000) + 0xe6000000U) >> 0x18) < 2) {
    for(iVar3 = 0; iVar3 < 0x10; iVar3++)
    {
      iVar2 = gUnknown_203B418->unk1358C[iVar3];
      if ((sub_80450E0(iVar2) != '\0') && (iVar2 != param_1) && (iVar2->unk70->unkA4 == param_2)) {
        return;
      }
    }
    // WTF is this??
    if(!unk1){
        sub_8097FA8(0x11);
        gUnknown_203B418->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  struct unkDungeon_8041D5C *iVar1;
  
  iVar1 = sub_8085480();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(sub_80862BC);
  sub_803E708(0x20,0x46);
  sub_808692C();
  sub_8052910(&gUnknown_8103BD8);
  // We don't like to brag or 
  // nothing, but
  sub_8052910(&gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  sub_8052910(&gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  sub_8052910(&gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  sub_8052910(&gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  sub_8052910(&gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  sub_8052910(&gUnknown_8103D50);
  sub_803E708(10,0x46);
  sub_80858AC(&iVar1->unkC,0x10);
}



void sub_8089878(void)
{
  struct unkDungeon_8041D5C *iVar1;
  
  iVar1 = sub_8085480();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(sub_80862BC);
  sub_803E708(0x20,0x46);
  sub_808692C();
  sub_8052910(&gUnknown_8103D8C);
  sub_8052910(&gUnknown_8103D98);
  sub_8052910(&gUnknown_8103DD8);
  sub_8052910(&gUnknown_8103E28);
  sub_803E708(10,0x46);
  sub_80858AC(&iVar1->unkC,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

void sub_80898F8(struct unkDungeon_8041D5C *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void sub_8089908(struct unkDungeon_8041D5C *r0)
{
    sub_8085918(r0, 4);
}

void sub_8089914(void)
{
  struct unkDungeon_8041D5C *iVar1;
  struct unkDungeon_8041D5C *uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x11);
  sub_8083F14();
  gUnknown_203B418->unk7 = 1;
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_MEWTWO);
}

void sub_8089978(void)
{
  struct unkDungeon_8041D5C *iVar2;
  struct unkDungeon_8041D5C *uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x11);
  sub_8083F14();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if(HasRecruitedMon(SPECIES_MEWTWO)){
    sub_8083E88(0x23);
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    gUnknown_203B418->unk7 = 1;
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->unk4,iVar2->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_MEWTWO);
}

void sub_8089A00(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE3000000U) >> 0x18 < 3) && (param_1 == 0x11)) {
    sub_8097FA8(0x13);
    gUnknown_203B418->unk2 = 1;
  }
}

void MewtwoPreFightDialogue(void)
{
  struct unkDungeon_8041D5C *iVar1;
  struct unkDungeon_8041D5C *uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x11);
  sub_8086448();
  sub_8052910(&gUnknown_8103EA4);
  sub_803E708(10,0x46);
  sub_8083E88(0x23);
  sub_8086794();
  sub_803E708(0x1e,0x46);
  sub_8089B64(uVar2);
  sub_803E708(0x3c,0x46);
  sub_8052910(&gUnknown_8103F0C);
  sub_8052910(&gUnknown_8103F4C);
  sub_803E708(10,0x46);
  MewtwoScreenFlash();
  sub_8052910(&gUnknown_8103FCC);
  MewtwoScreenFlash();
  sub_8052910(&gUnknown_8104008);
  sub_803E708(10,0x46);
  sub_8086A70(uVar2,900,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void MewtwoPreFightDialogue1(void)
{
  struct unkDungeon_8041D5C *iVar2;
  struct unkDungeon_8041D5C *uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x11);
  sub_8086448();
  if(HasRecruitedMon(SPECIES_MEWTWO)) {
    sub_80866C4(&gUnknown_8104144);
  }
  else {
    sub_8052910(&gUnknown_8104044);
    sub_8083E88(0x23);
    sub_8086794();
    sub_8089B64(uVar3);
    sub_803E708(0x3c,0x46);
    sub_8052910(&gUnknown_8104050);
    MewtwoScreenFlash();
    sub_8052910(&gUnknown_81040CC);
    MewtwoScreenFlash();
    sub_8052910(&gUnknown_8104114);
    sub_8086A70(uVar3,900,0x20);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void sub_8089B64(struct unkDungeon_8041D5C *param_1)
{
  s32 iVar1;
  s32 iVar2;
  
  param_1->unk70->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x400;
  sub_8083E38(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 = iVar1 -= 11;
    if (iVar1 < 0x1e) {
      iVar1 = 0x1e;
    }
    if (iVar2 < 0) break;
    param_1->unk70->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  param_1->unk70->unk174 = 0;
}

void MewtwoScreenFlash(void)
{
  int iVar1;
  
  sub_8083E38(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  { 
    sub_8085C54(iVar1,iVar1,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8089C44(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x12);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ENTEI);
}


void sub_8089C90(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x12);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  if (HasRecruitedMon(SPECIES_ENTEI)) {
      sub_8068FE0(uVar3,0x21c,0);
  }
  else {
      sub_8085918(uVar3,0);
  }
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ENTEI);
}


void sub_8089CFC(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xE0000000U) >> 0x18 < 3) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gUnknown_203B418->unk2 = 1;
  }
}


void EnteiPreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x12);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_8104150);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81041AC);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81041F8);
  sub_803E708(10,70);
  sub_8086A70(uVar2,600,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void EnteiPreFightDialogue1(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x12);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_8104240);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81042AC);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81042B8);
  sub_803E708(10,70);
  sub_8086A70(uVar2,600,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void EnteiPreFightDialogue2(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x12);
  if (HasRecruitedMon(SPECIES_ENTEI)) {
    sub_80866C4(&gUnknown_81043DC);
  }
  else {
    EnteiScreenFlash();
    sub_8052910(&gUnknown_8104310);
    EnteiScreenFlash();
    sub_8052910(&gUnknown_810439C);
    EnteiScreenFlash();
    sub_8052910(&gUnknown_81043C0);
    sub_803E708(10,70);
    sub_8086A70(uVar3,600,0xb);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1, 0, 0, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_8089EFC(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}


void sub_8089F44(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}


void sub_8089F8C(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  if (HasRecruitedMon(SPECIES_RAIKOU)) {
      sub_8068FE0(uVar3,0x21c,0);
  }
  else {
      sub_8085918(uVar3,0);
  }
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}

void sub_8089FF0(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xdD000000U) >> 0x18 < 3) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gUnknown_203B418->unk2 = 1;
  }
}


void RaikouPreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x13);
  sub_8052910(&gUnknown_8104450);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81044B4);
  gUnknown_203B418->unkE265 = 4;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  sub_8052910(&gUnknown_8104510);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_810453C);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_8104570);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81045B0);
  sub_803E708(10,70);
  sub_8086A70(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void RaikouPreFightDialogue1(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  gUnknown_203B418->unkE265 = 4;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81045F8);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_8104674);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81046A0);
  sub_803E708(10,70);
  sub_8086A70(uVar3,0x28a,0xb);
  sub_80858AC(&iVar2->unkC,0x10);
}

void RaikouPreFightDialogue2(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  if (HasRecruitedMon(SPECIES_RAIKOU)) {
    sub_80866C4(&gUnknown_8104778);
  }
  else {
    gUnknown_203B418->unkE265 = 4;
    sub_807EAA0(0,1);
    sub_8052910(&gUnknown_81046CC);
    RaikouScreenFlash();
    sub_8052910(&gUnknown_8104744);
    RaikouScreenFlash();
    sub_8052910(&gUnknown_810476C);
    sub_803E708(10,70);
    sub_8086A70(uVar3,0x28a,0xb);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A264(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A2C0(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar2,0);
  sub_8085860(iVar1->unk4,iVar1->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A308(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x14);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  if (HasRecruitedMon(SPECIES_SUICUNE)) {
     sub_8068FE0(uVar3,0x21c,0);
  }
  else {
     sub_8085918(uVar3,0);
  }
  sub_8085860(iVar2->unk4,iVar2->unk6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A36C(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xda000000U) >> 0x18 < 3) && (param_1 == 0x14)) {
    sub_8097FA8(0x19);
    gUnknown_203B418->unk2 = 1;
  }
}

void SuicunePreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8086448();
  sub_8052910(&gUnknown_8104784);
  sub_803E708(10,70);
  sub_8052910(&gUnknown_8104790);
  sub_803E708(10,70);
  sub_80426C8(1,2);
  sub_803E708(0x3c,70);
  sub_8052910(&gUnknown_81047B0);
  sub_803E708(10,70);
  sub_808A528(uVar2);
  sub_8052910(&gUnknown_810484C);
  sub_8052910(&gUnknown_8104888);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_81048C8);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_8104914);
  sub_803E708(10,70);
  sub_8086A70(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void SuicunePreFightDialogue1(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8052910(&gUnknown_8104930);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_8104980);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_8104998);
  sub_803E708(10,70);
  sub_8086A70(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void SuicunePreFightDialogue2(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x14);
  if (HasRecruitedMon(SPECIES_SUICUNE)) {
    sub_80866C4(&gUnknown_8104AC8);
  }
  else {
    sub_8052910(&gUnknown_81049D4);
    SuicuneScreenFlash();
    sub_8052910(&gUnknown_8104A80);
    SuicuneScreenFlash();
    sub_8052910(&gUnknown_8104A9C);
    sub_803E708(10,70);
    sub_8086A70(uVar3,0x28a,0xb);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void sub_808A528(struct unkDungeon_8041D5C * param_1)
{
  s32 iVar1;
  s32 iVar2;
  
  param_1->unk70->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  sub_8083E38(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->unk70->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->unk70->unk174 = 0;
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1ee);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A608(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x15);
  sub_8083E88(0x1c);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->unk4,iVar1->unk6 + -6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_HO_OH);
}

void sub_808A668(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x15);
  sub_8083E88(0x1c);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(4);
  if (HasRecruitedMon(SPECIES_HO_OH)) {
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->unk4,iVar2->unk6 - 6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_HO_OH);
}

void sub_808A6E8(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd7000000U) >> 0x18 < 2) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gUnknown_203B418->unk2 = 1;
  }
}


void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  int local_14[2];

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x15);
  local_14[0] = iVar1->unkC;
  local_14[1] = iVar1->unk10 + -0x1000;
  sub_80858AC(local_14,0x88);
  sub_803E708(0x40,70);
  sub_8052910(&gUnknown_8104AD4);
  sub_803E708(10,70);
  HoOhScreenFlash();
  sub_8052910(&gUnknown_8104BEC);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  sub_8083E38(0x1c5);
  sub_803E708(0xfa,70);
  sub_808A904(uVar2);
  sub_8083E58(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_8085930(4);
  sub_8052910(&gUnknown_8104C10);
  sub_8052910(&gUnknown_8104C54);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  sub_8052910(&gUnknown_8104CB4);
  HoOhScreenFlash();
  sub_8052910(&gUnknown_8104CE0);
  sub_803E708(10,70);
  sub_8086A70(uVar2,800,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void HoOhPreFightDialogue1(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  u32 local_14[2];

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x15);

  local_14[0] = iVar2->unkC;
  local_14[1] = iVar2->unk10 + -0x1000;
  sub_80858AC(local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(SPECIES_HO_OH)) {
    sub_80866C4(&gUnknown_8104E54);
  }
  else {
    sub_8052910(&gUnknown_8104CEC);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    sub_808A904(uVar3);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(4);
    sub_8052910(&gUnknown_8104D60);
    HoOhScreenFlash();
    sub_8052910(&gUnknown_8104DDC);
    HoOhScreenFlash();
    sub_8052910(&gUnknown_8104E0C);
    sub_803E708(10,70);
    sub_8086A70(uVar3,800,0x20);
    sub_80858AC(&iVar2->unkC,0x10);
  }
}

void sub_808A904(struct unkDungeon_8041D5C * param_1)
{
  s32 iVar1;
  s32 iVar2;
  
  param_1->unk70->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  sub_8083E38(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->unk70->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->unk70->unk174 = 0;
}

void HoOhScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808A9E4(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,4);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 4);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AA3C(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,4);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AA94(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AAF0(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd5000000U) >> 0x18 < 3) && (param_1 == 0x16)) {
    sub_8097FA8(0x1c);
    gUnknown_203B418->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * iVar2;
  u32 local_18[3];

  iVar1 = sub_8085480();
  iVar2 = sub_8085680(0x16);

  local_18[0] = iVar2->unkC;
  local_18[1] = iVar2->unk10 + (0x80 << 6);
  local_18[2] = 0x7000fc;
  sub_8085EC8(0x1bd,0,0,&local_18[2],1);

  sub_803E708(0x1e,70);
  sub_8086448();
  sub_80858AC(local_18,0x18);
  sub_803E708(2,70);
  sub_80862BC(iVar2);
  sub_803E708(0x20,70);
  sub_808692C();
  sub_8052910(&gUnknown_8104E60);
  LatiosScreenFlash();
  sub_8052910(&gUnknown_8104EFC);
  LatiosScreenFlash();
  sub_8052910(&gUnknown_8104F30);
  sub_803E708(10,70);
  sub_8086A70(iVar2,600,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void LatiosReFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8086448();
  sub_808692C();
  sub_8052910(&gUnknown_8104F64);
  LatiosScreenFlash();
  sub_8052910(&gUnknown_8104EFC);
  LatiosScreenFlash();
  sub_8052910(&gUnknown_8104F30);
  sub_803E708(10,70);
  sub_8086A70(uVar2,600,0xb);
  sub_80858AC(&iVar1->unkC,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(&gUnknown_8104FC8);
}

void LatiosScreenFlash(void)
{
  s32 iVar1;
  
  sub_8083E38(0x1ee);
  gUnknown_202EDC8 = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1,1,1);
    sub_803E46C(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

void sub_808ACC0(void)
{
  struct unkDungeon_8041D5C * uVar2;

  if (HasRecruitedMon(SPECIES_REGIROCK)) {
    uVar2 = sub_8085680(0x17);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(0x79);
  }
  else {
    if (sub_80860A8(0x79) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(0x7a) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
      } 
      else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(sub_808B2B0);
        CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_REGIROCK);
     }
    }
  }
}

void sub_808AD48(void)
{
  struct unkDungeon_8041D5C * uVar2;

  if (HasRecruitedMon(SPECIES_REGICE)) {
    uVar2 = sub_8085680(0x18);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(0x77);
  }
  else {
    if (sub_80860A8(0x77) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(0x7a) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
      } 
      else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(sub_808B2B0);
        CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_REGICE);
     }
    }
  }
}

void sub_808ADCC(void)
{

  struct unkDungeon_8041D5C * uVar2;

  if (HasRecruitedMon(SPECIES_REGISTEEL)) {
    uVar2 = sub_8085680(0x19);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(0x78);
  }
  else {
    if (sub_80860A8(0x78) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(0x7a) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
      } 
      else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(sub_808B2B0);
        CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_REGISTEEL);
     }
    }
  }
}

void sub_808AE54(char param_1,char param_2,u32 param_3)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack24 [4];
  u8 auStack20 [4];


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      sub_8090A8C(auStack20,0x79,0);
      sub_80464C8(sub_8083600(),param_3,auStack20);
      sub_8083E88(0x72);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      sub_8052910(&gUnknown_8105040);
    }
  }
}


void sub_808AEC8(char param_1,char param_2,u32 param_3)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack24 [4];
  u8 auStack20 [4];


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      sub_8090A8C(auStack20,0x77,0);
      sub_80464C8(sub_8083600(),param_3,auStack20);
      sub_8083E88(0x72);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      sub_8052910(&gUnknown_810510C);
    }
  }
}

void sub_808AF3C(char param_1,char param_2,u32 param_3)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack24 [4];
  u8 auStack20 [4];


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      sub_8090A8C(auStack20,0x78,0);
      sub_80464C8(sub_8083600(),param_3,auStack20);
      sub_8083E88(0x72);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      sub_8052910(&gUnknown_81051D0);
    }
  }
}

void sub_808AFB0(char param_1)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack12 [4];

  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2E) && (sub_8098100(0x1d) == 0) && (sub_80860A8(0x79) != 0)) {
    sub_8097FD0(0x1d);
    sub_8045B94(gAvailablePokemonNames,sub_8083600(),0);
    // $m0 obatined the Rock Part that Regirock was guarding
    sub_8052910(&gUnknown_81050B4);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(char param_1)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack12 [4];

  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2F) && (sub_8098100(0x1d) == 0) && (sub_80860A8(0x77) != 0)) {
    sub_8097FD0(0x1d);
    sub_8045B94(gAvailablePokemonNames,sub_8083600(),0);
    // $m0 obatined the Ice Part that Regice was guarding
    sub_8052910(&gUnknown_810517C);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(char param_1)
{
  struct unkDungeon_8041D5C * uVar3;
  u8 auStack12 [4];
  
  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x30) && (sub_8098100(0x1d) == 0) && (sub_80860A8(0x78) != 0)) {
    sub_8097FD0(0x1d);
    sub_8045B94(gAvailablePokemonNames, sub_8083600(), 0);
    // $m0 obatined the Steel Part that Registeel was guarding
    sub_8052910(&gUnknown_8105244);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(4);
    // INTRUDER ALERT
    // EXTERMINATE
    sub_8052910(&gUnknown_8104FD4);
    sub_803E708(10,70);
    sub_808563C(sub_808B2C4);
  }
}

void RegicePreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(4);
    // INTRUDER ALERT
    // EXTERMINATE
    sub_8052910(&gUnknown_8105028);
    sub_803E708(10,70);
    sub_808563C(sub_808B2D4);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (sub_8098100(0x22) == '\0') {
    sub_8085930(4);
    // INTRUDER ALERT
    // EXTERMINATE
    sub_8052910(&gUnknown_8105034);
    sub_803E708(10,70);
    sub_808563C(sub_808B2E4);
  }
}

NAKED
void sub_808B1CC(u8 r0)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tsub sp, 0x8\n"
	"\tlsls r0, 24\n"
	"\tlsrs r6, r0, 24\n"
	"\tldr r7, _0808B21C\n"
	"\tldr r2, [r7]\n"
	"\tldr r1, _0808B220\n"
	"\tadds r0, r2, r1\n"
	"\tldrh r0, [r0]\n"
	"\tldr r5, _0808B224\n"
	"\tldr r1, [sp]\n"
	"\tands r1, r5\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
	"\tldr r3, _0808B228\n"
	"\tadds r2, r3\n"
	"\tldrh r0, [r2]\n"
	"\tlsls r0, 16\n"
	"\tldr r4, _0808B22C\n"
	"\tadds r2, r4, 0\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp]\n"
	"\tmov r0, sp\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tcmp r0, 0\n"
	"\tblt _0808B208\n"
	"\tcmp r2, 0\n"
	"\tbge _0808B244\n"
"_0808B208:\n"
	"\tbl sub_8083600\n"
	"\tadds r2, r0, 0\n"
	"\tcmp r2, 0\n"
	"\tbne _0808B230\n"
	"\tldr r1, [r7]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tb _0808B2A8\n"
	"\t.align 2, 0\n"
"_0808B21C: .4byte gUnknown_203B418\n"
"_0808B220: .4byte 0x00000684\n"
"_0808B224: .4byte 0xffff0000\n"
"_0808B228: .4byte 0x00000686\n"
"_0808B22C: .4byte 0x0000ffff\n"
"_0808B230:\n"
	"\tldrh r0, [r2, 0x4]\n"
	"\tldr r1, [sp]\n"
	"\tands r1, r5\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
	"\tldrh r0, [r2, 0x6]\n"
	"\tlsls r0, 16\n"
	"\tands r1, r4\n"
	"\torrs r1, r0\n"
	"\tstr r1, [sp]\n"
"_0808B244:\n"
	"\tmov r5, sp\n"
	"\tmov r0, sp\n"
	"\tmovs r1, 0\n"
	"\tbl sub_807FE04\n"
	"\tmov r0, sp\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r0, r2]\n"
	"\tmovs r3, 0x2\n"
	"\tldrsh r1, [r5, r3]\n"
	"\tbl sub_8049590\n"
	"\tldrh r2, [r0]\n"
	"\tmovs r3, 0x80\n"
	"\tlsls r3, 2\n"
	"\tadds r1, r3, 0\n"
	"\torrs r1, r2\n"
	"\tstrh r1, [r0]\n"
	"\tcmp r6, 0\n"
	"\tbeq _0808B2A0\n"
	"\tadds r0, r6, 0\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808B2A0\n"
	"\tmovs r0, 0x7A\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0808B2A0\n"
	"\tadd r4, sp, 0x4\n"
	"\tadds r0, r4, 0\n"
	"\tadds r1, r6, 0\n"
	"\tmovs r2, 0\n"
	"\tbl sub_8090A8C\n"
	"\tldrh r0, [r5, 0x2]\n"
	"\tsubs r0, 0x1\n"
	"\tstrh r0, [r5, 0x2]\n"
	"\tmov r0, sp\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl sub_80460F8\n"
"_0808B2A0:\n"
	"\tbl sub_8049ED4\n"
	"\tbl sub_8040A84\n"
"_0808B2A8:\n"
	"\tadd sp, 0x8\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}


void sub_808B2B0(struct unkDungeon_8041D5C *r0)
{
    r0->unk70->unk46 = 4;
    sub_806CE68(r0, 4);
}


void sub_808B2C4(struct unkDungeon_8041D5C *r0)
{
    sub_8086A70(r0, 0xE1 << 1, 0xB);
}


void sub_808B2D4(struct unkDungeon_8041D5C *r0)
{
    sub_8086A70(r0, 0xE1 << 1, 0xB);
}


void sub_808B2E4(struct unkDungeon_8041D5C *r0)
{
    sub_8086A70(r0, 0xE1 << 1, 0xB);
}

void sub_808B2F4(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x1a);
  sub_8083E88(0x79);
  sub_808BCE4();
  sub_8049ED4();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->unk4,iVar1->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
}

void sub_808B35C(void)
{
  struct unkDungeon_8041D5C * iVar2;
  struct unkDungeon_8041D5C * uVar3;
  
  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x1a);
  sub_8083E88(0x79);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(SPECIES_JIRACHI)) {
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
    sub_808BCE4();
    sub_8049ED4();

  }
  sub_8085860(iVar2->unk4,iVar2->unk6 - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
}

#ifdef NONMATCHING
void sub_808B3E4(u8 param_1,u8 param_2,u8 param_3)
{
  u8 uVar1;
  
  // TODO R1 and R2 shifts are switched ordering but matches
  if (((((param_2 * 0x1000000) + 0xcf000000U) >> 0x18) < 2) && (param_1 == 0x1A)){
    sub_8097FA8(0x1e);
    if (param_3 != 0) {
      gUnknown_203B418->unk2 = 1;
    }
    else {
      uVar1 = gUnknown_203B418->unk1356C;
      if (sub_80860A8(0x36) != 0) {
           JirachiWish();
      }
      else {
          sub_808B50C();
      }
      gUnknown_203B418->unk1356C = uVar1;
      sub_8040A84();
    }
  }
}
#else
NAKED
void sub_808B3E4(u8 param_1, u8 param_2, u8 param_3)
{
    asm_unified(
	"\tpush {r4,lr}\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tlsls r1, 24\n"
	"\tlsls r2, 24\n"
	"\tlsrs r4, r2, 24\n"
	"\tmovs r2, 0xCF\n"
	"\tlsls r2, 24\n"
	"\tadds r1, r2\n"
	"\tlsrs r1, 24\n"
	"\tcmp r1, 0x1\n"
	"\tbhi _0808B44E\n"
	"\tcmp r0, 0x1A\n"
	"\tbne _0808B44E\n"
	"\tmovs r0, 0x1E\n"
	"\tbl sub_8097FA8\n"
	"\tcmp r4, 0\n"
	"\tbeq _0808B418\n"
	"\tldr r0, _0808B414\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1, 0x2]\n"
	"\tb _0808B44E\n"
	"\t.align 2, 0\n"
"_0808B414: .4byte gUnknown_203B418\n"
"_0808B418:\n"
	"\tldr r0, _0808B434\n"
	"\tldr r0, [r0]\n"
	"\tldr r1, _0808B438\n"
	"\tadds r0, r1\n"
	"\tldrb r4, [r0]\n"
	"\tmovs r0, 0x36\n"
	"\tbl sub_80860A8\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0808B43C\n"
	"\tbl JirachiWish\n"
	"\tb _0808B440\n"
	"\t.align 2, 0\n"
"_0808B434: .4byte gUnknown_203B418\n"
"_0808B438: .4byte 0x0001356c\n"
"_0808B43C:\n"
	"\tbl sub_808B50C\n"
"_0808B440:\n"
	"\tldr r0, _0808B454\n"
	"\tldr r0, [r0]\n"
	"\tldr r2, _0808B458\n"
	"\tadds r0, r2\n"
	"\tstrb r4, [r0]\n"
	"\tbl sub_8040A84\n"
"_0808B44E:\n"
	"\tpop {r4}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0808B454: .4byte gUnknown_203B418\n"
"_0808B458: .4byte 0x0001356c");
}
#endif

void JirachiPreFightDialogue(void)
{
  struct unkDungeon_8041D5C * iVar1;
  struct unkDungeon_8041D5C * uVar2;
  
  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x1a);
  sub_8086448();
  sub_803E708(0x40,70);
  sub_8052910(&gUnknown_8105438);
  sub_803E708(10,70);
  sub_808696C(iVar1);
  sub_803E708(10,70);
  sub_8052910(&gUnknown_81054A0);
  sub_80861F8(0x37,uVar2,1);
  sub_80855E4(sub_80862BC);
  sub_803E708(0x3c,70);
  sub_808BBB8(uVar2);
  sub_803E708(0x5a,70);
  sub_8052910(&gUnknown_81054E4);
  sub_803E708(10,70);
  sub_8052910(&gUnknown_810550C);
  sub_803E708(10,70);
  sub_8086A70(uVar2,0x15e,0x20);
  sub_80858AC(&iVar1->unkC,0x10);
}

void sub_808B50C(void)
{
  struct unkDungeon_8041D5C * iVar1;
  
  iVar1 = sub_8085680(0x1a);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(iVar1);
  sub_8041888(0);
  iVar1->unk70->unk15C = 1;
  iVar1->unk70->unk15E = 0;
  sub_80861B8(iVar1,0xe,0);
  sub_8083ED8(0x1e);
  sub_803E708(0x1e,70);
  // Fwaaaahhhh
  sub_8052910(&gUnknown_810554C);
  sub_8083E88(0x79);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  sub_8052910(&gUnknown_8105558);
  sub_803E708(10,70);
  sub_808BC20(iVar1);
  sub_8052910(&gUnknown_81055F4);
  sub_803E708(10,70);
  gUnknown_203B418->unk2 = 1;
}
