#include "global.h"
#include "dungeon_ai_attack.h"

#include "constants/iq_skill.h"
#include "dungeon_global_data.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_util.h"

bool8 IsTargetStraightAhead(struct DungeonEntity *pokemon, struct DungeonEntity *targetPokemon, s32 facingDir, s32 maxRange)
{
    s32 posDiffX = pokemon->posWorld.x - targetPokemon->posWorld.x;
    s32 effectiveMaxRange;
    if (posDiffX < 0)
    {
        posDiffX = -posDiffX;
    }
    effectiveMaxRange = pokemon->posWorld.y - targetPokemon->posWorld.y;
    if (effectiveMaxRange < 0)
    {
        effectiveMaxRange = -effectiveMaxRange;
    }
    if (effectiveMaxRange < posDiffX)
    {
        effectiveMaxRange = posDiffX;
    }
    if (effectiveMaxRange > maxRange)
    {
        effectiveMaxRange = maxRange;
    }
    if (!HasIQSkill(pokemon, IQ_SKILL_COURSE_CHECKER))
    {
        // BUG: effectiveMaxRange is already capped at maxRange, so this condition always evaluates to TRUE.
        // The AI also has range checks elsewhere, so this doesn't become an issue in most cases.
        // If the AI has the Long Toss or Pierce statuses and Course Checker is disabled,
        // this incorrect check causes the AI to throw items at targets further than 10 tiles away.
        if (effectiveMaxRange <= maxRange)
        {
            return TRUE;
        }
    }
    else
    {
        s32 currentPosX = pokemon->posWorld.x;
        s32 currentPosY = pokemon->posWorld.y;
        s32 adjacentTileOffsetX = gAdjacentTileOffsets[facingDir].x;
        s32 adjacentTileOffsetY = gAdjacentTileOffsets[facingDir].y;
        s32 i;
        for (i = 0; i <= effectiveMaxRange; i++)
        {
            struct MapTile *mapTile;
            currentPosX += adjacentTileOffsetX;
            currentPosY += adjacentTileOffsetY;
            if (currentPosX <= 0 || currentPosY <= 0 ||
                currentPosX >= DUNGEON_MAX_SIZE_X - 1 || currentPosY >= DUNGEON_MAX_SIZE_Y - 1)
            {
                break;
            }
            while (0); // Extra label needed to swap branch locations in ASM.
            mapTile = GetMapTileAtPosition(currentPosX, currentPosY);
            if (!(mapTile->tileType & (TILE_TYPE_FLOOR | TILE_TYPE_LIQUID)))
            {
                break;
            }
            if (mapTile->pokemon == targetPokemon)
            {
                return TRUE;
            }
            if (mapTile->pokemon != NULL)
            {
                break;
            }
        }
    }
    return FALSE;
}
