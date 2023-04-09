#include "global.h"
#include "constants/item.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"
#include "dungeon_random.h"
#include "item.h"

extern u8 *gUnknown_80FE6F4[];
extern struct unkStruct_8090F58 gUnknown_80F699C;
extern struct unkStruct_8090F58 gUnknown_80F69A8;
extern struct unkStruct_8090F58 gUnknown_80F6990;

extern struct EntityInfo* GetTrapData_1(struct Entity *entity);
extern void SetMessageArgument_2(u8 *, struct EntityInfo *, u32);
extern void GetTrapName(u8 *, u8);
extern bool8 IsNotSpecialItem(u8 id);
void sub_8045BF8(u8 *, struct Item *);
void sub_8046CE4(void *param_1,u32 param_2);

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

void sub_8045C28(struct Item *Item, u8 itemID, u32 param_3)
{
  bool8 stickyFlag;
  u32 total;
  
  xxx_init_itemslot_8090A8C(Item,itemID,0);
  stickyFlag = FALSE;
  if (IsNotSpecialItem(itemID)) {
    if (param_3 == 0) {
        if (DungeonRandInt(100) >= gDungeon->unk1C57E)
        {
            goto _short;
        }
        else
        {
            goto _store;
        }
    }
    else if (param_3 == 1) {
        stickyFlag = TRUE;
    }
  }
_short:
  if (stickyFlag)
_store:
    Item->flags = Item->flags | ITEM_FLAG_STICKY;
  if (GetItemCategory(itemID) == CATEGORY_POKE) {
    // FIXME: total hack but too lazy to figure out array for now
    total = (gDungeon->unk1C58B << 2) + gDungeon->unk1C58B;
    total <<= 3;
    sub_8046CE4(Item, total);
  }
}
