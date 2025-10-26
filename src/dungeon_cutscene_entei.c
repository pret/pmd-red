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


static void EnteiScreenFlash(void);

void sub_8089C44(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = CutsceneGetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}

void sub_8089C90(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = CutsceneGetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      HandleFaint(EnteiEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
      SetFacingDirection(EnteiEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ENTEI);
}

void sub_8089CFC(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x20 || param_2 == 0x21 || param_2 == 0x22) && (param_1 == 0x12)) {
    sub_8097FA8(0x15);
    gDungeon->unk2 = 1;
  }
}

void EnteiPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = CutsceneGetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = CutsceneGetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_1);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_2);
  EnteiScreenFlash();
  DisplayDungeonDialogue(&gEnteiReFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void EnteiPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = CutsceneGetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
    sub_80866C4(&gEnteiPostStoryPreFightDialogue_4);
  }
  else {
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_1);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_2);
    EnteiScreenFlash();
    DisplayDungeonDialogue(&gEnteiPostStoryPreFightDialogue_3);
    sub_803E708(10,70);
    SetupBossFightHP(EnteiEntity,600,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void EnteiScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, 0, 0, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1, iVar1 / 2, iVar1 / 2, 1, 1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}

