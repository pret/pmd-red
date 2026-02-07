#include "global.h"
#include "globaldata.h"
#include "dungeon_cutscene.h"
#include "constants/dungeon.h"
#include "constants/direction.h"
#include "constants/dungeon.h"
#include "constants/dungeon_exit.h"
#include "constants/fixed_rooms.h"
#include "constants/weather.h"
#include "structs/str_dungeon.h"
#include "structs/sprite_oam.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "direction_util.h"
#include "dungeon_boss_dialogue.h"
#include "dungeon_cutscenes.h"
#include "dungeon_engine.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_mon_spawn.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_pos_data.h"
#include "dungeon_range.h"
#include "dungeon_music.h"
#include "dungeon_tilemap.h"
#include "dungeon_util.h"
#include "dungeon_vram.h"
#include "effect_data.h"
#include "effect_main.h"
#include "effect_sub_1.h"
#include "exclusive_pokemon.h"
#include "items.h"
#include "math.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "random.h"
#include "sprite.h"
#include "weather.h"

extern OpenedFile *gDungeonPaletteFile;
extern RGB_Struct gUnknown_202ECA4[33];

// Size: R=0x8 | B=0x6
typedef struct FixedRoomCutsceneData
{
    /* 0x0 */ u8 fixedRoomNum; // See enum "FixedRoomID"
    /* 0x1 */ u8 cutscene1; // See enum "CutsceneKind"
    /* 0x2 */ u8 cutscene2Flag; // See enum "CutsceneFlagID"
    /* 0x3 */ u8 cutscene2; // See enum "CutsceneKind"
    /* 0x4 */ u8 cutscene3Flag; // See enum "CutsceneFlagID"
    /* 0x5 */ u8 cutscene3; // See enum "CutsceneKind"
} FixedRoomCutsceneData;

// size: 0x8
typedef struct unkStruct_202F3D0
{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
} unkStruct_202F3D0;

static void sub_8084854(const FixedRoomCutsceneData *data);
static void sub_8085764(void);
static void sub_80857B8(void);
static void sub_80861EC(Entity *);

static const FixedRoomCutsceneData sFixedRoomCutsceneLookup[] = {
    { FIXED_ROOM_MT_STEEL_SKARMORY, CUTSCENE_MT_STEEL_ATTEMPT1, CUTSCENE_FLAG_MT_STEEL_REACHED, CUTSCENE_MT_STEEL_ATTEMPT2, CUTSCENE_FLAG_MT_STEEL_COMPLETE, CUTSCENE_MT_STEEL_POSTSTORY },
    { FIXED_ROOM_SINISTER_WOODS_TEAM_MEANIES, CUTSCENE_SINISTER_WOODS_ATTEMPT1, CUTSCENE_FLAG_SINISTER_WOODS_REACHED, CUTSCENE_SINISTER_WOODS_ATTEMPT2, CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE, CUTSCENE_SINISTER_WOODS_POSTSTORY },
    { FIXED_ROOM_MT_THUNDER_PEAK_ZAPDOS, CUTSCENE_MT_THUNDER_PEAK_ATTEMPT1, CUTSCENE_FLAG_MT_THUNDER_PEAK_REACHED, CUTSCENE_MT_THUNDER_PEAK_ATTEMPT2, CUTSCENE_FLAG_MT_THUNDER_PEAK_COMPLETE, CUTSCENE_MT_THUNDER_PEAK_POSTSTORY },
    { FIXED_ROOM_MT_BLAZE_PEAK_MOLTRES, CUTSCENE_MT_BLAZE_PEAK_ATTEMPT1, CUTSCENE_FLAG_MT_BLAZE_PEAK_REACHED, CUTSCENE_MT_BLAZE_PEAK_ATTEMPT2, CUTSCENE_FLAG_MT_BLAZE_PEAK_COMPLETE, CUTSCENE_MT_BLAZE_PEAK_POSTSTORY },
    { FIXED_ROOM_FROSTY_GROTTO_ARTICUNO, CUTSCENE_FROSTY_GROTTO_ATTEMPT1, CUTSCENE_FLAG_FROSTY_GROTTO_REACHED, CUTSCENE_FROSTY_GROTTO_ATTEMPT2, CUTSCENE_FLAG_FROSTY_GROTTO_COMPLETE, CUTSCENE_FROSTY_GROTTO_POSTSTORY },
    { FIXED_ROOM_MT_FREEZE_PEAK_NINETALES, CUTSCENE_MT_FREEZE_PEAK, CUTSCENE_FLAG_MT_FREEZE_PEAK_COMPLETE, CUTSCENE_MT_FREEZE_PEAK_POSTSTORY, CUTSCENE_FLAG_MT_FREEZE_PEAK_COMPLETE, CUTSCENE_MT_FREEZE_PEAK_POSTSTORY },
    { FIXED_ROOM_MAGMA_CAVERN_PIT_GROUDON, CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1, CUTSCENE_FLAG_MAGMA_CAVERN_PIT_REACHED, CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2, CUTSCENE_FLAG_MAGMA_CAVERN_PIT_COMPLETE, CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY },
    { FIXED_ROOM_MAGMA_CAVERN_PIT_TYRANITAR_ALAKAZAM, CUTSCENE_MAGMA_CAVERN_MID, CUTSCENE_FLAG_MAGMA_CAVERN_MID_REACHED, CUTSCENE_MAGMA_CAVERN_MID_POSTSTORY, CUTSCENE_FLAG_MAGMA_CAVERN_MID_REACHED, CUTSCENE_MAGMA_CAVERN_MID_POSTSTORY },
    { FIXED_ROOM_SKY_TOWER_SUMMIT_RAYQUAZA, CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT1, CUTSCENE_FLAG_SKY_TOWER_SUMMIT_REACHED, CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT2, CUTSCENE_FLAG_SKY_TOWER_SUMMIT_COMPLETE, CUTSCENE_SKY_TOWER_SUMMIT_POSTSTORY },
    { FIXED_ROOM_UPROAR_FOREST_MANKEY, CUTSCENE_UPROAR_FOREST_ATTEMPT1, CUTSCENE_FLAG_UPROAR_FOREST_REACHED, CUTSCENE_UPROAR_FOREST_ATTEMPT2, CUTSCENE_FLAG_UPROAR_FOREST_COMPLETE, CUTSCENE_UPROAR_FOREST_POSTSTORY },
    { FIXED_ROOM_WESTERN_CAVE_MEWTWO, CUTSCENE_WESTERN_CAVE_ATTEMPT1, CUTSCENE_FLAG_WESTERN_CAVE_REACHED, CUTSCENE_WESTERN_CAVE_ATTEMPT2, CUTSCENE_FLAG_WESTERN_CAVE_COMPLETE, CUTSCENE_WESTERN_CAVE_POSTSTORY },
    { FIXED_ROOM_FIERY_FIELD_ENTEI, CUTSCENE_FIERY_FIELD_ATTEMPT1, CUTSCENE_FLAG_FIERY_FIELD_REACHED, CUTSCENE_FIERY_FIELD_ATTEMPT2, CUTSCENE_FLAG_FIERY_FIELD_COMPLETE, CUTSCENE_FIERY_FIELD_POSTSTORY },
    { FIXED_ROOM_LIGHTNING_FIELD_RAIKOU, CUTSCENE_LIGHTNING_FIELD_ATTEMPT1, CUTSCENE_FLAG_LIGHTNING_FIELD_REACHED, CUTSCENE_LIGHTNING_FIELD_ATTEMPT2, CUTSCENE_FLAG_LIGHTNING_FIELD_COMPLETE, CUTSCENE_LIGHTNING_FIELD_POSTSTORY },
    { FIXED_ROOM_NORTHWIND_FIELD_SUICUNE, CUTSCENE_NORTHWIND_FIELD_ATTEMPT1, CUTSCENE_FLAG_NORTHWIND_FIELD_REACHED, CUTSCENE_NORTHWIND_FIELD_ATTEMPT2, CUTSCENE_FLAG_NORTHWIND_FIELD_COMPLETE, CUTSCENE_NORTHWIND_FIELD_POSTSTORY },
    { FIXED_ROOM_MT_FARAWAY_HO_OH, CUTSCENE_MT_FARAWAY, NUM_CUTSCENE_FLAGS, CUTSCENE_MT_FARAWAY, CUTSCENE_FLAG_MT_FARAWAY_COMPLETE, CUTSCENE_MT_FARAWAY_POSTSTORY },
    { FIXED_ROOM_NORTHERN_RANGE_LATIOS, CUTSCENE_NORTHERN_RANGE_ATTEMPT1, CUTSCENE_FLAG_NORTHERN_RANGE_REACHED, CUTSCENE_NORTHERN_RANGE_ATTEMPT2, CUTSCENE_FLAG_NORTHERN_RANGE_COMPLETE, CUTSCENE_NORTHERN_RANGE_POSTSTORY },
    { FIXED_ROOM_BURIED_RELIC_REGIROCK, CUTSCENE_REGIROCK, NUM_CUTSCENE_FLAGS, CUTSCENE_REGIROCK, NUM_CUTSCENE_FLAGS, CUTSCENE_REGIROCK },
    { FIXED_ROOM_BURIED_RELIC_REGICE, CUTSCENE_REGICE, NUM_CUTSCENE_FLAGS, CUTSCENE_REGICE, NUM_CUTSCENE_FLAGS, CUTSCENE_REGICE },
    { FIXED_ROOM_BURIED_RELIC_REGISTEEL, CUTSCENE_REGISTEEL, NUM_CUTSCENE_FLAGS, CUTSCENE_REGISTEEL, NUM_CUTSCENE_FLAGS, CUTSCENE_REGISTEEL },
    { FIXED_ROOM_WISH_CAVE_JIRACHI, CUTSCENE_JIRACHI, NUM_CUTSCENE_FLAGS, CUTSCENE_JIRACHI, CUTSCENE_FLAG_JIRACHI_COMPLETE, CUTSCENE_JIRACHI_POSTSTORY },
    { FIXED_ROOM_SILVER_TRENCH_LUGIA, CUTSCENE_SILVER_TRENCH, NUM_CUTSCENE_FLAGS, CUTSCENE_SILVER_TRENCH, NUM_CUTSCENE_FLAGS, CUTSCENE_SILVER_TRENCH },
    { FIXED_ROOM_STORMY_SEA_KYOGRE, CUTSCENE_STORMY_SEA, NUM_CUTSCENE_FLAGS, CUTSCENE_STORMY_SEA, NUM_CUTSCENE_FLAGS, CUTSCENE_STORMY_SEA },
    { FIXED_ROOM_METEOR_CAVE_DEOXYS, CUTSCENE_METEOR_CAVE, NUM_CUTSCENE_FLAGS, CUTSCENE_METEOR_CAVE, NUM_CUTSCENE_FLAGS, CUTSCENE_METEOR_CAVE },
    { FIXED_ROOM_PURITY_FOREST_CELEBI, CUTSCENE_PURITY_FOREST, NUM_CUTSCENE_FLAGS, CUTSCENE_PURITY_FOREST, NUM_CUTSCENE_FLAGS, CUTSCENE_PURITY_FOREST },
    { FIRST_DOJO_MAZE_BOSS_ROOM, CUTSCENE_MAZE_BOSS, NUM_CUTSCENE_FLAGS, CUTSCENE_MAZE_BOSS, NUM_CUTSCENE_FLAGS, CUTSCENE_MAZE_BOSS },
    { FIXED_ROOM_WISH_CAVE_MEDICHAM, CUTSCENE_MEDICHAM, CUTSCENE_FLAG_MEDICHAM_COMPLETE, CUTSCENE_MEDICHAM_POSTSTORY, CUTSCENE_FLAG_MEDICHAM_COMPLETE, CUTSCENE_MEDICHAM_POSTSTORY },
    { FIXED_ROOM_HOWLING_FOREST_SMEARGLE, CUTSCENE_HOWLING_FOREST, CUTSCENE_FLAG_HOWLING_FOREST_COMPLETE, CUTSCENE_HOWLING_FOREST_POSTSTORY, CUTSCENE_FLAG_HOWLING_FOREST_COMPLETE, CUTSCENE_HOWLING_FOREST_POSTSTORY },
    { FIXED_ROOM_NONE, 0, 0, 0, 0, 0 },
};

