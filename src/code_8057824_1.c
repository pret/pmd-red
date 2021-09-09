#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_entity.h"
#include "pokemon.h"
#include "item.h"
#include "constants/direction.h"

extern struct DungeonGlobalData *gDungeonGlobalData;

extern u32 gUnknown_202EDC8;
extern u8 gUnknown_202E038[0x50];
extern u8 gAvailablePokemonNames[0x58];

extern s16 gUnknown_80F57CA;
extern s16 gUnknown_80F57D2;
extern s16 gUnknown_80F57D0;
extern s16 gUnknown_80F57CE;

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
extern u32 gUnknown_8102C30;
extern u32 gUnknown_8102C54;
extern u32 gUnknown_8102C98;
extern u32 gUnknown_8102CB0;
extern u32 gUnknown_8102CF8;
extern u32 gUnknown_8102D34;
extern u32 gUnknown_8102D4C;
extern u32 gUnknown_8102D7C;
extern u32 gUnknown_8102DFC;
extern u32 gUnknown_8102E2C;
extern u32 gUnknown_8102E54;
extern u32 gUnknown_8102BE4;
extern u32 gUnknown_8102BC4;
extern u32 gUnknown_8102B54;
extern u32 gUnknown_8102B1C;
extern u32 gUnknown_8103488;
extern u32 gUnknown_81033A0;
extern u32 gUnknown_81033AC;
extern u32 gUnknown_810343C;
extern u32 gUnknown_810347C;
extern u32 gUnknown_8103188;
extern u32 gUnknown_8103228;
extern u32 gUnknown_8103310;
extern u32 gUnknown_8103340;
extern u32 gUnknown_8102E70;
extern u32 gUnknown_8102EBC;
extern u32 gUnknown_8102EE0;
extern u32 gUnknown_8102EF8;
extern u32 gUnknown_8102F30;
extern u32 gUnknown_8102F64;
extern u32 gUnknown_8102F84;
extern u32 gUnknown_8102FAC;
extern u32 gUnknown_8102FC4;
extern u32 gUnknown_8102FD8;
extern u32 gUnknown_8103054;
extern u32 gUnknown_81030D8;
extern u32 gUnknown_8103110;
extern u32 gUnknown_8103140;
extern u32 gUnknown_8102B10;
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
extern u32 gUnknown_8102A9C;
extern u32 gUnknown_8102984;
extern u32 gUnknown_81029B4;
extern u32 gUnknown_8102A18;
extern u32 gUnknown_8102A24;
extern u32 gUnknown_8102A74;
extern u32 gUnknown_81028D4;
extern u32 gUnknown_8102918;
extern u32 gUnknown_8102948;
extern u32 gUnknown_8102478;
extern u32 gUnknown_81025B4;
extern u32 gUnknown_81025D4;
extern u32 gUnknown_8102610;
extern u32 gUnknown_81026C4;
extern u32 gUnknown_810270C;
extern u32 gUnknown_810272C;
extern u32 gUnknown_81027BC;
extern u32 gUnknown_8102810;
extern u32 gUnknown_8102840;
extern u32 gUnknown_810286C;
extern u32 gUnknown_81028B8;
extern u32 gUnknown_810232C;
extern u32 gUnknown_8102398;
extern u32 gUnknown_81023C4;
extern u32 gUnknown_8102400;
extern u32 gUnknown_8102454;
extern u32 gUnknown_8100D3C;
extern u32 gUnknown_8102158;
extern u32 gUnknown_8102190;
extern u32 gUnknown_8102200;
extern u32 gUnknown_8102254;
extern u32 gUnknown_81022F8;
extern u32 gUnknown_8101A9C;
extern u32 gUnknown_8101AD4;
extern u32 gUnknown_8101C30;
extern u32 gUnknown_8101CBC;
extern u32 gUnknown_8101D8C;
extern u32 gUnknown_8101DA0;
extern u32 gUnknown_8101E1C;
extern u32 gUnknown_8101EAC;
extern u32 gUnknown_8102070;
extern u32 gUnknown_81020A4;
extern u32 gUnknown_81020D4;
extern u32 gUnknown_8102108;
extern u32 gUnknown_810193C;
extern u32 gUnknown_8101970;
extern u32 gUnknown_8101994;
extern u32 gUnknown_81019E4;
extern u32 gUnknown_8101A04;
extern u32 gUnknown_8101A38;

extern struct DungeonEntity *sub_8085480(void);
extern struct DungeonEntity *sub_8085680(u32);
extern void sub_808BBA8(struct DungeonEntity * );
extern void sub_80855E4(void *);
extern void sub_8041888(u32);
extern void sub_80861B8(struct DungeonEntity *, u32, u32);
extern void sub_8083ED8(u32);
extern void sub_803E708(u32, u32);
extern void sub_8052910(u32 *r0);
extern void sub_8083E88(u32);
extern void sub_808BC20(struct DungeonEntity *);

extern void sub_80862BC(struct DungeonEntity *);
extern void sub_8086448();
extern void SpriteLookAroundEffect();
extern u32 sub_80861F8(u32, struct DungeonEntity *, u32);
extern void SetupBossFightHP(struct DungeonEntity *, u32, u32);
extern void sub_80858AC(u32 *, u32);

extern void sub_8097FA8(u32);
extern void JirachiWish();
extern u8 sub_80860A8(u32);
extern void sub_8040A84();
extern void sub_8086A3C(struct DungeonEntity *);
extern u8 HasRecruitedMon(u32);
extern void sub_80854D4();
extern void sub_8085930(u32);
extern void sub_8068FE0(struct DungeonEntity *, u32, u32);
extern void sub_8085918(struct DungeonEntity *, u32);
extern void sub_8049ED4();
extern void sub_8085860(s32 r0, u32 r1);
extern void sub_806CE68(struct DungeonEntity *, u32);

extern void sub_8052D44(u8 *, struct DungeonEntity *, struct DungeonEntity *);
extern void sub_8097FD0(u32);
extern void sub_8045B94(u8 *, struct DungeonEntity *, u32);
extern struct DungeonEntity *sub_8083600();
extern void sub_80421C0(struct DungeonEntity *, u32);
extern void sub_8046D20();
extern void sub_808B1CC(u8);
extern void sub_80464C8(struct DungeonEntity *, u32, struct ItemSlot *);
extern void sub_8098044(u32);
extern void PlaySoundEffect(u32);
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
extern void sub_808BBB8(struct DungeonEntity *param_1);
extern u8 sub_8098100(u32);
extern void sub_8086794();

