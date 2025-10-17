#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
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

extern void sub_8042B0C(Entity *);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8041888(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);

static void sub_80891F0(void);
static void sub_8089294(void);

void sub_8088DC0(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = CutsceneGetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(groudonEntity);
  sub_806CDD4(groudonEntity,0xe,DIRECTION_SOUTH);
  sub_8086A3C(alakazamEntity);
  sub_806CDD4(alakazamEntity,0xe,DIRECTION_SOUTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088E5C(void)
{
  Entity * leaderEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;

  leaderEntity = CutsceneGetLeader();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_80867F4();
  sub_8086838(0,1,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  HandleFaint(groudonEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  HandleFaint(alakazamEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_GROUDON);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ALAKAZAM);
}

void sub_8088EE8(void)
{
    sub_8086854();
}

void MagmaCavernMidDialogue(void)
{
  Entity * leaderEntity;
  Entity * partnerEntity;
  Entity * groudonEntity;
  Entity * alakazamEntity;
  s16 IDStack [2];
  PixelPos pos;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  groudonEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GROUDON_1);
  alakazamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ALAKAZAM_2);
  sub_8052D44(IDStack,leaderEntity,partnerEntity);
  sub_8086448();
  SpriteLookAroundEffect(partnerEntity);
  // Let's see..
  // I wonder where we are?
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  // I know we've come pretty
  // far...
  //
  // I'm certain we've come quite
  // far already..
  DisplayDungeonDialogue(MagmaCavernMidDialogue_2);
  sub_803E708(10,0x46);
  DungeonStopBGM();
  sub_80855E4(sub_80868F4);
  sub_808680C();
  PlaySoundEffect(0x1c5);
  sub_803E708(0x28,0x46);
  // Waaah!
  // Qu-quake!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_3);
  sub_803E708(0x78,0x46);
  StopSoundEffect(0x1c5);
  sub_808682C();
  sub_80855E4(sub_8086910);
  sub_803E708(0x14,0x46);
  sub_8085930(DIRECTION_NORTH);
  sub_803E708(10,0x46);
  // Whew!
  // It settled down.
  //
  // Whew
  // It's over.
  DisplayDungeonDialogue(MagmaCavernMidDialogue_4);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  PlaySoundEffect(0x1c7);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  // Hey! {POKEMON_0}!
  // Over there!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_5);
  GetEntInfo(groudonEntity)->unk15E = 0;
  GetEntInfo(alakazamEntity)->unk15E =0;
  pos.x = (groudonEntity->pixelPos.x + alakazamEntity->pixelPos.x) / 2;
  pos.y = (groudonEntity->pixelPos.y + alakazamEntity->pixelPos.y) / 2 + 0x800;
  ShiftCameraToPosition(&pos,0x20);
  sub_803E708(0x3c,0x46);
  sub_80891F0();
  // Hey!
  // Are you OK?!
  //
  // Hey!
  // Snap out of it!
  DisplayDungeonDialogue(MagmaCavernMidDialogue_6);
  sub_803E708(10,0x46);
  // Urrrrgh...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_7);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,2,DIRECTION_NORTHWEST);
  // What happened to you?
  //
  // What happened here?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_8);
  sub_803E708(10,0x46);
  // We challenged..
  // {POKEMON_2}...
  // And wiped out..
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_9);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_10);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTHEAST);
  sub_80869E4(partnerEntity,4,1,DIRECTION_NORTHEAST);
  // Grrgh..
  // We... It crushed us
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_11);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  // That's right...
  // What happened to {POKEMON_3}?
  // Where is {POKEMON_3}?
  //
  // Wait...
  // What about {POKEMON_3}?
  // Where did {POKEMON_3} go?
  DisplayDungeonDialogue(MagmaCavernMidDialogue_12);
  sub_803E708(0x1e,0x46);
  // {POKEMON_3} is...
  // Still battling {POKEMON_2}...
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_13);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);

  // {POKEMON_0}!
  // We've got to hurry!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_14);
  sub_8089294();
  // Be careful!
  DisplayDungeonDialogue(&MagmaCavernMidDialogue_15);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

void sub_8089168(void)
{
  Entity *leaderEntity;

  leaderEntity = CutsceneGetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(leaderEntity);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_808919C(Entity *r0)
{
    IncreaseEntityPixelPos(r0, 0, -512);
}

void sub_80891B0(Entity *r0)
{
    sub_806CDD4(r0, 0, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 1;
}

void sub_80891D0(Entity *r0)
{
    sub_806CDD4(r0, 7, DIRECTION_NORTH);
    GetEntInfo(r0)->unk15F = 0;
}

static void sub_80891F0(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 < 0x30; iVar1++)
  {
    sub_80855E4(sub_808919C);
    DungeonRunFrameActions(0x46);
  }
  sub_80855E4(sub_80891D0);
}

void sub_8089224(Entity * entity)
{
  s32 xPixelPos;

  if (entity->pixelPos.y < 0x9001) {
    return;
  }
  xPixelPos = entity->pixelPos.x;

  if(xPixelPos < 0xE400)
  {
      if(xPixelPos <= 0xB400)
      {
          // 0 - 0xB400
          IncreaseEntityPixelPos(entity, 0, -512);
      }
      else
      {
          // 0xB401 - 0xE3FF
           IncreaseEntityPixelPos(entity, -512, 0);
      }
  }
  else if(xPixelPos < 0xFC00)
  {
    IncreaseEntityPixelPos(entity, 0, -512);
  }
  else if(xPixelPos <= 0x11400)
  {
    IncreaseEntityPixelPos(entity, 0x200, 0);
  }
  else
  {
    IncreaseEntityPixelPos(entity, 0, -512);
  }
}

static void sub_8089294(void)
{
  s32 iVar1;

  sub_80855E4(sub_80891B0);
  for(iVar1 = 0; iVar1 <= 0x77; iVar1++)
  {
    sub_80855E4(sub_8089224);
    DungeonRunFrameActions(0x46);
  }
  sub_80855E4(sub_80891D0);
}

