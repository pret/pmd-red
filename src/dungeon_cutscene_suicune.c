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


static void sub_808A528(Entity * param_1);
static void SuicuneScreenFlash(void);

void sub_808A264(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8086A3C(SuicuneEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A2C0(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void sub_808A308(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
     HandleFaint_Async(SuicuneEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
     SetFacingDirection(SuicuneEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SUICUNE);
}

void HandleSuicuneBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_NORTHWIND_FIELD_ATTEMPT1 || cutscene == CUTSCENE_NORTHWIND_FIELD_ATTEMPT2 || cutscene == CUTSCENE_NORTHWIND_FIELD_POSTSTORY) && monsterBehavior == BEHAVIOR_SUICUNE) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_NORTHWIND_FIELD_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void SuicunePreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  sub_8086448();
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_1);
  DungeonWaitFrames_Async(10,70);
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_2);
  DungeonWaitFrames_Async(10,70);
  sub_80426C8(1,2);
  DungeonWaitFrames_Async(0x3c,70);
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_3);
  DungeonWaitFrames_Async(10,70);
  sub_808A528(SuicuneEntity);
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_4);
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_5);
  SuicuneScreenFlash();
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_6);
  SuicuneScreenFlash();
  DisplayDungeonDialogue_Async(&gSuicunePreFightDialogue_7);
  DungeonWaitFrames_Async(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicuneReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  DisplayDungeonDialogue_Async(&gSuicuneReFightDialogue_1);
  SuicuneScreenFlash();
  DisplayDungeonDialogue_Async(&gSuicuneReFightDialogue_2);
  SuicuneScreenFlash();
  DisplayDungeonDialogue_Async(&gSuicuneReFightDialogue_3);
  DungeonWaitFrames_Async(10,70);
  SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SuicunePostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * SuicuneEntity;

  leaderEntity = CutsceneGetLeader();
  SuicuneEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SUICUNE);
  if (HasRecruitedMon(MONSTER_SUICUNE)) {
    sub_80866C4(&gSuicunePostStoryPreFightDialogue_4);
  }
  else {
    DisplayDungeonDialogue_Async(&gSuicunePostStoryPreFightDialogue_1);
    SuicuneScreenFlash();
    DisplayDungeonDialogue_Async(&gSuicunePostStoryPreFightDialogue_2);
    SuicuneScreenFlash();
    DisplayDungeonDialogue_Async(&gSuicunePostStoryPreFightDialogue_3);
    DungeonWaitFrames_Async(10,70);
    SetupBossFightHP(SuicuneEntity,0x28a,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void sub_808A528(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 -= iVar1;
    iVar1 = F248_Sub(iVar1, IntToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = IntToF248(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    DungeonRunFrameActions(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248(0);
}

static void SuicuneScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
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

