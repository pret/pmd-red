#include "global.h"
#include "constants/status.h"
#include "code_806CD90.h"
#include "code_8077274_1.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "move_effects_target.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "dungeon_util.h"
#include "status_checks_1.h"
#include "code_8069D4C.h"

extern u8 gUnknown_810AC60; // 0xC
extern u8 gUnknown_810AC62; // 0xC
extern u8 gUnknown_810AC68; // 0x8
extern u8 gUnknown_810AC64; // 0x8
extern u8 gUnknown_810AC66; // 0x8
extern DungeonPos gPlayerDotMapPosition;
extern DungeonPos gUnknown_202EE0C;
s32 sub_806A4DC(EntityInfo *info);
bool8 sub_8070F80(Entity * pokemon, s32 direction);
void sub_80402AC(s32, s32);

void sub_80694C0(Entity *target,s32 x,int y,char param_4)
{
    Tile *tile;
    Tile *tile2;
    EntityInfo *info;

    tile = GetTileMut(x,y);
    info = GetEntInfo(target);

    if (info->frozenClassStatus.status == STATUS_WRAP || info->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(info->unk9C);
    }
    if (info->frozenClassStatus.status == STATUS_CONSTRICTION || info->frozenClassStatus.status == STATUS_INGRAIN || info->frozenClassStatus.status == STATUS_SHADOW_HOLD) {
        EndFrozenClassStatus(target,target);
    }
    if ((x != (target->pos).x) || (y != (target->pos).y)) {
        if ((0 <= (target->pos).x) && (0 <= (target->pos).y)) {
            tile2 = GetTileMut((target->pos).x,(target->pos).y);
            if (tile2->monster == target) {
                tile2->monster = NULL;
            }
            sub_80402AC((target->pos).x,(target->pos).y);
        }
        (target->prevPos).x = (target->pos).x;
        (target->prevPos).y = (target->pos).y;
        (target->pos).x = x;
        (target->pos).y = y;
        if (info->isTeamLeader) {
            gPlayerDotMapPosition.x = x;
            gPlayerDotMapPosition.y = y;
        }
        tile->monster = target;
        if (info->isTeamLeader) {
            gUnknown_202EE0C.x = x;
            gUnknown_202EE0C.y = y;
            gDungeon->unk1 = 0;
        }
        sub_80402AC(x,y);

        switch(param_4)
        {
            case 0:
                info->prevPos[3] = info->prevPos[2];
                info->prevPos[2] = info->prevPos[1];
                info->prevPos[1] = info->prevPos[0];
                if (info->invisibleClassStatus.status != 1) {
                    info->prevPos[0] = target->prevPos;
                }
                break;
            case 1:
                info->prevPos[0] = target->pos;
                info->prevPos[1] = info->prevPos[0];
                info->prevPos[2] = info->prevPos[0];
                info->prevPos[3] = info->prevPos[0];
                break;
        }
        target->room = tile->room;
        sub_806CF98(target);
    }
    return;
}

void sub_80695EC(Entity *param_1,int x,int y)
{
    EntityInfo *info;

    info = GetEntInfo(param_1);
    if (info->frozenClassStatus.status == STATUS_WRAP || info->frozenClassStatus.status == STATUS_WRAPPED) {
        sub_8076CB4(info->unk9C);
    }
    if ((x != (param_1->pos).x) || (y != (param_1->pos).y)) {
        param_1->prevPos.x = param_1->pos.x;
        param_1->prevPos.y = param_1->pos.y;
        param_1->pos.x = x;
        param_1->pos.y = y;
        info->prevPos[3] = info->prevPos[2];
        info->prevPos[2] = info->prevPos[1];
        info->prevPos[1] = info->prevPos[0];
        if (info->invisibleClassStatus.status != 1) {
            info->prevPos[0] = param_1->prevPos;
        }
        param_1->room = GetTile(x,y)->room;
    }
}

