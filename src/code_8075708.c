#include "global.h"
#include "dungeon_ai.h"

#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "code_806CD90.h"
#include "dungeon_capabilities.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "dungeon_visibility.h"
#include "structs/str_dungeon.h"
#include "tile_types.h"
#include "position_util.h"
#include "trap.h"

extern void sub_8049ED4(void);
extern void sub_8073D14(Entity *);

void sub_8075680(void)
{
    u32 direction;
    Position *targetPos;
    Entity *entity;
    EntityInfo *info;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if ((EntityExists(entity)) && (info = entity->axObj.info, !info->isTeamLeader)) {
            targetPos = &(info->targetPos);

            if (targetPos->x == 0 && targetPos->y == 0)
                continue;

            if (targetPos->x == entity->pos.x && targetPos->y == entity->pos.y)
                continue;

            if (CheckVariousStatuses2(entity, TRUE))
                continue;

            direction = GetDirectionTowardsPosition(&entity->pos, targetPos);
            info->action.direction = direction & DIRECTION_MASK;
            sub_806CDD4(entity, sub_806CEBC(entity), direction);
        }
    }
}

void nullsub_97(Entity *entity)
{}

void sub_8075708(Entity *entity)
{
    bool8 bVar1;
    bool8 bVar2;
    Tile *tile;
    Trap *trapData;
    Entity *trap;
    EntityInfo *info;

    info = entity->axObj.info;
    if (!EntityExists(entity)) {
        return;
    }
    tile = GetTileAtEntitySafe(entity);
    if (((IQSkillIsEnabled(entity, IQ_SUPER_MOBILE)) && (info->transformStatus.transformStatus != STATUS_MOBILE)) &&
        (!HasHeldItem(entity, ITEM_MOBILE_SCARF))) {
        sub_804AE84(&entity->pos);
    }
    trap = tile->object;
    if (trap == NULL) {
        return;
    }

    switch(GetEntityType(trap)) {
        case ENTITY_TRAP:
            trapData = GetTrapData(trap);
            bVar1 = FALSE;
            bVar2 = FALSE;
            if ((IQSkillIsEnabled(entity, IQ_TRAP_SEER)) && (!trap->isVisible)) {
                trap->isVisible = TRUE;
                sub_8049ED4();
                bVar2 = TRUE;
            }

            if (trapData->unk1 == 0) {
                if (!trap->isVisible) goto _080757EC;
                if (info->isNotTeamMember) goto _080757EC;
            }
            else {
                if (trapData->unk1 == 1) {
                    if (!info->isNotTeamMember) goto _080757EC;
                    goto _ret;
                }
                if ((trapData->unk1 == 2) && (!info->isNotTeamMember)) {
                    bVar1 = TRUE;
                }
            _080757EC:
                if (!bVar1) {
                    return;
                }
            }
        _ret:
            if (!bVar2) {
                sub_807FE9C(entity, &entity->pos, 0, 1);
            }
            break;
        case ENTITY_ITEM:
            sub_8073D14(entity);
            break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
    }
}

u32 sub_8075818(Entity *entity)
{
    struct Tile *tile;
    EntityInfo *entityInfo;
    Entity *subEntity;
    Item *item;
    Trap *trapData; // TODO: turn into struct when more research is done..
    u8 r1;

    entityInfo = entity->axObj.info;
    if(EntityExists(entity))
    {
        tile = GetTileAtEntitySafe(entity);
        if(IQSkillIsEnabled(entity, IQ_SUPER_MOBILE))
            if(!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                return 1;
        subEntity = tile->object;
        if(subEntity != NULL)
        {
            switch(GetEntityType(subEntity))
            {
                case ENTITY_NOTHING:
                case ENTITY_MONSTER:
                case ENTITY_UNK_4:
                case ENTITY_UNK_5:
                    break;
                case ENTITY_TRAP:
                    trapData = GetTrapData(subEntity);
                    r1 = 0;
                    if(trapData->unk1 == 0)
                    {
                        if(!subEntity->isVisible || entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData->unk1 == 1)
                    {
                        if(!entityInfo->isNotTeamMember)
                            goto flag_check;
                        else
                            goto error;
                    }
                    else if(trapData->unk1 == 2)
                    {
                        if(!entityInfo->isNotTeamMember)
                            r1 = 1;
                    }
flag_check:
                    if(r1 == 0)
                        break;
                    else
                        goto error;
                case ENTITY_ITEM:
                    if(!entityInfo->isTeamLeader)
                    {
                        if(!(entityInfo->heldItem.flags & ITEM_FLAG_EXISTS))
                        {
                            if(!(tile->terrainType & (TERRAIN_TYPE_NORMAL | TERRAIN_TYPE_SECONDARY)))
                            {
                                if(entityInfo->isNotTeamMember)
                                    break;
                                else
                                {
                                    item = GetItemData(subEntity);
                                    if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                    {
                                        return 1;
                                    }
                                }
                            }
                            else
                            {
                                item = GetItemData(subEntity);
                                if(!(item->flags & ITEM_FLAG_IN_SHOP))
                                {
error:
                                    return 1;
                                }
                            }
                        }
                    }
                    break;
            }
        }
    }
    return 0;
}