static const s32 gUnknown_8107314[17] = {
    0, -1, 1, -2, 2, -3, 3, -4,
    4, -4, 4, -4, 4, -4, 4, -4,
    4
};

EWRAM_DATA static unkStruct_202F3D0 gUnknown_202F3D0 = { 0 };

void sub_80847D4(void)
{
    u32 fixedRoomNumber;
    s32 i;

    gDungeon->cutscene = CUTSCENE_NONE;
    gDungeon->unk1356C = FALSE;
    UpdateMinimap();

    for (i = 0; i < 999 && sFixedRoomCutsceneLookup[i].fixedRoomNum != FIXED_ROOM_NONE; i++) {
        fixedRoomNumber = gDungeon->fixedRoomNumber;

        // Dojo maze bosses all use the same cutscene data
        if (fixedRoomNumber >= (FIRST_DOJO_MAZE_BOSS_ROOM + 1) && fixedRoomNumber <= LAST_DOJO_MAZE_BOSS_ROOM)
            fixedRoomNumber = FIRST_DOJO_MAZE_BOSS_ROOM;

        if (fixedRoomNumber == sFixedRoomCutsceneLookup[i].fixedRoomNum) {
            sub_8084854(&sFixedRoomCutsceneLookup[i]);
            break;
        }
    }

    FlushTempCutsceneFlags();
}

static void sub_8084854(const FixedRoomCutsceneData *data)
{
    if (gDungeon->unk644.missionKind != DUNGEON_MISSION_UNK0) {
        gDungeon->cutscene = data->cutscene3;
    }
    else if (GetCutsceneFlag(data->cutscene3Flag)) {
        gDungeon->cutscene = data->cutscene3;
    }
    else if (GetCutsceneFlag(data->cutscene2Flag)) {
        gDungeon->cutscene = data->cutscene2;
    }
    else {
        gDungeon->cutscene = data->cutscene1;

        if (data->cutscene2Flag != NUM_CUTSCENE_FLAGS)
            SetTempCutsceneFlag(data->cutscene2Flag);
    }

    gDungeon->unk644.unk31 = 1;
    sub_807E5E4(WEATHER_CLEAR);
}

bool8 ShouldShowDungeonBanner(void)
{
    return TRUE;
}

