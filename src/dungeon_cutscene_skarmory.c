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

extern void sub_8049884(void);
extern void sub_8049B8C(void);
extern void sub_8052D44(s16 *, Entity *, Entity *);

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

  HandleFaint(skarmoryEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  HandleFaint(diglettEntity,DUNGEON_EXIT_DELETED_FOR_EVENT,0);
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y);
}

void sub_8086BDC(u8 param_1, u8 param_2)
{
    if ((param_2 == 1 || param_2 == 2) && param_1 == 3) {
        sub_8097FA8(1);
        gDungeon->unk2 = 1;
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
  sub_803E708(10,0x46);
  SpriteShockEffect(partnerEntity);
  sub_803E708(0x20,0x46);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_1);
  ShiftCameraToPosition(&pos1,0x40);
  sub_803E708(0x40,0x46);
  ShiftCameraToPosition(&pos2,0x30);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_2);
  sub_803E708(10,0x46);
  GetEntInfo(diglettEntity)->unk15D = 1;
  ShiftCameraToPosition(&pos1,0x30);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_3); // Diglett: ...I...\nI'm scared.
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&pos2,0x20);
  sub_803E708(0x20,0x46);
  SkarmoryEntry(skarmoryEntity);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_4); // Skarmory: You!\nWhat do you think you're doing here?!
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_5);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_6);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_7);
  sub_803E708(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue(&gSkarmoryPreFightDialogue_8);
  sub_803E708(10,0x46);
  sub_80869E4(partnerEntity,4,1,DIRECTION_EAST);
  sub_80869E4(leaderEntity,4,2,DIRECTION_WEST);
  DisplayDungeonDialogue(gSkarmoryPreFightDialogue_9);
  sub_80869E4(partnerEntity,4,2,DIRECTION_NORTH);
  sub_80869E4(leaderEntity,4,1,DIRECTION_NORTH);
  sub_803E708(10,0x46);
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
  sub_803E708(10,0x46);
  SkarmoryEntry(skarmoryEntity);
  ShiftCameraToPosition(&pos,0x10);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_1);
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_2);
  sub_803E708(10,0x46);
  sub_806CDD4(skarmoryEntity,0xd,DIRECTION_SOUTH);
  DisplayDungeonDialogue(&gSkarmoryReFightDialogue_3);
  sub_803E708(10,0x46);
  ShiftCameraToPosition(&leaderEntity->pixelPos,0x10);
  DungeonStartNewBGM(MUS_BOSS_BATTLE);
}

void sub_8086E40(void)
{
  SpriteLookAroundEffect(CutsceneGetLeader());
  sub_803E708(10,0x46);
  DisplayDungeonDialogue(&gUnknown_8100D3C);
  sub_803E708(10,0x46);
  gDungeon->unk2 = 1;
}

static void SkarmoryEntry(Entity * skarmoryEntity)
{
  sub_806CDD4(skarmoryEntity,0xf,DIRECTION_SOUTH);
  sub_8086A54(skarmoryEntity);
  PlaySoundEffect(0x1f8);
  sub_803E708(0x44,0x46);
}

