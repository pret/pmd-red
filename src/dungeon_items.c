#include "global.h"
#include "dungeon_items.h"

#include "dungeon_capabilities.h"
#include "dungeon_global_data.h"
#include "dungeon_leader.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "team_inventory.h"
#include "pokemon.h"

extern u8 gAvailablePokemonNames[];
extern s32 gUnknown_810A3F0[];
extern u8 *gUnknown_80FA408[];
extern u8 *gUnknown_810531C[];
extern u8 *gUnknown_8105360[];
extern u8 *gUnknown_81053A8[];
extern u8 *gUnknown_8105434[];

extern u8 sub_8046D70(void);
extern s32 sub_8052B8C(u32, u8 *, u32);
extern void sub_80861A8(void);
extern void PrintFieldMessage(u32, u8 *, u32);
extern void sub_803E708(u32, u32);
extern void sub_80869E4(struct DungeonEntity *, u32, u32, u32);
extern void sub_80416E0(struct Position32 *r0, u32, u32);
extern void SetMessageArgument(u8 *r0, struct DungeonEntity *r1, u32);
extern void sub_80421C0(struct DungeonEntity *, u32);
extern void sub_80855E4(void *);
extern void PlaySoundEffect(u32);
extern void sub_804178C(u32);
extern void sub_8040A84(void);

void MusicBoxCreation(void);

bool8 HasItem(struct DungeonEntity *pokemon, u8 itemIndex)
{
    // Weird assignment to fix a regswap.
    struct DungeonEntityData *pokemonData = pokemonData = pokemon->entityData;
    if (!(pokemonData->heldItem.itemFlags & ITEM_FLAG_EXISTS))
    {
        return FALSE;
    }
    if (pokemonData->heldItem.itemFlags & ITEM_FLAG_STICKY)
    {
        return FALSE;
    }
    if (pokemonData->heldItem.itemIndex != itemIndex)
    {
        return FALSE;
    }
    return TRUE;
}

void sub_8046CE4(u8 *param_1,s32 param_2)
{
  s32 iVar1;
  s32 iVar2;

  iVar1 = DungeonRandomCapped(100);
  for(iVar2 = 0; iVar2 < 200; iVar2++)
  {
    if (gUnknown_810A3F0[iVar1] <= param_2) {
      param_1[1] = iVar1;
      return;
    }
    iVar1 = iVar1 / 2;
  }
  param_1[1] = 1;
}

void sub_8046D20(void)
{
  u8 cVar1;

  cVar1 = gDungeonGlobalData->unk8;
  gDungeonGlobalData->unk8 = sub_8046D70();
  if (((gDungeonGlobalData->unk8 == 1) && (cVar1 == 0)) &&
     (sub_8052B8C(0, *gUnknown_80FA408, 1) == 1)) {
    gDungeonGlobalData->unk4 = 1;
    gDungeonGlobalData->unk11 = 2;
  }
  else {
    MusicBoxCreation();
  }
}

u8 sub_8046D70(void)
{
    if(gDungeonGlobalData->unk68A)
        return 0;
    else
        return 0;
}

