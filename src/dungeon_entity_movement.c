#include "global.h"
#include "globaldata.h"
#include "dungeon_entity_movement.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_items.h"
#include "dungeon_range.h"
#include "dungeon_map_access.h"
#include "dungeon_logic.h"
#include "dungeon_util.h"
#include "structs/str_dungeon.h"
#include "position_util.h"
#include "trap.h"
#include "items.h"
#include "weather.h"
#include "structs/dungeon_entity.h"
#include "structs/map.h"
#include "structs/str_moves.h"
#include "position_util.h"
#include "dungeon_music.h"
#include "dungeon_map_access.h"
#include "dungeon_vram.h"
#include "dungeon_mon_sprite_render.h"
#include "game_options.h"
#include "dungeon_items.h"
#include "moves.h"
#include "dungeon_random.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/ability.h"
#include "constants/type.h"
#include "constants/move_id.h"
#include "constants/weather.h"
#include "number_util.h"
#include "dungeon_message.h"
#include "math.h"
#include "dungeon_config.h"
#include "dungeon_engine.h"
#include "dungeon_kecleon_shop.h"
#include "dungeon_misc.h"
#include "dungeon_pos_data.h"
#include "dungeon_turn_effects.h"
#include "dungeon_leveling.h"
#include "dungeon_cutscene.h"
#include "dungeon_monster_house.h"
#include "dungeon_strings.h"
#include "dungeon_main.h"
#include "warp_target.h"
#include "dungeon_action_execution.h"
#include "dungeon_tilemap.h"
#include "run_dungeon.h"
#include "dungeon_8041AD0.h"
#include "dungeon_ai_items.h"

static EWRAM_DATA s32 sSpeedMultiplier = 0;

static void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr);
static void nullsub_97(Entity *entity);
static void TryInteractWithTile(Entity *entity);

static inline void SetSpeedMultiplier(void)
{
    if (gGameOptionsRef->dungeonSpeed != 0)
        sSpeedMultiplier = 2;
    else
        sSpeedMultiplier = 1;
}

void sub_8074FB0(Entity *entity, s32 a1, DungeonPos *pos)
{
    Unk_Entity_x184 *strPtr;
    EntityInfo *entityInfo = GetEntInfo(entity);

    if (entityInfo->numMoveTiles > 3) {
        entityInfo->action.action = 0;
        return;
    }
    SetSpeedMultiplier();

    strPtr = &entityInfo->unk184[entityInfo->numMoveTiles];
    strPtr->unk1A = 0;
    strPtr->lastMoveDirection = a1;
    strPtr->previousTargetMovePosition1.x = entity->pos.x;
    strPtr->previousTargetMovePosition1.y = entity->pos.y;
    strPtr->previousTargetMovePosition2.x = pos->x;
    strPtr->previousTargetMovePosition2.y = pos->y;
    strPtr->lastMoveIncrement.x = gUnknown_80F4D44[a1].x * sSpeedMultiplier;
    strPtr->lastMoveIncrement.y = gUnknown_80F4D44[a1].y * sSpeedMultiplier;
    sub_8075050(entityInfo, strPtr);
}

