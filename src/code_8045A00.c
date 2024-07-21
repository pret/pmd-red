#include "global.h"
#include "code_8045A00.h"
#include "constants/item.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "items.h"
#include "status_checks_1.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "trap.h"

extern u8 *gUnknown_80FE6F4[];
extern struct unkStruct_8090F58 gUnknown_80F699C;
extern struct unkStruct_8090F58 gUnknown_80F69A8;
extern struct unkStruct_8090F58 gUnknown_80F6990;

void sub_8045BF8(u8 *, Item *);
extern u32 sub_803D73C(u32);
void sub_80460F8(Position *, Item *, u32);

void sub_8045ACC(void)
{
  Entity *entity;
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

void SetMessageArgument(char buffer[], Entity *entity, u32 param_3)
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
        GetTrapName(buffer, GetTrapData_1(entity)->id);
        break;
    default:
        strcpy(buffer, *gUnknown_80FE6F4);
        break;
  }
}

void sub_8045BF8(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F699C);
}

void sub_8045C08(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F69A8);
}

void sub_8045C18(u8 *buffer, Item *item)
{
    sub_8090E14(buffer, item, &gUnknown_80F6990);
}

void sub_8045C28(Item *Item, u8 itemID, u32 param_3)
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

void sub_8045CB0(void)
{
  bool8 shopFlag;
  u8 itemID;
  u32 x;
  int y;
  int yCounter;
  struct Tile *tile;
  u32 uVar5;
  int xCounter;
  Item item;
  Position pos;
  u32 flag;

  x = DungeonRandInt(DUNGEON_MAX_SIZE_X);
  y = DungeonRandInt(DUNGEON_MAX_SIZE_Y);
  gDungeon->unk3904 = 0;
  for(yCounter = 0; yCounter < DUNGEON_MAX_SIZE_Y; yCounter++)
  {
    y++;
    if (y == DUNGEON_MAX_SIZE_Y) {
      y = 0;
    }

    for(xCounter = 0; xCounter < DUNGEON_MAX_SIZE_X; xCounter++)
    {
      x++;
      flag = ITEM_FLAG_IN_SHOP;
      if (x == DUNGEON_MAX_SIZE_X) {
        x = 0;
      }
      tile = GetTile(x,y);

      if (((tile->terrainType & TERRAIN_TYPE_STAIRS) == 0) && ((tile->unk4 & 2) != 0)) {
        shopFlag = FALSE;
        pos.x = x;
        pos.y = y;

        if (tile->terrainType & TERRAIN_TYPE_SHOP) {
          shopFlag = TRUE;
          uVar5 = 1;
        }
        else
        {
          if ((tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)) == 0) {
            uVar5 = 3;
          }
          else {
            uVar5 = -(tile->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE) >> 0x1f & 2;
          }
        }
        itemID = sub_803D73C(uVar5);
        if (!CanSellItem(itemID)) {
          shopFlag = 0;
        }
        sub_8045C28(&item,itemID,0);
        if (shopFlag) {
          item.flags |= flag;
        }
        sub_80460F8(&pos,&item,1);
      }
    }
  }
}
