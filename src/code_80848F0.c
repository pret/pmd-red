#include "global.h"
#include "structs/str_dungeon.h"
#include "dungeon_music.h"
#include "exclusive_pokemon.h"

extern void SkarmoryPreFightDialogue();
extern void SkarmoryReFightDialogue();
extern void sub_8086E40();
extern void TeamMeaniesPreFightDialogue();
extern void TeamMeaniesReFightDialogue();
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
extern void MewtwoReFightDialogue();
extern void EnteiPreFightDialogue();
extern void EnteiReFightDialogue();
extern void EnteiPostStoryPreFightDialogue();
extern void RaikouPreFightDialogue();
extern void RaikouReFightDialogue();
extern void RaikouPostStoryPreFightDialogue();
extern void SuicunePreFightDialogue();
extern void SuicuneReFightDialogue();
extern void SuicunePostStoryPreFightDialogue();
extern void HoOhPreFightDialogue();
extern void HoOhReFightDialogue();
extern void LatiosPreFightDialogue();
extern void LatiosReFightDialogue();
extern void sub_808AC3C();
extern void RegirockPreFightDialogue();
extern void RegicePreFightDialogue();
extern void RegisteelPreFightDialogue();
extern void JirachiPreFightDialogue();
extern void JirachiReFightDialogue();
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

extern void sub_8086BDC(u32,u8);
extern void sub_8086F54(u32,u8);
extern void sub_8087334(u32,u8);
extern void sub_80878F4(u32,u8);
extern void sub_8088088(u32,u8);
extern void sub_8088818(u32,u8);
extern void sub_80893B4(u32,u8);
extern void sub_8089788(Entity *,u32,u8);
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
extern void sub_808C948(Entity *,u8);

extern void sub_808AFB0(u8);
extern void sub_808B030(u8);
extern void sub_808B0B0(u8);

extern void sub_8086B14(void);
extern void sub_8086B94(void);
extern void sub_8086E9C(void);
extern void sub_8086F00(void);
extern void sub_8087230(void);
extern void sub_808729C(void);
extern void sub_80877E8(void);
extern void sub_8087848(void);
extern void sub_8087F54(void);
extern void sub_8087FB4(void);
extern void sub_8087FF8(void);
extern void sub_80885A0(void);
extern void sub_80885C4(void);
extern void sub_808862C(void);
extern void sub_80886C4(void);
extern void sub_808875C(void);
extern void sub_8088DC0(void);
extern void sub_8088E5C(void);
extern void sub_80892C8(void);
extern void sub_8089328(void);
extern void sub_808970C(void);
extern void sub_808974C(void);
extern void sub_8089914(void);
extern void sub_8089978(void);
extern void sub_8089C44(void);
extern void sub_8089C90(void);
extern void sub_8089EFC(void);
extern void sub_8089F44(void);
extern void sub_8089F8C(void);
extern void sub_808A264(void);
extern void sub_808A2C0(void);
extern void sub_808A308(void);
extern void sub_808A608(void);
extern void sub_808A668(void);
extern void sub_808A9E4(void);
extern void sub_808AA3C(void);
extern void sub_808AA94(void);
extern void sub_808ACC0(void);
extern void sub_808AD48(void);
extern void sub_808ADCC(void);
extern void sub_808B2F4(void);
extern void sub_808B35C(void);
extern void sub_808BDEC(void);
extern void sub_808C10C(void);
extern void sub_808C3A0(void);
extern void sub_808C5C0(void);
extern void sub_808C938(void);
extern void sub_808C9C4(void);
extern void sub_808CB5C(void);
extern void sub_808CBB0(void);
extern void sub_808CD44(void);

extern void sub_807E5E4(u32);

void sub_8084854(u8 *param_1)
{
  if (gDungeon->unk678 != 0) {
       gDungeon->unk3A0D = param_1[5];
  }
  else
  {
    if (sub_8098100(param_1[4]) != 0) {
        gDungeon->unk3A0D = param_1[5];
    }
    else
    {
      if (sub_8098100(param_1[2]) != 0) {
        gDungeon->unk3A0D = param_1[3];
      }
      else
      {
        gDungeon->unk3A0D = param_1[1];
        if (param_1[2] != 0x40) {
          sub_8097FA8(param_1[2]);
        }
      }
    }
  }
  gDungeon->unk675 = 1;
  sub_807E5E4(0);
}

