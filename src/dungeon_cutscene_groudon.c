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
#include "dungeon_tilemap.h"
#include "dungeon_leveling.h"


static void SceneGroudonMovement(Entity * groudonEntity);
static void GroudonScreenFlash(void);
static void GroudonScreenFlash2(void);

void sub_808862C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = CutsceneGetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(alakazamEntity, DIRECTION_NORTH);
  sub_80861D4(alakazamEntity,0xd,DIRECTION_NORTH);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_80886C4(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = CutsceneGetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  PlaySoundEffect(0x3e5);
  sub_80867F4();
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  HandleFaint_Async(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
  sub_8086A3C(groudonEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_808875C(void)
{
  Entity * leaderEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = CutsceneGetLeader();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_80867F4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  HandleFaint_Async(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    HandleFaint_Async(groudonEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    LevelUpTarget(groudonEntity,groudonEntity,gGroudonConfigLevel,0,0);
    SetFacingDirection(groudonEntity, DIRECTION_SOUTH);
    sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void HandleGroudonBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1 || cutscene == CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2 || cutscene == CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY) && monsterBehavior == BEHAVIOR_GROUDON_2) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_MAGMA_CAVERN_PIT_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void sub_8088848(void)
{
    sub_8086854();
}

void GroudonPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * alakazamEntity;
  Entity * groudonEntity;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_1);
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  DisplayDungeonDialogue_Async(GroudonPreFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  DungeonWaitFrames_Async(0x3c,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_2);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  DungeonWaitFrames_Async(0x3c,0x46);
  sub_808682C();
  DungeonWaitFrames_Async(0x1e,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_3);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  DungeonWaitFrames_Async(0x3c,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_4);
  DungeonWaitFrames_Async(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_5);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_6);
  DungeonWaitFrames_Async(10,0x46);
  PlaySoundEffect(0x1d5);
  CutsceneLookAroundEffect_Async(partnerEntity);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_7);
  DungeonWaitFrames_Async(10,0x46);
  sub_808682C();
  DungeonWaitFrames_Async(0x3c,0x46);
  sub_80861B8(alakazamEntity,6,DIRECTION_NORTH);
  PlaySoundEffect(0x205);
  sub_8086738();
  HandleFaint_Async(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_8);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_9);
  DungeonWaitFrames_Async(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  DungeonWaitFrames_Async(0x28,0x46);
  PlaySoundEffect(0x1d5);
  CutsceneLookAroundEffect_Async(partnerEntity);
  DisplayDungeonDialogue_Async(GroudonPreFightDialogue_10);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  DungeonWaitFrames_Async(0x3c,0x46);
  DisplayDungeonDialogue_Async(GroudonPreFightDialogue_11);
  DungeonWaitFrames_Async(10,0x46);
  DungeonStopBGM();
  GroudonScreenFlash2();
  DungeonWaitFrames_Async(0x1e,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_12);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&GroudonPreFightDialogue_13);
  DungeonWaitFrames_Async(10,0x46);
  DungeonWaitFrames_Async(0x1e,0x46);
  sub_808682C();
  DungeonWaitFrames_Async(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue_Async(GroudonPreFightDialogue_14);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = CutsceneGetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086838(1,1,1);
  sub_808680C();
  DungeonWaitFrames_Async(0x3c,0x46);
  DisplayDungeonDialogue_Async(gGroudonReFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  GroudonScreenFlash();
  DungeonWaitFrames_Async(0x1e,0x46);
  DisplayDungeonDialogue_Async(gGroudonReFightDialogue_2);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gGroudonReFightDialogue_3);
  DungeonWaitFrames_Async(10,0x46);
  sub_808682C();
  DungeonWaitFrames_Async(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue_Async(gGroudonReFightDialogue_4);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086A54(groudonEntity);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void GroudonPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;

  leaderEntity = CutsceneGetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_2);
  sub_8086448();
  if (sub_8086AE4(MONSTER_GROUDON)) {
      sub_80866C4(&gUnknown_8103488);
  }
  else{
    DisplayDungeonDialogue_Async(&gGroudonPostStoryPreFightDialogue_1);
    DungeonWaitFrames_Async(10,0x46);
    SceneGroudonMovement(groudonEntity);
    SceneGroudonMovement(groudonEntity);
    DisplayDungeonDialogue_Async(&gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue_Async(&gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue_Async(&gGroudonPostStoryPreFightDialogue_4);
    DungeonWaitFrames_Async(10,0x46);
    SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
static void SceneGroudonMovement(Entity * groudonEntity)
{
  s32 iVar1;

  sub_8086848(0x18,0x10);
  sub_806CDD4(groudonEntity,0,DIRECTION_SOUTH);
  for(iVar1 = 0; iVar1 < 0x2C; iVar1++)
  {
    if ((iVar1 == 10) || (iVar1 == 0x20)) {
      PlaySoundEffect(0x1f9);
      sub_8086838(0,1,0);
      sub_808680C();
    }
    if ((iVar1 - 10U < 0xc) || (iVar1 > 0x1f)) {
      IncreaseEntityPixelPos(groudonEntity,0,0x100);
    }
    DungeonRunFrameActions(0x46);
  }
  sub_80856C8(groudonEntity,groudonEntity->pos.x,groudonEntity->pos.y + 1);
  sub_80861D4(groudonEntity,0xf,DIRECTION_SOUTH);
  DungeonWaitFrames_Async(10,0x46);
  sub_808682C();
  sub_8085930(DIRECTION_NORTH);
  DungeonWaitFrames_Async(0x22,0x46);
}

static void GroudonScreenFlash(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  sub_8085EB0();
}

static void GroudonScreenFlash2(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  sub_8085EB0();
}


