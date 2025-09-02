#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_806CD90.h"
#include "constants/bg_music.h"
#include "constants/direction.h"
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


extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8041888(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);

static void LatiosScreenFlash(void);

void sub_808A9E4(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = CutsceneGetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 4);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA3C(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = CutsceneGetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(LatiosEntity, DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AA94(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = CutsceneGetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  HandleFaint(LatiosEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LATIOS);
}

void sub_808AAF0(u8 param_1, u8 param_2)
{
  if ((param_2 == 0x2B || param_2 == 0x2C || param_2 == 0x2D) && (param_1 == 0x16)) {
    sub_8097FA8(0x1C);
    gDungeon->unk2 = 1;
  }
}

void LatiosPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;
  PixelPos local_18;
  DungeonPos local_19;

  leaderEntity = CutsceneGetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);

  local_18.x = LatiosEntity->pixelPos.x;
  local_18.y = LatiosEntity->pixelPos.y + (0x80 << 6);
  local_19.y = 0x70;
  local_19.x = 0xFC;
  sub_8085EC8(0x1bd,0,0,&local_19,1);

  sub_803E708(0x1e,70);
  sub_8086448();
  ShiftCameraToPosition(&local_18,0x18);
  sub_803E708(2,70);
  SpriteShockEffect(LatiosEntity);
  sub_803E708(0x20,70);
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void LatiosReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * LatiosEntity;

  leaderEntity = CutsceneGetLeader();
  LatiosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LATIOS);
  sub_8086448();
  sub_808692C();
  DisplayDungeonDialogue(&gLatiosReFightDialogue_1);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_2);
  LatiosScreenFlash();
  DisplayDungeonDialogue(&gLatiosPreFightDialogue_3);
  sub_803E708(10,70);
  SetupBossFightHP(LatiosEntity,600,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808AC3C(void)
{
    sub_8086448();
    // There appears to be no one here
    sub_80866C4(&gUnknown_8104FC8);
}

static void LatiosScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1ee);
  gDungeonBrightness = 0x1f;
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10)
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
