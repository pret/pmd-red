#include "global.h"
#include "dungeon_global_data.h"

extern struct DungeonGlobalData *gDungeonGlobalData;

extern void SkarmonyPreFightDialogue();
extern void SkarmonyReFightDialogue();
extern void sub_8086E40();
extern void TeamMeaniePreFightDialogue();
extern void TeamMeanieReFightDialogue();
extern void sub_8087130();
extern void ZapdosPreFightDialogue();
extern void ZapdosReFightDialogue();
extern void ZapdosPostStoryPreFightDialogue();
extern void MoltresPreFightDialogue();
extern void MoltresReFightDialogue();
extern void MoltresPostStoryPreFightDialogue();
extern void ArticunoPreFightDialogue();
extern void ArticunoReFightDialogue();
extern void ArticunoPostStoryPreFightDialogue();
extern void sub_8088608();
extern void sub_8088618();
extern void GroudonPreFightDialogue();
extern void GroudonReFightDialogue();
extern void GroudonPostStoryPreFightDialogue();
extern void MagmaCavernMidDialogue();
extern void sub_8089168();
extern void RayquazaPreFightDialogue();
extern void RayquazaReFightDialogue();
extern void RayquazaPostStoryPreFightDialogue();
extern void sub_80897F0();
extern void sub_8089878();
extern void sub_80898E4();
extern void MewtwoPreFightDialogue();
extern void MewtwoPreFightDialogue1();
extern void EnteiPreFightDialogue();
extern void EnteiPreFightDialogue1();
extern void EnteiPreFightDialogue2();
extern void RaikouPreFightDialogue();
extern void RaikouPreFightDialogue1();
extern void RaikouPreFightDialogue2();
extern void SuicunePreFightDialogue();
extern void SuicunePreFightDialogue1();
extern void SuicunePreFightDialogue2();
extern void HoOhPreFightDialogue();
extern void HoOhPreFightDialogue1();
extern void LatiosPreFightDialogue();
extern void LatiosReFightDialogue();
extern void sub_808AC3C();
extern void RegirockPreFightDialogue();
extern void RegicePreFightDialogue();
extern void RegisteelPreFightDialogue();
extern void JirachiPreFightDialogue();
extern void JirachiPreFightDialogue1();
extern void LugiaPreFightDialogue();
extern void KyogrePreFightDialogue();
extern void DeoxysPreFightDialogue();
extern void CelebiJoinDialogue();
extern void sub_808C998();
extern void MedichamRescueDialogue();
extern void DummyFightDialogue();
extern void SmeargleRescueDialogue();
extern void sub_808CD9C();
extern void sub_8085764();
extern void sub_80857B8();
extern void sub_8097FF8();

extern void sub_8086BDC(u32,u8);
extern void sub_8086F54(u32,u8);
extern void sub_8087334(u32,u8);
extern void sub_80878F4(u32,u8);
extern void sub_8088088(u32,u8);
extern void sub_8088818(u32,u8);
extern void sub_80893B4(u32,u8);
extern void sub_8089788(struct DungeonEntity *,u32,u8);
extern void sub_8089A00(u32,u8);
extern void sub_8089CFC(u32,u8);
extern void sub_8089FF0(u32,u8);
extern void sub_808A36C(u32,u8);
extern void sub_808A6E8(u32,u8);
extern void sub_808AAF0(u32,u8);
extern void sub_808AE54(u32,u8,s16 *);
extern void sub_808AEC8(u32,u8,s16 *);
extern void sub_808AF3C(u32,u8,s16 *);
extern void sub_808B3E4(u32,u8,u8);
extern void sub_808BE70(u32,u8,u8);
extern void sub_808C1A4(u32,u8,u8);
extern void sub_808C414(u32,u8,u8);
extern void nullsub_100(u32,u8,u8);
extern void sub_808C948(struct DungeonEntity *,u8);
extern void sub_8083E88(u32);

extern void sub_808AFB0(u8);
extern void sub_808B030(u8);
extern void sub_808B0B0(u8);