void EnteiScreenFlash(void);
void RaikouScreenFlash(void);
void sub_808A528(struct DungeonEntity * param_1);
void SuicuneScreenFlash();
void sub_808A904(struct DungeonEntity * param_1);
void HoOhScreenFlash(void);
void LatiosScreenFlash(void);
void sub_808B2B0(struct DungeonEntity *r0);
void sub_808B2C4(struct DungeonEntity *r0);
void sub_808B2D4(struct DungeonEntity *r0);
void sub_808B2E4(struct DungeonEntity *r0);
void sub_808B50C(void);
void sub_8089B64(struct DungeonEntity *param_1);
void MewtwoScreenFlash(void);
void sub_80898F8(struct DungeonEntity *r0);
void sub_8089908(struct DungeonEntity *r0);
void sub_8089620(struct DungeonEntity *param_1);
void RayquazaScreenFlash(void);
void sub_80891F0(void);
void sub_8089294(void);
void sub_80891B0();
void sub_8089224();
void sub_80891D0();
void sub_808919C();
void sub_8088D30(void);

extern void sub_8083F14();
extern u8 sub_80450E0(struct DungeonEntity *);
extern u8 sub_8086AE4(u32);


extern void sub_8072008(struct DungeonEntity *, struct DungeonEntity *, s16, u32, u32);
extern struct DungeonEntity *sub_808548C();
extern void sub_80856E0(struct DungeonEntity *, u32);
extern void sub_80869E4(struct DungeonEntity *, u32, u32, u32);
extern void sub_804539C(struct DungeonEntity *, u32, u32);
extern void sub_806CDD4(struct DungeonEntity *, u32, u32);
extern void sub_8085374();

extern void sub_8086848(u32 ,u32);
extern void sub_80856C8(struct DungeonEntity *, s32, s32);
extern void sub_80861D4(struct DungeonEntity *, u32, u32);
extern void sub_8086738();
extern void sub_8086A54(struct DungeonEntity *);
extern void sub_8086764();

extern u32 sub_803F994();
extern s32 sub_803F9B0();
extern void sub_803F878(u32,s32);

void sub_8088C08(struct DungeonEntity * param_1);
void sub_8088CA0(void);
void ArticunoScreenFlash(void);
void sub_8088484(struct DungeonEntity *param_1);
void sub_8088574(void);

void sub_8087D30(struct DungeonEntity * param_1);
void sub_8087D80(s32 r0, s32 r1);
void sub_8087DE8(s32 r0, s32 r1);
void sub_8087EB0(void);
void sub_808654C(void);

extern void sub_8086598();
extern void sub_80865E8();


extern void sub_8086500(void);
extern void sub_8086690(void);
void sub_8087F24(void);
extern void sub_808663C(void);
void sub_8087704(struct DungeonEntity *param_1);
void sub_808775C(int param_1);

extern u32 gUnknown_81017E4;
extern u32 gUnknown_81015A0;
extern u32 gUnknown_8101898;
extern u32 gUnknown_81018EC;
extern u32 gUnknown_8101918;


void ZapdosReFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(8);
  sub_8086448();
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_81017E4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1da);
  sub_8052910(&gUnknown_81015A0);
  sub_803E708(10,0x46);
  sub_8087704(uVar2);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8101898);
  sub_808775C(1);
  sub_8052910(&gUnknown_81018EC);
  sub_808775C(2);
  sub_8052910(&gUnknown_8101918);
  SetupBossFightHP(uVar2,300,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(8);
  sub_8086448();
  if (sub_8086AE4(SPECIES_ZAPDOS)) {
    sub_80866C4(&gUnknown_8101A38);
  }
  else {
    sub_808775C(1);
    PlaySoundEffect(0x1da);
    sub_8052910(&gUnknown_810193C);
    sub_8087704(uVar3);
    sub_8052910(&gUnknown_8101970);
    sub_808775C(1);
    sub_8052910(&gUnknown_8101994);
    sub_808775C(2);
    sub_8052910(&gUnknown_81019E4);
    sub_808775C(2);
    sub_8052910(&gUnknown_8101A04);
    sub_803E708(10,0x46);
    SetupBossFightHP(uVar3,300,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}


void sub_8087704(struct DungeonEntity *param_1)
{
  int iVar1;

  param_1->entityData->unk15C = 1;
  param_1->entityData->unk15E = 0;
  param_1->entityData->unk174 = 200;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    param_1->entityData->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
}

void sub_808775C(int param_1)
{
  int iVar1;
  int iVar2;

  PlaySoundEffect(0x1f6);
  if (2 < param_1) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      sub_8085C54(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  if (1 < param_1) {
    for(iVar2 = 250; iVar2 > 199; iVar2 -= 10)
    {
      sub_8085C54(iVar2,iVar2,iVar2 / 2,1,1);
      sub_803E46C(0x46);
    }
  }
  for(iVar2 = 250; iVar2 >= 0; iVar2 -= 10)
  {
    iVar1 = iVar2;
    if (iVar2 < 0) {
      iVar1 = iVar2 + 3;
    }
    sub_8085C54(iVar2,iVar2,iVar1 >> 2,1,1);
    sub_803E46C(0x46);
  }
  sub_8085EB0();
}



void sub_80877E8(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(9);
  sub_8083E88(0x26);
  sub_8085374();
  sub_80854D4();
  sub_8085930(6);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->posWorldX + -3,iVar1->posWorldY + -2);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_MOLTRES);
}

void sub_8087848(void)
{
  struct DungeonEntity *iVar2;
  struct DungeonEntity *uVar3;

  u32 uVar4;
  s32 iVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(9);
  sub_8083E88(0x26);
  sub_80854D4();
  sub_8085930(6);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(SPECIES_MOLTRES)) {
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    sub_8072008(uVar3,uVar3,gUnknown_80F57CE,0,0);
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->posWorldX - 5, iVar2->posWorldY);
  uVar4 = sub_803F994();
  iVar3 = sub_803F9B0();
  sub_803F878(uVar4,iVar3 + -0x1000);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_MOLTRES);
}



void sub_80878F4(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xF6000000U) >> 0x18 < 3) && (param_1 == 0x9)) {
    sub_8097FA8(0x7);
    gDungeonGlobalData->unk2 = 1;
  }
}

void MoltresPreFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;
  struct DungeonEntity *uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(9);
  sub_8087D80(0xc,5);
  sub_8086500();
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8101A9C);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,5);
  sub_803E708(4,0x46);
  SpriteLookAroundEffect(uVar2);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8101AD4);
  sub_803E708(10,0x46);
  sub_8087D80(0xc,5);
  sub_8087DE8(9,5);
  sub_8052910(&gUnknown_8101C30);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(iVar1,4,2,6);
  sub_8052910(&gUnknown_8101CBC);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,2,6);
  sub_8086690();
  sub_8052910(&gUnknown_8101D8C);
  sub_803E708(10,0x46);
  sub_8085930(5);
  sub_803E708(4,0x46);
  sub_8085930(4);
  PlaySoundEffect(0x2f2);
  sub_8083F14();
  sub_8087F24();
  sub_8052910(&gUnknown_8101DA0);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8101E1C);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1cf);
  sub_80856E0(uVar2,4);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8101EAC);
  sub_803E708(10,0x46);
  sub_8087EB0();
  PlaySoundEffect(0x1da);
  sub_8052910(&gUnknown_8102070);
  sub_803E708(10,0x46);
  sub_8087D80(9,5);
  sub_8087DE8(0xb,5);
  sub_8052910(&gUnknown_81020A4);
  sub_803E708(10,0x46);
  sub_8087D80(0xc,5);
  sub_8087DE8(9,5);
  sub_8087D30(uVar3);
  sub_808663C();
  sub_8087EB0();
  sub_8052910(&gUnknown_81020D4);
  sub_803E708(10,0x46);
  sub_8087DE8(0xb,6);
  sub_8052910(&gUnknown_8102108);
  sub_803E708(10,0x46);
  SetupBossFightHP(uVar3,400,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}


void MoltresReFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;
  struct DungeonEntity *uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(9);
  sub_8087D80(10,5);
  sub_8086500();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(uVar2);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8102158);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(iVar1,4,2,6);
  sub_8052910(&gUnknown_8102190);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,2,6);
  sub_80869E4(iVar1,4,2,6);
  sub_8086690();
  sub_8087F24();
  sub_803E708(10,0x46);
  sub_8085930(5);
  sub_803E708(4,0x46);
  sub_8085930(4);
  sub_8087D30(uVar3);
  sub_808663C();
  sub_8087EB0();
  sub_8052910(&gUnknown_8102200);
  sub_803E708(10,0x46);
  sub_8087DE8(0xb,6);
  sub_8052910(&gUnknown_8102254);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_81022F8);
  sub_803E708(10,0x46);
  SetupBossFightHP(uVar3,400,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void MoltresPostStoryPreFightDialogue(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(9);
  sub_8087D80(0xc,5);
  sub_808654C();
  if (sub_8086AE4(SPECIES_MOLTRES)) {
    sub_8085930(5);
    sub_803E708(4,0x46);
    sub_8085930(4);
    sub_803E708(4,0x46);
    sub_803E708(10,0x46);
    sub_8052910(&gUnknown_8100D3C);
    sub_803E708(10,0x46);
    gDungeonGlobalData->unk2 = 1;
  }
  else {
    sub_8052910(&gUnknown_810232C);
    sub_8085930(5);
    sub_803E708(4,0x46);
    sub_8085930(4);
    sub_8087D30(uVar3);
    sub_8052910(&gUnknown_8102398);
    sub_8087D80(0xc,5);
    sub_8087DE8(9,5);
    sub_8052910(&gUnknown_81023C4);
    sub_8087EB0();
    sub_8052910(&gUnknown_8102400);
    sub_8087DE8(0xb,6);
    sub_8052910(&gUnknown_8102454);
    sub_803E708(10,0x46);
    SetupBossFightHP(uVar3,400,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_8087D30(struct DungeonEntity * param_1)
{
  s32 iVar1;

  param_1->entityData->unk15C = 1;
  param_1->entityData->unk15E = 0;
  param_1->entityData->unk174 = 0xc800;
  PlaySoundEffect(0x1f8);
  iVar1 = 200;
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    param_1->entityData->unk174 = iVar1 * 256;
    sub_803E46C(0x46);
  }
}

NAKED
void sub_8087D80(s32 r0, s32 r1)
{
	asm_unified("\tpush {lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087D98\n"
	"\tadds r0, 0xFF\n"
"_08087D98:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087DE0\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087DB8\n"
	"\tadds r0, 0xFF\n"
"_08087DB8:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087DE4\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x10\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadd sp, 0x8\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087DE0: .4byte 0xffff0000\n"
"_08087DE4: .4byte 0x0000ffff");
}

NAKED
void sub_8087DE8(s32 r0, s32 r1)
{
	asm_unified("\tpush {r4-r6,lr}\n"
	"\tsub sp, 0x8\n"
	"\tadds r3, r1, 0\n"
	"\tlsls r1, r0, 1\n"
	"\tadds r1, r0\n"
	"\tlsls r1, 11\n"
	"\tmovs r2, 0xC0\n"
	"\tlsls r2, 4\n"
	"\tadds r0, r1, r2\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E00\n"
	"\tadds r0, 0xFF\n"
"_08087E00:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tldr r1, _08087EA8\n"
	"\tldr r2, [sp, 0x4]\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tlsls r0, r3, 1\n"
	"\tadds r0, r3\n"
	"\tlsls r0, 11\n"
	"\tmovs r1, 0x80\n"
	"\tlsls r1, 5\n"
	"\tadds r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbge _08087E20\n"
	"\tadds r0, 0xFF\n"
"_08087E20:\n"
	"\tlsls r0, 8\n"
	"\tlsrs r0, 16\n"
	"\tlsls r0, 16\n"
	"\tldr r1, _08087EAC\n"
	"\tands r2, r1\n"
	"\torrs r2, r0\n"
	"\tstr r2, [sp, 0x4]\n"
	"\tmovs r0, 0xB9\n"
	"\tlsls r0, 1\n"
	"\tmovs r1, 0\n"
	"\tstr r1, [sp]\n"
	"\tmovs r1, 0x16\n"
	"\tmovs r2, 0\n"
	"\tadd r3, sp, 0x4\n"
	"\tbl sub_8085EC8\n"
	"\tadds r6, r0, 0\n"
	"\tmovs r0, 0xF6\n"
	"\tlsls r0, 1\n"
	"\tbl PlaySoundEffect\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E4E:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl sub_8085C54\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0x13\n"
	"\tbgt _08087E4E\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tmovs r4, 0xFA\n"
	"\tmovs r5, 0x1\n"
"_08087E74:\n"
	"\tstr r5, [sp]\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0\n"
	"\tmovs r2, 0\n"
	"\tmovs r3, 0x1\n"
	"\tbl sub_8085C54\n"
	"\tmovs r0, 0x46\n"
	"\tbl sub_803E46C\n"
	"\tsubs r4, 0xA\n"
	"\tcmp r4, 0\n"
	"\tbge _08087E74\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x46\n"
	"\tbl sub_803E708\n"
	"\tbl sub_8085EB0\n"
	"\tadds r0, r6, 0\n"
	"\tbl sub_8085F44\n"
	"\tadd sp, 0x8\n"
	"\tpop {r4-r6}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08087EA8: .4byte 0xffff0000\n"
"_08087EAC: .4byte 0x0000ffff");
}

void sub_8087EB0(void)
{
  int iVar1;

  PlaySoundEffect(0x1ed);
  iVar1 = 0xfa;
  for(iVar1 = 250; iVar1 > 9; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(0x1e,0x46);
  sub_8085EB0();
}

void sub_8087F24(void)
{
  s32 iVar1;

  for(iVar1 = 0; iVar1 >= -80; iVar1 -= 8)
  {
    sub_8085C54(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}


void sub_8087F54(void)
{
  struct DungeonEntity  *iVar2;
  struct DungeonEntity *uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xd);
  sub_8083E88(0x72);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar3, 0);
  sub_8086A3C(uVar3);
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY + -3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ARTICUNO);
}

void sub_8087FB4(void)
{
  struct DungeonEntity  *iVar2;

  iVar2 = sub_8085680(0xd);
  sub_8083E88(0x72);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(iVar2, 0);
  sub_806CDD4(iVar2, 0xF, 0);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ARTICUNO);
}

void sub_8087FF8(void)
{
  struct DungeonEntity  *iVar2;
  struct DungeonEntity *uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xd);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(SPECIES_ARTICUNO)) {
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    sub_8072008(uVar3,uVar3,gUnknown_80F57D0,0,0);
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY + -3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ARTICUNO);
}



