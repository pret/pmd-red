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
#include "dungeon_leveling.h"


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

    leaderEntity = CutsceneGetLeader();
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

  leaderEntity = CutsceneGetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_80854D4();
  sub_8085930(4);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    HandleFaint_Async(zapdosEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    LevelUpTarget(zapdosEntity,zapdosEntity,gZapdosConfigLevel,0,0);
    SetFacingDirection(zapdosEntity,DIRECTION_SOUTH);
    sub_8086A3C(zapdosEntity);
  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SHIFTRY);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_ZAPDOS);
}

void HandleZapdosBossFaint(u8 monsterBehavior, u8 cutscene)
{
  if ((cutscene == CUTSCENE_MT_THUNDER_PEAK_ATTEMPT1 || cutscene == CUTSCENE_MT_THUNDER_PEAK_ATTEMPT2 || cutscene == CUTSCENE_MT_THUNDER_PEAK_POSTSTORY) && monsterBehavior == BEHAVIOR_ZAPDOS) {
    SetTempCutsceneFlag(CUTSCENE_FLAG_MT_THUNDER_PEAK_COMPLETE);
    gDungeon->unk2 = DUNGEON_UNK2_1;
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

    leaderEntity = CutsceneGetLeader();
    partnerEntity = CutsceneGetPartner();
    zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
    sub_8086448();
    DungeonWaitFrames_Async(10,0x46);
    CutsceneLookAroundEffect_Async(partnerEntity);
    DungeonWaitFrames_Async(10,0x46);
    CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_EAST);
    CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_WEST);
    DisplayDungeonDialogue_Async(gUnknown_81014B0);
    DungeonWaitFrames_Async(10,0x46);
    CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_NORTH);
    CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_NORTH);
    DisplayDungeonDialogue_Async(gUnknown_8101504);
    DungeonWaitFrames_Async(10,0x46);
    ZapdosScreenFlash(3);
    DungeonStopBGM();
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue_Async(&gUnknown_81015A0);
    ZapdosDropInEffect(zapdosEntity);
    DungeonStartNewBGM(MUS_RISING_FEAR);
    sub_806CDD4(partnerEntity,6,DIRECTION_NORTH);
    DisplayDungeonDialogue_Async(&gUnknown_81015D4); //  Waah!
    DungeonWaitFrames_Async(10,0x46);
    CutsceneLookDir_Async(partnerEntity,2,DIR_TRANS_SPINRIGHT1,DIRECTION_SOUTHEAST);

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
    CutsceneLookDir_Async(partnerEntity,2,DIR_TRANS_SPINLEFT1,DIRECTION_NORTH);
    DisplayDungeonDialogue_Async(&gUnknown_81015E8); // I warned you! I have no mercy for meddlers
    DungeonWaitFrames_Async(0x3c,0x46);
    DisplayDungeonDialogue_Async(&gUnknown_8101624);
    DungeonWaitFrames_Async(10,0x46);
    GetEntInfo(partnerEntity)->unk15D = 0;
    CutsceneLookDir_Async(partnerEntity,2,DIR_TRANS_SPINLEFT1,DIRECTION_NORTHWEST);

    puStack_30 = (struct Zapdos2) {5, 2, 12, 0, 4, 2, 12, 0, 4, 0, 0, 0, 0, 8, 7, 0};
    puStack_4c[0] = puStack_30.unk0;
    pEStack_2c[0] = partnerEntity;
    sub_8085B4C(&auStack_48,puStack_4c,pEStack_2c,1);
    while (sub_8085B80(&auStack_48)) {
        DungeonRunFrameActions(0x46);
    }

    CutsceneLookDir_Async(partnerEntity,2,DIR_TRANS_SPINRIGHT1,DIRECTION_NORTHEAST);
    DisplayDungeonDialogue_Async(gUnknown_810165C);
    DungeonWaitFrames_Async(10,0x46);
    ZapdosScreenFlash(3);
    DisplayDungeonDialogue_Async(&gUnknown_8101750);
    DungeonWaitFrames_Async(10,0x46);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue_Async(&gUnknown_810178C);
    DungeonWaitFrames_Async(10,0x46);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue_Async(&gUnknown_81017B4);
    DungeonWaitFrames_Async(10,0x46);
    SetupBossFightHP(zapdosEntity,300, MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *zapdosEntity;

  leaderEntity = CutsceneGetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(gZapdosReFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue_Async(&gUnknown_81015A0);
  DungeonWaitFrames_Async(10,0x46);
  ZapdosDropInEffect(zapdosEntity);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gZapdosReFightDialogue_2);
  ZapdosScreenFlash(1);
  DisplayDungeonDialogue_Async(&gZapdosReFightDialogue_3);
  ZapdosScreenFlash(2);
  DisplayDungeonDialogue_Async(&gZapdosReFightDialogue_4);
  SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void ZapdosPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * zapdosEntity;

  leaderEntity = CutsceneGetLeader();
  zapdosEntity = GetEntityFromMonsterBehavior(BEHAVIOR_ZAPDOS);
  sub_8086448();
  if (sub_8086AE4(MONSTER_ZAPDOS)) {
    sub_80866C4(&gZapdosPostStoryPreFightDialogue_6);
  }
  else {
    ZapdosScreenFlash(1);
    PlaySoundEffect(0x1da);
    DisplayDungeonDialogue_Async(&gZapdosPostStoryPreFightDialogue_1);
    ZapdosDropInEffect(zapdosEntity);
    DisplayDungeonDialogue_Async(&gZapdosPostStoryPreFightDialogue_2);
    ZapdosScreenFlash(1);
    DisplayDungeonDialogue_Async(&gZapdosPostStoryPreFightDialogue_3);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue_Async(&gZapdosPostStoryPreFightDialogue_4);
    ZapdosScreenFlash(2);
    DisplayDungeonDialogue_Async(&gZapdosPostStoryPreFightDialogue_5);
    DungeonWaitFrames_Async(10,0x46);
    SetupBossFightHP(zapdosEntity,300,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void ZapdosDropInEffect(Entity *zapdosEntity)
{
  s32 iVar1;

  GetEntInfo(zapdosEntity)->unk15C = 1;
  GetEntInfo(zapdosEntity)->unk15E = 0;
  GetEntInfo(zapdosEntity)->unk174 = 200; // incorrect value? Overwritten immediately anyway
  PlaySoundEffect(0x1ea);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(zapdosEntity)->unk174 = IntToF248(iVar1);
    DungeonRunFrameActions(0x46);
  }
  DungeonWaitFrames_Async(0x1e,0x46);
}

static void ZapdosScreenFlash(s32 numFlashes)
{
  s32 index;

  PlaySoundEffect(0x1f6);
  if (2 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,TRUE,TRUE);
      DungeonRunFrameActions(0x46);
    }
  }
  if (1 < numFlashes) {
    for(index = 250; index > 199; index -= 10)
    {
      SetDungeonBGColorRGB(index,index,index / 2,TRUE,TRUE);
      DungeonRunFrameActions(0x46);
    }
  }
  for(index = 250; index >= 0; index -= 10)
  {
    SetDungeonBGColorRGB(index,index,index / 4,TRUE,TRUE);
    DungeonRunFrameActions(0x46);
  }
  sub_8085EB0();
}


