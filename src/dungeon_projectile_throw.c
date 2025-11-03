#include "global.h"
#include "globaldata.h"
#include "dungeon_projectile_throw.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "moves.h"
#include "dungeon_items.h"
#include "dungeon_vram.h"
#include "dungeon_map_access.h"
#include "dungeon_config.h"
#include "dungeon_pos_data.h"
#include "dungeon_tilemap.h"
#include "dungeon_mon_sprite_render.h"
#include "dungeon_message.h"
#include "move_util.h"
#include "move_orb_effects_5.h"
#include "dungeon_strings.h"
#include "dungeon_range.h"
#include "dungeon_item_action.h"
#include "structs/dungeon_entity.h"
#include "constants/move_id.h"

static bool8 CanProjectileHitTarget(Entity *thrower, Entity *target);

struct ProjectileHitEntry
{
    Entity *target;
    bool8 didHit;
};

void HandleStraightProjectileThrow(Entity *thrower, Item *item, DungeonPos *pos, s32 dir, struct ProjectileThrowInfo *a4)
{
    const Tile *tile;
    int i;
    u32 stepResult;
    int remainingSteps;
    int count;
    bool8 hallucinating = gDungeon->unk181e8.hallucinating;
    struct ProjectileHitEntry hitList[64];
    bool8 lockOnActive;
    Move moveBuffer;
    DungeonPos bouncePos;
    PixelPos pixelDelta;

    s32 currentDir = dir;
    Entity *projectile = &gDungeon->unkC0;

    projectile->type = ENTITY_ITEM;
    projectile->unk24 = 0;
    projectile->isVisible = TRUE;
    projectile->unk22 = 0;
    projectile->axObj.info.item = item;
    projectile->unk1C = 0;
    projectile->pos = *pos;

    SetEntityPixelPos(projectile, (pos->x * 24 + 4) << 8, (pos->y * 24 + 0) << 8);
    projectile->spawnGenID = 0;

    lockOnActive = FALSE;
    if (GetEntityType(thrower) == ENTITY_MONSTER && HasHeldItem(thrower, ITEM_LOCKON_SPECS))
        lockOnActive = TRUE;

    remainingSteps = a4->unk2;
    count = 0;

    SetUnk1C05E(TRUE);

    while (1) {
        s32 i;
        DungeonPos prevPos = projectile->pos;

        if (a4->unk1 && !a4->unk0) {
            tile = GetTile(projectile->pos.x + gAdjacentTileOffsets[currentDir].x, projectile->pos.y + gAdjacentTileOffsets[currentDir].y);

            if (GetTerrainType(tile) == TERRAIN_TYPE_WALL) {
                s32 i;
                for (i = 0; i < 4; i++) {
                    s32 testDir = gUnknown_80F4D64[currentDir][i];
                    if (testDir < NUM_DIRECTIONS) {
                        const Tile *adjTile = GetTile(
                            gAdjacentTileOffsets[testDir].x + prevPos.x,
                            gAdjacentTileOffsets[testDir].y + prevPos.y
                        );

                        if (GetTerrainType(adjTile) != TERRAIN_TYPE_WALL) {
                            currentDir = testDir;
                            break;
                        }
                    }
                }
            }
        }

        projectile->pos.x += gAdjacentTileOffsets[currentDir].x;
        projectile->pos.y += gAdjacentTileOffsets[currentDir].y;

        if (projectile->pos.x < 0 || projectile->pos.y < 0 ||
            projectile->pos.x >= 56 || projectile->pos.y >= 32)
        {
            stepResult = 2;
            break;
        }

        pixelDelta.x = gAdjacentTileOffsets[currentDir].x << 10;
        pixelDelta.y = gAdjacentTileOffsets[currentDir].y << 10;

        for (i = 0; i < 6; i++) {
            s32 arg2;
            bool8 advanceFrame = FALSE;

            IncreaseEntityPixelPos(projectile, pixelDelta.x, pixelDelta.y);
            if (IsWaterTileset()) arg2 = 3;
            else arg2 = 0;

            if (sub_8083568((projectile->pixelPos.x / 256) + 8, (projectile->pixelPos.y / 256) + 16, arg2))
                advanceFrame = TRUE;

            if (sub_80462AC(projectile, hallucinating, 0, currentDir, 1))
                advanceFrame = TRUE;

            if (advanceFrame)
                DungeonRunFrameActions(0x12);
        }

        tile = GetTile(projectile->pos.x, projectile->pos.y);

        if (GetTerrainType(tile) == 0 && !a4->unk0) {
            projectile->pos = prevPos;
            stepResult = 1;
            break;
        }

        if (tile->monster != NULL) {
            bool8 reflectHit = FALSE;

            if (!a4->unk0 &&
                GetEntityType(tile->monster) == ENTITY_MONSTER &&
                HasHeldItem(tile->monster, ITEM_BOUNCE_BAND))
            {
                reflectHit = TRUE;
            }

            if (reflectHit) {
                currentDir = (currentDir + 4) & DIRECTION_MASK;
            }
            else {
                bool8 canHit = TRUE;

                if (GetEntityType(tile->monster) == ENTITY_MONSTER) {
                    InitPokemonMove(&moveBuffer, MOVE_PROJECTILE);
                    if (sub_80571F0(tile->monster, &moveBuffer)) {
                        canHit = FALSE;
                    }
                }

                if (canHit) {
                    if (count < 64) {
                        hitList[count].target = tile->monster;
                        hitList[count].didHit = CanProjectileHitTarget(thrower, tile->monster);
                        count++;
                    }

                    if (!a4->unk0) {
                        stepResult = 0;
                        break;
                    }
                }
            }
        }

        remainingSteps--;
        if (remainingSteps <= 0) {
            stepResult = 1;
            break;
        }
    }

    SetUnk1C05E(FALSE);

    for (i = 0; i < count; i++) {
        Entity *target = hitList[i].target;

        if (hitList[i].didHit) {
            bool8 endMsg;

            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
            sub_8045C08(gFormatBuffer_Items[0], item);
            TryDisplayDungeonLoggableMessage3(thrower, target, gUnknown_80F94C4);
            endMsg = TrySendImmobilizeSleepEndMsg(thrower, target);
            sub_80479B8(1, (lockOnActive || a4->unk0) ? 1 : 0, endMsg, thrower, target, item);
        }
        else {
            if (!a4->unk0 && count == 1) {
                stepResult = 1;
            }

            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], target, 0);
            sub_8045BF8(gFormatBuffer_Items[0], item);

            if (a4->unk0) {
                TryDisplayDungeonLoggableMessage3(thrower, target, gUnknown_80F94D8);
            }
            else {
                TryDisplayDungeonLoggableMessage3(thrower, target, gUnknown_80F94F0);
            }
        }
    }

    bouncePos.x = gAdjacentTileOffsets[currentDir].x * 8;
    bouncePos.y = gAdjacentTileOffsets[currentDir].y * 8;

    switch (stepResult) {
        case 0:
            break;
        case 1:
            SpawnDroppedItem(thrower, projectile, item, 1, &bouncePos);
            break;
        case 2:
            sub_8045C08(gFormatBuffer_Items[0], item);
            LogMessageByIdWithPopupCheckUser(thrower, gUnknown_80F9530);
            break;
    }
}

