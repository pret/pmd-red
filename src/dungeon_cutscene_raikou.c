#include "global.h"
#include "globaldata.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_80861A8.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "exclusive_pokemon.h"
#include "friend_area.h"
#include "items.h"
#include "pokemon_3.h"
#include "pokemon.h"
#include "position_util.h"
#include "trap.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_boss_dialogue.h"

extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern void sub_8085EB0(void);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void UpdateMinimap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void SpawnDroppedItemWrapper(Entity *, DungeonPos *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern u32 sub_8085EC8(u32, u32, u32, DungeonPos *, u32);
extern void sub_807EAA0(u32, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern bool8 sub_8085B80(struct_8085B80 *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void RaikouScreenFlash(void);

void sub_8089EFC(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void sub_8089F44(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void sub_8089F8C(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      HandleFaint(RaikouEntity,0x21c,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void sub_8089FF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x23 || param_2 == 0x24 || param_2 == 0x25) && (param_1 == 0x13)) {
    sub_8097FA8(0x17);
    gDungeon->unk2 = 1;
  }
}

void RaikouPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_2);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue(&gRaikouReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = xxx_call_GetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(&gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue(&gRaikouPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

