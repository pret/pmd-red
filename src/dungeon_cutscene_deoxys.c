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



static void DeoxysScreenFlash(void);
static void sub_808C550(void);
static void sub_808C590(Entity *r0);
static void SetupDeoxysFacingDirection(Entity *deoxysEntity);
static void SetupDeoxysFightHP(Entity *deoxysEntity);

void sub_808C3A0(void)
{
  Entity * leaderEntity;

  leaderEntity = CutsceneGetLeader();
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    sub_808563C(sub_808C590);
  }
  else {
    gDungeon->unk7 = 1;
    sub_808563C(SetupDeoxysFacingDirection);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_DEOXYS_NORMAL);
}

void HandleDeoxysNormalBossFaint(u8 monsterBehavior, u8 cutscene, bool8 transformedIntoFriend)
{
  if (cutscene == CUTSCENE_METEOR_CAVE && monsterBehavior == BEHAVIOR_DEOXYS_NORMAL) {
    gDungeon->unk2 = DUNGEON_UNK2_1;
    DungeonStartNewBGM(MUS_RAYQUAZAS_DOMAIN);
  }
}

void DeoxysPreFightDialogue(void)
{
  Entity * leaderEntity;

  leaderEntity = CutsceneGetLeader();
  sub_8086448();
  if (HasRecruitedMon(MONSTER_DEOXYS_NORMAL)) {
    // There appears to be no one here.
    // It's impossible to go any further
    sub_80866C4(&gDeoxysPreFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue_Async(&gDeoxysPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_RAYQUAZAS_DOMAIN, 0x3c);
    sub_808C550();
    DisplayDungeonDialogue_Async(&gDeoxysPreFightDialogue_2);
    DeoxysScreenFlash();
    DisplayDungeonDialogue_Async(&gDeoxysPreFightDialogue_3);
    DeoxysScreenFlash();
    DisplayDungeonDialogue_Async(&gDeoxysPreFightDialogue_4);
    DungeonWaitFrames_Async(10,0x46);
    sub_808563C(SetupDeoxysFightHP);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void DeoxysScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,iVar1,0,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(iVar1,0,0,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  sub_8085EB0();
}

static void sub_808C550(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,TRUE,TRUE);
  BgColorCallNullsub4();
  DungeonRunFrameActions(0x46);
  gDungeon->unk7 = 0;
  DeoxysScreenFlash();
}

static void sub_808C590(Entity *r0)
{
    HandleFaint_Async(r0, DUNGEON_EXIT_DELETED_FOR_EVENT, 0);
}

static void SetupDeoxysFacingDirection(Entity *deoxysEntity)
{
    SetFacingDirection(deoxysEntity, DIRECTION_SOUTH);
}

static void SetupDeoxysFightHP(Entity *deoxysEntity)
{
    SetupBossFightHP(deoxysEntity, 950, MUS_BATTLE_WITH_RAYQUAZA);
}

