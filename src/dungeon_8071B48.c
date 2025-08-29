#include "global.h"
#include "globaldata.h"
#include "constants/tactic.h"
#include "dungeon_config.h"
#include "dungeon_range.h"
#include "dungeon_message.h"
#include "code_8041AD0.h"
#include "code_8077274_1.h"
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

extern void sub_8042920(struct Entity *r0);

void sub_8071B48(void)
{
  const Tile *tile;
  struct Entity *entity2;
  struct Entity *entity;
  int index;
  int index1;
  int counter;
  struct Entity *entityPtr;
  s32 level;
  struct Dungeon *dungeon; // feels like a hack
  struct MonSpawnInfo local_2c;

  entityPtr = NULL;
  dungeon = gDungeon;
  if ((dungeon->unk644.unk20 != 0) &&
     ((dungeon->unk644.dungeonLocation.id != DUNGEON_METEOR_CAVE || (dungeon->unk37FD == 0)))) {
    dungeon->unk644.unk1E++;
    if (dungeon->unk644.unk2A == 0) {
      if ( dungeon->unk644.unk1E < gUnknown_80F4DAA) {
        return;
      }
    }
    else {
      if ( dungeon->unk644.unk1E < gUnknown_80F4DAC) {
        return;
      }
    }

    if (dungeon->unk644.unk1E > 900) {
      entity2 = dungeon->unk17B34;
      if ((EntityIsValid(entity2)) && (entity2->spawnGenID == dungeon->unk17B40)) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity2,0);
        entityPtr = entity2;
      }
    }

      dungeon->unk644.unk1E = 0;
      dungeon->unk17B34 = NULL;

      counter = 0;
      for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
      {
        entity = dungeon->wildPokemon[index];
        if ((EntityIsValid(entity)) &&
           (tile = GetTile((entity->pos).x, (entity->pos).y),
           (tile->terrainFlags & TERRAIN_TYPE_UNBREAKABLE) == 0)) {
          counter++;
        }
      }
      if (dungeon->unk644.unk2A == 0) {
        if (gDungeon->monsterHouseRoom == CORRIDOR_ROOM) {
            if (counter >= gUnknown_80F4DA6) {
              return;
            }
        }
        else
        {
            if (counter >= gUnknown_80F4DA8) {
              return;
            }
        }

      }
      if (entityPtr != NULL) {
        DisplayDungeonLoggableMessageTrue(0,gUnknown_80FED68);
        sub_8042920(entityPtr);
      }
      if (dungeon->unk644.unk2A != 0) {
        index1 = 0x17c;
      }
      else {
        index1 = GetRandomFloorMonsterId(0);
      }

      level = GetSpawnedMonsterLevel(index1);
      if (level == 0) {
        level = 1;
      }
      if ((sub_806AA0C(index1, 0)) && (sub_8083660(&local_2c.pos))) {
        local_2c.species = index1;
        local_2c.level = level;
        local_2c.unk2 = 0;
        if(DungeonRandInt(100) < GetRandomMovementChance(gDungeon->unk644.dungeonLocation.id))
        {
            local_2c.unk4 = 1;
        }
        else
        {
            local_2c.unk4 = 0;
        }
        local_2c.unk10 = 0;
        SpawnWildMon(&local_2c, FALSE);
      }
  }
}