u32 sub_80848EC(void)
{
    return 1;
}

void sub_80848F0(void)
{
  gDungeon->unk1356C = 1;
  switch(gDungeon->unk3A0D) {
    case 0:
    case 0x3c:
        gDungeon->unk1356C = 0;
        break;
    case 1:
    case 2:
        sub_8086B14();
        break;
    case 3:
        sub_8086B94();
        break;
    case 4:
    case 5:
        sub_8086E9C();
        break;
    case 6:
        sub_8086F00();
        break;
    case 7:
    case 8:
        sub_8087230();
        break;
    case 9:
        sub_808729C();
        break;
    case 10:
    case 0xb:
        sub_80877E8();
        break;
    case 0xc:
        sub_8087848();
        break;
    case 0xd:
        sub_8087F54();
        break;
    case 0xe:
        sub_8087FB4();
        break;
    case 0xf:
        sub_8087FF8();
        break;
    case 0x10:
        sub_80885A0();
        break;
    case 0x11:
        sub_80885C4();
        break;
    case 0x12:
        sub_808862C();
        break;
    case 0x13:
        sub_80886C4();
        break;
    case 0x14:
        sub_808875C();
        break;
    case 0x15:
        sub_8088DC0();
        break;
    case 0x16:
        sub_8088E5C();
        break;
    case 0x17:
    case 0x18:
        sub_80892C8();
        break;
    case 0x19:
        sub_8089328();
        break;
    case 0x1a:
    case 0x1b:
        sub_808970C();
        break;
    case 0x1c:
        sub_808974C();
        break;
    case 0x1d:
    case 0x1e:
        sub_8089914();
        break;
    case 0x1f:
        sub_8089978();
        break;
    case 0x20:
    case 0x21:
        sub_8089C44();
        break;
    case 0x22:
        sub_8089C90();
        break;
    case 0x23:
        sub_8089EFC();
        break;
    case 0x24:
        sub_8089F44();
        break;
    case 0x25:
        sub_8089F8C();
        break;
    case 0x26:
        sub_808A264();
        break;
    case 0x27:
        sub_808A2C0();
        break;
    case 0x28:
        sub_808A308();
        break;
    case 0x29:
        sub_808A608();
        break;
    case 0x2a:
        sub_808A668();
        break;
    case 0x2b:
        sub_808A9E4();
        break;
    case 0x2c:
        sub_808AA3C();
        break;
    case 0x2d:
        sub_808AA94();
        break;
    case 0x2e:
        sub_808ACC0();
        break;
    case 0x2f:
        sub_808AD48();
        break;
    case 0x30:
        sub_808ADCC();
        break;
    case 0x31:
        sub_808B2F4();
        break;
    case 0x32:
        sub_808B35C();
        break;
    case 0x33:
        sub_808BDEC();
        break;
    case 0x34:
        sub_808C10C();
        break;
    case 0x35:
        sub_808C3A0();
        break;
    case 0x36:
        sub_808C5C0();
        break;
    case 0x37:
        sub_808C938();
        break;
    case 0x38:
        sub_808C9C4();
        break;
    case 0x39:
        sub_808CB5C();
        break;
    case 0x3a:
        sub_808CBB0();
        break;
    case 0x3b:
        sub_808CD44();
        break;
  }
  sub_8097FF8();
}

