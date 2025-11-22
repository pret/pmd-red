#include "global.h"
#include "globaldata.h"
#include "dungeon_wild_mon_spawn.h"
#include "constants/tactic.h"
#include "dungeon_config.h"
#include "dungeon_range.h"
#include "dungeon_message.h"
#include "dungeon_8041AD0.h"
#include "constants/dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_info.h"
#include "pokemon_3.h"
#include "code_805D8C8.h"
#include "dungeon_logic.h"
#include "dungeon_floor_spawns.h"
#include "dungeon_strings.h"
#include "dungeon_misc.h"
#include "dungeon_mon_spawn.h"

void TrySpawnWildMonster(void)
{
    s32 i;
    s32 species;
    s32 wildMonsCount;
    struct Entity *illuminateEntity;
    s32 level;
    struct Dungeon *dungeon;
    struct MonSpawnInfo monSpawnInfo;

    illuminateEntity = NULL;
    dungeon = gDungeon;
    if (dungeon->unk644.enemyDensity == 0)
        return;
    if (dungeon->unk644.dungeonLocation.id == DUNGEON_METEOR_CAVE && dungeon->unk37FD != 0)
        return;

    dungeon->unk644.wildMonSpawnFrames++;
    if (!dungeon->unk644.stoleFromKecleon) {
        if (dungeon->unk644.wildMonSpawnFrames < gWildSpawnIntervalFrames)
            return;
    }
    else {
        if (dungeon->unk644.wildMonSpawnFrames < gKecleonSpawnIntervalFrames)
            return;
    }

    if (dungeon->unk644.wildMonSpawnFrames > 900) {
        Entity *entity = dungeon->illuminatePokemon;
        if (EntityIsValid(entity) && entity->spawnGenID == dungeon->illuminateMonSpawnGenID) {
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
            illuminateEntity = entity;
        }
    }

    dungeon->unk644.wildMonSpawnFrames = 0;
    dungeon->illuminatePokemon = NULL;

    wildMonsCount = 0;
    for (i = 0; i < DUNGEON_MAX_WILD_POKEMON; i++) {
        Entity *entity = dungeon->wildPokemon[i];
        if (EntityIsValid(entity)) {
            const Tile *tile = GetTile(entity->pos.x, entity->pos.y);
            if (!(tile->terrainFlags & TERRAIN_TYPE_UNBREAKABLE)) {
                wildMonsCount++;
            }
        }
    }

    if (!dungeon->unk644.stoleFromKecleon) {
        if (gDungeon->monsterHouseRoom == CORRIDOR_ROOM) {
            if (wildMonsCount >= gMaxWildMonsInMonsterHouse)
                return;
        }
        else {
            if (wildMonsCount >= gMaxWildMonsInRoom)
                return;
        }
    }
    if (illuminateEntity != NULL) {
        DisplayDungeonLoggableMessageTrue_Async(0,gText_Pokemon0Blinked);
        sub_8042920(illuminateEntity);
    }

    if (dungeon->unk644.stoleFromKecleon) {
        species = MONSTER_KECLEON;
    }
    else {
        species = GetRandomFloorMonsterId(0);
    }

    level = GetSpawnedMonsterLevel(species);
    if (level == 0) {
        level = 1;
    }

    if (sub_806AA0C(species, 0) && sub_8083660(&monSpawnInfo.pos)) {
        monSpawnInfo.species = species;
        monSpawnInfo.level = level;
        monSpawnInfo.unk2 = 0;
        if (DungeonRandInt(100) < GetRandomMovementChance(gDungeon->unk644.dungeonLocation.id)) {
            monSpawnInfo.unk4 = 1;
        }
        else {
            monSpawnInfo.unk4 = 0;
        }
        monSpawnInfo.unk10 = 0;
        SpawnWildMon(&monSpawnInfo, FALSE);
    }
}
