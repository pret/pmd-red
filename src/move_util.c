#include "global.h"
#include "move_util.h"

extern bool8 IsMoveUsable(struct DungeonEntity *pokemon, struct PokemonMove *move, bool8 hasPPChecker);

bool8 IsMoveIndexUsable(struct DungeonEntity *pokemon, s32 moveIndex, bool8 hasPPChecker)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct PokemonMove *move = &pokemonData->moves[moveIndex];
    s32 i;
    if (!(move->moveFlags & MOVE_FLAG_EXISTS))
    {
        return FALSE;
    }
    if (move->moveFlags & MOVE_FLAG_LINKED)
    {
        return FALSE;
    }
    if (move->moveFlags & MOVE_FLAG_DISABLED ||
        move->moveFlags2 & MOVE_FLAG_SEALED)
    {
        return FALSE;
    }
    goto initMoveIndex;
    returnTrue:
    return TRUE;
    initMoveIndex:
    i = 0;
    goto checkMoveUsable;
    incMoveIndex:
    i++;
    checkMoveUsable:
    if (i >= MAX_MON_MOVES)
    {
        return FALSE;
    }
    if (IsMoveUsable(pokemon, move, hasPPChecker))
    {
        goto returnTrue;
    }
    move++;
    if ((u32) move >= (u32) &pokemonData->struggleMoveFlags || !(move->moveFlags & MOVE_FLAG_LINKED))
    {
        return FALSE;
    }
    goto incMoveIndex;
}