Entity * sub_8069660(Entity *target)
{
    const Tile *tile;

    EntityInfo *info;

    info = GetEntInfo(target);

    if(sub_8070F80(target, info->action.direction))
    {
        tile = GetTile((target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x,(target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y);
        return tile->monster;
    }
    return NULL;
}

Entity * sub_80696A8(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    EntityInfo *info;

    info = GetEntInfo(target);

    if(CanAttackInDirection(target, info->action.direction))
    {
        tile = GetTile((target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x,(target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y);
        if (((entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
            return entity;
        }
    }
    return NULL;
}


Entity * sub_80696FC(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    DungeonPos pos;
    EntityInfo *info;

    info = GetEntInfo(target);

    pos.x = (target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x;
    pos.y =  (target->pos).y + (gAdjacentTileOffsets)[info->action.direction].y;
    tile = GetTile(pos.x,pos.y);
    if (((!sub_80705F0(target,&pos)) && (entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
        return entity;
    }
    return NULL;
}

Entity * sub_806977C(Entity *target)
{
    const Tile *tile;
    Entity *entity;

    DungeonPos pos;
    EntityInfo *info;

    info = GetEntInfo(target);

    pos.x = (target->pos).x + (gAdjacentTileOffsets)[info->action.direction].x;
    pos.y =  (target->pos).y + ((gAdjacentTileOffsets)[info->action.direction].y);
    GetTile(pos.x,(int)pos.y);
    if (!sub_80705F0(target,&pos)) {
        pos.x = (gAdjacentTileOffsets)[info->action.direction].x * 2 + (target->pos).x;
        pos.y = (gAdjacentTileOffsets)[info->action.direction].y * 2 + (target->pos).y;
        tile = GetTile(pos.x,pos.y);
        if (((!sub_80705F0(target,&pos)) && (entity = tile->monster, entity != NULL)) && (entity->type == ENTITY_MONSTER)) {
            return entity;
        }
    }
    return NULL;
}

void sub_8069844(struct unkStruct_808FF20 *param_1, Entity *target) {
    int index;
    u8 *atkPtr;
    u8 *spAtkPtr;
    u8 *defPtr;
    s32 uVar15;
    u8 *spDefBoost;

    EntityInfo *info = GetEntInfo(target);

    SetMessageArgument_2(param_1->nameBuffer, info, 0);
    param_1->species = info->id;
    param_1->HP1 = info->HP;
    param_1->HP2 = info->maxHPStat;
    param_1->level = info->level;
    param_1->exp = info->exp;
    for(index = 0; index < 2; index++)
    {
        (param_1->offense).att[index] = info->atk[index];
        (param_1->offense).def[index] = info->def[index];
        param_1->types[index] = info->types[index];
        param_1->abilities[index] = info->abilities[index];
    }
    param_1->isTeamLeader = info->isTeamLeader;
    atkPtr = &param_1->atkBoost;
    *atkPtr = 0;
    spAtkPtr = &param_1->spAtkBoost;
    *spAtkPtr = 0;
    defPtr = &param_1->defBoost;
    *defPtr = 0;
    spDefBoost = &param_1->spDefBoost;
    *spDefBoost = 0;
    if ((info->heldItem.flags & ITEM_FLAG_EXISTS) && ((info->heldItem.flags & ITEM_FLAG_STICKY) == 0)) {
        if (info->heldItem.id == ITEM_POWER_BAND) {
            *atkPtr += gUnknown_810AC60;
        }
        if (info->heldItem.id == ITEM_MUNCH_BELT) {
            *atkPtr += gUnknown_810AC68;
        }
        if (info->heldItem.id == ITEM_SPECIAL_BAND) {
            *spAtkPtr += gUnknown_810AC62;
        }
        if (info->heldItem.id == ITEM_MUNCH_BELT) {
            *spAtkPtr += gUnknown_810AC68;
        }
        if (info->heldItem.id == ITEM_DEF_SCARF) {
            *defPtr += gUnknown_810AC64;
        }
        if (info->heldItem.id == ITEM_ZINC_BAND) {
            *spDefBoost += gUnknown_810AC66;
        }
    }
    param_1->tactic = info->tactic;
    param_1->item = info->heldItem;
    param_1->IQ = info->IQ;
    (param_1->dungeonLocation) = info->joinedAt;
    param_1->unk44[0].level = 0;
    param_1->unk44[1].level = 0;
    param_1->IQSkills = info->IQSkillMenuFlags;
    if (gDungeon->unk644.unk16 != 0) {
        param_1->unk4C = sub_806A4DC(info);
    }
    else {
        param_1->unk4C = 3;
    }

    uVar15 = 0;
    if (info->HP <= info->maxHPStat / 4) {
        param_1->unk58[0] = 6;
        uVar15 = 1;
    }

    if (gDungeon->unk644.itemHoldersIdentified) {
        param_1->unk58[uVar15] = 11;
        uVar15++;
    }
    if (FixedPointToInt(info->belly) == 0) {
        if (info->isTeamLeader) {
            param_1->unk58[uVar15] = 19;
        }
        else {
            param_1->unk58[uVar15] = 59;
        }

        uVar15++;
    }
    if (GetEntInfo(target)->speedStage > 1) {
        param_1->unk58[uVar15] = 27;
        uVar15++;
    }
    if (GetEntInfo(target)->speedStage < 1) {
        param_1->unk58[uVar15] = 40;
        uVar15++;
    }
    if ((((((info->offensiveMultipliers[0].raw < 0x100) || (info->offensiveMultipliers[1].raw < 0x100)
    ) || (info->defensiveMultipliers[0].raw < 0x100)) ||
        ((info->defensiveMultipliers[1].raw < 0x100 || (info->offensiveStages[0] < 10)))) ||
        ((info->offensiveStages[1] < 10 ||
        ((info->defensiveStages[0] < 10 || (info->defensiveStages[1] < 10)))))) ||
        ((info->hitChanceStages[0] < 10 || (info->hitChanceStages[1] < 10)))) {
        param_1->unk58[uVar15] = 55;
        uVar15++;
    }
    if (((info->sleepClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->sleepClassStatus).status;
        uVar15++;
    }
    if (((info->burnClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->burnClassStatus).status + 6;
        uVar15++;
    }
    if (((info->frozenClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->frozenClassStatus).status + 11;
        uVar15++;
    }
    if (((info->cringeClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->cringeClassStatus).status + 19;
        uVar15++;
    }
    if (((info->bideClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->bideClassStatus).status + 27;
        uVar15++;
    }
    if (((info->reflectClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->reflectClassStatus).status + 40;
        uVar15++;
    }
    if (((info->curseClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->curseClassStatus).status + 55;
        uVar15++;
    }
    if (((info->leechSeedClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = (info->leechSeedClassStatus).status + 59;
        uVar15++;
    }
    if (((info->sureShotClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->sureShotClassStatus.status + 62;
        uVar15++;
    }
    if (((info->longTossClassStatus).status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->longTossClassStatus.status + 67;
        uVar15++;
    }
    if ((info->invisibleClassStatus.status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->invisibleClassStatus.status + 70;
        uVar15++;
    }
    if ((info->blinkerClassStatus.status != STATUS_NONE) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->blinkerClassStatus.status + 74;
        uVar15++;
    }
    if ((info->muzzled.muzzled) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = info->muzzled.muzzled + 78;
        uVar15++;
    }
    if ((info->stockpileStage != 0) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 80;
        uVar15++;
    }
    if ((info->powerEars) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 81;
        uVar15++;
    }
    if ((info->scanning) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 82;
        uVar15++;
    }
    if ((info->grudge) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 83;
        uVar15++;
    }
    if ((info->exposed) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 84;
        uVar15++;
    }
    if ((ShouldMonsterRunAway(target)) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 85;
        uVar15++;
    }
    if ((info->perishSongTurns != 0) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 86;
        uVar15++;
    }
    if ((1 < sub_8070828(target,FALSE)) && (uVar15 < 0xc)) {
        param_1->unk58[uVar15] = 87;
        uVar15++;
    }
    if (info->stairSpotter) {
        if (0xb < uVar15) {
            return;
        }
        param_1->unk58[uVar15] = 88;
        uVar15++;
    }

    for(; uVar15 < 0xC; uVar15++)
    {
        param_1->unk58[uVar15] = 0;
    }
    return;
}

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