void sub_80848F0(void)
{
    gDungeon->unk1356C = TRUE;

    switch (gDungeon->cutscene) {
        case CUTSCENE_NONE:
        case NUM_CUTSCENES:
            gDungeon->unk1356C = FALSE;
            break;
        case CUTSCENE_MT_STEEL_ATTEMPT1:
        case CUTSCENE_MT_STEEL_ATTEMPT2:
            sub_8086B14();
            break;
        case CUTSCENE_MT_STEEL_POSTSTORY:
            sub_8086B94();
            break;
        case CUTSCENE_SINISTER_WOODS_ATTEMPT1:
        case CUTSCENE_SINISTER_WOODS_ATTEMPT2:
            sub_8086E9C();
            break;
        case CUTSCENE_SINISTER_WOODS_POSTSTORY:
            sub_8086F00();
            break;
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT1:
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT2:
            sub_8087230();
            break;
        case CUTSCENE_MT_THUNDER_PEAK_POSTSTORY:
            sub_808729C();
            break;
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT1:
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT2:
            sub_80877E8();
            break;
        case CUTSCENE_MT_BLAZE_PEAK_POSTSTORY:
            sub_8087848();
            break;
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT1:
            sub_8087F54();
            break;
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT2:
            sub_8087FB4();
            break;
        case CUTSCENE_FROSTY_GROTTO_POSTSTORY:
            sub_8087FF8();
            break;
        case CUTSCENE_MT_FREEZE_PEAK:
            sub_80885A0();
            break;
        case CUTSCENE_MT_FREEZE_PEAK_POSTSTORY:
            sub_80885C4();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1:
            sub_808862C();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2:
            sub_80886C4();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY:
            sub_808875C();
            break;
        case CUTSCENE_MAGMA_CAVERN_MID:
            sub_8088DC0();
            break;
        case CUTSCENE_MAGMA_CAVERN_MID_POSTSTORY:
            sub_8088E5C();
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT1:
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT2:
            sub_80892C8();
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_POSTSTORY:
            sub_8089328();
            break;
        case CUTSCENE_UPROAR_FOREST_ATTEMPT1:
        case CUTSCENE_UPROAR_FOREST_ATTEMPT2:
            sub_808970C();
            break;
        case CUTSCENE_UPROAR_FOREST_POSTSTORY:
            sub_808974C();
            break;
        case CUTSCENE_WESTERN_CAVE_ATTEMPT1:
        case CUTSCENE_WESTERN_CAVE_ATTEMPT2:
            sub_8089914();
            break;
        case CUTSCENE_WESTERN_CAVE_POSTSTORY:
            sub_8089978();
            break;
        case CUTSCENE_FIERY_FIELD_ATTEMPT1:
        case CUTSCENE_FIERY_FIELD_ATTEMPT2:
            sub_8089C44();
            break;
        case CUTSCENE_FIERY_FIELD_POSTSTORY:
            sub_8089C90();
            break;
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT1:
            sub_8089EFC();
            break;
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT2:
            sub_8089F44();
            break;
        case CUTSCENE_LIGHTNING_FIELD_POSTSTORY:
            sub_8089F8C();
            break;
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT1:
            sub_808A264();
            break;
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT2:
            sub_808A2C0();
            break;
        case CUTSCENE_NORTHWIND_FIELD_POSTSTORY:
            sub_808A308();
            break;
        case CUTSCENE_MT_FARAWAY:
            sub_808A608();
            break;
        case CUTSCENE_MT_FARAWAY_POSTSTORY:
            sub_808A668();
            break;
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT1:
            sub_808A9E4();
            break;
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT2:
            sub_808AA3C();
            break;
        case CUTSCENE_NORTHERN_RANGE_POSTSTORY:
            sub_808AA94();
            break;
        case CUTSCENE_REGIROCK:
            sub_808ACC0();
            break;
        case CUTSCENE_REGICE:
            sub_808AD48();
            break;
        case CUTSCENE_REGISTEEL:
            sub_808ADCC();
            break;
        case CUTSCENE_JIRACHI:
            sub_808B2F4();
            break;
        case CUTSCENE_JIRACHI_POSTSTORY:
            sub_808B35C();
            break;
        case CUTSCENE_SILVER_TRENCH:
            sub_808BDEC();
            break;
        case CUTSCENE_STORMY_SEA:
            sub_808C10C();
            break;
        case CUTSCENE_METEOR_CAVE:
            sub_808C3A0();
            break;
        case CUTSCENE_PURITY_FOREST:
            sub_808C5C0();
            break;
        case CUTSCENE_MAZE_BOSS:
            sub_808C938();
            break;
        case CUTSCENE_MEDICHAM:
            sub_808C9C4();
            break;
        case CUTSCENE_MEDICHAM_POSTSTORY:
            sub_808CB5C();
            break;
        case CUTSCENE_HOWLING_FOREST:
            sub_808CBB0();
            break;
        case CUTSCENE_HOWLING_FOREST_POSTSTORY:
            sub_808CD44();
            break;
    }
    FlushTempCutsceneFlags();
}

void DisplayPreFightDialogue(void)
{
    switch (gDungeon->cutscene) {
        case CUTSCENE_NONE:
            break;
        case CUTSCENE_MT_STEEL_ATTEMPT1:
            SkarmoryPreFightDialogue();
            break;
        case CUTSCENE_MT_STEEL_ATTEMPT2:
            SkarmoryReFightDialogue();
            break;
        case CUTSCENE_MT_STEEL_POSTSTORY:
            sub_8086E40();
            break;
        case CUTSCENE_SINISTER_WOODS_ATTEMPT1:
            TeamMeaniesPreFightDialogue();
            break;
        case CUTSCENE_SINISTER_WOODS_ATTEMPT2:
            TeamMeaniesReFightDialogue();
            break;
        case CUTSCENE_SINISTER_WOODS_POSTSTORY:
            sub_8087130();
            break;
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT1:
            ZapdosPreFightDialogue();
            break;
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT2:
            ZapdosReFightDialogue();
            break;
        case CUTSCENE_MT_THUNDER_PEAK_POSTSTORY:
            ZapdosPostStoryPreFightDialogue();
            break;
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT1:
            MoltresPreFightDialogue();
            break;
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT2:
            MoltresReFightDialogue();
            break;
        case CUTSCENE_MT_BLAZE_PEAK_POSTSTORY:
            MoltresPostStoryPreFightDialogue();
            break;
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT1:
            ArticunoPreFightDialogue();
            break;
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT2:
            ArticunoReFightDialogue();
            break;
        case CUTSCENE_FROSTY_GROTTO_POSTSTORY:
            ArticunoPostStoryPreFightDialogue();
            break;
        case CUTSCENE_MT_FREEZE_PEAK:
            sub_8088608();
            break;
        case CUTSCENE_MT_FREEZE_PEAK_POSTSTORY:
            sub_8088618();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1:
            GroudonPreFightDialogue();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2:
            GroudonReFightDialogue();
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY:
            GroudonPostStoryPreFightDialogue();
            break;
        case CUTSCENE_MAGMA_CAVERN_MID:
            MagmaCavernMidDialogue();
            break;
        case CUTSCENE_MAGMA_CAVERN_MID_POSTSTORY:
            sub_8089168();
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT1:
            RayquazaPreFightDialogue();
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT2:
            RayquazaReFightDialogue();
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_POSTSTORY:
            RayquazaPostStoryPreFightDialogue();
            break;
        case CUTSCENE_UPROAR_FOREST_ATTEMPT1:
            sub_80897F0();
            break;
        case CUTSCENE_UPROAR_FOREST_ATTEMPT2:
            sub_8089878();
            break;
        case CUTSCENE_UPROAR_FOREST_POSTSTORY:
            sub_80898E4();
            break;
        case CUTSCENE_WESTERN_CAVE_ATTEMPT1:
        case CUTSCENE_WESTERN_CAVE_ATTEMPT2:
            MewtwoPreFightDialogue();
            break;
        case CUTSCENE_WESTERN_CAVE_POSTSTORY:
            MewtwoReFightDialogue();
            break;
        case CUTSCENE_FIERY_FIELD_ATTEMPT1:
            EnteiPreFightDialogue();
            break;
        case CUTSCENE_FIERY_FIELD_ATTEMPT2:
            EnteiReFightDialogue();
            break;
        case CUTSCENE_FIERY_FIELD_POSTSTORY:
            EnteiPostStoryPreFightDialogue();
            break;
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT1:
            RaikouPreFightDialogue();
            break;
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT2:
            RaikouReFightDialogue();
            break;
        case CUTSCENE_LIGHTNING_FIELD_POSTSTORY:
            RaikouPostStoryPreFightDialogue();
            break;
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT1:
            SuicunePreFightDialogue();
            break;
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT2:
            SuicuneReFightDialogue();
            break;
        case CUTSCENE_NORTHWIND_FIELD_POSTSTORY:
            SuicunePostStoryPreFightDialogue();
            break;
        case CUTSCENE_MT_FARAWAY:
            HoOhPreFightDialogue();
            break;
        case CUTSCENE_MT_FARAWAY_POSTSTORY:
            HoOhReFightDialogue();
            break;
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT1:
            LatiosPreFightDialogue();
            break;
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT2:
            LatiosReFightDialogue();
            break;
        case CUTSCENE_NORTHERN_RANGE_POSTSTORY:
            sub_808AC3C();
            break;
        case CUTSCENE_REGIROCK:
            RegirockPreFightDialogue();
            break;
        case CUTSCENE_REGICE:
            RegicePreFightDialogue();
            break;
        case CUTSCENE_REGISTEEL:
            RegisteelPreFightDialogue();
            break;
        case CUTSCENE_JIRACHI:
            JirachiPreFightDialogue();
            break;
        case CUTSCENE_JIRACHI_POSTSTORY:
            JirachiReFightDialogue();
            break;
        case CUTSCENE_SILVER_TRENCH:
            LugiaPreFightDialogue();
            break;
        case CUTSCENE_STORMY_SEA:
            KyogrePreFightDialogue();
            break;
        case CUTSCENE_METEOR_CAVE:
            DeoxysPreFightDialogue();
            break;
        case CUTSCENE_PURITY_FOREST:
            CelebiJoinDialogue();
            break;
        case CUTSCENE_MAZE_BOSS:
            sub_808C998();
            break;
        case CUTSCENE_MEDICHAM:
            MedichamRescueDialogue();
            break;
        case CUTSCENE_MEDICHAM_POSTSTORY:
            DummyFightDialogue();
            break;
        case CUTSCENE_HOWLING_FOREST:
            SmeargleRescueDialogue();
            break;
        case CUTSCENE_HOWLING_FOREST_POSTSTORY:
            sub_808CD9C();
            break;
        case NUM_CUTSCENES:
            break;
    }
    sub_8085764();
    sub_80857B8();
    gDungeon->unk1356C = FALSE;
    FlushTempCutsceneFlags();
}

