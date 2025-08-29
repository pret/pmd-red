#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "code_8041AD0.h"
#include "code_804267C.h"
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
#include "dungeon_map.h"

extern void sub_8042B0C(Entity *);
extern u8 sub_806FD18(Entity *);
extern void sub_806FDF4(Entity *, Entity *, Entity **);
extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void sub_8086A3C(Entity *pokemon);
extern void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex);
extern u8 sub_8086AE4(s16 _index);

static void sub_808B1CC(u8 itemID);
static void SetupRegiFacingDirection(Entity *regiEntity);
static void SetupRegirockFightHP(Entity *r0);
static void SetupRegiceFightHP(Entity *r0);
static void SetupRegisteelFightHP(Entity *r0);

void sub_808ACC0(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGIROCK)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGIROCK);
    HandleFaint(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ROCK_PART);
  }
  else if (sub_80860A8(ITEM_ROCK_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGIROCK);
  }
}

void sub_808AD48(void)
{
  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGICE)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGICE);
    HandleFaint(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_ICE_PART);
  }
  else if (sub_80860A8(ITEM_ICE_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGICE);
  }
}

void sub_808ADCC(void)
{

  Entity * entity;

  if (HasRecruitedMon(MONSTER_REGISTEEL)) {
    entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGISTEEL);
    HandleFaint(entity,0x21c,0);
    sub_8097FA8(0x22);
    sub_8097FA8(0x1d);
    sub_808B1CC(ITEM_STEEL_PART);
  }
  else if (sub_80860A8(ITEM_STEEL_PART) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else if (sub_80860A8(ITEM_MUSIC_BOX) != 0) {
        sub_8098044(0x22);
        sub_8097FA8(0x1d);
  }
  else {
        sub_8098044(0x22);
        sub_8098044(0x1d);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGISTEEL);
  }
}

void sub_808AE54(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2E) && (param_1 == 0x17)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToItem(&item,ITEM_ROCK_PART,0);
      SpawnDroppedItemWrapper(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regirock's body
      // Regirock was apparently guarding this item
      DisplayDungeonDialogue(&gRegirockPostFightDialogue_1);
    }
  }
}

void sub_808AEC8(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x2F) && (param_1 == 0x18)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToItem(&item,ITEM_ICE_PART,0);
      SpawnDroppedItemWrapper(GetLeader(),param_3,&item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Regice's body
      // Regice was apparently guarding this item
      DisplayDungeonDialogue(&gRegicePostFightDialogue_1);
    }
  }
}

void sub_808AF3C(u8 param_1,u8 param_2,DungeonPos *param_3)
{
  Entity * leaderEntity;
  s16 IDStack[2];
  Item item;


  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_2 == 0x30) && (param_1 == 0x19)) {
    sub_808B1CC(ITEM_NOTHING);
    if (!sub_8098100(0x1d)) {
      ItemIdToItem(&item,ITEM_STEEL_PART,0);
      SpawnDroppedItemWrapper(GetLeader(),param_3, &item);
      DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
      // Something fell from Registeel's body
      // Registeel was apparently guarding this item
      DisplayDungeonDialogue(&gRegisteelPostFightDialogue_1);
    }
  }
}

void sub_808AFB0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2E) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ROCK_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Rock Part that Regirock was guarding
    DisplayDungeonDialogue(&gRegirockPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B030(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x2F) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_ICE_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],GetLeader(),0);
    // {POKEMON_0} obtained the Ice Part that Regice was guarding
    DisplayDungeonDialogue(&gRegicePostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void sub_808B0B0(u8 param_1)
{
  Entity * leaderEntity;
  s16 IDStack [2];

  leaderEntity = CutsceneGetLeader();
  sub_8052D44(IDStack,leaderEntity,0);
  if (!sub_8098100(0x22) && (param_1 == 0x30) && (!sub_8098100(0x1d)) && (sub_80860A8(ITEM_STEEL_PART) != 0)) {
    sub_8097FD0(0x1d);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
    // {POKEMON_0} obtained the Steel Part that Registeel was guarding
    DisplayDungeonDialogue(&gRegisteelPostFightDialogue_2);
    sub_80421C0(0,0xd4);
    sub_803E708(10,70);
    sub_8046D20();
  }
}

void RegirockPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegirockPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegicePreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (!sub_8098100(0x22)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue(&gRegisteelPreFightDialogue_1);
    sub_803E708(10,70);
    sub_808563C(SetupRegisteelFightHP);
  }
}

static void sub_808B1CC(u8 itemID)
{
    Entity *entity;
    Tile *tile;
    DungeonPos pos;
    Item item;

    pos.x = gDungeon->unk644.unk40;
    pos.y = gDungeon->unk644.unk42;
    if ((pos.x < 0) || (pos.y  < 0)) {
        entity = GetLeader();
        if (entity == NULL) {
            gDungeon->unk2 = 1;
            return;
        }
        pos.x = entity->pos.x;
        pos.y = entity->pos.y;
    }
    sub_807FE04(&pos, 0);
    tile = GetTileMut(pos.x, pos.y);
    tile->terrainFlags = tile->terrainFlags | TERRAIN_TYPE_STAIRS;
    if (((itemID != ITEM_NOTHING) && (sub_80860A8(itemID) == 0)) &&
        (sub_80860A8(ITEM_MUSIC_BOX) == 0)) {
        ItemIdToItem(&item,itemID,0);
        pos.y--;
        SpawnItem(&pos,&item,1);
    }
    UpdateTrapsVisibility();
    UpdateMinimap();
}

static void SetupRegiFacingDirection(Entity *regiEntity)
{
    GetEntInfo(regiEntity)->action.direction = DIRECTION_NORTH;
    sub_806CE68(regiEntity, DIRECTION_NORTH);
}

static void SetupRegirockFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}

static void SetupRegiceFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}

static void SetupRegisteelFightHP(Entity *r0)
{
    SetupBossFightHP(r0, 450, MUS_BOSS_BATTLE);
}



