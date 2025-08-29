#include "global.h"
#include "globaldata.h"
#include "constants/dungeon.h"
#include "constants/item.h"
#include "constants/move_id.h"
#include "dungeon_vram.h"
#include "dungeon_tilemap.h"
#include "code_8041AD0.h"
#include "dungeon_action.h"
#include "code_8066D04.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_jobs.h"
#include "run_dungeon.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_message.h"
#include "dungeon_misc.h"
#include "dungeon_move.h"
#include "dungeon_move_util.h"
#include "dungeon_logic.h"
#include "dungeon_music.h"
#include "dungeon_random.h"
#include "dungeon_strings.h"
#include "dungeon_util.h"
#include "friend_area.h"
#include "input.h"
#include "items.h"
#include "menu_input.h"
#include "moves.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "position_util.h"
#include "sprite.h"
#include "string_format.h"
#include "text_1.h"
#include "trap.h"
#include "dungeon_pos_data.h"
#include "dungeon_projectile_throw.h"
#include "dungeon_engine.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_item_action.h"
#include "dungeon_leveling.h"
#include "warp_target.h"

extern void sub_8057588(Entity * pokemon, u8 param_2);
void sub_8042208(Entity *pokemon, u8 r1);
extern void sub_807AB38(Entity *, u32);
Entity *sub_806773C(Entity *entity);
void sub_8067558(Entity *entity, Entity *targetEntity, s32 a2);
void sub_8067794(Entity *entity, Entity *targetEntity, s32 a2);

void HandlePickUpPlayerAction(Entity *entity)
{
  GetEntInfo(entity)->action.actionParameters[0].actionUseIndex = 1;
  TryLeaderItemPickUp(&entity->pos,0);
}

void HandleSetItemAction(Entity *param_1, bool8 param_2)
{
  Item *item;
  Item *itemPtr;
  s32 index;

  item = sub_8044D90(param_1,0,0xfe);
  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    itemPtr = &gTeamInventoryRef->teamItems[index];
    if (((itemPtr->flags & ITEM_FLAG_EXISTS)) && ((itemPtr->flags & ITEM_FLAG_SET))) {
      if ((itemPtr->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],itemPtr);
        LogMessageByIdWithPopupCheckUser(param_1,gItemStickyCannotEquip);
        return;
      }
      itemPtr->flags &= ~(ITEM_FLAG_SET);
    }
  }
  sub_8045BF8(gFormatBuffer_Items[0],item);
  PlaySoundEffect(0x133);
  if (param_2 != 0) {
    if ((item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8D04);
    }
    else {
      if (GetItemCategory(item->id) == CATEGORY_THROWN_LINE) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8CE4);
      }
      else
      {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8CE8);
      }
    }
  }
  item->flags |= ITEM_FLAG_SET;
  if (((item->flags & ITEM_FLAG_STICKY)) && (param_2 != 0)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
  }
}

void HandleUnsetItemAction(Entity *entity,bool8 enableMessage)
{
  Item *item;
  int index;

  for(index = 0; index < INVENTORY_SIZE; index++)
  {
    item = &gTeamInventoryRef->teamItems[index];
    if (((item->flags & ITEM_FLAG_EXISTS)) && ((item->flags & ITEM_FLAG_SET))) {
      if ((item->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],item);
        LogMessageByIdWithPopupCheckUser(entity,gItemStickyCannotEquip);
        return;
      }
      item->flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],item);
      PlaySoundEffect(0x133);
      if (enableMessage) {
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8D20);
      }
    }
  }
}