void HandleCurvedProjectileThrow(Entity *thrower, Item *item, DungeonPos *startPos, DungeonPos *targetPos, struct ProjectileThrowInfo *a4)
{
    Entity *projectile;
    bool8 r4;
    const Tile *tile;
    bool8 throwResult;
    bool8 hallucinating;
    bool8 lockOnSpecs;
    struct ProjectileHitEntry hitResult;

    hallucinating = gDungeon->unk181e8.hallucinating;
    hitResult.target = NULL;
    projectile = &gDungeon->unkC0;

    projectile->type = ENTITY_ITEM;
    projectile->unk24 = 0;
    projectile->isVisible = TRUE;
    projectile->unk22 = 0;
    projectile->axObj.info.item = item;
    projectile->unk1C = 0;
    projectile->pos = *startPos;

    SetEntityPixelPos(projectile, (startPos->x * 24 + 4) << 8, (startPos->y * 24 + 4) << 8);
    projectile->spawnGenID = 0;

    throwResult = 1;
    lockOnSpecs = FALSE;
    if (GetEntityType(thrower) == ENTITY_MONSTER && HasHeldItem(thrower, ITEM_LOCKON_SPECS)) {
        lockOnSpecs = TRUE;
    }

    r4 = FALSE;
    if (sub_803F428(startPos)) {
        r4 = TRUE;
    }
    if (sub_803F428(targetPos)) {
        r4 = TRUE;
    }

    SetUnk1C05E(TRUE);
    if (r4) {
        s32 i;
        s32 posXFixed, posYFixed;
        s32 arcHeight;
        s32 deltaXFixed;
        s32 deltaYFixed;
        s32 sinePhase;
        s32 sinePhaseStep;
        s32 unkX, unkY;
        bool8 runFrameActions;
        s32 posX, posY;
        s32 entPosX, entPosY;
        s32 absX, absY;
        s32 displayX, displayY;
        s32 sinVal;
        s32 totalSteps;

        entPosX = projectile->pos.x;
        posX = targetPos->x;
        absX = abs(entPosX - posX);
        entPosY = projectile->pos.y;
        posY = targetPos->y;
        absY = abs(entPosY - posY);
        totalSteps = (absX + absY) * 12;
        arcHeight = totalSteps + 12;
        if (arcHeight >= 64) {
            arcHeight = 64;
        }

        sinePhase = 0;
        sinePhaseStep = 0x80000 / totalSteps;
        posXFixed = (startPos->x * 24) * 256;
        posYFixed = (startPos->y * 24) * 256;
        deltaXFixed = (((posX * 24) * 256) - posXFixed) / totalSteps;
        deltaYFixed = (((posY * 24) * 256) - posYFixed) / totalSteps;
        for (i = 0; i < totalSteps - 3; i++) {
            u8 terrainArg;

            runFrameActions = FALSE;
            sinVal = sin_4096(sinePhase / 256) * arcHeight;
            displayX = posXFixed + 0x400;
            displayY = posYFixed + 0x400;

            projectile->unk1C = sinVal;
            unkX = (posXFixed / 256) + 8;
            unkY = (posYFixed / 256) + 16;
            sinePhase += sinePhaseStep;
            SetEntityPixelPos(projectile, displayX, displayY);

            if (IsWaterTileset()) terrainArg = 3;
            else terrainArg = 0;

            if (sub_8083568(unkX, unkY, terrainArg))
                runFrameActions = TRUE;
            if (sub_80462AC(projectile, hallucinating, 0, 0xFF, 1))
                runFrameActions = TRUE;

            if (runFrameActions)
                DungeonRunFrameActions(0x17);

            posXFixed += deltaXFixed;
            posYFixed += deltaYFixed;
        }
    }
    projectile->pos = *targetPos;
    SetUnk1C05E(FALSE);
    tile = GetTile(targetPos->x, targetPos->y);
    if (tile->monster != NULL) {
        bool8 canHit = TRUE;
        bool8 hasBounceBand = FALSE;

        if (GetEntityType(tile->monster) == ENTITY_MONSTER) {
            Move move;

            if (HasHeldItem(tile->monster, ITEM_BOUNCE_BAND)) {
                hasBounceBand = TRUE;
            }
            InitPokemonMove(&move, MOVE_PROJECTILE);
            if (sub_80571F0(tile->monster, &move)) {
                canHit = FALSE;
            }
        }
        if (canHit) {
            hitResult.target = tile->monster;
            if (hasBounceBand) {
                hitResult.didHit = FALSE;
            }
            else {
                hitResult.didHit = CanProjectileHitTarget(thrower, hitResult.target);
            }

            sub_8045C08(gFormatBuffer_Items[0], item);
            SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], hitResult.target, 0);
            if (hitResult.didHit) {
                bool8 immobiSlpEndMsg;

                sub_806CE94(hitResult.target, 8);
                TryDisplayDungeonLoggableMessage3(thrower, hitResult.target, gUnknown_80F94C4);
                immobiSlpEndMsg = TrySendImmobilizeSleepEndMsg(thrower, hitResult.target);
                sub_80479B8(1, (lockOnSpecs || a4->unk0 != 0) ? 1 : 0, immobiSlpEndMsg, thrower, hitResult.target, item);
                throwResult = 0;
            }
            else {
                if (hasBounceBand) {
                    TryDisplayDungeonLoggableMessage3(thrower, hitResult.target, gUnknown_80F9510);
                }
                else {
                    TryDisplayDungeonLoggableMessage3(thrower, hitResult.target, gUnknown_80F94F0);
                }
                throwResult = 1;
            }
        }
    }

    switch (throwResult) {
        case 0:
        case 2:
            break;
        case 1:
            SpawnDroppedItem(thrower, projectile, item, FALSE, NULL);
            break;
    }
}

static bool8 CanProjectileHitTarget(Entity *thrower, Entity *target)
{
    bool8 ret;

    if (GetEntInfo(target)->shopkeeper == TRUE
         || GetEntInfo(target)->monsterBehavior == BEHAVIOR_DIGLETT
         || GetEntInfo(target)->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
    {
        return FALSE;
    }

    if (DungeonRandInt(100) < gProjectileHitChance)
        ret = TRUE;
    else
        ret = FALSE;

    if (GetEntityType(thrower) == ENTITY_MONSTER) {
        if (HasHeldItem(thrower, ITEM_WHIFF_SPECS))
            ret = FALSE;
        else if (HasHeldItem(thrower, ITEM_LOCKON_SPECS))
            ret = TRUE;
    }

    if (GetEntityType(target) == ENTITY_MONSTER && HasHeldItem(target, ITEM_DODGE_SCARF))
        ret = FALSE;

    return ret;
}
