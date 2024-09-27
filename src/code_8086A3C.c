#include "global.h"
#include "code_8086A3C.h"

#include "code_803E46C.h"
#include "code_803E668.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/monster.h"
#include "dungeon_music.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"

extern u8 sub_8044B28(void);
extern u8 gUnknown_202E038[];
extern void sub_8085374();
extern void sub_8068FE0(Entity *, u32, u32);
extern void DisplayDungeonDialogue(const u8 *);
extern void sub_8086448(void);
extern void SkarmoryEntry(Entity *);
extern void sub_8086A54(Entity *);
extern void sub_8087144();
extern void sub_8072008(Entity *pokemon, Entity *r1, u32 r2, u8 r3, u32);
extern bool8 sub_8085B80(struct_8085B80 *);

extern const u8 gUnknown_810739C[];
extern const u8 gUnknown_81073D4[];
extern const u8 gUnknown_810740C[];
extern const s16 gUnknown_80F57CC;
extern const u8 gUnknown_8101440[];
extern const u8 gSkarmoryPreFightDialogue_1[];
extern const u8 gSkarmoryPreFightDialogue_2[];
extern const u8 gSkarmoryPreFightDialogue_3[];
extern const u8 gSkarmoryPreFightDialogue_4[];
extern const u8 gSkarmoryPreFightDialogue_5[];
extern const u8 gSkarmoryPreFightDialogue_6[];
extern const u8 gSkarmoryPreFightDialogue_7[];
extern const u8 gSkarmoryPreFightDialogue_8[];
extern const u8 gSkarmoryPreFightDialogue_9[];
extern const u8 gSkarmoryReFightDialogue_1[];
extern const u8 gSkarmoryReFightDialogue_2[];
extern const u8 gSkarmoryReFightDialogue_3[];
extern const u8 gTeamMeaniesPreFightDialogue_1[];
extern const u8 gTeamMeaniesPreFightDialogue_2[];
extern const u8 gTeamMeaniesPreFightDialogue_3[];
extern const u8 gTeamMeaniesPreFightDialogue_4[];
extern const u8 gTeamMeaniesPreFightDialogue_5[];
extern const u8 gTeamMeaniesPreFightDialogue_6[];
extern const u8 gTeamMeaniesPreFightDialogue_7[];
extern const u8 gTeamMeaniesReFightDialogue_1[];
extern const u8 gTeamMeaniesReFightDialogue_2[];
extern const u8 gTeamMeaniesReFightDialogue_3[];
extern const u8 gTeamMeaniesReFightDialogue_4[];
extern const u8 gTeamMeaniesReFightDialogue_5[];

extern const u8 gUnknown_8100D3C[];

void sub_8086A3C(Entity *pokemon)
{
    pokemon->axObj.info->unk15C = 1;
    pokemon->axObj.info->unk15E = 1;
}

void sub_8086A54(Entity *pokemon)
{
    pokemon->axObj.info->unk15C = 1;
    pokemon->axObj.info->unk15E = 0;
}

void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex)
{

  // NOTE: needed two of these to match.. very dumb
  EntityInfo *entityInfo;
  EntityInfo *enityData_1;

  entityInfo = pokemon->axObj.info;
  enityData_1 = pokemon->axObj.info;

  entityInfo->bossFlag = TRUE;

  // BUG: Source of the Reviver Seed Boss Glitch
  //
  // Video to demonstration:
  // https://www.youtube.com/watch?v=rHu7EehrZ68
  entityInfo->originalHP = entityInfo->maxHPStat;
  if (newHP != 0) {
    entityInfo->maxHPStat = newHP;
    entityInfo->HP = newHP;
  }

  gDungeon->bossSongIndex = songIndex;
  SetDefaultIQSkills(enityData_1->IQSkillMenuFlags, enityData_1->bossFlag);
  LoadIQSkills(pokemon);
}

void sub_8086AC0(void)
{
    if(!sub_8044B28())
        if(gDungeon->unk2 == 0)
            sub_8097FF8();
}

u8 sub_8086AE4(s16 _index)
{
    s32 pokeIndex = _index;

    if(gDungeon->unk65C == 0)
        return 1;
    else
        return HasRecruitedMon(pokeIndex);
}