void HandleGiveItemAction(Entity *param_1)
{
  Entity *entity;
  Item *item;
  EntityInfo *info1;
  EntityInfo *info2;
  bool8 bVar3;
  Item item1;
  Item item2;
  Item item3;

  entity = sub_8044DA4(param_1,1);
  info1 = GetEntInfo(param_1);
  info2 = GetEntInfo(entity);
  item = sub_8044D90(param_1,0,2);

  if((info1->action).actionParameters[0].actionUseIndex == 0x80)
      bVar3 = TRUE;
  else
      bVar3 = FALSE;

  if ((!bVar3) && ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET))) {
    sub_8045BF8(gFormatBuffer_Items[1],item);
    LogMessageByIdWithPopupCheckUser(param_1,gItemStickyCannotMove2);
  }
  else
  {
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    if (((info2->heldItem).flags & ITEM_FLAG_EXISTS)) {
     if (((info2->heldItem).flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[1],&info2->heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,gItemStickyCannotMove1);
        return;
      }
      item1 = (info2->heldItem);
      item2 = *item;
      item1.flags &= ~(ITEM_FLAG_SET);
      item2.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1,0,100);
      if (bVar3) {
        SpawnItem(&param_1->pos,&item1,1);
      }
      else {
        AddItemToInventory(&item1);
      }
      info2->heldItem = item2;
      sub_8045BF8(gFormatBuffer_Items[0],&item2);
      sub_8045BF8(gFormatBuffer_Items[1],&item1);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,gMonTookAndReturnedItem);
      if ((item2.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
      }
    }
    else {
      item3 = *item;
      item3.flags &= ~(ITEM_FLAG_SET);
      sub_8044DF0(param_1, 0, 101);
      info2->heldItem = item3;
      sub_8045BF8(gFormatBuffer_Items[0],&item3);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8D44);
      if ((item3.flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
      }
    }
    sub_806A6E8(entity);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info2->isTeamLeader) {
      info2->flags = info2->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}

void HandleTakeItemAction(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *heldItem;
  Item item;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  if (ItemExists(&gTeamInventoryRef->teamItems[ITEM_POWER_BAND])) {
    LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8D60);
  }
  else
  {
    if (ItemSticky(heldItem)) {
        sub_8045BF8(gFormatBuffer_Items[0],heldItem);
        LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
    }
    else
    {
      item = *heldItem;
      item.flags &= ~(ITEM_FLAG_SET);
      sub_8045BF8(gFormatBuffer_Items[0],&item);
      SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
      ZeroOutItem(heldItem);
      AddItemToInventory(&item);
      PlaySoundEffect(0x14d);
      LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8D7C);
      sub_806A6E8(entity);
      if (sub_80706A4(entity,&entity->pos) != 0) {
        WarpTarget(param_1,entity,0,0);
      }
      if (!info->isTeamLeader) {
        info->flags |= MOVEMENT_FLAG_UNK_14;
      }
      sub_807AB38(param_1,gDungeon->forceMonsterHouse);
    }
  }
}

void sub_8066BD4(Entity *param_1)
{
  Entity *entity;
  EntityInfo *info;
  Item *item;
  Item *heldItem;
  Item temp;

  entity = sub_8044DA4(param_1,0);
  info = GetEntInfo(entity);
  heldItem = &info->heldItem;
  item = sub_8044D90(param_1,1,0x1565);
  if (heldItem->flags & ITEM_FLAG_STICKY)
  {
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
  }
  else if ((item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
    sub_8045BF8(gFormatBuffer_Items[0],item);
    LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8BE0);
  }
  else
  {
    heldItem->flags &= ~(ITEM_FLAG_SET);
    item->flags &= ~(ITEM_FLAG_SET);
    sub_8045BF8(gFormatBuffer_Items[0],heldItem);
    sub_8045BF8(gFormatBuffer_Items[1],item);
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[1],entity,0);
    temp = info->heldItem;
    info->heldItem = *item;
    *item = temp;
    PlaySoundEffect(0x14d);
    LogMessageByIdWithPopupCheckUser(param_1,gUnknown_80F8DB4);
    if (sub_80706A4(entity,&entity->pos) != 0) {
      WarpTarget(param_1,entity,0,0);
    }
    if (!info->isTeamLeader) {
      info->flags = info->flags | MOVEMENT_FLAG_UNK_14;
    }
    sub_807AB38(param_1,gDungeon->forceMonsterHouse);
  }
}