#ifdef NONMATCHING
void MusicBoxCreation(void)
{
  bool8 musicBoxOnce;
  bool8 createMusicBox;
  struct ItemSlot *pbVar3; // r2
  s32 iVar4;
  struct DungeonEntity *entity;

  s32 indexes[3];

  createMusicBox = FALSE;
  do {
    musicBoxOnce = FALSE;
    indexes[0] = -1;
    indexes[1] = -1;
    indexes[2] = -1;

    for(iVar4 = 0, pbVar3 = &gTeamInventory_203B460->teamItems[iVar4]; iVar4 < 20; pbVar3++, iVar4++)
    {
      if (pbVar3->itemFlags & ITEM_FLAG_EXISTS) {
        if (pbVar3->itemIndex == ITEM_ID_ROCK_PART) {
          indexes[0] = iVar4;
        }
        if (pbVar3->itemIndex == ITEM_ID_ICE_PART) {
          indexes[1] = iVar4;
        }
        if (pbVar3->itemIndex == ITEM_ID_STEEL_PART) {
          indexes[2] = iVar4;
        }
      }
    }

    if ((indexes[0] >= 0) && (indexes[1] >= 0) && (indexes[2] >= 0)) {

      // NOTE: doesn't match here.. tried to register pin but still not perfect
      register struct ItemSlot *pbVar4 asm("r1");
      register struct ItemSlot *pbVar5 asm("r0");

      musicBoxOnce = TRUE;
      createMusicBox = TRUE;

      // clear out each of the parts
      pbVar4 = &gTeamInventory_203B460->teamItems[indexes[0]];
      pbVar4->itemIndex = 0;
      pbVar4->numItems = 0;
      pbVar4->itemFlags = 0;

      pbVar5 = &gTeamInventory_203B460->teamItems[indexes[1]];
      pbVar5->itemIndex = 0;
      pbVar5->numItems = 0;
      pbVar5->itemFlags = 0;

      pbVar5 = &gTeamInventory_203B460->teamItems[indexes[2]];
      pbVar5->itemIndex = 0;
      pbVar5->numItems = 0;
      pbVar5->itemFlags = 0;

      // init the music box
      xxx_init_itemslot_8090A8C(&gTeamInventory_203B460->teamItems[indexes[0]], ITEM_ID_MUSIC_BOX, 0);
    }
  } while (musicBoxOnce);

  FillInventoryGaps();

  if (createMusicBox) {
    entity = GetLeaderEntity();
    sub_80855E4(sub_80861A8);
    gDungeonGlobalData->unk1356C = 1;
    PrintFieldMessage(0,*gUnknown_810531C,1);
    sub_803E708(0x3c,0x41);
    PrintFieldMessage(0,*gUnknown_8105360,1);
    sub_80869E4(entity,4,10,0);
    sub_80416E0(&entity->posPixel,0x10c,0);
    sub_80421C0(entity,0xd7);
    sub_803E708(0x3c,0x41);
    SetMessageArgument(gAvailablePokemonNames,entity,0);
    PrintFieldMessage(0,*gUnknown_81053A8,1);
    sub_803E708(10,0x41);
    PlaySoundEffect(0xd4);
    PrintFieldMessage(0,*gUnknown_8105434,1);
    sub_803E708(10,0x41);
    sub_804178C(1);
    gDungeonGlobalData->unk1356C = 0;
    sub_8040A84();
  }
}
#else
NAKED
void MusicBoxCreation(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tsub sp, 0xC\n"
	"\tmovs r6, 0\n"
	"\tldr r5, _08046EDC\n"
	"\tmovs r4, 0\n"
"_08046D96:\n"
	"\tmovs r7, 0\n"
	"\tmovs r0, 0x1\n"
	"\tnegs r0, r0\n"
	"\tstr r0, [sp]\n"
	"\tstr r0, [sp, 0x4]\n"
	"\tstr r0, [sp, 0x8]\n"
	"\tmovs r3, 0\n"
	"\tldr r2, [r5]\n"
"_08046DA6:\n"
	"\tldrb r1, [r2]\n"
	"\tmovs r0, 0x1\n"
	"\tands r0, r1\n"
	"\tcmp r0, 0\n"
	"\tbeq _08046DC8\n"
	"\tldrb r0, [r2, 0x2]\n"
	"\tcmp r0, 0x79\n"
	"\tbne _08046DB8\n"
	"\tstr r3, [sp]\n"
"_08046DB8:\n"
	"\tldrb r0, [r2, 0x2]\n"
	"\tcmp r0, 0x77\n"
	"\tbne _08046DC0\n"
	"\tstr r3, [sp, 0x4]\n"
"_08046DC0:\n"
	"\tldrb r0, [r2, 0x2]\n"
	"\tcmp r0, 0x78\n"
	"\tbne _08046DC8\n"
	"\tstr r3, [sp, 0x8]\n"
"_08046DC8:\n"
	"\tadds r2, 0x4\n"
	"\tadds r3, 0x1\n"
	"\tcmp r3, 0x13\n"
	"\tble _08046DA6\n"
	"\tldr r1, [sp]\n"
	"\tcmp r1, 0\n"
	"\tblt _08046E1E\n"
	"\tldr r0, [sp, 0x4]\n"
	"\tcmp r0, 0\n"
	"\tblt _08046E1E\n"
	"\tldr r0, [sp, 0x8]\n"
	"\tcmp r0, 0\n"
	"\tblt _08046E1E\n"
	"\tmovs r7, 0x1\n"
	"\tmovs r6, 0x1\n"
	"\tlsls r1, 2\n"
	"\tldr r0, [r5]\n"
	"\tadds r1, r0\n"
	"\tstrb r4, [r1, 0x2]\n"
	"\tstrb r4, [r1, 0x1]\n"
	"\tstrb r4, [r1]\n"
	"\tldr r0, [sp, 0x4]\n"
	"\tlsls r0, 2\n"
	"\tldr r1, [r5]\n"
	"\tadds r0, r1\n"
	"\tstrb r4, [r0, 0x2]\n"
	"\tstrb r4, [r0, 0x1]\n"
	"\tstrb r4, [r0]\n"
	"\tldr r0, [sp, 0x8]\n"
	"\tlsls r0, 2\n"
	"\tldr r1, [r5]\n"
	"\tadds r0, r1\n"
	"\tstrb r4, [r0, 0x2]\n"
	"\tstrb r4, [r0, 0x1]\n"
	"\tstrb r4, [r0]\n"
	"\tldr r1, [sp]\n"
	"\tlsls r1, 2\n"
	"\tldr r0, [r5]\n"
	"\tadds r0, r1\n"
	"\tmovs r1, 0x7A\n"
	"\tmovs r2, 0\n"
	"\tbl xxx_init_itemslot_8090A8C\n"
"_08046E1E:\n"
	"\tcmp r7, 0\n"
	"\tbne _08046D96\n"
	"\tbl FillInventoryGaps\n"
	"\tcmp r6, 0\n"
	"\tbeq _08046ED4\n"
	"\tbl GetLeaderEntity\n"
	"\tadds r4, r0, 0\n"
	"\tldr r0, _08046EE0\n"
	"\tbl sub_80855E4\n"
	"\tldr r6, _08046EE4\n"
	"\tldr r0, [r6]\n"
	"\tldr r5, _08046EE8\n"
	"\tadds r0, r5\n"
	"\tmovs r1, 0x1\n"
	"\tstrb r1, [r0]\n"
	"\tldr r0, _08046EEC\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl PrintFieldMessage\n"
	"\tmovs r0, 0x3C\n"
	"\tmovs r1, 0x41\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _08046EF0\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl PrintFieldMessage\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0x4\n"
	"\tmovs r2, 0xA\n"
	"\tmovs r3, 0\n"
	"\tbl sub_80869E4\n"
	"\tadds r0, r4, 0\n"
	"\tadds r0, 0xC\n"
	"\tmovs r1, 0x86\n"
	"\tlsls r1, 1\n"
	"\tmovs r2, 0\n"
	"\tbl sub_80416E0\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0xD7\n"
	"\tbl sub_80421C0\n"
	"\tmovs r0, 0x3C\n"
	"\tmovs r1, 0x41\n"
	"\tbl sub_803E708\n"
	"\tldr r0, _08046EF4\n"
	"\tadds r1, r4, 0\n"
	"\tmovs r2, 0\n"
	"\tbl SetMessageArgument\n"
	"\tldr r0, _08046EF8\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl PrintFieldMessage\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x41\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0xD4\n"
	"\tbl PlaySoundEffect\n"
	"\tldr r0, _08046EFC\n"
	"\tldr r1, [r0]\n"
	"\tmovs r0, 0\n"
	"\tmovs r2, 0x1\n"
	"\tbl PrintFieldMessage\n"
	"\tmovs r0, 0xA\n"
	"\tmovs r1, 0x41\n"
	"\tbl sub_803E708\n"
	"\tmovs r0, 0x1\n"
	"\tbl sub_804178C\n"
	"\tldr r0, [r6]\n"
	"\tadds r0, r5\n"
	"\tstrb r7, [r0]\n"
	"\tbl sub_8040A84\n"
"_08046ED4:\n"
	"\tadd sp, 0xC\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_08046EDC: .4byte gTeamInventory_203B460\n"
"_08046EE0: .4byte sub_80861A8\n"
"_08046EE4: .4byte gDungeonGlobalData\n"
"_08046EE8: .4byte 0x0001356c\n"
"_08046EEC: .4byte gUnknown_810531C\n"
"_08046EF0: .4byte gUnknown_8105360\n"
"_08046EF4: .4byte gAvailablePokemonNames\n"
"_08046EF8: .4byte gUnknown_81053A8\n"
"_08046EFC: .4byte gUnknown_8105434"
    );
}
#endif