static void sub_8075050(EntityInfo *info, Unk_Entity_x184 *strPtr)
{
    s32 savedX, savedY;

    SetSpeedMultiplier();
    info->numMoveTiles++;
    if (info->numMoveTiles == 2) {
        info->unk184[0].walkAnimFramesLeft = 24 / (sSpeedMultiplier * 2);
        info->unk184[0].lastMoveIncrement.x *= 2;
        info->unk184[0].lastMoveIncrement.y *= 2;
        strPtr->walkAnimFramesLeft = 24 / (sSpeedMultiplier * 2);
        strPtr->lastMoveIncrement.x *= 2;
        strPtr->lastMoveIncrement.y *= 2;
    }
    else if (info->numMoveTiles == 3) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 2; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (sSpeedMultiplier * 3);
            info->unk184[i].lastMoveIncrement.x *= 3;
            info->unk184[i].lastMoveIncrement.y *= 3;
            info->unk184[i].lastMoveIncrement.x /= 2;
            info->unk184[i].lastMoveIncrement.y /= 2;
        }
        strPtr->walkAnimFramesLeft = 24 / (sSpeedMultiplier * 3);
        strPtr->lastMoveIncrement.x = savedX * 3;
        strPtr->lastMoveIncrement.y = savedY * 3;
    }
    else if (info->numMoveTiles == 4) {
        s32 i;

        savedX = strPtr->lastMoveIncrement.x;
        savedY = strPtr->lastMoveIncrement.y;
        for (i = 0; i < 3; i++) {
            info->unk184[i].walkAnimFramesLeft = 24 / (sSpeedMultiplier * 4);
            info->unk184[i].lastMoveIncrement.x *= 4;
            info->unk184[i].lastMoveIncrement.y *= 4;
            info->unk184[i].lastMoveIncrement.x /= 3;
            info->unk184[i].lastMoveIncrement.y /= 3;
        }
        strPtr->walkAnimFramesLeft = 24 / (sSpeedMultiplier * 4);
        strPtr->lastMoveIncrement.x = savedX * 4;
        strPtr->lastMoveIncrement.y = savedY * 4;
    }
    else {
        strPtr->walkAnimFramesLeft = 24 / sSpeedMultiplier;
    }
}

