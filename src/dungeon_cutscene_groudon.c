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

extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8052D44(s16 *, Entity *, Entity *);

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
  HandleFaint(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
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
  HandleFaint(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  if (sub_8086AE4(MONSTER_GROUDON)) {
    HandleFaint(groudonEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
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

void sub_8088818(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x12 || param_2 == 0x13 || param_2 == 0x14) && (param_1 == 0xE)) {
    sub_8097FA8(0xC);
    gDungeon->unk2 = 1;
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
  DisplayDungeonDialogue(GroudonPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  sub_808682C();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_4);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  DisplayDungeonDialogue(&GroudonPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_6);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  sub_80861B8(alakazamEntity,6,DIRECTION_NORTH);
  PlaySoundEffect(0x205);
  sub_8086738();
  HandleFaint(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_8);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_9);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_8086764();
  sub_803E708(0x28,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(GroudonPreFightDialogue_10);
  sub_803E708(10,0x46);
  sub_8086838(1,1,1);
  sub_808680C();
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(GroudonPreFightDialogue_11);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  GroudonScreenFlash2();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_12);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&GroudonPreFightDialogue_13);
  sub_803E708(10,0x46);
  sub_803E708(0x1e,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  PlaySoundEffect(0x1fa);
  sub_8086738();
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(GroudonPreFightDialogue_14);
  sub_803E708(10,0x46);
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
  sub_803E708(0x3c,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_1);
  sub_803E708(10,0x46);
  GroudonScreenFlash();
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(gGroudonReFightDialogue_2);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gGroudonReFightDialogue_3);
  sub_803E708(10,0x46);
  sub_808682C();
  sub_803E708(0x3c,0x46);
  DungeonStopBGM();
  PlaySoundEffect(0x1fa);
  sub_8086738();
  DisplayDungeonDialogue(gGroudonReFightDialogue_4);
  sub_803E708(10,0x46);
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
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    SceneGroudonMovement(groudonEntity);
    SceneGroudonMovement(groudonEntity);
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_2);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_3);
    PlaySoundEffect(0x1f6);
    GroudonScreenFlash();
    DisplayDungeonDialogue(&gGroudonPostStoryPreFightDialogue_4);
    sub_803E708(10,0x46);
    SetupBossFightHP(groudonEntity,500,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

// Moves Groudon down in a walking fashion
static void SceneGroudonMovement(Entity * groudonEntity)
{
  int iVar1;

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
  sub_803E708(10,0x46);
  sub_808682C();
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(0x22,0x46);
}

static void GroudonScreenFlash(void)
{
  s32 iVar1;

  for(iVar1 = 250; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
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
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,0,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1 / 2,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}


