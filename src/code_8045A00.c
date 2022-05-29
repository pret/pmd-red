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
  struct DungeonEntity *uVar2;
  s32 index;
  s32 pokeCount;
  
  pokeCount = 0;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    uVar2 = gDungeonGlobalData->teamPokemon[index];
    if (EntityExists(uVar2)) {
      gDungeonGlobalData->allPokemon[pokeCount] = uVar2;
      pokeCount++;
    }
  }

  for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
  {
    uVar2 = gDungeonGlobalData->wildPokemon[index];
    if (EntityExists(uVar2)) {
      gDungeonGlobalData->allPokemon[pokeCount] = uVar2;
      pokeCount++;
    }
  }
  for (; pokeCount < DUNGEON_MAX_POKEMON; pokeCount++) {
    gDungeonGlobalData->allPokemon[pokeCount] = NULL;
  }
}

s32 GetTeamMemberEntityIndex(struct DungeonEntity *entity)
{
  struct DungeonEntity *uVar2;
  s32 index;

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    uVar2 = gDungeonGlobalData->teamPokemon[index];
    if (entity == uVar2)
      return index;
  }
  return -1;
}

void SetMessageArgument(char *buffer, struct DungeonEntity *entity, u32 param_3)
{
  switch(GetEntityType(entity))
  {
    case ENTITY_POKEMON:
        SetMessageArgument_2(buffer, entity->entityData, param_3);
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
