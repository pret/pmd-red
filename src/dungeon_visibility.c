#include "global.h"
#include "dungeon_visibility.h"

#include "constants/status.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_range.h"
#include "dungeon_util.h"

extern bool8 InSameRoom_3(struct Position *pos1, struct Position *pos2);

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

bool8 CanSee_2(struct DungeonEntity *entity, struct DungeonEntity *targetEntity)
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
    return InSameRoom_3(&entity->posWorld, &targetEntity->posWorld);
}

bool8 sub_8045A70(struct DungeonEntity *entity, struct DungeonEntity *targetEntity)
{
    if (EntityExists(entity) && EntityExists(targetEntity) && targetEntity->visible)
    {
         return InSameRoom_2(&entity->posWorld, &targetEntity->posWorld);
    }
   return FALSE;
}

bool8 sub_8045AAC(struct DungeonEntity *entity, struct Position *pos)
{
    return InSameRoom_2(&entity->posWorld, pos);
}

bool8 InSameRoom(struct DungeonEntity *entity, struct Position *pos)
{
    return InSameRoom_3(&entity->posWorld, pos);
}

