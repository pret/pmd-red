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
#include "dungeon_leveling.h"


static void RayquazaDropInEffect(Entity *rayquazaEntity);
static void RayquazaScreenFlash(void);

void sub_80892C8(void)
{
  Entity * leaderEntity;
  Entity * RayquazaEntity;

  leaderEntity = CutsceneGetLeader();
  RayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(RayquazaEntity, DIRECTION_SOUTH);
  sub_8086A3C(RayquazaEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void sub_8089328(void)
{
  Entity * leaderEntity;
  Entity * rayquazaEntity;

  leaderEntity = CutsceneGetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    HandleFaint_Async(rayquazaEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    LevelUpTarget(rayquazaEntity,rayquazaEntity,gRayquazaConfigLevel,0,0);
    sub_8086A3C(rayquazaEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_RAYQUAZA);
}

void HandleRayquazaBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT1 || cutscene == CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT2 || cutscene == CUTSCENE_SKY_TOWER_SUMMIT_POSTSTORY) && monsterBehavior == BEHAVIOR_RAYQUAZA) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_SKY_TOWER_SUMMIT_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void RayquazaPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *rayquazaEntity;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_2);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  CutsceneLookAroundEffect_Async(partnerEntity);
  DungeonWaitFrames_Async(10,0x46);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_EAST);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_WEST);
  DisplayDungeonDialogue_Async(gRayquazaPreFightDialogue_3);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_NORTH);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_NORTH);
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_4);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_5);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_6);
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_7);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_8);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_9);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_10);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_11);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = CutsceneGetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  RayquazaScreenFlash();
  PlaySoundEffect(0x1da); // Rayquaza Cry
  DisplayDungeonDialogue_Async(&gRayquazaPreFightDialogue_7);
  DungeonWaitFrames_Async(10,0x46);
  RayquazaDropInEffect(rayquazaEntity);
  DisplayDungeonDialogue_Async(&gRayquazaReFightDialogue_1);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaReFightDialogue_2);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaReFightDialogue_3);
  RayquazaScreenFlash();
  DisplayDungeonDialogue_Async(&gRayquazaReFightDialogue_4);
  SetupBossFightHP(rayquazaEntity,600,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void RayquazaPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *rayquazaEntity;

  leaderEntity = CutsceneGetLeader();
  rayquazaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_RAYQUAZA);
  sub_8086448();
  if (sub_8086AE4(MONSTER_RAYQUAZA)) {
    sub_80866C4(&gRayquazaPostStoryPreFightDialogue_6);
  }
  else {
    PlaySoundEffect(0x1da); // Rayquaza Cry
    DisplayDungeonDialogue_Async(&gRayquazaPostStoryPreFightDialogue_1);
    RayquazaDropInEffect(rayquazaEntity);
    DisplayDungeonDialogue_Async(&gRayquazaPostStoryPreFightDialogue_2);
    RayquazaScreenFlash();
    DisplayDungeonDialogue_Async(&gRayquazaPostStoryPreFightDialogue_3);
    RayquazaScreenFlash();
    DisplayDungeonDialogue_Async(&gRayquazaPostStoryPreFightDialogue_4);
    RayquazaScreenFlash();
    DisplayDungeonDialogue_Async(&gRayquazaPostStoryPreFightDialogue_5);
    SetupBossFightHP(rayquazaEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void RayquazaDropInEffect(Entity *rayquazaEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(rayquazaEntity)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(6);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 = iVar2 - iVar1;
    iVar1 = F248_Sub(iVar1, IntToF248(0.09375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = IntToF248(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(rayquazaEntity)->unk174 = iVar2;
    DungeonRunFrameActions(0x46);
  }
  GetEntInfo(rayquazaEntity)->unk174 = IntToF248(0);
}

static void RayquazaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, TRUE, TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, 0, TRUE, TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2, iVar1, iVar1 / 2, TRUE, TRUE);
    DungeonRunFrameActions(70);
  }
  DungeonWaitFrames_Async(10,70);
  sub_8085EB0();
}
