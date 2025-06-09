#include "global.h"
#include "globaldata.h"
#include "dungeon_spawns.h"
#include "constants/dungeon.h"
#include "constants/trap.h"
#include "structs/str_202ED28.h"
#include "structs/str_202EDE8.h"
#include "bg_palette_buffer.h"
#include "graphics_memory.h"
#include "code_800D090.h"
#include "code_803D110.h"
#include "dungeon_vram.h"
#include "cpu.h"
#include "def_filearchives.h"
#include "dungeon_info.h"
#include "dungeon_random.h"
#include "file_system.h"
#include "game_options.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "text_1.h"
#include "text_3.h"
#include "dungeon_config.h"
#include "structs/dungeon_mapparam.h"

void sub_803D4AC(void)
{
    gDungeon->unk1C570.id = DUNGEON_INVALID;
    gDungeon->unk1C570.floor = 0xFF;
}

void SetFloorItemMonsterSpawns(void)
{
    s16 spArray[NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS];
    s32 i, j, k;
    OpenedFile *file;
    struct DungeonMapParam1 *strPtr;

    GeneralizeMazeDungeonLoc(&gDungeon->unk644.dungeonLocation2, &gDungeon->unk644.dungeonLocation);
    if (gDungeon->unk1C570.id == gDungeon->unk644.dungeonLocation2.id && gDungeon->unk1C570.floor == gDungeon->unk644.dungeonLocation2.floor)
        return;

    gDungeon->unk1C570 = gDungeon->unk644.dungeonLocation2;
    file = OpenFileAndGetFileDataPtr("mapparam", &gDungeonFileArchive);
    strPtr = &((struct DungeonMapParam2 *)(file->data))->unk0[gDungeon->unk1C570.id][gDungeon->unk1C570.floor];

    gDungeon->unk1CEC8 = GetDungeonFloorCount(gDungeon->unk644.dungeonLocation.id);
    gDungeon->startFloorId = GetDungeonStartingFloor(gDungeon->unk644.dungeonLocation.id);

    gDungeon->floorProperties = ((struct DungeonMapParam2 *)(file->data))->floorProperties[strPtr->unk0];

    for (i = 0; i < NUM_TRAPS; i++) {
        gDungeon->trapSpawnChances[i] = ((struct DungeonMapParam2 *)(file->data))->trapSpawnChances[strPtr->unk4][i];
    }
    for (i = 0; i < MONSTER_SPAWNS_ARR_COUNT - 1; i++) {
        gDungeon->fileMonsterSpawns[i] = ((struct DungeonMapParam2 *)(file->data))->monsterSpawns[strPtr->unk2][i];
        if (ExtractSpeciesIndex(&gDungeon->fileMonsterSpawns[i]) == 0)
            break;
    }
    while (i < MONSTER_SPAWNS_ARR_COUNT) {
        SetSpeciesToExtract(&gDungeon->fileMonsterSpawns[i], 0);
        i++;
    }

    for (i = 0; i < 4; i++)
    {
        u16 *src = ((struct DungeonMapParam2 *)(file->data))->itemSpawns[strPtr->unk6[i]];
        s32 arrId = 0;

        for (j = 0; j < NUM_ITEM_CATEGORIES + NUMBER_OF_ITEM_IDS; ) {
            if (src[arrId] >= 30000) {
                for (k = src[arrId] - 30000; k != 0; k--) {
                    spArray[j++] = 0;
                }
            }
            else {
                spArray[j++] = src[arrId];
            }
            arrId++;
        }

        arrId = 0;
        for (j = 0; j < NUM_ITEM_CATEGORIES; j++) {
            gDungeon->itemSpawns[i].categoryValues[arrId] = spArray[arrId];
            arrId++;
        }

        for (j = 0; j < NUMBER_OF_ITEM_IDS; j++) {
            gDungeon->itemSpawns[i].itemValues[j] = spArray[arrId];
            arrId++;
        }
    }

    CloseFile(file);
}

