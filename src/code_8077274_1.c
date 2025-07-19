#include "global.h"
#include "globaldata.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_random.h"
#include "constants/ability.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_items.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "moves.h"
#include "math.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "structs/str_806B7F8.h"
#include "dungeon_config.h"
#include "dungeon_logic.h"
#include "dungeon_strings.h"

extern bool8 sub_806AA0C(s32, u32);
extern s16 GetRandomFloorMonsterId(u32);
extern void sub_804178C(u32);

void sub_807AA30(void)
{
  bool32 adjacentCheck;
  bool32 forceWakeup;
  u8 room;
  s32 xDiff;
  s32 wildIndex;
  s32 yDiff;
  Entity *teamEntity;
  Entity *wildEntity;
  EntityInfo *entityInfo;
  s32 teamIndex;

  for(wildIndex = 0; wildIndex < DUNGEON_MAX_WILD_POKEMON; wildIndex++)
  {
    wildEntity = gDungeon->wildPokemon[wildIndex];
    if (EntityIsValid(wildEntity) &&
        (entityInfo = GetEntInfo(wildEntity), entityInfo->sleepClassStatus.status == STATUS_SLEEP) &&
        (entityInfo->sleepClassStatus.turns == 0x7F)) {
      adjacentCheck = FALSE;
      forceWakeup = FALSE;
      room = GetEntityRoom(wildEntity);

      for(teamIndex = 0; teamIndex < MAX_TEAM_MEMBERS; teamIndex++)
      {
        teamEntity = gDungeon->teamPokemon[teamIndex];
        if (EntityIsValid(teamEntity) && !HasHeldItem(teamEntity, ITEM_SNEAK_SCARF)) {
          xDiff = teamEntity->pos.x - wildEntity->pos.x;
          if (xDiff < 0) {
            xDiff = -xDiff;
          }
          if (xDiff < 2) {
            yDiff = teamEntity->pos.y- wildEntity->pos.y;
            if (yDiff < 0) {
              yDiff = -yDiff;
            }
            if (yDiff < 2) {
              adjacentCheck = TRUE;
              break;
            }
          }
          if (HasHeldItem(teamEntity, ITEM_RACKET_BAND) && (room == GetEntityRoom(teamEntity)))
            goto _WakeUp;
        }
      }

      if(forceWakeup)
        goto _WakeUp;
      else if(adjacentCheck)
        forceWakeup = TRUE;

      if (forceWakeup) {
_WakeUp:
        WakeUpPokemon(wildEntity);
      }
    }
  }
}

void sub_807AB38(Entity *entity, bool8 forcedMonsterHouse)
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
            struct unkStruct_806B7F8 spawnStruct;

            spawnStruct.species = GetRandomFloorMonsterId(1);
            spawnStruct.level = 0;
            spawnStruct.unk2 = 0;
            spawnStruct.unk4 = 0;
            spawnStruct.unk10 = 1;
            spawnStruct.pos.x = positions[rndId].x;
            spawnStruct.pos.y = positions[rndId].y;
            if (sub_806AA0C(spawnStruct.species, 1)) {
                Entity *newMonster = sub_806B7F8(&spawnStruct, FALSE);
                if (EntityIsValid(newMonster)) {
                    newMonster->unk1C = IntToF248_2(200);
                    for (j = 0; j < 100; j++) {
                        newMonster->unk1C = s24_8_mul(newMonster->unk1C, IntToF248_2(0.665));
                        if (newMonster->unk1C.raw < IntToF248_2(1).raw) {
                            break;
                        }
                        DungeonRunFrameActions(0x57);
                    }
                    newMonster->unk1C = IntToF248_2(0);
                }
            }
        }

    }

    sub_804178C(1);
}

