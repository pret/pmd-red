#include "global.h"
#include "globaldata.h"
#include "constants/ability.h"
#include "constants/weather.h"
#include "dungeon_vram.h"
#include "dungeon_message.h"
#include "code_806CD90.h"
#include "code_807CD9C.h"
#include "structs/str_dungeon.h"
#include "code_8077274_1.h"
#include "dungeon_ai.h"
#include "run_dungeon.h"
#include "dungeon_generation.h"
#include "dungeon_logic.h"
#include "dungeon_map.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "math.h"
#include "move_effects_target.h"
#include "moves.h"
#include "move_util.h"
#include "code_8041AD0.h"
#include "weather.h"
#include "dungeon_config.h"
#include "dungeon_misc.h"
#include "dungeon_items.h"
#include "dungeon_strings.h"
#include "dungeon_engine.h"

extern void sub_806F370(Entity *pokemon, Entity *target, u32, u32, u8 *, u8 moveType, s32, u32, u32, u32);
extern void sub_804216C(Entity *pokemon, Entity *target, u32 r2);
extern void sub_804218C(Entity *pokemon, Entity *target);

static EWRAM_INIT u32 gUnknown_203B444[3] = {0x28, 0x28, 0x50};

void sub_807E1A0(Entity *pokemon,Entity *target,u8 moveType,s32 param_4,s32 param_5);

static const DungeonPos gUnknown_81070E8[] = {
    {0, 0},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {99, 99},
};

static const DungeonPos gUnknown_8107110[] = {
    {0, 0},
    {0, 1},
    {1, 1},
    {1, 0},
    {1, -1},
    {0, -1},
    {-1, -1},
    {-1, 0},
    {-1, 1},
    {0, 2},
    {1, 2},
    {2, 2},
    {2, 1},
    {2, 0},
    {2, -1},
    {2, -2},
    {1, -2},
    {0, -2},
    {-1, -2},
    {-2, -2},
    {-2, -1},
    {-2, 0},
    {-2, 1},
    {-2, 2},
    {-1, 2},
    {99, 99},
};

static const DungeonPos *const gUnknown_8107178[3] = {
    gUnknown_81070E8,
    gUnknown_81070E8,
    gUnknown_8107110
};

void HandleExplosion(Entity *pokemon,Entity *target,DungeonPos *param_3,s32 param_4,u8 moveType,s16 param_6)
{
    bool8 flag;
    const DungeonPos *posPtr;
    Tile *tile;
    Entity * entity1;
    Entity *entity2;
    int x;
    int y;
    int index;
    DungeonPos pos;

    u32 uStack_2c;

    uStack_2c = param_6;
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
        entity1 = gDungeon->activePokemon[index];
        if ((EntityIsValid(entity1)) && (AbilityIsActive(entity1, ABILITY_DAMP))) break;
    }
    if (index != DUNGEON_MAX_POKEMON) {
        sub_804218C(pokemon,target);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F96EC);
    }
    else if (GetApparentWeather(target) == WEATHER_RAIN) {
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F96EC);
    }
    else
    {
        sub_804216C(pokemon,target,param_4);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],target,0);
        TryDisplayDungeonLoggableMessage3(pokemon,target,gUnknown_80F96BC);
        flag = FALSE;

        posPtr = (gUnknown_8107178)[param_4];
        if (posPtr->x != 99) {
            while (posPtr->x != 99) {
                pos.x = posPtr->x + param_3->x;
                pos.y = posPtr->y + param_3->y;
                if ((0 <= pos.x) && (0 <= pos.y) && (pos.x < DUNGEON_MAX_SIZE_X) && (pos.y < DUNGEON_MAX_SIZE_Y)) {
                    tile = GetTileMut(pos.x,pos.y);
                    if ((0 < pos.x) && (0 < pos.y && ((pos.x < (DUNGEON_MAX_SIZE_X - 1) && ((pos.y < (DUNGEON_MAX_SIZE_Y - 1)
                        && GetTerrainType(tile) == TERRAIN_TYPE_WALL)))
                    )) && (tile->terrainType & TERRAIN_TYPE_IMPASSABLE_WALL) == 0) {
                        SetTerrainNormal(tile);
                        for(y = -1; y < 2; y++)
                        {
                            for(x = -1; x < 2; x++)
                            {
                                sub_80498A8(pos.x + x,pos.y + y);
                            }
                        }
                        flag = TRUE;
                    }
                    entity2 = tile->object;
                    if (((entity2 != NULL) && (entity2 != target)) && (GetEntityType(entity2) == ENTITY_ITEM)) {
                        RemoveGroundItem(&pos, 0);
                    }
                    entity2 = tile->monster;
                    if (((entity2 != NULL) && (entity2 != target)) && (GetEntityType(entity2) == ENTITY_MONSTER)) {
                        sub_807E1A0(pokemon,entity2,moveType,uStack_2c,gUnknown_203B444[param_4]);
                        if (IsFloorOver()) break;
                    }
                }
                posPtr++;
            }
        }
        if (IsFloorOver()) {
            return;
        }
        if (GetEntityType(target) == ENTITY_MONSTER) {
            sub_807E1A0(pokemon,target,moveType,uStack_2c,gUnknown_203B444[param_4]);
        }
        if (!flag) {
            return;
        }
        for(y = 0; y < DUNGEON_MAX_SIZE_Y; y++)
        {
            for(x = 0; x < DUNGEON_MAX_SIZE_X; x++)
            {
                sub_8049BB0(x,y);
            }
        }
        UpdateMinimap();
        UpdateTrapsVisibility();
    }
}

void sub_807E1A0(Entity *pokemon,Entity *target,u8 moveType,s32 param_4,s32 param_5)
{
  EntityInfo *targetInfo;
  u8 flag;
  Move move;
  s32 newHP;
  s32 param_4_s32;

  param_4_s32 = (s16) param_4;

  if (EntityIsValid(target)) {
    targetInfo = GetEntInfo(target);
    InitPokemonMove(&move, MOVE_REGULAR_ATTACK);
    if (!sub_80571F0(target,&move)) {
      if (!targetInfo->isNotTeamMember) {
        newHP = targetInfo->HP;
        newHP /= 2;
        if (MonsterIsType(target, TYPE_FIRE)) {
          newHP /= 2;
        }
        if (newHP < 1) {
          newHP = 1;
        }
      }
      else {
        newHP = param_5;
        if (MonsterIsType(target, TYPE_FIRE)) {
           newHP /= 2;
        }
      }
      sub_806F370(pokemon,target,newHP,0,&flag,moveType,param_4_s32,0,0,0);
    }
  }
}

