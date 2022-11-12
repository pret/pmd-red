#include "global.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern u8 *gUnknown_80FE6F4[];
extern struct unkStruct_8090F58 gUnknown_80F699C;
extern struct unkStruct_8090F58 gUnknown_80F69A8;
extern struct unkStruct_8090F58 gUnknown_80F6990;

extern struct DungeonEntityData* GetTrapData_1(struct DungeonEntity *entity);
extern void SetMessageArgument_2(u8 *, struct DungeonEntityData *, u32);
extern void GetTrapName(u8 *, u8);

void sub_8045BF8(u8 *, struct ItemSlot *);

void sub_8045ACC(void)
{
  struct DungeonEntity *entity;
  s32 index;
  s32 pokeCount;
  
  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeonGlobalData->teamPokemon[index];
    if (EntityExists(entity)) {
      gDungeonGlobalData->allPokemon[pokeCount] = entity;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    entity = gDungeonGlobalData->wildPokemon[index];
    if (EntityExists(entity)) {
      gDungeonGlobalData->allPokemon[pokeCount] = entity;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeonGlobalData->allPokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(struct DungeonEntity *pokemon)
{
  struct DungeonEntity *entity;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeonGlobalData->teamPokemon[index];
    if (pokemon == entity)
      return index;
  }
  return -1;
}

void SetMessageArgument(char *buffer, struct DungeonEntity *pokemon, u32 param_3)
{
  switch(GetEntityType(pokemon))
  {
    case ENTITY_POKEMON:
        SetMessageArgument_2(buffer, pokemon->entityData, param_3);
        break;
    case ENTITY_ITEM:
        sub_8045BF8(buffer, GetItemData_1(pokemon));
        break;
    case ENTITY_TRAP:
        GetTrapName(buffer, *((u8 *)GetTrapData_1(pokemon)));
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}

void sub_8045BF8(u8 *buffer, struct ItemSlot *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F699C);
}

void sub_8045C08(u8 *buffer, struct ItemSlot *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F69A8);
}

void sub_8045C18(u8 *buffer, struct ItemSlot *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F6990);
}