void sub_8088088(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xF3000000U) >> 0x18 < 3) && (param_1 == 0xD)) {
    sub_8097FA8(0x9);
    gDungeonGlobalData->unk2 = 1;
  }
}

void ArticunoPreFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;
  struct DungeonEntity *uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(0xd);
  sub_8086448();
  SpriteLookAroundEffect(uVar2);
  sub_8052910(&gUnknown_8102478);
  sub_803E708(10,0x46);
  sub_8086598();
  sub_8083F14();
  sub_8052910(&gUnknown_81025B4);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(iVar1,4,2,6);
  sub_8052910(&gUnknown_81025D4);
  sub_803E708(10,0x46);
  sub_8085918(iVar1,6);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,5);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,6);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,7);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,6);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,5);
  sub_803E708(4,0x46);
  sub_8085918(iVar1,6);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8102610);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_81026C4);
  sub_803E708(10,0x46);
  sub_80869E4(iVar1,4,1,4);
  sub_80869E4(uVar2,4,2,4);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(uVar2);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(iVar1);
  sub_8052910(&gUnknown_810270C);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_810272C);
  sub_803E708(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeonGlobalData->unkE265 = 7;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  sub_8052910(&gUnknown_81027BC);
  sub_803E708(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  sub_8052910(&gUnknown_8102810);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(uVar3);
  sub_80865E8();
  ArticunoScreenFlash();
  sub_8052910(&gUnknown_8102840);
  sub_806CDD4(uVar3,0xf,0);
  ArticunoScreenFlash();
  sub_8052910(&gUnknown_810286C);
  sub_806CDD4(uVar3,0x10,0);
  ArticunoScreenFlash();
  sub_8052910(&gUnknown_81028B8);
  sub_806CDD4(uVar3,0xf,0);
  sub_803E708(0x10,0x46);
  SetupBossFightHP(uVar3,0x1c2,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void ArticunoReFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xd);
  gDungeonGlobalData->unkE265 = 7;
  sub_807EAA0(0,1);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_81028D4);
  sub_806CDD4(uVar2,0x10,0);
  ArticunoScreenFlash();
  sub_8052910(&gUnknown_8102918);
  ArticunoScreenFlash();
  sub_8052910(&gUnknown_8102948);
  sub_806CDD4(uVar2,0xf,0);
  sub_803E708(0x28,0x46);
  SetupBossFightHP(uVar2,0x1c2,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  struct DungeonEntity *iVar2;
  struct DungeonEntity *uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xd);
  sub_8086448();
  if (sub_8086AE4(SPECIES_ARTICUNO)) {
    sub_80866C4(&gUnknown_8102A9C);
  }
  else {
    gDungeonGlobalData->unkE265 = 7;
    sub_807EAA0(0,1);
    ArticunoScreenFlash();
    sub_8086738();
    PlaySoundEffect(0x1da);
    sub_8052910(&gUnknown_8102984);
    sub_803E708(10,0x46);
    sub_8088484(uVar3);
    ArticunoScreenFlash();
    sub_8052910(&gUnknown_81029B4);
    sub_806CDD4(uVar3,0xf,0);
    ArticunoScreenFlash();
    sub_8052910(&gUnknown_8102A18);
    sub_806CDD4(uVar3,0x10,0);
    ArticunoScreenFlash();
    sub_8052910(&gUnknown_8102A24);
    ArticunoScreenFlash();
    sub_8052910(&gUnknown_8102A74);
    sub_806CDD4(uVar3,0xf,0);
    sub_803E708(0x28,0x46);
    SetupBossFightHP(uVar3,0x1c2,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_8088484(struct DungeonEntity *param_1)
{
  int iVar1;

  param_1->entityData->unk15C = 1;
  param_1->entityData->unk15E = 0;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 5)
  {
    param_1->entityData->unk174 = iVar1 * 256;
    sub_8085C54(iVar1,iVar1,iVar1 / 2,1,0);
    sub_803E46C(0x46);
  }
}

void ArticunoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x2ad);
  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    sub_8085C54(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(0,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1 / 2,iVar1,iVar1,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(4,0x46);
  sub_8085EB0();
}

void sub_8088574(void)
{
  int iVar1;

  for(iVar1 = 0; iVar1 <= 80; iVar1 += 8)
  {
    sub_8085C54(iVar1,iVar1,iVar1,0,0);
    sub_803E46C(0x46);
  }
}

void sub_80885A0(void)
{
  sub_8083ED8(0x3c);
  sub_803E708(0x3c,0x46);
  sub_8083F14();
  gDungeonGlobalData->unk7 = 1;
}

void sub_80885C4(void)
{
  struct DungeonEntity * iVar1;

  iVar1 = sub_8085480();
  sub_8083ED8(0x3c);
  sub_803E708(0x3c,0x46);
  sub_8083F14();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
}

void sub_8088608(void)
{
    gDungeonGlobalData->unk2 = 1;
}

void sub_8088618(void)
{
    sub_8086448();
    // The mountain's summit...
    // But there is no one here
    // It's time to go back
    sub_80866C4(&gUnknown_8102B10);
}

void sub_808862C(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(10);
  uVar3 = sub_8085680(0xe);
  sub_8083E88(0x72);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,4);
  sub_80861D4(uVar2,0xd,4);
  sub_8085918(uVar3,0);
  sub_8086A3C(uVar3);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY -3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_GROUDON);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_ALAKAZAM);
}