bool8 sub_8046F00(struct ItemSlot *item)
{
  bool8 canLearnMove;
  bool8 cannotMove;
  u16 moveID;
  struct DungeonEntity *entity;
  s32 index;

  if (GetItemType(item->itemIndex) == ITEM_TYPE_TM) {
    moveID = GetItemMove(item->itemIndex);
    if (!IsHMItem(item->itemIndex)) {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeonGlobalData->teamPokemon[index];
        if (EntityExists(entity)) {
          canLearnMove = CanMonLearnMove(moveID, entity->entityData->entityID);
          cannotMove = CannotMove(entity, FALSE);
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
  struct ItemSlot *item;
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventory_203B460->teamItems[index];
    if ((item->itemFlags & ITEM_FLAG_EXISTS) && (item->itemFlags & itemFlag)) {
      item->itemIndex = 0;
      item->numItems = 0;
      item->itemFlags = 0;
    }
  }
  FillInventoryGaps();

  for(index = 0; index < 4; index++)
  {
    entity = gDungeonGlobalData->teamPokemon[index];
    if (EntityExists(entity)) {
      entityData = entity->entityData;
      item = &entityData->heldItem;
      if ((item->itemFlags & ITEM_FLAG_EXISTS) && (item->itemFlags & itemFlag)) {
        item->itemIndex = 0;
        item->numItems = 0;
        item->itemFlags = 0;
      }
    }
  }
}

void sub_804700C(void)
{
  struct ItemSlot *item;
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventory_203B460->teamItems[index];
    if ((item->itemFlags & ITEM_FLAG_EXISTS)) {
      xxx_init_itemslot_8090A8C(item, ITEM_ID_PLAIN_SEED, 0);
    }
  }
  FillInventoryGaps();

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeonGlobalData->teamPokemon[index];
    if (EntityExists(entity)) {
      entityData = entity->entityData;
      item = &entityData->heldItem;
      if ((item->itemFlags & ITEM_FLAG_EXISTS)) {
        xxx_init_itemslot_8090A8C(item, ITEM_ID_PLAIN_SEED, 0);
      }
    }
  }
}

