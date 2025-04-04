#include "global.h"
#include "globaldata.h"
#include "code_800DAC0.h"
#include "code_800E9A8.h"
#include "dungeon_vram.h"
#include "code_803E668.h"
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

extern s32 gDungeonBrightness;

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

static void sub_808B50C(void);
static void JirachiWish(void);
static void JirachiWishGrantFlash(void);
static void sub_808BB3C(DungeonPos *pos1);
static void sub_808BBA8(Entity *jirachiEntity);
static void JirachiDropInEffect(Entity *jirachiEntity);
static void JirachiSpinEffect(Entity * jirachiEntity);
static void JirachiWishGrantDialogue(Entity *jirachiEntity);
static void CreateJirachiWishWarpTile(void);
static void EnableJirachiWishWarpTile(void);
static u8 JirachiFriendAreaSearch(void);

void sub_808B2F4(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  CreateJirachiWishWarpTile();
  sub_8049ED4();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  SetFacingDirection(jirachiEntity, DIRECTION_SOUTH);
  sub_8086A3C(jirachiEntity);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
}

void sub_808B35C(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  if (HasRecruitedMon(MONSTER_JIRACHI)) {
    sub_8068FE0(jirachiEntity,0x21c,0);
  }
  else {
    SetFacingDirection(jirachiEntity, DIRECTION_SOUTH);
    sub_8086A3C(jirachiEntity);
    CreateJirachiWishWarpTile();
    sub_8049ED4();

  }
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
}

void sub_808B3E4(u8 param_1, u8 param_2, u8 param_3)
{
  u8 uVar1;
  if ((param_2 == 0x31 || param_2 == 0x32) && (param_1 == 0x1A)) {
    sub_8097FA8(0x1E);
    if(param_3 != 0)
    {
        gDungeon->unk2 = 1;
    }
    else {
        uVar1 = gDungeon->unk1356C;
        if(sub_80860A8(0x36) != 0)
        {
            JirachiWish();
        }
        else
        {
            sub_808B50C();
        }
        gDungeon->unk1356C = uVar1;
        ShowWholeRevealedDungeonMap();
    }
  }
}

void JirachiPreFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * jirachiEntity;

  leaderEntity = xxx_call_GetLeader();
  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  sub_8086448();
  sub_803E708(0x40,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_1);
  sub_803E708(10,70);
  SpriteLookAroundEffect(leaderEntity);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_2);
  sub_80861F8(0x37,jirachiEntity,1);
  sub_80855E4(SpriteShockEffect);
  sub_803E708(0x3c,70);
  JirachiDropInEffect(jirachiEntity);
  sub_803E708(0x5a,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_3);
  sub_803E708(10,70);
  DisplayDungeonDialogue(&gJirachiPreFightDialogue_4);
  sub_803E708(10,70);
  SetupBossFightHP(jirachiEntity,0x15e,MUS_BATTLE_WITH_RAYQUAZA);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

static void sub_808B50C(void)
{
  Entity * jirachiEntity;

  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(jirachiEntity);
  sub_8041888(0);
  GetEntInfo(jirachiEntity)->unk15C = 1;
  GetEntInfo(jirachiEntity)->unk15E = 0;
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,70);
  // Fwaaaahhhh
  DisplayDungeonDialogue(&gUnknown_810554C);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  // I think I had a dream, and I was fighting in it
  // Did I imagine it?
  // I'm sleepy so I'm going back to sleep.
  DisplayDungeonDialogue(&gUnknown_8105558);
  sub_803E708(10,70);
  JirachiSpinEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81055F4);
  sub_803E708(10,70);
  gDungeon->unk2 = 1;
}

static const u8 sJirachiItems[] = {ITEM_PROTEIN, ITEM_CALCIUM, ITEM_IRON, ITEM_ZINC, ITEM_JOY_SEED, ITEM_GINSENG, ITEM_LIFE_SEED, ITEM_SITRUS_BERRY};