void sub_80886C4(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * uVar3;

  u32 uVar4;
  s32 iVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(10);
  uVar3 = sub_8085680(0xe);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8085918(uVar3,0);
  sub_8086A3C(uVar3);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY);
  uVar4 = sub_803F994();
  iVar2 = sub_803F9B0();
  sub_803F878(uVar4,iVar2 + -0x1000);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_GROUDON);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_ALAKAZAM);
}

void sub_808875C(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;
  struct DungeonEntity * uVar4;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(10);
  uVar4 = sub_8085680(0xe);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar3,0x21c,0);
  if (sub_8086AE4(0x19b)) {
    sub_8068FE0(uVar4,0x21c,0);
  }
  else {
    sub_8072008(uVar4,uVar4,gUnknown_80F57D2,0,0);
    sub_8085918(uVar4,0);
    sub_80861D4(uVar4,0xf,0);
  }
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_GROUDON);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_ALAKAZAM);
}

void sub_8088818(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xEE000000U) >> 0x18 < 3) && (param_1 == 0xE)) {
    sub_8097FA8(0xC);
    gDungeonGlobalData->unk2 = 1;
  }
}

void sub_8088848(void)
{
    sub_8086854();
}

void GroudonPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * uVar3;
  struct DungeonEntity * uVar4;

  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(10);
  uVar4 = sub_8085680(0xe);
  sub_8086448();
  sub_8052910(&gUnknown_8102E70);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  sub_8052910(&gUnknown_8102EBC);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  sub_8052910(&gUnknown_8102EE0);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_8052910(&gUnknown_8102EF8);
  sub_803E708(10,0x46);
  sub_8088CA0();
  sub_8052910(&gUnknown_8102F30);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8102F64);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(uVar2);
  sub_8052910(&gUnknown_8102F84);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(uVar3,6,4);
  PlaySoundEffect(0x205);
  sub_8086738();
  sub_8068FE0(uVar3,0x21c,0);
  sub_8052910(&gUnknown_8102FAC);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8102FC4);
  sub_803E708(10,0x46);
  sub_8085930(4);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(uVar2);
  sub_8052910(&gUnknown_8102FD8);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_8052910(&gUnknown_8103054);
  sub_803E708(10,0x46);
  sub_8083F14();
  sub_8088D30();
  sub_803E708(0x1e,0x46);
  sub_8052910(&gUnknown_81030D8);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8103110);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(4);
  sub_8052910(&gUnknown_8103140);
  sub_803E708(10,0x46);
  sub_8086A54(uVar4);
  sub_8085930(4);
  sub_8086764();
  SetupBossFightHP(uVar4,500,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void GroudonReFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xe);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_8052910(&gUnknown_8103188);
  sub_803E708(10,0x46);
  sub_8088CA0();
  sub_803E708(0x1e,0x46);
  sub_8052910(&gUnknown_8103228);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8103310);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_8083F14();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8052910(&gUnknown_8103340);
  sub_803E708(10,0x46);
  sub_8086A54(uVar2);
  sub_8085930(4);
  sub_8086764();
  SetupBossFightHP(uVar2,500,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xe);
  sub_8086448();
  if (sub_8086AE4(SPECIES_GROUDON)) {
      sub_80866C4(&gUnknown_8103488);
  }
  else{
    sub_8052910(&gUnknown_81033A0);
    sub_803E708(10,0x46);
    sub_8088C08(uVar3);
    sub_8088C08(uVar3);
    sub_8052910(&gUnknown_81033AC);
    PlaySoundEffect(0x1f6);
    sub_8088CA0();
    sub_8052910(&gUnknown_810343C);
    PlaySoundEffect(0x1f6);
    sub_8088CA0();
    sub_8052910(&gUnknown_810347C);
    sub_803E708(10,0x46);
    SetupBossFightHP(uVar3,500,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_8088C08(struct DungeonEntity * param_1)
{
  int iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(param_1,0,0);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      sub_804539C(param_1,0,0x100);
    }
    sub_803E46C(0x46);
  }
  sub_80856C8(param_1,param_1->posWorldX,param_1->posWorldY + 1);
  sub_80861D4(param_1,0xf,0);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_8085930(4);
  sub_803E708(0x22,0x46);
}

void sub_8088CA0(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

void sub_8088D30(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,0,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    sub_8085C54(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    sub_803E46C(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}


void sub_8088DC0(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xb);
  uVar3 = sub_8085680(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(uVar2);
  sub_806CDD4(uVar2,0xe,0);
  sub_8086A3C(uVar3);
  sub_806CDD4(uVar3,0xe,0);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_GROUDON);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_ALAKAZAM);
}

void sub_8088E5C(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xb);
  uVar3 = sub_8085680(0xc);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8068FE0(uVar3,0x21c,0);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY + -3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_GROUDON);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}


