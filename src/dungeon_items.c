#include "global.h"
#include "dungeon_items.h"

#include "code_803E668.h"
#include "code_8041AD0.h"
#include "code_8045A00.h"
#include "code_80861A8.h"
#include "code_80869E4.h"
#include "dungeon_capabilities.h"
#include "dungeon_leader.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "structs/str_dungeon.h"

extern s32 gUnknown_810A3F0[];
extern u8 *gUnknown_80FA408[];
extern u8 *gUnknown_810531C[];
extern u8 *gUnknown_8105360[];
extern u8 *gUnknown_81053A8[];
extern u8 *gUnknown_8105434[];

extern void sub_80416E0(Position32 *r0, u32, bool8);
extern void sub_80855E4(void *);
extern void PlaySoundEffect(u32);
extern void sub_804178C(u32);
extern void sub_8040A84(void);

static void MusicBoxCreation(void);
static u8 sub_8046D70(void);

bool8 HasHeldItem(Entity *pokemon, u8 id)
{
    // Weird assignment to fix a regswap.
    EntityInfo *pokemonInfo = pokemonInfo = GetEntInfo(pokemon);
    if (!(pokemonInfo->heldItem.flags & ITEM_FLAG_EXISTS))
    {
        return FALSE;
    }
    if (pokemonInfo->heldItem.flags & ITEM_FLAG_STICKY)
    {
        return FALSE;
    }
    if (pokemonInfo->heldItem.id != id)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_8046CE4(Item *item,s32 param_2)
{
  s32 iVar1;
  s32 iVar2;

  iVar1 = DungeonRandInt(100);
  for(iVar2 = 0; iVar2 < 200; iVar2++)
  {
    if (gUnknown_810A3F0[iVar1] <= param_2) {
      item->quantity = iVar1;
      return;
    }
    iVar1 = iVar1 / 2;
  }
  item->quantity = 1;
}

void sub_8046D20(void)
{
  u8 cVar1;

  cVar1 = gDungeon->unk8;
  gDungeon->unk8 = sub_8046D70();
  if (((gDungeon->unk8 == 1) && (cVar1 == 0)) &&
     (DisplayDungeonYesNoMessage(0, *gUnknown_80FA408, 1) == 1)) {
    gDungeon->unk4 = 1;
    gDungeon->unk11 = 2;
  }
  else {
    MusicBoxCreation();
  }
}

u8 sub_8046D70(void)
{
    if(gDungeon->unk644.unk46)
        return 0;
    else
        return 0;
}

void MusicBoxCreation(void)
{
  bool8 musicBoxOnce;
  bool8 createMusicBox;
  Item *pbVar3; // r2
  s32 iVar4;
  Entity *entity;

  s32 indexes[3];

  createMusicBox = FALSE;
  do {
    musicBoxOnce = FALSE;
    indexes[0] = -1;
    indexes[1] = -1;
    indexes[2] = -1;

    for(iVar4 = 0, pbVar3 = &gTeamInventoryRef->teamItems[iVar4]; iVar4 < 20; pbVar3++, iVar4++)
    {
      if (pbVar3->flags & ITEM_FLAG_EXISTS) {
        if (pbVar3->id == ITEM_ROCK_PART) {
          indexes[0] = iVar4;
        }
        if (pbVar3->id == ITEM_ICE_PART) {
          indexes[1] = iVar4;
        }
        if (pbVar3->id == ITEM_STEEL_PART) {
          indexes[2] = iVar4;
        }
      }
    }

    if ((indexes[0] >= 0) && (indexes[1] >= 0) && (indexes[2] >= 0)) {

      musicBoxOnce = TRUE;
      createMusicBox = TRUE;

      // clear out each of the parts
      ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[0]]);
      ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[1]]);
      ZeroOutItem(&gTeamInventoryRef->teamItems[indexes[2]]);

      // init the music box
      xxx_init_itemslot_8090A8C(&gTeamInventoryRef->teamItems[indexes[0]], ITEM_MUSIC_BOX, 0);
    }
  } while (musicBoxOnce);

  FillInventoryGaps();

  if (createMusicBox) {
    entity = GetLeader();
    sub_80855E4(sub_80861A8);
    gDungeon->unk1356C = 1;
    DisplayDungeonMessage(0,*gUnknown_810531C,1);
    sub_803E708(0x3c,0x41);
    DisplayDungeonMessage(0,*gUnknown_8105360,1);
    sub_80869E4(entity,4,10,0);
    sub_80416E0(&entity->pixelPos,0x10c,FALSE);
    sub_80421C0(entity,0xd7);
    sub_803E708(0x3c,0x41);
    SetMessageArgument(gFormatBuffer_Monsters[0],entity,0);
    DisplayDungeonMessage(0,*gUnknown_81053A8,1);
    sub_803E708(10,0x41);
    PlaySoundEffect(0xd4);
    DisplayDungeonMessage(0,*gUnknown_8105434,1);
    sub_803E708(10,0x41);
    sub_804178C(1);
    gDungeon->unk1356C = 0;
    sub_8040A84();
  }
}

