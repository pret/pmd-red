#include "global.h"
#include "pokemon_mid.h"
#include "dungeon_util.h"
#include "structs/struct_8069D4C.h"

u32 sub_8069D18(Position *pos,Entity *entity)
{
    EntityInfo *info;

    info = entity->info;

    pos->x = (entity->pos).x + gAdjacentTileOffsets[(info->action).direction].x;
    pos->y = (entity->pos).y + gAdjacentTileOffsets[(info->action).direction].y;
    return info->action.direction & 1;
}

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target)
{
    EntityInfo *info;
    LevelData leveldata;

    info = target->info;

    r0->id = info->id;
    r0->pos = target->pos;

    if(info->bossFlag)
        r0->HP = info->originalHP;
    else
        r0->HP = info->maxHPStat;

    r0->level = info->level;

    GetPokemonLevelData(&leveldata, info->id, info->level);
    r0->exp = leveldata.expRequired;
    r0->att[0] = info->atk;
    r0->att[1] = info->spAtk;
    r0->def[0] = info->def;
    r0->def[1] = info->spDef;
    r0->heldItem = info->heldItem;
    memcpy(r0->moves.moves, info->moves, sizeof(r0->moves));
    r0->belly = info->belly;
    r0->maxBelly = info->maxBelly;
    r0->hiddenPower = info->hiddenPower;
}