void HandleUseItemAction(Entity *param_1)
{
  Entity *entity;

  entity = sub_8044DA4(param_1,0);
  GetEntInfo(entity)->useHeldItem = TRUE;
}

void HandlePlaceItemAction(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity,0,4);

    sub_8045BF8(gFormatBuffer_Items[0],item);
    if (info->action.actionParameters[0].actionUseIndex == 0x80) {
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8DE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex < 0x15 && (item->flags & (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) == (ITEM_FLAG_STICKY | ITEM_FLAG_SET)) {
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8BE0);
    }
    else if (info->action.actionParameters[0].actionUseIndex == 0x81 && (item->flags & ITEM_FLAG_STICKY)) {
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8BE0);
    }
    else {
        const Tile *tile = GetTile(entity->pos.x, entity->pos.y);
        if ((tile->terrainFlags & TERRAIN_TYPE_STAIRS)) {
            LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E04);
        }
        else if (GetTerrainType(tile) != TERRAIN_TYPE_NORMAL) {
            LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E04);
        }
        else if (tile->object != NULL) {
            LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E04);
        }
        else {
            item->flags &= ~(ITEM_FLAG_SET);
            sub_8045BF8(gFormatBuffer_Items[0],item);
            if (SpawnItem(&entity->pos,item,1) == 0) {
                LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E04);
            }
            else {
                ZeroOutItem(item);
                FillInventoryGaps();
                PlaySoundEffect(0x14d);
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0],entity,0);
                LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E28);
                sub_807AB38(entity,gDungeon->forceMonsterHouse);
            }
        }
    }
}

void sub_8066E14(Entity *entity)
{
    Item *item[2];
    EntityInfo *info = GetEntInfo(entity);
    item[0] = sub_8044D90(entity,0,5);
    item[1] = sub_8044D90(entity,1,6);

    if (info->action.actionParameters[0].actionUseIndex != 0x80) {
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8E2C);
    }
    else if (info->action.actionParameters[1].actionUseIndex < 0x15 && (item[1]->flags & ITEM_FLAG_SET) && (item[1]->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[0],item[1]);
        LogMessageByIdWithPopupCheckUser(entity,gUnknown_80F8BE0);
    }
    else if (info->action.actionParameters[1].actionUseIndex == 0x81 && ItemSticky(item[1])) {
        sub_8045BF8(gFormatBuffer_Items[1],item[1]);
        LogMessageByIdWithPopupCheckUser(entity,gItemStickyCannotMove3);
    }
    else {
        const Tile *tile = GetTile((entity->pos).x,(entity->pos).y);
        if (tile->object != NULL && GetEntityType(tile->object) != ENTITY_ITEM) {
            LogMessageByIdWithPopupCheckUser(entity,gNoExchangesHere);
        }
        else {
            Item newItems[2];

            newItems[0] = *item[0];
            newItems[1] = *item[1];
            newItems[0].flags &= ~(ITEM_FLAG_SET);
            newItems[1].flags &= ~(ITEM_FLAG_SET);

            RemoveGroundItem(&info->action.actionParameters[0].itemPos,1);
            ZeroOutItem(item[1]);
            if (!SpawnItem(&info->action.actionParameters[0].itemPos,&newItems[1],1)) {
                LogMessageByIdWithPopupCheckUser(entity,gNothingCanBePutDownHere);
            }
            else {
                if (info->action.actionParameters[1].actionUseIndex == 0x81) {
                    info->heldItem = newItems[0];
                }
                else {
                    AddItemToInventory(&newItems[0]);
                }

                FillInventoryGaps();
                sub_8045BF8(gFormatBuffer_Items[0],&newItems[1]);
                sub_8045BF8(gFormatBuffer_Items[1],&newItems[0]);
                PlaySoundEffect(0x14d);
                LogMessageByIdWithPopupCheckUser(entity,gSwappedGroundItem);
                sub_807AB38(entity,gDungeon->forceMonsterHouse);
            }
        }
    }
}

