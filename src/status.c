#include "global.h"
#include "status.h"

#include "constants/ability.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"

u8 GetFlashFireStatus(struct DungeonEntity *pokemon)
{
    if (!EntityExists(pokemon) || !HasAbility(pokemon, ABILITY_FLASH_FIRE))
    {
        return FLASH_FIRE_STATUS_NONE;
    }
    if (pokemon->entityData->flashFireBoost > 1)
    {
        return FLASH_FIRE_STATUS_MAXED;
    }
    return FLASH_FIRE_STATUS_NOT_MAXED;
}
