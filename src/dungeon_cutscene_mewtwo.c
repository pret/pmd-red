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


static void MewtwoDropInEffect(Entity *mewtwoEntity);
static void MewtwoScreenFlash(void);

void sub_8089914(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = CutsceneGetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  gDungeon->unk7 = 1;
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
  sub_8086A3C(MewtwoEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void sub_8089978(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = CutsceneGetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if(HasRecruitedMon(MONSTER_MEWTWO)){
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    HandleFaint_Async(MewtwoEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(MewtwoEntity, DIRECTION_SOUTH);
    sub_8086A3C(MewtwoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MEWTWO);
}

void HandleMewtwoBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_WESTERN_CAVE_ATTEMPT1 || cutscene == CUTSCENE_WESTERN_CAVE_ATTEMPT2 || cutscene == CUTSCENE_WESTERN_CAVE_POSTSTORY) && monsterBehavior == BEHAVIOR_MEWTWO) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_WESTERN_CAVE_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void MewtwoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = CutsceneGetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  DisplayDungeonDialogue_Async(&gMewtwoPreFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  sub_8086794();
  DungeonWaitFrames_Async(0x1e,0x46);
  MewtwoDropInEffect(MewtwoEntity);
  DungeonWaitFrames_Async(0x3c,0x46);
  DisplayDungeonDialogue_Async(&gMewtwoPreFightDialogue_2);
  DisplayDungeonDialogue_Async(&gMewtwoPreFightDialogue_3);
  DungeonWaitFrames_Async(10,0x46);
  MewtwoScreenFlash();
  DisplayDungeonDialogue_Async(&gMewtwoPreFightDialogue_4);
  MewtwoScreenFlash();
  DisplayDungeonDialogue_Async(&gMewtwoPreFightDialogue_5);
  DungeonWaitFrames_Async(10,0x46);
  SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MewtwoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *MewtwoEntity;

  leaderEntity = CutsceneGetLeader();
  MewtwoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEWTWO);
  sub_8086448();
  if(HasRecruitedMon(MONSTER_MEWTWO)) {
    sub_80866C4(&gMewtwoReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue_Async(&gMewtwoReFightDialogue_1);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    sub_8086794();
    MewtwoDropInEffect(MewtwoEntity);
    DungeonWaitFrames_Async(0x3c,0x46);
    DisplayDungeonDialogue_Async(&gMewtwoReFightDialogue_2);
    MewtwoScreenFlash();
    DisplayDungeonDialogue_Async(&gMewtwoReFightDialogue_3);
    MewtwoScreenFlash();
    DisplayDungeonDialogue_Async(&gMewtwoReFightDialogue_4);
    SetupBossFightHP(MewtwoEntity,900,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void MewtwoDropInEffect(Entity *mewtwoEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(mewtwoEntity)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(4);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2 -= iVar1;
    iVar1 = F248_Sub(iVar1, IntToF248(0.045));
    if (F248LessThanFloat(iVar1, 0.12)) {
      iVar1 = IntToF248(0.12);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(mewtwoEntity)->unk174 = iVar2;
    DungeonRunFrameActions(0x46);
  }
  GetEntInfo(mewtwoEntity)->unk174 = IntToF248(0);
}

static void MewtwoScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,0,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  sub_8085EB0();
}