void sub_8066FA4(Entity *entity)
{
    Item *item[2];
    EntityInfo *info = GetEntInfo(entity);
    const Tile *tile = GetTile((entity->pos).x,(entity->pos).y);

    item[0] = sub_8044D90(entity,0,7);
    sub_8045BF8(gFormatBuffer_Items[0],item[0]);
    if (info->action.actionParameters[0].actionUseIndex < 0x15 && (item[0]->flags & ITEM_FLAG_SET) && (item[0]->flags & ITEM_FLAG_STICKY)) {
        sub_8045BF8(gFormatBuffer_Items[1],item[0]);
        LogMessageByIdWithPopupCheckUser(entity,gItemStickyCannotMove3);
    }
    else if (info->action.actionParameters[0].actionUseIndex == 0x81 && ItemSticky(item[0])) {
        LogMessageByIdWithPopupCheckUser(entity,gItemStickyCannotMove2);
    }
    else if (tile->object != NULL && GetEntityType(tile->object) != ENTITY_ITEM) {
        LogMessageByIdWithPopupCheckUser(entity,gNoExchangesHere);
    }
    else {
        Item newItems[2];

        item[1] = GetItemInfo(tile->object);
        sub_8045BF8(gFormatBuffer_Items[1],item[1]);
        newItems[0] = *item[0];
        newItems[1] = *item[1];
        newItems[0].flags &= ~(ITEM_FLAG_SET);
        newItems[1].flags &= ~(ITEM_FLAG_SET);

        RemoveGroundItem(&entity->pos,1);
        ZeroOutItem(item[0]);
        if (!SpawnItem(&entity->pos, &newItems[0],1)) {
            LogMessageByIdWithPopupCheckUser(entity,gNothingCanBePutDownHere);
        }
        else {
            if (info->action.actionParameters[0].actionUseIndex  == 0x81) {
                info->heldItem = newItems[1];
            }
            else {
                AddItemToInventory(&newItems[1]);
            }
            FillInventoryGaps();
            PlaySoundEffect(0x14d);
            LogMessageByIdWithPopupCheckUser(entity,gSwappedGroundItem);
            sub_807AB38(entity,gDungeon->forceMonsterHouse);
        }
    }
}

void sub_8067110(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity,0,8);

    sub_8045BF8(gFormatBuffer_Items[0],item);
    SetMessageArgument_2(gFormatBuffer_Monsters[0],info,0);
    if (sub_8048D50(entity,item)) {
        Item item2;

        LogMessageByIdWithPopupCheckUser(entity,sub_80464AC(item));
        item2 = *item;
        sub_8044DF0(entity,0,0x66);
        sub_803E708(0x1e,0x11);
        sub_80479B8(0,0,0,entity,entity,&item2);
        sub_807AB38(entity,gDungeon->forceMonsterHouse);
    }
}

