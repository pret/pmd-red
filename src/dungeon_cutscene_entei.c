#include "global.h"
#include "globaldata.h"
#include "code_800DAC0.h"
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
#include "dungeon_leader.h"
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
extern s32 GetCameraXPos(void);
extern s32 GetCameraYPos(void);
extern void sub_803F878(u32, s32);
extern void BgColorCallNullsub4(void);
extern void sub_8085EB0(void);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void ShowWholeRevealedDungeonMap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_80464C8(Entity *, DungeonPos *, Item *);
extern void SetDungeonBGColorRGB(u32, u32, u32, u32, u32);
extern u32 sub_8085EC8(u32, u32, u32, DungeonPos *, u32);
extern void sub_807EAA0(u32, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern u32 GetRandomFloorItem(u32);
extern bool8 sub_8085B80(struct_8085B80 *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void EnteiScreenFlash(void);

void sub_8089C44(void)
{
  Entity * leaderEntity;
  Entity * EnteiEntity;

  leaderEntity = xxx_call_GetLeader();
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

  leaderEntity = xxx_call_GetLeader();
  EnteiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ENTEI);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  if (HasRecruitedMon(MONSTER_ENTEI)) {
      sub_8068FE0(EnteiEntity,0x21c,0);
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

  leaderEntity = xxx_call_GetLeader();
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

  leaderEntity = xxx_call_GetLeader();
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

  leaderEntity = xxx_call_GetLeader();
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

