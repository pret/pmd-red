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
#include "dungeon_leveling.h"

extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8052D44(s16 *, Entity *, Entity *);

static void MoltresDropInEffect(Entity * moltresEntity);
static void MoltresScreenFlash1(s32 xArg, s32 yArg);
static void MoltresScreenFlash2(s32 xArg, s32 yArg);
static void MoltresScreenFlash3(void);
static void MoltresScreenDarken(void);

void sub_80877E8(void)
{
  Entity * leaderEntity;
  Entity * moltresEntity;

  leaderEntity = CutsceneGetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(moltresEntity, DIRECTION_SOUTH);
  sub_8086A3C(moltresEntity);
  sub_8085860(leaderEntity->pos.x + -3,leaderEntity->pos.y + -2);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MOLTRES);
}

void sub_8087848(void)
{
  Entity *leaderEntity;
  Entity *moltresEntity;

  u32 XPos;
  s32 YPos;

  leaderEntity = CutsceneGetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  DungeonStartNewBGM(MUS_THE_MOUNTAIN_OF_FIRE);
  sub_80854D4();
  sub_8085930(DIRECTION_WEST);
  sub_80855E4(sub_8086A3C);
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    HandleFaint(moltresEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  }
  else {
    LevelUpTarget(moltresEntity,moltresEntity,gMoltresConfigLevel,0,0);
    SetFacingDirection(moltresEntity, DIRECTION_SOUTH);
    sub_8086A3C(moltresEntity);
  }
  sub_8085860(leaderEntity->pos.x - 5, leaderEntity->pos.y);
  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  sub_803F878(XPos, YPos + -0x1000);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_MOLTRES);
}

void sub_80878F4(u8 param_1, u8 param_2)
{
  if ((param_2 == 0xA || param_2 == 0xB || param_2 == 0xC) && (param_1 == 0x9)) {
    sub_8097FA8(0x7);
    gDungeon->unk2 = 1;
  }
}

void MoltresPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *moltresEntity;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(0xc,5);
  sub_8086500();
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_2);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_3);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_4);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,2,DIRECTION_WEST);
  sub_8086690();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_5);
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  PlaySoundEffect(0x2f2);
  DungeonStopBGM();
  MoltresScreenDarken();
  DisplayDungeonDialogue(gMoltresPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_7);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1cf);
  sub_80856E0(partnerEntity, DIRECTION_NORTH);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gMoltresPreFightDialogue_8);
  sub_803E708(10,0x46);
  MoltresScreenFlash3();
  PlaySoundEffect(0x1da);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_9);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(9,5);
  MoltresScreenFlash2(0xb,5);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_10);
  sub_803E708(10,0x46);
  MoltresScreenFlash1(0xc,5);
  MoltresScreenFlash2(9,5);
  MoltresDropInEffect(moltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_11);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(&gMoltresPreFightDialogue_12);
  sub_803E708(10,0x46);
  SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MoltresReFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity *moltresEntity;

  leaderEntity = CutsceneGetLeader();
  partnerEntity = CutsceneGetPartner();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(10,5);
  sub_8086500();
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(partnerEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_1);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(gMoltresReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,2,DIRECTION_WEST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  sub_8086690();
  MoltresScreenDarken();
  sub_803E708(10,0x46);
  sub_8085930(DIRECTION_NORTHWEST);
  sub_803E708(4,0x46);
  sub_8085930(DIRECTION_NORTH);
  MoltresDropInEffect(moltresEntity);
  sub_808663C();
  MoltresScreenFlash3();
  DisplayDungeonDialogue(&gMoltresReFightDialogue_3);
  sub_803E708(10,0x46);
  MoltresScreenFlash2(0xb,6);
  DisplayDungeonDialogue(gMoltresReFightDialogue_4);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gMoltresReFightDialogue_5);
  sub_803E708(10,0x46);
  SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void MoltresPostStoryPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * moltresEntity;

  leaderEntity = CutsceneGetLeader();
  moltresEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MOLTRES);
  MoltresScreenFlash1(0xc,5);
  sub_808654C();
  if (sub_8086AE4(MONSTER_MOLTRES)) {
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    sub_803E708(4,0x46);
    sub_803E708(10,0x46);
    DisplayDungeonDialogue(&gUnknown_8100D3C);
    sub_803E708(10,0x46);
    gDungeon->unk2 = 1;
  }
  else {
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_1);
    sub_8085930(DIRECTION_NORTHWEST);
    sub_803E708(4,0x46);
    sub_8085930(DIRECTION_NORTH);
    MoltresDropInEffect(moltresEntity);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_2);
    MoltresScreenFlash1(0xc,5);
    MoltresScreenFlash2(9,5);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_3);
    MoltresScreenFlash3();
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_4);
    MoltresScreenFlash2(0xb,6);
    DisplayDungeonDialogue(&gMoltresPostStoryPreFightDialogue_5);
    sub_803E708(10,0x46);
    SetupBossFightHP(moltresEntity,400,MUS_BOSS_BATTLE);
    ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  }
}

static void MoltresDropInEffect(Entity * moltresEntity)
{
  s32 iVar1;

  GetEntInfo(moltresEntity)->unk15C = 1;
  GetEntInfo(moltresEntity)->unk15E = 0;
  GetEntInfo(moltresEntity)->unk174 = IntToF248_2(200);
  PlaySoundEffect(0x1f8);
  for(iVar1 = 200; iVar1 >= 0; iVar1 -= 5)
  {
    GetEntInfo(moltresEntity)->unk174 = IntToF248_2(iVar1);
    DungeonRunFrameActions(0x46);
  }
}

static void MoltresScreenFlash1(s32 xArg, s32 yArg)
{
    s32 x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(xArg);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(yArg);
    newPos.y = y / 256;

    sub_8085EC8(370,16,0,&newPos,0);
}

static void MoltresScreenFlash2(s32 xArg, s32 yArg)
{
    s32 r6;
    s32 i, x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(xArg);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(yArg);
    newPos.y = y / 256;

    r6 = sub_8085EC8(370,22,0,&newPos,0);
    PlaySoundEffect(0x1EC);

    for (i = 250; i >= 20; i -= 10) {
        SetDungeonBGColorRGB(i, 0, 0, 1, 1);
        DungeonRunFrameActions(0x46);
    }
    sub_803E708(0xA, 0x46);

    for (i = 250; i >= 0; i -= 10) {
        SetDungeonBGColorRGB(i, 0, 0, 1, 1);
        DungeonRunFrameActions(0x46);
    }
    sub_803E708(0xA, 0x46);

    sub_8085EB0();
    sub_8085F44(r6);
}

static void MoltresScreenFlash3(void)
{
  int iVar1;

  PlaySoundEffect(0x1ed);
  iVar1 = 0xfa;
  for(iVar1 = 250; iVar1 > 9; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(0x1e,0x46);
  PlaySoundEffect(0x1ed);
  for(iVar1 = 250; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1 / 2,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(0x1e,0x46);
  sub_8085EB0();
}

static void MoltresScreenDarken(void)
{
  s32 iVar1;

  for(iVar1 = 0; iVar1 >= -80; iVar1 -= 8)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,0,0);
    DungeonRunFrameActions(0x46);
  }
}
