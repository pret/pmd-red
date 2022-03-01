#include "global.h"
#include "status_checker_1.h"

#include "dungeon_entity.h"

bool8 HasLastUsedMove(struct PokemonMove *moves)
{
    s32 i;
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags & MOVE_FLAG_LAST_USED)
        {
            return TRUE;
        }
    }
    if (moves[STRUGGLE_MOVE_INDEX].moveFlags & MOVE_FLAG_LAST_USED)
    {
        return TRUE;
    }
    return FALSE;
}