void sub_80671A0(Entity *entity)
{
    EntityInfo *info = GetEntInfo(entity);
    Item *item = sub_8044D90(entity, 0, 9);

    if (info->action.actionParameters[0].actionUseIndex == 0x81 && ItemSticky(item)) {
        sub_8045BF8(gFormatBuffer_Items[0], item);
        LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8BE0);
        sub_803E708(0x14, 0x4C);
    }
    else if ((GetItemCategory(item->id) == CATEGORY_THROWN_LINE || GetItemCategory(item->id) == CATEGORY_THROWN_ARC) && ItemSticky(item)) {
        sub_8045BF8(gFormatBuffer_Items[0], item);
        LogMessageByIdWithPopupCheckUser(entity, gUnknown_80F8BE0);
        sub_803E708(0x14, 0x4C);
    }
    else if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FF76C);
        sub_803E708(0x14, 0x4C);
    }
    else {
        bool8 r7;
        Item newItem;
        DungeonPos pos;
        struct ProjectileThrowInfo unkStruct;

        newItem = *item;
        newItem.flags &= ~(ITEM_FLAG_SET);

        if (info->action.actionParameters[0].actionUseIndex == 0x80) {
            item = NULL;
            RemoveGroundItem(&info->action.actionParameters[0].itemPos, 1);
        }

        r7 = TRUE;
        if ((GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE || GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC) && (newItem.quantity > 1)) {
            r7 = FALSE;
        }

        if (r7) {
            if (info->action.actionParameters[0].actionUseIndex != 0x80) {
                ZeroOutItem(item);
                FillInventoryGaps();
            }
        }
        else {
            if (info->action.actionParameters[0].actionUseIndex == 0x80) {
                newItem.quantity--;
                SpawnItem(&info->action.actionParameters[0].itemPos, &newItem, 1);
            }
            else {
                item->quantity--;
            }
        }

        if (HasHeldItem(entity, ITEM_NO_AIM_SCOPE)) {
            info->action.direction = DungeonRandInt(NUM_DIRECTIONS);
        }

        if (ShouldDisplayEntity(entity)) {
            s32 i;
            s32 dir = info->action.direction;
            sub_80421C0(entity, 0x164);

            for (i = 0; i < NUM_DIRECTIONS; i++) {
                dir--;
                dir &= DIRECTION_MASK;
                sub_806CDD4(entity, 0, dir);
                sub_803E708(2, 21);
            }
            info->unk166 = 4;
        }

        if ((GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE || GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC)) {
            newItem.quantity = 1;
        }

        sub_8045C08(gFormatBuffer_Items[0], &newItem);
        SetMessageArgument_2(gFormatBuffer_Monsters[0], info, 0);
        if (GetItemCategory(newItem.id) == CATEGORY_THROWN_LINE) {
            LogMessageByIdWithPopupCheckUser(entity, gMonThrewItem2);
        }
        else {
            LogMessageByIdWithPopupCheckUser(entity, gMonThrewItem1);
        }

        sub_8042208(entity, GetItemCategory(newItem.id));
        if (HasHeldItem(entity, ITEM_CURVE_BAND)) {
            unkStruct.unk1 = 1;
        }
        else {
            unkStruct.unk1 = 0;
        }

        switch (info->longTossClassStatus.status) {
            case 0:
                unkStruct.unk0 = 0;
                unkStruct.unk2 = 10;
                break;
            case STATUS_LONG_TOSS:
                unkStruct.unk0 = 0;
                unkStruct.unk2 = 99;
                break;
            case STATUS_PIERCE:
                unkStruct.unk0 = 1;
                unkStruct.unk2 = 99;
                break;
        }

        if (HasHeldItem(entity, ITEM_PIERCE_BAND)) {
            unkStruct.unk0 = 1;
            unkStruct.unk2 = 99;
        }

        if (GetItemCategory(newItem.id) == CATEGORY_THROWN_ARC) {
            sub_8083904(&pos, entity);
            HandleCurvedProjectileThrow(entity, &newItem, &entity->pos, &pos, &unkStruct);
        }
        else {
            HandleStraightProjectileThrow(entity, &newItem, &entity->pos, info->action.direction, &unkStruct);
        }

        if (EntityIsValid(entity)) {
            sub_806CE68(entity, info->action.direction);
            sub_807AB38(entity,gDungeon->forceMonsterHouse);
        }
    }
}

void HandleTalkFieldAction(Entity *entity)
{
    sub_8067558(entity, sub_806773C(entity), -1);
}

