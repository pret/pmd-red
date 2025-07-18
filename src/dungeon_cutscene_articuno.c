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
extern void sub_807EAA0(u32, u32);
extern void sub_8072008(Entity *, Entity *, s16, u32, u32);
extern void sub_8085374(void);
extern u32 GetRandomFloorItem(u32);
extern bool8 sub_8085B80(struct_8085B80 *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void sub_8088484(Entity *param_1);
static void ArticunoScreenFlash(void);
static void sub_8088574(void);

void sub_8087F54(void)
{
  Entity  *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
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

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ARTICUNO)) {
    HandleFaint(articunoEntity,0x21c,0);
  }
  else {
    sub_8072008(articunoEntity,articunoEntity,gArticunoConfigLevel,0,0);
    SetFacingDirection(articunoEntity, DIRECTION_SOUTH);
    sub_8086A3C(articunoEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y + -3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_ARTICUNO);
}

void sub_8088088(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xD || param_2 == 0xE || param_2 == 0xF) && (param_1 == 0xD)) {
    sub_8097FA8(0x9);
    gDungeon->unk2 = 1;
  }
}

void ArticunoPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  partnerEntity = GetPartnerEntity();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  sub_8086448();
  SpriteLookAroundEffect(partnerEntity);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_8086598();
  DungeonStopBGM();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_3);
  sub_803E708(10,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_SOUTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SetFacingDirection(leaderEntity, DIRECTION_WEST);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gArticunoPreFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(partnerEntity);
  PlaySoundEffect(0x1d5);
  SpriteLookAroundEffect(leaderEntity);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0); // snow flurry
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  PlaySoundEffect(0x1ee); // flash effect?
  sub_8088574();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_8);
  sub_803E708(10,0x46);
  ArticunoScreenFlash();
  sub_8086738();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_9);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1ea);
  sub_8088484(articunoEntity);
  sub_80865E8();
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_10);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_11);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoPreFightDialogue_12);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x10,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
  articunoEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ARTICUNO);
  gDungeon->weather.unkE265 = WEATHER_SNOW;
  sub_807EAA0(0,1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gArticunoReFightDialogue_1);
  sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_2);
  ArticunoScreenFlash();
  DisplayDungeonDialogue(&gArticunoReFightDialogue_3);
  sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
  sub_803E708(0x28,0x46);
  SetupBossFightHP(articunoEntity,0x1c2,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ArticunoPostStoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *articunoEntity;

  leaderEntity = xxx_call_GetLeader();
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
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_1);
    sub_803E708(10,0x46);
    sub_8088484(articunoEntity);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_2);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_3);
    sub_806CDD4(articunoEntity,0x10,DIRECTION_SOUTH);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_4);
    ArticunoScreenFlash();
    DisplayDungeonDialogue(&gArticunoPostStoryPreFightDialogue_5);
    sub_806CDD4(articunoEntity,0xf,DIRECTION_SOUTH);
    sub_803E708(0x28,0x46);
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
    GetEntInfo(param_1)->unk174 = IntToF248_2(iVar1);
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
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(4,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1 / 2,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(4,0x46);
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
