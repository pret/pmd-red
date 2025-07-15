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

struct Zapdos1
{
    s16 unk0[12];
};

struct Zapdos2
{
    s16 unk0[16];
};

static void ZapdosDropInEffect(Entity *zapdosEntity);
static void ZapdosScreenFlash(s32 numFlashes);

void sub_8087230(void)
{
    Entity *leaderEntity;
    Entity *zapdosEntity;

    leaderEntity = xxx_call_GetLeader();
    zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_8085374();
    sub_80854D4();
    sub_8085930(4);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(zapdosEntity, DIRECTION_SOUTH);
    sub_8086A3C(zapdosEntity);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SHIFTRY);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ZAPDOS);
}

void sub_808729C(void)
{
  Entity *leaderEntity;
  Entity *zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(0x91) != 0) {
    sub_8068FE0(zapdosEntity,0x21c,0);
  }
  else {
    sub_8072008(zapdosEntity,zapdosEntity,gZapdosConfigLevel,0,0);
    SetFacingDirection(zapdosEntity,DIRECTION_SOUTH);
    sub_8086A3C(zapdosEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SHIFTRY);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ZAPDOS);
}

void sub_8087334(u8 param_1, u8 param_2)
{
  if ((param_2 == 7 || param_2 == 8 || param_2 == 9) && (param_1 == 8)) {
    sub_8097FA8(5);
    gDungeon->unk2 = 1;
  }
}

void ZapdosPreFightDialogue(void)
{
    Entity *leaderEntity;
    Entity *partnerEntity;
    struct Zapdos1 puStack_38; // sp 0x0
    struct_8085B80 auStack_78;
    struct Zapdos2 puStack_30;
    s16 *puStack_34[1]; // sp 0x58
    struct Entity *pEStack_34[1]; // sp 0x5c
    s16 *puStack_4c[1]; // sp 0x60
    Entity *pEStack_2c[1]; // sp 0x64
    Entity *zapdosEntity; // sp 0x68
    struct_8085B80 auStack_48;  // r8

    leaderEntity = xxx_call_GetLeader();
    partnerEntity = GetPartnerEntity();
    zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
    sub_8086448();
    sub_803E708(10,0x46);
    SpriteLookAroundEffect(partnerEntity);
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
    sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
    DisplayDungeonDialogue(gUnknown_81014B0);
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
    sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
    DisplayDungeonDialogue(gUnknown_8101504);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(3);
    DungeonStopBGM();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gUnknown_81015A0);
    ZapdosDropInEffect(zapdosEntity);
    DungeonStartNewBGM(MUS_RISING_FEAR);
    sub_806CDD4(partnerEntity,6,DIRECTION_NORTH);
    DisplayDungeonDialogue(&gUnknown_81015D4); //  Waah!
    sub_803E708(10,0x46);
    sub_80869E4(partnerEntity,2,1,DIRECTION_SOUTHEAST);

    puStack_38 = (struct Zapdos1) {1, 2, 12, 0, 1, 0, 0, 0, 0, 9, 9, 0};
    puStack_34[0] = puStack_38.unk0;
    pEStack_34[0] = partnerEntity;
    sub_8085B4C(&auStack_78,puStack_34,pEStack_34,1);
    GetEntInfo(partnerEntity)->unk15F = 1;
    while(sub_8085B80(&auStack_78)) {
        DungeonRunFrameActions(0x46);
    }

    GetEntInfo(partnerEntity)->unk15F = 0;
    GetEntInfo(partnerEntity)->unk15D = 1;
    sub_80869E4(partnerEntity,2,2,DIRECTION_NORTH);
    DisplayDungeonDialogue(&gUnknown_81015E8); // I warned you! I have no mercy for meddlers
    sub_803E708(0x3c,0x46);
    DisplayDungeonDialogue(&gUnknown_8101624);
    sub_803E708(10,0x46);
    GetEntInfo(partnerEntity)->unk15D = 0;
    sub_80869E4(partnerEntity,2,2,DIRECTION_NORTHWEST);

    puStack_30 = (struct Zapdos2) {5, 2, 12, 0, 4, 2, 12, 0, 4, 0, 0, 0, 0, 8, 7, 0};
    puStack_4c[0] = puStack_30.unk0;
    pEStack_2c[0] = partnerEntity;
    sub_8085B4C(&auStack_48,puStack_4c,pEStack_2c,1);
    while (sub_8085B80(&auStack_48)) {
        DungeonRunFrameActions(0x46);
    }

    sub_80869E4(partnerEntity,2,1,DIRECTION_NORTHEAST);
    DisplayDungeonDialogue(gUnknown_810165C);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(3);
    DisplayDungeonDialogue(&gUnknown_8101750);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(&gUnknown_810178C);
    sub_803E708(10,0x46);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gUnknown_81017B4);
    sub_803E708(10,0x46);
    SetupBossFightHP(zapdosEntity,300, MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gZapdosReFightDialogue_1);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gUnknown_81015A0);
  sub_803E708(10,0x46);
  ZapdosDropInEffect(zapdosEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_2);
  ZapdosScreenFlash(1);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_3);
  ZapdosScreenFlash(2);
  DisplayDungeonDialogue(&gZapdosReFightDialogue_4);
  SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * zapdosEntity;

  leaderEntity = xxx_call_GetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    sub_80866C4(&gZapdosPostStoryPreFightDialogue_6);
  }
  else {
    ZapdosScreenFlash(1);
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_1);
    ZapdosDropInEffect(zapdosEntity);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_2);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_3);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_4);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue(&gZapdosPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void ZapdosDropInEffect(Entity *zapdosEntity)
{
  int iVar1;

  GetEntInfo(zapdosEntity)->unk15C = 1;
  GetEntInfo(zapdosEntity)->unk15E = 0;
  GetEntInfo(zapdosEntity)->unk174.raw = 200; // incorrect value? Overwritten immediately anyway
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(zapdosEntity)->unk174 = IntToF248_2(iVar1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(0x1e,0x46);
}

static void ZapdosScreenFlash(s32 numFlashes)
{
  s32 index;

  PlaySoundEffect(0x1f6);
  if (2 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,1,1);
      DungeonRunFrameActions(0x46);
    }
  }
  if (1 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,1,1);
      DungeonRunFrameActions(0x46);
    }
  }
  for(index = 250; index >= 0; index -= 10)
  {
    SetDungeonBGColorRGB(index,index,index / 4,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_8085EB0();
}