void sub_806752C(ActionContainer *a0)
{
    Entity *targetEntity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    sub_8067558(GetLeader(), targetEntity, 0);
}

void sub_8067558(Entity *entity, Entity *targetEntity, s32 a2)
{
    EntityInfo *info1 = GetEntInfo(entity);

    if (targetEntity == NULL) {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
    else if (!sub_8070BC0(entity)) {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
    else if (GetTreatmentBetweenMonsters(entity, targetEntity, TRUE, FALSE) != 1
             && GetTreatmentBetweenMonsters(targetEntity, entity, TRUE, FALSE) != 1)
    {
        EntityInfo *info2 = GetEntInfo(targetEntity);

        SetMessageArgument_2(gFormatBuffer_Monsters[0], info2, 0);
        SetMessageArgument_2(gFormatBuffer_Monsters[1], info1, 7);
        sub_8084778();
        TrySendImmobilizeSleepEndMsg(entity, targetEntity);
        if (!sub_8070BC0(targetEntity) || CheckVariousStatuses2(targetEntity, TRUE)) {
            DisplayDungeonMessage(NULL, gUnknown_80FE008, TRUE);
            return;
        }

        sub_806CEFC(entity, GetDirectionTowardsPosition(&entity->pos, &targetEntity->pos));
        if (a2 >= 0) {
            sub_806CEFC(targetEntity, a2);
        }
        else {
            sub_806CEFC(targetEntity, info1->action.direction + 4);
        }

        if (info2->shopkeeper == SHOPKEEPER_MODE_SHOPKEEPER) {
            sub_807EF84();
            return;
        }

        if (info2->monsterBehavior == 1) {
            if (gDungeon->unk644.unk2A != 0) {
                DisplayDungeonMessage(NULL, gUnknown_80FF674, TRUE);
            }
            else if (gDungeon->unk644.unk33) {
                sub_80845E0(targetEntity);
            }
            else {
                sub_8084448(targetEntity);
            }
        }
        else {
            u8 txt[300];
            s32 r2;
            s32 speciesId = info2->apparentID;
            bool8 r6 = FALSE;

            if (info2->joinedAt.id == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON) {
                speciesId = MONSTER_MUNCHLAX;
            }
            else if (info2->joinedAt.id == DUNGEON_RESCUE_TEAM_BASE) {
                speciesId = MONSTER_DECOY;
            }
            else if (info2->joinedAt.id == DUNGEON_JOIN_LOCATION_PARTNER && !gDungeon->unk644.unk18) {
                r6 = TRUE;
            }

            if (info2->HP <= info2->maxHPStat / 4) {
                r2 = 2;
            }
            else if (info2->HP <= (info2->maxHPStat * 6) / 10) {
                r2 = 1;
            }
            else {
                r2 = 0;
            }

            sub_806A3D4(txt, speciesId,  r2, r6);
            DisplayDungeonMessage(NULL, txt, TRUE);
        }
    }
    else {
        DisplayDungeonMessage(NULL, gCannotTalk, TRUE);
    }
}

Entity *sub_806773C(Entity *entity)
{
    Entity *ret = sub_80696A8(entity);
    if (ret == NULL) return NULL;
    if (GetEntityType(ret) != ENTITY_MONSTER) return NULL;
    if (GetEntInfo(entity)->isNotTeamMember) return NULL;

    return ret;
}

void sub_8067768(ActionContainer *a0)
{
    Entity *targetEntity = gDungeon->teamPokemon[a0->actionParameters[0].actionUseIndex];
    sub_8067794(GetLeader(), targetEntity, 0);
}

void sub_8067794(Entity *entity, Entity *targetEntity, s32 a2)
{
    const u8 *stringPtr1;
    const u8 *stringPtr2;
    s32 teamIndex;
    EntityInfo *info2 = GetEntInfo(targetEntity);

    if (targetEntity == NULL) {
        DisplayDungeonMessage(NULL, gCannotFarewell, TRUE);
        return;
    }

    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], targetEntity, 0);
    stringPtr1 = gSayFarewellQ;
    stringPtr2 = gUnknown_80F913C;
    teamIndex = info2->teamIndex;
    if (teamIndex >= 0) {
        DungeonMon *pokeStruct = &gRecruitedPokemonRef->dungeonTeam[teamIndex];
        if (sub_806A564(pokeStruct->recruitedPokemonId)) {
            stringPtr1 = gUnknown_80F9114;
            stringPtr2 = gMonDisappointedAndLeft;
        }
        else if (sub_806A58C(pokeStruct->recruitedPokemonId)) {
            if (IsMakuhitaTrainingMaze()) {
                stringPtr1 = gSendMonBackQ;
            }
            else {
                stringPtr1 = gSendMonBackWithItemQ;
            }
            stringPtr2 = gMonWentBack;
        }
    }

    if (DisplayDungeonYesNoMessage(NULL, stringPtr1, FALSE) == 1) {
        u8 tempText[64];

        strncpy(tempText, gFormatBuffer_Monsters[0], sizeof(tempText));
        HandleFaint(targetEntity, 0x21D, 0);
        strncpy(gFormatBuffer_Monsters[0], tempText, sizeof(tempText));
        DisplayDungeonMessage(NULL, stringPtr2, TRUE);
    }
}