void HandleBossFaint_Async(Entity *entity, u8 monsterBehavior, bool8 transformedIntoFriend)
{
    if (monsterBehavior == BEHAVIOR_FIXED_ENEMY)
        return;

    switch (gDungeon->cutscene) {
        case CUTSCENE_NONE:
            break;
        case CUTSCENE_MT_STEEL_ATTEMPT1:
        case CUTSCENE_MT_STEEL_ATTEMPT2:
            HandleSkarmoryBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_SINISTER_WOODS_ATTEMPT1:
        case CUTSCENE_SINISTER_WOODS_ATTEMPT2:
            HandleMeaniesBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT1:
        case CUTSCENE_MT_THUNDER_PEAK_ATTEMPT2:
        case CUTSCENE_MT_THUNDER_PEAK_POSTSTORY:
            HandleZapdosBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT1:
        case CUTSCENE_MT_BLAZE_PEAK_ATTEMPT2:
        case CUTSCENE_MT_BLAZE_PEAK_POSTSTORY:
            HandleMoltresBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT1:
        case CUTSCENE_FROSTY_GROTTO_ATTEMPT2:
        case CUTSCENE_FROSTY_GROTTO_POSTSTORY:
            HandleArticunoBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1:
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2:
        case CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY:
            HandleGroudonBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT1:
        case CUTSCENE_SKY_TOWER_SUMMIT_ATTEMPT2:
        case CUTSCENE_SKY_TOWER_SUMMIT_POSTSTORY:
            HandleRayquazaBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_UPROAR_FOREST_ATTEMPT1:
        case CUTSCENE_UPROAR_FOREST_ATTEMPT2:
            HandleMankeyBossFaint(entity, monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_WESTERN_CAVE_ATTEMPT1:
        case CUTSCENE_WESTERN_CAVE_ATTEMPT2:
        case CUTSCENE_WESTERN_CAVE_POSTSTORY:
            HandleMewtwoBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_FIERY_FIELD_ATTEMPT1:
        case CUTSCENE_FIERY_FIELD_ATTEMPT2:
        case CUTSCENE_FIERY_FIELD_POSTSTORY:
            HandleEnteiBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT1:
        case CUTSCENE_LIGHTNING_FIELD_ATTEMPT2:
        case CUTSCENE_LIGHTNING_FIELD_POSTSTORY:
            HandleRaikouBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT1:
        case CUTSCENE_NORTHWIND_FIELD_ATTEMPT2:
        case CUTSCENE_NORTHWIND_FIELD_POSTSTORY:
            HandleSuicuneBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_MT_FARAWAY:
        case CUTSCENE_MT_FARAWAY_POSTSTORY:
            HandleHoOhBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT1:
        case CUTSCENE_NORTHERN_RANGE_ATTEMPT2:
        case CUTSCENE_NORTHERN_RANGE_POSTSTORY:
            HandleLatiosBossFaint(monsterBehavior, gDungeon->cutscene);
            break;
        case CUTSCENE_REGIROCK:
            HandleRegirockBossFaint_Async(monsterBehavior, gDungeon->cutscene, &entity->pos);
            break;
        case CUTSCENE_REGICE:
            HandleRegiceBossFaint_Async(monsterBehavior, gDungeon->cutscene, &entity->pos);
            break;
        case CUTSCENE_REGISTEEL:
            HandleRegisteelBossFaint_Async(monsterBehavior, gDungeon->cutscene, &entity->pos);
            break;
        case CUTSCENE_JIRACHI:
        case CUTSCENE_JIRACHI_POSTSTORY:
            HandleJirachiBossFaint_Async(monsterBehavior, gDungeon->cutscene, transformedIntoFriend);
            break;
        case CUTSCENE_SILVER_TRENCH:
            HandleLugiaBossFaint(monsterBehavior, gDungeon->cutscene, transformedIntoFriend);
            break;
        case CUTSCENE_STORMY_SEA:
            HandleKyogreBossFaint(monsterBehavior, gDungeon->cutscene, transformedIntoFriend);
            break;
        case CUTSCENE_METEOR_CAVE:
            HandleDeoxysNormalBossFaint(monsterBehavior, gDungeon->cutscene, transformedIntoFriend);
            break;
        case CUTSCENE_PURITY_FOREST:
            HandleCelebiBossFaint(monsterBehavior, gDungeon->cutscene, transformedIntoFriend);
            break;
        case CUTSCENE_MAZE_BOSS:
            HandleMazeBossFaint(entity, gDungeon->cutscene);
            break;
        case CUTSCENE_MEDICHAM:
        case CUTSCENE_MEDICHAM_POSTSTORY:
        case CUTSCENE_HOWLING_FOREST:
        case CUTSCENE_HOWLING_FOREST_POSTSTORY:
        case NUM_CUTSCENES:
            break;
    }

    if (!transformedIntoFriend && gDungeon->unk2 != DUNGEON_UNK2_0)
        DungeonStartNewBGM(STOP_BGM);
}

void sub_8085140_Async(void)
{
    switch (gDungeon->cutscene) {
        // NOTE: shortcut way to generate all cases from [CUTSCENE_NONE, NUM_CUTSCENES] properly
        default:
        case CUTSCENE_NONE:
        case CUTSCENE_MT_STEEL_ATTEMPT1:
        case NUM_CUTSCENES:
            break;
        case CUTSCENE_REGIROCK:
            sub_808AFB0_Async(gDungeon->cutscene);
            break;
        case CUTSCENE_REGICE:
            sub_808B030_Async(gDungeon->cutscene);
            break;
        case CUTSCENE_REGISTEEL:
            sub_808B0B0_Async(gDungeon->cutscene);
            break;
  }
}

bool8 MonCutsceneCompleted(s32 speciesId_)
{
    s32 flag;
    s32 speciesId = 0;

    // This line serves no purpose other than generating the right asm. Feel free to remove it.
    speciesId += (s16) speciesId_;

    speciesId = (s16) speciesId_;
    flag = NUM_CUTSCENE_FLAGS;

    switch (speciesId) {
        case MONSTER_SKARMORY:
            flag = CUTSCENE_FLAG_MT_STEEL_COMPLETE;
            break;
        case MONSTER_EKANS:
            flag = CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE;
            break;
        case MONSTER_GENGAR:
            flag = CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE;
            break;
        case MONSTER_MEDICHAM:
            flag = CUTSCENE_FLAG_SINISTER_WOODS_COMPLETE;
            break;
        case MONSTER_ZAPDOS:
            flag = CUTSCENE_FLAG_MT_THUNDER_PEAK_COMPLETE;
            break;
        case MONSTER_MOLTRES:
            flag = CUTSCENE_FLAG_MT_BLAZE_PEAK_COMPLETE;
            break;
        case MONSTER_ARTICUNO:
            flag = CUTSCENE_FLAG_FROSTY_GROTTO_COMPLETE;
            break;
        case MONSTER_GROUDON:
            flag = CUTSCENE_FLAG_MAGMA_CAVERN_PIT_COMPLETE;
            break;
        case MONSTER_RAYQUAZA:
            flag = CUTSCENE_FLAG_SKY_TOWER_SUMMIT_COMPLETE;
            break;
        case MONSTER_MEWTWO:
            flag = CUTSCENE_FLAG_WESTERN_CAVE_COMPLETE;
            break;
        case MONSTER_ENTEI:
            flag = CUTSCENE_FLAG_FIERY_FIELD_COMPLETE;
            break;
        case MONSTER_RAIKOU:
            flag = CUTSCENE_FLAG_LIGHTNING_FIELD_COMPLETE;
            break;
        case MONSTER_SUICUNE:
            flag = CUTSCENE_FLAG_NORTHWIND_FIELD_COMPLETE;
            break;
        case MONSTER_HO_OH:
            flag = CUTSCENE_FLAG_MT_FARAWAY_COMPLETE;
            break;
        case MONSTER_MANKEY:
            flag = CUTSCENE_FLAG_UPROAR_FOREST_COMPLETE;
            break;
        case MONSTER_REGIROCK:
            flag = CUTSCENE_FLAG_REGI_ITEM_OBTAINED;
            break;
        case MONSTER_REGICE:
            flag = CUTSCENE_FLAG_REGI_ITEM_OBTAINED;
            break;
        case MONSTER_REGISTEEL:
            flag = CUTSCENE_FLAG_REGI_ITEM_OBTAINED;
            break;
    }

    if (flag != NUM_CUTSCENE_FLAGS && !GetCutsceneFlag(flag))
        return FALSE;
    return TRUE;
}

void sub_8085374(void)
{
    const Tile *tile;
    Entity *entity;
    DungeonPos pos;
    s32 i, j;
    s32 temp;
    Entity *leaderEntity = NULL;
    Entity *partnerEntity = NULL;
    s32 species = GetPartnerMon2()->speciesNum;

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        entity = gDungeon->teamPokemon[i];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->isTeamLeader)
                leaderEntity = entity;
            if (GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
                partnerEntity = entity;
        }
    }

    if (leaderEntity == NULL || partnerEntity != NULL || gDungeon->unk644.canChangeLeader)
        return;

    j = 0;
    while ((pos = gUnknown_80F4598[j]).x != 99) {
        pos.x += leaderEntity->pos.x;
        pos.y += leaderEntity->pos.y;
        tile = GetTile(pos.x, pos.y);
        temp = sub_807034C(species, tile);
        if (temp == 0) {
            struct MonSpawnInfo local_30;

            local_30.species = species;
            local_30.level = 1;
            local_30.unk2 = 2;
            local_30.pos = pos;
            local_30.unk4 = temp;
            local_30.unk10 = 0;
            SpawnWildMon(&local_30, 1);
            break;
        }
        j++;
    }
}

