#include "global.h"
#include "globaldata.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_item_weight.h"
#include "dungeon_ai_items.h"
#include "dungeon_logic.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "items.h"
#include "structs/str_position.h"
#include "position_util.h"
#include "string_format.h"
#include "dungeon_strings.h"
#include "dungeon_message.h"
#include "dungeon_music.h"
#include "dungeon_items.h"
#include "constants/dungeon.h"

extern void sub_8045BF8(u8 *, Item *);
extern void sub_8067110(Entity *);
extern void sub_80671A0(Entity *);
extern bool8 sub_8044B28(void);

#define NUM_POTENTIAL_ROCK_TARGETS 20
#define GROUND_ITEM_TOOLBOX_INDEX 0x80
#define HELD_ITEM_TOOLBOX_INDEX 0x81

enum ItemTargetFlag
{
    ITEM_TARGET_OTHER = 1 << 0,
    ITEM_TARGET_ALLY = 1 << 1
};

EWRAM_INIT s32 gAIThrowItemActionChoiceCount = {0};

EWRAM_DATA u32 gAIThrownItemDirections[NUM_DIRECTIONS] = {0};
EWRAM_DATA bool8 gAIThrownItemDirectionIsUsed[NUM_DIRECTIONS] = {0};
EWRAM_DATA u32 gAIThrownItemProbabilities[NUM_DIRECTIONS] = {0};

extern TeamInventory *gTeamInventoryRef;

void sub_8073D14(Entity *);