void DisplayPreFightDialogue(void)
{
  
  switch(gDungeonGlobalData->unk3A0D) {
      case 0:
        break;
      case 1:
        SkarmonyPreFightDialogue();
        break;
      case 2:
        SkarmonyReFightDialogue();
        break;
      case 3:
        sub_8086E40();
        break;
      case 4:
        TeamMeaniePreFightDialogue();
        break;
      case 5:
        TeamMeanieReFightDialogue();
        break;
      case 6:
        sub_8087130();
        break;
      case 7:
        ZapdosPreFightDialogue();
        break;
      case 8:
        ZapdosReFightDialogue();
        break;
      case 9:
        ZapdosPostStoryPreFightDialogue();
        break;
      case 10:
        MoltresPreFightDialogue();
        break;
      case 0xb:
        MoltresReFightDialogue();
        break;
      case 0xc:
        MoltresPostStoryPreFightDialogue();
        break;
      case 0xd:
        ArticunoPreFightDialogue();
        break;
      case 0xe:
        ArticunoReFightDialogue();
        break;
      case 0xf:
        ArticunoPostStoryPreFightDialogue();
        break;
      case 0x10:
        sub_8088608();
        break;
      case 0x11:
        sub_8088618();
        break;
      case 0x12:
        GroudonPreFightDialogue();
        break;
      case 0x13:
        GroudonReFightDialogue();
        break;
      case 0x14:
        GroudonPostStoryPreFightDialogue();
        break;
      case 0x15:
        MagmaCavernMidDialogue();
        break;
      case 0x16:
        sub_8089168();
        break;
      case 0x17:
        RayquazaPreFightDialogue();
        break;
      case 0x18:
        RayquazaReFightDialogue();
        break;
      case 0x19:
        RayquazaPostStoryPreFightDialogue();
        break;
      case 0x1a:
        sub_80897F0();
        break;
      case 0x1b:
        sub_8089878();
        break;
      case 0x1c:
        sub_80898E4();
        break;
      case 0x1d:
      case 0x1e:
        MewtwoPreFightDialogue();
        break;
      case 0x1f:
        MewtwoPreFightDialogue1();
        break;
      case 0x20:
        EnteiPreFightDialogue();
        break;
      case 0x21:
        EnteiPreFightDialogue1();
        break;
      case 0x22:
        EnteiPreFightDialogue2();
        break;
      case 0x23:
        RaikouPreFightDialogue();
        break;
      case 0x24:
        RaikouPreFightDialogue1();
        break;
      case 0x25:
        RaikouPreFightDialogue2();
        break;
      case 0x26:
        SuicunePreFightDialogue();
        break;
      case 0x27:
        SuicunePreFightDialogue1();
        break;
      case 0x28:
        SuicunePreFightDialogue2();
        break;
      case 0x29:
        HoOhPreFightDialogue();
        break;
      case 0x2a:
        HoOhPreFightDialogue1();
        break;
      case 0x2b:
        LatiosPreFightDialogue();
        break;
      case 0x2c:
        LatiosReFightDialogue();
        break;
      case 0x2d:
        sub_808AC3C();
        break;
      case 0x2e:
        RegirockPreFightDialogue();
        break;
      case 0x2f:
        RegicePreFightDialogue();
        break;
      case 0x30:
        RegisteelPreFightDialogue();
        break;
      case 0x31:
        JirachiPreFightDialogue();
        break;
      case 0x32:
        JirachiPreFightDialogue1();
        break;
      case 0x33:
        LugiaPreFightDialogue();
        break;
      case 0x34:
        KyogrePreFightDialogue();
        break;
      case 0x35:
        DeoxysPreFightDialogue();
        break;
      case 0x36:
        CelebiJoinDialogue();
        break;
      case 0x37:
        sub_808C998();
        break;
      case 0x38:
        MedichamRescueDialogue();
        break;
      case 0x39:
        DummyFightDialogue();
        break;
      case 0x3a:
        SmeargleRescueDialogue();
        break;
      case 0x3b:
        sub_808CD9C();
        break;
      case 0x3C:
        break;
  }
  sub_8085764();
  sub_80857B8();
  gDungeonGlobalData->unk1356C = 0;
  sub_8097FF8();
}

void sub_8084E00(struct DungeonEntity *param_1,char param_2,char param_3)
{

  if (param_2 != '\0') {
    switch(gDungeonGlobalData->unk3A0D) {
        case 0:
            break;
        case 1:
        case 2:
            sub_8086BDC(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 4:
        case 5:
            sub_8086F54(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 7:
        case 8:
        case 9:
            sub_8087334(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 10:
        case 0xb:
        case 0xc:
            sub_80878F4(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0xd:
        case 0xe:
        case 0xf:
            sub_8088088(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x12:
        case 0x13:
        case 0x14:
            sub_8088818(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x17:
        case 0x18:
        case 0x19:
            sub_80893B4(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x1a:
        case 0x1b:
            sub_8089788(param_1,param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x1d:
        case 0x1e:
        case 0x1f:
            sub_8089A00(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x20:
        case 0x21:
        case 0x22:
            sub_8089CFC(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            sub_8089FF0(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x26:
        case 0x27:
        case 0x28:
            sub_808A36C(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x29:
        case 0x2a:
            sub_808A6E8(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x2b:
        case 0x2c:
        case 0x2d:
            sub_808AAF0(param_2,gDungeonGlobalData->unk3A0D);
            break;
        case 0x2e:
            sub_808AE54(param_2,gDungeonGlobalData->unk3A0D,&param_1->posWorldX);
            break;
        case 0x2f:
            sub_808AEC8(param_2,gDungeonGlobalData->unk3A0D,&param_1->posWorldX);
            break;
        case 0x30:
            sub_808AF3C(param_2,gDungeonGlobalData->unk3A0D,&param_1->posWorldX);
            break;
        case 0x31:
        case 0x32:
            sub_808B3E4(param_2,gDungeonGlobalData->unk3A0D,param_3);
            break;
        case 0x33:
            sub_808BE70(param_2,gDungeonGlobalData->unk3A0D,param_3);
            break;
        case 0x34:
            sub_808C1A4(param_2,gDungeonGlobalData->unk3A0D,param_3);
            break;
        case 0x35:
            sub_808C414(param_2,gDungeonGlobalData->unk3A0D,param_3);
            break;
        case 0x36:
            nullsub_100(param_2,gDungeonGlobalData->unk3A0D,param_3);
            break;
        case 0x37:
            sub_808C948(param_1,gDungeonGlobalData->unk3A0D);
            break;
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
            break;
    }
    if ((param_3 == '\0') && (gDungeonGlobalData->unk2 != '\0')) {
      sub_8083E88(999);
    }
  }
}

void sub_8085140(void)
{
    switch(gDungeonGlobalData->unk3A0D) {
        // NOTE: shortcut way to generate all cases from 0 - 0x3C properly
        default:
        case 0:
        case 1:
        case 0x3C:
            break;
        case 0x2e:
            sub_808AFB0(gDungeonGlobalData->unk3A0D);
            break;
        case 0x2f:
            sub_808B030(gDungeonGlobalData->unk3A0D);
            break;
        case 0x30:
            sub_808B0B0(gDungeonGlobalData->unk3A0D);
            break;
  }
}
