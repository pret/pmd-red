#include "global.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack_2.h"
#include "dungeon_ai_item_weight.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_targeting_2.h"
#include "dungeon_capabilities.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_random_1.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "item.h"
#include "position.h"
#include "position_util.h"
#include "team_inventory.h"

#define NUM_POTENTIAL_ROCK_TARGETS 20
#define GROUND_ITEM_TOOLBOX_INDEX 0x80
#define HELD_ITEM_TOOLBOX_INDEX 0x81
#define RANGED_ATTACK_RANGE 10

enum ItemTargetFlag
{
    ITEM_TARGET_OTHER = 1 << 0,
    ITEM_TARGET_ALLY = 1 << 1
};

extern void sub_8077274(struct DungeonEntity *, struct DungeonEntity *);

extern s32 gNumPotentialTargets;
extern u32 gPotentialItemTargetWeights[NUM_DIRECTIONS];
extern u32 gPotentialItemTargetDirections[NUM_DIRECTIONS];
extern bool8 gTargetAhead[NUM_DIRECTIONS];
extern struct TeamInventory *gTeamInventory_203B460;

void sub_807360C(struct DungeonEntity *pokemon)
{
    s32 iVar2;
    struct DungeonEntity *entity;

    for(iVar2 = 0; iVar2 < DUNGEON_MAX_POKEMON; iVar2++)
    {
        entity = gDungeonGlobalData->allPokemon[iVar2];
        if(EntityExists(entity))
        {
            if(entity->entityData->unk152 != 0)
            {
               entity->entityData->unk152 = 0;
               sub_8077274(entity, entity);
            }
        }
    }
}

