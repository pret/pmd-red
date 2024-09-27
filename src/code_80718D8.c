#include "global.h"
#include "code_8045A00.h"
#include "constants/dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon.h"
#include "structs/str_dungeon.h"

struct unkStruct_806B7F8
{
    s16 species;
    u8 unk2;
    u32 unk4;
    u16 level;
    u8 fillA[2];
    struct Position pos;
    u8 unk10;
};

extern u8 gAvailablePokemonNames[];
extern s16 gUnknown_80F4DA6;
extern s16 gUnknown_80F4DA8;
extern s16 gUnknown_80F4DAA;
extern s16 gUnknown_80F4DAC;
extern u8 *gUnknown_80FED68[];

extern Entity* sub_806B7F8(struct unkStruct_806B7F8 *, bool8);
extern void sub_805239C(struct Entity *r0, const char r1[]);
extern void sub_8042920(struct Entity *r0);
extern s16 sub_803D970(u32);
extern s32 sub_803DA20(s32 param_1);
extern bool8 sub_806AA0C(s32, u32);
extern bool8 sub_8083660(struct Position *param_1);

void sub_8071B48(void)
{
  struct Tile *tile;
  struct Entity *entity2;
  struct Entity *entity;
  int index;
  int index1;
  int counter;
  struct Entity *entityPtr;
  s32 level;
  struct Dungeon *dungeon; // feels like a hack
  struct unkStruct_806B7F8 local_2c;

  entityPtr = NULL;
  dungeon = gDungeon;
  if ((dungeon->unk664 != 0) &&
     ((dungeon->dungeonLocation.id != DUNGEON_METEOR_CAVE || (dungeon->fill37FD == 0)))) {
    dungeon->unk662++;
    if (dungeon->unk66E == 0) {
      if ( dungeon->unk662 < gUnknown_80F4DAA) {
        return;
      }
    }
    else {
      if ( dungeon->unk662 < gUnknown_80F4DAC) {
        return;
      }
    }

    if (dungeon->unk662 > 900) {
      entity2 = dungeon->unk17B34;
      if ((EntityExists(entity2)) && (entity2->spawnGenID == dungeon->unk17B40)) {
        SetMessageArgument(gAvailablePokemonNames,entity2,0);
        entityPtr = entity2;
      }
    }

      dungeon->unk662 = 0;
      dungeon->unk17B34 = NULL;

      counter = 0;
      for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
      {
        entity = dungeon->wildPokemon[index];
        if ((EntityExists(entity)) &&
           (tile = GetTile((entity->pos).x, (entity->pos).y),
           (tile->terrainType & 0x100) == 0)) {
          counter++;
        }
      }
      if (dungeon->unk66E == 0) {
        if (gDungeon->unk3A0C == 0xff) {
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
        sub_805239C(0,*gUnknown_80FED68);
        sub_8042920(entityPtr);
      }
      if (dungeon->unk66E != 0) {
        index1 = 0x17c;
      }
      else {
        index1 = sub_803D970(0);
      }

      level = sub_803DA20(index1);
      if (level == 0) {
        level = 1;
      }
      if ((sub_806AA0C(index1, 0)) && (sub_8083660(&local_2c.pos))) {
        local_2c.species = index1;
        local_2c.level = level;
        local_2c.unk2 = 0;
        if(DungeonRandInt(100) < GetRandomMovementChance(gDungeon->dungeonLocation.id))
        {
            local_2c.unk4 = 1;
        }
        else
        {
            local_2c.unk4 = 0;
        }
        local_2c.unk10 = 0;
        sub_806B7F8(&local_2c, FALSE);
      }
  }
}

void sub_8071D4C(Entity *pokemon, Entity *target, s32 exp)
{
  s32 newExp;
  s32 expDiff;
  EntityInfo *info;

  info = target->axObj.info;
  if (info->level != 100) {
    if (!IsClientOrTeamBase(info->joinedAt.joinedAt)) {
      newExp = info->exp + exp;
      if (9999998 < newExp) {
        newExp = 9999999;
      }
      expDiff = newExp - info->exp;
      if (expDiff != 0) {
        info->expGainedInTurn += expDiff;
        gDungeon->unkD = 1;
      }
    }
  }
}
