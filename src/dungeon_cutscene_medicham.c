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

void sub_808C9C4(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = xxx_call_GetLeader();
    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_80855E4(sub_8086A3C);
    SetFacingDirection(medichamEntity, DIRECTION_SOUTH);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y - 3);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MEDICHAM);
}

void MedichamRescueDialogue(void)
{
    Entity *medichamEntity;
    s32 counter;

    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    SpriteLookAroundEffect(medichamEntity);
    sub_803E708(0xA, 0x46);
    // Oh my I can't seem to find a way out...
    DisplayDungeonDialogue(&gMedichamRescueDialogue_1);
    sub_803E708(0xA, 0x46);
    sub_80869E4(medichamEntity, 4, 2, DIRECTION_NORTH);
    sub_803E708(0xA, 0x46);
    // What am I to do...?
    DisplayDungeonDialogue(&gMedichamRescueDialogue_2);
    sub_803E708(0xA, 0x46);
    sub_8086448();
    sub_8086598();
    sub_803E708(0x20, 0x46);
    SpriteShockEffect(medichamEntity);
    sub_803E708(0x20, 0x46);
    sub_80869E4(medichamEntity, 4, 2, DIRECTION_SOUTH);
    DisplayDungeonDialogue(&gMedichamRescueDialogue_3);
    sub_803E708(0xA, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(medichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    sub_806CE68(medichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x4, 0x46);
    PlaySoundEffect(0x1c7);
    sub_806CDD4(medichamEntity, 0xA, DIRECTION_SOUTH);
    sub_803E708(0x14, 0x46);
    // Yes Yes
    // I am so lucky
    //
    // There appears to be no one here
    DisplayDungeonDialogue(&gMedichamRescueDialogue_4);
    sub_803E708(0xA, 0x46);
    sub_806CDD4(medichamEntity, 0, DIRECTION_SOUTH);
    for(counter = 0x17; counter >= 0; counter--)
    {
        IncreaseEntityPixelPos(medichamEntity, 0, 0x100);
        DungeonRunFrameActions(0x46);
    }
    sub_806CE68(medichamEntity, DIRECTION_SOUTH);
    sub_803E708(0x20, 0x46);
    sub_8042B0C(medichamEntity);
    sub_8068FE0(medichamEntity, 0x21C, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CB5C(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = xxx_call_GetLeader();
    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    sub_8068FE0(medichamEntity, 0x21C, 0);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MEDICHAM);
}