bool8 sub_8046F00(Item *item)
{
  bool8 canLearnMove;
  bool8 cannotMove;
  u16 moveID;
  Entity *entity;
  s32 index;

  if (GetItemCategory(item->id) == CATEGORY_TMS_HMS) {
    moveID = GetItemMoveID(item->id);
    if (!IsHMItem(item->id)) {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
          canLearnMove = CanMonLearnMove(moveID, GetEntInfo(entity)->id);
          cannotMove = CheckVariousStatuses2(entity, FALSE);
          if (cannotMove) {
            canLearnMove = FALSE;
          }
          if (canLearnMove) return TRUE;
        }
      }
    }
    return FALSE;
  }
  else
    return TRUE;
}

void sub_8046F84(s32 itemFlag)
{
  Item *item;
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if ((item->flags & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
      item->id = 0;
      item->quantity = 0;
      item->flags = 0;
    }
  }
  FillInventoryGaps();

  for(index = 0; index < 4; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityExists(entity)) {
      entityInfo = GetEntInfo(entity);
      item = &entityInfo->heldItem;
      if ((item->flags & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
        item->id = 0;
        item->quantity = 0;
        item->flags = 0;
      }
    }
  }
}

void sub_804700C(void)
{
  Item *item;
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if ((item->flags & ITEM_FLAG_EXISTS)) {
      xxx_init_itemslot_8090A8C(item, ITEM_PLAIN_SEED, 0);
    }
  }
  FillInventoryGaps();

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeon->teamPokemon[index];
    if (EntityExists(entity)) {
      entityInfo = GetEntInfo(entity);
      item = &entityInfo->heldItem;
      if ((item->flags & ITEM_FLAG_EXISTS)) {
        xxx_init_itemslot_8090A8C(item, ITEM_PLAIN_SEED, 0);
      }
    }
  }
}

bool8 sub_8047084(s32 itemFlag)
{
    s32 i;

    for (i = 0; i < INVENTORY_SIZE; i++)
    {
        if ((ItemExists(&gTeamInventoryRef->teamItems[i])) && (gTeamInventoryRef->teamItems[i].flags & itemFlag)) {
            return TRUE;
        }
    }
    FillInventoryGaps();

    for (i = 0; i < MAX_TEAM_MEMBERS; i++)
    {
        Entity *entity = gDungeon->teamPokemon[i];
        if (EntityExists(entity)) {
            EntityInfo *entityInfo = GetEntInfo(entity);
            Item *item = &entityInfo->heldItem;
            if ((ItemExists(item) & ITEM_FLAG_EXISTS) && (item->flags & itemFlag)) {
                return TRUE;
            }
        }
    }
    return FALSE;
}

void sub_8047104(void)
{
  Item *item;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if (item->flags & ITEM_FLAG_EXISTS)
    {
        if(item->id == ITEM_POKE)
        {
            AddToTeamMoney(GetMoneyValue(item));
            item->id = 0;
            item->quantity = 0;
            item->flags = 0;
        }
        if(item->flags & ITEM_FLAG_IN_SHOP)
        {
            item->id = 0;
            item->quantity = 0;
            item->flags = 0;
        }
    }
  }
  FillInventoryGaps();
}