Entity *CutsceneGetLeader(void)
{
    return GetLeader();
}

Entity *CutsceneGetPartner(void)
{
    s32 counter;
    Entity *entity;
    for(counter = 0; counter < MAX_TEAM_MEMBERS; counter++)
    {
        entity = gDungeon->teamPokemon[counter];
        if(EntityIsValid(entity) && GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            return entity;
        }
    }
    return GetEntityFromMonsterBehavior(BEHAVIOR_ALLY);
}

void sub_80854D4(void)
{
    Entity *stack1[MAX_TEAM_MEMBERS];
    Entity *stack2[MAX_TEAM_MEMBERS];
    s32 counter = 0;
    s32 index;
    Entity *entity;
    Entity *entity2;
    Entity *entity3;
    Entity *entity4;
    Entity *entity5;

    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
        {
            stack1[counter] = entity;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack1[counter] = NULL;
    }
    counter = 0;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity2 = stack1[index];
        if(entity2 != NULL && GetEntInfo(entity2)->isTeamLeader)
        {
            stack1[index] = NULL;
            stack2[counter] = entity2;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity3 = stack1[index];
        if(entity3 != NULL && GetEntInfo(entity3)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER)
        {
            stack1[index] = NULL;
            stack2[counter] = entity3;
            counter++;
        }
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity4 = stack1[index];
        if(entity4 != NULL)
        {
            stack1[index] = NULL;
            stack2[counter] = entity4;
            counter++;
        }
    }
    for(; counter < MAX_TEAM_MEMBERS; counter++)
    {
        stack2[counter] = NULL;
    }
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity5 = stack2[index];
        if(entity5 != NULL)
            sub_80856C8(entity5, gDungeon->unkE220[index].x, gDungeon->unkE220[index].y);
    }
}

void sub_80855E4(DungeonCallback func)
{
    bool8 flag;
    Entity * entity;
    Entity * partnerEntity;
    s32 index;

    flag = FALSE;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if (EntityIsValid(entity)) {
            if (GetEntInfo(entity)->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER) {
                flag = TRUE;
            }
            func(entity);
        }
    }
    if ((!flag) && (partnerEntity = CutsceneGetPartner(), partnerEntity != NULL)) {
        func(partnerEntity);
    }
}

void sub_808563C(DungeonCallback func)
{
    Entity * entity;
    s32 index;

    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->joinedAt.id != 0x41)) {
            func(entity);
        }
    }
}

Entity *GetEntityFromMonsterBehavior(u8 entityType)
{
    s32 index;

    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        Entity *entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity) && GetEntInfo(entity)->monsterBehavior == entityType)
            return entity;
    }
    return NULL;
}

void sub_80856C8(Entity * pokemon, s32 x, s32 y)
{
    sub_80694C0(pokemon, x, y, 1);
    UpdateEntityPixelPos(pokemon,NULL);
}

void sub_80856E0(Entity * pokemon, s32 direction)
{
    EntityInfo *entityInfo;
    s32 counter;

    entityInfo = GetEntInfo(pokemon);
    sub_80861D4(pokemon, 6, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Add(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);

    for(counter = 0; counter < 5; counter++)
    {
        entityInfo->unk174 = F248_Sub(entityInfo->unk174, IntToF248(2));
        DungeonRunFrameActions(0x46);
    }
    entityInfo->unk174 = 0;
    DungeonRunFrameActions(0x46);
}

static void sub_8085764(void)
{
    Entity *entity;
    s32 index;
    Entity stackEntity;

    sub_80457DC(&stackEntity);
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) && (GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)) {
            HandleFaint_Async(entity,DUNGEON_EXIT_DEBUG_DAMAGE,&stackEntity);
        }
    }
}

static void sub_80857B8(void)
{
    u8 *direction;
    s32 index;

    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        Entity *entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            EntityInfo *entityInfo = GetEntInfo(entity);
            if (gDungeon->unk4 == 0 && gDungeon->unk2 == DUNGEON_UNK2_0) {
                UpdateEntityPixelPos(entity, 0);
                entityInfo->unk15C = 0;
                entityInfo->unkFE = 99;
                direction = &entityInfo->action.direction;
                entityInfo->targetPos.x = gAdjacentTileOffsets[*direction].x + entity->pos.x;
                entityInfo->targetPos.y = gAdjacentTileOffsets[*direction].y + entity->pos.y;
                sub_806CE68(entity,*direction);
            }
        }
    }
}

void sub_8085860(s32 x, s32 y)
{
    sub_803F4A0(0);
    sub_803F878(X_POS_TO_PIXELPOS(x), Y_POS_TO_PIXELPOS(y));
}

UNUSED static void sub_8085890(s32 x, s32 y)
{
    sub_803F4A0(0);
    sub_803F878(x, y);
}

void ShiftCameraToPosition(PixelPos *posStruct, s32 cameraSteps)
{
  s32 XPos;
  s32 YPos;
  s32 XIncrement;
  s32 YIncrement;

  XPos = GetCameraXPos();
  YPos = GetCameraYPos();
  XIncrement = (posStruct->x - XPos) / cameraSteps;
  YIncrement = (posStruct->y - YPos) / cameraSteps;
  sub_803F4A0(0);
  if (0 < cameraSteps) {
    do {
      XPos += XIncrement;
      YPos += YIncrement;
      sub_803F878(XPos,YPos);
      DungeonRunFrameActions(0x46);
      cameraSteps--;
    } while (cameraSteps != 0);
  }
  sub_803F878(posStruct->x,posStruct->y);
  DungeonRunFrameActions(0x46);
}

void SetFacingDirection(Entity *pokemon, s32 direction)
{
    GetEntInfo(pokemon)->action.direction = direction & DIRECTION_MASK;
    sub_806CE68(pokemon, direction);
}

void sub_8085930(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
        entity = gDungeon->teamPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(GetEntInfo(entity)->monsterBehavior == BEHAVIOR_ALLY)
            {
                if(direction >= NUM_DIRECTIONS)
                {
                    sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
                }
                else
                {
                    GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                    sub_806CE68(entity, direction);
                }
            }
        }
    }
}

static void sub_80859F0(s32 direction)
{
    s32 index;
    Entity *entity;
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
        entity = gDungeon->wildPokemon[index];
        if(EntityIsValid(entity))
        {
            if(direction >= NUM_DIRECTIONS)
            {
                sub_806CE68(entity, RandInt(NUM_DIRECTIONS));
            }
            else
            {
                GetEntInfo(entity)->action.direction = direction & DIRECTION_MASK;
                sub_806CE68(entity, direction);
            }
        }
    }
}

