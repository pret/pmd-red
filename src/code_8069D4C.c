#include "global.h"
#include "pokemon_mid.h"
#include "dungeon_util.h"
#include "code_8069D4C.h"

u32 sub_8069D18(Position *pos,Entity *entity)
{
    EntityInfo *info;

    info = entity->axObj.info;

    pos->x = (entity->pos).x + gAdjacentTileOffsets[(info->action).direction].x;
    pos->y = (entity->pos).y + gAdjacentTileOffsets[(info->action).direction].y;
    return info->action.direction & 1;
}

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target)
{
    EntityInfo *info;
    LevelData leveldata;

    info = target->axObj.info;

    r0->id = info->id;
    r0->pos = target->pos;

    if(info->bossFlag)
        r0->HP = info->originalHP;
    else
        r0->HP = info->maxHPStat;

    r0->level = info->level;


    GetPokemonLevelData(&leveldata, info->id, info->level);
    r0->exp = leveldata.expRequired;
    r0->atk = info->atk;
    r0->spAtk = info->spAtk;
    r0->def = info->def;
    r0->spDef = info->spDef;
    r0->heldItem = info->heldItem;
    memcpy(r0->moves, info->moves, sizeof(r0->moves) + sizeof(r0->unk40));
    r0->belly = info->belly;
    r0->maxBelly = info->maxBelly;
    r0->hiddenPower = info->hiddenPower;
}
