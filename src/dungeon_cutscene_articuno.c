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
#include "weather.h"


static void sub_8088484(Entity *param_1);
static void ArticunoScreenFlash(void);
static void sub_8088574(void);

void sub_8087F54(void)
{
  Entity  *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = CutsceneGetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
  sub_8086A3C(articunoEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8087FB4(void)
{
  Entity  *articunoEntity;

  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
  sub_806CDD4(articunoEntity, 0xF, DIRECTION_SOUTH);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8087FF8(void)
{
  Entity  *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = CutsceneGetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    HandleFaint_Async(articunoEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    LevelUpTarget(articunoEntity,articunoEntity,gArticunoConfigLevel,0,0);
    SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
    sub_8086A3C(articunoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void HandleArticunoBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_FROSTY_GROTTO_ATTEMPT1 || cutscene == CUTSCENE_FROSTY_GROTTO_ATTEMPT2 || cutscene == CUTSCENE_FROSTY_GROTTO_POSTSTORY) && monsterBehavior == BEHAVIOR_ARTICUNO) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_FROSTY_GROTTO_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
}

void ArticunoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *articunoEntity;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8086448();
  CutsceneLookAroundEffect_Async(partnerEntity);
  DisplayDungeonDialogue_Async(gArticunoPreFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  sub_8086598();
  DungeonStopBGM();
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_2);
  DungeonWaitFrames_Async(10,0x46);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_EAST);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_WEST);
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_3);
  DungeonWaitFrames_Async(10,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_SOUTHWEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  DungeonWaitFrames_Async(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(gArticunoPreFightDialogue_4);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_5);
  DungeonWaitFrames_Async(10,0x46);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_NORTH);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_NORTH);
  PlaySoundEffect(0x1d5);
  CutsceneLookAroundEffect_Async(partnerEntity);
  PlaySoundEffect(0x1d5);
  CutsceneLookAroundEffect_Async(leaderEntity);
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_6);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_7);
  DungeonWaitFrames_Async(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_8);
  DungeonWaitFrames_Async(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_9);
  DungeonWaitFrames_Async(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(articunoEntity);
  sub_80865E8();
  ArticunoScreenFlash();
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_10);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_11);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue_Async(&gArticunoPreFightDialogue_12);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  DungeonWaitFrames_Async(0x10,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = CutsceneGetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gArticunoReFightDialogue_1);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue_Async(&gArticunoReFightDialogue_2);
  ArticunoScreenFlash();
  DisplayDungeonDialogue_Async(&gArticunoReFightDialogue_3);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  DungeonWaitFrames_Async(0x28,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = CutsceneGetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    sub_80866C4(&gUnknown_8102A9C);
  }
  else {
    gDungeon->weather.unkE265 = WEATHER_SNOW;
    sub_807EAA0(0,1);
    ArticunoScreenFlash();
    sub_8086738();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue_Async(&gArticunoPostStoryPreFightDialogue_1);
    DungeonWaitFrames_Async(10,0x46);
    sub_8088484(articunoEntity);
    ArticunoScreenFlash();
    DisplayDungeonDialogue_Async(&gArticunoPostStoryPreFightDialogue_2);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue_Async(&gArticunoPostStoryPreFightDialogue_3);
    sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue_Async(&gArticunoPostStoryPreFightDialogue_4);
    ArticunoScreenFlash();
    DisplayDungeonDialogue_Async(&gArticunoPostStoryPreFightDialogue_5);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    DungeonWaitFrames_Async(0x28,0x46);
    SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void sub_8088484(Entity *param_1)
{
  int iVar1;

  GetEntInfo(param_1)->unk15C = 1;
  GetEntInfo(param_1)->unk15E = 0;
  PlaySoundEffect(0x1ea);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(param_1)->unk174 = IntToF248(iVar1);
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,0);
    DungeonRunFrameActions(0x46);
  }
}

static void ArticunoScreenFlash(void)
{
  int iVar1;

  PlaySoundEffect(0x2ad);
  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(4,0x46);
  sub_8085EB0();
}

static void sub_8088574(void)
{
  int iVar1;

  for(iVar1 = 0; iVar1 <= 80; iVar1 += 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    DungeonRunFrameActions(0x46);
  }
}