bool8 ShouldRunMonsterAI(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    switch (pokemonInfo->monsterBehavior)
    {
        case BEHAVIOR_RESCUE_TARGET:
        case BEHAVIOR_SKARMORY:
        case BEHAVIOR_GENGAR:
        case BEHAVIOR_EKANS:
        case BEHAVIOR_MEDICHAM:
        case BEHAVIOR_ZAPDOS:
        case BEHAVIOR_MOLTRES:
        case BEHAVIOR_ARTICUNO:
        case BEHAVIOR_GROUDON_2:
        case BEHAVIOR_RAYQUAZA:
        case BEHAVIOR_MANKEY:
        case BEHAVIOR_MEWTWO:
        case BEHAVIOR_ENTEI:
        case BEHAVIOR_RAIKOU:
        case BEHAVIOR_SUICUNE:
        case BEHAVIOR_HO_OH:
        case BEHAVIOR_LATIOS:
        case BEHAVIOR_REGIROCK:
        case BEHAVIOR_REGICE:
        case BEHAVIOR_REGISTEEL:
        case BEHAVIOR_JIRACHI:
        case BEHAVIOR_LUGIA:
        case BEHAVIOR_KYOGRE:
        case BEHAVIOR_DEOXYS_NORMAL:
        case BEHAVIOR_CELEBI:
        case BEHAVIOR_SMEARGLE:
        case BEHAVIOR_32:
        case BEHAVIOR_33:
        case BEHAVIOR_34:
        case BEHAVIOR_35:
        case BEHAVIOR_MAZE_BOSS:
            return TRUE;
        case BEHAVIOR_FIXED_ENEMY:
        case BEHAVIOR_ALLY:
        case BEHAVIOR_DIGLETT:
        case BEHAVIOR_ALAKAZAM_1:
        case BEHAVIOR_GROUDON_1:
        case BEHAVIOR_ALAKAZAM_2:
        default:
            return FALSE;
    }
}

UNUSED static void sub_8085B0C(Entity *pokemon)
{
  s32 index = 0;
  u8 local_28[] = {4, 3, 2, 3, 4, 5, 6, 5, 4, 3, 2, 3, 4, 5, 6, 5, 4, 4, 4, 4, 4, 4, 5, 6, 0};

  while (local_28[index] != 0) {
    SetFacingDirection(pokemon, local_28[index]);
    DungeonWaitFrames_Async(6,0x46);
    index++;
  }
}

static EWRAM_DATA s32 gUnknown_202F3D8 = 0;

void sub_8085B4C(struct_8085B80 a0[], s16 *a1[], Entity *a2[], s32 a3)
{
    s32 i;

    gUnknown_202F3D8 = a3;

    for (i = 0; i < a3; i++) {
        a0[i].unk0 = 1;
        a0[i].unk4 = a2[i];
        a0[i].unkC = a1[i];
        a0[i].unk8 = a1[i][2];
    }
}

bool8 sub_8085B80(struct_8085B80 *a0)
{
    s16 *unkCPtr;
    s32 i;
    bool8 ret = FALSE;

    for (i = 0; i < gUnknown_202F3D8; i++) {
        Entity *entity = a0[i].unk4;
        EntityInfo *enInfo = GetEntInfo(entity);
        unkCPtr = a0[i].unkC;
        if (a0[i].unk0 != 0) {
            ret = TRUE;
            if (a0[i].unk8 == 0) {
                unkCPtr = unkCPtr + 4;
                if (unkCPtr[2] == 0) {
                    a0[i].unk0 = 0;
                    enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                    sub_806CDD4(entity, 7, unkCPtr[0]);
                    sub_80856C8(entity, unkCPtr[5], unkCPtr[6]);
                    continue;
                }
                a0[i].unk8 = unkCPtr[2];
                a0[i].unkC = unkCPtr;
              enInfo->action.direction = unkCPtr[0] & DIRECTION_MASK;
                sub_806CDD4(entity, 0, (int)*unkCPtr);
            }

            a0[i].unk8--;
            IncreaseEntityPixelPos(entity,
                gAdjacentTileOffsets[*unkCPtr].x * unkCPtr[1] * 0x100,
                gAdjacentTileOffsets[*unkCPtr].y * unkCPtr[1] * 0x100);
        }
    }
    return ret;
}

void SetDungeonBGColorRGB(s32 r, s32 g, s32 b, bool8 a3, bool8 a4)
{
    s32 i, palIndex, n;
    const RGB_Struct *colorPtr;
    RGB_Struct color;
    RGB_Struct16 colorS16;

    n = 160;
    sub_8085E98();
    palIndex = 0;
    colorPtr = gDungeonPaletteFile->data;
    if (a4) {
        if (r >= 0) { r /= 2; }
        if (g >= 0) { g /= 2; }
        if (b >= 0) { b /= 2; }
    }

    color.r = 0;
    color.g = 0;
    color.b = 0;
    SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
    colorPtr++;
    palIndex++;

    for (i = 1; i < n; i++) {
        s32 newR = colorPtr->r + r;
        s32 newG = colorPtr->g + g;
        s32 newB = colorPtr->b + b;

        if (newR > 0xFF) { newR = 0xFF; }
        if (newG > 0xFF) { newG = 0xFF; }
        if (newB > 0xFF) { newB = 0xFF; }

        if (newR < 0)       { newR = 0; }
        if (newG < 0)       { newG = 0; }
        if (newB < 0)       { newB = 0; }

        color.r = newR;
        color.g = newG;
        color.b = newB;
        SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
        colorPtr++;
        palIndex++;
    }

    colorS16.r = r;
    colorS16.g = g;
    colorS16.b = b;
    sub_8004C00(gDungeonAnimatedColors, 160, 32, gDungeonBrightness, gDungeon->colorRamp, &colorS16);
    palIndex += 32;

    colorPtr = gUnknown_202ECA4;
    n = 32;
    for (i = 0; i < n; i++) {
        s32 newR = colorPtr->r + r;
        s32 newG = colorPtr->g + g;
        s32 newB = colorPtr->b + b;

        if (newR > 0xFF) { newR = 0xFF; }
        if (newG > 0xFF) { newG = 0xFF; }
        if (newB > 0xFF) { newB = 0xFF; }

        if (newR < 0)       { newR = 0; }
        if (newG < 0)       { newG = 0; }
        if (newB < 0)       { newB = 0; }

        color.r = newR;
        color.g = newG;
        color.b = newB;
        SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, gDungeon->colorRamp);
        colorPtr++;
        palIndex++;
    }

    if (a3) {
        colorPtr = gDungeon->paletFile->data;
        palIndex = 256;
        n = 208;
        for (i = 0; i < n; i++) {
            s32 newR = colorPtr->r + r;
            s32 newG = colorPtr->g + g;
            s32 newB = colorPtr->b + b;

            if (newR > 0xFF) { newR = 0xFF; }
            if (newG > 0xFF) { newG = 0xFF; }
            if (newB > 0xFF) { newB = 0xFF; }

            if (newR < 0)       { newR = 0; }
            if (newG < 0)       { newG = 0; }
            if (newB < 0)       { newB = 0; }

            color.r = newR;
            color.g = newG;
            color.b = newB;
            SetBGPaletteBufferColorRGB(palIndex, &color, gDungeonBrightness, NULL);
            colorPtr++;
            palIndex++;
        }
    }
}

void sub_8085E98(void)
{
    gDungeon->unk181e8.unk18215 = FALSE;
}

void sub_8085EB0(void)
{
    gDungeon->unk181e8.unk18215 = TRUE;
}

static const unkStruct_2039DB0 sDefaultSpriteMasks = DEFAULT_UNK_2039DB0_MASKS;

u32 sub_8085EC8(s16 param_1,u32 param_2,u32 param_3,DungeonPos *param_4, bool32 param_5)
{
    u32 uVar1;
    unkStruct_80416E0 local_40;

    bool8 param_5_bool8;
    s32 param_1_s32 = param_1;


    param_5_bool8 = param_5;

    sub_800EE5C(param_1_s32);
    sub_800EF64();
    DungeonRunFrameActions(0x46);
    local_40.unk0 = param_1;
    local_40.unk4 = param_2;
    local_40.dir = param_3;
    local_40.pos1.x = param_4->x;
    local_40.pos1.y = param_4->y;
    local_40.pos2.x = 0;
    local_40.pos2.y = 0;
    local_40.unk18 = 0xffff;
    local_40.spriteMasks = sDefaultSpriteMasks;

    uVar1 = sub_800E890(&local_40);
    if (param_5_bool8) {
        sub_8085F44(uVar1);
        uVar1 = -1;
    }
    return uVar1;
}

