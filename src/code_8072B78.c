#include "global.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_pokemon.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "code_805D8C8.h"

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

extern void sub_806B7F8(struct unkStruct_806B7F8 *, u32);
extern void sub_806BFC0(EntityInfo *, u32);
void sub_8069E0C(Entity *pokemon);
extern void sub_806CCB4(Entity *, u8);
void sub_80522F4(Entity *r0, Entity *r1, const char r2[]);
void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);
extern void SetMessageArgument_2(u8 *, EntityInfo *, u32);
void GetPokemonLevelData(LevelData* a1, s16 _id, s32 level);
void sub_8042A44(Entity *r0);
void sub_8083D78(void);
extern bool8 sub_803D930(u32);

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
  entityInfo = target->info;
  SetMessageArgument_2(gAvailablePokemonNames,entityInfo,0);
  CopyCyanMonsterNametoBuffer(gAvailablePokemonNames + 0x50,id_s32);
  file = sub_80687D0(id_s32);
  fu(entityInfo, id_s32);
  GetPokemonLevelData(&levelData,id_s32,entityInfo->level);
  entityInfo->exp = levelData.expRequired;
  target->sprite = file;
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
      sub_806B7F8(&local_2c,1);
    }
  }
}
