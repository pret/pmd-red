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

static void sub_8087144(void);

void sub_8086E9C(void)
{
  Entity * leaderEntity;

  leaderEntity = xxx_call_GetLeader();
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

  leaderEntity = xxx_call_GetLeader();
  sub_80854D4();
  sub_8085930(DIRECTION_NORTH);
  sub_80855E4(sub_8086A3C);
  sub_8085860(leaderEntity->pos.x,leaderEntity->pos.y - 3);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_METAPOD);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[3], MONSTER_GENGAR);
  CopyMonsterNameToBuffer(gFormatBuffer_Monsters[4], MONSTER_CATERPIE);
}

void sub_8086F54(u8 param_1, u8 param_2)
{
    s32 index;

    if (param_2 == 4 || param_2 == 5)  {
        bool8 found = FALSE;
        for (index = 0; index < 0x10; index++) {
            struct Entity *entity = gDungeon->wildPokemon[index];
            if ((EntityIsValid(entity))) {
                struct EntityInfo *entInfo = GetEntInfo(entity);
                if (entInfo->monsterBehavior != param_1) {
                    found = TRUE;
                    return;
                }
            }
        }

        if (!found) {
            sub_8097FA8(3);
            gDungeon->unk2 = 1;
        }
    }
}

void TeamMeaniesPreFightDialogue(void)
{
    Entity *leaderEntity;

    leaderEntity = xxx_call_GetLeader();
    sub_8086448();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    DungeonStartNewBGM(MUS_THERES_TROUBLE);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_3);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesPreFightDialogue_4);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_5);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_6);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_7);
    sub_803E708(10, 0x46);
    ShiftCameraToPosition(&leaderEntity->pixelPos, 0x10);
}

void TeamMeaniesReFightDialogue(void)
{
    Entity *leaderEntity;
    Entity *partnerEntity;

    leaderEntity = xxx_call_GetLeader();
    partnerEntity = GetPartnerEntity();
    sub_8086448();
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_1);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesPreFightDialogue_2);
    sub_803E708(10, 0x46);
    sub_8087144();
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(gTeamMeaniesReFightDialogue_2);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_3);
    sub_803E708(10, 0x46);
    sub_806CDD4(leaderEntity, 6, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 6, DIRECTION_NORTH);
    sub_803E708(10, 0x46);
    sub_806CDD4(leaderEntity, 7, DIRECTION_NORTH);
    sub_806CDD4(partnerEntity, 7, DIRECTION_NORTH);
    sub_803E708(10, 0x46);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_4);
    DisplayDungeonDialogue(&gTeamMeaniesReFightDialogue_5);
    sub_803E708(10, 0x46);
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

