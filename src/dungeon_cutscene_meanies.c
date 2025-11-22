#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "effect_main.h"
#include "dungeon_vram.h"
#include "dungeon_8041AD0.h"
#include "dungeon_mon_sprite_render.h"
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


static void sub_8087144(void);

void sub_8086E9C(void)
{
  Entity * leaderEntity;

  leaderEntity = CutsceneGetLeader();
  DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
  sub_8085374();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_808563C(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_METAPOD);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GENGAR);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[4], MONSTER_CATERPIE);
}

void sub_8086F00(void)
{
  Entity * leaderEntity;

  leaderEntity = CutsceneGetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_METAPOD);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GENGAR);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[4], MONSTER_CATERPIE);
}

void HandleMeaniesBossFaint(u8 monsterBehavior, u8 cutscene)
{
    s32 i;

    if (cutscene == CUTSCENE_SINISTER_WOODS_ATTEMPT1 || cutscene == CUTSCENE_SINISTER_WOODS_ATTEMPT2)  {
        bool8 stillAlive = FALSE;

        for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++) {
            struct Entity *entity = gDungeon->wildPokemon[i];
            if ((EntityIsValid(entity))) {
                struct EntityInfo *entInfo = GetEntInfo(entity);
                if (entInfo->monsterBehavior != monsterBehavior) {
                    stillAlive = TRUE;
                    return;
                }
            }
        }

        if (!stillAlive) {
            SetTempCutsceneFlag(CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE);
            gDungeon->unk2 = DUNGEON_UNK2_1;
        }
    }
}

void TeamMeaniesPreFightDialogue(void)
{
    Entity *leaderEntity;

    leaderEntity = CutsceneGetLeader();
    sub_8086448();
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(gTeamMeaniesPreFightDialogue_1);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_2);
    DungeonWaitFrames_Async(10, 0x46);
    sub_8087144();
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_3);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(gTeamMeaniesPreFightDialogue_4);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_5);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_6);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_7);
    DungeonWaitFrames_Async(10, 0x46);
    ShiftCameraToPosition(&leaderEntity->pixelPos, 0x10);
}

void TeamMeaniesReFightDialogue(void)
{
    Entity *leaderEntity;
    Entity *partnerEntity;

    leaderEntity = CutsceneGetLeader();
    partnerEntity = CutsceneGetPartner();
    sub_8086448();
    DisplayDungeonDialogue_Async(gTeamMeaniesReFightDialogue_1);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesPreFightDialogue_2);
    DungeonWaitFrames_Async(10, 0x46);
    sub_8087144();
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(gTeamMeaniesReFightDialogue_2);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesReFightDialogue_3);
    DungeonWaitFrames_Async(10, 0x46);
    sub_806CDD4(leaderEntity, 6, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 6, DIRECTION_NORTH);
    DungeonWaitFrames_Async(10, 0x46);
    sub_806CDD4(leaderEntity, 7, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 7, DIRECTION_NORTH);
    DungeonWaitFrames_Async(10, 0x46);
    DisplayDungeonDialogue_Async(&gTeamMeaniesReFightDialogue_4);
    DisplayDungeonDialogue_Async(&gTeamMeaniesReFightDialogue_5);
    DungeonWaitFrames_Async(10, 0x46);
    ShiftCameraToPosition(&leaderEntity->pixelPos, 0x10);
}

void sub_8087130(void)
{
    sub_8086448();
    sub_80866C4(&gUnknown_8101440);
}

static void sub_8087144(void)
{
    Entity *gengarEntity = GetEntityFromMonsterBehavior(BEHAVIOR_GENGAR);
    Entity *ekansEntity = GetEntityFromMonsterBehavior(BEHAVIOR_EKANS);
    Entity *medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    s16 auStack_10c[28] = {4, 2, 12, 0, 3, 2, 24, 0, 4, 2, 24, 0, 5, 2, 12, 0, 6, 2, 12, 0, 0, 0, 0, 0, 0, 11, 8, 0};
    s16 puStack_60[28] =  {4, 2, 12, 0, 3, 2, 24, 0, 4, 2, 24, 0, 5, 2, 12, 0, 6, 2, 12, 0, 0, 0, 0, 0, 0, 12, 8, 0};
    s16 puStack_5c[28] =  {4, 2, 12, 0, 5, 2, 12, 0, 4, 2, 12, 0, 4, 2, 24, 0, 3, 2, 12, 0, 0, 0, 0, 0, 0, 10, 8, 0};
    s16 *puStack_64[3];
    Entity *pEStack_58[3];
    struct_8085B80 auStack_4c[3];

    puStack_64[0] = auStack_10c;
    puStack_64[1] = puStack_60;
    puStack_64[2] = puStack_5c;
    pEStack_58[0] = gengarEntity;
    pEStack_58[1] = ekansEntity;
    pEStack_58[2] = medichamEntity;
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    sub_8086A54(gengarEntity);
    sub_8086A54(ekansEntity);
    sub_8086A54(medichamEntity);
    sub_8085B4C(auStack_4c,puStack_64,pEStack_58,3);
    GetEntInfo(gengarEntity)->unk15F = 1;
    GetEntInfo(ekansEntity)->unk15F = 1;
    GetEntInfo(medichamEntity)->unk15F = 1;
    while( TRUE ) {
        if (!sub_8085B80(auStack_4c)) break;
        DungeonRunFrameActions(0x46);
    }
    GetEntInfo(gengarEntity)->unk15F = 0;
    GetEntInfo(ekansEntity)->unk15F = 0;
    GetEntInfo(medichamEntity)->unk15F = 0;
}