bool8 DisplayActions_Async(Entity *a0)
{
    s32 i, j, loop;
    Entity *savedEntityPtr;
    bool32 r7 = FALSE;
    bool32 r9 = FALSE;

    gUnknown_202F32D = 0;
    if (gGameOptionsRef->dungeonSpeed != 0)
        sSpeedMultiplier = 2;
    else
        sSpeedMultiplier = 1;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            if (monInfo->numMoveTiles == 0) {
                if (monInfo->waiting) {
                    monInfo->waiting = FALSE;
                    if ((monInfo->targetPos.x != 0 || monInfo->targetPos.y != 0)
                        && (monInfo->targetPos.x != mon->pos.x || monInfo->targetPos.y != mon->pos.y)
                        && (!CheckVariousStatuses2(mon, TRUE) || !CheckVariousStatuses(mon)))
                    {
                        s32 direction = GetDirectionTowardsPosition(&mon->pos, &monInfo->targetPos);
                        if (direction != monInfo->action.direction)
                            sub_806CE68(mon, direction);
                    }
                }
            }
            else {
                PixelPos pos;

                monInfo->flags |= 0x2000;
                pos.x = X_POS_TO_PIXELPOS(monInfo->unk184[0].previousTargetMovePosition2.x);
                pos.y = Y_POS_TO_PIXELPOS(monInfo->unk184[0].previousTargetMovePosition2.y);
                UpdateEntityPixelPos(mon, &pos);
                sub_806CDFC(mon, 0, monInfo->unk184[0].lastMoveDirection);
                monInfo->notMoving = 0;
                r7 = TRUE;
                if (ShouldDisplayEntity(mon))
                    r9 = TRUE;
            }
        }
    }

    if (!r7)
        return FALSE;

    savedEntityPtr = gDungeon->unkB8;
    gDungeon->unkB8 = a0;
    if (gDungeon->unk644.unk28 == 0 && r9) {
        sub_80526D0(0x35);
        for (loop = 0; loop < 24 / sSpeedMultiplier; loop++) {
            DungeonRunFrameActions(7);
            for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
                Entity *mon = gDungeon->activePokemon[i];
                if (EntityIsValid(mon)) {
                    EntityInfo *monInfo = GetEntInfo(mon);
                    Unk_Entity_x184 *strPtr = &monInfo->unk184[monInfo->notMoving];

                    ASM_MATCH_TRICK(i);
                    if (monInfo->numMoveTiles != 0) {
                        IncreaseEntityPixelPos(mon, strPtr->lastMoveIncrement.x, strPtr->lastMoveIncrement.y);
                        if (--strPtr->walkAnimFramesLeft == 0) {
                            if (++monInfo->notMoving == monInfo->numMoveTiles) {
                                monInfo->numMoveTiles = 0;
                            }
                            else {
                                PixelPos pos;

                                pos.x = X_POS_TO_PIXELPOS(monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.x);
                                pos.y = Y_POS_TO_PIXELPOS(monInfo->unk184[monInfo->notMoving].previousTargetMovePosition2.y);
                                UpdateEntityPixelPos(mon, &pos);
                                sub_806CDFC(mon, 0, monInfo->unk184[monInfo->notMoving].lastMoveDirection);
                            }
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *mon = gDungeon->activePokemon[i];
        if (EntityIsValid(mon)) {
            EntityInfo *monInfo = GetEntInfo(mon);
            monInfo->numMoveTiles = 0;
            nullsub_97(mon);
            if (monInfo->flags & 0x2000) {
                UpdateEntityPixelPos(mon, NULL);
            }
        }
    }

    TryWakeSleepingWildPokemon();
    for (j = 0; j < 2; j++) {
        for (loop = 0; loop < DUNGEON_MAX_POKEMON; loop++) {
            DungeonPos monPosBefore;
            EntityInfo *monInfo;
            Entity *mon = gDungeon->activePokemon[loop];

            if (!EntityIsValid(mon))
                continue;
            if (IsFloorOver())
                break;

            monInfo = GetEntInfo(mon);
            if ((j == 0 && !monInfo->isTeamLeader) || (j != 0 && monInfo->isTeamLeader))
                continue;

            monPosBefore = mon->pos;

            // Statement with no effect needed to match.
            GetEntInfo(mon)->isTeamLeader = GetEntInfo(mon)->isTeamLeader;

            if (monInfo->flags & 0x2000) {
                monInfo->flags &= ~(0x2000);
                if (monInfo->isTeamLeader) {
                    DiscoverMinimap(&mon->pos);
                    sub_807EC28(FALSE);
                    CheckLeaderTile();
                }
                else {
                    TryInteractWithTile(mon);
                }
                if (!EntityIsValid(mon))
                    continue;
                if (IsFloorOver())
                    break;

                TryForcedLoss_Async(FALSE);
                DoEndOfTurnEffects_Async(mon);
                if (!EntityIsValid(mon))
                    continue;
                if (IsFloorOver())
                    break;

                EnemyEvolution(mon);
                PotentiallyCreateMusicBox_Async();
                TryTriggerMonsterHouseWithMsg_Async(mon, gDungeon->forceMonsterHouse);
            }
            if (!EntityIsValid(mon))
                continue;
            if (IsFloorOver())
                break;

            if (monPosBefore.x != mon->pos.x || monPosBefore.y != mon->pos.y)
                gUnknown_202F32D = 1;

            sub_806A5B8(mon);
            if (sub_80706A4(mon, &mon->pos)) {
                WarpTarget(mon, mon, 0, NULL);
            }
        }
    }

    sub_8086AC0();
    if (!IsFloorOver()) {
        sub_8085140_Async();
        gDungeon->unkB8 = savedEntityPtr;
    }
    else {
        gDungeon->unkB8 = savedEntityPtr;
    }

    return TRUE;
}

void sub_8075680(bool8 unused)
{
    u32 direction;
    int i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        Entity *entity = gDungeon->activePokemon[i];
        if (EntityIsValid(entity)) {
            EntityInfo *info = GetEntInfo(entity);
            if (!info->isTeamLeader) {
                DungeonPos *targetPos = &info->targetPos;

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
}

static void nullsub_97(Entity *entity)
{}

static void TryInteractWithTile(Entity *entity)
{
    const Tile *tile;
    Entity *tileEntity;
    EntityInfo *info = GetEntInfo(entity);
    if (!EntityIsValid(entity))
        return;

    tile = GetTileAtEntitySafe(entity);
    if (IqSkillIsEnabled(entity, IQ_SUPER_MOBILE)
        && info->invisibleClassStatus.status != STATUS_MOBILE
        && !(HasHeldItem(entity, ITEM_MOBILE_SCARF)))
    {
        sub_804AE84(&entity->pos);
    }
    tileEntity = tile->object;
    if (tileEntity == NULL)
        return;

    switch (GetEntityType(tileEntity)) {
        case ENTITY_TRAP: {
            Trap *trapData = GetTrapInfo(tileEntity);
            bool8 trigger = FALSE;
            bool8 onlyMakeVisible = FALSE;
            if (IqSkillIsEnabled(entity, IQ_TRAP_SEER) && !tileEntity->isVisible) {
                tileEntity->isVisible = TRUE;
                UpdateTrapsVisibility();
                onlyMakeVisible = TRUE;
            }

            if (trapData->unk1 == 0) {
                if (tileEntity->isVisible && !info->isNotTeamMember)
                    trigger = TRUE;
            }
            else if (trapData->unk1 == 1) {
                if (info->isNotTeamMember)
                    trigger = TRUE;
            }
            else if (trapData->unk1 == 2) {
                if (!info->isNotTeamMember)
                    trigger = TRUE;
            }

            if (trigger && !onlyMakeVisible) {
                TryTriggerTrap(entity, &entity->pos, 0, 1);
            }
            break;
        }
        case ENTITY_ITEM:
            MonTryPickUpItem(entity);
            break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
    }
}

bool8 CheckEntityTileForInteraction(Entity *entity)
{
    Entity *subEntity;
    const Tile *tile;
    EntityInfo *entityInfo = GetEntInfo(entity);
    if (!EntityIsValid(entity))
        return FALSE;

    tile = GetTileAtEntitySafe(entity);
    if (IqSkillIsEnabled(entity, IQ_SUPER_MOBILE) && GetTerrainType(tile) == TERRAIN_TYPE_WALL)
        return TRUE;
    subEntity = tile->object;
    if (subEntity == NULL)
        return FALSE;

    switch (GetEntityType(subEntity)) {
        case ENTITY_TRAP: {
            Trap *trapData = GetTrapInfo(subEntity);
            bool8 flag = FALSE;

            if (trapData->unk1 == 0) {
                if (subEntity->isVisible && !entityInfo->isNotTeamMember)
                    flag = TRUE;
            }
            else if (trapData->unk1 == 1) {
                if (entityInfo->isNotTeamMember)
                    flag = TRUE;
            }
            else if (trapData->unk1 == 2) {
                if (!entityInfo->isNotTeamMember)
                    flag = TRUE;
            }

            if (flag)
                return TRUE;

            break;
        }
        case ENTITY_ITEM:
            if (!entityInfo->isTeamLeader && !ItemExists(&entityInfo->heldItem)) {
                if (GetTerrainType(tile) == TERRAIN_TYPE_WALL) {
                    if (!entityInfo->isNotTeamMember) {
                        Item *item = GetItemInfo(subEntity);
                        if (!(item->flags & ITEM_FLAG_IN_SHOP))
                            return TRUE;
                    }
                }
                else {
                    Item *item = GetItemInfo(subEntity);
                    if (!(item->flags & ITEM_FLAG_IN_SHOP))
                        return TRUE;
                }

            }
            break;
        case ENTITY_NOTHING:
        case ENTITY_MONSTER:
        case ENTITY_UNK_4:
        case ENTITY_UNK_5:
            break;
    }

    return FALSE;
}

void TryTriggerMonsterHouseWithMsg_Async(Entity *pokemon, bool8 forcedMonsterHouse)
{
    if (EntityIsValid(pokemon)
        && !GetEntInfo(pokemon)->isNotTeamMember
        && !IsFloorOver()
        && !gDungeon->unk644.monsterHouseTriggered
        && (GetTileAtEntitySafe(pokemon)->terrainFlags & TERRAIN_TYPE_IN_MONSTER_HOUSE))
    {
        // It's a monster house!
        LogMessageByIdWithPopupCheckUser_Async(GetLeader(), gPtrItsaMonsterHouseMessage);
        gDungeon->unk644.monsterHouseTriggeredEvent = TRUE;
        TriggerMonsterHouse_Async(pokemon, forcedMonsterHouse);
        sub_8041888(0);
        if (sub_803F428(&pokemon->pos))
            DungeonWaitFrames_Async(0x78, 0x39);
    }
}
