#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "dungeon_8041AD0.h"
#include "dungeon_mon_sprite_render.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
#include "constants/dungeon_exit.h"
#include "constants/friend_area.h"
#include "constants/weather.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_misc.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
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
#include "weather.h"


static void RaikouScreenFlash(void);

void sub_8089EFC(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = CutsceneGetLeader();
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

  leaderEntity = CutsceneGetLeader();
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

  leaderEntity = CutsceneGetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
      HandleFaint_Async(RaikouEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
      SetFacingDirection(RaikouEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_RAIKOU);
}

void HandleRaikouBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_LIGHTNING_FIELD_ATTEMPT1 || cutscene == CUTSCENE_LIGHTNING_FIELD_ATTEMPT2 || cutscene == CUTSCENE_LIGHTNING_FIELD_POSTSTORY) && monsterBehavior == BEHAVIOR_RAIKOU) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_LIGHTNING_FIELD_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void RaikouPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = CutsceneGetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_2);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  DungeonWaitFrames_Async(10,70);
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_3);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_4);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_5);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouPreFightDialogue_6);
  DungeonWaitFrames_Async(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = CutsceneGetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  gDungeon->weather.unkE265 = WEATHER_RAIN;
  sub_807EAA0(0,1);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouReFightDialogue_1);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouReFightDialogue_2);
  RaikouScreenFlash();
  DisplayDungeonDialogue_Async(&gRaikouReFightDialogue_3);
  DungeonWaitFrames_Async(10,70);
  SetupBossFightHP(RaikouEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RaikouPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * RaikouEntity;

  leaderEntity = CutsceneGetLeader();
  RaikouEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAIKOU);
  if (HasRecruitedMon(MONSTER_RAIKOU)) {
    sub_80866C4(&gRaikouPostStoryPreFightDialogue_4);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_RAIN;
    sub_807EAA0(0,1);
    DisplayDungeonDialogue_Async(&gRaikouPostStoryPreFightDialogue_1);
    RaikouScreenFlash();
    DisplayDungeonDialogue_Async(&gRaikouPostStoryPreFightDialogue_2);
    RaikouScreenFlash();
    DisplayDungeonDialogue_Async(&gRaikouPostStoryPreFightDialogue_3);
    DungeonWaitFrames_Async(10,70);
    SetupBossFightHP(RaikouEntity,650,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void RaikouScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  sub_8085EB0();
}

