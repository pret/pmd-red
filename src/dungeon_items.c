#include "global.h"
#include "dungeon_items.h"

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
