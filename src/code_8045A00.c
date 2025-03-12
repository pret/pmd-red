#include "global.h"
#include "code_8045A00.h"
#include "constants/item.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_leader.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_map.h"
#include "dungeon_ai_targeting.h"
#include "string_format.h"
#include "items.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "trap.h"
#include "math.h"
#include "code_80450F8.h"
#include "dungeon_util.h"
#include "structs/str_item_text.h"

void sub_8045BF8(u8 *, Item *);

extern u8 *gUnknown_80FE6F4[];

void sub_8045ACC(void)
{
  Entity *entity;
  s32 index;
  s32 pokeCount;

  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    entity = gDungeon->wildPokemon[index];
    if (EntityIsValid(entity)) {
      gDungeon->activePokemon[pokeCount] = entity;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeon->activePokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(Entity *pokemon)
{
  Entity *entity;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (pokemon == entity)
      return index;
  }
  return -1;
}

void SubstitutePlaceholderStringTags(u8 *buffer, Entity *entity, u32 param_3)
{
  switch(GetEntityType(entity))
  {
    case ENTITY_MONSTER:
        SetMessageArgument_2(buffer, GetEntInfo(entity), param_3);
        break;
    case ENTITY_ITEM:
        sub_8045BF8(buffer, GetItemData_1(entity));
        break;
    case ENTITY_TRAP:
        GetTrapName(buffer, GetTrapData_1(entity)->id);
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}

// FILE SPLIT HERE


//
