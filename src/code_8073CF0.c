#include "global.h"
#include "dungeon_util.h"
#include "items.h"
#include "dungeon_ai_targeting.h"
#include "code_8045A00.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "dungeon_music.h"
#include "constants/dungeon.h"

extern bool8 sub_8044B28(void);
extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern void sub_8073D14(Entity *);
extern void sub_8045BF8(u8 *, Item *);
extern void sub_805239C(Entity *, const u8 *);
extern bool8 sub_80461C8(Position *, u32);

extern u8 gUnknown_202DE58[];
extern u8 gAvailablePokemonNames[];

void HandleEatAIAction(Entity *pokemon)
{
    sub_8067110(pokemon);
}

void HandleThrowItemAIAction(Entity *pokemon)
{
    sub_80671A0(pokemon);
}

void HandlePickUpAIAction(Entity *pokemon)
{
    sub_8073D14(pokemon);
}

extern const u8 *gUnknown_80F8F88;
extern const u8 *gUnknown_80F9054;
extern const u8 *gUnknown_80F9018;
extern const u8 *gUnknown_80F9050;
extern const u8 *gUnknown_80F8F54;
extern const u8 *gUnknown_80F8FAC;

void sub_8073D14(Entity *entity)
{
    Item *groundItem;
    EntityInfo *_entityInfo;
    EntityInfo *entityInfo = entity->info;
    Entity *tileObject = GetTileAtEntitySafe(entity)->object;
    if (tileObject == NULL)
        return;
    if (sub_8044B28())
        return;
    SetMessageArgument(gAvailablePokemonNames, entity, 0);
    if (entityInfo->isTeamLeader)
        return;
    if (entityInfo->shopkeeper == 1)
        return;
    if (IsClientOrTeamBase(entityInfo->joinedAt.joinedAt))
        return;
    if (entityInfo->clientType == 1)
        return;

    _entityInfo = entity->info; // Reloaded as a new variable for some reason.
    groundItem = GetItemData(tileObject);
    if (groundItem->flags & ITEM_FLAG_IN_SHOP)
        return;

    if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        sub_8045BF8(gUnknown_202DE58, groundItem);
        SetMessageArgument(gAvailablePokemonNames, entity, 0);
        sub_805239C(entity, gUnknown_80F8F88);
    }
    else if (!_entityInfo->isNotTeamMember && GetItemCategory(groundItem->id) == CATEGORY_POKE) {
        // Why check the same thing again?
        if (_entityInfo->isNotTeamMember) {
            PlaySoundEffect(0x14B);
        }
        else {
            PlaySoundEffect(0x14C);
        }
        AddToTeamMoney(GetMoneyValue(groundItem));
        sub_8045BF8(gUnknown_202DE58, groundItem);
        sub_80461C8(&entity->pos, 1);
        sub_805239C(entity, gUnknown_80F9054);
    }
    else {
        s32 i, nItems, newInventoryId;
        s32 inventoryIds[INVENTORY_SIZE + 1]; // plus held
        Item *carriedItems[INVENTORY_SIZE + 1]; // plus held
        s32 newQuantity;

        if (gDungeon->unk65B && !_entityInfo->isNotTeamMember) {
            for (i = 0; i < INVENTORY_SIZE; i++) {
                carriedItems[i] = &gTeamInventoryRef->teamItems[i];
                inventoryIds[i] = i;
            }
            carriedItems[INVENTORY_SIZE] = &_entityInfo->heldItem;
            inventoryIds[INVENTORY_SIZE] = -1;
            nItems = INVENTORY_SIZE + 1;
        }
        else {
            carriedItems[0] = &_entityInfo->heldItem;
            inventoryIds[0] = -1;
            nItems = 1;
        }

        if ((groundItem->id < 9) && !(groundItem->flags & ITEM_FLAG_IN_SHOP)) {
            newInventoryId = -1;
            newQuantity = -1;
            for (i = 0; i < nItems; i++) {
                if (carriedItems[i]->flags & ITEM_FLAG_EXISTS
                    && !(carriedItems[i]->flags & ITEM_FLAG_IN_SHOP)
                    && ((groundItem->id == carriedItems[i]->id) && (groundItem->flags & ITEM_FLAG_STICKY) == (carriedItems[i]->flags & ITEM_FLAG_STICKY))
                    && carriedItems[i]->quantity != 99 && newQuantity < carriedItems[i]->quantity)
                {
                    newQuantity = carriedItems[i]->quantity;
                    newInventoryId = i;
                }
            }

            if (newInventoryId == -1) {
                newQuantity = -1;
                for (i = 0; i < nItems; i++) {
                    if (carriedItems[i]->flags & ITEM_FLAG_EXISTS
                        && !(carriedItems[i]->flags & ITEM_FLAG_IN_SHOP)
                        && groundItem->id == carriedItems[i]->id
                        && carriedItems[i]->quantity != 99
                        && newQuantity < carriedItems[i]->quantity)
                    {
                        newQuantity = carriedItems[i]->quantity;
                        newInventoryId = i;
                    }
                }
            }

            if (newInventoryId != -1) {
                s32 quantity = carriedItems[newInventoryId]->quantity + groundItem->quantity;
                if (quantity >= 99)
                    quantity = 99;
                carriedItems[newInventoryId]->quantity = quantity;
                if (groundItem->flags & ITEM_FLAG_STICKY)
                    carriedItems[newInventoryId]->flags |= ITEM_FLAG_STICKY;

                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                PlaySoundEffect(0x14A);
                if (inventoryIds[newInventoryId] <= -1)
                    sub_805239C(entity, gUnknown_80F9018);
                else
                    sub_805239C(entity, gUnknown_80F9050);

                return;
            }
        }

        for (i = 0; i < nItems; i++) {
            if (!(carriedItems[i]->flags & ITEM_FLAG_EXISTS))
                break;
        }

        if (i == nItems) {
            sub_8045BF8(gUnknown_202DE58, groundItem);
            sub_805239C(entity, gUnknown_80F8F54);
        }
        else {
            if (_entityInfo->isNotTeamMember) {
                PlaySoundEffect(0x14B);
            }
            else {
                PlaySoundEffect(0x14A);
            }

            if (inventoryIds[i] <= -1) {
                _entityInfo->heldItem = *groundItem;
                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gUnknown_80F9018);
            }
            else if (AddItemToInventory(groundItem)) {
                SetMessageArgument(gAvailablePokemonNames, entity, 0);
                sub_805239C(entity, gUnknown_80F8FAC);
            }
            else {
                sub_8045BF8(gUnknown_202DE58, groundItem);
                sub_80461C8(&entity->pos, 1);
                sub_805239C(entity, gUnknown_80F9050);
            }
        }
    }
}

