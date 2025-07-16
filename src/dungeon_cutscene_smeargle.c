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
extern void UpdateMinimap(void);
extern void sub_8086A54(Entity *);
extern void ResetMonEntityData(EntityInfo *, u32);
extern void sub_8041888(u32);
extern u32 sub_80861F8(u32, Entity *, u32);
extern u8 sub_80860A8(u32);
extern void sub_8052D44(s16 *, Entity *, Entity *);
extern void SpawnDroppedItemWrapper(Entity *, DungeonPos *, Item *);
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

void DummyFightDialogue(void)
{
}

void sub_808CBB0(void)
{
    Entity *leaderEntity;
    Entity *smeargleEntity;

    leaderEntity = xxx_call_GetLeader();
    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(smeargleEntity, DIRECTION_SOUTH);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SMEARGLE);
}

void SmeargleRescueDialogue(void)
{
    Entity *smeargleEntity;
    s32 counter;

    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    SpriteLookAroundEffect(smeargleEntity);
    sub_803E708(0xA, 0x46);
    // Ohhh...
    // I've lost my bearings
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(smeargleEntity, 4, 2, DIRECTION_NORTH);
    sub_803E708(0xA, 0x46);
    // I can't get out...
    // I'm hungry...
    // I'm in trouble
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(smeargleEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(smeargleEntity, 4, 2, DIRECTION_SOUTH);
    // Oh! You are?
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(smeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(smeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(smeargleEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Did you maybe come to rescue me?
    // Am I glad to see you
    DisplayDungeonDialogue(&gSmeargleRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(smeargleEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(smeargleEntity, 0, 0x100);
        DungeonRunFrameActions(0x46);
    }
    sub_806CE68(smeargleEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(smeargleEntity);
    HandleFaint(smeargleEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CD44(void)
{
    Entity *leaderEntity;
    Entity *smeargleEntity;

    leaderEntity = xxx_call_GetLeader();
    smeargleEntity = GetEntityFromMonsterBehavior(BEHAVIOR_SMEARGLE);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    HandleFaint(smeargleEntity, 540, 0);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_SMEARGLE);
}