void sub_8086B14(void)
{
  Entity * LeaderEntity;
  Entity * DiglettEntity;
  Entity * SkarmoryEntity;

  LeaderEntity = xxx_call_GetLeader();
  DiglettEntity = GetEntityFromClientType(4);
  SkarmoryEntity = GetEntityFromClientType(3);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(SkarmoryEntity);
  DiglettEntity->axObj.info->unk15C = 1;
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 2);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_DIGLETT);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_SKARMORY);
}

void sub_8086B94(void)
{
  Entity * LeaderEntity;
  Entity * DiglettEntity;
  Entity * SkarmoryEntity;

  LeaderEntity = xxx_call_GetLeader();
  DiglettEntity = GetEntityFromClientType(4);
  SkarmoryEntity = GetEntityFromClientType(3);

  sub_8068FE0(SkarmoryEntity,0x21c,0);
  sub_8068FE0(DiglettEntity,0x21c,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y);
}

void sub_8086BDC(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) - 0x1000000U) >> 0x18 < 2) && (param_1 == 3)) {
    sub_8097FA8(1);
    gDungeon->unk2 = 1;
  }
}

void SkarmoryPreFightDialogue(void)
{
  Entity *LeaderEntity;
  Entity *PartnerEntity;
  Entity * DiglettEntity;
  Entity * SkarmoryEntity;

  Position32 pos1;
  Position32 pos2;

  LeaderEntity = xxx_call_GetLeader(); // Player
  PartnerEntity = GetPartnerEntity(); // Partner
  DiglettEntity = GetEntityFromClientType(4); // Diglett
  SkarmoryEntity = GetEntityFromClientType(3); // Skarmory

  pos1.x = DiglettEntity->pixelPos.x;
  pos1.y = DiglettEntity->pixelPos.y + 0x3000;

  pos2.x = SkarmoryEntity->pixelPos.x;
  pos2.y = SkarmoryEntity->pixelPos.y + 0x2000;

  sub_8086448();
  sub_803E708(10,0x46);
  SpriteShockEffect(PartnerEntity);
  sub_803E708(0x20,0x46);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&pos1,0x40);
  sub_803E708(0x40,0x46);
  ShiftCameraToPosition(&pos2,0x30);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_2);
  sub_803E708(10,0x46);
  DiglettEntity->axObj.info->unk15D = 1;
  ShiftCameraToPosition(&pos1,0x30);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&pos2,0x20);
  sub_803E708(0x20,0x46);
  SkarmoryEntry(SkarmoryEntity);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_4); // Skarmory: You!\nWhat do you think you're doing here?!
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_806CDD4(SkarmoryEntity,0xd,0);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_8);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_9);
  sub_80869E4(PartnerEntity,4,2,4);
  sub_80869E4(LeaderEntity,4,1,4);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SkarmoryReFightDialogue(void)
{
  Entity * LeaderEntity;
  Entity * SkarmoryEntity;
  Position32 pos;

  LeaderEntity = xxx_call_GetLeader();
  SkarmoryEntity = GetEntityFromClientType(3);
  pos.x = SkarmoryEntity->pixelPos.x;
  pos.y = SkarmoryEntity->pixelPos.y + 0x2000;
  sub_8086448();
  sub_803E708(10,0x46);
  SkarmoryEntry(SkarmoryEntity);
  ShiftCameraToPosition(&pos,0x10);
  DisplayDungeonDialogue(gSkarmoryReFightDialogue_1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_806CDD4(SkarmoryEntity,0xd,0);
  DisplayDungeonDialogue(gSkarmoryReFightDialogue_3);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
}

void sub_8086E40(void)
{
  SpriteLookAroundEffect(xxx_call_GetLeader());
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gUnknown_8100D3C);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void SkarmoryEntry(Entity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,0);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  sub_803E708(0x44,0x46);
}

void sub_8086E9C(void)
{
  Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8086A3C);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_METAPOD);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_GENGAR);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0xA0, MONSTER_CATERPIE);
}

void sub_8086F00(void)
{
  Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_METAPOD);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_GENGAR);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0xA0, MONSTER_CATERPIE);
}

// From @jiangzhengwenjz:
// Matches this way for -O2 but can match w/o this hack on -O1
// https://decomp.me/scratch/BTqWo
void sub_8086F54(u8 param_1, u8 param_2)
{
  Entity *entity;
  s32 index;
  u32 unk1 = 0;


  if (param_2 == 4 || param_2 == 5) {
    void *labels[2];
    labels[0] = labels[1] = &&label;

    for(index = 0; index < 0x10; index++)
    {
      entity = gDungeon->wildPokemon[index];
      if ((EntityExists(entity)) && (entity->axObj.info->clientType != param_1)) {
        return;
      }
    }
    if(!unk1)
    {
      sub_8097FA8(3);
    label:
      gDungeon->unk2 = 1;
    }
  }
}

