#include "global.h"
#include "targeting_flags.h"

#include "constants/move_id.h"
#include "constants/type.h"
#include "dungeon_pokemon_attributes.h"
#include "moves.h"

s16 GetMoveTargetAndRangeForPokemon(struct Entity *pokemon, struct Move *move, bool32 isAI)
{
    if (move->id == MOVE_CURSE && !isAI && !MonsterIsType(pokemon, TYPE_GHOST))
    {
        return TARGETING_FLAG_BOOST_SELF | TARGETING_FLAG_TARGET_SELF;
    }
    return GetMoveTargetAndRange(move, isAI);
}