void DecideUseItem(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    void *null;
    struct ItemSlot *item;
    s32 toolboxIndex;
    u8 selectedToolboxIndex;
    u32 *potentialTargetWeights;
    if (CannotUseItems(pokemon))
    {
        pokemonData->useHeldItem = FALSE;
        return;
    }
    null = NULL;
    if (pokemonData->useHeldItem)
    {
        item = &pokemonData->heldItem;
        if ((item->itemFlags & ITEM_FLAG_EXISTS) == 0)
        {
            return;
        }
        else
        {
            u8 itemType;
            selectedToolboxIndex = HELD_ITEM_TOOLBOX_INDEX;
            itemType = GetItemType(item->itemIndex);
            if (itemType == ITEM_TYPE_THROWABLE)
            {
                s32 targetIndex;
                FindStraightThrowableTargets(pokemon, 2, item, 1);
                for (targetIndex = 0; targetIndex < gNumPotentialTargets; targetIndex++)
                {
                    if (RollPercentChance(gPotentialItemTargetWeights[targetIndex]))
                    {
                        SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                        pokemonData->action.actionUseIndex = selectedToolboxIndex;
                        pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                        pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
                        pokemonData->action.facingDir = gPotentialItemTargetDirections[targetIndex] & DIRECTION_MASK;
                        break;
                    }
                }
                if (targetIndex == gNumPotentialTargets)
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_HAVE_SECOND_THOUGHTS);
                }
            }
            else if (itemType == ITEM_TYPE_ROCK)
            {
                struct Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                FindRockItemTargets(pokemon, item, potentialTargetPositions, TRUE);
                if (gNumPotentialTargets == 0)
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_HAVE_SECOND_THOUGHTS);
                }
                else
                {
                    u32 chosenTargetIndex = DungeonRandomCapped(gNumPotentialTargets);
                    SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                    pokemonData->action.actionUseIndex = selectedToolboxIndex;
                    pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                    pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
                    pokemonData->action.facingDir = CalculateFacingDir(&pokemon->posWorld, &potentialTargetPositions[chosenTargetIndex]) & DIRECTION_MASK;
                    pokemonData->itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                }
            }
            else
            {
                u8 itemTypeCompare = itemType - 2;
                if (itemTypeCompare < ITEM_TYPE_HOLD_ITEM - 2)
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_CONSUME_ITEM_AI);
                    pokemonData->action.actionUseIndex = selectedToolboxIndex;
                    pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                    pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
                }
                else
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_HAVE_SECOND_THOUGHTS);
                }
            }
        }
    }
    else if (HasIQSkill(pokemon, IQ_SKILL_ITEM_MASTER))
    {
        for (toolboxIndex = 1; toolboxIndex < INVENTORY_SIZE + 2; toolboxIndex++)
        {
            if (toolboxIndex == 1)
            {
                item = &pokemonData->heldItem;
                selectedToolboxIndex = HELD_ITEM_TOOLBOX_INDEX;
            }
            else if (toolboxIndex == 0)
            {
                // This seems unused. toolboxIndex can never be 0.
                struct MapTile *mapTile = GetMapTile_1(pokemon->posWorld.x, pokemon->posWorld.y);
                struct DungeonEntity *mapObject = mapTile->mapObject;
                if (mapObject != null)
                {
                    u32 mapObjectType = GetEntityType(mapObject);
                    if (mapObjectType == ENTITY_ITEM)
                    {
                        item = GetItemData(mapTile->mapObject);
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
            else if (pokemonData->isLeader)
            {
                item = &gTeamInventory_203B460->teamItems[toolboxIndex - 2];
                selectedToolboxIndex = toolboxIndex - 1;
            }
            else
            {
                return;
            }
            if (((item->itemFlags & ITEM_FLAG_EXISTS) != 0) && ((item->itemFlags & ITEM_FLAG_FOR_SALE) == 0))
            {
                if ((item->itemFlags & ITEM_FLAG_STICKY) == 0)
                {
                    if (GetItemAIFlag(item->itemIndex, ITEM_AI_FLAG_TARGET_SELF))
                    {
                        u32 itemWeight = EvaluateItem(pokemon, item, ITEM_TARGET_ALLY);
                        if (itemWeight != 0)
                        {
                            u8 itemType = GetItemType(item->itemIndex);
                            if ((!((itemType == ITEM_TYPE_ORB) && (!pokemonData->isEnemy))) && RollPercentChance(itemWeight))
                            {
                                if (itemType == ITEM_TYPE_ORB)
                                {
                                    SetAction(&pokemonData->action, DUNGEON_ACTION_USE_ORB);
                                }
                                else
                                {
                                    SetAction(&pokemonData->action, DUNGEON_ACTION_CONSUME_ITEM_AI);
                                }
                                pokemonData->action.actionUseIndex = selectedToolboxIndex;
                                pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                                pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
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
            if (ToolboxEnabled(pokemonData))
            {
                s32 thrownAIFlag;
                for (thrownAIFlag = ITEM_AI_FLAG_TARGET_ALLY; thrownAIFlag <= ITEM_AI_FLAG_TARGET_ENEMY; thrownAIFlag++)
                {
                    potentialTargetWeights = gPotentialItemTargetWeights;
                    if (GetItemAIFlag(item->itemIndex, thrownAIFlag))
                    {
                        u8 itemType = GetItemType(item->itemIndex);
                        if (itemType == ITEM_TYPE_ROCK)
                        {
                            struct Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                            FindRockItemTargets(pokemon, item, potentialTargetPositions, FALSE);
                            if (gNumPotentialTargets != 0)
                            {
                                u32 chosenTargetIndex = DungeonRandomCapped(gNumPotentialTargets);
                                SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                                pokemonData->action.actionUseIndex = selectedToolboxIndex;
                                pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                                pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
                                pokemonData->action.facingDir = CalculateFacingDir(&pokemon->posWorld, &potentialTargetPositions[chosenTargetIndex]) & DIRECTION_MASK;
                                pokemonData->itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                                return;
                            }
                        }
                        else
                        {
                            s32 targetIndex;
                            FindStraightThrowableTargets(pokemon, thrownAIFlag, item, FALSE);
                            for (targetIndex = 0; targetIndex < gNumPotentialTargets; targetIndex++)
                            {
                                if (RollPercentChance(potentialTargetWeights[targetIndex]))
                                {
                                    SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                                    pokemonData->action.actionUseIndex = selectedToolboxIndex;
                                    pokemonData->action.lastItemThrowPosition.x = pokemon->posWorld.x;
                                    pokemonData->action.lastItemThrowPosition.y = pokemon->posWorld.y;
                                    pokemonData->action.facingDir = gPotentialItemTargetDirections[targetIndex] & DIRECTION_MASK;
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

void FindStraightThrowableTargets(struct DungeonEntity *pokemon, s32 thrownAIFlag, struct ItemSlot *item, bool8 ignoreRollChance)
{
    s32 i;
    gNumPotentialTargets = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gTargetAhead[i] = FALSE;
    }
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        struct DungeonEntity* targetPokemon = gDungeonGlobalData->allPokemon[i];
        if (EntityExists(targetPokemon) && pokemon != targetPokemon)
        {
            s32 targetingFlags;
            if (thrownAIFlag == ITEM_AI_FLAG_TARGET_ALLY)
            {
                if (CanTarget(pokemon, targetPokemon, FALSE, FALSE) == TARGET_CAPABILITY_CANNOT_ATTACK)
                {
                    targetingFlags = ITEM_TARGET_OTHER | ITEM_TARGET_ALLY;
                }
                else
                {
                    continue;
                }
            }
            else if (CanTarget(pokemon, targetPokemon, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
            {
                targetingFlags = ITEM_TARGET_OTHER;
            }
            else
            {
                continue;
            }
            if (CanSee(pokemon, targetPokemon))
            {
                TargetThrownItem(pokemon, targetPokemon, item, targetingFlags, ignoreRollChance);
            }
        }
    }
}

void FindRockItemTargets(struct DungeonEntity *pokemon, struct ItemSlot *item, struct Position potentialTargets[], bool8 ignoreRollChance)
{
    s32 i;
    gNumPotentialTargets = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        struct DungeonEntity* targetPokemon = gDungeonGlobalData->allPokemon[i];
        if (EntityExists(targetPokemon) && pokemon != targetPokemon &&
            CanSee(pokemon, targetPokemon) && CanTarget(pokemon, targetPokemon, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
        {
            s32 posDiffX;
            s32 maxPosDiff;
            posDiffX = targetPokemon->posWorld.x - pokemon->posWorld.x;
            if (posDiffX < 0)
            {
                posDiffX = -posDiffX;
            }
            maxPosDiff = targetPokemon->posWorld.y - pokemon->posWorld.y;
            if (maxPosDiff < 0)
            {
                maxPosDiff = -maxPosDiff;
            }
            if (maxPosDiff < posDiffX)
            {
                maxPosDiff = posDiffX;
            }
            if (maxPosDiff <= 10)
            {
                struct Position *newPotentialTarget;
                if (!ignoreRollChance)
                {
                    u32 itemWeight = EvaluateItem(targetPokemon, item, ITEM_TARGET_OTHER);
                    if (!RollPercentChance(itemWeight))
                    {
                        continue;
                    }
                }
                newPotentialTarget = &potentialTargets[gNumPotentialTargets];
                newPotentialTarget->x = targetPokemon->posWorld.x;
                newPotentialTarget->y = targetPokemon->posWorld.y;
                gNumPotentialTargets++;
            }
        }
    }
}

void TargetThrownItem(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, struct ItemSlot *item, s32 targetingFlags, bool8 ignoreRollChance)
{
    s32 posDiffX = pokemon->posWorld.x - targetPokemon->posWorld.x;
    s32 posDiffY;
    s32 targetDirection;
    posDiffX = posDiffX < 0 ? -posDiffX : posDiffX;
    posDiffY = pokemon->posWorld.y - targetPokemon->posWorld.y;
    posDiffY = posDiffY < 0 ? -posDiffY : posDiffY;
    if (pokemon->entityData->itemStatus == ITEM_STATUS_NONE)
    {
        s32 maxPosDiff = posDiffY < posDiffX ? posDiffX : posDiffY;
        if (maxPosDiff > RANGED_ATTACK_RANGE)
        {
            return;
        }
    }
    targetDirection = -1;
    if (posDiffX == posDiffY)
    {
        if (pokemon->posWorld.x < targetPokemon->posWorld.x && pokemon->posWorld.y < targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_SOUTHEAST;
        }
        else if (pokemon->posWorld.x < targetPokemon->posWorld.x && pokemon->posWorld.y > targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_NORTHEAST;
        }
        else if (pokemon->posWorld.x > targetPokemon->posWorld.x && pokemon->posWorld.y > targetPokemon->posWorld.y)
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
        if (pokemon->posWorld.x == targetPokemon->posWorld.x && pokemon->posWorld.y < targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_SOUTH;
        }
        else if (pokemon->posWorld.x < targetPokemon->posWorld.x && pokemon->posWorld.y == targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_EAST;
        }
        else if (pokemon->posWorld.x == targetPokemon->posWorld.x && pokemon->posWorld.y > targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_NORTH;
        }
        else if (pokemon->posWorld.x > targetPokemon->posWorld.x && pokemon->posWorld.y == targetPokemon->posWorld.y)
        {
            targetDirection = DIRECTION_WEST;
        }
    }

    if (targetDirection > -1 && !gTargetAhead[targetDirection] && IsTargetStraightAhead(pokemon, targetPokemon, targetDirection, RANGED_ATTACK_RANGE))
    {
        u32 itemWeight;
        u32 *targetWeight;
        gTargetAhead[targetDirection] = TRUE;
        gPotentialItemTargetDirections[gNumPotentialTargets] = targetDirection;
        targetWeight = &gPotentialItemTargetWeights[gNumPotentialTargets];
        itemWeight = !ignoreRollChance ? EvaluateItem(targetPokemon, item, targetingFlags) : 100;
        *targetWeight = itemWeight;
        gNumPotentialTargets++;
    }
}
