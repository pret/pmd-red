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


static void SkarmoryEntry(Entity * skarmoryEntity);

void sub_8086B14(void)
{
  Entity * leaderEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  leaderEntity = CutsceneGetLeader();
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT);
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8086A3C(skarmoryEntity);
  GetEntInfo(diglettEntity)->unk15C = 1;
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 2);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2],MONSTER_DIGLETT);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_SKARMORY);
}

void sub_8086B94(void)
{
  Entity * leaderEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  leaderEntity = CutsceneGetLeader();
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT);
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);

  HandleFaint_Async(skarmoryEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  HandleFaint_Async(diglettEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
}

void HandleSkarmoryBossFaint(u8 monsterBehavior, u8 cutscene)
{
    if ((cutscene == CUTSCENE_MT_STEEL_ATTEMPT1 || cutscene == CUTSCENE_MT_STEEL_ATTEMPT2) && monsterBehavior == BEHAVIOR_SKARMORY) {
        SetTempCutsceneFlag(CUTSCENE_FLAG_MT_STEEL_COMPLETE);
        gDungeon->unk2 = DUNGEON_UNK2_1;
    }
}

void SkarmoryPreFightDialogue(void)
{
  Entity *leaderEntity;
  Entity *partnerEntity;
  Entity * diglettEntity;
  Entity * skarmoryEntity;

  PixelPos pos1;
  PixelPos pos2;

  leaderEntity = CutsceneGetLeader(); // Player
  partnerEntity = CutsceneGetPartner(); // Partner
  diglettEntity = GetEntityFromMonsterBehavior(BEHAVIOR_DIGLETT); // Diglett
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY); // Skarmory

  pos1.x = diglettEntity->pixelPos.x;
  pos1.y = diglettEntity->pixelPos.y + 0x3000;

  pos2.x = skarmoryEntity->pixelPos.x;
  pos2.y = skarmoryEntity->pixelPos.y + 0x2000;

  sub_8086448();
  DungeonWaitFrames_Async(10,0x46);
  SpriteShockEffect(partnerEntity);
  DungeonWaitFrames_Async(0x20,0x46);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&pos1,0x40);
  DungeonWaitFrames_Async(0x40,0x46);
  ShiftCameraToPosition(&pos2,0x30);
  DisplayDungeonDialogue_Async(gSkarmoryPreFightDialogue_2);
  DungeonWaitFrames_Async(10,0x46);
  GetEntInfo(diglettEntity)->unk15D = 1;
  ShiftCameraToPosition(&pos1,0x30);
  DisplayDungeonDialogue_Async(&gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  DungeonWaitFrames_Async(10,0x46);
  ShiftCameraToPosition(&pos2,0x20);
  DungeonWaitFrames_Async(0x20,0x46);
  SkarmoryEntry(skarmoryEntity);
  DisplayDungeonDialogue_Async(&gSkarmoryPreFightDialogue_4); // Skarmory: You!\nWhat do you think you're doing here?!
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(gSkarmoryPreFightDialogue_5);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gSkarmoryPreFightDialogue_6);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(gSkarmoryPreFightDialogue_7);
  DungeonWaitFrames_Async(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue_Async(&gSkarmoryPreFightDialogue_8);
  DungeonWaitFrames_Async(10,0x46);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_EAST);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_WEST);
  DisplayDungeonDialogue_Async(gSkarmoryPreFightDialogue_9);
  CutsceneLookDir_Async(partnerEntity,4,DIR_TRANS_SPINLEFT1,DIRECTION_NORTH);
  CutsceneLookDir_Async(leaderEntity,4,DIR_TRANS_SPINRIGHT1,DIRECTION_NORTH);
  DungeonWaitFrames_Async(10,0x46);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
}

void SkarmoryReFightDialogue(void)
{
  Entity * leaderEntity;
  Entity * skarmoryEntity;
  PixelPos pos;

  leaderEntity = CutsceneGetLeader();
  skarmoryEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SKARMORY);
  pos.x = skarmoryEntity->pixelPos.x;
  pos.y = skarmoryEntity->pixelPos.y + 0x2000;
  sub_8086448();
  DungeonWaitFrames_Async(10,0x46);
  SkarmoryEntry(skarmoryEntity);
  ShiftCameraToPosition(&pos,0x10);
  DisplayDungeonDialogue_Async(&gSkarmoryReFightDialogue_1);
  DungeonWaitFrames_Async(10,0x46);
  DisplayDungeonDialogue_Async(&gSkarmoryReFightDialogue_2);
  DungeonWaitFrames_Async(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue_Async(&gSkarmoryReFightDialogue_3);
  DungeonWaitFrames_Async(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
}

void sub_8086E40(void)
{
    CutsceneLookAroundEffect_Async(CutsceneGetLeader());
    DungeonWaitFrames_Async(10, 70);
    DisplayDungeonDialogue_Async(&gUnknown_8100D3C);
    DungeonWaitFrames_Async(10, 70);
    gDungeon->unk2 = DUNGEON_UNK2_1;
}

static void SkarmoryEntry(Entity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,DIRECTION_SOUTH);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  DungeonWaitFrames_Async(0x44,0x46);
}

