#include "global.h"
#include "constants/direction.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "pokemon.h"
#include "dungeon_util_1.h"

extern void LoadIQSkills(struct DungeonEntity *);
extern struct DungeonEntity *GetPartnerEntity();
extern struct DungeonEntity *xxx_call_GetLeaderEntity(void);
extern struct DungeonEntity *GetEntityFromClientType(u32);
extern void SetDefaultIQSkills(u8 *param_1, u8 param_2);
extern void sub_8097FF8(void);
extern u8 sub_8044B28(void);
extern u8 HasRecruitedMon(u32);
extern u8 gUnknown_202E038[];
extern void sub_8083E88(u32);
extern void sub_8085374();
extern void sub_80854D4();
extern void sub_8085930(u32);
extern void sub_80855E4(void *);
extern void sub_8085860(s32 r0, u32 r1);
extern void sub_8068FE0(struct DungeonEntity *, u32, u32);
extern void sub_8097FA8(u32);
extern void DisplayDungeonDialogue(u8 *);
extern void sub_806CDD4(struct DungeonEntity *, u32, u32);
extern void sub_80869E4(struct DungeonEntity *, u32, u32, u32);
extern void sub_8083E88(u32);
extern void sub_803E708(u32, u32);
extern void sub_8086448(void);
extern void SpriteShockEffect(struct DungeonEntity *);
extern void SkarmoryEntry(struct DungeonEntity *);
extern void SpriteLookAroundEffect(struct DungeonEntity *);
extern void sub_8086A54(struct DungeonEntity *);
extern void PlaySoundEffect(u32);
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

void sub_8086A3C(struct DungeonEntity *param_1)
{
    param_1->entityData->unk15C = 1;
    param_1->entityData->unk15E = 1;
}

void sub_8086A54(struct DungeonEntity *param_1)
{
    param_1->entityData->unk15C = 1;
    param_1->entityData->unk15E = 0;
}

void SetupBossFightHP(struct DungeonEntity *param_1, s32 newHP, u16 param_3)
{

  // NOTE: needed two of these to match.. very dumb
  struct DungeonEntityData *iVar1;
  struct DungeonEntityData *iVar2;

  iVar1 = param_1->entityData;
  iVar2 = param_1->entityData;

  iVar1->isBoss = TRUE;

  // BUG: Source of the Reviver Seed Boss Glitch
  //
  // Video to demonstration:
  // https://www.youtube.com/watch?v=rHu7EehrZ68
  iVar1->originalHP = iVar1->maxHP;
  if (newHP != 0) {
    iVar1->maxHP = newHP;
    iVar1->HP = newHP;
  }

  gDungeonGlobalData->unk66A = param_3;
  SetDefaultIQSkills(iVar2->IQSkillsSelected,iVar2->isBoss);
  LoadIQSkills(param_1);
}

void sub_8086AC0(void)
{
    if(!sub_8044B28())
        if(gDungeonGlobalData->unk2 == 0)
            sub_8097FF8();
}

u8 sub_8086AE4(s16 _index)
{
    s32 pokeIndex = _index;

    if(gDungeonGlobalData->unk65C == 0)
        return 1;
    else
        return HasRecruitedMon(pokeIndex);
}

void sub_8086B14(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * DiglettEntity;
  struct DungeonEntity * SkarmoryEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  DiglettEntity = GetEntityFromClientType(4);
  SkarmoryEntity = GetEntityFromClientType(3);
  sub_8083E88(0x72);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(SkarmoryEntity);
  DiglettEntity->entityData->unk15C = 1;
  sub_8085860(LeaderEntity->posWorld.x,LeaderEntity->posWorld.y + -2);
  CopySpeciesNametoBuffer(gUnknown_202E038,SPECIES_DIGLETT);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_SKARMORY);
}