void MagmaCavernMidDialogue(void)
{
  struct DungeonEntity * uVar1;
  struct DungeonEntity * uVar2;
  struct DungeonEntity * iVar3;
  struct DungeonEntity * iVar4;
  u8 auStack36 [4];
  s32 local_20[2];

  uVar1 = sub_8085480();
  uVar2 = sub_808548C();
  iVar3 = sub_8085680(0xb);
  iVar4 = sub_8085680(0xc);
  sub_8052D44(auStack36,uVar1,uVar2);
  sub_8086448();
  SpriteLookAroundEffect(uVar2);
  // Let's see..
  // I wonder where we are?
  sub_8052910(&gUnknown_8102B1C);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(uVar1,4,2,6);
  // I know we've come pretty
  // far...
  //
  // I'm certain we've come quite
  // far already..
  sub_8052910(&gUnknown_8102B54);
  sub_803E708(10,0x46);
  sub_8083F14();
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0x28,0x46);
  // Waaah!
  // Qu-quake!
  sub_8052910(&gUnknown_8102BC4);
  sub_803E708(0x78,0x46);
  sub_8083E58(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_803E708(0x14,0x46);
  sub_8085930(4);
  sub_803E708(10,0x46);
  // Whew!
  // It settled down.
  //
  // Whew
  // It's over.
  sub_8052910(&gUnknown_8102BE4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(uVar2);
  PlaySoundEffect(0x1c7);
  sub_80856E0(uVar2,4);
  // Hey! $m0!
  // Over there!
  sub_8052910(&gUnknown_8102C30);
  iVar3->entityData->unk15E = 0;
  iVar4->entityData->unk15E =0;
  local_20[0] = (iVar3->posPixelX + iVar4->posPixelX) / 2;
  local_20[1] = (iVar3->posPixelY + iVar4->posPixelY) / 2 + 0x800;
  sub_80858AC(local_20,0x20);
  sub_803E708(0x3c,0x46);
  sub_80891F0();
  // Hey!
  // Are you OK?!
  //
  // Hey!
  // Snap out of it!
  sub_8052910(&gUnknown_8102C54);
  sub_803E708(10,0x46);
  // Urrrrgh...
  sub_8052910(&gUnknown_8102C98);
  sub_803E708(10,0x46);
  sub_80869E4(uVar1,4,2,5);
  // What happened to you?
  //
  // What happened here?
  sub_8052910(&gUnknown_8102CB0);
  sub_803E708(10,0x46);
  // We challenged..
  // $m2...
  // And wiped out..
  sub_8052910(&gUnknown_8102CF8);
  sub_803E708(10,0x46);
  sub_8052910(&gUnknown_8102D34);
  sub_803E708(10,0x46);
  sub_80869E4(uVar1,4,1,3);
  sub_80869E4(uVar2,4,1,3);
  // Grrgh..
  // We... It crushed us
  sub_8052910(&gUnknown_8102D4C);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(uVar2);
  // That's right...
  // What happened to $m3?
  // Where is $m3?
  //
  // Wait...
  // What about $m3?
  // Where did $m3 go?
  sub_8052910(&gUnknown_8102D7C);
  sub_803E708(0x1e,0x46);
  // $m3 is...
  // Still battling $m2...
  sub_8052910(&gUnknown_8102DFC);
  sub_803E708(10,0x46);
  sub_80869E4(uVar2,4,1,2);
  sub_80869E4(uVar1,4,2,6);
  // $m0!
  // We've got to hurry!
  sub_8052910(&gUnknown_8102E2C);
  sub_8089294();
  // Be careful!
  sub_8052910(&gUnknown_8102E54);
  sub_803E708(10,0x46);
  gDungeonGlobalData->unk2 = 1;
}

void sub_8089168(void)
{
  struct DungeonEntity *iVar1;

  iVar1 = sub_8085480();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(iVar1);
  sub_803E708(10,0x46);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void sub_808919C(struct DungeonEntity *r0)
{
    sub_804539C(r0, 0, 0xfffffe00);
}

void sub_80891B0(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 0, 4);
    r0->entityData->unk15F = 1;
}


void sub_80891D0(struct DungeonEntity *r0)
{
    sub_806CDD4(r0, 7, 4);
    r0->entityData->unk15F = 0;
}

void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_8089224(struct DungeonEntity * param_1)
{
  s32 iVar1;

  if (param_1->posPixelY < 0x9001) {
    return;
  }
  iVar1 = param_1->posPixelX;

  if(iVar1 < 0xE400)
  {
      if(iVar1 <= 0xB400)
      {
          // 0 - 0xB400
          sub_804539C(param_1, 0, 0xfffffe00);
      }
      else
      {
          // 0xB401 - 0xE3FF
           sub_804539C(param_1, 0xfffffe00, 0);
      }
  }
  else
  {
      if(iVar1 < 0xFC00)
      {
            sub_804539C(param_1, 0, 0xfffffe00);
      }
      else
      {
          if(iVar1 <= 0x11400)
          {
              sub_804539C(param_1, 0x200, 0);
          }
          else
          {
              sub_804539C(param_1, 0, 0xfffffe00);
          }
      }
  }
}

void sub_8089294(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 <= 0x77; iVar1++)
  {
    sub_80855E4(sub_8089224);
    sub_803E46C(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_80892C8(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xf);
  sub_8083E88(0x1a);
  sub_8085374();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_RAYQUAZA);
}

void sub_8089328(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xf);
  sub_8083E88(0x1a);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(SPECIES_RAYQUAZA)) {
    sub_8068FE0(uVar3,0x21c,0);
  }
  else {
    sub_8072008(uVar3,uVar3,gUnknown_80F57CA,0,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_RAYQUAZA);
}

void sub_80893B4(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE9000000U) >> 0x18 < 3) && (param_1 == 0xF)) {
    sub_8097FA8(0xF);
    gDungeonGlobalData->unk2 = 1;
  }
}

void RayquazaPreFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;
  struct DungeonEntity *uVar3;

  iVar1 = sub_8085480();
  uVar2 = sub_808548C();
  uVar3 = sub_8085680(0xf);
  sub_8086448();
  sub_8052910(&gUnknown_8103500);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_810352C);
  sub_80856E0(uVar2,4);
  SpriteLookAroundEffect(uVar2);
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
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  sub_8052910(&gUnknown_8103690);
  sub_8089620(uVar3);
  sub_8052910(&gUnknown_81036C8);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_81037A0);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_81037D4);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_8103820);
  SetupBossFightHP(uVar3,600,0x20);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void RayquazaReFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0xf);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  sub_8052910(&gUnknown_8103690);
  sub_803E708(10,0x46);
  sub_8089620(uVar2);
  sub_8052910(&gUnknown_8103844);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_8103874);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_81038A8);
  RayquazaScreenFlash();
  sub_8052910(&gUnknown_81038F8);
  SetupBossFightHP(uVar2,600,0x20);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  struct DungeonEntity *iVar2;
  struct DungeonEntity *uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0xf);
  sub_8086448();
  if (sub_8086AE4(SPECIES_RAYQUAZA)) {
    sub_80866C4(&gUnknown_8103B58);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    sub_8052910(&gUnknown_8103904);
    sub_8089620(uVar3);
    sub_8052910(&gUnknown_8103938);
    RayquazaScreenFlash();
    sub_8052910(&gUnknown_8103AA4);
    RayquazaScreenFlash();
    sub_8052910(&gUnknown_8103AE4);
    RayquazaScreenFlash();
    sub_8052910(&gUnknown_8103B30);
    SetupBossFightHP(uVar3,600,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_8089620(struct DungeonEntity *param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->entityData->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x600;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 = iVar1 -= 0x18;
    if (iVar1 < 0x14) {
      iVar1 = 0x14;
    }
    if (iVar2 < 0) break;
    param_1->entityData->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  param_1->entityData->unk174 = 0;
}

void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
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
  struct DungeonEntity *iVar1;

  iVar1 = sub_8085480();
  sub_8083E88(0x7D);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY + -3);
}

void sub_808974C(void)
{
  struct DungeonEntity *iVar1;

  iVar1 = sub_8085480();
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY + -3);
}

