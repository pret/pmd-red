#include "global.h"
#include "targeting_flags.h"

#include "constants/move_id.h"
#include "constants/type.h"
#include "dungeon_pokemon_attributes.h"
#include "moves.h"

s16 GetMoveTargetingFlagsForPokemon(struct DungeonEntity *pokemon, struct PokemonMove *move, u32 isAI)
{
    if (move->moveID == MOVE_CURSE && !isAI && !HasType(pokemon, TYPE_GHOST))
    {
        return TARGETING_FLAG_BOOST_SELF | TARGETING_FLAG_TARGET_SELF;
    }
    return GetMoveTargetingFlags(move, isAI);
}