void sub_8086B94(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * DiglettEntity;
  struct DungeonEntity * SkarmoryEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  DiglettEntity = GetEntityFromClientType(4);
  SkarmoryEntity = GetEntityFromClientType(3);

  sub_8068FE0(SkarmoryEntity,0x21c,0);
  sub_8068FE0(DiglettEntity,0x21c,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8085860(LeaderEntity->posWorld.x,LeaderEntity->posWorld.y);
}

void sub_8086BDC(char param_1, s32 param_2)
{
  if ((((param_2 * 0x1000000) - 0x1000000U) >> 0x18 < 2) && (param_1 == 3)) {
    sub_8097FA8(1);
    gDungeonGlobalData->unk2 = 1;
  }
}

void SkarmoryPreFightDialogue(void)
{
  struct DungeonEntity *LeaderEntity;
  struct DungeonEntity *PartnerEntity;
  struct DungeonEntity * DiglettEntity;
  struct DungeonEntity * SkarmoryEntity;

  struct Position32 local_1c;
  struct Position32 local_20;

  LeaderEntity = xxx_call_GetLeaderEntity(); // Player
  PartnerEntity = GetPartnerEntity(); // Partner
  DiglettEntity = GetEntityFromClientType(4); // Diglett
  SkarmoryEntity = GetEntityFromClientType(3); // Skarmory

  local_1c.x = DiglettEntity->posPixel.x;
  local_1c.y = DiglettEntity->posPixel.y + 0x3000;

  local_20.x = SkarmoryEntity->posPixel.x;
  local_20.y = SkarmoryEntity->posPixel.y + 0x2000;

  sub_8086448();
  sub_803E708(10,0x46);
  SpriteShockEffect(PartnerEntity);
  sub_803E708(0x20,0x46);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&local_1c,0x40);
  sub_803E708(0x40,0x46);
  ShiftCameraToPosition(&local_20,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_2);
  sub_803E708(10,0x46);
  DiglettEntity->entityData->unk15D = 1;
  ShiftCameraToPosition(&local_1c,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&local_20,0x20);
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
  sub_8083E88(0xb);
  ShiftCameraToPosition(&LeaderEntity->posPixel,0x10);
}

void SkarmoryReFightDialogue(void)
{
  struct DungeonEntity * LeaderEntity;
  struct DungeonEntity * SkarmoryEntity;
  struct Position32 local_14;

  LeaderEntity = xxx_call_GetLeaderEntity();
  SkarmoryEntity = GetEntityFromClientType(3);
  local_14.x = SkarmoryEntity->posPixel.x;
  local_14.y = SkarmoryEntity->posPixel.y + 0x2000;
  sub_8086448();
  sub_803E708(10,0x46);
  SkarmoryEntry(SkarmoryEntity);
  ShiftCameraToPosition(&local_14,0x10);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_806CDD4(SkarmoryEntity,0xd,0);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_3);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&LeaderEntity->posPixel,0x10);
  sub_8083E88(0xb);
}

void sub_8086E40(void)
{
  SpriteLookAroundEffect(xxx_call_GetLeaderEntity());
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_8100D3C);
  sub_803E708(10,0x46);
  gDungeonGlobalData->unk2 = 1;
}

void SkarmoryEntry(struct DungeonEntity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,0);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  sub_803E708(0x44,0x46);
}

void sub_8086E9C(void)
{
  struct DungeonEntity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  sub_8083E88(0x72);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8086A3C);
  sub_8085860(LeaderEntity->posWorld.x,LeaderEntity->posWorld.y - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_METAPOD);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_GENGAR);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0xA0, SPECIES_CATERPIE);
}

void sub_8086F00(void)
{
  struct DungeonEntity * LeaderEntity;

  LeaderEntity = xxx_call_GetLeaderEntity();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(LeaderEntity->posWorld.x,LeaderEntity->posWorld.y - 3);
  CopySpeciesNametoBuffer(gUnknown_202E038, SPECIES_METAPOD);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0x50, SPECIES_GENGAR);
  CopySpeciesNametoBuffer(gUnknown_202E038 + 0xA0, SPECIES_CATERPIE);
}