void sub_8089788(struct DungeonEntity *param_1, u8 param_2, s32 param_3)
{
  struct DungeonEntity *iVar2;
  s32 iVar3;
  u32 unk1;

  unk1 = 0;

  if ((((param_3 * 0x1000000) + 0xe6000000U) >> 0x18) < 2) {
    for(iVar3 = 0; iVar3 < 0x10; iVar3++)
    {
      iVar2 = gDungeonGlobalData->wildPokemon[iVar3];
      if ((sub_80450E0(iVar2) != '\0') && (iVar2 != param_1) && (iVar2->entityData->clientFlags == param_2)) {
        return;
      }
    }
    // WTF is this??
    if(!unk1){
        sub_8097FA8(0x11);
        gDungeonGlobalData->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  struct DungeonEntity *iVar1;

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
  sub_80858AC(&iVar1->posPixelX,0x10);
}



void sub_8089878(void)
{
  struct DungeonEntity *iVar1;

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
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

void sub_80898F8(struct DungeonEntity *r0)
{
    sub_8068FE0(r0, 0x21C, 0);
}

void sub_8089908(struct DungeonEntity *r0)
{
    sub_8085918(r0, 4);
}

void sub_8089914(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x11);
  sub_8083F14();
  gDungeonGlobalData->unk7 = 1;
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_MEWTWO);
}

void sub_8089978(void)
{
  struct DungeonEntity *iVar2;
  struct DungeonEntity *uVar3;

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
    gDungeonGlobalData->unk7 = 1;
    sub_8085918(uVar3,0);
    sub_8086A3C(uVar3);
  }
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_MEWTWO);
}

void sub_8089A00(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xE3000000U) >> 0x18 < 3) && (param_1 == 0x11)) {
    sub_8097FA8(0x13);
    gDungeonGlobalData->unk2 = 1;
  }
}

void MewtwoPreFightDialogue(void)
{
  struct DungeonEntity *iVar1;
  struct DungeonEntity *uVar2;

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
  SetupBossFightHP(uVar2,900,0x20);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void MewtwoPreFightDialogue1(void)
{
  struct DungeonEntity *iVar2;
  struct DungeonEntity *uVar3;

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
    SetupBossFightHP(uVar3,900,0x20);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_8089B64(struct DungeonEntity *param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->entityData->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 0x400;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 = iVar1 -= 11;
    if (iVar1 < 0x1e) {
      iVar1 = 0x1e;
    }
    if (iVar2 < 0) break;
    param_1->entityData->unk174 = iVar2;
    sub_803E46C(0x46);
  }
  param_1->entityData->unk174 = 0;
}

void MewtwoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x1f6);
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
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x12);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ENTEI);
}


void sub_8089C90(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_ENTEI);
}


void sub_8089CFC(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xE0000000U) >> 0x18 < 3) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gDungeonGlobalData->unk2 = 1;
  }
}


void EnteiPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x12);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_8104150);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81041AC);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81041F8);
  sub_803E708(10,70);
  SetupBossFightHP(uVar2,600,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void EnteiPreFightDialogue1(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x12);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_8104240);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81042AC);
  EnteiScreenFlash();
  sub_8052910(&gUnknown_81042B8);
  sub_803E708(10,70);
  SetupBossFightHP(uVar2,600,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void EnteiPreFightDialogue2(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
    SetupBossFightHP(uVar3,600,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
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
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}


void sub_8089F44(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar3, 0);
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}


void sub_8089F8C(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_RAIKOU);
}

void sub_8089FF0(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xdD000000U) >> 0x18 < 3) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gDungeonGlobalData->unk2 = 1;
  }
}


void RaikouPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x13);
  sub_8052910(&gUnknown_8104450);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81044B4);
  gDungeonGlobalData->unkE265 = 4;
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
  SetupBossFightHP(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void RaikouPreFightDialogue1(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  gDungeonGlobalData->unkE265 = 4;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81045F8);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_8104674);
  RaikouScreenFlash();
  sub_8052910(&gUnknown_81046A0);
  sub_803E708(10,70);
  SetupBossFightHP(uVar3,0x28a,0xb);
  sub_80858AC(&iVar2->posPixelX,0x10);
}

void RaikouPreFightDialogue2(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x13);
  if (HasRecruitedMon(SPECIES_RAIKOU)) {
    sub_80866C4(&gUnknown_8104778);
  }
  else {
    gDungeonGlobalData->unkE265 = 4;
    sub_807EAA0(0,1);
    sub_8052910(&gUnknown_81046CC);
    RaikouScreenFlash();
    sub_8052910(&gUnknown_8104744);
    RaikouScreenFlash();
    sub_8052910(&gUnknown_810476C);
    sub_803E708(10,70);
    SetupBossFightHP(uVar3,0x28a,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
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
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A2C0(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar2,0);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A308(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_SUICUNE);
}

void sub_808A36C(char param_1,int param_2)
{
  if ((((param_2 * 0x1000000) + 0xda000000U) >> 0x18 < 3) && (param_1 == 0x14)) {
    sub_8097FA8(0x19);
    gDungeonGlobalData->unk2 = 1;
  }
}

void SuicunePreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

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
  SetupBossFightHP(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void SuicunePreFightDialogue1(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x14);
  sub_8052910(&gUnknown_8104930);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_8104980);
  SuicuneScreenFlash();
  sub_8052910(&gUnknown_8104998);
  sub_803E708(10,70);
  SetupBossFightHP(uVar2,0x28a,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void SuicunePreFightDialogue2(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
    SetupBossFightHP(uVar3,0x28a,0xb);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_808A528(struct DungeonEntity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->entityData->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->entityData->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->entityData->unk174 = 0;
}

void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
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
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x15);
  sub_8083E88(0x1c);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(4);
  sub_8085918(uVar2,0);
  sub_8086A3C(uVar2);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY + -6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_HO_OH);
}

void sub_808A668(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY - 6);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_HO_OH);
}

void sub_808A6E8(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd7000000U) >> 0x18 < 2) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gDungeonGlobalData->unk2 = 1;
  }
}


void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;
  int local_14[2];

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x15);
  local_14[0] = iVar1->posPixelX;
  local_14[1] = iVar1->posPixelY + -0x1000;
  sub_80858AC(local_14,0x88);
  sub_803E708(0x40,70);
  sub_8052910(&gUnknown_8104AD4);
  sub_803E708(10,70);
  HoOhScreenFlash();
  sub_8052910(&gUnknown_8104BEC);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
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
  SetupBossFightHP(uVar2,800,0x20);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void HoOhPreFightDialogue1(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;
  u32 local_14[2];

  iVar2 = sub_8085480();
  uVar3 = sub_8085680(0x15);

  local_14[0] = iVar2->posPixelX;
  local_14[1] = iVar2->posPixelY + -0x1000;
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
    SetupBossFightHP(uVar3,800,0x20);
    sub_80858AC(&iVar2->posPixelX,0x10);
  }
}

void sub_808A904(struct DungeonEntity * param_1)
{
  s32 iVar1;
  s32 iVar2;

  param_1->entityData->unk15E = 0;
  iVar2 = 51200;
  iVar1 = 3072;
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 -= 96;
    if (iVar1 < 20) {
      iVar1 = 20;
    }
    if (iVar2 < 0) break;
    param_1->entityData->unk174 = iVar2;
    sub_803E46C(70);
  }
  param_1->entityData->unk174 = 0;
}

