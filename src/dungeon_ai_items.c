#include "global.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_item_weight.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_entity.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "item.h"
#include "position.h"
#include "position_util.h"
#include "status.h"
#include "team_inventory.h"

#define NUM_POTENTIAL_ROCK_TARGETS 20
#define GROUND_ITEM_TOOLBOX_INDEX 0x80
#define HELD_ITEM_TOOLBOX_INDEX 0x81

enum ItemTargetFlag
{
    ITEM_TARGET_OTHER = 1 << 0,
    ITEM_TARGET_ALLY = 1 << 1
};

extern s32 gNumPotentialTargets;
extern u32 gPotentialItemTargetWeights[NUM_DIRECTIONS];
extern u32 gPotentialItemTargetDirections[NUM_DIRECTIONS];
extern bool8 gTargetAhead[NUM_DIRECTIONS];
extern struct TeamInventory *gTeamInventory_203B460;

void sub_807360C(struct Entity *pokemon)
{
    s32 iVar2;
    struct Entity *entity;

    for(iVar2 = 0; iVar2 < DUNGEON_MAX_POKEMON; iVar2++)
    {
        entity = gDungeon->allPokemon[iVar2];
        if(EntityExists(entity))
        {
            if(entity->info->unk152 != 0)
            {
               entity->info->unk152 = 0;
               UpdateFlashFireBoost(entity, entity);
            }
        }
    }
}

void DecideUseItem(struct Entity *pokemon)
{
    struct EntityInfo *pokemonInfo = pokemon->info;
    void *null;
    struct Item *item;
    s32 toolboxIndex;
    u8 selectedToolboxIndex;
    u32 *potentialTargetWeights;
    if (CannotUseItems(pokemon))
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
                FindStraightThrowableTargets(pokemon, 2, item, 1);
                for (targetIndex = 0; targetIndex < gNumPotentialTargets; targetIndex++)
                {
                    if (DungeonRandOutcome(gPotentialItemTargetWeights[targetIndex]))
                    {
                        SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                        pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                        pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                        pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
                        pokemonInfo->action.direction = gPotentialItemTargetDirections[targetIndex] & DIRECTION_MASK;
                        break;
                    }
                }
                if (targetIndex == gNumPotentialTargets)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
            }
            else if (itemType == CATEGORY_THROWN_ARC)
            {
                struct Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                FindRockItemTargets(pokemon, item, potentialTargetPositions, TRUE);
                if (gNumPotentialTargets == 0)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
                else
                {
                    u32 chosenTargetIndex = DungeonRandInt(gNumPotentialTargets);
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                    pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                    pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
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
                    pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                    pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
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
                struct Tile *mapTile = GetTile(pokemon->pos.x, pokemon->pos.y);
                struct Entity *object = mapTile->object;
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
                item = &gTeamInventory_203B460->teamItems[toolboxIndex - 2];
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
                    if (GetItemAIFlag(item->id, ITEM_AI_FLAG_TARGET_SELF))
                    {
                        u32 itemWeight = EvaluateItem(pokemon, item, ITEM_TARGET_ALLY);
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
                                pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                                pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
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
            if (ToolboxEnabled(pokemonInfo))
            {
                s32 thrownAIFlag;
                for (thrownAIFlag = ITEM_AI_FLAG_TARGET_ALLY; thrownAIFlag <= ITEM_AI_FLAG_TARGET_ENEMY; thrownAIFlag++)
                {
                    potentialTargetWeights = gPotentialItemTargetWeights;
                    if (GetItemAIFlag(item->id, thrownAIFlag))
                    {
                        u8 itemType = GetItemCategory(item->id);
                        if (itemType == CATEGORY_THROWN_ARC)
                        {
                            struct Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                            FindRockItemTargets(pokemon, item, potentialTargetPositions, FALSE);
                            if (gNumPotentialTargets != 0)
                            {
                                u32 chosenTargetIndex = DungeonRandInt(gNumPotentialTargets);
                                SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                                pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                                pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
                                pokemonInfo->action.direction = GetDirectionTowardsPosition(&pokemon->pos, &potentialTargetPositions[chosenTargetIndex]) & DIRECTION_MASK;
                                pokemonInfo->action.itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                                return;
                            }
                        }
                        else
                        {
                            s32 targetIndex;
                            FindStraightThrowableTargets(pokemon, thrownAIFlag, item, FALSE);
                            for (targetIndex = 0; targetIndex < gNumPotentialTargets; targetIndex++)
                            {
                                if (DungeonRandOutcome(potentialTargetWeights[targetIndex]))
                                {
                                    SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                                    pokemonInfo->action.actionUseIndex = selectedToolboxIndex;
                                    pokemonInfo->action.lastItemThrowPosition.x = pokemon->pos.x;
                                    pokemonInfo->action.lastItemThrowPosition.y = pokemon->pos.y;
                                    pokemonInfo->action.direction = gPotentialItemTargetDirections[targetIndex] & DIRECTION_MASK;
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

void FindStraightThrowableTargets(struct Entity *pokemon, s32 thrownAIFlag, struct Item *item, bool8 ignoreRollChance)
{
    s32 i;
    gNumPotentialTargets = 0;
    for (i = 0; i < NUM_DIRECTIONS; i++)
    {
        gTargetAhead[i] = FALSE;
    }
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        struct Entity *targetPokemon = gDungeon->allPokemon[i];
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
            if (CanSeeTarget(pokemon, targetPokemon))
            {
                TargetThrownItem(pokemon, targetPokemon, item, targetingFlags, ignoreRollChance);
            }
        }
    }
}

void FindRockItemTargets(struct Entity *pokemon, struct Item *item, struct Position potentialTargets[], bool8 ignoreRollChance)
{
    s32 i;
    gNumPotentialTargets = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        struct Entity *targetPokemon = gDungeon->allPokemon[i];
        if (EntityExists(targetPokemon) && pokemon != targetPokemon &&
            CanSeeTarget(pokemon, targetPokemon) && CanTarget(pokemon, targetPokemon, FALSE, TRUE) == TARGET_CAPABILITY_CAN_TARGET)
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
                struct Position *newPotentialTarget;
                if (!ignoreRollChance)
                {
                    u32 itemWeight = EvaluateItem(targetPokemon, item, ITEM_TARGET_OTHER);
                    if (!DungeonRandOutcome(itemWeight))
                    {
                        continue;
                    }
                }
                newPotentialTarget = &potentialTargets[gNumPotentialTargets];
                newPotentialTarget->x = targetPokemon->pos.x;
                newPotentialTarget->y = targetPokemon->pos.y;
                gNumPotentialTargets++;
            }
        }
    }
}

void TargetThrownItem(struct Entity *pokemon, struct Entity *targetPokemon, struct Item *item, s32 targetingFlags, bool8 ignoreRollChance)
{
    s32 distanceX = pokemon->pos.x - targetPokemon->pos.x;
    s32 distanceY;
    s32 targetDirection;
    distanceX = distanceX < 0 ? -distanceX : distanceX;
    distanceY = pokemon->pos.y - targetPokemon->pos.y;
    distanceY = distanceY < 0 ? -distanceY : distanceY;
    if (pokemon->info->itemStatus == STATUS_NONE)
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

    if (targetDirection > -1 && !gTargetAhead[targetDirection] && IsTargetInRange(pokemon, targetPokemon, targetDirection, RANGED_ATTACK_RANGE))
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