void TeamMeaniesPreFightDialogue(void)
{
    Entity *LeaderEntity;

    LeaderEntity = xxx_call_GetLeader();
    sub_8086448();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_3);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_4);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_5);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_6);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_7);
    sub_803E708(10, 0x46);
    ShiftCameraToPosition(&LeaderEntity->pixelPos, 0x10);
}

void TeamMeaniesReFightDialogue(void)
{
    Entity *LeaderEntity;
    Entity *PartnerEntity;

    LeaderEntity = xxx_call_GetLeader();
    PartnerEntity = GetPartnerEntity();
    sub_8086448();
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_2);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_3);
    sub_803E708(10, 0x46);
    sub_806CDD4(LeaderEntity, 6, 4);
    sub_806CDD4(PartnerEntity, 6, 4);
    sub_803E708(10, 0x46);
    sub_806CDD4(LeaderEntity, 7, 4);
    sub_806CDD4(PartnerEntity, 7, 4);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_4);
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_5);
    sub_803E708(10, 0x46);
    ShiftCameraToPosition(&LeaderEntity->pixelPos, 0x10);
}

void sub_8087130(void)
{
    sub_8086448();
    sub_80866C4(gUnknown_8101440);
}

void sub_8087144(void)
{
    Entity *iVar2;
    Entity *iVar3;
    Entity *iVar4;
    s16 auStack_10c[28];
    s16 puStack_60[28];
    s16 puStack_5c[28];
    s16 *puStack_64[3];
    Entity *pEStack_58[3];
    struct_8085B80 auStack_4c[3];

    iVar2 = GetEntityFromClientType(5);
    iVar3 = GetEntityFromClientType(6);
    iVar4 = GetEntityFromClientType(7);
    memcpy(auStack_10c,gUnknown_810739C, 0x38);
    memcpy(puStack_60, gUnknown_81073D4, 0x38);
    memcpy(puStack_5c, gUnknown_810740C, 0x38);
    puStack_64[0] = auStack_10c;
    puStack_64[1] = puStack_60;
    puStack_64[2] = puStack_5c;
    pEStack_58[0] = iVar2;
    pEStack_58[1] = iVar3;
    pEStack_58[2] = iVar4;
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    sub_8086A54(iVar2);
    sub_8086A54(iVar3);
    sub_8086A54(iVar4);
    sub_8085B4C(auStack_4c,puStack_64,pEStack_58,3);
    iVar2->axObj.info->unk15F = 1;
    iVar3->axObj.info->unk15F = 1;
    iVar4->axObj.info->unk15F = 1;
    while( TRUE ) {
        if (!sub_8085B80(auStack_4c)) break;
        sub_803E46C(0x46);
    }
    iVar2->axObj.info->unk15F = 0;
    iVar3->axObj.info->unk15F = 0;
    iVar4->axObj.info->unk15F = 0;
}

void sub_8087230(void)
{
    Entity *LeaderEntity;
    Entity *ZapdosEntity;

    LeaderEntity = xxx_call_GetLeader();
    ZapdosEntity = GetEntityFromClientType(0x8);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_8085374();
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(ZapdosEntity, 0);
    sub_8086A3C(ZapdosEntity);
    sub_8085860(LeaderEntity->pos.x, LeaderEntity->pos.y - 3);
    CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SHIFTRY);
    CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ZAPDOS);
}

void sub_808729C(void)
{
  Entity *LeaderEntity;
  Entity *ZapdosEntity;

  LeaderEntity = xxx_call_GetLeader();
  ZapdosEntity = GetEntityFromClientType(8);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(0x91) != 0) {
    sub_8068FE0(ZapdosEntity,0x21c,0);
  }
  else {
    sub_8072008(ZapdosEntity,ZapdosEntity,gUnknown_80F57CC,0,0);
    SetFacingDirection(ZapdosEntity,0);
    sub_8086A3C(ZapdosEntity);
  }
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_SHIFTRY);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_ZAPDOS);
}

void sub_8087334(u8 param_1, u8 param_2)
{
  if ((param_2 == 7 || param_2 == 8 || param_2 == 9) && (param_1 == 8)) {
    sub_8097FA8(5);
    gDungeon->unk2 = 1;
  }
}