u8 GetRandomFloorTrap(void)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    for (i = 0; i < NUM_TRAPS; i++) {
        if (gDungeon->trapSpawnChances[i] != 0 && gDungeon->trapSpawnChances[i] >= rand)
            return i;
    }

    return TRAP_CHESTNUT_TRAP;
}

u8 GetRandomFloorItem(s32 spawnType)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);
    u8 category = NUM_ITEM_CATEGORIES;
    for (i = 0; i < NUM_ITEM_CATEGORIES; i++) {
        if (gDungeon->itemSpawns[spawnType].categoryValues[i] != 0 && gDungeon->itemSpawns[spawnType].categoryValues[i] >= rand) {
            category = i;
            break;
        }
    }
    if (category == NUM_ITEM_CATEGORIES)
        return ITEM_POKE;

    rand = DungeonRandInt(10000);
    for (i = 0; i < NUMBER_OF_ITEM_IDS; i++) {
        if (gDungeon->itemSpawns[spawnType].itemValues[i] != 0 && GetItemCategory(i) == category && gDungeon->itemSpawns[spawnType].itemValues[i] >= rand) {
            return i;
        }
    }

    return ITEM_POKE;
}

s32 SetMonsterSpawnsArray(SpawnPokemonData *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < MONSTER_SPAWNS_ARR_COUNT; i++) {
        if (ExtractSpeciesIndex(&gDungeon->fileMonsterSpawns[i]) == 0)
            break;
        strPtr[id] = gDungeon->fileMonsterSpawns[i];
        id++;
    }

    return id;
}

s32 GetAvailableMonsToTransform(SpawnPokemonData *strPtr, s32 id)
{
    s32 i;

    for (i = 0; i < MONSTER_SPAWNS_ARR_COUNT; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->fileMonsterSpawns[i]);
        if (species == 0)
            break;
        if (GetBodySize(species) < 2 && gDungeon->fileMonsterSpawns[i].randNum[0] != 0) {
            strPtr[id] = gDungeon->fileMonsterSpawns[i];
            id++;
        }
    }

    return id;
}

void SetCurrentMonsterSpawns(void)
{
    if (!gDungeon->monsterSpawnsPopulated) {
        gDungeon->monsterSpawnsPopulated = TRUE;
        gDungeon->currFloorMonsterSpawnsCount = SetMonsterSpawnsArray(gDungeon->monsterSpawns, 0);
    }
}

bool8 CanMonsterBeSpawnedHere(s16 speciesToFind)
{
    s32 i;
    s32 id = SpeciesId(speciesToFind);

    for (i = 0; i < MONSTER_SPAWNS_ARR_COUNT; i++) {
        s16 species = ExtractSpeciesIndex(&gDungeon->fileMonsterSpawns[i]);
        if (species == 0)
            break;
        if (species == id)
            return TRUE;
    }
    return FALSE;
}

s16 GetRandomFloorMonsterId(s32 arrId)
{
    s32 i;
    s32 rand = DungeonRandInt(10000);

    for (i = 0; i < gDungeon->currFloorMonsterSpawnsCount; i++) {
        if (gDungeon->monsterSpawns[i].randNum[arrId] != 0 && gDungeon->monsterSpawns[i].randNum[arrId] >= rand) {
            return ExtractSpeciesIndex(&gDungeon->monsterSpawns[i]);
        }
    }
    for (i = 0; i < gDungeon->currFloorMonsterSpawnsCount; i++) {
        if (gDungeon->monsterSpawns[i].randNum[arrId] != 0) {
            return ExtractSpeciesIndex(&gDungeon->monsterSpawns[i]);
        }
    }

    return MONSTER_KECLEON;
}

s32 GetSpawnedMonsterLevel(s32 species)
{
    s32 i;
    s32 speciesId = SpeciesId(species);

    for (i = 0; i < gDungeon->currFloorMonsterSpawnsCount; i++) {
        if (ExtractSpeciesIndex(&gDungeon->monsterSpawns[i]) == speciesId)
            return ExtractLevel(&gDungeon->monsterSpawns[i]);
    }
    return 1;
}
