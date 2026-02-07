#include "global.h"
#include "globaldata.h"
#include "dungeon_monster_house.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "code_805D8C8.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_orb_effects_1.h"
#include "moves.h"
#include "math.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_config.h"
#include "dungeon_logic.h"
#include "dungeon_strings.h"
#include "dungeon_floor_spawns.h"
#include "dungeon_misc.h"
#include "dungeon_mon_spawn.h"
#include "move_orb_effects_5.h"
#include "dungeon_8041AD0.h"

void TryWakeSleepingWildPokemon(void)
{
    s32 wildIndex, teamIndex;

    for (wildIndex = 0; wildIndex < DUNGEON_MAX_WILD_POKEMON; wildIndex++) {
        Entity *wildEntity = gDungeon->wildPokemon[wildIndex];
        if (EntityIsValid(wildEntity)) {
            EntityInfo *entityInfo = GetEntInfo(wildEntity);
            if (entityInfo->sleepClassStatus.status != STATUS_SLEEP)
                continue;
            if (entityInfo->sleepClassStatus.turns == 0x7F) {
                bool8 adjacentCheck = FALSE;
                bool8 wakeUp = FALSE;
                u8 room = GetEntityRoom(wildEntity);

                for (teamIndex = 0; teamIndex < MAX_TEAM_MEMBERS; teamIndex++) {
                    Entity *teamEntity = gDungeon->teamPokemon[teamIndex];
                    if (EntityIsValid(teamEntity) && !HasHeldItem(teamEntity, ITEM_SNEAK_SCARF)) {
                        if (abs(teamEntity->pos.x - wildEntity->pos.x) <= 1
                           && abs(teamEntity->pos.y- wildEntity->pos.y) <= 1)
                        {
                            adjacentCheck = TRUE;
                            break;
                        }
                        else if (HasHeldItem(teamEntity, ITEM_RACKET_BAND) && room == GetEntityRoom(teamEntity)) {
                            wakeUp = TRUE;
                            break;
                        }
                    }
                }

                if (!wakeUp) {
                    if (adjacentCheck)
                        wakeUp = TRUE;
                }

                if (wakeUp) {
                    WakeUpPokemon(wildEntity);
                }
            }
        }
    }
}

void TriggerMonsterHouse_Async(Entity *entity, bool8 forcedMonsterHouse)
{
    u8 monsterHouseRoomId;
    DungeonPos positions[100];
    RoomData *monsterHouseRoomData;
    s32 x, y, count;
    s32 randMonstersCount;

    if (GetEntInfo(entity)->isNotTeamMember)
        return;
    if (!(GetTileAtEntitySafe(entity)->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE))
        return;

    if (gDungeon->unk644.monsterHouseTriggered)
        return;
    gDungeon->unk644.monsterHouseTriggered = TRUE;

    monsterHouseRoomId = gDungeon->monsterHouseRoom;
    if (monsterHouseRoomId == CORRIDOR_ROOM)
        return;

    monsterHouseRoomData = &gDungeon->roomData[monsterHouseRoomId];
    count = 0;
    if (forcedMonsterHouse) {
        for (y = entity->pos.y - 4; y <= entity->pos.y + 4; y++) {
            for (x = entity->pos.x - 4; x <= entity->pos.x + 4; x++) {
                Tile *tile = GetTileMut(x, y);
                if (tile->monster == NULL && GetTerrainType(tile) == TERRAIN_TYPE_NORMAL && count < 100) {
                    positions[count].x = x;
                    positions[count].y = y;
                    count++;
                }
            }
        }
    }
    else {
        s32 xStart, xEnd;
        s32 yStart, yEnd;

        xStart = max(entity->pos.x - 4, monsterHouseRoomData->bottomRightCornerX);
        xEnd = min(entity->pos.x + 5, monsterHouseRoomData->topLeftCornerX);

        yStart = max(entity->pos.y - 4, monsterHouseRoomData->bottomRightCornerY);
        yEnd = min(entity->pos.y + 5, monsterHouseRoomData->topLeftCornerY);
        for (y = yStart; y < yEnd; y++) {
            for (x = xStart; x < xEnd; x++) {
                Tile *tile = GetTileMut(x, y);
                if (tile->monster == NULL && GetTerrainType(tile) == TERRAIN_TYPE_NORMAL && tile->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE && count < 100) {
                    positions[count].x = x;
                    positions[count].y = y;
                    count++;
                }
            }
        }
    }

    randMonstersCount = DungeonRandRange(gMonsterHouseMinMons, gMonsterHouseMaxMons);
    if (randMonstersCount >= count)
        randMonstersCount = count;

    for (y = 0; y < randMonstersCount; y++) {
        s32 i, j;
        s32 rndId = DungeonRandInt(count);
        for (i = 0; i < count; i++) {
            if (positions[rndId].x != 0)
                break;

            rndId++;
            if (rndId >= count)
                rndId = 0;
        }

        if (positions[rndId].x == 0) {
            break;
        }
        else
        {
            struct MonSpawnInfo spawnStruct;

            spawnStruct.species = GetRandomFloorMonsterId(1);
            spawnStruct.level = 0;
            spawnStruct.unk2 = 0;
            spawnStruct.unk4 = 0;
            spawnStruct.unk10 = 1;
            spawnStruct.pos.x = positions[rndId].x;
            spawnStruct.pos.y = positions[rndId].y;
            if (sub_806AA0C(spawnStruct.species, 1)) {
                Entity *newMonster = SpawnWildMon(&spawnStruct, FALSE);
                if (EntityIsValid(newMonster)) {
                    newMonster->unk1C = IntToF248(200);
                    for (j = 0; j < 100; j++) {
                        newMonster->unk1C = s24_8_mul(newMonster->unk1C, IntToF248(0.665));
                        if (newMonster->unk1C < IntToF248(1)) {
                            break;
                        }
                        DungeonRunFrameActions(87);
                    }
                    newMonster->unk1C = IntToF248(0);
                }
            }
        }

    }

    sub_804178C_Async(TRUE);
}

