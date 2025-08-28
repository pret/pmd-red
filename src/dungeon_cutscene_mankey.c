#include "global.h"
#include "globaldata.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
#include "code_80861A8.h"
#include "code_806CD90.h"
#include "code_80869E4.h"
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
#include "dungeon_util_1.h"
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
extern void sub_8085EB0(void);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void UpdateMinimap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void SpawnDroppedItemWrapper(Entity *, DungeonPos *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern u32 sub_8085EC8(u32, u32, u32, DungeonPos *, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern bool8 sub_8085B80(struct_8085B80 *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void sub_80898F8(Entity *r0);
static void sub_8089908(Entity *r0);

void sub_808970C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  DungeonStartNewBGM(MUS_TINY_WOODS);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8089908);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y -3);
}

void sub_808974C(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_80898F8);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
}

void sub_8089788(Entity *entity, u8 param_2, u8 param_3)
{
  Entity *monEntity;
  s32 index;
  bool8 found = FALSE;

  if (param_3 == 0x1A || param_3 == 0x1B) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      monEntity = gDungeon->wildPokemon[index];
      if ((EntityIsValid(monEntity)) && (monEntity != entity) && (GetEntInfo(monEntity)->monsterBehavior == param_2)) {
        found = TRUE;
        break;
      }
    }

    if(!found){
        sub_8097FA8(0x11);
        gDungeon->unk2 = 1;
    }
  }
}

void sub_80897F0(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103BD8);
  // We don't like to brag or
  // nothing, but
  DisplayDungeonDialogue(&gUnknown_8103C00);
  // We get furious real easy
  // You know that?!
  DisplayDungeonDialogue(&gUnknown_8103C3C);
  // What really irritates us is
  // when we see some dim witted face
  DisplayDungeonDialogue(&gUnknown_8103C74);
  // .........
  // Wrooooooar!
  // That vacant expression
  DisplayDungeonDialogue(&gUnknown_8103CC4);
  // Gwoooh
  // It's ticking me off!
  // I'm seeing red!
  DisplayDungeonDialogue(&gUnknown_8103D0C);
  // Mukkkeeeeeh
  // Get 'em! It's frenzy time!
  DisplayDungeonDialogue(&gUnknown_8103D50);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_8089878(void)
{
  Entity *leaderEntity;

  leaderEntity = xxx_call_GetLeader();
  sub_8086448();
  sub_803E708(10,0x46);
  sub_808563C(SpriteShockEffect);
  sub_803E708(0x20,0x46);
  sub_808692C();
  DisplayDungeonDialogue(&gUnknown_8103D8C);
  DisplayDungeonDialogue(&gUnknown_8103D98);
  DisplayDungeonDialogue(&gUnknown_8103DD8);
  DisplayDungeonDialogue(&gUnknown_8103E28);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void sub_80898E4(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8103E34);
}

static void sub_80898F8(Entity *r0)
{
    HandleFaint(r0, 0x21C, 0);
}

static void sub_8089908(Entity *r0)
{
    SetFacingDirection(r0, DIRECTION_NORTH);
}