void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
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
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,4);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 4);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AA3C(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8085918(uVar2,4);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AA94(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x16);
  sub_8083E88(0x72);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  sub_8068FE0(uVar2,0x21c,0);
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_LATIOS);
}

void sub_808AAF0(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) + 0xd5000000U) >> 0x18 < 3) && (param_1 == 0x16)) {
    sub_8097FA8(0x1c);
    gDungeonGlobalData->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * iVar2;
  u32 local_18[3];

  iVar1 = sub_8085480();
  iVar2 = sub_8085680(0x16);

  local_18[0] = iVar2->posPixelX;
  local_18[1] = iVar2->posPixelY + (0x80 << 6);
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
  SetupBossFightHP(iVar2,600,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void LatiosReFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

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
  SetupBossFightHP(uVar2,600,0xb);
  sub_80858AC(&iVar1->posPixelX,0x10);
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

  PlaySoundEffect(0x1ee);
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
  struct DungeonEntity * uVar2;

  if (HasRecruitedMon(SPECIES_REGIROCK)) {
    uVar2 = sub_8085680(0x17);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ID_ROCK_PART);
  }
  else {
    if (sub_80860A8(ITEM_ID_ROCK_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(ITEM_ID_MUSIC_BOX) != 0) {
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
  struct DungeonEntity * uVar2;

  if (HasRecruitedMon(SPECIES_REGICE)) {
    uVar2 = sub_8085680(0x18);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ID_ICE_PART);
  }
  else {
    if (sub_80860A8(ITEM_ID_ICE_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(ITEM_ID_MUSIC_BOX) != 0) {
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

  struct DungeonEntity * uVar2;

  if (HasRecruitedMon(SPECIES_REGISTEEL)) {
    uVar2 = sub_8085680(0x19);
    sub_8068FE0(uVar2,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ID_STEEL_PART);
  }
  else {
    if (sub_80860A8(ITEM_ID_STEEL_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
    }
    else
    {
      if (sub_80860A8(ITEM_ID_MUSIC_BOX) != 0) {
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
  struct DungeonEntity * uVar3;
  u8 auStack24 [4];
  struct ItemSlot auStack20;


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&auStack20,ITEM_ID_ROCK_PART,0);
      sub_80464C8(sub_8083600(),param_3,&auStack20);
      sub_8083E88(0x72);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      sub_8052910(&gUnknown_8105040);
    }
  }
}


void sub_808AEC8(char param_1,char param_2,u32 param_3)
{
  struct DungeonEntity * uVar3;
  u8 auStack24 [4];
  struct ItemSlot auStack20;


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&auStack20,ITEM_ID_ICE_PART,0);
      sub_80464C8(sub_8083600(),param_3,&auStack20);
      sub_8083E88(0x72);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      sub_8052910(&gUnknown_810510C);
    }
  }
}

void sub_808AF3C(char param_1,char param_2,u32 param_3)
{
  struct DungeonEntity * uVar3;
  u8 auStack24 [4];
  struct ItemSlot auStack20;


  uVar3 = sub_8085480();
  sub_8052D44(auStack24,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(0);
    if (sub_8098100(0x1d) == 0) {
      xxx_init_itemslot_8090A8C(&auStack20,ITEM_ID_STEEL_PART,0);
      sub_80464C8(sub_8083600(),param_3, &auStack20);
      sub_8083E88(0x72);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      sub_8052910(&gUnknown_81051D0);
    }
  }
}

void sub_808AFB0(char param_1)
{
  struct DungeonEntity * uVar3;
  u8 auStack12 [4];

  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2E) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ID_ROCK_PART) != 0)) {
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
  struct DungeonEntity * uVar3;
  u8 auStack12 [4];

  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x2F) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ID_ICE_PART) != 0)) {
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
  struct DungeonEntity * uVar3;
  u8 auStack12 [4];

  uVar3 = sub_8085480();
  sub_8052D44(auStack12,uVar3,0);
  if ((sub_8098100(0x22) == 0) && (param_1 == 0x30) && (sub_8098100(0x1d) == 0) && (sub_80860A8(ITEM_ID_STEEL_PART) != 0)) {
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
"_0808B21C: .4byte gDungeonGlobalData\n"
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
	"\tbl xxx_init_itemslot_8090A8C\n"
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


void sub_808B2B0(struct DungeonEntity *r0)
{
    r0->entityData->facingDir = DIRECTION_NORTH;
    sub_806CE68(r0, 4);
}


void sub_808B2C4(struct DungeonEntity *r0)
{
    SetupBossFightHP(r0, 0xE1 << 1, 0xB);
}


void sub_808B2D4(struct DungeonEntity *r0)
{
    SetupBossFightHP(r0, 0xE1 << 1, 0xB);
}


void sub_808B2E4(struct DungeonEntity *r0)
{
    SetupBossFightHP(r0, 0xE1 << 1, 0xB);
}

void sub_808B2F4(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

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
  sub_8085860(iVar1->posWorldX,iVar1->posWorldY - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
}

void sub_808B35C(void)
{
  struct DungeonEntity * iVar2;
  struct DungeonEntity * uVar3;

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
  sub_8085860(iVar2->posWorldX,iVar2->posWorldY - 3);
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
      gDungeonGlobalData->unk2 = 1;
    }
    else {
      uVar1 = gDungeonGlobalData->unk1356C;
      if (sub_80860A8(0x36) != 0) {
           JirachiWish();
      }
      else {
          sub_808B50C();
      }
      gDungeonGlobalData->unk1356C = uVar1;
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
"_0808B414: .4byte gDungeonGlobalData\n"
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
"_0808B434: .4byte gDungeonGlobalData\n"
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
"_0808B454: .4byte gDungeonGlobalData\n"
"_0808B458: .4byte 0x0001356c");
}
#endif

void JirachiPreFightDialogue(void)
{
  struct DungeonEntity * iVar1;
  struct DungeonEntity * uVar2;

  iVar1 = sub_8085480();
  uVar2 = sub_8085680(0x1a);
  sub_8086448();
  sub_803E708(0x40,70);
  sub_8052910(&gUnknown_8105438);
  sub_803E708(10,70);
  SpriteLookAroundEffect(iVar1);
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
  SetupBossFightHP(uVar2,0x15e,0x20);
  sub_80858AC(&iVar1->posPixelX,0x10);
}

void sub_808B50C(void)
{
  struct DungeonEntity * iVar1;

  iVar1 = sub_8085680(0x1a);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(iVar1);
  sub_8041888(0);
  iVar1->entityData->unk15C = 1;
  iVar1->entityData->unk15E = 0;
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
  gDungeonGlobalData->unk2 = 1;
}