void AIDecideUseItem(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    void *null;
    Item *item;
    s32 toolboxIndex;
    u8 selectedToolboxIndex;
    u32 *potentialTargetWeights;
    if (CheckVariousConditions(pokemon))
    {
        pokemonInfo->useHeldItem = FALSE;
        return;
    }
    null = NULL;
    if (pokemonInfo->useHeldItem)
    {
        item = &pokemonInfo->heldItem;
        if ((item->flags & ITEM_FLAG_EXISTS) == 0)
        {
            return;
        }
        else
        {
            u8 itemType;
            selectedToolboxIndex = HELD_ITEM_TOOLBOX_INDEX;
            itemType = GetItemCategory(item->id);
            if (itemType == CATEGORY_THROWN_LINE)
            {
                s32 targetIndex;
                GetPossibleAIThrownItemDirections(pokemon, ITEM_AI_FLAG_TARGET_ENEMY, item, TRUE);
                for (targetIndex = 0; targetIndex < gAIThrowItemActionChoiceCount; targetIndex++)
                {
                    if (DungeonRandOutcome(gAIThrownItemProbabilities[targetIndex]))
                    {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                        pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                        pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                        pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                        pokemonInfo->action.direction = gAIThrownItemDirections[targetIndex] & DIRECTION_MASK;
                        break;
                    }
                }
                if (targetIndex == gAIThrowItemActionChoiceCount)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
            }
            else if (itemType == CATEGORY_THROWN_ARC)
            {
                DungeonPos potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                GetPossibleAIArcItemTargets(pokemon, item, potentialTargetPositions, TRUE);
                if (gAIThrowItemActionChoiceCount == 0)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
                else
                {
                    u32 chosenTargetIndex = DungeonRandInt(gAIThrowItemActionChoiceCount);
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                    pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                    pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                    pokemonInfo->action.direction = GetDirectionTowardsPosition(&pokemon->pos, &potentialTargetPositions[chosenTargetIndex]) & DIRECTION_MASK;
                    pokemonInfo->action.itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                }
            }
            else
            {
                u8 itemTypeCompare = itemType - 2;
                if (itemTypeCompare < CATEGORY_HELD_ITEMS - 2)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_EAT_AI);
                    pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                    pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                }
                else
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
            }
        }
    }
    else if (IQSkillIsEnabled(pokemon, IQ_ITEM_MASTER))
    {
        for (toolboxIndex = 1; toolboxIndex < INVENTORY_SIZE + 2; toolboxIndex++)
        {
            if (toolboxIndex == 1)
            {
                item = &pokemonInfo->heldItem;
                selectedToolboxIndex = HELD_ITEM_TOOLBOX_INDEX;
            }
            else if (toolboxIndex == 0)
            {
                // This seems unused. toolboxIndex can never be 0.
                const Tile *mapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
                Entity *object = mapTile->object;
                if (object != null)
                {
                    u32 objectType = GetEntityType(object);
                    if (objectType == ENTITY_ITEM)
                    {
                        item = GetItemData(mapTile->object);
                        selectedToolboxIndex = GROUND_ITEM_TOOLBOX_INDEX;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
            else if (pokemonInfo->isTeamLeader)
            {
                item = &gTeamInventoryRef->teamItems[toolboxIndex - 2];
                selectedToolboxIndex = toolboxIndex - 1;
            }
            else
            {
                return;
            }
            if (((item->flags & ITEM_FLAG_EXISTS) != 0) && ((item->flags & ITEM_FLAG_IN_SHOP) == 0))
            {
                if ((item->flags & ITEM_FLAG_STICKY) == 0)
                {
                    if (TestItemAIFlag(item->id, ITEM_AI_FLAG_TARGET_SELF))
                    {
                        u32 itemWeight = GetAIUseItemProbability(pokemon, item, ITEM_TARGET_ALLY);
                        if (itemWeight != 0)
                        {
                            u8 itemType = GetItemCategory(item->id);
                            if ((!((itemType == CATEGORY_ORBS) && (!pokemonInfo->isNotTeamMember))) && DungeonRandOutcome(itemWeight))
                            {
                                if (itemType == CATEGORY_ORBS)
                                {
                                    SetMonsterActionFields(&pokemonInfo->action, ACTION_USE_ORB);
                                }
                                else
                                {
                                    SetMonsterActionFields(&pokemonInfo->action, ACTION_EAT_AI);
                                }
                                pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                                pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                                return;
                            }
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
            else
            {
                continue;
            }
            if (MonsterCanThrowItems(pokemonInfo))
            {
                s32 thrownAIFlag;
                for (thrownAIFlag = ITEM_AI_FLAG_TARGET_ALLY; thrownAIFlag <= ITEM_AI_FLAG_TARGET_ENEMY; thrownAIFlag++)
                {
                    potentialTargetWeights = gAIThrownItemProbabilities;
                    if (TestItemAIFlag(item->id, thrownAIFlag))
                    {
                        u8 itemType = GetItemCategory(item->id);
                        if (itemType == CATEGORY_THROWN_ARC)
                        {
                            DungeonPos potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                            GetPossibleAIArcItemTargets(pokemon, item, potentialTargetPositions, FALSE);
                            if (gAIThrowItemActionChoiceCount != 0)
                            {
                                u32 chosenTargetIndex = DungeonRandInt(gAIThrowItemActionChoiceCount);
                                SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                                pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                                pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                                pokemonInfo->action.direction = GetDirectionTowardsPosition(&pokemon->pos, &potentialTargetPositions[chosenTargetIndex]) & DIRECTION_MASK;
                                pokemonInfo->action.itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                                return;
                            }
                        }
                        else
                        {
                            s32 targetIndex;
                            GetPossibleAIThrownItemDirections(pokemon, thrownAIFlag, item, FALSE);
                            for (targetIndex = 0; targetIndex < gAIThrowItemActionChoiceCount; targetIndex++)
                            {
                                if (DungeonRandOutcome(potentialTargetWeights[targetIndex]))
                                {
                                    SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                                    pokemonInfo->action.actionParameters[0].actionUseIndex = selectedToolboxIndex;
                                    pokemonInfo->action.actionParameters[0].itemPos.x = pokemon->pos.x;
                                    pokemonInfo->action.actionParameters[0].itemPos.y = pokemon->pos.y;
                                    pokemonInfo->action.direction = gAIThrownItemDirections[targetIndex] & DIRECTION_MASK;
                                    return;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void GetPossibleAIThrownItemDirections(Entity *pokemon, s32 thrownAIFlag, Item *item, bool8 ignoreRollChance)
{
    s32 i;
    gAIThrowItemActionChoiceCount = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gAIThrownItemDirectionIsUsed[i] = FALSE;
    }
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        Entity *targetPokemon = gDungeon->activePokemon[i];
        if (EntityIsValid(targetPokemon) && pokemon != targetPokemon)
        {
            s32 targetingFlags;
            if (thrownAIFlag == ITEM_AI_FLAG_TARGET_ALLY)
            {
                if (GetTreatmentBetweenMonsters(pokemon, targetPokemon, FALSE, FALSE) == TREATMENT_TREAT_AS_ALLY)
                {
                    targetingFlags = ITEM_TARGET_OTHER | ITEM_TARGET_ALLY;
                }
                else
                {
                    continue;
                }
            }
            else if (GetTreatmentBetweenMonsters(pokemon, targetPokemon, FALSE, TRUE) == TREATMENT_TREAT_AS_ENEMY)
            {
                targetingFlags = ITEM_TARGET_OTHER;
            }
            else
            {
                continue;
            }
            if (CanSeeTarget(pokemon, targetPokemon))
            {
                TargetThrownItem(pokemon, targetPokemon, item, targetingFlags, ignoreRollChance);
            }
        }
    }
}

void GetPossibleAIArcItemTargets(Entity *pokemon, Item *item,
                                 DungeonPos potentialTargets[],
                                 bool8 ignoreRollChance)
{
    s32 i;
    gAIThrowItemActionChoiceCount = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        Entity *targetPokemon = gDungeon->activePokemon[i];
        if (EntityIsValid(targetPokemon) && pokemon != targetPokemon &&
            CanSeeTarget(pokemon, targetPokemon) && GetTreatmentBetweenMonsters(pokemon, targetPokemon, FALSE, TRUE) == TREATMENT_TREAT_AS_ENEMY)
        {
            s32 distanceX;
            s32 distance;
            distanceX = targetPokemon->pos.x - pokemon->pos.x;
            if (distanceX < 0)
            {
                distanceX = -distanceX;
            }
            distance = targetPokemon->pos.y - pokemon->pos.y;
            if (distance < 0)
            {
                distance = -distance;
            }
            if (distance < distanceX)
            {
                distance = distanceX;
            }
            if (distance <= 10)
            {
                DungeonPos *newPotentialTarget;
                if (!ignoreRollChance)
                {
                    u32 itemWeight = GetAIUseItemProbability(targetPokemon, item, ITEM_TARGET_OTHER);
                    if (!DungeonRandOutcome(itemWeight))
                    {
                        continue;
                    }
                }
                newPotentialTarget = &potentialTargets[gAIThrowItemActionChoiceCount];
                newPotentialTarget->x = targetPokemon->pos.x;
                newPotentialTarget->y = targetPokemon->pos.y;
                gAIThrowItemActionChoiceCount++;
            }
        }
    }
}

void TargetThrownItem(Entity *pokemon, Entity *targetPokemon, Item *item, s32 targetingFlags, bool8 ignoreRollChance)
{
    s32 distanceX = pokemon->pos.x - targetPokemon->pos.x;
    s32 distanceY;
    s32 targetDirection;
    distanceX = distanceX < 0 ? -distanceX : distanceX;
    distanceY = pokemon->pos.y - targetPokemon->pos.y;
    distanceY = distanceY < 0 ? -distanceY : distanceY;
    if (GetEntInfo(pokemon)->longTossClassStatus.status == STATUS_NONE)
    {
        s32 distance = distanceY < distanceX ? distanceX : distanceY;
        if (distance > RANGED_ATTACK_RANGE)
        {
            return;
        }
    }
    targetDirection = -1;
    if (distanceX == distanceY)
    {
        if (pokemon->pos.x < targetPokemon->pos.x && pokemon->pos.y < targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_SOUTHEAST;
        }
        else if (pokemon->pos.x < targetPokemon->pos.x && pokemon->pos.y > targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_NORTHEAST;
        }
        else if (pokemon->pos.x > targetPokemon->pos.x && pokemon->pos.y > targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_NORTHWEST;
        }
        else
        {
            targetDirection = DIRECTION_SOUTHWEST;
        }
    }
    else
    {
        if (pokemon->pos.x == targetPokemon->pos.x && pokemon->pos.y < targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_SOUTH;
        }
        else if (pokemon->pos.x < targetPokemon->pos.x && pokemon->pos.y == targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_EAST;
        }
        else if (pokemon->pos.x == targetPokemon->pos.x && pokemon->pos.y > targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_NORTH;
        }
        else if (pokemon->pos.x > targetPokemon->pos.x && pokemon->pos.y == targetPokemon->pos.y)
        {
            targetDirection = DIRECTION_WEST;
        }
    }

    if (targetDirection > -1 && !gAIThrownItemDirectionIsUsed[targetDirection] && IsTargetInRange(pokemon, targetPokemon, targetDirection, RANGED_ATTACK_RANGE))
    {
        u32 itemWeight;
        u32 *targetWeight;
        gAIThrownItemDirectionIsUsed[targetDirection] = TRUE;
        gAIThrownItemDirections[gAIThrowItemActionChoiceCount] = targetDirection;
        targetWeight = &gAIThrownItemProbabilities[gAIThrowItemActionChoiceCount];
        itemWeight = !ignoreRollChance ? GetAIUseItemProbability(targetPokemon, item, targetingFlags) : 100;
        *targetWeight = itemWeight;
        gAIThrowItemActionChoiceCount++;
    }
}

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

void sub_8073D14(Entity *entity)
{
    Item *groundItem;
    EntityInfo *_entityInfo;
    EntityInfo *entityInfo = GetEntInfo(entity);
    Entity *tileObject = GetTileAtEntitySafe(entity)->object;
    if (tileObject == NULL)
        return;
    if (sub_8044B28())
        return;
    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
    if (entityInfo->isTeamLeader)
        return;
    if (entityInfo->shopkeeper == 1)
        return;
    if (IsExperienceLocked(entityInfo->joinedAt.id))
        return;
    if (entityInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
        return;

    _entityInfo = GetEntInfo(entity); // Reloaded as a new variable for some reason.
    groundItem = GetItemData(tileObject);
    if (groundItem->flags & ITEM_FLAG_IN_SHOP)
        return;

    if (ShouldMonsterRunAwayAndShowEffect(entity, TRUE)) {
        sub_8045BF8(gFormatBuffer_Items[0], groundItem);
        SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
        DisplayDungeonLoggableMessageTrue(entity, gMonTerrifiedCouldntPickUpItem);
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
        sub_8045BF8(gFormatBuffer_Items[0], groundItem);
        RemoveItemFromDungeonAt(&entity->pos, 1);
        DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem);
    }
    else {
        s32 i, nItems, newInventoryId;
        s32 inventoryIds[INVENTORY_SIZE + 1]; // plus held
        Item *carriedItems[INVENTORY_SIZE + 1]; // plus held
        s32 newQuantity;

        if (gDungeon->unk644.hasInventory && !_entityInfo->isNotTeamMember) {
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

                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                RemoveItemFromDungeonAt(&entity->pos, 1);
                PlaySoundEffect(0x14A);
                if (inventoryIds[newInventoryId] <= -1)
                    DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem2);
                else
                    DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItemToolbox);

                return;
            }
        }

        for (i = 0; i < nItems; i++) {
            if (!(carriedItems[i]->flags & ITEM_FLAG_EXISTS))
                break;
        }

        if (i == nItems) {
            sub_8045BF8(gFormatBuffer_Items[0], groundItem);
            DisplayDungeonLoggableMessageTrue(entity, gMonSteppedOnItem);
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
                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                RemoveItemFromDungeonAt(&entity->pos, 1);
                DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItem2);
            }
            else if (AddItemToInventory(groundItem)) {
                SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], entity, 0);
                DisplayDungeonLoggableMessageTrue(entity, gMonCouldntPickUpItem);
            }
            else {
                sub_8045BF8(gFormatBuffer_Items[0], groundItem);
                RemoveItemFromDungeonAt(&entity->pos, 1);
                DisplayDungeonLoggableMessageTrue(entity, gMonPickedUpItemToolbox);
            }
        }
    }
}