void DisplayPreFightDialogue(void)
{
  switch(gDungeon->unk3A0D) {
      case 0:
        break;
      case 1:
        SkarmoryPreFightDialogue();
        break;
      case 2:
        SkarmoryReFightDialogue();
        break;
      case 3:
        sub_8086E40();
        break;
      case 4:
        TeamMeaniesPreFightDialogue();
        break;
      case 5:
        TeamMeaniesReFightDialogue();
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
        MewtwoReFightDialogue();
        break;
      case 0x20:
        EnteiPreFightDialogue();
        break;
      case 0x21:
        EnteiReFightDialogue();
        break;
      case 0x22:
        EnteiPostStoryPreFightDialogue();
        break;
      case 0x23:
        RaikouPreFightDialogue();
        break;
      case 0x24:
        RaikouReFightDialogue();
        break;
      case 0x25:
        RaikouPostStoryPreFightDialogue();
        break;
      case 0x26:
        SuicunePreFightDialogue();
        break;
      case 0x27:
        SuicuneReFightDialogue();
        break;
      case 0x28:
        SuicunePostStoryPreFightDialogue();
        break;
      case 0x29:
        HoOhPreFightDialogue();
        break;
      case 0x2a:
        HoOhReFightDialogue();
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
        JirachiReFightDialogue();
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
  gDungeon->unk1356C = 0;
  sub_8097FF8();
}

void sub_8084E00(Entity *entity, u8 param_2, u8 param_3)
{
  if (param_2 != 0) {
    switch(gDungeon->unk3A0D) {
        case 0:
            break;
        case 1:
        case 2:
            sub_8086BDC(param_2,gDungeon->unk3A0D);
            break;
        case 4:
        case 5:
            sub_8086F54(param_2,gDungeon->unk3A0D);
            break;
        case 7:
        case 8:
        case 9:
            sub_8087334(param_2,gDungeon->unk3A0D);
            break;
        case 10:
        case 0xb:
        case 0xc:
            sub_80878F4(param_2,gDungeon->unk3A0D);
            break;
        case 0xd:
        case 0xe:
        case 0xf:
            sub_8088088(param_2,gDungeon->unk3A0D);
            break;
        case 0x12:
        case 0x13:
        case 0x14:
            sub_8088818(param_2,gDungeon->unk3A0D);
            break;
        case 0x17:
        case 0x18:
        case 0x19:
            sub_80893B4(param_2,gDungeon->unk3A0D);
            break;
        case 0x1a:
        case 0x1b:
            sub_8089788(entity,param_2,gDungeon->unk3A0D);
            break;
        case 0x1d:
        case 0x1e:
        case 0x1f:
            sub_8089A00(param_2,gDungeon->unk3A0D);
            break;
        case 0x20:
        case 0x21:
        case 0x22:
            sub_8089CFC(param_2,gDungeon->unk3A0D);
            break;
        case 0x23:
        case 0x24:
        case 0x25:
            sub_8089FF0(param_2,gDungeon->unk3A0D);
            break;
        case 0x26:
        case 0x27:
        case 0x28:
            sub_808A36C(param_2,gDungeon->unk3A0D);
            break;
        case 0x29:
        case 0x2a:
            sub_808A6E8(param_2,gDungeon->unk3A0D);
            break;
        case 0x2b:
        case 0x2c:
        case 0x2d:
            sub_808AAF0(param_2,gDungeon->unk3A0D);
            break;
        case 0x2e:
            sub_808AE54(param_2,gDungeon->unk3A0D,&entity->pos.x);
            break;
        case 0x2f:
            sub_808AEC8(param_2,gDungeon->unk3A0D,&entity->pos.x);
            break;
        case 0x30:
            sub_808AF3C(param_2,gDungeon->unk3A0D,&entity->pos.x);
            break;
        case 0x31:
        case 0x32:
            sub_808B3E4(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x33:
            sub_808BE70(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x34:
            sub_808C1A4(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x35:
            sub_808C414(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x36:
            nullsub_100(param_2,gDungeon->unk3A0D,param_3);
            break;
        case 0x37:
            sub_808C948(entity,gDungeon->unk3A0D);
            break;
        case 0x38:
        case 0x39:
        case 0x3A:
        case 0x3B:
        case 0x3C:
            break;
    }
    if ((param_3 == 0) && (gDungeon->unk2 != 0)) {
      DungeonStartNewBGM(999);
    }
  }
}

void sub_8085140(void)
{
    switch(gDungeon->unk3A0D) {
        // NOTE: shortcut way to generate all cases from 0 - 0x3C properly
        default:
        case 0:
        case 1:
        case 0x3C:
            break;
        case 0x2e:
            sub_808AFB0(gDungeon->unk3A0D);
            break;
        case 0x2f:
            sub_808B030(gDungeon->unk3A0D);
            break;
        case 0x30:
            sub_808B0B0(gDungeon->unk3A0D);
            break;
  }
}
