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
#include "dungeon_map.h"


static void sub_808B1CC(u8 itemID);
static void SetupRegiFacingDirection(Entity *regiEntity);
static void SetupRegirockFightHP(Entity *r0);
static void SetupRegiceFightHP(Entity *r0);
static void SetupRegisteelFightHP(Entity *r0);

void sub_808ACC0(void)
{
    if (HasRecruitedMon(MONSTER_REGIROCK)) {
        Entity *entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGIROCK);
        HandleFaint_Async(entity, DUNGEON_EXIT_DELETED_FOR_EVENT, NULL);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_808B1CC(ITEM_ROCK_PART);
    }
    else if (ItemInInventoryOrHeld(ITEM_ROCK_PART)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else if (ItemInInventoryOrHeld(ITEM_MUSIC_BOX)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGIROCK);
    }
}

void sub_808AD48(void)
{
    if (HasRecruitedMon(MONSTER_REGICE)) {
        Entity *entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGICE);
        HandleFaint_Async(entity, DUNGEON_EXIT_DELETED_FOR_EVENT, NULL);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_808B1CC(ITEM_ICE_PART);
    }
    else if (ItemInInventoryOrHeld(ITEM_ICE_PART)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else if (ItemInInventoryOrHeld(ITEM_MUSIC_BOX)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGICE);
    }
}

void sub_808ADCC(void)
{
    if (HasRecruitedMon(MONSTER_REGISTEEL)) {
        Entity *entity = GetEntityFromMonsterBehavior(BEHAVIOR_REGISTEEL);
        HandleFaint_Async(entity, DUNGEON_EXIT_DELETED_FOR_EVENT, NULL);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_808B1CC(ITEM_STEEL_PART);
    }
    else if (ItemInInventoryOrHeld(ITEM_STEEL_PART)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else if (ItemInInventoryOrHeld(ITEM_MUSIC_BOX)) {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        SetTempCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
    }
    else {
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED);
        UnsetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        sub_80855E4(SetupRegiFacingDirection);
        CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_REGISTEEL);
    }
}

void HandleRegirockBossFaint_Async(u8 monsterBehavior, u8 cutscene, DungeonPos *pos)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGIROCK && monsterBehavior == BEHAVIOR_REGIROCK) {
        sub_808B1CC(ITEM_NOTHING);
        if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED)) {
            Item item;

            ItemIdToItem(&item, ITEM_ROCK_PART, FALSE);
            SpawnDroppedItemWrapper(GetLeader(),pos,&item);
            DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
            // Something fell from Regirock's body
            // Regirock was apparently guarding this item
            DisplayDungeonDialogue_Async(&gRegirockPostFightDialogue_1);
        }
    }
}

void HandleRegiceBossFaint_Async(u8 monsterBehavior, u8 cutscene, DungeonPos *pos)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGICE && monsterBehavior == BEHAVIOR_REGICE) {
        sub_808B1CC(ITEM_NOTHING);
        if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED)) {
            Item item;

            ItemIdToItem(&item, ITEM_ICE_PART, FALSE);
            SpawnDroppedItemWrapper(GetLeader(), pos, &item);
            DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
            // Something fell from Regice's body
            // Regice was apparently guarding this item
            DisplayDungeonDialogue_Async(&gRegicePostFightDialogue_1);
        }
    }
}

void HandleRegisteelBossFaint_Async(u8 monsterBehavior, u8 cutscene, DungeonPos *pos)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGISTEEL && monsterBehavior == BEHAVIOR_REGISTEEL) {
        sub_808B1CC(ITEM_NOTHING);
        if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED)) {
            Item item;

            ItemIdToItem(&item, ITEM_STEEL_PART, FALSE);
            SpawnDroppedItemWrapper(GetLeader(), pos, &item);
            DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
            // Something fell from Registeel's body
            // Registeel was apparently guarding this item
            DisplayDungeonDialogue_Async(&gRegisteelPostFightDialogue_1);
        }
    }
}

void sub_808AFB0_Async(u8 cutscene)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGIROCK && !GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED) && ItemInInventoryOrHeld(ITEM_ROCK_PART)) {
        SetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
        // {POKEMON_0} obtained the Rock Part that Regirock was guarding
        DisplayDungeonDialogue_Async(&gRegirockPostFightDialogue_2);
        sub_80421C0(0, 212);
        DungeonWaitFrames_Async(10, 70);
        PotentiallyCreateMusicBox_Async();
    }
}

void sub_808B030_Async(u8 cutscene)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGICE && !GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED) && ItemInInventoryOrHeld(ITEM_ICE_PART)) {
        SetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
        // {POKEMON_0} obtained the Ice Part that Regice was guarding
        DisplayDungeonDialogue_Async(&gRegicePostFightDialogue_2);
        sub_80421C0(0, 212);
        DungeonWaitFrames_Async(10, 70);
        PotentiallyCreateMusicBox_Async();
    }
}

void sub_808B0B0_Async(u8 cutscene)
{
    Entity *leaderEntity;
    s16 IDStack[2];

    leaderEntity = CutsceneGetLeader();
    BufferCutsceneProtagonists(IDStack, leaderEntity, NULL);

    if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED) && cutscene == CUTSCENE_REGISTEEL && !GetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED) && ItemInInventoryOrHeld(ITEM_STEEL_PART)) {
        SetCutsceneFlag(CUTSCENE_FLAG_REGI_ITEM_OBTAINED);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], GetLeader(), 0);
        // {POKEMON_0} obtained the Steel Part that Registeel was guarding
        DisplayDungeonDialogue_Async(&gRegisteelPostFightDialogue_2);
        sub_80421C0(0, 212);
        DungeonWaitFrames_Async(10, 70);
        PotentiallyCreateMusicBox_Async();
    }
}

void RegirockPreFightDialogue(void)
{
  if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue_Async(&gRegirockPreFightDialogue_1);
    DungeonWaitFrames_Async(10, 70);
    sub_808563C(SetupRegirockFightHP);
  }
}

void RegicePreFightDialogue(void)
{
  if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue_Async(&gRegicePreFightDialogue_1);
    DungeonWaitFrames_Async(10,70);
    sub_808563C(SetupRegiceFightHP);
  }
}

void RegisteelPreFightDialogue(void)
{
  if (!GetCutsceneFlag(CUTSCENE_FLAG_REGI_RECRUITED)) {
    sub_8085930(DIRECTION_NORTH);
    // INTRUDER ALERT
    // EXTERMINATE
    DisplayDungeonDialogue_Async(&gRegisteelPreFightDialogue_1);
    DungeonWaitFrames_Async(10,70);
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
            gDungeon->unk2 = DUNGEON_UNK2_1;
            return;
        }
        pos.x = entity->pos.x;
        pos.y = entity->pos.y;
    }
    sub_807FE04(&pos, 0);
    tile = GetTileMut(pos.x, pos.y);
    tile->terrainFlags = tile->terrainFlags | TERRAIN_TYPE_STAIRS;
    if (itemID != ITEM_NOTHING && !ItemInInventoryOrHeld(itemID) && !ItemInInventoryOrHeld(ITEM_MUSIC_BOX)) {
        ItemIdToItem(&item, itemID, FALSE);
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