static void JirachiWish(void)
{
  Entity *jirachiEntity;
  DungeonPos *LeaderPos;
  Entity *leaderEntity;
  s32 wishChoice;

  jirachiEntity = GetEntityFromMonsterBehavior(BEHAVIOR_JIRACHI);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_JIRACHI);
  sub_80855E4(sub_808BBA8);
  sub_808BBA8(jirachiEntity);
  sub_8041888(0);
  GetEntInfo(jirachiEntity)->unk15C = 1;
  GetEntInfo(jirachiEntity)->unk15E = 0;
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  sub_80855E4(sub_80861A8);
  gDungeon->unk1356C = 1;
  DungeonFadeOutBGM(0x1e);
  sub_803E708(0x1e,0x46);
  DisplayDungeonDialogue(&gUnknown_8105668);
  sub_803E708(10,0x46);
  PlaySoundEffect(0x1a7);
  sub_803E708(0x96,0x46);
  SpriteShockEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_8105674);
  DungeonStartNewBGM(MUS_FRIEND_AREA_FOREST);
  sub_803E708(10,0x46);
  sub_80856E0(jirachiEntity, DIRECTION_SOUTH);
  PlaySoundEffect(0x16a);
  DisplayDungeonDialogue(&gUnknown_81056B8);
  sub_803E708(10,0x46);
  SpriteLookAroundEffect(jirachiEntity);
  DisplayDungeonDialogue(&gUnknown_81056DC);
  sub_803E708(10,0x46);
  while( 1 ) {
    while (1) {
        wishChoice = DisplayDungeonMenuMessage(NULL,gUnknown_8105798,gUnknown_810579C,0x705);
        if (wishChoice >= 1) break;
    }
    sub_803E708(10,0x46);
    if (wishChoice == 1) {
      s32 counter, index;
      DungeonPos pos;
      Item moneyItems [9];
      // Lots of Money
      DisplayDungeonDialogue(&gUnknown_810581C);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(jirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
        for(index = 0; index < 9; index++)
        {
          CreateItemWithStickyChance(&moneyItems[index], ITEM_POKE, 0);
        }
        pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);
        if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
          PlaySoundEffect(0x14c);
          sub_808BB3C(&pos);
          sub_8046860(jirachiEntity,&pos,moneyItems,9);
        }
      }
      GetEntInfo(jirachiEntity)->unk15D  = 0;
    }
    if (wishChoice == 2) {
      s32 counter, index;
      DungeonPos pos;
      Item items [9];
      // Lots of Items
      DisplayDungeonDialogue(&gUnknown_8105974);
      sub_803E708(10,0x46);
      JirachiWishGrantDialogue(jirachiEntity);

      for(counter = 0; counter < 6; counter++)
      {
        for(index = 0; index < 9; index++)
        {
          CreateItemWithStickyChance(&items[index], GetRandomFloorItem(0),0);
        }
        pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
        pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);

        if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
          PlaySoundEffect(400);
          sub_808BB3C(&pos);
          sub_8046860(jirachiEntity,&pos,items,9);
        }
      }
      GetEntInfo(jirachiEntity)->unk15D = 0;
    }

    if (wishChoice == 3)
    {
        // A Friend Area
        s32 friendArea = JirachiFriendAreaSearch();
        if (friendArea == NUM_FRIEND_AREAS)
        {
            // You want a friend area? But you already have many friend areas...
            DisplayDungeonDialogue(&gUnknown_8105A08);
            sub_803E708(10,0x46);
            continue;
        }
        else
        {
        // You want a friend area? As you wish..
          DisplayDungeonDialogue(&gUnknown_8105AD4);
          sub_803E708(10,0x46);
          JirachiWishGrantDialogue(jirachiEntity);
          GetEntInfo(jirachiEntity)->unk15D  = 0;
          DisplayDungeonDialogue(&gUnknown_8105B20);
          UnlockFriendArea(friendArea);
          PlaySoundEffect(0xd4);
          leaderEntity = GetLeader();
          SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],leaderEntity,0);
          WriteFriendAreaName(gFormatBuffer_Items[0],friendArea,FALSE);
          // Obtained the friend area!
          DisplayDungeonDialogue(&gUnknown_8105B68);
        }
    }
    if (wishChoice == 4) {
        s32 counter, index;
        DungeonPos pos;
        Item strengthItems [9];
        // More Strength..
        DisplayDungeonDialogue(&gUnknown_8105BA8);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(jirachiEntity);

        for(counter = 0; counter < 5; counter++)
        {

          for(index = 0; index < 4; index++)
          {
            CreateItemWithStickyChance(&strengthItems[index],sJirachiItems[DungeonRandInt(ARRAY_COUNT(sJirachiItems))],0);
          }

          pos.x = (jirachiEntity->pos.x + DungeonRandInt(3) - 1);
          pos.y = (jirachiEntity->pos.y + DungeonRandInt(3) + -1);

          if ((GetTileMut(pos.x, pos.y)->terrainType & 3) != 0) {
            PlaySoundEffect(400);
            sub_808BB3C(&pos);
            sub_8046860(jirachiEntity,&pos,strengthItems,4);
          }
        }
        GetEntInfo(jirachiEntity)->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105BF4);
        sub_803E708(10,0x46);
    }
    if (wishChoice == 5) {
        s32 direction;
        // Something Good...
        DisplayDungeonDialogue(&gUnknown_8105D2C);
        sub_803E708(10,0x46);
        JirachiWishGrantDialogue(jirachiEntity);
        GetEntInfo(jirachiEntity)->unk15D  = 0;
        DisplayDungeonDialogue(&gUnknown_8105D80);
        sub_803E708(10,0x46);
        LeaderPos = &GetLeader()->pos;
        direction = GetDirectionTowardsPosition(&jirachiEntity->pos,LeaderPos);
        SetFacingDirection(jirachiEntity,direction);
        sub_803E708(10,0x46);
        DisplayDungeonDialogue(&gUnknown_8105D9C);
        sub_803E708(10,0x46);
        gDungeon->unk644.unk30 = 1;
    }
    break;
  }

  DisplayDungeonDialogue(&gUnknown_81058E0);
  JirachiSpinEffect(jirachiEntity);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_810593C);
  sub_803E708(10,0x46);
  EnableJirachiWishWarpTile();
}