void sub_8085F44(s32 param_1)
{
    while (sub_800E9A8(param_1)) {
        sub_800E90C(&gDungeon->unk181e8.cameraPixelPos);
        DungeonRunFrameActions(0x46);
    }
}

void sub_8085F78(void)
{
    switch(gDungeon->cutscene) {
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT1:
        case CUTSCENE_MAGMA_CAVERN_PIT_ATTEMPT2:
        case CUTSCENE_MAGMA_CAVERN_PIT_POSTSTORY:
            sub_8088848();
            break;
        case CUTSCENE_MAGMA_CAVERN_MID:
            sub_8088EE8();
            break;
        case CUTSCENE_MT_FARAWAY:
        case CUTSCENE_MT_FARAWAY_POSTSTORY:
            sub_808A718();
            break;
        case CUTSCENE_NONE:
        case NUM_CUTSCENES:
        default:
            break;
    }
}

bool8 ItemInInventoryOrHeld(u8 id)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++) {
        Item *item = &gTeamInventoryRef->teamItems[i];

        if ((item->flags & 1) != 0 && item->id == id)
            return TRUE;
    }

    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *entity = gDungeon->teamPokemon[i];

        if (EntityIsValid(entity)) {
            EntityInfo *info = GetEntInfo(entity);

            if (ItemExists(&info->heldItem) && info->heldItem.id == id)
                return TRUE;
        }
    }

    return FALSE;
}

UNUSED static void sub_8086124(Entity *entity, u8 param_2)
{
    GetEntInfo(entity)->unk160 = param_2;
}

void FrostyForestIntrusionCutscene_Async(void)
{
    DungeonFadeOutBGM(60);
    DungeonWaitFrames_Async(60, 70);
    sub_8052FB8(gUnknown_810665C);
    DungeonWaitFrames_Async(30, 70);
    sub_8052FB8(gUnknown_810668C);
    DungeonWaitFrames_Async(30, 70);
    sub_8052FB8(gUnknown_81066D4);
    DungeonWaitFrames_Async(30, 70);
    sub_8052FB8(gUnknown_81066F0);
    DungeonWaitFrames_Async(30, 70);
    sub_8052FB8(gUnknown_810671C);
    DungeonWaitFrames_Async(30, 70);
}

void sub_80861A8(Entity *a0)
{
    sub_806CDD4(a0, 0, NUM_DIRECTIONS);
}

void sub_80861B8(Entity *a0, u8 r1, s32 direction)
{
    EntityInfo *info;

    info = GetEntInfo(a0);

    sub_806CDD4(a0, r1, direction);
    info->unkFE = r1;
}

void sub_80861D4(Entity *a0, u8 r1, s32 direction)
{
    sub_806CDD4(a0, r1, direction);
    sub_80861EC(a0);
}

static void sub_80861EC(Entity *a0)
{
    GetEntInfo(a0)->unkFE = 0x63;
}

s32 sub_80861F8(s32 param_1,Entity *param_2,bool32 param_3)
{
    EntityInfo *info;
    s32 uVar2;
    s32 uStack_38;
    DungeonPos pos;
    unkStruct_80416E0 stack;

    // Needed to match.
    s32 param_1Copy2 = (s16) param_1;
    s32 param_1Copy = param_1Copy2;
    u8 param_3_bool32 = param_3;

    sub_800EE5C(param_1Copy2);
    sub_800EF64();
    DungeonRunFrameActions(0x46);
    info = GetEntInfo(param_2);
    pos.x = 0;
    pos.y = 0;
    uStack_38 = sub_800E700(param_1Copy);
    if (uStack_38 != -1) {
        sub_800569C(&pos, &param_2->axObj.axdata, uStack_38);
    }
    stack.unk0 = param_1Copy;
    stack.unk4 = 0;
    stack.dir = info->action.direction;
    stack.pos1.x = (param_2->pixelPos).x / 256;
    stack.pos1.y = (param_2->pixelPos).y / 256;

    stack.pos2.x = pos.x;
    stack.pos2.y = pos.y;
    stack.unk14 = uStack_38;
    stack.unk18 = 0xffff;
    stack.spriteMasks = DEFAULT_UNK_2039DB0_MASKS;

    uVar2 = sub_800E890(&stack);
    if (param_3_bool32) {
        sub_8085F44(uVar2);
        uVar2 = -1;
    }
    return uVar2;
}

void SpriteShockEffect(Entity *entity)
{
    PlaySoundEffect(464);
    sub_80861F8(323, entity, 0);
}

static void sub_80862DC(Entity *entity)
{
    PixelPos pos;
    pos.x = entity->pixelPos.x;
    pos.y = entity->pixelPos.y + 0x3800;

    UpdateEntityPixelPos(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_NORTH);
    sub_8086A54(entity);
}

static void sub_8086310(Entity *entity)
{
    PixelPos pos;
    pos.x = entity->pixelPos.x;
    pos.y = entity->pixelPos.y + 0x9000;

    UpdateEntityPixelPos(entity, &pos);
    sub_806CE68(entity, DIRECTION_SOUTH);
    sub_8086A3C(entity);
    entity->isVisible = 0;
}

static void sub_8086348(Entity *entity)
{
    PixelPos pos;
    pos.x = entity->pixelPos.x + 0x7800;
    pos.y = entity->pixelPos.y - 0x2000;

    UpdateEntityPixelPos(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_WEST);
    sub_8086A54(entity);
}

static void sub_8086384(Entity *entity)
{
    PixelPos pos;
    pos.x = entity->pixelPos.x + 0x7800;
    pos.y = entity->pixelPos.y;

    UpdateEntityPixelPos(entity, &pos);
    sub_806CDD4(entity, 0, DIRECTION_WEST);
    sub_8086A54(entity);
}

static void sub_80863B8(Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_NORTH);
}

static void sub_80863C8(Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_SOUTH);
}

static void sub_80863D8(Entity *entity)
{
    sub_806CDD4(entity, 0, DIRECTION_WEST);
}

static void sub_80863E8(Entity *entity)
{
    sub_806CDD4(entity, 6, DIRECTION_NORTH);
}

static void sub_80863F8(Entity *entity)
{
    sub_806CE68(entity, DIRECTION_NORTH);
}

static void sub_8086404(Entity *entity)
{
    sub_806CE68(entity, DIRECTION_WEST);
}

static void sub_8086410(Entity *entity)
{
    IncreaseEntityPixelPos(entity, 0, -0x100);
}

static void sub_8086424(Entity *entity)
{
    IncreaseEntityPixelPos(entity, 0, 0x100);
}

static void sub_8086434(Entity *entity)
{
    IncreaseEntityPixelPos(entity, -0x100, 0);
}

void sub_8086448(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80862DC);

    for (i = 0; i < 56; i++) {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        YPos += 0x100;
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086410);
        DungeonRunFrameActions(0x46);
    }

    sub_80855E4(sub_80863F8);
}

static void sub_8086494(void)
{
    s32 i;

    sub_8085930(DIRECTION_NORTHEAST);
    DungeonWaitFrames_Async(4, 70);

    sub_8085930(DIRECTION_EAST);
    DungeonWaitFrames_Async(4, 70);

    sub_8085930(DIRECTION_SOUTHEAST);
    DungeonWaitFrames_Async(4, 70);

    sub_8085930(DIRECTION_SOUTH);
    DungeonWaitFrames_Async(4, 70);

    sub_80855E4(sub_80863C8);

    for (i = 0; i < 144; i++) {
        sub_80855E4(sub_8086424);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_8086310);
}

void sub_8086500(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_8086348);

    for (i = 0; i < 72; i++) {
        XPos = GetCameraXPos();
        XPos += 0x100;
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086434);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_8086404);
}

void sub_808654C(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_8086384);

    for (i = 0; i < 120; i++) {
        XPos = GetCameraXPos();
        XPos += 0x100;
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos);
        sub_80855E4(sub_8086434);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_8086404);
}

void sub_8086598(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863B8);

    for (i = 0; i < 24; i++) {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos - 0x100);
        sub_80855E4(sub_8086410);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_80863F8);
}

