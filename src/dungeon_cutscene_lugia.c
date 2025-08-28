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

static void LugiaScreenFlash(void);
static void LugiaScreenFlash2(void);
static void sub_808C0CC(void);

void sub_808BDEC(void)
{
  Entity * leaderEntity;
  Entity * lugiaEntity;

  leaderEntity = xxx_call_GetLeader();
  lugiaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LUGIA);
  DungeonStopBGM();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    HandleFaint(lugiaEntity,0x21c,0);
  }
  else {
    gDungeon->unk7 = 1;
    SetFacingDirection(lugiaEntity, DIRECTION_SOUTH);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_LUGIA);
}

void sub_808BE70(u8 param_1,u8 param_2,u8 param_3)
{
  if ((param_2 == 0x33) && (param_1 == 0x1B)) {
    gDungeon->unk2 = 1;
  }
}

void LugiaPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * lugiaEntity;

  leaderEntity = xxx_call_GetLeader();
  lugiaEntity = GetEntityFromMonsterBehavior(BEHAVIOR_LUGIA);
  if (HasRecruitedMon(MONSTER_LUGIA)) {
    sub_8086448();
    sub_80866C4(&gLugiaPreFightDialogue_8);
  }
  else {
    DungeonStopBGM();
    sub_8086448();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_1);
    DungeonFadeInNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE,0x3c);
    sub_808C0CC();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_2);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_3);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_4);
    PlaySoundEffect(0x1f8);
    sub_80861D4(lugiaEntity,0xd,DIRECTION_SOUTH);
    sub_803E708(0x2b,0x46);
    sub_80861B8(lugiaEntity,0,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_5);
    LugiaScreenFlash();
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_6);
    LugiaScreenFlash2();
    SetDungeonBGColorRGB(-250,-250,-250,1,0);
    DungeonStopBGM();
    sub_80861D4(lugiaEntity,7,DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gLugiaPreFightDialogue_7);
    LugiaScreenFlash();
    SetupBossFightHP(lugiaEntity,800,MUS_BATTLE_WITH_RAYQUAZA);
    DungeonStartNewBGM(MUS_FRIEND_AREA_CRYPTIC_CAVE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void LugiaScreenFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);
  for(iVar1 = 250; iVar1 > 149; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 > 199; iVar1 -= 10){
    SetDungeonBGColorRGB(0,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10){
    SetDungeonBGColorRGB(0,0,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

static void LugiaScreenFlash2(void)
{
  s32 iVar1;

  PlaySoundEffect(0x1f6);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    DungeonRunFrameActions(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    DungeonRunFrameActions(0x46);
  }

  sub_803E708(4,0x46);

  for(iVar1 = 0; iVar1 < 200; iVar1 += 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    DungeonRunFrameActions(0x46);
  }

  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 100){
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,0);
    DungeonRunFrameActions(0x46);
  }

  sub_803E708(10,0x46);
  sub_8085EB0();
}

static void sub_808C0CC(void)
{
  gDungeonBrightness = 0x1f;
  SetDungeonBGColorRGB(0,0,0,1,1);
  BgColorCallNullsub4();
  DungeonRunFrameActions(0x46);
  gDungeon->unk7 = 0;
  LugiaScreenFlash();
}

