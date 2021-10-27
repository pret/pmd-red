#include "global.h"
#include "dungeon_capabilities.h"
#include "constants/dungeon.h"

extern bool8 ShouldAvoidEnemies(struct DungeonEntity*);
extern bool8 CannotMove(struct DungeonEntity*, bool8);
extern bool8 CannotAct(struct DungeonEntity*);
extern bool8 IsCharging(struct DungeonEntity*, bool8);

static inline bool8 JoinLocationCannotUseItems(struct DungeonEntityData *pokemonData)
{
    if (pokemonData->joinLocation == DUNGEON_JOIN_LOCATION_CLIENT_POKEMON)
    {
        return TRUE;
    }
    if (pokemonData->joinLocation == DUNGEON_RESCUE_TEAM_BASE)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 CannotUseItems(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    if (pokemonData->clientType == CLIENT_TYPE_CLIENT
        || JoinLocationCannotUseItems(pokemonData)
        || (!pokemonData->isLeader && ShouldAvoidEnemies(pokemon))
        || CannotMove(pokemon, FALSE)
        || CannotAct(pokemon))
    {
        return TRUE;
    }
    if (IsCharging(pokemon, FALSE))
    {
        return TRUE;
    }
    return FALSE;
}
