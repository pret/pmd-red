#include "global.h"
#include "dungeon_ai_items.h"

#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "dungeon_capabilities.h"
#include "dungeon_capabilities_1.h"
#include "dungeon_global_data.h"
#include "item.h"
#include "team_inventory.h"

#define NUM_POTENTIAL_ROCK_TARGETS 20
#define GROUND_ITEM_TOOLBOX_INDEX 0x80
#define HELD_ITEM_TOOLBOX_INDEX 0x81
#define ITEM_TARGET_ALLY 1 << 1

extern void SetAction(u16*, u16);
extern void FindStraightThrowableTargets(struct DungeonEntity*, s32 thrownAIFlag, struct ItemSlot*, bool8 ignoreRollChance);
extern bool8 RollPercentChance(u32);
extern void FindRockItemTargets(struct DungeonEntity*, struct ItemSlot*, s16*[], bool8 ignoreRollChance);
extern s32 DungeonRandomCapped(s32);
extern s32 CalculateFacingDir(s16*, s16*);
extern bool8 HasIQSkill(struct DungeonEntity*, u8);
extern struct MapTile* GetMapTileAtPosition(s16, s16);
extern u32 GetEntityType(struct DungeonEntity*);
extern struct ItemSlot* GetItemData(struct DungeonEntity*);
extern u32 EvaluateItem(struct DungeonEntity*, struct ItemSlot*, u8);
extern bool8 ToolboxEnabled(struct DungeonEntityData*);

extern s32 gNumPotentialTargets;
extern u32 gPotentialTargetWeights[NUM_DIRECTIONS];
extern u32 gPotentialTargetDirections[NUM_DIRECTIONS];
extern struct TeamInventory *gTeamInventory_203B460;

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
                    if (RollPercentChance(gPotentialTargetWeights[targetIndex]))
                    {
                        SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                        pokemonData->actionUseIndex = selectedToolboxIndex;
                        pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                        pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
                        pokemonData->facingDir = gPotentialTargetDirections[targetIndex] & DIRECTION_MASK;
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
                s16 *potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                FindRockItemTargets(pokemon, item, potentialTargetPositions, TRUE);
                if (gNumPotentialTargets == 0)
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_HAVE_SECOND_THOUGHTS);
                }
                else
                {
                    u32 chosenTargetIndex = DungeonRandomCapped(gNumPotentialTargets);
                    SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                    pokemonData->actionUseIndex = selectedToolboxIndex;
                    pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                    pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
                    pokemonData->facingDir = CalculateFacingDir(&pokemon->posWorldX, (s16 *) (&potentialTargetPositions[chosenTargetIndex])) & DIRECTION_MASK;
                    pokemonData->itemTargetPosition = potentialTargetPositions[chosenTargetIndex];
                }
            }
            else
            {
                u8 itemTypeCompare = itemType - 2;
                if (itemTypeCompare < ITEM_TYPE_HOLD_ITEM - 2)
                {
                    SetAction(&pokemonData->action, DUNGEON_ACTION_CONSUME_ITEM_AI);
                    pokemonData->actionUseIndex = selectedToolboxIndex;
                    pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                    pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
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
                struct MapTile *mapTile = GetMapTileAtPosition(pokemon->posWorldX, pokemon->posWorldY);
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
                                pokemonData->actionUseIndex = selectedToolboxIndex;
                                pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                                pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
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
                    potentialTargetWeights = gPotentialTargetWeights;
                    if (GetItemAIFlag(item->itemIndex, thrownAIFlag))
                    {
                        u8 itemType = GetItemType(item->itemIndex);
                        if (itemType == ITEM_TYPE_ROCK)
                        {
                            s16 *potentialTargetPositions[NUM_POTENTIAL_ROCK_TARGETS];
                            FindRockItemTargets(pokemon, item, potentialTargetPositions, FALSE);
                            if (gNumPotentialTargets != 0)
                            {
                                u32 chosenTargetIndex = DungeonRandomCapped(gNumPotentialTargets);
                                SetAction(&pokemonData->action, DUNGEON_ACTION_THROW_ITEM_AI);
                                pokemonData->actionUseIndex = selectedToolboxIndex;
                                pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                                pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
                                pokemonData->facingDir = CalculateFacingDir(&pokemon->posWorldX, (s16 *) (&potentialTargetPositions[chosenTargetIndex])) & DIRECTION_MASK;
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
                                    pokemonData->actionUseIndex = selectedToolboxIndex;
                                    pokemonData->lastItemThrowPositionX = pokemon->posWorldX;
                                    pokemonData->lastItemThrowPositionY = pokemon->posWorldY;
                                    pokemonData->facingDir = gPotentialTargetDirections[targetIndex] & DIRECTION_MASK;
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