bool8 sub_8047084(s32 itemFlag)
{
  struct ItemSlot *item;
  struct DungeonEntity *entity;
  struct DungeonEntityData *entityData;
  s32 index;

  // NEED THIS ORDERING TO MATCH
  index = 0;
  item = &gTeamInventory_203B460->teamItems[index];

  for(index = 0; index < INVENTORY_SIZE; item++, index++)
  {
    if ((item->itemFlags & ITEM_FLAG_EXISTS) && (item->itemFlags & itemFlag)) {
      return TRUE;
    }
  }
  FillInventoryGaps();

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    entity = gDungeonGlobalData->teamPokemon[index];
    if (EntityExists(entity)) {
      entityData = entity->entityData;
      item = &entityData->heldItem;
      if ((item->itemFlags & ITEM_FLAG_EXISTS) && (item->itemFlags & itemFlag)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

void sub_8047104(void)
{
  struct ItemSlot *item;
  s32 index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventory_203B460->teamItems[index];
    if (item->itemFlags & ITEM_FLAG_EXISTS)
    {
        if(item->itemIndex == ITEM_ID_POKE)
        {
            AddToTeamMoney(GetMoneyValue(item));
            item->itemIndex = 0;
            item->numItems = 0;
            item->itemFlags = 0;
        }
        if(item->itemFlags & ITEM_FLAG_FOR_SALE)
        {
            item->itemIndex = 0;
            item->numItems = 0;
            item->itemFlags = 0;
        }
    }
  }
  FillInventoryGaps();
}
