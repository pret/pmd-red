#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern u8 *gUnknown_80FE6F4[];
extern struct unkStruct_8090F58 gUnknown_80F699C;
extern struct unkStruct_8090F58 gUnknown_80F69A8;
extern struct unkStruct_8090F58 gUnknown_80F6990;

extern struct EntityInfo* GetTrapData_1(struct Entity *entity);
extern void SetMessageArgument_2(u8 *, struct EntityInfo *, u32);
extern void GetTrapName(u8 *, u8);

void sub_8045BF8(u8 *, struct Item *);

void sub_8045ACC(void)
{
  struct Entity *entity;
  s32 index;
  s32 pokeCount;
  
  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityExists(entity)) {
      gDungeon->allPokemon[pokeCount] = entity;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    entity = gDungeon->wildPokemon[index];
    if (EntityExists(entity)) {
      gDungeon->allPokemon[pokeCount] = entity;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeon->allPokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(struct Entity *pokemon)
{
  struct Entity *entity;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (pokemon == entity)
      return index;
  }
  return -1;
}

void SetMessageArgument(char *buffer, struct Entity *entity, u32 param_3)
{
  switch(GetEntityType(entity))
  {
    case ENTITY_MONSTER:
        SetMessageArgument_2(buffer, entity->info, param_3);
        break;
    case ENTITY_ITEM:
        sub_8045BF8(buffer, GetItemData_1(entity));
        break;
    case ENTITY_TRAP:
        GetTrapName(buffer, *((u8 *)GetTrapData_1(entity)));
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}

void sub_8045BF8(u8 *buffer, struct Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F699C);
}

void sub_8045C08(u8 *buffer, struct Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F69A8);
}

void sub_8045C18(u8 *buffer, struct Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F6990);
}