void JirachiReFightDialogue(void)
{
    if(HasRecruitedMon(MONSTER_JIRACHI))
    {
        sub_8086448();
        sub_80866C4(&gJirachiReFightDialogue_1);
    }
    else
    {
        JirachiPreFightDialogue();
    }
}

static void JirachiWishGrantFlash(void)
{
  s32 iVar1;

  PlaySoundEffect(0x2c1);
  gDungeonBrightness = 0x1f;

  for(iVar1 = 0xFA; iVar1 > 0x95; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 > 0xC7; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);

  for(iVar1 = 0xFA; iVar1 >= 0; iVar1 -= 10)
  {
    SetDungeonBGColorRGB(iVar1,iVar1,iVar1,1,1);
    DungeonRunFrameActions(0x46);
  }
  sub_803E708(10,0x46);
  sub_8085EB0();
}

static void sub_808BB3C(DungeonPos *pos1)
{
    s32 x, y;
    DungeonPos newPos;

    x = X_POS_TO_PIXELPOS(pos1->x);
    newPos.x = x / 256;

    y = Y_POS_TO_PIXELPOS(pos1->y);
    newPos.y = y / 256;

    sub_8085EC8(100,0,0,&newPos,0);
}

static void sub_808BBA8(Entity *jirachiEntity)
{
  ResetMonEntityData(GetEntInfo(jirachiEntity),0);
}