void sub_80865E8(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863E8);

    for (i = 0; i < 12; i++) {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos + 0x200);
        sub_80855E4(sub_8086424);
        sub_80855E4(sub_8086424);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_80863F8);
}

void sub_808663C(void)
{
    s32 i;
    u32 XPos;
    u32 YPos;

    sub_80855E4(sub_80863E8);

    for (i = 0; i < 16; i++) {
        XPos = GetCameraXPos();
        YPos = GetCameraYPos();
        sub_803F878(XPos, YPos + 0x200);
        sub_80855E4(sub_8086424);
        sub_80855E4(sub_8086424);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_80863F8);
}

void sub_8086690(void)
{
    s32 i;

    sub_80855E4(sub_80863D8);

    for (i = 0; i < 48; i++) {
        sub_80855E4(sub_8086434);
        DungeonRunFrameActions(70);
    }

    sub_80855E4(sub_8086404);
}

void sub_80866C4(const struct DungeonDialogueStruct *dialogue)
{
    CutsceneLookAroundEffect_Async(CutsceneGetLeader());
    DungeonWaitFrames_Async(10, 70);
    DisplayDungeonDialogue_Async(dialogue);
    DungeonWaitFrames_Async(10, 70);
    sub_8086494();
    gDungeon->unk2 = DUNGEON_UNK2_1;
}

UNUSED static void sub_80866FC(void)
{
    s32 i;

    for (i = 0; i >= -250; i -= 10) {
        SetDungeonBGColorRGB(i, i, i, TRUE, FALSE);
        DungeonRunFrameActions(70);
    }
}

UNUSED static void sub_808627C(void)
{
    sub_803E748();
}

void sub_8086738(void)
{
    s32 i;

    for (i = 0; i < 250; i += 10) {
        SetDungeonBGColorRGB(i, i, i, TRUE, FALSE);
        DungeonRunFrameActions(70);
    }
}

void sub_8086764(void)
{
    s32 i;

    for (i = 250; i >= 0; i -= 5) {
        SetDungeonBGColorRGB(i, i, i, TRUE, FALSE);
        DungeonRunFrameActions(70);
    }

    sub_8085EB0();
}

void sub_8086794(void)
{
    s32 i;

    gDungeonBrightness = 0;

    for (i = 0; i < 200; i++) {
        SetDungeonBGColorRGB(0, 0, 0, TRUE, FALSE);
        BgColorCallNullsub4();
        DungeonRunFrameActions(70);

        if ((i & 3) == 0) {
            gDungeonBrightness++;
            if (gDungeonBrightness == 31)
                break;
        }
    }

    DungeonRunFrameActions(70);
    gDungeon->unk7 = 0;
}

void sub_80867F4(void)
{
    gUnknown_202F3D0.unk0 = 0;
    gUnknown_202F3D0.unk1 = 0;
    gUnknown_202F3D0.unk2 = 0;
    gUnknown_202F3D0.unk3 = 0;
    gUnknown_202F3D0.unk4 = 0;
    gUnknown_202F3D0.unk5 = 0;
}

void sub_808680C(void)
{
    gUnknown_202F3D0.unk0 = 1;
    if (gUnknown_202F3D0.unk3 != 0)
        PlaySoundEffect(505);
}

void sub_808682C(void)
{
    gUnknown_202F3D0.unk0 = 0;
}

void sub_8086838(u8 entity, u8 r1, u8 r2)
{
    gUnknown_202F3D0.unk1 = entity;
    gUnknown_202F3D0.unk2 = r1;
    gUnknown_202F3D0.unk3 = r2;
}

void sub_8086848(u8 entity, u8 r1)
{
    gUnknown_202F3D0.unk4 = entity;
    gUnknown_202F3D0.unk5 = r1;
}

void sub_8086854(void)
{
    if (gUnknown_202F3D0.unk0) {
        if (gUnknown_202F3D0.unk4 == 0) {
            if (gUnknown_202F3D0.unk1) {
                gUnknown_202F3D0.unk4 = 80;
                gUnknown_202F3D0.unk5 = 16;
            }
            else {
                gUnknown_202F3D0.unk4 = RandInt(6) + 2;
                gUnknown_202F3D0.unk5 = RandInt(6) + 2;
            }

            if (gUnknown_202F3D0.unk3 != 0)
                PlaySoundEffect(505);
        }
        else
            gUnknown_202F3D0.unk4--;

        if (gUnknown_202F3D0.unk5 != 0)
            gUnknown_202F3D0.unk5--;

        gDungeon->unk181e8.unk181FC = gUnknown_8107314[gUnknown_202F3D0.unk5];
    }
    else
        gDungeon->unk181e8.unk181FC = 0;
}

void sub_80868F4(Entity *entity)
{
    GetEntInfo(entity)->unk15C = 1;
    GetEntInfo(entity)->unk15D = 1;
}

void sub_8086910(Entity *entity)
{
    GetEntInfo(entity)->unk15C = 0;
    GetEntInfo(entity)->unk15D = 0;
}

void sub_808692C(void)
{
    sub_80859F0(DIRECTION_NORTHWEST);
    DungeonWaitFrames_Async(4, 70);

    sub_80859F0(DIRECTION_WEST);
    DungeonWaitFrames_Async(4, 70);

    sub_80859F0(DIRECTION_SOUTHWEST);
    DungeonWaitFrames_Async(4, 70);

    sub_80859F0(DIRECTION_SOUTH);
    DungeonWaitFrames_Async(4, 70);
}

void CutsceneLookAroundEffect_Async(Entity *entity)
{
    s8 dir = (s8)GetEntInfo(entity)->action.direction;

    dir = TransformDirection1(dir, DIR_TRANS_SPINLEFT2);
    CutsceneLookDir_Async(entity, 4, DIR_TRANS_SPINLEFT1, dir);
    DungeonWaitFrames_Async(15, 70);
    dir = TransformDirection1(dir, DIR_TRANS_FLIP);
    CutsceneLookDir_Async(entity, 4, DIR_TRANS_SPINRIGHT1, dir);
    DungeonWaitFrames_Async(15, 70);
    dir = TransformDirection1(dir, DIR_TRANS_SPINLEFT2);
    CutsceneLookDir_Async(entity, 4, DIR_TRANS_SPINLEFT1, dir);
    DungeonWaitFrames_Async(15, 70);
}

void CutsceneLookDir_Async(struct Entity *entity, s32 numFrames, u8 dirTrans, s32 _someDirection)
{
    s32 someDirection = (s8) _someDirection;
    struct EntityInfo *info = GetEntInfo(entity);
    s32 direction = (s8) info->action.direction;

    while (direction != someDirection) {
        direction = (s8) TransformDirection2(direction, someDirection, dirTrans);
        info->action.direction = direction;
        info->action.direction &= DIRECTION_MASK;
        sub_806CE68(entity, info->action.direction);
        DungeonWaitFrames_Async(numFrames, 70);
    }
}

void sub_8086A3C(Entity *pokemon)
{
    GetEntInfo(pokemon)->unk15C = 1;
    GetEntInfo(pokemon)->unk15E = 1;
}

void sub_8086A54(Entity *pokemon)
{
    GetEntInfo(pokemon)->unk15C = 1;
    GetEntInfo(pokemon)->unk15E = 0;
}

void SetupBossFightHP(Entity *pokemon, s32 newHP, u16 songIndex)
{
    EntityInfo *entityInfo = GetEntInfo(pokemon);

    entityInfo->bossFlag = TRUE;

    // BUG: Source of the Reviver Seed Boss Glitch
    //
    // Video to demonstration:
    // https://www.youtube.com/watch?v=rHu7EehrZ68
    entityInfo->originalHP = entityInfo->maxHPStat;
    if (newHP != 0) {
        entityInfo->maxHPStat = newHP;
        entityInfo->HP = newHP;
    }

    gDungeon->unk644.bossSongIndex = songIndex;
    SetDefaultIQSkills(&entityInfo->IQSkillMenuFlags, entityInfo->bossFlag);
    LoadIQSkills(pokemon);
}

void sub_8086AC0(void)
{
    if (!IsFloorOver() && gDungeon->unk2 == DUNGEON_UNK2_0)
        FlushTempCutsceneFlags();
}

bool8 sub_8086AE4(s16 _index)
{
    s32 pokeIndex = _index;

    if (!gDungeon->unk644.canChangeLeader)
        return TRUE;
    else
        return HasRecruitedMon(pokeIndex);
}

