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
#include "dungeon_map.h"


static void nullsub_99(void);
static void KyogreScreenFlash(void);
static void sub_808C360(void);

void sub_808C10C(void)
{
  Entity * leaderEntity;
  Entity * kyogreEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = CutsceneGetLeader();
  kyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    HandleFaint_Async(kyogreEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(kyogreEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos,YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_KYOGRE);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GROUDON);
}

void HandleKyogreBossFaint(u8 monsterBehavior, u8 cutscene, bool8 transformedIntoFriend)
{
  if (cutscene == CUTSCENE_STORMY_SEA && monsterBehavior == BEHAVIOR_KYOGRE) {
    gDungeon->unk2 = DUNGEON_UNK2_1;
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
  }
}

void KyogrePreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *KyogreEntity;

  leaderEntity = CutsceneGetLeader();
  KyogreEntity = GetEntityFromMonsterBehavior(BEHAVIOR_KYOGRE);
  DungeonStopBGM();
  if (HasRecruitedMon(MONSTER_KYOGRE)) {
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    CutsceneLookAroundEffect_Async(leaderEntity);
    DungeonWaitFrames_Async(10,0x46);
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_8);
    DungeonWaitFrames_Async(10,0x46);
    gDungeon->unk2 = DUNGEON_UNK2_1;
  }
  else {
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_1);
    DungeonWaitFrames_Async(10,0x46);
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_2);
    DungeonWaitFrames_Async(10,0x46);
    nullsub_99();
    DungeonWaitFrames_Async(10,0x46);
    // Gwwwwwooooooooh
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_3);
    DungeonWaitFrames_Async(10,0x46);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C360();
    // My duels against {POKEMON_3} (Groudon) left us both exhausted
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_4);
    KyogreScreenFlash();
    // I am {POKEMON_2} (Kyogre)!
    // The lord of the sea!
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_5);
    KyogreScreenFlash();
    // Witness the destructive force of my waves!
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_6);
    KyogreScreenFlash();
    // Marvel at my awesome
    // power!
    DisplayDungeonDialogue_Async(&gKyogrePreFightDialogue_7);
    DungeonWaitFrames_Async(10,0x46);
    SetupBossFightHP(KyogreEntity,600,MUS_BOSS_BATTLE);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void nullsub_99(void)
{
}

static void KyogreScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f8);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(10,0x46);
  sub_8085EB0();
}

static void sub_808C360(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,TRUE,TRUE);
  BgColorCallNullsub4();
  DungeonRunFrameActions(0x46);
  gDungeon->unk7 = 0;
  KyogreScreenFlash();
}
