#include "global.h"
#include "pokemon.h"
#include "dungeon_util.h"
#include "code_8069D4C.h"

u32 sub_8069D18(DungeonPos *pos,Entity *entity)
{
    EntityInfo *info;

    info = GetEntInfo(entity);

    pos->x = (entity->pos).x + gAdjacentTileOffsets[(info->action).direction].x;
    pos->y = (entity->pos).y + gAdjacentTileOffsets[(info->action).direction].y;
    return info->action.direction & 1;
}

void sub_8069D4C(struct unkStruct_8069D4C *r0, Entity *target)
{
    EntityInfo *info;
    LevelData leveldata;

    info = GetEntInfo(target);

    r0->id = info->id;
    r0->pos = target->pos;

    if(info->bossFlag)
        r0->HP = info->originalHP;
    else
        r0->HP = info->maxHPStat;

    r0->level = info->level;

    GetPokemonLevelData(&leveldata, info->id, info->level);
    r0->exp = leveldata.expRequired;
    r0->offense.att[0] = info->atk[0];
    r0->offense.att[1] = info->atk[1];
    r0->offense.def[0] = info->def[0];
    r0->offense.def[1] = info->def[1];
    r0->heldItem = info->heldItem;
    memcpy(r0->moves.moves, info->moves.moves, sizeof(r0->moves));
    r0->belly = info->belly;
    r0->maxBelly = info->maxBelly;
    r0->hiddenPower = info->hiddenPower;
}
