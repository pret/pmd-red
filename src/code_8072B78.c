#include "global.h"
#include "code_805D8C8.h"
#include "code_806CD90.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_random.h"
#include "moves.h"
#include "pokemon_mid.h"
#include "pokemon_mid.h"
#include "status_checks_1.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_pokemon.h"

extern u8 gAvailablePokemonNames[];
extern u8 gUnknown_202DFE8[];
extern Position gAdjacentTileOffsets[];
extern u8 *gUnknown_80FE2EC[];

struct unkStruct_806B7F8
{
    u16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    u8 fillA[0xC - 0xA];
    struct Position pos;
    u8 unk10;
};

extern Entity* sub_806B7F8(struct unkStruct_806B7F8 *, bool8);
extern void sub_806BFC0(EntityInfo *, u32);
void sub_8069E0C(Entity *pokemon);
void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);
void sub_8042A44(Entity *r0);
void sub_8083D78(void);
extern bool8 sub_803D930(u32);

void sub_8072AC8(s16 *param_1, s16 species, s32 param_3)
{
  const u8 *levelUpMoves;
  s32 arrIndex;
  s32 counter;
  u16 moveIDs [2];
  s32 species_s32;
  s32 index;

  species_s32 = species;

  for(index = 0; index < MAX_MON_MOVES; index++) {
    param_1[index] = MOVE_NOTHING;
  }

  counter = 0;
  levelUpMoves = GetLevelUpMoves(species_s32);

  while( 1 ) {
    if (*levelUpMoves == 0) {
      return;
    }
    levelUpMoves = DecompressMoveID(levelUpMoves,moveIDs);
    if (*levelUpMoves++ > param_3) break;
    if (counter == MAX_MON_MOVES) {
      arrIndex = DungeonRandInt(MAX_MON_MOVES);
      counter = MAX_MON_MOVES;
    }
    else {
      arrIndex = counter;
      counter++;
    }
    param_1[arrIndex] = moveIDs[0];
  }
}

void sub_8072B24(Entity *entity, Move *moves)
{
    int index;
    int count;

    count = 0;
    for(index = 0; index < 8; index++)
    {
        if (moves[index].moveFlags & MOVE_FLAG_EXISTS) {
            moves[index].moveFlags &= 0xfd;
            count++;
        }
    }
    index = DungeonRandInt(count);
    for (; index < 7; index++) {
        moves[index] = moves[index + 1];
    }
    moves[7].moveFlags = 0;
}

static inline void fu(EntityInfo *entityInfo, s16 id)
{
  ++id; --id;
  entityInfo->apparentID = id;
  entityInfo->id = id;
}

void sub_8072B78(Entity *pokemon, Entity *target, s16 id)
{
  OpenedFile *file;
  Tile *tile;
  int index;
  s32 id_s32;
  EntityInfo *entityInfo;
  LevelData levelData;
  struct unkStruct_806B7F8 local_2c;

  id_s32 = id;
  entityInfo = target->axObj.info;
  SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
  CopyCyanMonsterNametoBuffer(gAvailablePokemonNames + 0x50,id_s32);
  file = GetSpriteData(id_s32);
  fu(entityInfo, id_s32);
  GetPokemonLevelData(&levelData,id_s32,entityInfo->level);
  entityInfo->exp = levelData.expRequired;
  target->axObj.spriteFile = file;
  sub_806BFC0(entityInfo,0);
  sub_8069E0C(target);
  sub_806CCB4(target,7);
  sub_80522F4(pokemon,target,*gUnknown_80FE2EC);
  sub_8042A44(target);
  sub_8083D78();
  if (id_s32 == MONSTER_NINJASK) {
    for (index = 0; index < 8; index++) {
      tile = GetTile(gAdjacentTileOffsets[index].x + target->pos.x,gAdjacentTileOffsets[index].y + target->pos.y);
      if (sub_807034C(MONSTER_SHEDINJA,tile) == 0) break;
    }
    if (sub_803D930(MONSTER_SHEDINJA)) {
      local_2c.species = MONSTER_SHEDINJA;
      local_2c.level = entityInfo->level;
      local_2c.unk2 = 0;
      local_2c.pos.x = gAdjacentTileOffsets[index].x + target->pos.x;
      local_2c.pos.y = gAdjacentTileOffsets[index].y + target->pos.y;
      local_2c.unk4 = 0;
      local_2c.unk10 = 0;
      sub_806B7F8(&local_2c, TRUE);
    }
  }
}
