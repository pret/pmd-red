#include "global.h"
#include "dungeon_visibility.h"

#include "constants/status.h"
#include "dungeon_pokemon_attributes_1.h"
#include "dungeon_range.h"
#include "dungeon_util.h"

bool8 CanSee(struct DungeonEntity *entity, struct DungeonEntity *targetEntity)
{
    if (!EntityExists(entity) || !EntityExists(targetEntity) || !targetEntity->visible)
    {
        return FALSE;
    }
    if (targetEntity->entityType == ENTITY_POKEMON)
    {
        if (entity->entityType == ENTITY_POKEMON)
        {
            if (!CanSeeInvisible(entity) && targetEntity->entityData->transformStatus == TRANSFORM_STATUS_INVISIBLE)
            {
                return FALSE;
            }
            if (entity->entityData->eyesightStatus == EYESIGHT_STATUS_BLINKER)
            {
                return FALSE;
            }
        }
        else if (targetEntity->entityData->transformStatus == TRANSFORM_STATUS_INVISIBLE)
        {
            return FALSE;
        }
    }
    return InSameRoom_2(&entity->posWorld, &targetEntity->posWorld);
}
