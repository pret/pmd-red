#include "global.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_music.h"
#include "dungeon_pokemon_attributes.h"
#include "pokemon.h"
#include "dungeon_util_1.h"

extern struct Entity *GetPartnerEntity();
extern struct Entity *xxx_call_GetLeader(void);
extern void SetDefaultIQSkills(u8 *param_1, u8 param_2);
extern void sub_8097FF8(void);
extern u8 sub_8044B28(void);
extern u8 HasRecruitedMon(u32);
extern u8 gUnknown_202E038[];
extern void sub_8085374();
extern void sub_80854D4();
extern void sub_80855E4(void *);
extern void sub_8068FE0(struct Entity *, u32, u32);
extern void sub_8097FA8(u32);
extern void DisplayDungeonDialogue(u8 *);
extern void sub_806CDD4(struct Entity *, u32, u32);
extern void sub_80869E4(struct Entity *, u32, u32, u32);
extern void sub_803E708(u32, u32);
extern void sub_8086448(void);
extern void SpriteShockEffect(struct Entity *);
extern void SkarmoryEntry(struct Entity *);
extern void SpriteLookAroundEffect(struct Entity *);
extern void sub_8086A54(struct Entity *);
extern void sub_808563C(void *);

extern u8 gSkarmoryPreFightDialogue_1;
extern u8 gSkarmoryPreFightDialogue_2;
extern u8 gSkarmoryPreFightDialogue_3;
extern u8 gSkarmoryPreFightDialogue_4;
extern u8 gSkarmoryPreFightDialogue_5;
extern u8 gSkarmoryPreFightDialogue_6;
extern u8 gSkarmoryPreFightDialogue_7;
extern u8 gSkarmoryPreFightDialogue_8;
extern u8 gSkarmoryPreFightDialogue_9;
extern u8 gSkarmoryReFightDialogue_1;
extern u8 gSkarmoryReFightDialogue_2;
extern u8 gSkarmoryReFightDialogue_3;
extern u8 gUnknown_8100D3C;

void sub_8086A3C(struct Entity *pokemon)
{
    pokemon->info->unk15C = 1;
    pokemon->info->unk15E = 1;
}

void sub_8086A54(struct Entity *pokemon)
{
    pokemon->info->unk15C = 1;
    pokemon->info->unk15E = 0;
}

void SetupBossFightHP(struct Entity *pokemon, s32 newHP, u16 songIndex)
{

  // NOTE: needed two of these to match.. very dumb
  struct EntityInfo *entityInfo;
  struct EntityInfo *enityData_1;

  entityInfo = pokemon->info;
  enityData_1 = pokemon->info;

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
  struct Entity * LeaderEntity;
  struct Entity * DiglettEntity;
  struct Entity * SkarmoryEntity;

  LeaderEntity = xxx_call_GetLeader();
  DiglettEntity = GetEntityFromClientType(4);
  SkarmoryEntity = GetEntityFromClientType(3);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(SkarmoryEntity);
  DiglettEntity->info->unk15C = 1;
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y + -2);
  CopyMonsterNametoBuffer(gUnknown_202E038,MONSTER_DIGLETT);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_SKARMORY);
}

void sub_8086B94(void)
{
  struct Entity * LeaderEntity;
  struct Entity * DiglettEntity;
  struct Entity * SkarmoryEntity;

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
  struct Entity *LeaderEntity;
  struct Entity *PartnerEntity;
  struct Entity * DiglettEntity;
  struct Entity * SkarmoryEntity;

  struct Position32 pos1;
  struct Position32 pos2;

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
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&pos1,0x40);
  sub_803E708(0x40,0x46);
  ShiftCameraToPosition(&pos2,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_2);
  sub_803E708(10,0x46);
  DiglettEntity->info->unk15D = 1;
  ShiftCameraToPosition(&pos1,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&pos2,0x20);
  sub_803E708(0x20,0x46);
  SkarmoryEntry(SkarmoryEntity);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_4); // Skarmory: You!\nWhat do you think you're doing here?!
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_806CDD4(SkarmoryEntity,0xd,0);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_8);
  sub_803E708(10,0x46);
  sub_80869E4(PartnerEntity,4,1,2);
  sub_80869E4(LeaderEntity,4,2,6);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_9);
  sub_80869E4(PartnerEntity,4,2,4);
  sub_80869E4(LeaderEntity,4,1,4);
  sub_803E708(10,0x46);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
}

void SkarmoryReFightDialogue(void)
{
  struct Entity * LeaderEntity;
  struct Entity * SkarmoryEntity;
  struct Position32 pos;

  LeaderEntity = xxx_call_GetLeader();
  SkarmoryEntity = GetEntityFromClientType(3);
  pos.x = SkarmoryEntity->pixelPos.x;
  pos.y = SkarmoryEntity->pixelPos.y + 0x2000;
  sub_8086448();
  sub_803E708(10,0x46);
  SkarmoryEntry(SkarmoryEntity);
  ShiftCameraToPosition(&pos,0x10);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_806CDD4(SkarmoryEntity,0xd,0);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_3);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->pixelPos,0x10);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
}

void sub_8086E40(void)
{
  SpriteLookAroundEffect(xxx_call_GetLeader());
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_8100D3C);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void SkarmoryEntry(struct Entity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,0);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  sub_803E708(0x44,0x46);
}

void sub_8086E9C(void)
{
  struct Entity * LeaderEntity;

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
  struct Entity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(LeaderEntity->pos.x,LeaderEntity->pos.y - 3);
  CopyMonsterNametoBuffer(gUnknown_202E038, MONSTER_METAPOD);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0x50, MONSTER_GENGAR);
  CopyMonsterNametoBuffer(gUnknown_202E038 + 0xA0, MONSTER_CATERPIE);
}
