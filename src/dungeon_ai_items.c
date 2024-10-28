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
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "items.h"
#include "structs/str_position.h"
#include "position_util.h"
#include "status.h"


#define NUM_POTENTIAL_ROCK_TARGETS 20
#define GROUND_ITEM_TOOLBOX_INDEX 0x80
#define HELD_ITEM_TOOLBOX_INDEX 0x81

enum ItemTargetFlag
{
    ITEM_TARGET_OTHER = 1 << 0,
    ITEM_TARGET_ALLY = 1 << 1
};

EWRAM_DATA_2 s32 gAIThrowItemActionChoiceCount = {0};

EWRAM_DATA u32 gAIThrownItemDirections[NUM_DIRECTIONS] = {0};
EWRAM_DATA bool8 gAIThrownItemDirectionIsUsed[NUM_DIRECTIONS] = {0};
EWRAM_DATA u32 gAIThrownItemProbabilities[NUM_DIRECTIONS] = {0};

extern TeamInventory *gTeamInventoryRef;

void sub_807360C(void)
{
    s32 index;
    Entity *entity;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if(EntityExists(entity))
        {
            if(entity->axObj.info->unk152 != 0)
            {
               entity->axObj.info->unk152 = 0;
               UpdateFlashFireBoost(entity, entity);
            }
        }
    }
}

void AIDecideUseItem(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->axObj.info;
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
                        pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                        pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                        pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
                Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                GetPossibleAIArcItemTargets(pokemon, item, potentialTargetPositions, TRUE);
                if (gAIThrowItemActionChoiceCount == 0)
                {
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_SECOND_THOUGHTS);
                }
                else
                {
                    u32 chosenTargetIndex = DungeonRandInt(gAIThrowItemActionChoiceCount);
                    SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                    pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                    pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
                    pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                    pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                    pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
                    if (GetItemAIFlag(item->id, ITEM_AI_FLAG_TARGET_SELF))
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
                                pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                                pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
                    if (GetItemAIFlag(item->id, thrownAIFlag))
                    {
                        u8 itemType = GetItemCategory(item->id);
                        if (itemType == CATEGORY_THROWN_ARC)
                        {
                            Position potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                            GetPossibleAIArcItemTargets(pokemon, item, potentialTargetPositions, FALSE);
                            if (gAIThrowItemActionChoiceCount != 0)
                            {
                                u32 chosenTargetIndex = DungeonRandInt(gAIThrowItemActionChoiceCount);
                                SetMonsterActionFields(&pokemonInfo->action, ACTION_THROW_ITEM_AI);
                                pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                                pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                                pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
                                    pokemonInfo->action.unk4[0].actionUseIndex = selectedToolboxIndex;
                                    pokemonInfo->action.unk4[0].lastItemThrowPosition.x = pokemon->pos.x;
                                    pokemonInfo->action.unk4[0].lastItemThrowPosition.y = pokemon->pos.y;
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
        Entity *targetPokemon = gDungeon->allPokemon[i];
        if (EntityExists(targetPokemon) && pokemon != targetPokemon)
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

void GetPossibleAIArcItemTargets(Entity *pokemon, Item *item, Position potentialTargets[], bool8 ignoreRollChance)
{
    s32 i;
    gAIThrowItemActionChoiceCount = 0;
    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
    {
        Entity *targetPokemon = gDungeon->allPokemon[i];
        if (EntityExists(targetPokemon) && pokemon != targetPokemon &&
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
                Position *newPotentialTarget;
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
    if (pokemon->axObj.info->itemStatus.itemStatus == STATUS_NONE)
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