void HandleUseMovePlayerAction(Entity *entity)
{
    s32 i = 0;

    while (i < sub_8070828(entity, TRUE)) {
        EntityInfo *info = GetEntInfo(entity);

        sub_8055A00(entity, info->action.actionParameters[1].actionUseIndex, 1, 0, 0);
        if (IsFloorOver()) {
            break;
        }
        if (info->unk159 != 0) {
            break;
        }
        i++;
    }

    sub_8057588(entity, 1);
    if (!IsFloorOver()) {
        if (EntityIsValid(entity)) {
            sub_806A9B4(entity, GetEntInfo(entity)->action.actionParameters[1].actionUseIndex);
        }
        sub_806A1B0(entity);
    }
}

void sub_8067904(Entity *entity, u16 moveId)
{
    Move move;
    EntityInfo *info = GetEntInfo(entity);

    gUnknown_202F208 = 0;
    InitPokemonMove(&move, moveId);
    if (info->cringeClassStatus.status == STATUS_CRINGE) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        LogMessageByIdWithPopupCheckUser(entity, gMonCringing);
    }
    else if (info->burnClassStatus.status == STATUS_PARALYSIS) {
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        LogMessageByIdWithPopupCheckUser(entity, gMonParalyzed);
    }
    else {
        s32 i;
        bool32 isStruggle;

        if (moveId == MOVE_STRUGGLE) {
            isStruggle = TRUE;
        }
        else {
            isStruggle = FALSE;
        }

        i = 0;
        while (i < sub_8070828(entity, TRUE)) {
            info->abilityEffectFlags = 0;
            move.moveFlags |= 8;
            move.moveFlags |= 4;
            move.PP = 10;
            TryUseChosenMove(entity, isStruggle, 0, 0, FALSE, &move);

            if (!EntityIsValid(entity) || info->unk159 != 0) {
                break;
            }
            i++;
        }

        if (EntityIsValid(entity)) {
            if (moveId == MOVE_STRUGGLE && gUnknown_202F208 == 0) {
                LogMessageByIdWithPopupCheckUser(entity, gUnknown_80FC690);
            }
            if (info->isTeamLeader && moveId != MOVE_STRUGGLE) {
                DungeonPos pos;

                pos.x = entity->pos.x + gAdjacentTileOffsets[info->action.direction].x;
                pos.y = entity->pos.y + gAdjacentTileOffsets[info->action.direction].y;
                sub_807FE44(&pos, 1);
            }
            EnemyEvolution(entity);
        }
    }
}
