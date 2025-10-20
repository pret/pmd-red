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

void sub_808C9C4(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = CutsceneGetLeader();
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
    HandleFaint(medichamEntity, DUNGEON_EXIT_DELETED_FOR_EVENT, 0);
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 4;
}

void sub_808CB5C(void)
{
    Entity *leaderEntity;
    Entity *medichamEntity;

    leaderEntity = CutsceneGetLeader();
    medichamEntity = GetEntityFromMonsterBehavior(BEHAVIOR_MEDICHAM);
    DungeonStartNewBGM(MUS_IN_THE_DEPTHS_OF_THE_PIT);
    sub_80854D4();
    sub_8085930(DIRECTION_NORTH);
    HandleFaint(medichamEntity, DUNGEON_EXIT_DELETED_FOR_EVENT, 0);
    sub_8085860(leaderEntity->pos.x, leaderEntity->pos.y);
    CopyMonsterNameToBuffer(gFormatBuffer_Monsters[2], MONSTER_MEDICHAM);
}