static void JirachiDropInEffect(Entity *jirachiEntity)
{
  s24_8 iVar1;
  s24_8 iVar2;

  sub_80861F8(0x1b,jirachiEntity,0);
  sub_8086A54(jirachiEntity);
  sub_80861B8(jirachiEntity,0xe,DIRECTION_SOUTH);
  iVar1 = IntToF248(160);
  iVar2 = IntToF248(2);
  PlaySoundEffect(0x1f8);
  while (1) {
    iVar1.raw = iVar1.raw - iVar2.raw; // FRAGILE! Subtraction and assignment below must use .raw
    if (F248LessThanInt(iVar1, 24)) {
      iVar2.raw = IntToF248_2(1).raw;
    }
    if (F248LessThanInt(iVar1, 0)) break;
    GetEntInfo(jirachiEntity)->unk174 = iVar1;
    DungeonRunFrameActions(0x46);
  }
  GetEntInfo(jirachiEntity)->unk174 = IntToF248_2(0);
}

static void JirachiSpinEffect(Entity * jirachiEntity)
{
  s32 uVar1;

  PlaySoundEffect(0x298);
  for(uVar1 = 0; uVar1 < 25; uVar1++){
    SetFacingDirection(jirachiEntity, uVar1 & DIRECTION_MASK);
    sub_803E708(3,0x46);
  }
  GetEntInfo(jirachiEntity)->unk15E = 1;
  PlaySoundEffect(0x27f);
  sub_80861F8(99,jirachiEntity,1);
}

static void JirachiWishGrantDialogue(Entity *jirachiEntity)
{
  u32 uVar2;

  GetEntInfo(jirachiEntity)->unk15D = 1;
  // Nnnnnnnnnn!
  DisplayDungeonDialogue(&gUnknown_81058A8);
  PlaySoundEffect(0x375);
  sub_80861F8(0x67,jirachiEntity,1);
  PlaySoundEffect(0x2a8);
  uVar2 = sub_80861F8(0x68,jirachiEntity,0);
  // Taaaaaaaah!
  DisplayDungeonDialogue(&gUnknown_81058C4);
  if (sub_800E9A8(uVar2)) {
    sub_800DC14(uVar2);
  }
  sub_803E708(10,0x46);
  JirachiWishGrantFlash();
}

// Warp Tile is created but not enabled until the Wish is done with EnableJirachiWishWarpTile
static void CreateJirachiWishWarpTile(void)
{
  Tile *tile;

  tile = GetTileMut(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType &= ~TERRAIN_TYPE_STAIRS;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
}

static void EnableJirachiWishWarpTile(void)
{
  Tile *tile;

  tile = GetTileMut(gDungeon->unkE220[7].x, gDungeon->unkE220[7].y);
  tile->terrainType &= ~(TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY);
  tile->terrainType |= TERRAIN_TYPE_NORMAL;
  tile->terrainType &= ~TERRAIN_TYPE_IMPASSABLE_WALL;
  tile->terrainType |= TERRAIN_TYPE_STAIRS;
  tile->unk8 = 1;
  sub_8049884();
  sub_8049B8C();
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
}

static u8 JirachiFriendAreaSearch(void)
{
  u8 unlockCondition;
  s32 friendAreaCounter;
  s32 numUnlockableAreas;
  u8 friendAreas[NUM_FRIEND_AREAS];
  u32 friendAreaIndex;

  // Build a copy of friend area list and keep track of
  // how many are only Story Unlockable
  numUnlockableAreas = 0;
  for(friendAreaCounter = 1; friendAreaCounter < NUM_FRIEND_AREAS; friendAreaCounter++){
    unlockCondition = GetFriendAreaUnlockCondition(friendAreaCounter);
    if (!(unlockCondition == UNLOCK_LEGENDARY_REQUEST)){
        if (!(unlockCondition == UNLOCK_WONDER_MAIL)){
            if(!gFriendAreas[friendAreaCounter]) {
                friendAreas[numUnlockableAreas] = friendAreaCounter;
                numUnlockableAreas++;
            }
        }
    }
  }

  if (numUnlockableAreas == 0) {
    return NUM_FRIEND_AREAS;
  }
  else {
      // Randomly pick 1
    friendAreaIndex = DungeonRandInt(numUnlockableAreas);
    return friendAreas[friendAreaIndex];
  }
}


