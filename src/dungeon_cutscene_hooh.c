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


static void HoOhDropInEffect(Entity * param_1);
static void HoOhScreenFlash(void);

void sub_808A608(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = CutsceneGetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
  sub_8086A3C(HoOhEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A668(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;

  leaderEntity = CutsceneGetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  DungeonStartNewBGM(MUS_FRIEND_AREA_RAINBOW_PEAK);
  sub_80867F4();
  sub_8086838(0,0,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    HandleFaint(HoOhEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    SetFacingDirection(HoOhEntity, DIRECTION_SOUTH);
    sub_8086A3C(HoOhEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 6);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_HO_OH);
}

void sub_808A6E8(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x29 || param_2 == 0x2A) && (param_1 == 0x15)) {
    sub_8097FA8(0x1A);
    gDungeon->unk2 = 1;
  }
}

void sub_808A718(void)
{
    sub_8086854();
}

void HoOhPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = CutsceneGetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);
  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_1);
  sub_803E708(10,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_2);
  sub_803E708(10,70);
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0xfa,70);
  HoOhDropInEffect(HoOhEntity);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_8085930(DIRECTION_NORTH);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_3);
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_4);
  sub_803E708(0x1e,70);
  sub_803E708(0x1e,70);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_5);
  HoOhScreenFlash();
  DisplayDungeonDialogue(&gHoOhPreFightDialogue_6);
  sub_803E708(10,70);
  SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void HoOhReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * HoOhEntity;
  PixelPos local_14;

  leaderEntity = CutsceneGetLeader();
  HoOhEntity = GetEntityFromMonsterBehavior(BEHAVIOR_HO_OH);

  local_14.x = leaderEntity->pixelPos.x;
  local_14.y = leaderEntity->pixelPos.y + -0x1000;
  ShiftCameraToPosition(&local_14,0x88);
  sub_803E708(0x40,70);
  if (HasRecruitedMon(MONSTER_HO_OH)) {
    sub_80866C4(&HoOhReFightDialogue_5);
  }
  else {
    DisplayDungeonDialogue(&HoOhReFightDialogue_1);
    HoOhScreenFlash();
    sub_80855E4(sub_80868F4);
    sub_808680C();
    sub_803E708(10,70);
    HoOhDropInEffect(HoOhEntity);
    sub_808682C();
    sub_80855E4(sub_8086910);
    sub_8085930(DIRECTION_NORTH);
    DisplayDungeonDialogue(&HoOhReFightDialogue_2);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_3);
    HoOhScreenFlash();
    DisplayDungeonDialogue(&HoOhReFightDialogue_4);
    sub_803E708(10,70);
    SetupBossFightHP(HoOhEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void HoOhDropInEffect(Entity * param_1)
{
  s24_8 iVar1;
  s24_8 iVar2;

  GetEntInfo(param_1)->unk15E = 0;
  iVar2 = IntToF248(200);
  iVar1 = IntToF248(12);
  PlaySoundEffect(0x1f8);
  while( 1 ) {
    iVar2.raw -= iVar1.raw;
    iVar1 = F248_Sub(iVar1, FloatToF248(0.375));
    if (F248LessThanFloat(iVar1, 0.08)) {
      iVar1 = FloatToF248_2(0.08);
    }
    if (F248LessThanInt(iVar2, 0)) break;
    GetEntInfo(param_1)->unk174 = iVar2;
    DungeonRunFrameActions(70);
  }
  GetEntInfo(param_1)->unk174 = IntToF248_2(0);
}

static void HoOhScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(70);
  }
  sub_803E708(10,70);
  sub_8085EB0();
}
